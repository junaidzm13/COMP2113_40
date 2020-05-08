//read_username.h
#include <iostream>
#include <string>
#include "structs.h"
using namespace std;
#ifndef READ_USERNAME_H
#define READ_USERNAME_H

void create_new(string username);
bool read_username(string username, Player_current_details *players, int i);
string enter_username(Player_current_details *players, int i);

#endif
