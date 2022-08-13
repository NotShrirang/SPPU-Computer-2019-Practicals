#Assignment 3 (B)

string=input("Enter String : ")
#print(string)
i=0
length=0
for i in string:
    length=length+1
#print(length)

# a) word of longest length
i=0
max_length=0
temp=0
while(i<length):
    temp=temp+1
    if(string[i]==" "):
        temp=0
    if (temp>max_length):
        pos=i
        max_length=temp
    i=i+1
st=pos-max_length
en=pos+1
print("Maximum length =",max_length, "and the word is :", string[st+1:en])

# b) Checking character and frequency of it.
i=0
s_val=input("Enter a character : ")
char_count=0
while(i<length):
    if(string[i]==s_val):
        char_count=char_count+1
    i=i+1
print("The character", s_val, "has occured", char_count, "times.")

# c) Pallindrome or not
i=0
j=length-1
temp=0
while(i<length and j>0):
    if(string[i]==string[j]):
        temp=temp+1
    else:
        print("Not a pallindrome!")
        break
    j=j-1
    i=i+1
if(temp==length-1):
    print("A pallindrome!")

# d) Accepting substring and checking the appearence of it in the string entered.
sub_str=input("Enter a substring : ")
k=0
sub_length=0
for k in sub_str:
    sub_length=sub_length+1
i=0
k=0
temp=0
counter = 0
while(i<length):
    sub_char=sub_str[k]
    main_char=string[i]
    if (sub_char==main_char):
        temp=i+1
        k=k+1
        while(k<sub_length):
            if(string[temp]==sub_str[k]):
                temp=temp+1
                k=k+1
                if(k==sub_length-1):
                    print("Postion :", i)
                    break
            else:
                counter=1
                break
    elif(k==sub_length-1):
        break
    elif(i==length-1 and k!=sub_length-1):
        print("Not Found2!")
        break
    else:
        pass
    i=i+1