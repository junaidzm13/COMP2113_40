# COMP2113_40
## COMP2113 final project repository.
### Team members:
1. **Name:** MALIK Muhammad Junaid Zubair | **UID:** 3035445974
2. **Name:** REHMAN Ismail Abdul | **UID:** 3035604520

### Game description:
We have planned to implement a game called ludo. It is a game that accommodates either two or four players (at least in our implementation). Each player has four tokens and will play on their own (in other words no teams will be allowed). Each player will roll a dice on their turn and move tokens accordingly. Each player’s goal is to finish the whole round of the board with each of their tokens to win. The player who finishes all the rounds first would be ranked first and the other 3 rankings are given accordingly.
More information can be found here: https://en.wikipedia.org/wiki/Ludo_(board_game)

### Basic rules and regulations:
  - Each player has their starting point called base.
  - Token can only come out of the base, with a 6.
  -	If the player gets a 6 on a die, the player gets another turn.
  -	Other players can kill your token if it’s not on a star (a safe point). Killing here means to send the token back to the start (i.e.    back to their base).
  -	Once each token completes 81 steps (i.e. one whole round) they will reach their ultimate safe point. Where they would need exact numbers to reach their home. For instance, if a token is at the 81st step then it needs 5 to reach home.
  -	Once the token reaches home it cannot be used again.
  -	Once all of the tokens reach home, the player finishes the game.
  -	If your tokens completed their rounds faster than other player’s tokens, you are ranked above that player.

### Coding requirements:
  1. **Generation of random game sets or events:** Rolling a dice at each user’s turn.
  2.	**Data structures for storing game status:** We will be using two types of data structures to represent different information. First, one data structure will be used during the game, showing the current status of the game, how do the players rank at a point in time. The second data structure will be used to store each user’s information including but not limited to username, winning percentage, last 5 games results, current XP, etc.
  3.	**Dynamic memory management:**
  4.	**File input/output:** Once the user enters his/her username, the file containing all the usernames will be used to check against the list of users and will respond accordingly whether such a user exists or not. And if exists, will load that user’s file, if not will create another user. File output will also be used to store each user’s information in a separate file. After each game, file output will be used to write to the file to update user’s information. 
  5. **Program codes in multiple files:** Most of the functions mentioned below will be written in separate files, will be compiled separately and all the files will then be linked together to generate a single executable.
  
### Functions:

**Main function:**
 Main function will have the following features:
  -	Will ask the user how many players (2 or 4)
  -	Depending on the input will ask how many users to include and how many computer bots.
  -	Then depending on the number of users, will prompt the users for usernames.
  -	Will ask each user to choose their token symbol (this choice depends on XP, the higher your XP the more token symbols you unlock)
  -	Next, will set the board.
  -	The players will play turn by turn
  -	Players will keep winning, until only 1 player remains
  -	The game will output the result of the game
  -	Will update each user’s profile
  -	Will then prompt whether to play another match or to quit

**read_username:** This function will prompt user for the username input and will accordingly either load the user’s info or will ask for confirmation to create a new user with that username.

**create_board:** This function will create a board as an array.

**show_board:** This function will take an array and will show the board as an output to the screen.

**roll_dice:** This function will generate a random number between 1 to 6 imitating a die. After this function the player will be asked to make a move.

**which_token:** This function will take an array representing a board and an integer representing the result of rolling a dice. And will output to the screen the tokens (1 to 4) that the player is allowed to move depending on their current positions and the number. Will keep on prompting the user unless the user inputs the number of the allowed token. The function will return this token number. If all tokens will be unable to move, the function will return -1. 

**kill_token:** This function will take 2 parameters one is a token number and the other is a number say dice_output representing the output of a dice. This function will check whether the move made by the user will kill any other user’s token. Function will return a Boolean representing true or false. (Killing means whether the current user’s token will land on any other user’s token which is not a safe point called a star) 

**make_move:** This function will take 3 parameters. An array representing the board, and two integers representing the token (1 to 4) and the number of steps that will move. The function will modify the array representing the board accordingly.

**has_won:** This function will take 2 parameters, a character representing the user’s token symbol and an array representing the board to check whether the user defined by that symbol has won the game. Function will return a Boolean.

**update_profile:** This function will take 3 parameters, one a string representing the user’s username, an integer representing the number of users and third an integer representing the rank of the user. The function will update the user’s profile by updating the data in his/her text file (<username>.txt).
