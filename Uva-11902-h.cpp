#include<iostream>
using namespace std;

void dfs(int graph[][110],int n,int visited[],int src){
    // if visited of src == 2, return 
    int i;
    visited[src]=1;
    for(i=0;i<n;i++){
        
        if(graph[src][i]==1 && visited[i]==0){
            dfs(graph,n,visited,i);
        }
    }
}

void print(int domino[][110],int n,int tc){
    int i;
    cout<<"Case "<<tc<<":\n";
    cout<<"+";
    for(i=0;i<2*n-1;i++){
        cout<<"-";
    }
    cout<<"+\n";
    for(i=0;i<n;i++){
        cout<<"|";
        for(int j=0;j<n;j++){
            if(domino[i][j]==1)
                cout<<"Y|";
            else
                cout<<"N|";
        }
    cout<<"\n+";
    for(int k=0;k<2*n-1;k++){
        cout<<"-";
    }
    cout<<"+\n";
    }
}

int main(){
    int t,tc=1;
    cin>>t;
    for(;tc<=t;tc++){
        int i,j,n,graph[110][110],dominator[110][110]={};
        cin>>n;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>graph[i][j];
            }
        }
        int Visitable[110]={};
        dfs(graph,n,Visitable,0);
        for(int i=0;i<n;i++){
            if(Visitable[i]==1){
                dominator[i][i]=1;
                dominator[0][i]=1;
            }
        }
        for(i=1;i<n;i++){
            int ifRemoved[110]={};
            ifRemoved[i]=2;
            dfs(graph,n,ifRemoved,0);
            for(int j=0;j<n;j++){
                if(Visitable[j]==1 && ifRemoved[j]==0)
                    dominator[i][j]=1;
            }
        }
        print(dominator,n,tc);
    }
    return 0;
}