#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const int INF = 10e9;

struct Edge
{
	int u, v, w;
};

struct Graph
{
	int nV;
	vector<int> degree, in_degree, out_degree;
	vector<Edge> edges;
	vector<vector<int>> adj;

	Graph() : nV(0) {}

	void init_Graph()
	{
		degree.resize(nV, 0);
		in_degree.resize(nV, 0);
		out_degree.resize(nV, 0);
		edges.clear();
		adj.resize(nV, vector<int>(nV, 0));
	}
};

bool Check_Undirected_Graph(Graph& graph)
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

void Read_Graph(string fn, Graph& graph, bool& is_undirected)
{
	ifstream is(fn);

	if (is.is_open())
	{
		is >> graph.nV;

		graph.init_Graph();

		for (int i = 0; i < graph.nV; i++)
		{
			for (int j = 0; j < graph.nV; j++)
			{
				is >> graph.adj[i][j];
			}
		}

		is_undirected = Check_Undirected_Graph(graph);

		if (is_undirected)
		{
			for (int i = 0; i < graph.nV; i++)
			{
				for (int j = 0; j < graph.nV; j++)
				{
					if (graph.adj[i][j] != 0 && j > i)  
					{
						graph.degree[i]++;
						graph.degree[j]++;
						graph.edges.push_back({ i, j, graph.adj[i][j] });
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
						graph.in_degree[j]++;
						graph.out_degree[i]++;
						graph.edges.push_back({ i, j, graph.adj[i][j] });
					}
				}
			}
		}

		is.close();
	}
	else
	{
		cout << "Khong mo duoc file!\n";
	}
}

int Largest_Weight_Number(vector<Edge> edges)
{
	if (edges.empty()) return -1;

	int max_w = -INF;
	for (auto edge : edges)
		if (max_w < edge.w)
			max_w = edge.w;
	return max_w;
}

void Calculate_Undirected_Degree(ofstream& os, int nV, vector<int> degree)
{
	for (int i = 0; i < nV; i++)
	{
		os << "Bac cua dinh " << i << "la: " << degree[i] << "\n";
	}
}

void Calculate_Directed_Degree(ofstream& os, int nV, vector<int> in_degree, vector<int> out_degree)
{
	for (int i = 0; i < nV; i++)
	{
		os << "Dinh " << i << " Ban bac vao la: " << in_degree[i] 
			<< ", Ban bac ra la: " << out_degree[i] << "\n";
	}
}

void Largest_Undirected_Degree(ofstream& os, int nV, vector<int> degree)
{
	int max = -INF;
	vector<int> vec(0);

	for (int i = 0; i < nV; i++)
	{
		if (max < degree[i]) 
		{
			max = degree[i];
			
			vec.push_back(i);
		}
	}

	os << "Dinh co bac lon nhat la: ";
	if (!vec.empty())
	{
		for (auto x : vec)
			os << x << " ";
		os << "\n";
	}
	else os << "Khong co!\n";

}

void Largest_Directed_Degree(ofstream& os, int nV, vector<int> in_degree, vector<int> out_degree)
{
	int max = -INF;
	vector<int> vec(0);

	for (int i = 0; i < nV; i++)
	{
		int total = in_degree[i] + out_degree[i];
		if (max < total)
		{
			max = total;
			vec.push_back(i);
		}
	}

	os << "Dinh co bac lon nhat la: ";
	if (!vec.empty())
	{
		for (auto x : vec)
			os << x << " ";
		os << "\n";
	}
	else os << "Khong co!\n";
}

void Smallest_Undirected_Degree(ofstream& os, int nV, vector<int> degree)
{
	int min = INF;
	vector<int> vec(0);

	for (int i = 0; i < nV; i++)
	{
		if (min > degree[i])
		{
			min = degree[i];
			vec.push_back(i);
		}
	}

	os << "Dinh co bac nho nhat la: ";
	if (!vec.empty())
	{
		for (auto x : vec)
			os << x << " ";
		os << "\n";
	}
	else os << "Khong co!\n";
}

