//
//  Manager.cpp
//  project
//
//  Created by Дима on 15.10.23.
//

#include "Manager.hpp"
#include <iostream>
#include <filesystem>
#include <fstream>
using namespace std::filesystem;

Manager::Manager() {
    file.open("file.txt");
}


void Manager:: createFile(string& name){
    ofstream file(name, ios:: out | ios:: trunc);
}

void Manager:: writeFile(string& data){
    if(file.is_open()){
    file << data << " ";
    file.close();
    }
    else{
        cout << "файл не найден" << endl;
    }
    
}

void Manager:: readFile(){
    
    string data;
    if(file.is_open()){
        while(!file.eof()){
            file << data;
            cout << data << ' ';
    }
        file.close();
    }
    else{
        cout << "файл не найден" << endl;
    }
    
}
void Manager:: Rename(string& oldName, string& newName){
        if(rename(oldName.c_str(), newName.c_str()) == 0){
            cout << "обьект успешно переименован." << std::endl;
        }
        else {
            cout << "Не удалось переименовать обьект." << std::endl;
        }
    
}

void Manager:: copyFile(string& filename1, string& filename2){
    
     ifstream from(filename1);
     if(!file.is_open()) {
         cout << "Не удалось открыть исходный файл." << endl;
         
     }

     ofstream to(filename2);
     if (!to.is_open()) {
         cout << "Не удалось создать целевой файл." << endl;
         
     }

     char ch;
     while (from.get(ch)) {
         to.put(ch);
     }

     to.close();
     from.close();
}

void Manager:: deleteFile(string& filename){
    if (remove(filename.c_str()) == 0) {
           cout << "Файл успешно удален." << std::endl;
       }
    else {
           cout << "Не удалось удалить файл." << std::endl;
       }
}

void Manager:: printFile(string& filename){
    ifstream file(filename);
    if(file.is_open()){
        char c;
        while(file.get(c)){
            cout << c;
        }
        file.close();
    }
}

void Manager:: createDirectory(string& path){
    if (!exists(path)) {
        if (create_directory(path)) {
            cout << "Папка успешно создана." << endl;
        } else {
            cout << "Не удалось создать папку." << endl;
        }
    } else {
        cout << "Папка уже существует." << endl;
    }
}



