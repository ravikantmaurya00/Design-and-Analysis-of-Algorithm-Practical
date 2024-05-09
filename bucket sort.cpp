#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to perform Bucket Sort
void bucketSort(vector<float>& arr) {
    int n = arr.size();

    // Create n empty buckets
    vector<vector<float>> buckets(n);

    // Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort individual buckets
    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

// Function to print an array
void printArray(const vector<float>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<float> arr(n);
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Original array:" << endl;
    printArray(arr);
    
    bucketSort(arr);

    cout << "Sorted array:" << endl;
    printArray(arr);

    return 0;
}
