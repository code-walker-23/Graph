#include<iostream>
#include<bits/stdc++.h>

using namespace std;
// Consider node as numbered with strings eg-> cities

class Node{
public:
	string name;
	vector<string> nbrs;

	Node(string name){
		this->name = name;
	}
};

class Graph{
	
	// Whenever i call a graph a hashpam is created.
	unordered_map<string,Node*> m;
public:

	Graph(vector<string> cities){
		for(auto city : cities){
			m[city] = new Node(city);
			// cout << city << endl;
		}
	}

	void addEdge(string x , string y ,bool dir){
		m[x]->nbrs.push_back(y);
			// cout << x <<" , " << y << endl;

		if(!dir)
			m[y]->nbrs.push_back(x);
	}

	void printgraph(){
		for(auto cit : m){
			cout << cit.first << "-> ";
			for(auto x : cit.second->nbrs)
				cout << x << " , ";
			cout << endl; 
		}
	}

};

int main(){

	vector<string> str = {"london","paris","new delhi","new york"};
	Graph g(str);

	g.addEdge("new york","london",true);
	g.addEdge("paris","new york",true);
	g.addEdge("new delhi","london",true);
	g.addEdge("new delhi","paris",true);

	g.printgraph();


}
	





















// considering node as numbered with numeric values
/*class Graph{
	int V;
	list<int> *l;

public:

	Graph(int v){
		V = v;
		l = new list<int>[V];
	}

	void addEdge(int i, int j,bool undir = true){
		l[i].push_back(j);
		if(undir)
			l[j].push_back(i);
	}

	void printAdjList(){
		for(int i = 0; i < V; i++){
			cout << i << ": ";
			for(auto x : l[i])
				cout << x << " ";
			cout << endl;
	    }

	}

};
*/

/*int main(){

	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	// g.addEdge(3,4);


	g.printAdjList();

} */