#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0;
    for(int i = 0; i < k; i++)
        sum += arr[i];

    int maxSum = sum;

    for(int i = k; i < n; i++) {
        sum += arr[i];
        sum -= arr[i - k];
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
    return 0;
}
