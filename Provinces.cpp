#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// By making adjacency list BFS

class Solution {
public:
void makeAdjList(vector<vector<int>> isConnected, vector<int> adj[]){
	int n = isConnected.size(); 	
 	for(int i = 0; i < n; i++){
 		for(int j = 0; j < n; j++){
 			if(isConnected[i][j] && i != j)
 				adj[i+1].push_back(j+1);
 		}
 	}

}

void bfs(int s, vector<int> adj[], vector<int> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto nbrs : adj[node]) {
            if (!visited[nbrs]) {
                q.push(nbrs);
                visited[nbrs] = 1;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
	vector<int> adj[n+1];
	makeAdjList(isConnected , adj);
    vector<int>visited(n+1,0);
	int noOfProvinces = 0;

	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			bfs(i,adj,visited);
			noOfProvinces++;
            cout << noOfProvinces << endl;
		}
	}
	
    return noOfProvinces;

  }

};

// By using Adjancency Matrix BFS

class Solution {
public:
void bfs(int s, vector<vector<int>>& isConnected, vector<int> &visited) {
    queue<int> q;
    q.push(s);
    visited[s] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for(int i = 0; i < isConnected.size(); i++){
            if(isConnected[node][i] && !visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
    
    vector<int>visited(n,0);
	int noOfProvinces = 0;
    
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			bfs(i,isConnected,visited);
			noOfProvinces++;
		}
	}
    
    return noOfProvinces;

  }  

};


// By using Dfs

class Solution {
public:
 void dfs(int s ,vector<vector<int>> adj , vector<bool> &visited){
        int n = adj.size();
        visited[s] = true;
        for(int i = 0; i < n; i++){
            if(adj[s][i] && !visited[i]){
                visited[i] = true;
                dfs(i,adj,visited);
            }
        }
        
    }


int findCircleNum(vector<vector<int>>& isConnected) {
	int n = isConnected.size();
    
    vector<bool>visited(n,false);
	int noOfProvinces = 0;
    
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(i,isConnected,visited);
			noOfProvinces++;
		}
	}
    
    return noOfProvinces;
  }  
};