# COMP2113_40 final project repository (Group 40)
### Team members:
1. **Name:** MALIK Muhammad Junaid Zubair | **UID:** 3035445974
2. **Name:** REHMAN Ismail Abdul | **UID:** 3035604520

## Game description:
We have implemented a game called ludo. The game will accommodate 2, 3 or 4 players. Each player will have four tokens at the start and will play on their own (in other words no teams will be allowed). Each player will roll a dice on their turn and will move tokens accordingly. Each player’s goal is to finish the whole round of the board with each of the four tokens to win. The player who finishes all the rounds first would be ranked first and the other players are ranked accordingly.
More information can be found here: https://en.wikipedia.org/wiki/Ludo_(board_game)
*Reference: The idea of the game dates back to the 6th century. However, the name ludo was given by England in 1896 when they patented the game.*

## Game manual:
### How to setup / play:
  - The first step is to compile and run the program. To compile execute "make ludo_main".
  - Then you will have to enter the number of players as a **[single integer]**. Number of players can only be between 2 and 4 inclusive.
  - Then depending on the number of players, each user will be asked to input his/her username **[(username cannot have any whitespaces)]** and if invalid username entered will be prompted "Do you want to create a new profile? (Y/N)", then the user should enter either a Y or N **[Cannot enter anything other than a character]**.  
  - Afterwards, the user will be prompted with a list of token symbols to select from. This list only includes characters and therefore, the user can only enter a **[character]** from the given list (that would be printed along with asking for token symbols).
  - Once, this step is completed, the board will be displayed and the player 1 will be prompted to roll the dice by pressing any character. *Note: Player numbers are given in the same order as the entered usernames*
  - From this onwards, each player will roll the dice on his/her turn (by pressing any key other than "enter" key) and will move the tokens accordingly. After the dice roll at each player's turn, the player will prompted to select the dice roll that he/she would like to move first (if there are more than one dice rolls). Then the player is prompted to select the token that he/she would like to move. Obviously, this depends on whether user has any token that can move.
  - The first player to reach home marked by \<token_symbol\>H (i.e. YH) on the board, with all 4 tokens is given the rank of 1. The subsequent rankings are given accordingly.
  - The remaining players keep playing until a single player remains. At this point, the game ends and that match's rankings are displayed.
  - Then finally based on the results of the game, each player's profile is updated and displayed.

### Game rules:
  - Each player has their own unique starting point called base marked by the empty block with 4 tokens in the middle. You can see in the board that tokens are in their respective bases at the start.
  - There are total of 8 in-game safe points marked by *SS*. Apart from that each player has their ultimate safe points marked by *\<token symbol\>S*. Called ultimate safe point, becasue once the token reaches these points it cannot be killed as no other player can access these points and after this the token is only on its way home.
  - The *xx* marks the playing area together with in-game safe points *SS*. The difference is that at *xx* the token can be killed whereas at *SS* it cannot be. Killing means to send the token back to the start (i.e. back to their base). *Please refer to the board below for further explanation to the above points.*
  - Token can only come out of the base with a number 6 on a dice.
  -	Moreover, if the player gets a 6 on a dice, the player gets another turn. However, if a player gets three consecutive 6s, the player loses his/her turn. 
  -	Once the token reaches home, it cannot be used again.
  -	Once all of the tokens of a player reach home, that player finishes the game while others continue to play the game until only one player is left in the game.
  -	If your all 4 tokens complete their rounds faster than the other player’s tokens, you are ranked above that player.
  - A player can create a temporary safe point anywhere by placing two of his own token at a single point. That point will be a temporary safe point for everyone until only one (or none) token is left at that point. First of this kind of safe point will be shown as *\*1* on the board (*\*2* and so on depending on the total number of such positions at a point in time).
  - Moreover, if there is only 1 token on a particular safe-point, that particular token will be displayed rather than *SS*. However, if more than one token resides on a single safe-point then that point will be displayed as *1S* (or *2S* and so on depending on the total number of such safe points at a point in time).
  - All these positions (*\*1* and *1S*) where more than one token reside, will be displayed separately under the board, reporting the tokens residing there.
  
