## Assignment 4
while True:
    length=int(input("Enter number of students :"))
    if(length>0):
        break
    if(length<0):
        print("You have entered negative value. Please re-enter it.")

def InsertionSort(marklist):
    global length
    print("\nUnsorted marks are :", marklist, "\n")
    i=0
    j=0
    count=0
    while(i<length):
        key=marklist[i]
        j=i-1
        while(j>=0 and marklist[j]>key):
            marklist[j+1]=marklist[j]
            j=j-1
        marklist[j+1]=key
        i=i+1
        count=count+1
        print("Pass", count, ":-", marklist)
    print("\nSorted marks are :", marklist)
    print("\nTop five scores are,\n1.",marklist[-1],"\n2.",marklist[-2],"\n3.",marklist[-3],"\n4.", marklist[-4],"\n5.", marklist[-5])
    print("\n#############################################################################################\n")

def ShellSort(marklist):
    global length
    print("\nUnsorted marks are :", marklist, "\n")
    n = length
    count=0
    gap = n//2
    while gap > 0:
        for i in range(gap,length):
            temp = marklist[i]
            j = i
            while  (j >= gap and marklist[j-gap] >temp):
                marklist[j] = marklist[j-gap]
                j -= gap
            marklist[j] = temp
            count=count+1
            print("Step", count, ":-", marklist)
        gap //= 2       
    print("\nSorted marks are :", marklist)
    print("\nTop five scores are,\n1.",marklist[-1],"\n2.",marklist[-2],"\n3.",marklist[-3],"\n4.", marklist[-4],"\n5.", marklist[-5])
    print("\n#############################################################################################\n")

i=0
marklist=[None]*length
while(i<length):
    marks=float(input("Enter marks :"))
    if(marks<0):
        print("You have entered negative value. Please re-enter it.")
        i=i-1
    else:
        marklist[i]=marks
    i=i+1

print("\nUnsorted marks are :", marklist)
boolean=True
while(boolean==True):
    choice=int(input("Enter choice :\n1 - Insertion Sort\n2 - Shell Sort\n0 - Exit.\n\n-->"))
    if (choice==1):
        print("\n#############################################################################################\n")
        InsertionSort(marklist)
    elif(choice==2):
        print("\n#############################################################################################\n")
        ShellSort(marklist)
    elif(choice==0):
        break
