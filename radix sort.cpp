#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to get the maximum element from the array
int getMax(const vector<int>& arr) {
    int max = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on a specific digit
void countingSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);

    // Store count of occurrences in count[]
    for (size_t i = 0; i < arr.size(); i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Function to perform Radix Sort
void radixSort(vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Function to print an array
void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Original array:" << endl;
    printArray(arr);
    
    radixSort(arr);

    cout << "Sorted array:" << endl;
    printArray(arr);

    return 0;
}
