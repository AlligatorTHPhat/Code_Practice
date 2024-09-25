#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int Start, End;

struct Graph
{
	int Nv, Ne;
	vector<int> degree;
	vector<vector<int>> adj;

	Graph() : Nv(0), Ne(0) {}

	void init_degree()
	{
		degree.resize(Nv, 0);
		adj.resize(Nv, vector<int>(Nv, 0));
	}
};

struct Queue
{
	int Front_index, Rear_index;
	vector<int> data;
};

void init(Queue& q)
{
	q.Front_index = 0;
	q.Rear_index = -1;
}

bool Empty(Queue& q)
{
	return q.Front_index > q.Rear_index;
}

void Push(Queue& q, int value)
{
	q.data.push_back(value);
	q.Rear_index++;
}

void Pop(Queue& q)
{
	if (!Empty(q))
		q.Front_index++;
}

int Front(Queue& q)
{
	if (!Empty(q))
		return q.data[q.Front_index];
	return -1;
}

void Read_Graph(string fn, Graph& graph)
{
	ifstream ifile(fn);

	if (!ifile.is_open())
		cout << "Khong mo duoc file.";

	else
	{
		ifile >> graph.Nv >> Start >> End;

		graph.init_degree();

		for (int i = 0; i < graph.Nv; i++)
			for (int j = 0; j < graph.Nv; j++)
				ifile >> graph.adj[i][j];

		for (int i = 0; i < graph.Nv; i++)
		{
			for (int j = 0; j < graph.Nv; j++)
			{
				if (graph.adj[i][j] != 0)
				{
					graph.Ne++;
					graph.degree[i]++;
				}
			}
		}
		graph.Ne /= 2;

		ifile.close();
	}
}

vector<bool> visited;
vector<int> save;
vector<int> path;

void BFS(int Start, vector<vector<int>> adj)
{
	Queue q; init(q);

	visited.assign(adj.size(), false);
	save.assign(adj.size(), -1);


	visited[Start] = true;
	Push(q, Start);

	while (!Empty(q))
	{
		int i = Front(q);
		Pop(q);

		path.push_back(i);

		for (int j = 0; j < adj.size(); j++)
		{
			if (adj[i][j] != 0 && !visited[j])
			{
				visited[j] = true;
				save[j] = i;

				Push(q, j);
			}
		}
	}
}

void Print_Path(int Start, int End, vector<vector<int>> adj, ofstream& ofile)
{
	BFS(Start, adj);

	if (visited[End])
	{
		ofile << "Duyet theo chieu rong : " << endl;

		int e = End;

		while (e != -1)
		{
			e = save[e];
		}

		for (int i = path.size() - 1; i >= 0; i--)
		{
			ofile << path[i];
			if (i > 0)
				ofile << "<---";
		}
		ofile << endl;
	}

	else
		ofile << "Khong co duong di tu " << Start << " toi " << End << endl;
}

void Print_Graph(string fn, Graph graph)
{
	ofstream ofile(fn);

	if (!ofile.is_open())
		cout << "Khong mo duoc file!";

	else
	{
		ofile << "So dinh trong do thi : " << graph.Nv << endl;

		for (int i = 0; i < graph.Nv; i++)
		{
			for (int j = 0; j < graph.Nv; j++)
			{
				ofile << setw(4) << graph.adj[i][j] << " ";
			}
			ofile << endl;
		}

		ofile << "So canh trong do thi : " << graph.Ne << endl;

		Print_Path(Start, End, graph.adj, ofile);

		ofile.close();
	}
}

int main()
{
	Graph graph;

	Read_Graph("dothi.txt", graph);

	Print_Graph("output.txt", graph);

	return 0;
}
