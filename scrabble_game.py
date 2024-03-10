# Purpose: Number Scrabble Game, list of numbers between 1 and 9.
#            Each player takes turns picking a number from the list. Once a number has been picked, it cannot be picked again.
#            If a player has picked three numbers that add up to 15, that player wins the game.
#            However, if all the numbers are used and no player gets exactly 15, the game is a draw.


# Initializing (1-9) list
scrabble = ["1","2","3","4","5","6","7","8","9"]


# Give User Game Description & Instructions
print("This is Scrabble Game")
print("This is a 2 player game,")
print("Every Player's turn will have to pickup a number of numbers between 1 and 9")
print("Once a number has been picked, it cannot be picked again")
print("If a player has picked three numbers that add up to 15, that player wins the game.")
print("However, if all the numbers are used and no player gets exactly 15, the game is a draw.")

# Initialize empty list called players_nums to keep track of the numbers chosen by each player
players_nums = [[],[]]

# Initialize Current player
current_player = 1


# Game loop while there are still numbers in the scrabble list
while scrabble:
    print("-------------------------------------------------------------------------------------------------")
    print(f'Available numbers are: {scrabble}') # Display Available numbers

    num = (input(f'Player {current_player} turn, pick a number from the list: ')) # prompt user to pick a number
    
    # Check if number available to be picked
    if num not in scrabble: # If Input was wrong, Prompt user to re-enter a number, and continue
        print("Invalid number, try again.")
        continue


    # If number correctly picked, remove from list and add to players_nums
    players_nums[current_player-1].append(int(num))
    scrabble.remove(num)

    # Check for winner
    if len(players_nums[current_player-1]) >= 3: # Checks if list length is greater than or equal to 3 (Game Condition: 3 numbers sum is 15)
        # 3 nested loops to try every available combination
        for i in range(len(players_nums[current_player-1])):
            for j in range(i+1, len(players_nums[current_player-1])):
                for k in range(j+1, len(players_nums[current_player-1])):
                    if players_nums[current_player-1][i] + players_nums[current_player-1][j] + players_nums[current_player-1][k] == 15: # If 3 numbers sum is 15, Player wins
                        print(f'Player {current_player} wins!')
                        print(f"Player {current_player} winning list: [{players_nums[current_player-1][i]}, {players_nums[current_player-1][j]}, {players_nums[current_player-1][k]}]")
                        exit()


    # Switch Current Player, Using Relative relation between 1,2,3, Player 1 --> 3-1=2 --> Change player to 2
    current_player = 3 - current_player


# If the loop ended without a winner, It's a draw
else:
    print("It's a draw!")