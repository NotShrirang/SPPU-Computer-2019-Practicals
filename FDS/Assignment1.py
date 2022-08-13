## Assignment 1

##Cricket
while True:
    i=int(input("How many students play cricket?\n="))
    if(i<0):
        print("You have entered negative number! Please enter again!")
        pass
    elif(i>0):
        break
a=[None]*i
n=0
while(n<i):
    x=int(input("Enter roll number of student:"))
    if(x>0):
        if x in a:
            print("Already in list!")
            n=n-1
        else:
            a[n]=x
        n=n+1
    elif(x<0):
        print("Negative.")

##Badminton
while True:
    j=int(input("How many students play badminton?\n="))
    if(j<0):
        print("You have entered negative number! Please enter again!")
        pass
    elif(j>0):
        break
b=[None]*j
n=0
while(n<j):
    x=int(input("Enter roll number of student:"))
    if(x>0):
        if x in b:
            print("Already in list!")
            n=n-1
        else:
            b[n]=x
        n=n+1
    elif(x<0):
        print("Negative.")

##Football
while True:
    k=int(input("How many students play football?\n="))
    if(k<0):
        print("You have entered negative number! Please enter again!")
        pass
    elif(k>0):
        break
c=[None]*k
n=0
while(n<k):
    x=int(input("Enter roll number of student:"))
    if(x>0):
        if x in c:
            print("Already in list!")
            n=n-1
        else:
            c[n]=x
        n=n+1
    elif(x<0):
        print("Negative.")


######### Operations on Sets #########
I=[]
count=0
print("Cricket players :", a)
print("Badminton players :", b)
diff=[]
for x in a:
    if(x in b):
        continue
    else:
        diff.append(x)
print("Difference : ", diff)
print("Students who play both cricket and badminton:")
for i in a:
    for j in b:
        if(i==j):
            I.append(i)
            count=count+1
        else:
            continue
print(I)
U=[]
U=b
for i in a:
    if(i in b):
        continue
    else:
        U.append(i)
#print("Union :", U)
print("Students who play either cricket or badminton but not both:")
for i in I:
    if i in U:
        U.remove(i)
    else:
        continue
len=0
for x in U:
    len=len+1
counter=0
while(counter<len):
    counter2=0
    while(counter2<((len-counter)-1)):
        temp=U[counter2]
        if(U[counter2]>U[counter2+1]):
            U[counter2]=U[counter2+1]
            U[counter2+1]=temp
        counter2=counter2+1
    counter=counter+1
print(U)

print("Number of students who play neither cricket nor badminton :", k)

i=0
for x in a:
    if(x in c):
            if(x in b):
                pass
            else:
                i=i+1
    else:
        pass
print("Number of students who play cricket and football but not badminton :", i)
            