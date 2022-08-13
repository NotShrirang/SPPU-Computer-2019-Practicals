#Assignement 5

#Selection Sort
def selectionSort(array):
    i=0 #loop counter
    j=0 #element counter
    temp=0
    min_marks=100
    for i in range(0,length):
        for j in range(i+1, length):
            min=i
            if(mark_list[j]<mark_list[min]):
                min=j
                mark_list[min], mark_list[i] = mark_list[i], mark_list[min]
        print(mark_list)
    print("Sorted :", mark_list)
    print("Top 5 are:\n1.", mark_list[-1],"\n2.", mark_list[-2],"\n3.", mark_list[-3], "\n4.", mark_list[-4], "\n5.", mark_list[-5])

def bubbleSort(array):
    global length
    i=0
    counter=0
    while(i<length):
        j=0
        while(j<((length-i)-1)):
            temp=array[j]
            if(array[j]>array[j+1]):
                array[j]=array[j+1]
                array[j+1]=temp
                print(array)
            j=j+1
            counter=counter+1
        i=i+1
    print("Sorted : ", array)
    print("Top 5 are:\n1.", mark_list[-1],"\n2.", mark_list[-2],"\n3.", mark_list[-3], "\n4.", mark_list[-4], "\n5.", mark_list[-5])
    
while True:
    length=int(input("Enter number of elements :"))
    if(length<0):
        print("Please enter positive value.")
    else:
        break
i=0
mark_list=[None]*length
while(i<length):
    marks=float(input("Enter marks of student:"))
    if(marks<0):
        print("Error. Please enter positive value.")
        i=i-1
    else:
        mark_list[i]=marks
    i=i+1
print("Unsorted :",mark_list)
while(True):
    choice=int(input("Enter choice:\n1. Selection Sort\n2. Bubble Sort\n9. Exit\n-->"))
    if(choice==1):
        print("\n################################## Selection Sort ########################################\n")
        selectionSort(mark_list)
        print("\n##########################################################################################\n")
        break
    elif(choice==2):
        print("\n#################################### Bubble Sort #########################################\n")
        bubbleSort(mark_list)
        print("\n##########################################################################################\n")
        break
    elif(choice==9):
        break
    else:
        print("You have wrong choice.")