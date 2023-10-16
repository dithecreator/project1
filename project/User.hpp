//
//  User.hpp
//  project
//
//  Created by Дима on 16.10.23.
//

#ifndef User_hpp
#define User_hpp
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class User{
protected:
    string nickname;
    string password;
    
public:
    
    User();
    void signIn();
    void login();
};

#endif /* User_hpp */
