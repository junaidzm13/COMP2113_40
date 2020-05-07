//read_username.h
#include <iostream>
#include <string>
#include "structs.h"
using namespace std;
#ifndef UPDATE_PROFILE_H
#define UPDATE_PROFILE_H

int getxp(int rank, int num_players);
string tokens_unlock(int level);
void update_profile(Profile &username, int num_players, int rank);

#endif
