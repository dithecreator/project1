//
//  File.hpp
//  project
//
//  Created by Дима on 16.10.23.
//

#ifndef File_hpp
#define File_hpp
#include <stdio.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;
class File{
    string filename;
    ofstream file;
public:

    File();
    void createFile();
    void writeFile(string& data);
    void readFile();
    void Rename(string& newName);
    void copyFile(string& filename1, string& filename2);
    void deleteFile();
    void printFile();
    int getFileSize();
    string getFileName();
};

#endif /* File_hpp */
