#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Add Edge (Undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // DFS Traversal
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> st;

        st.push(start);

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            if(!visited[node]) {
                cout << node << " ";
                visited[node] = true;
            }

            for(int neigh : adj[node]) {
                if(!visited[neigh])
                    st.push(neigh);
            }
        }
        cout << endl;
    }

    // BFS Traversal
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cout << node << " ";

            for(int neigh : adj[node]) {
                if(!visited[neigh]) {
                    visited[neigh] = true;
                    q.push(neigh);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int V, E;
    cin >> V >> E;

    Graph g(V);

    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cin >> start;

    cout << "BFS: ";
    g.BFS(start);

    cout << "DFS: ";
    g.DFS(start);

    return 0;
}
