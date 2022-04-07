# Consider a telephone book db of N clients. Make use of a hash table implementation to quickly
# look up client's telephone number. Make use of 2 collision handling techniques.
# and compare them using number of comparisons required to find a set of telephone numbers.
# Input : 
#   N clients
# For each client : Name & Telephone No.
def hash(num) -> int:
    return int(num % total_numbers)
def linearProbingWithoutReplacement(h) -> int:
    if(h==total_numbers-1):
        h = 0
        return(h)
    else:        
        return(h+1)
def search(num) -> bool:
    if(hashTable[num]!=(None, None)):
        return True
    else:
        return False
def insert(name, num) -> int:
    hashed_num = hash(num)
    if(search(hashed_num)): 
        hashed_num = hash(num)
        counter = 0
        while(search(hashed_num)):
            if(counter==total_numbers-1):
                print("Hash Table is full!")
            hashed_num = linearProbingWithoutReplacement(hashed_num)
            counter += 1
        hashTable[int(hashed_num)] = (name, num)
        return 2
    else:
        hashed_num = hash(num)
        hashTable[int(hashed_num)] = (name, num)
        return 1
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

hashTable = [(None, None)]*total_numbers
displayHashTable()

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
                    insert(name, number)
            case 2 : 
                displayHashTable()
            case 3: 
                break
    except:
        print("Enter valid choice.")
    
# insert("Shrirang", 9404797231)
# insert("Shrirang", 9404797231)
# insert("Shrirang", 9404797231)