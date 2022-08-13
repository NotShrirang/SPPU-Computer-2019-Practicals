#Assignment2
while(True):
    n=int(input("Enter number of students:"))
    if(n>0):
        break
    else:
        print("Please enter valid value.")

i=0
sum=0
l=[None]*n
absent=0
minimum=101
maximum=0
while (i<n):
    mark=input("Enter marks:")
    if mark=="a":
        absent=absent+1
    else:
        mark=int(mark)
        if(mark<0):
            print("You have entered negative value! Please re-enter.")
            i=i-1
        else:
            sum=sum+mark
            l[i]=mark 
            if(mark<minimum):
                minimum=mark
            elif(mark>maximum):
                maximum=mark  
    i=i+1

boolean=False
i=0
while(i<n):
    if(l[i]==None):
        boolean = True
    else:
        boolen = False
        break
    i=i+1
if(boolean==True):
    print("All students were absent.")
    quit("Nothing to display!")

print("\nAvg =",sum/n)
print("Max =", maximum)
print("Min =", minimum)
print("Absent Students :", absent)

# n is length of array.
print("Students present :", n-absent) 

i=0
j=0
highest_freq=0
highest_marks=0
print(l)
count=0
while(i<n):
    if(l[i]!=None):
        while(j<n):
            if(l[i]==l[j]):
                count=count+1
            j=j+1
    if(count>highest_freq):
        highest_freq=count
        highest_marks=l[i]
    i=i+1
print("Most frequent number is",highest_marks,"with frequency", highest_freq,".\n")







