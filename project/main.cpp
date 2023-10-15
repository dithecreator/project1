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
#include "Manager.hpp"
using namespace std;

int main() {
    Manager file;
    string data = "hello";
    file.writeFile(data);
    string filename = "file.txt";
    file.printFile(filename);
}
