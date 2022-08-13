import random
class Player:
    def __init__(self, name) -> None:
        self.location = 1
        self.name = name
        print(f"Welcome {self.name}!")
    def rollDice(self):
        roll = random.randint(1, 6)
        print(f"\n{self.name} : rolled {roll}.")
        self.location = self.location + roll
        print(f"{self.name} : went to {self.location}.")
        for key, value in snakes_ladders.items():
            if self.location == key:
                self.location = value
                if(key>value):
                    print("Ahh... Snake bit you!")
                    print(f"{self.name} : went to {self.location}.")
                    break
                elif(key<value):
                    print("Nice! A ladder.")
                    print(f"{self.name} : went to {self.location}.")
                    break
        if(self.location >= 100):
            print(f"{self.name} won!!!")
            quit()

if __name__ == '__main__':
    snakes_ladders = {
                    1  : 38,
                    4  : 14,
                    8  : 30,
                    21 : 42,
                    28 : 76,
                    32 : 10,
                    34 : 6,
                    48 : 26,
                    50 : 67,
                    62 : 18,
                    71 : 92,
                    80 : 99,
                    88 : 24,
                    95 : 66,
                    97 : 78}
    name1 = input("Enter name of player 1 : ")
    player1 = Player(name1)
    name2 = input("Enter name of player 2 : ")
    player2 = Player(name2)
    i = 1
    while(True):
        choice = input("\nContinue? (Y/N) : ")
        if(choice == "Y" or choice == "y"):
            if(i%2 == 1):
                player1.rollDice()
                i += 1
            else:
                player2.rollDice()
                i += 1 
        elif(choice == "N" or choice == "n"):
            break
        else:
            pass