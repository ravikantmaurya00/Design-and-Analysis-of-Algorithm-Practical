#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0-1 knapsack problem
int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> val(n), wt(n);
    cout << "Enter the values of items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Value of item " << i + 1 << ": ";
        cin >> val[i];
    }

    cout << "Enter the weights of items:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> wt[i];
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value that can be obtained: " << knapsack(W, wt, val, n) << endl;

    return 0;
}
