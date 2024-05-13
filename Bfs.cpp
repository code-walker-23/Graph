#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){

	int vertices; cin >> vertices;
	int edges; cin >> edges; 
	vector<int> adj[vertices];

	for(int i = 1; i <= edges; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}


	queue<int> q;
	q.push(0);

	int visited[vertices] = {1};

	vector<int> bfs;

	while(!q.empty()){

		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for(auto nbrs : adj[node]){
			if(!visited[nbrs])
				q.push(nbrs);
				visited[nbrs] = 1;
		}

	}

	for(auto x : bfs)
		cout << x << " ";
}