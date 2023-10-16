//
//  User.cpp
//  project
//
//  Created by Дима on 16.10.23.
//

#include "User.hpp"

User:: User(){
    nickname = ' ';
    password = ' ';
}

void User:: signIn(){
    cout << "введите ваш ник: ";
    cin >> nickname;
    
    cout << "введите ваш пароль: ";
    cin >> password;
    
    cout << "регистрация прошла успешно" << endl;
}



void User:: login(){
    string checkNickname;
    string checkPassword;
    cout << "введите ваш ник: ";
    cin >> checkNickname;

    if(checkNickname != nickname){
        cout << "вы ввели неверный логин" << endl;
    }
    
    else{
    cout << "введите ваш пароль: ";
    cin >> checkPassword;
    

    if(checkPassword != password){
        cout << "вы ввели неверный пароль" << endl;
    }
    
    }
    
    if(checkNickname == nickname && checkPassword == password){
        cout << "вход выполнен" << endl;
    }
    
}
