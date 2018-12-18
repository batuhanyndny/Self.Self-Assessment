#include <pch.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

vector<string> Read;
vector<string> Listen;
vector<string> View;
vector<string> Gram;
vector<string> Extra;



string ReadingFileName = "selfassessment/Reading.txt";
string ViewingFileName = "selfassessment/Viewing.txt";
string GrammerFileName = "selfassessment/Grammer.txt";
string ExtraFileName = "selfassessment/Extra.txt";
string ListenFileName = "selfassessment/Listening.txt";


void loadIntoArray(vector<string> &arr, string fileName)
{
	string currentLine;
	ifstream file(fileName);
	if (file.is_open())
	{
		while (getline(file, currentLine))
		{
			arr.push_back(currentLine);
		}
	}
	else
	{
		cout << "unable to open file";
	}

}

int main()
{

	loadIntoArray(Read,   ReadingFileName);
	loadIntoArray(View,   ViewingFileName);
	loadIntoArray(Gram,   GrammerFileName);
	loadIntoArray(Extra,  ExtraFileName);
	loadIntoArray(Listen, ListenFileName);

	srand(time(NULL));
	int random = rand() % 7+1;
	cout << random;


	string line;
	string rep = "Read" + to_string(random);
	fstream myfile("weeklyplan1.rtf");
	ofstream file2;
	file2.open("selfass.rtf");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{

			size_t pos = line.find(rep);
			if (pos != string::npos)
			{
				line.replace(line.find(rep), rep.length(), Read.at(random));
				file2 << line << "\n";
			}
			else
			{
				file2 << line << "\n";
			}


		}
		myfile.close();
		file2.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	string curline;
	fstream res("selfass.rtf");
	ofstream finalres;
	string rep2 = "Read";
	finalres.open("DrumRoll.rtf");
	if (res.is_open())
	{
		while (getline(res, curline))
		{
			for (int i = 1; i <= 7; i++)
			{
				
				string curstr = rep2 + to_string(i);
				//cout << curstr << endl;
				size_t pos2 = curline.find(curstr);
				if (pos2 != string::npos)
				{
					curline.replace(curline.find(curstr), curstr.length(), "-");

				}
			}
			finalres << curline << "\n";
		}
		res.close();
		finalres.close();
		
	}
	//
	//string line;
	//fstream file("weeklyplan1.rtf");
	//if (file.is_open())
	//{
	//	while (getline(file, line))
	//	{
	//		cout << line << endl;
	//	}
	//}

	//system("PAUSE");

	return 0;
}