### Special features:
  - Based on the user's XP (accumulated by winning) user will unlock various token symbols. Then user can choose his/her token symbol for the curremt game. While in traditional ludo there are only 4 symbols available R(red), B(blue), G,(green) and Y(yellow).
  - Moreover, each player will have his unique username, and that username will be used to retreive the user's profile.
  - Profile will have information on the user's level, XP, total matches played, total matches won, available tokens and winning percentage.
  - Profile for each user will also be displayed at the end of the game.

## Board:
[Board example together with some explanation](board.txt)

## Coding requirements:
  1. **Generation of random game sets or events:** Rolling the dice at each user’s turn.
  2.	**Data structures for storing game status:** We have used two types of data structures to represent different information. First data structure will be used during the game, showing the current status of the game; usernames of the current players, their rank, and their chosen tokens. Second data structure will be used to store each user’s profile including his/her username, level, XP, matches played, matches won, winning percentage and all the unlocked tokens.
  3.	**Dynamic memory management:** Dynamic arrays have been used to store the data structures namely *Profile* and *Current_player_details* of all the players. The size is equal to the number of players. Secondly, we have also implemented integer vectors which store the result of all the dice rolls at a single turn (in *make_a_move* function).
  4.	**File input/output:** File input/output has been done several times during a single run of the game. First, the file named *usernames.txt* is read to check whether the entered username already exists. If it does the file corresponding to that username is opened and read to load the profile of that user. If it does not exist, then the based on user's confirmation, a new file with name \<username\>.txt is created and the new username is written down in *usernames.txt*. And once the game ends, all the player's profiles are updated by writing down in their respective files.
  5. **Program codes in multiple files:** All of the functions have been separated into different files. Each file contains one or more functions depending on the task that they perform. We also have a separate header file for both of the major structures defined. In total we have 20 different files (including header files).
  
## Functions:

#### Main function:
 Main function will have the following features:
  -	Will ask the user how many players (2, 3 or 4)
  -	Then will prompt each player for his / her username.
  - If username exists, will load that user's profile or otherwise, will create a new profile.
  -	Will ask each user to choose their token symbol (this choice depends on XP, the higher your XP the more token symbols you unlock)
  -	Next, will set the board depending on the number of players playing
  -	The players will play turn by turn
  -	Players will keep winning, until only 1 player remains
  -	The program will then output the result of the game
  -	Will then update each user’s profile
  -	Will then output the updated profile of each user.

#### roll_dice
This function takes 4 parameters, a Player_current_details structure player, an integer turn_count, No_of_sixes and dice_number.It generates a random number between 1 and 6 imitating a dice. If there is a 6, it will roll the dice again (recursive call). If there are three 6's in a row, the player loses his turn. This function modifies the No_of_sixes and outputs the dice_number (which is the dice roll that not equals 6).

#### set_the_board
This function takes a 15x15 2D string array board, a dynamic array of structure Player_current_details players and an integer representing the number of players. It populates the array with the required strings that immitates a ludo board.

#### show_board
This function takes a 2-D string array board representing a board, a pointer pointing to the dynamic array players containing structure Player_current_details and an integer num_players representing the number of players as parameters and will show the board as an output to the screen.

#### select_token
This function takes two strings, one representing the available tokens to the user depending on user's XP and other representing the already chosen tokens by other players. This function prompts the user to choose tokens from the displayed list of available tokens. Returns the chosen token as a character.

*available_tokens*
This function is a helper function to select_token and takes same parameters as select_token and an integer representing the size of chosen_tokens. It returns a string containing all the tokens availabale to the user.

#### read_username
This function takes a string username, a pointer to an array of Player_current_details (structure) and an int i which equals player number -1. Returns a boolean. Returns true if and only if the username exists in the file *usernames.txt* and is not aleady taken by any other player currently playing.

*enter_username*:
This function takes two parameters, a pointer to an array of Player_current_details players and an int i, which equals player number - 1. Prompts the user to enter his/her username. Calls read_username to check whether such a username exists or has already been taken. If it does exist and is not taken by any other player playing function returns that username and if it does not exist or has already been taken the function creates a new file \<username\>.txt and returns the new username entered.

*create_new*
This function takes a string username representing a new username, and creates a text file \<username\>.txt representing the profile of the user and writes this username to *usernames.txt*.
  
#### load_profile
This function takes a Profile user as pass by reference and a string representing user's username. This function reads the corresponding file of the user and populates the corresponding structure accordingly.
 
