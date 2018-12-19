#include <pch.h>
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
	FileManager fileManager;

	loadIntoArray(ReadVector,   ReadingFileName);
	loadIntoArray(ViewVector,   ViewingFileName);
	loadIntoArray(GramVector,   GrammerFileName);
	loadIntoArray(ExtraVector,  ExtraFileName);
	loadIntoArray(ListenVector, ListenFileName);
	

	fileManager.changeTopic("Listen", ListenVector);
	fileManager.changeTopic("Read",   ReadVector);
	fileManager.changeTopic("View",   ViewVector);
	fileManager.changeTopic("Gram",   GramVector);
	fileManager.changeTopic("Extra",  ExtraVector);
	

	fileManager.deleteTopic("Listen");
	fileManager.deleteTopic("Read");
	fileManager.deleteTopic("View");
	fileManager.deleteTopic("Gram");
	fileManager.deleteTopic("Extra");
	
	return 0;
}
