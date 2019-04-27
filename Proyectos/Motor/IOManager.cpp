#include "IOManager.h"
#include <fstream>

bool IOManager::readFileToBuffer(string filePath, 
	vector<unsigned char>& buffer)
{
	ifstream file(filePath, ios::binary);
	if (file.fail()) {
		perror(filePath.c_str());
		return false;
	}
	file.seekg(0, ios::end);
	int filesize = file.tellg();
	file.seekg(0, ios::beg);
	filesize -= file.tellg();
	buffer.resize(filesize);
	file.read((char *)&buffer[0], filesize);
	file.close();
	return true;
}
