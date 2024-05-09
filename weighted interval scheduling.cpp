#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int start;
    int end;
    int weight;
};

// Function to compare intervals based on their end time
bool compareIntervals(const Interval& a, const Interval& b) {
    return a.end < b.end;
}

// Function to find the latest non-overlapping interval that ends before the current interval
int latestNonOverlappingInterval(const vector<Interval>& intervals, int index) {
    for (int i = index - 1; i >= 0; i--) {
        if (intervals[i].end <= intervals[index].start) {
            return i;
        }
    }
    return -1;
}

// Function to solve the weighted interval scheduling problem
int weightedIntervalScheduling(const vector<Interval>& intervals) {
    int n = intervals.size();
    vector<int> dp(n); // dp[i] stores the maximum weight that can be obtained by considering intervals[0] to intervals[i]

    // Sort intervals based on end times
    sort(intervals.begin(), intervals.end(), compareIntervals);

    // Base case: the maximum weight for the first interval is its weight
    dp[0] = intervals[0].weight;

    // Fill dp[] in bottom-up manner
    for (int i = 1; i < n; i++) {
        // Include the current interval
        int includedWeight = intervals[i].weight;
        int latestNonOverlap = latestNonOverlappingInterval(intervals, i);
        if (latestNonOverlap != -1) {
            includedWeight += dp[latestNonOverlap];
        }

        // Exclude the current interval
        int excludedWeight = dp[i - 1];

        // Choose the maximum of including and excluding the current interval
        dp[i] = max(includedWeight, excludedWeight);
    }

    // Return the maximum weight that can be obtained
    return dp[n - 1];
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;

    vector<Interval> intervals(n);
    cout << "Enter the start time, end time, and weight of each interval:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Interval " << i + 1 << ":" << endl;
        cout << "Start time: ";
        cin >> intervals[i].start;
        cout << "End time: ";
        cin >> intervals[i].end;
        cout << "Weight: ";
        cin >> intervals[i].weight;
    }

    cout << "Maximum weight that can be obtained: " << weightedIntervalScheduling(intervals) << endl;

    return 0;
}
