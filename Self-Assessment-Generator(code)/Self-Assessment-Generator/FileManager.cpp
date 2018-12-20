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
void FileManager::replaceLines(string &line, string topicName, int topicIndex, vector<string> topicArray)
{
	size_t targetPos = line.find(topicName);
	if (targetPos != string::npos)
	{
		line.replace(line.find(topicName), topicName.length(), topicArray.at(topicIndex));

	}
}

void FileManager::changeTopic(string changeTopicName, vector<string> topicArray)
{

	int ArraySize = topicArray.size();
	int topicRandom1 = rand() % ArraySize;
	int topicRandom2 = rand() % ArraySize;
	int topicRandom3 = rand() % ArraySize;


	int randomPlace1 = rand() % 7 + 1;
	int randomPlace2 = rand() % 7 + 1;
	int randomPlace3 = rand() % 7 + 1;

	string currentLine;
	string topicName1 = changeTopicName + to_string(randomPlace1);
	string topicName2 = changeTopicName + to_string(randomPlace2);
	string topicName3 = changeTopicName + to_string(randomPlace3);

	fstream weekPlanFile(inputFileName);
	ofstream weekPlanResult;
	weekPlanResult.open(resultFileName);
	if (weekPlanFile.is_open())
	{

		while (getline(weekPlanFile, currentLine))
		{

			replaceLines(currentLine, topicName1, topicRandom1, topicArray);
			replaceLines(currentLine, topicName2, topicRandom2, topicArray);
			replaceLines(currentLine, topicName3, topicRandom3, topicArray);

			weekPlanResult << currentLine << "\n";

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
					curLine.replace(curLine.find(curStr), curStr.length(), " ");
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
	inputFileName = "bin/base" + std::to_string(fileCount) + ".bd";
	resultFileName = "bin/result" + std::to_string(fileCount) + ".bd";
}
void FileManager::deleteTempFiles()
{

	for (int i = 0; i <= 4; i++)
	{
		string base = "bin/base" + to_string(i) + ".bd";
		string result = "bin/result" + to_string(i) + ".bd";

		if (i != 0)
		{
			deleteFile(base);
		}
		deleteFile(result);
	}
	string renamedFileName = "bin/base" + to_string(fileCount) + ".bd";
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
