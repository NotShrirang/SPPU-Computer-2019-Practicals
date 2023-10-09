def merge(left_arr, right_arr):
    merged = []
    left_index, right_index = 0, 0

    while left_index < len(left_arr) and right_index < len(right_arr):
        if left_arr[left_index] < right_arr[right_index]:
            merged.append(left_arr[left_index])
            left_index += 1
        else:
            merged.append(right_arr[right_index])
            right_index += 1

    merged.extend(left_arr[left_index:])
    merged.extend(right_arr[right_index:])
    
    return merged
        

def mergeSort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_arr = arr[mid:]
    right_arr = arr[:mid]

    left_arr = mergeSort(left_arr)
    right_arr = mergeSort(right_arr)

    return merge(left_arr, right_arr)

if __name__ == '__main__':
    print(mergeSort([9, 7, 10, 13, 6, 8]))