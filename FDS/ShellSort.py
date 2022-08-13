def ShellSort(arr):
    global length
    n = length
    gap = n//2
    while gap > 0:
        for i in range(gap,length):
            temp = arr[i]
            j = i
            while  (j >= gap and arr[j-gap] >temp):
                arr[j] = arr[j-gap]
                j -= gap
            arr[j] = temp
        gap //= 2

while(True):
    length=int(input("Enter number of students :"))
    if(length<0):
        print("Negative value. Please re-enter!")
    else:
        break
i=0
arr=[None]*length
while(i<length):
    mark=float(input("Enter marks :"))
    if(mark<0):
        print("Negative. Please re-enter.")
        i=i-1
    else:
        arr[i]=mark
    i=i+1

ShellSort(arr)
print("Array after sorting :", arr)