#Bubble Sort
n=0
def BubbleSort(array):
    global n
    i=0
    counter=0
    while(i<n):
        j=0
        while(j<((n-i)-1)):
            temp=array[j]
            if(array[j]>array[j+1]):
                array[j]=array[j+1]
                array[j+1]=temp
                print(array)
            j=j+1
            counter=counter+1
        i=i+1
    print("Sorted : ", array)
    print("I did", counter, "comparisons for this!")

n=int(input("How many students:"))
array=[None]*n
i=0
while(i<n):
    mark=float(input("Enter marks:"))
    if(mark<0):
        print("Value is negative.")
        i=i-1
    else:
        array[i]=mark
    i=i+1
print("Unsorted :",array)
BubbleSort(array)
print("Toppers are:", array[-5:n])



