//
//  Manager.hpp
//  project
//
//  Created by Дима on 15.10.23.
//

#ifndef Manager_hpp
#define Manager_hpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
class Manager{
    ofstream file;
//    User user;
    
public:
    Manager();
    void createFile(string& name);
    void writeFile(string& data);
    void readFile();
    void Rename(string& oldName, string& newName);
    void copyFile(string& filename1, string& filename2);
   void deleteFile(string& filename);
    void printFile(string& filename);
    int getSize();
    
    void createDirectory(string& path);
    void copyDirectory();
    
};

#endif /* Manager_hpp */
