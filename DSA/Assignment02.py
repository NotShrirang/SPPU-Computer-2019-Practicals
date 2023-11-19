class HashTable:
    def __init__(self, num) -> None:
        self.size = int(num)
        self.dictionary = [[None]]*num
    def isEmpty(self) -> str:
        for x in self.dictionary:
            if x[0] == None :
                pass
            else:
                return "List is not empty!"
        return "List is empty!"
    def hash(self, key) -> int:
        return key % self.size
    def search(self, key, value) -> str:
        if value in self.dictionary[key]:
            return True
        else:
            return False
    def insert(self, key, value) -> bool:
        key = self.hash(key)
        if(self.search(key, value)):
            return False
        else:
            if ((len(self.dictionary[key]) == 1) and (self.dictionary[key][0]==None)) :
                self.dictionary[key] = [value]
            else:
                self.dictionary[key].append(value)
            return True
    def display(self) -> None:
        print(self.dictionary)


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
            choice = int(input("\nEnter :\n1. Insert\n2. Display\n3. Search\n4. Exit\n-->"))
        except:
            print("Enter an integer!")
            continue
        match choice:
            case 1 : 
                key = int(input("Enter key :"))
                value = input("Enter value :")
                state = mydictionary.insert(key=key, value=value)
                print("Inserted successfully!") if state else print("Element is already present")
            case 2 :
                mydictionary.display()
            case 3 :
                key = int(input("Enter key : "))
                value = input("Enter value :")
                if(mydictionary.search(hash(key), value)):
                    print("Element is present!")
                else:
                    print("Element is not present!")
            case 4 :
                del mydictionary, key, value
                print("Object has been deleted!")
                print("Exiting Program...")
                exit()
            case _ :
                print("Enter valid option!")