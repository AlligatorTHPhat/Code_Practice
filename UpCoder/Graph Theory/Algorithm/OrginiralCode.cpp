#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip>

using namespace std;

struct Edge
{
	int u, v, w;
};

struct Graph
{
	int nV;
	vector<int> deg, in_deg, out_deg;
	vector<Edge> edges;
	vector<vector<int>> adj;

	Graph() : nV(0) {}

	void init_graph(int nV_)
	{
		nV = nV_;  // Set the number of vertices
		deg.resize(nV, 0);
		in_deg.resize(nV, 0);
		out_deg.resize(nV, 0);
		edges.clear();
		adj.resize(nV, vector<int>(nV, 0));
	}
};

bool check_undirected_graph(const Graph& graph)  // Pass by const reference
{
	for (int i = 0; i < graph.nV; i++)
	{
		for (int j = 0; j < graph.nV; j++)
		{
			if (graph.adj[i][j] != graph.adj[j][i])
				return false;
		}
	}
	return true;
}

void read_graph(string ifs, Graph& graph)  // Pass by reference
{
	ifstream is(ifs);

	if (!is.is_open())
		cout << "Khong mo duoc file!" << endl;
	else
	{
		int nV;
		is >> nV;  // Read the number of vertices
		graph.init_graph(nV);  // Initialize the graph with the correct number of vertices

		for (int i = 0; i < graph.nV; i++)
		{
			for (int j = 0; j < graph.nV; j++)
			{
				is >> graph.adj[i][j];
			}
		}

		if (check_undirected_graph(graph))
		{
			for (int i = 0; i < graph.nV; i++)
			{
				for (int j = 0; j < graph.nV; j++)
				{
					if (graph.adj[i][j] != 0 && j > i)
					{
						graph.deg[i]++;
						graph.edges.push_back({ i,j, graph.adj[i][j] });
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < graph.nV; i++)
			{
				for (int j = 0; j < graph.nV; j++)
				{
					if (graph.adj[i][j] != 0)
					{
						graph.in_deg[j]++;
						graph.out_deg[i]++;
						graph.edges.push_back({ i,j, graph.adj[i][j] });
					}
				}
			}
		}
		is.close();
	}
}

void print_graph(string ofs, const Graph& graph)  // Pass by const reference
{
	ofstream os(ofs);

	if (!os.is_open())
		cout << "Khong mo duoc file!" << endl;
	else
	{
		os << "So dinh trong do thi la: " << graph.nV << "\n";
		os << "Ma tran do thi:\n";
		for (int i = 0; i < graph.nV; i++)
		{
			for (int j = 0; j < graph.nV; j++)
			{
				os << setw(4) << graph.adj[i][j];
			}
			os << "\n";
		}
		os << "So canh trong do thi la: " << graph.edges.size() << "\n";

		if (check_undirected_graph(graph))
		{
			os << "La do thi vo huong!\n";
		}
		else
		{
			os << "La do thi co huong!\n";
		}
		os.close();
	}
}

int main()
{
	Graph graph;
	read_graph("input.txt", graph);
	print_graph("output.txt", graph);

	return 0;
}
