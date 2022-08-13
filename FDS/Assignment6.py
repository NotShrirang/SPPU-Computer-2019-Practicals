# Assignment 6
def partition(array, l, h):
    i=l-1
    pivot=array[h]
    j=l
    while(l<=j<h):
        if(array[j]<=pivot):
            i=i+1
            array[i], array[j] = array[j], array[i]
        j+=1
    array[i + 1], array[h] = array[h], array[i + 1]    
    return i+1

def quicksort(array, l, h):
    if (l<h):
        q=partition(array,l,h)
        quicksort(array, l, q-1)
        quicksort(array, q+1, h)


while(True):
    length=int(input("Enter number of students :"))
    if(length<0):
        print("Negative value. Please re-enter!")
    else:
        break
i=0
marklist=[None]*length
while(i<length):
    mark=float(input("Enter marks :"))
    if(mark<0):
        print("Negative. Please re-enter.")
        i=i-1
    else:
        marklist[i]=mark
    i=i+1
print("Unsorted array :", marklist)
quicksort(marklist, 0, length-1)
print("Sorted array :", marklist)
i=length-1
j=1
while(i>length-6):
    print(j, "-", marklist[i])
    i=i-1
    j=j+1