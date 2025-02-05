#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible to paint all boards with 'm' painters in 'limit' time
bool findFeasible(int boards[], int n, int limit, int m) {
    int sum = 0, painters = 1;

    for (int i = 0; i < n; i++) {
        sum += boards[i];

        // If adding this board exceeds the limit, we need another painter
        if (sum > limit) {
            sum = boards[i]; // Reset sum to current board length
            painters++;

            // If the number of painters exceeds m, return false
            if (painters > m) {
                return false;
            }
        }
    }

    // If painters are within the limit, return true
    return true;
}

// Function to find the minimum time required to paint all boards with 'm' painters
int painterPartition(int boards[], int n, int m) {
    int totalLength = 0, k = 0;

    // Find the maximum single board length and the total length of all boards
    for (int i = 0; i < n; i++) {
        k = max(k, boards[i]);
        totalLength += boards[i];
    }

    int low = k, high = totalLength;

    // Perform binary search to find the minimum feasible time
    while (low < high) {
        int mid = (low + high) / 2;

        // Check if we can paint all boards in 'mid' time with 'm' painters
        if (findFeasible(boards, n, mid, m)) {
            high = mid; // Try to find a smaller feasible time
        } else {
            low = mid + 1; // Increase the time limit to find feasibility
        }
    }

    return low;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << "Minimum time to paint boards: " << painterPartition(arr, n, m) << endl;
    return 0;
}
