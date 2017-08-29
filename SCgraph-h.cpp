#include <iostream>
#include <vector>
using namespace std;

class graph{
public:
	vector<int>* adjList;
	int nv,ne;
	graph(int n){
		nv=n;
		ne=0;
		adjList=new vector<int>[nv+1];
	}
	void addEdge(int src,int dest){
		adjList[src].push_back(dest);
	}
	//just for debugging process
	void printGraph(){
		for(int i=0;i<nv;i++){
			cout<<i<<" : ";
			for(int j=0;j<adjList[i].size();j++){
				cout<<adjList[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	void dfs(int src,bool visited[]){
		visited[src]=true;
		for(int i=0;i<adjList[src].size();i++){
			int child=adjList[src][i];
			if(!visited[child]){
				dfs(child,visited);
			}
		}
	}
	bool dfs_helper(int src){
		bool visited[nv+1]={};
		dfs(src,visited);
		for(int i=0;i<nv;i++){
			if(!visited[i])
				return false;
		}
	return true;
	}
};


int main(){
	int nv,ne;
	cin>>nv>>ne;
	graph g(nv);
	while(ne--){
		int a,b;
		cin>>a>>b;
		g.addEdge(a,b);
	}
	bool isConnected=g.dfs_helper(0);
	//dfs helper tells if we were able to visit all the nodes from 0
	if(isConnected==false){
		cout<<"\nGraph is not connected\n";
	}
	else{
		//we reverse all the edges
		graph transposed(nv);
		for(int i=0;i<nv;i++){
			for(int j=0;j<g.adjList[i].size();i++){
				int child=g.adjList[i][j];
				transposed.addEdge(child,i);
			}
		}
		//if we are here we are sure that we can visit all nodes from 0
		//Now to check if all the nodes are able to visit 0, we reverse the edges
		//(this is similar to applying dfs from each node if edges weren't reversed)
		//and if now 0 is able to visit all the nodes, then it is strongly connected
		//otherwise not
		bool isStronglyConnected=transposed.dfs_helper(0);
		if(isStronglyConnected){
			cout<<"\nGraph is strongly connected\n";
		}else{
			cout<<"\nGraph is not strongly connected\n";
		}
	}
	return 0;
}

/*
5 6
0 1
1 2
2 3
3 0
2 4
4 2

Output : YES

4 3
0 1
1 2
2 3

Output : NO
*/
