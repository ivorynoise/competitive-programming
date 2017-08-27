/*
sample input : 
5 8
0 1 -1
1 4 2
0 2 4
1 2 3
4 3 -3
3 2 5
1 3 2
3 1 1
*/
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class vertex{
public:
	int id;
	int weight;
};

class graph{
public:
	vector<vertex>* adjList;
	int nv,ne;
	graph(int n){
		nv=n;
		ne=0;
		adjList=new vector<vertex>[nv+1];
	}
	void addEdge(int src,int dest,int wt){
		vertex a;
		a.id=dest;
		a.weight=wt;
		adjList[src].push_back(a);
		ne++;
	}
	//for testing purpose to see if the graph got inputted the right way
	void printGraph(){
		for(int i=0;i<nv;i++){
			cout<<i<<" : ";
			for(int j=0;j<adjList[i].size();j++){
				cout<<"("<<adjList[i][j].id<<", "<<adjList[i][j].weight<<") \t";
			}
			cout<<"\n";
		}
	}


	void bellmanFord(int src){
		int distances[nv+1]={};
		//set all distances from source to each vertex to INT_MAX
		for(int i=0;i<nv;i++){
			distances[i]=INT_MAX;
		}
		//distance of src from itself=0
		distances[src]=0;
		//we have to do stuff nv-1 times.
		for(int k=0;k<nv-1;k++){
		//traverse the graph
		for(int i=0;i<nv;i++){
			for(int j=0;j<adjList[i].size();j++){
				int child=adjList[i][j].id;
				int weight=adjList[i][j].weight;
				//distances[i]!=INT_MAX ensures that we don't overflow an integer when we add weight to it
				// if distance is less, put distance of that child from source = distance[parent] + weight
				if(distances[i]!=INT_MAX && distances[i]+weight < distances[child]){
					distances[child]=distances[i]+weight;
				}
			}
		}
	}	
		bool containsNegativeCycle=false;
		for(int i=0;i<nv;i++){
			for(int j=0;j<adjList[i].size();j++){
				int child=adjList[i][j].id;
				int weight=adjList[i][j].weight;
				//if we are further able to find minimum weight for a node
				//it means we definitely have a negative weight cycle
				if(distances[i]!=INT_MAX && distances[i]+weight < distances[child]){
					containsNegativeCycle=true;
				}
			}
		}
		if(containsNegativeCycle){
			cout<<"Contains negative cycle!\n";
		}
		else{
		//print all the distances
			for(int i=0;i<nv;i++){
				cout<<distances[i]<<" ";
			}
			cout<<"\n";
		}
	}
};

int main(){
	int nv,ne;
	cin>>nv>>ne;
	graph g(nv);
	while(ne--){
		int a,b,wt;
		cin>>a>>b>>wt;
		g.addEdge(a,b,wt);
	}
	g.bellmanFord(0);
	// g.printGraph();
}
