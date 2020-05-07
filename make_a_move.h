//make_a_move.h
#include <iostream>
#include <string>
#include "structs.h"
using namespace std;
#ifndef MAKE_A_MOVE_H
#define MAKE_A_MOVE_H

void token_movement(int player_number, int dice_roll, int &row_index, int &col_index);
char itoc(int i);
int ctoi(char c);
int check_digit(string num);
bool can_move(string board[][15], int player_number, int dice_roll, string token);
string will_kill(string board[][15], int player_number, string token, int row_index, int col_index);
void linear_search(int position[], string board [][15], string token );
void make_a_move(Player_current_details *, int, int, int, int, string [][15]);
void replace_old_position(Player_current_details *, string [][15], int, int, string, int);
void replace_new_position(Player_current_details *, int, string [][15], int, int, string, int);
void send_base(string board[][15], int player_killed, string token2);

#endif
