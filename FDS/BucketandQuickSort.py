def bucket_sort(input_list):

    max_value = max(input_list)
    size = max_value / len(input_list)
    buckets_list = []
    for x in range(len(input_list)):
        buckets_list.append([])
    for i in range(len(input_list)):
        j = int(input_list[i] / size)
        if j != len(input_list):
            buckets_list[j].append(input_list[i])
        else:
            buckets_list[len(input_list) - 1].append(input_list[i])
    for z in range(len(input_list)):
        quickSort(buckets_list[z],0,len(buckets_list[z])-1)
    final_output = []
    for x in range(len(input_list)):
        final_output = final_output + buckets_list[x]
    return final_output

def partition(arr,low,high):
   i = (low-1)
   pivot = arr[high]
   for j in range(low, high):
      if arr[j] <= pivot:
         i = i+1
         arr[i],arr[j] = arr[j],arr[i]
         print(arr)
   arr[i+1],arr[high] = arr[high],arr[i+1]
   return (i+1)

def quickSort(arr,low,high):
   if low < high:
      pi = partition(arr,low,high)
      quickSort(arr, low, pi-1)
      quickSort(arr, pi+1, high)

input_list = []
i=0
while(True):
    n=int(input("Enter no. of entries : "))
    if(n>0):
        break
    else:
        print("\nNegative value! Please re-enter.\n")
while(i<n):
    x=float(input("Enter value :"))
    if(x>0):
        input_list.append(x)
        i+=1
    else:
        print("\nValue is negative! Please re-enter.\n")
print("Unsorted List :", input_list)
sorted_list = bucket_sort(input_list)
print("Sorted List :", sorted_list)