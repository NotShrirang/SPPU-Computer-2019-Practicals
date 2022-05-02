class HashTable:
    def __init__(self, num) -> None:
        self.size = int(num)
        self.dictionary = [[None]]*num
    def isEmpty(self):
        for x in self.dictionary:
            if x[0] == None :
                pass
            else:
                return "List is not empty!"
        return "List is empty!"
    def hash(self, key):
        return key % self.size
    def insert(self, key, value):
        key = hash(key)
        if ((len(self.dictionary[key]) == 1) and (self.dictionary[key][0]==None)) :
            self.dictionary[key] = [value]
        else:
            self.dictionary[key].append(value)
            pass
    def display(self):
        print(self.dictionary)
    def search(self, value):
        key

if __name__ == '__main__':
    while(1):
        try:
            num = int(input("Enter total number : "))
        except:
            print("Enter an integer!")
            continue
        if(num<=0):
            print("Enter non-zero positive number!")
        elif(num>0):
            break
    mydictionary = HashTable(num)
    while(1):
        try:
            choice = int(input("Enter :\n1. Insert\n2. Display\n3. Search\n4. Exit "))
        except:
            print("Enter an integer!")
            continue
        match choice:
            case 1 : 
                key = int(input("Enter key :"))
                value = input("Enter value :")
                mydictionary.insert(key=key, value=value)
            case 2 :
                mydictionary.display()
            case 3 :
                pass
            case 4 :
                exit()

    # mydictionary.display()
    # mydictionary.insert(1, 1)
    # mydictionary.display()
    # mydictionary.insert(1, 2)
    # mydictionary.display()