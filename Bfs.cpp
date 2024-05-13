// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(){

	int vertices; cin >> vertices;
	int edges; cin >> edges;

	// Considering that the nodes of the graph are numbered from 0 to vetices-1. 
	vector<int> adj[vertices];

	// Creating an Adjacency List.
	for(int i = 1; i <= edges; i++){
		// Taking the input edges
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	// Creating an queue to store the nodes of the graph.
	queue<int> q;
	// Enter the source vertex if given.
	q.push(0);

	// Creating an array to check whether the given node is visited or not.
	// When it enters into the queue, it is considered as visited.
	int visited[vertices] = {1};

	// Creating an vector to store bfs traversal of the given graph
	vector<int> bfs;

	// This will iterate till the queue is not empty. 
	while(!q.empty()){

		// Stores the first element.
		int node = q.front();
		// Remove the front element.
		q.pop();

		// Push it to the bfs vector as it is Processed.
		bfs.push_back(node);

		// Extracting all neighbours of the front node.
		for(auto nbrs : adj[node]){
			// if not visited then push to the queue and marked as visited.
			if(!visited[nbrs])
				q.push(nbrs);
				visited[nbrs] = 1;
		}

	}

	// Printing Required Bfs.
	for(auto x : bfs)
		cout << x << " ";

	// return the Required Bfs.
	return bfs;
}

int main(){

	bfs();

}