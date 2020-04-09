# COMP2113_40
## COMP2113 final project repository (Group 40)
### Team members:
1. **Name:** MALIK Muhammad Junaid Zubair | **UID:** 3035445974
2. **Name:** REHMAN Ismail Abdul | **UID:** 3035604520

### Game description:
We have planned to implement a game called ludo. A game that accommodates either 2 or 4 players. Each player has four tokens and will play on their own (in other words no teams will be allowed). Each player will roll a dice on their turn and will move tokens accordingly. Each player’s goal is to finish the whole round of the board with each of their tokens to win. The player who finishes all the rounds first would be ranked first and the other 3 rankings are given accordingly.
More information can be found here: https://en.wikipedia.org/wiki/Ludo_(board_game)

### Basic rules and regulations:
  - Each player has their own starting point called base.
  - Token can only come out of the base, with a number 6 on a dice.
  -	If the player gets a 6 on a dice, the player gets another turn.
  -	Other players can kill your token if it’s not on a star (SS point in the board below). Killing means to send the token back to the start (i.e.    back to their base). You can see in the board below that tokens are in their bases at the start. 
  -	Once each token completes 81 steps (i.e. one whole round) they will reach their ultimate safe point(for example, BS is a safe points for player B and on one can kill him) In these types of safe points, only the specific player's token can be played( for example, on BS points no other player can come neither kill player B). Where they would need exact numbers to reach their home( for example, BH is the home point for player B). For instance, if a token is at the 81st step then it needs exactly 5 more steps to reach home.
  -	Once the token reaches home it cannot be used again.
  -	Once all of the tokens reach home, the player finishes the game.
  -	If your tokens completed their rounds faster than other player’s tokens, you are ranked above that player.

### Board:
  -- -- -- -- -- -- XX XX XX -- -- -- -- -- --
  -- R1 -- R2 -- -- XX YS SS -- -- Y1 -- Y2 --
  -- -- -- -- -- -- XX YS XX -- -- -- -- -- --
  -- R3 -- R4 -- -- XX YS XX -- -- Y3 -- Y4 --
  -- -- -- -- -- -- XX YS XX -- -- -- -- -- --
  -- -- -- -- -- -- XX YS XX -- -- -- -- -- --
  XX SS XX XX XX XX -- YH -- XX XX XX XX XX XX
  XX RS RS RS RS RS RH -- GH GS GS GS GS GS XX
  XX XX XX XX XX XX -- BH -- XX XX XX XX SS XX
  -- -- -- -- -- -- XX BS XX -- -- -- -- -- --
  -- -- -- -- -- -- XX BS XX -- -- -- -- -- --
  -- B1 -- B2 -- -- XX BS XX -- -- G1 -- G2 --
  -- -- -- -- -- -- XX BS XX -- -- -- -- -- --
  -- B3 -- B4 -- -- SS BS XX -- -- G3 -- G4 --
  -- -- -- -- -- -- XX XX XX -- -- -- -- -- -- 
  read: bad option: -1

**Explanation of board**

### Coding requirements:
  1. **Generation of random game sets or events:** Rolling a dice at each user’s turn.
  2.	**Data structures for storing game status:** We will be using two types of data structures to represent different information. First data structure will be used during the game, showing the current status of the game; usernames of the players and how do the players rank at a point in time. Second data structure will be used to store each user’s profile including but not limited to his/her username, winning percentage, last 5 games results, current XP, etc.
  3.	**Dynamic memory management:** Dynamic arrays / pointers will be used to store the list of usernames read from a file called usernames.txt. Dynamic arrays / pointers will also be used to store the usernames of the users playing the game.
  4.	**File input/output:** Once the user inputs his/her username, the file, usernames.txt which contains all the usernames will be used to check whether such a user exists or not. And if it does, the program will load that user’s file, if not will create a new username. File output will also be used to store each user’s profile in a separate file <username>.txt. After each game, file output will be used to write to the file to update all users' profile, depending on the result of the game. 
  5. **Program codes in multiple files:** Most of the functions mentioned below will be written in separate files and will be compiled separately. All the files will then be linked together to generate a single executable.
  
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
  -	The program will then output the result of the game
  -	Will update each user’s profile
  -	Will then prompt user whether to play another match or to quit

**read_username:** This function will prompt user for the username input and will accordingly either load the user’s info or will ask for confirmation to create a new user with that username.

**create_board:** This function will create a board as an array.

**show_board:** This function will take an array as a parameter and will show the board as an output to the screen.

**roll_dice:** This function will generate a random number between 1 to 6 imitating a dice.

**which_token:** This function will take 3 parameters: an array representing a board, an integer representing the result of rolling a dice and a character representing the player's symbol. And will output to the screen the tokens (1 to 4) that the player is allowed to move depending on the tokens' current positions and the number obtained from rolling a dice. Will keep prompting the user unless the user inputs the number of the allowed token. The function will return this token number. If all tokens will be unable to move, the function will return -1. 

**kills_token:** This function will take 4 parameters: an array representing the board, 2 integers, one is a token number, the other is a number say dice_output representing the output of a dice and 1 character representing the player's token symbol. This function will check whether the move made by the player will kill any other player’s token. Function will return a Boolean representing true or false. (Killing means whether the current player’s token will land on any other player’s token which is not a safe point called a star) 

**make_move:** This function will take 4 parameters. An array representing the board, two integers representing the token (between 1 and 4) and the number of steps that will move and a character representing the current player's token symbol. The function will modify the array representing the board accordingly.

**has_won:** This function will take 2 parameters, a character representing the user’s token symbol and an array representing the board to check whether the user defined by that symbol has won the game. Function will return a Boolean.

**update_profile:** This function will take 3 parameters, a string representing the user’s username, an integer representing the number of users and third an integer representing the rank of the user. The function will update the user’s profile by updating the data in his/her text file (<username>.txt).
