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

	string currentLine;
	string topicName = changeTopicName + to_string(placeRandom);

	fstream weekPlanFile(inputFileName);
	ofstream weekPlanResult;
	weekPlanResult.open(resultFileName);
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
			cout << fileCount << endl;
		}
		weekPlanFile.close();
		weekPlanResult.close();
		deleteTopic(changeTopicName);
		
	}
	else
	{
		cout << "change file was unable to open";
	}
}

void FileManager::deleteTopic(std::string deleteTopicName)
{
	string curLine;
	fstream readResult(resultFileName);
	ofstream finalResult;
	updateFileCount();
	finalResult.open(inputFileName);
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
		cout << "delete file was unable to open";
	}
}

void FileManager::updateFileCount()
{
	fileCount++;
	inputFileName = "base" + std::to_string(fileCount) + ".rtf";
	resultFileName = "result" + std::to_string(fileCount) + ".rtf";
	finalResultFileName = "finalresult" + std::to_string(fileCount) + ".rtf";
}
void FileManager::deleteTempFiles()
{
	
	for (int i = 0; i <= 4; i++)
	{
		string base = "base" + to_string(i) + ".rtf";
		string result = "result" + to_string(i) + ".rtf";
		
		if (i != 0)
		{
			deleteFile(base);
		}
		deleteFile(result);
	}
	string renamedFileName = "base" + to_string(fileCount) + ".rtf";
	rename(renamedFileName.c_str(), "Self-Assessment.rtf");
}
void FileManager::deleteFile(std::string fileName)
{
	if (remove(fileName.c_str()) != 0)
	{
		cout << "error deleting \n";
	}
	else
	{
		cout << "deleted \n";
	}
}
