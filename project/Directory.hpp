//
//  Directory.hpp
//  project
//
//  Created by Дима on 16.10.23.
//

#ifndef Directory_hpp
#define Directory_hpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
class Directory{
    string name;
public:
    Directory() = default;
    void createDirectory();
    void deleteDirectory();
    void printDirectory();
    int getDirectorySize(const string& filename);
    void copyDirectory(string& source, string& destination);
    void findFilesByMask(const string& directoryPath, const string& mask);
    void createFileInDirectory(string& fileName);
    void Rename(string& newName);
};

#endif /* Directory_hpp */
