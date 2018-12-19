#include "pch.h"
#include "FileManager.h"
#include <direct.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

FileManager::FileManager()
{
	
}


FileManager::~FileManager()
{
}

void FileManager::changeTopic(string changeTopicName, vector<string> topicArray)
{

	srand(time(NULL));
	int ArraySize = topicArray.size();
	int topicRandom = rand() % ArraySize;
	int placeRandom = rand() % 7 + 1;
	cout << "place random:" << placeRandom << endl;
	cout << "topic random:" << topicRandom << endl;
	string currentLine;
	string topicName = changeTopicName + to_string(placeRandom);
	fstream weekPlanFile("duzgungibi.rtf");
	ofstream weekPlanResult;
	weekPlanResult.open("selfass.rtf");
	if (weekPlanFile.is_open())
	{
		while (getline(weekPlanFile, currentLine))
		{
			size_t targetPos = currentLine.find(topicName);
			if (targetPos != string::npos)
			{
				currentLine.replace(currentLine.find(topicName), topicName.length(), topicArray.at(topicRandom));
				weekPlanResult << currentLine << "\n";
			}
			else
			{
				weekPlanResult << currentLine << "\n";
			}
		}
		weekPlanFile.close();
		weekPlanResult.close();
	}
}

void FileManager::deleteTopic(std::string deleteTopicName)
{
	string curLine;
	fstream readResult("selfass.rtf");
	ofstream finalResult;
	finalResult.open("NewSelfAss.rtf");
	if (readResult.is_open())
	{
		while (getline(readResult, curLine))
		{
			for (int i = 1; i <= 7; i++)
			{
				string curStr = deleteTopicName + to_string(i);
				size_t topicPos = curLine.find(curStr);
				if (topicPos != string::npos)
				{
					curLine.replace(curLine.find(curStr), curStr.length(), "-");
				}
			}
			finalResult << curLine << "\n";
		}
		readResult.close();
		finalResult.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}
