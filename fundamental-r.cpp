#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
vector <int> gra[10];
int nodes,edge;
bool graph[10][10] = {false};
// adjancency matrix 
void dfsi(int i)
{
	vector< bool> v(nodes,false);

	stack <int> s;
	s.push(i);
	while(!s.empty() )
	{
		i= s.top();
		s.pop();
		if(!v[i])
		{
			cout<<i<<" "<<"\n";	
			v[i]=true;	
		}
		for( vector <int> :: iterator it = gra[i].begin();it!=gra[i].end();++it)
		{
			if(!v[ * it])
			{
				s.push(*it);
			}
		}
	}
}
bool v[100]={};
// vector <bool> v(nodes,false);
void dfsr(int i)
{
	if(v[i]==true)
	{	
		return;
	}
	cout<<i<<" "<<"\n";
	v[i]=true;
	for(int j = 0;j<gra[i].size();j++)
	{
		if(v[gra[i][j]]==false)
		{
			dfsr(gra[i][j]);
		}
	}
}

bool connected(int i)
{
	dfsr(i);

	for(int i=1;i<nodes;i++)
	{
		if( v[i] == false)
		{
			return false;
		}
	}
	return true;
}
bool v1[100]={};
void bfs(int i)
{
	queue<int> q;
	q.push(i);

	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		if(!v1[s])
		{
			cout<<s<<" ";
			v1[s]=true;
		}
		for(vector<int> :: iterator it = gra[s].begin();it!=gra[s].end();++it)
		{
			if(v1 [ *it]==false)
			{
				q.push(*it);
			}
		}

	}
}
int main()
{
		// cin>>nodes;
		// cin>>edge;
		// for(int i=0;i<edge;i++)
		// {
		// 	int e1,e2;
		// 	cin>>e1>>e2;
		// 	graph[e1][e2]=true;

		// }

		// for(int i=0;i<nodes;i++)
		// {
		// 	for(int j=0;j<nodes;j++)
		// 	{
		// 		if(graph[i][j])
		// 		{
		// 			cout<<"Edge between "<<i<<" "<<j;
		// 			cout<<"\n";
		// 		}
		// 	}
		// }

		// adjancency list
		
		cin>>nodes>>edge;
		// cout<<nodes<<" "<<edge;
		for(int i=0;i<edge;i++)
		{
				int e1,e2;
				cin>>e1>>e2;
				gra[e1].push_back(e2);
				// cout<<e1<<" "<<e2;
		}
		for(int i=1;i<=nodes;i++)
		{
			cout<<i<<" ";
			for(int j=0;j<gra[i].size();j++)
			{
				cout<<gra[i][j]<<" ";
			}
			cout<<"\n";
		}
    	//traversal in a graph DFS me and pehle meri depth and than backtrack 
		int node1;
		cin>>node1;
		//dfsi(node1);
		dfsr(node1);

		bool status =connected( node1);

		cout<<boolalpha<<status;
		cout<<"\n";
		bfs(node1);
}