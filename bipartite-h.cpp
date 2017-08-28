//if it is possible to colour the vertices
// such that no two vertices have the same colour, then
// the graph is bipartite
//As we can place all the edges of same colour in one set and the remaining in another
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
enum colour {RED,BLUE,UNCOLOURED};

class graph{
public:
	int nv,ne;
	vector<int>* adjList;
	graph(int n){
		nv=n;
		ne=0;
		adjList=new vector<int> [nv+1];
	}
	void addEdge(int src,int dest){
		adjList[src].push_back(dest);
		ne++;
	}
	void printGraph(){
		for(int i=0;i<nv;i++){
			cout<<i<<" : ";
			for(int j=0;j<adjList[i].size();j++){
				cout<<adjList[i][j]<<" ";
			}
			cout<<"\n";
		}
	}

	bool isBipartite(int src){
		queue<int> q;
		vector <colour> c(nv+1);
		for(int i=0;i<nv;i++){
			c[i]=UNCOLOURED;
		}
		q.push(src);
		c[src]=RED;
		while(!q.empty()){
			int current=q.front();
			colour currentColour=c[current];
			q.pop();
			for(int i=0;i<adjList[current].size();i++){
				int child=adjList[current][i];
				//is not coloured
				if(c[child]==UNCOLOURED){
					c[child]=currentColour==RED?BLUE:RED;
					q.push(child);
				}
				else if(currentColour==c[child]){
					//is already coloured and has the same colour as parent
					//if child has black and has a back edge to the parent, parent will be of different colour
					//so we won't return false in that case
					//false only if the child and parent have different colour
					return false;
				}
			}

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
	//g.printGraph();
	if(g.isBipartite(0)){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}
/*
4 8
0 1
0 3
1 0
1 2
2 1
2 3
3 0
3 2
*/