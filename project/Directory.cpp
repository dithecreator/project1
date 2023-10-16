//
//  Directory.cpp
//  project
//
//  Created by Дима on 16.10.23.
//

#include "Directory.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std::filesystem;
void Directory:: createDirectory(){
    cout << "введите имя папки: ";
    cin >> name;
    if (!exists(name)) {
        if (create_directory(name)) {
            cout << "Папка успешно создана." << endl;
        } else {
            cout << "Не удалось создать папку." << endl;
        }
    } else {
        cout << "Папка уже существует." << endl;
    }
}



void Directory:: deleteDirectory(){
    cout << "введите имя папки, которую хотите удалить: ";
    cin >> name;
    if (exists(name) && is_directory(name)) {
        remove_all(name);
        cout << "Папка успешно удалена." << endl;
    } else {
        cout << "Папка не существует" << endl;
    }
}


void Directory:: copyDirectory(string& source, string& destination) {
    if (exists(source) || !is_directory(source)) {
        cout << "Исходная директория не существует или не является папкой." << endl;
    }

    if (!exists(destination)) {
        create_directory(destination);
    }

    for (auto& entry : directory_iterator(source)) {
        string currentPath = entry.path().string();
        string destinationPath = destination + "/" + entry.path().filename().string();

        if (is_directory(entry.status())) {
            copyDirectory(currentPath, destinationPath);
        } else if (is_regular_file(entry.status())) {
            remove(destinationPath);
            copy_file(currentPath, destinationPath);
        }
    }
}

int Directory:: getDirectorySize(const string& filename) {
    int totalSize = 0;
    for (const auto& entry : directory_iterator(filename)) {
        if (is_regular_file(entry.status())) {
            totalSize += file_size(entry);
        } else if (is_directory(entry.status())) {
            totalSize += getDirectorySize(entry.path().string());
        }
    }

    return totalSize;
}


void Directory:: findFilesByMask(const string& directoryPath, const string& mask) {
    for (const auto& entry : directory_iterator(directoryPath)) {
        if (is_regular_file(entry.status())) {
            string fileName = entry.path().filename().string();
            if (path(fileName).extension() == mask) {
                cout << entry.path() << endl;
            }
        } else if (is_directory(entry.status())) {
            findFilesByMask(entry.path().string(), mask);
        }
    }
}

void Directory:: printDirectory(){
    for(const auto& entry : directory_iterator(name)) {
        cout << entry.path().filename() << endl;
    }
}

void Directory:: Rename(string& newName){

        if (rename(name.c_str(), newName.c_str()) == 0) {
            cout << "Объект успешно переименован." << endl;
        } else {
            cout << "Не удалось переименовать объект." << endl;
        }
    
    
}


void Directory:: createFileInDirectory(string& fileName){
    string filePath = name + '/' + fileName;
    if (!exists(filePath)) {
        ofstream file(filePath);
        if (file.is_open()) {
            cout << "Файл успешно создан." << endl;
            file.close();
        } else {
            cout << "Не удалось создать файл." << endl;
        }
    } else {
        cout << "Файл уже существует." << endl;
    }
}
