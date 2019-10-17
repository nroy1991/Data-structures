// C++ Program for Floyd Warshall Algorithm 
#include <bits/stdc++.h> 
using namespace std; 
 int v; 
#define V 1000
#define INF 99999 

void printSolution(int dist[][V]); 
void floydWarshall (int graph[][V]) 
{ 
	int dist[V][V], i, j, k; 
	for (i = 0; i < v; i++) 
		for (j = 0; j < v; j++) 
			dist[i][j] = graph[i][j]; 
	for (k = 0; k < v; k++) 
	{ 
		for (i = 0; i < v; i++) 
		{ 
			for (j = 0; j < v; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 
printSolution(dist); 
} 

void printSolution(int dist[][V]) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < v; i++) 
	{ 
		for (int j = 0; j < v; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

int main() 
{ 
 cout<<"Enter no. of Veriex- ";
  cin>>v;
	int graph[V][V];
  cout<<"Enter the Adjecency matrix (enter -1 for no edge ) \n";
  for(int i=0;i<v;i++)
    for(int j=0;j<v;j++){
    cin>>graph[i][j];
      if(graph[i][j]==-1)
        graph[i][j]=INF;
    }
 
	floydWarshall(graph); 
	return 0; 
} 


