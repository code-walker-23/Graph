#include <iostream>
#include <vector>
#include <queue> // Add this line

using namespace std;

void bfs(int s, vector<int> adj[], vector<int> &bfs, int visited[]) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto nbrs : adj[node]) {
            if (!visited[nbrs]) {
                q.push(nbrs);
                visited[nbrs] = 1;
            }
        }
    }
}

// No refrence is required adj is an array of vectors
void adjList(vector<int> adj[], int e){

	for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

}

int main() {
	// Taking vertices , edges and source vertex.
    int v, e, s;
    cin >> v >> e >> s;
    
    // creating an vetor to store the result of the bfs.
    vector<int> bfs_result;

    int visited[v] = {0}; // Initialize all elements to 0

    // Creating an adjacency list.
    vector<int> adj[v];
    adjList(adj,e);
    

    // Calling for the first time.
    bfs(s, adj, bfs_result, visited);

    // Checking for disconnected part if any vertex is not visited then call to bfs again as source = unvisited vertex.
    for(int i = 0; i < v; i++){
    	if(!visited[i]){
    		bfs(i, adj, bfs_result, visited); // if source is not given comment 54 line.
    	}
    }

    // Printing the bfs of the given graph.
    for(auto x : bfs_result)
    	cout << x << endl;
    return 0;
}
