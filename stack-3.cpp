#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && heights[st.top()] > currHeight) {
            int h = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, h * width);
        }

        st.push(i);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};

    cout << largestRectangleArea(heights);

    return 0;
}
