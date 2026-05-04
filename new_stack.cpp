#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;

    st.pop(); // removes top element

    cout << "Top after pop: " << st.top() << endl;

    cout << "Stack size: " << st.size() << endl;

    if(st.empty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
