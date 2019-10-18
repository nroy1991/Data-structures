#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct Edge {
	int src, dest, weight;
};
class DisjointSet
{
	unordered_map<int, int> parent;
public:
	void makeSet(int N)
	{
		for (int i = 0; i < N; i++)
            parent[i] = i;
	}
	int Find(int k)
	{
		if (parent[k] == k)
			return k;
		return Find(parent[k]);
	}
	void Union(int a, int b)
	{
		int x = Find(a);
		int y = Find(b);
		parent[x] = y;
	}
};
vector<Edge> KruskalAlgo(vector<Edge> edges, int N)
{
	vector<Edge> MST;
	DisjointSet ds;
	ds.makeSet(N);
	while (MST.size() != N - 1)
	{
		Edge next_edge = edges.back();
		edges.pop_back();
		int x = ds.Find(next_edge.src);
		int y = ds.Find(next_edge.dest);
		if (x != y)
		{
			MST.push_back(next_edge);
			ds.Union(x, y);
		}
	}
	return MST;
}
struct compare
{
	inline bool operator() (Edge const &a, Edge const &b)
	{
		return (a.weight > b.weight);
	}
};
int main()
{
	vector<Edge> edges =
	{
		{ 0, 1, 7 }, { 1, 2, 8 }, { 0, 3, 5 }, { 1, 3, 9 },
		{ 1, 4, 7 }, { 2, 4, 5 }, { 3, 4, 15 }, { 3, 5, 6 },
		{ 4, 5, 8 }, { 4, 6, 9 }, { 5, 6, 11 }
	};
	sort(edges.begin(), edges.end(), compare());
	int N = 7;
	vector<Edge> e = KruskalAlgo(edges, N);
	for (Edge &edge: e)
		cout << "(" << edge.src << ", " << edge.dest << ", "
			<< edge.weight << ")" << endl;
	return 0;
}
