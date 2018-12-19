#pragma once
#include <string>
#include <vector>



class FileManager
{
public:
	FileManager();
	~FileManager();

	void changeTopic(std::string changeTopicName, std::vector<std::string> topicArray);
	void deleteTopic(std::string deleteTopicName);
private:
	int fileCount;
};

