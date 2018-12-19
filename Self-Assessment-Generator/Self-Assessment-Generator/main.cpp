#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "FileManager.h"

using namespace std;

vector<string> ReadVector;
vector<string> ListenVector;
vector<string> ViewVector;
vector<string> GramVector;
vector<string> ExtraVector;



string ReadingFileName = "bin/Reading.bd";
string ViewingFileName = "bin/Viewing.bd";
string GrammerFileName = "bin/Grammer.bd";
string ExtraFileName   = "bin/Extra.bd";
string ListenFileName  = "bin/Listening.bd";

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
	FileManager fileManager;
	srand(time(NULL));
	loadIntoArray(ReadVector, ReadingFileName);
	loadIntoArray(ViewVector, ViewingFileName);
	loadIntoArray(GramVector, GrammerFileName);
	loadIntoArray(ExtraVector, ExtraFileName);
	loadIntoArray(ListenVector, ListenFileName);


	fileManager.changeTopic("Listen", ListenVector);
	fileManager.changeTopic("Read", ReadVector);
	fileManager.changeTopic("View", ViewVector);
	fileManager.changeTopic("Gram", GramVector);
	fileManager.changeTopic("Extra", ExtraVector);

	fileManager.deleteTempFiles();

	return 0;
}