void Smallest_Directed_Degree(ofstream& os, int nV, vector<int> in_degree, vector<int> out_degree)
{
	int min = INF;
	vector<int> vec(0);

	for (int i = 0; i < nV; i++)
	{
		int total = in_degree[i] + out_degree[i];
		if (min > total)
		{
			min = total;
			vec.push_back(i);
		}
	}

	os << "Dinh co bac nho nhat la: ";
	if (!vec.empty())
	{
		for (auto x : vec)
			os << x << " ";
		os << "\n";
	}
	else os << "Khong co!\n";
}

void Find_Even_Odd_Undirected_Degree_Vertices(ofstream& os, int nV, vector<int> degree)
{
	os << "Cac dinh bac chan la: ";
	for (int i = 0; i < nV; i++)
	{
		if (degree[i] % 2 == 0)
			os << i << " ";
	}
	os << "\n";

	os << "Cac dinh bac le la: ";
	for (int i = 0; i < nV; i++)
	{
		if (degree[i] % 2 != 0)
			os << i << " ";
	}
	os << "\n";
}

void Find_Even_Odd_Directed_Degree_Vertices(ofstream& os, int nV, vector<int> in_degree, vector<int> out_degree)
{
	os << "Cac dinh bac vao chan la: ";
	for (int i = 0; i < nV; i++)
	{
		if (in_degree[i] % 2 == 0)
			os << i << " ";
	}
	os << "\n";

	os << "Cac dinh bac vao le la: ";
	for (int i = 0; i < nV; i++)
	{
		if (in_degree[i] % 2 != 0)
			os << i << " ";
	}
	os << "\n";

	os << "Cac dinh bac ra chan la: ";
	for (int i = 0; i < nV; i++)
	{
		if (out_degree[i] % 2 == 0)
			os << i << " ";
	}
	os << "\n";

	os << "Cac dinh bac ra le la: ";
	for (int i = 0; i < nV; i++)
	{
		if (out_degree[i] % 2 != 0)
			os << i << " ";
	}
	os << "\n";
}

void Find_Pendant_Isolated_Vertices_Undirected(ofstream& os, int nV, vector<int> degree)
{
	os << "Cac dinh treo: ";

	bool Has_Pendant = false;
	for (int i = 0; i < nV; i++)
	{
		if (degree[i] == 1)
		{
			os << i << " ";
			Has_Pendant = true;
		}
	}
	if (Has_Pendant == false) 
		os << "Khong co!";
	os << "\n";

	os << "Cac dinh co lap la: ";

	bool Has_Isolated = false;
	for (int i = 0; i < nV; i++)
	{
		if (degree[i] == 0)
		{
			os << i << " ";
			Has_Isolated = true;
		}
	}
	if (Has_Isolated == false) 
		os << "Khong co!";
	os << "\n";
}

void Find_Pendant_Isolated_Vertices_Directed(ofstream& os, int nV, vector<int> in_degree, vector<int> out_degree)
{
	os << "Cac dinh treo la: ";

	bool Has_Pendant = false;
	for (int i = 0; i < nV; i++)
	{
		int total = in_degree[i] + out_degree[i];
		if (total == 1)
		{
			os << i << " ";
			Has_Pendant = true;
		}
	}
	if (Has_Pendant == false) 
		os << "Khong co!";
	os << "\n";

	os << "Cac dinh co lap la: ";

	bool Has_Isolated = false;
	for (int i = 0; i < nV; i++)
	{
		int total = in_degree[i] + out_degree[i];
		if (total == 0)
		{
			os << i << " ";
			Has_Isolated = true;
		}
	}
	if (Has_Isolated == false) 
		os << "Khong co!";
	os << "\n";
}

vector<int>visited_domain;
int interconnected_domain;

