#include <iostream>
#include <vector>
using namespace std;

int maxSumSubarray(vector<int>& arr, int k) {
    int n = arr.size();

    int windowSum = 0;

    // First window
    for (int i = 0; i < k; i++)
        windowSum += arr[i];

    int maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++) {
        windowSum += arr[i];
        windowSum -= arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}

int main() {
    vector<int> arr = {2,1,5,1,3,2};
    int k = 3;

    cout << maxSumSubarray(arr, k);

    return 0;
}