#### update_profile
This function takes Profile structure user representing a profile of a user as pass-by-reference and two integers, one representing the number of players and the other the rank obtained by the user. This function updates the user's text file and updates the structure as well.

*getxp*
This function takes two integers, rank representing the rank of the player and num_players representing the number of players and returns an integer representing xp gained.

*tokens_unlock*
This function takes an integer level representing the level and returns a string representing the token unlocked on that particular level. Only called when levels up.

#### output_profile
This function takes a user's profile user as Profile and outputs to the screen the whole profile of the user with Profile user.

#### has_won
This function takes a 2-D string array representing a board and an integer representing the player number (1, 2, 3 or 4) and outputs a boolean whether the player has won or not. Player has won if all four tokens are accumulated at their respective home positions.

#### make_a_move:
This function takes a dynamic array *player* which contains the details of current players that are playing, four integers, and a 2D array. The first integer *turn_count* represents which player's turn  it is. The second integer *num_players* represent the total number of players who are playing the game. The third integer *No_of_sixes* represent the number of sixes a player got (can only be 0,1,2). The fourth integer *dice_number* represents the number which a player got on the last roll of a die in his turn which can only be 1,2,3,4,5 here. The 2D array named *board* stores the details of token positions.
The purpose of this function is to allow a player to move his token depending on the result from roll_dice function. The selected token by the player will be moved and after every single move, a board will be printed to show the movement of his selected token.

*token_movement*
Given integers player_number, dice_roll (singular), and a token's col and row indices as indexes this function tells you at what position (col and row indices) this token will be at after the move. Changes the values of row_index and col_index (as passed-by-reference).

*itoc*: Converts int i to character type.

*ctoi*: converts digit char c to type int.

*check_digit*
Takes a string and repeatedly prompts the user to enter a single digit. Returns that digit converted to int type.

*can_move*
This function takes 4 parameters, a 2-D 15x15 string array representing the board, 2 integers, player_number and the dice_roll and 4th a string representing the chosen token. This function returns a boolean checking whether the particular token can move or not.

*will_kill*
This function takes 5 parameters, a 2-D 15x15 string array board representing the board, 3 integers, one player_number representing the player number and the other two row_index, col_index representing the new row and column indices of the token respectively and 5th a string representing the chosen token. This function checks whether this token kills another token, if it does this token will return the string containing the token being killed. If no token is being killed, this function will return an empty string.

*linear_search*
This function searches the board to find the target's row and column indices. If found updates the array position else make elements equal -1. position[0] = row index, position[1] = column index.

*searchVector*
This function takes two arguments an integer vector allDiceRolls and an integer selected_dice. This function searches the vector and returns the first index where selected_dice is found. Otherwise, returns -1.

*printVector*
This function prints a integer vector allDiceRolls containing all the dice rolls in a prescribed fashion.

*populateVector*
This function takes an integer vector v (passed-by-reference), and two integers one representing total number of dice rolls Num_of_rolls and the other representing the value of the dice roll that's not equal to 6, dice_number. This function populates the vector with the all the obtained dice rolls at a single turn.

*replace_old_position*
This function takes a dynamic array *player* which contains the details of current players that are playing, three integers, one string, and a 2D array. The 2D array named *board* stores the details of token positions. The string *token* represents the token selected by the player to move. The integer *row* and the integer *column* represtents the position on the board. This position represents the position from which the selected token move to another new postion on board. The third integer *turn_count* represents which player's turn  it is. 
After the player selects a valid token to move, this function will change the last position of token on board as it should be.

*replace_new_position*
This function takes a dynamic array *player* which contains the details of current players that are playing, four integers, one string, and a 2D array. The 2D array named *board* stores the details of token positions. The string *token* represents the token selected by the player to move. The first integer *player_number* represent the total number of players who are playing the game. The integer *row* and the integer *column* represtents the position on the board. This position represents the new postion where the player's selected token will move on the board. The fourth integer *turn_count* represents which player's turn it is. 
After the player selects a valid token to move, this function will change the new position of token on board as it should be.

*send_base*
This function takes a 2D array, one string and one integer.  The 2D array named *board* stores the details of token positions. The integer *player_killed* represents which player is being killed. The string *token2* represents the token that is being killed.
This function will modify the board by sending back the killed token(token2) to it respective bases. It means token2 will now be stored in the respective players base.
