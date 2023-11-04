import random
import time


def quickSort(array):
    if len(array) <= 1:
        return array

    pivot = array[len(array) // 2]
    left = [x for x in array if x < pivot]
    middle = [x for x in array if x == pivot]
    right = [x for x in array if x > pivot]

    return quickSort(left) + middle + quickSort(right)


def quickSortRandomized(array):
    if len(array) <= 1:
        return array

    pivot = array[random.randint(0, len(array)-1)]
    left = [x for x in array if x < pivot]
    middle = [x for x in array if x == pivot]
    right = [x for x in array if x > pivot]

    return quickSortRandomized(left) + middle + quickSortRandomized(right)


if __name__ == "__main__":
    data_size = 1000000
    data = [random.randrange(0, 10000000000000) for _ in range(data_size)]

    start_time = time.time()
    sorted_data = quickSort(data)
    end_time = time.time()
    deterministic_time = end_time - start_time

    start_time = time.time()
    randomized_sorted_data = quickSortRandomized(data)
    end_time = time.time()
    randomized_time = end_time - start_time

    assert sorted_data == randomized_sorted_data

    print(f"Data Size: {data_size}")
    print(f"Deterministic Quick Sort Time: {deterministic_time:.6f} seconds")
    print(f"Randomized Quick Sort Time: {randomized_time:.6f} seconds")
