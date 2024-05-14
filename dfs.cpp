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