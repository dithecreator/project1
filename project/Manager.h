//
//  Manager.h
//  project
//
//  Created by Дима on 15.10.23.
//

#ifndef Manager_h
#define Manager_h
#include "User.hpp"
#include "File.hpp"
#include "Directory.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
class Manager: public User, public File, public Directory{
public:
    Manager() = default;
};


#endif /* Manager_h */
