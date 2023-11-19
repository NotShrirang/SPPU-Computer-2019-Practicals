def quickSort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[0]
    leftArr = [i for i in arr[1:] if i <= pivot]
    middleArr = [i for i in arr if i == pivot]
    rightArr = [i for i in arr[1:] if i > pivot]

    return quickSort(leftArr) + middleArr + quickSort(rightArr)


if __name__ == "__main__":
    arr = [10, 7, 8, 9, 1, 5]
    print(quickSort(arr))