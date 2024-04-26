#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int parallelMin(vector<int> arr) {
    int min_val = arr[0];

    #pragma omp parallel for
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int parallelMax(vector<int> arr) {
    int max_val = arr[0];

    #pragma omp parallel for
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

int parallelSum(vector<int> arr) {
    int sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    return sum;
}

float parallelAverage(vector<int> arr) {
    int sum = parallelSum(arr);
    float avg = float(sum) / arr.size();
    return avg;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int min_val = parallelMin(arr);
    int max_val = parallelMax(arr);
    int sum = parallelSum(arr);
    float avg = parallelAverage(arr);

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;
    cout << "Sum of values: " << sum << endl;
    cout << "Average of values: " << avg << endl;

    return 0;
}