void Visit(int nV, vector<vector<int>> adj, int i, int interconnected_domain)
{
	visited_domain[i] = interconnected_domain;
	for (int j = 0; j < nV; j++)
		if (visited_domain[j] == 0 && adj[i][j] != 0)
			Visit(nV, adj, j, interconnected_domain);
}

void Consider_The_Connectivity_Of_Graph(int nV, vector<vector<int>> adj)
{
	interconnected_domain = 0; 
	visited_domain.resize(nV, 0);

	for (int i = 0; i < nV; i++)
	{
		if (visited_domain[i] == 0)
		{
			interconnected_domain++;
			Visit(nV, adj, i, interconnected_domain);
		}
	}
}

void Print_Interconnected_Domain(ofstream& os, int nV, vector<vector<int>> adj)
{
	os << "So mien lien thong: " << interconnected_domain << "\n";

	for (int i = 1; i <= interconnected_domain; i++)
	{
		os << "Mien lien thong " << i << " gom cac dinh: \n";
		for (int j = 0; j < nV; j++)
		{
			if (visited_domain[j] == i)
				os << setw(4) << j;
		}
		os << "\n";
	}
}

void Print_Graph(string fn, Graph& graph, bool is_undirected)
{
	ofstream os(fn);

	if (os.is_open())
	{
		os << "So dinh trong do thi: " << graph.nV << "\n";
		os << "So canh trong do thi: " << graph.edges.size() << "\n";
		os << "Do thi: " << endl;

		for (int i = 0; i < graph.nV; i++)
		{
			for (int j = 0; j < graph.nV; j++)
			{
				os << setw(4) << graph.adj[i][j] << " ";
			}
			os << endl;
		}

		os << endl;

		os << "Trong so lon nhat trong do thi la: " << Largest_Weight_Number(graph.edges);
		os << "\n";

		if (is_undirected)
		{
			os << "La do thi vo huong." << "\n\n";
			Calculate_Undirected_Degree(os, graph.nV, graph.degree);
			os << "\n";

			Largest_Undirected_Degree(os, graph.nV, graph.degree);
			os << "\n";

			Smallest_Undirected_Degree(os, graph.nV, graph.degree);
			os << "\n";

			Find_Even_Odd_Undirected_Degree_Vertices(os, graph.nV, graph.degree);
			os << "\n";

			Find_Pendant_Isolated_Vertices_Undirected(os, graph.nV, graph.degree);
			os << "\n";
		}

		else
		{
			os << "La do thi co huong." << "\n\n";
			Calculate_Directed_Degree(os, graph.nV, graph.in_degree, graph.out_degree);
			os << "\n";

			Largest_Directed_Degree(os, graph.nV, graph.in_degree, graph.out_degree);
			os << "\n";

			Smallest_Directed_Degree(os, graph.nV, graph.in_degree, graph.out_degree);
			os << "\n";

			Find_Even_Odd_Directed_Degree_Vertices(os, graph.nV, graph.in_degree, graph.out_degree);
			os << "\n";

			Find_Pendant_Isolated_Vertices_Directed(os, graph.nV, graph.in_degree, graph.out_degree);
			os << "\n";
		}

		Consider_The_Connectivity_Of_Graph(graph.nV, graph.adj);
		Print_Interconnected_Domain(os, graph.nV, graph.adj);

		os.close();
	}
	else
	{
		cout << "Khong mo file de ghi duoc!\n";
	}
}

int main()
{
	Graph graph;
	bool is_undirected;

	Read_Graph("input.txt", graph, is_undirected);
	Print_Graph("output.txt", graph, is_undirected);

	return 0;
}

//7
//0 7 0 5 0 0 0
//7 0 8 9 7 0 0
//0 8 0 0 5 0 0
//5 9 0 0 15 6 0
//0 7 5 15 0 8 9
//0 0 0 6 8 0 11
//0 0 0 0 9 11 0

//Co huong


