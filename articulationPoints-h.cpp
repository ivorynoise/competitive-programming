#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//timer is to keep track at what time have we discovered each vertex
int timer=0;
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

        adjList[dest].push_back(src);
        ne++;
    }
    //for debugging purpose
    void printGraph(){
        for(int i=0;i<nv;i++){
            cout<<i<<" : ";
            for(int j=0;j<adjList[i].size();j++){
                cout<<adjList[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    void modifiedDfs(int src,bool visited[],int visitingTime[],int lowTime[],int parent[],bool isArticulationPoint[]){
        //set visited of src=true
        visited[src]=true;
        //set visiting and low time of src=timer which is the global variable
        visitingTime[src]=timer;
        lowTime[src]=timer;
        //increase the timer for the next vertex
        timer++;
        //numberofchildren is there to check if src is the root of the dfs and 
        //whether it has more than 1 child
        int numberOfChildren=0;
        for(int i=0;i<adjList[src].size();i++){
            int child=adjList[src][i];
            if(!visited[child]){

                //if child not visited, NOC++, parent of child=src
                parent[child]=src;
                numberOfChildren++;
               // call modifiedDfs on the child
                modifiedDfs(child,visited,visitingTime,lowTime,parent,isArticulationPoint);

                //after dfs is completed, update the low time of src. 
                // this low time will represent the lowest time to one of its child that it can have
                //for a backedge ofcourse
                lowTime[src]=min(lowTime[src],lowTime[child]);

                //if src is root of dfs and has more than 2 children, then it is an articulation point
                if(parent[src]==-1 && numberOfChildren>=2){
                    isArticulationPoint[src]=true;
                }

                //if src is not the root, and all the children have visiting time >= vistingTime of src
                // this means there is no backedge
		//thus removing it will break the graph
                if(parent[src]!=-1 && lowTime[child] >= visitingTime[src])
                    isArticulationPoint[src]=true;
            }
            else{
                //except for the case where we consider parent of src,
                //we will update the lowtime of src.
                //once the dfs is complete and src has no where to go
                //it still has to update its lowTime to visitingTime of its children
		//again if there is backedge
                if(child!=parent[src]){
                    lowTime[src]=min(lowTime[src],visitingTime[child]);
                }

            }
        }
    }


    void getArticulationPoints(){
        //visited tells us if we have visited that particular vertex
        //visiting time denotes the time taken to visit the vertex
        //low will tell us the child vertex with the minimum time that is visitable from current vertex (will be helpful to see if a
        //backedge exists)
        //parent keeps the track of the parent of a vertex in a dfs tree
        //this is so that we don't take its lowTime, afterall we want a backedge to some other node
        bool visited[nv+1]={},isArticulationPoint[nv+1]={};
        int visitingTime[nv+1],low[nv+1],parent[nv+1];
        for(int i=0;i<nv;i++){
            visitingTime[i]=-1;
            low[i]=-1;
            parent[i]=-1;
        }

        //for every unvisited node, visit it using modified DFS
        for(int i=0;i<nv;i++){
            if(!visited[i]){
                modifiedDfs(i,visited,visitingTime,low,parent,isArticulationPoint);
            }
        }

        for(int i=0;i<nv;i++){
            if(isArticulationPoint[i]){
                cout<<i<<" ";
            }
        }
    }
};

int main(){
    int nv,ne;
    cin>>nv>>ne;
    graph g(nv);
    // cout<<nv<<ne;
    while(ne--){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    g.getArticulationPoints();
    // g.printGraph();
}

/*
5 5
1 0
0 2
2 1
0 3
3 4
Output : 0 3


8 9
0 1
1 2
2 0
2 3
3 4
4 5
5 6
5 7
4 5

Output : 2 3 4 5
*/
