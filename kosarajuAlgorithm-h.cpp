#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//maintain a stack to store the order of reaching the points
stack<int> st;
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
		if(visited[src])	return;
		visited[src]=true;
		for(int i=0;i<adjList[src].size();i++){
			int child=adjList[src][i];
			if(!visited[child]){
				dfs(child,visited);
			}
		}
		st.push(src);
	}
	void dfs_helper(){
		bool visited[nv+10]={};
		for(int i=0;i<nv;i++){
			if(!visited[i]){
				dfs(i,visited);
			}
		}
	}
	//the nodes visited will lie in a single strongly connected component
	void PrintStronglyConnected(int src,bool visited[]){
		visited[src]=true;
		cout<<src<<" ";
		for(int i=0;i<adjList[src].size();i++){
			int child=adjList[src][i];
			if(!visited[child])
				PrintStronglyConnected(child,visited);
		}
	}
	//we keep popping elements of the stack and if the element not visited,
	//it belongs to a new strongly connected component
	void getConnectedComponents(){
		bool visited[nv+1]={};
		while(!st.empty()){
			int top=st.top();
			if(visited[top]==true)
				{st.pop();continue;}
			PrintStronglyConnected(top,visited);
			cout<<"\n";
			st.pop();
		}
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

	g.dfs_helper();
	//we first do a conventional dfs on the graph
	//and then reverse all the edges

	//after reversing the edges, we visit the nodes from the stack
	//each unvisited node is gonna be a part of a new
	//strongly connected component
	graph transposed(nv);
	for(int i=0;i<nv;i++){
		for(int j=0;j<g.adjList[i].size();i++){
			int child=g.adjList[i][j];
			transposed.addEdge(child,i);
		}
	}
	transposed.getConnectedComponents();
	// transposed.printGraph();
	return 0;
}


/*

11 13
0 1
1 2
2 0
1 3
3 4
4 5
5 3
6 5
6 7
7 8
8 9
9 6
9 10
*/
