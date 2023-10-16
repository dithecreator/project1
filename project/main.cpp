//
//  main.cpp
//  project
//
//  Created by Дима on 15.10.23.
//

//Первое задание
//Реализовать простейший файловый менеджер с использованием ООП (классы, наследование и так далее).
//Файловый менеджер должен иметь такие возможности:
//■ показывать содержимое дисков;
//■ создавать папки/файлы;
//■ удалять папки/файлы;
//■ переименовывать папки/файлы;
//■ копировать/переносить папки/файлы;
//■ вычислять размер папки/файла;
//■ производить поиск по маске (с поиском по подпапкам) и так далее.
#include <iostream>
#include <fstream>
#include <string>
#include "Manager.h"
#include "User.hpp"
#include "File.hpp"
#include "Directory.hpp"
using namespace std;

void account(Manager manage){
    manage.signIn();
    manage.login();
}
int main() {

    
    Manager manage;
    manage.signIn();
    manage.login();
    string myFile;
    
    int answer;
    cout << "выберите действие: " << endl;
    cout << endl;
    cout << "ФАЙЛЫ: " << endl;
    cout << "1 - создать файл" << endl;
    cout << "2 - записать данные в файл" << endl;
    cout << "3 - считать данные из файла" << endl;
    cout << "4 - переименовать файл" << endl;
    cout << "5 - копировать файл" << endl;
    cout << "6 - вывести размер файла" << endl;
    cout << "7 - показать содержимое файла" << endl;
    cout << "8 - удалить файл" << endl;
    cout << endl;
    cout << "ПАПКИ: " << endl;
    cout << "9 - создать папку" << endl;
    cout << "10 - показать содержимое папки" << endl;
    cout << "11 - переименовать папку" << endl;
    cout << "12 - копировать папку" << endl;
    cout << "13 - создать файл в папке" << endl;
    cout << "14 - показать размер папки" << endl;
    cout << "15 - произвести поиск по маске" << endl;
    cout << "16 - удалить папку" << endl;
    cout << "ответ: ";
    cin >> answer;
    string data;
    string newName;
    string copyFrom;
    string copyTo;
    string directoryName;
    string mask;
    switch(answer){
        case 1:
            
            manage.createFile();
            
            break;
            
        case 2:
           
            cout << "введите ваши данные: ";
            cin >> data;
            manage.writeFile(data);
            
            break;
            
        case 3:
            manage.readFile();
            break;
            
        case 4:
            cout << "введите новое название файла: ";
            cin >> newName;
            manage.File:: Rename(newName);
            
            break;
            
        case 5:
            manage.copyFile(copyFrom, copyTo);
            break;
            
        case 6:
           cout << "size: " << manage.getFileSize() << endl;
            break;
            
        case 7:
            manage.printFile();
            break;
            
        case 8:
            manage.deleteFile();
            break;
            
        case 9:
            manage.createDirectory();
            break;
            
        case 10:
            manage.printDirectory();
            break;
            
        case 11:
            cout << "введите название папки для получения её размера: ";
            cin >> directoryName;
            manage.getDirectorySize(directoryName);
            break;
            
        case 12:
            cout << "введите новое название папки: ";
            cin >> newName;
            manage.Directory:: Rename(newName);
            break;
            
        case 13:
            cout << "введите имя для нового файла: ";
            cin >> data;
             manage.createFileInDirectory(data);

            break;
            
        case 14:
            cout << "введите название папки для получение её размера: ";
            cin >> directoryName;
            cout << manage.getDirectorySize(directoryName) << endl;
            break;
            
        case 15:
            manage.findFilesByMask(directoryName, mask);
            break;
            
        case 16:
            manage.deleteDirectory();
            break;
            
        default:
            cout << "вы сделали неправильный выбор" << endl;
            break;
    }
}
