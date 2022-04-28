def displayHashTable():
    print(f"\nEntries : {total_numbers}")
    i = 0
    for bucket in hashTable:
        print(f"\t{i} : {bucket[0]} - {bucket[1]}")
        i += 1
def isFull() -> bool:
    count = 0
    for bucket in hashTable:
        if(bucket[0]!=None):
            count += 1
    if(count==total_numbers):
        return True
    else:
        return False

while(True):
    total_numbers = int(input("Enter total numbers :"))
    if(total_numbers != 0):
        break

hashTable = [[None, [1, 2]]]*total_numbers

while(True):
    choice = input("Enter Choice :\n1. Insert new number\n2. Display\n3. Exit\n-->")
    try:
        match int(choice):
            case 1 :
                if(isFull()):
                    print("Hash Table is full!")
                else:
                    name = input("Name : ")
                    while(True):
                        number = int(input("Num : "))
                        if(number<=999999999):
                            print("Invalid Number! Please re-enter!")
                        else:
                            break
                    # insert(name, number)
            case 2 : 
                displayHashTable()
            case 3: 
                exit(1)
    except:
        print("Enter valid choice.")