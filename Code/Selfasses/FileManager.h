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
	void deleteTempFiles();
private:

	void replaceLines(std::string&, std::string, int, std::vector<std::string> );
	void updateFileCount();
	
	void deleteFile(std::string fileName);

	int fileCount = 0;
	std::string inputFileName = "base" + std::to_string(fileCount) + ".rtf";
	std::string resultFileName = "result" + std::to_string(fileCount) + ".rtf";
	std::string finalResultFileName = "finalresult" + std::to_string(fileCount) + ".rtf";

};

