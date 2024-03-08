import random
from enum import IntEnum

class Actions(IntEnum):
    rock =0
    paper = 1
    scissors =2

def get_user_selection():
    user_input = input("Enter a choice (rock[0], paper[1], scissors[2]): ")
    selection = int(user_input)
    action = Actions(selection)
    return action

def get_computer_selection():
    selection = random.randint(0,len(Actions)-1)
    action= Actions(selection)
    return action

def determine_winner(user_action,computer_action):
    if user_action== computer_action:
        print(f"Both players selected {user_action.name}. It's a tie")
    elif user_action == Actions.rock:
        if computer_action == Actions.scissors:
            print("Rock smashes scissors! You win!")
        else:
            print("Paper covers rock! You lose.")
    elif user_action == Actions.paper:
        if computer_action == Actions.rock:
            print(f"Paper covers Rock, You Win!")
        else:
            print(f"Scissors cut paper, You Lose!")
    elif user_action == Actions.scissors:
        if computer_action == Actions.paper:
            print(f"Sciccors cuts paper, You Win!")
        else:
            print(f"Rock smashes scissors! You lose")

while True:
    try:
        user_action = get_user_selection()
    except ValueError as e:
        range_str = f"[0{len(Actions)-1}]"
        print(f"Invalid Selection. Enter a value in range {range_str}")
        continue

    computer_action = get_computer_selection()
    determine_winner(user_action, computer_action)

    play_again = input("Play again? (y/n): ")
    if play_again.lower() != "y":
        break
