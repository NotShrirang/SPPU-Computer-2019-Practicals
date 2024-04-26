#include <iostream>
#include <omp.h>
#include <vector>
#include <time.h>

using namespace std;

void bubbleSort(vector<int> &arr)
{
    int n = arr.size();
    bool swapped = false;

    while (swapped)
    {
        swapped = false;
#pragma omp parallel for
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
    }
}

void merge(vector<int> &array, int left, int middle, int right)
{
    vector<int> merged;
    int left_iter = left;
    int right_iter = middle + 1;

    while (left_iter <= left && right_iter <= right)
    {
        if (array[left_iter] < array[right_iter])
        {
            merged.push_back(array[left_iter]);
            left_iter++;
        }
        else
        {
            merged.push_back(array[right_iter]);
            right_iter++;
        }
    }

    while (left_iter <= middle)
    {
        merged.push_back(array[left_iter]);
        left_iter++;
    }

    while (right_iter <= right)
    {
        merged.push_back(array[right_iter]);
        right_iter++;
    }

    for (int i = left; i <= right; i++)
    {
        array[i] = merged[i - left];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
#pragma omp parallel sections
        {
#pragma omp section
            mergeSort(arr, left, middle);
#pragma omp section
            mergeSort(arr, middle + 1, right);
        }
        merge(arr, left, middle, right);
    }
}

int main()
{
    vector array = {14, 12, 8, 7, 10};
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\n";
    clock_t bubbleStart = clock();
    bubbleSort(array);
    clock_t bubbleEnd = clock();
    clock_t mergeStart = clock();
    mergeSort(array, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << ", ";
    }
    clock_t mergeEnd = clock();
    cout << "\n";
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << ", ";
    }
    double bubbleDuration = double(bubbleEnd - bubbleStart) / CLOCKS_PER_SEC;
    cout << "Bubble sort time in seconds: " << bubbleDuration << endl;
    double mergeDuration = double(mergeEnd - mergeStart) / CLOCKS_PER_SEC;
    cout << "Merge sort time in seconds: " << mergeDuration << endl;
    return 0;
}