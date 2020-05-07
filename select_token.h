//select_token.h
#include <iostream>
#include <string>
using namespace std;
#ifndef SELECT_TOKEN_H
#define SELECT_TOKEN_H

string available_tokens(string user_tokens, string chosen_tokens, int size);
char select_token(string user_tokens, string chosen_tokens);

#endif
