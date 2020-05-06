# COMP2113_40
## COMP2113 final project repository (Group 40)
### Team members:
1. **Name:** MALIK Muhammad Junaid Zubair | **UID:** 3035445974
2. **Name:** REHMAN Ismail Abdul | **UID:** 3035604520

### Game description:
We have implemented a game called ludo. The game will accommodate 2, 3 or 4 players. Each player will have four tokens at the start and will play on their own (in other words no teams will be allowed). Each player will roll a dice on their turn and will move tokens accordingly. Each player’s goal is to finish the whole round of the board with each of the four tokens to win. The player who finishes all the rounds first would be ranked first and the other players are ranked accordingly.
More information can be found here: https://en.wikipedia.org/wiki/Ludo_(board_game)

### Game manual:
### How to setup / play:

#### Rules and regulations
  - Each player has their own unique starting point called base.
  - Token can only come out of the base with a number 6 on a dice.
  -	If the player gets a 6 on a dice, the player gets another turn.
  - If the player gets three 6's in a row, the player looses his turn.
  -	Other players can kill your token if it’s not on a star (denoted by **\*S** on the board). Killing means to send the token back to the start (i.e. back to their base). You can see in the board  that tokens are in their respective bases at the start.
  - A player can create a temporary safe point anywhere by placing two of his own token at a point. That point will be a temporary safe point for everyone until only one (or none) token is left at that point. 
  -	Once each token completes 81 steps (i.e. one whole round) they will reach their ultimate safe point (denoted by **\<token symbol\>S**). Points denoted by **\<token symbol\>S** cannot be used by any other player except the player with that token. If a token is at the 81st (1st ultimate safe point) step then it needs exactly 5 more steps to reach home (denoted by **\<token symbol\>H**).
  -	Once the token reaches home, it cannot be used again.
  -	Once all of the tokens of a player reach home, that player finishes the game while others continue to play the game until only one player is left in the game.
  -	If your tokens completed rounds faster than the other player’s tokens, you are ranked above that player.
  
### Special features:
  - Based on the user's XP (accumulated by winning) user will unlock various token symbols. Then user can choose his/her token symbol for the curremt game. While in traditional ludo there are only 4 symbols available R(red), B(blue), G,(green) and Y(yellow).
  - Moreover, each player will have his unique username, and that username will be used to retreive the user's profile.
  - Profile will have information on the user's level, XP, total matches played, total matches won, available tokens and winning percentage.
  - Profile for each user will also be displayed at the end of the game.

### Board:
[Board example together with some explanation](board.txt)

### Coding requirements:
  1. **Generation of random game sets or events:** Rolling the dice at each user’s turn.
  2.	**Data structures for storing game status:** We have used two types of data structures to represent different information. First data structure will be used during the game, showing the current status of the game; usernames of the current players, their rank, and their chosen tokens. Second data structure will be used to store each user’s profile including his/her username, level, XP, matches played, matches won, winning percentage and all the unlocked tokens.
  3.	**Dynamic memory management:** Dynamic arrays have been used to store the data structures namely *Profile* and *Current_player_details* of all the players. The size is equal to the number of players. Secondly, we have also implemented integer vectors which store the result of all the dice rolls at a single turn (in *make_a_move* function).
  4.	**File input/output:** File input/output has been done several times during a single run of the game. First, the file named *usernames.txt* is read to check whether the entered username already exists. If it does the file corresponding to that username is opened and read to load the profile of that user. If it does not exist, then the based on user's confirmation, a new file with name \<username\>.txt is created and the new username is written down in *usernames.txt*. And once the game ends, all the player's profiles are updated by writing down in their respective files.
  5. **Program codes in multiple files:** All of the functions have been separated into different files. Each file contains one or more functions depending on the task that they perform. We also have a separate header file for both of the major structures defined. In total we have 20 different files (including header files).
  
### Functions:

**Main function:**
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

**roll_dice**: This function will generate a random number between 1 and 6 imitating a dice. If there is a 6, it will roll the dice again. If there are three 6's in a row, the player looses his turn.

**set_the_board**:

**show_board**:This function will take an array as a parameter and will show the board as an output to the screen.

**available_tokens**:

**select_token**:

**read_username**:

**create_new**:

**load_profile**:

**enter_username**:

**getxp**:

**tokens_unlock**:

**update_profile**:

**token_movement**:

**itoc**:

**ctoi**:

**check_digit**:

**can_move**:

**will_kill**:

**has_won**:

**linear_search**:

**searchVector**:

**printVector**:

**populateVector**:

**make_a_move**:

**replace_old_position**:

**replace_new_position**:

**send_home**:






**read_username:** This function will prompt the user for the username input and will accordingly either load the user’s profile or will ask for confirmation to create a new user with that username.

**create_board:** This function will create a board as an array. 

**show_board:** This function will take an array as a parameter and will show the board as an output to the screen.

**which_token:** This function will take 3 parameters: an array representing a board, an integer representing the result of rolling a dice and a character representing the player's token symbol. And will output to the screen the tokens (1 to 4) that the player is allowed to move depending on the tokens' current positions and the number obtained from rolling a dice. Will keep prompting the user unless the user inputs the number of the allowed token. The function will return this token number. If all tokens will be unable to move, the function will return -1. 

**kills_token:** This function will take 4 parameters: an array representing the board, 2 integers, one is a token number, the other is a number say dice_output representing the output of a dice and 1 character representing the player's token symbol. This function will check whether the move made by the player will kill any other player’s token. Function will return a boolean representing true or false. (Killing means whether the current player’s token will land on any other player’s token which is not on a safe point called a star) 

**make_move:** This function will take 4 parameters. An array representing the board, two integers representing the token (between 1 and 4) and the number of steps that it will move and a character representing the current player's token symbol. The function will modify the array representing the board accordingly.

**has_won:** This function will take 2 parameters, a character representing the user’s token symbol and an array representing the board to check whether the user defined by that symbol has won the game. Function will return a boolean.

**update_profile:** This function will take 3 parameters, a string representing the user’s username, an integer representing the number of users and third an integer representing the rank of the user. The function will update the user’s profile by updating the data in his/her text file (\<username\>.txt).
