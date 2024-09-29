#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>

using namespace std;

struct Graph
{
	int Nv, Ne;

	vector<int> degree, in_degree, out_degree;
	vector<vector<int>> adj;

	Graph() : Nv(0), Ne(0) {}

	void init_Degree()
	{
		degree.resize(Nv, 0);
		in_degree.resize(Nv, 0);
		out_degree.resize(Nv, 0);
		adj.resize(Nv, vector<int>(Nv, 0));
	}
};

bool Check_Undirected_Graph(Graph graph)
{
	for (int i = 0; i < graph.Nv; i++)
	{
		for (int j = 0; j < graph.Nv; j++)
		{
			if (graph.adj[i][j] != graph.adj[j][i])
				return false;
		}
	}
	return true;
}

int Start, End;

void Read_Graph(string ifs, Graph& graph)
{
	ifstream ifile(ifs);

	if (!ifile.is_open())
		cout << "Khong mo file duoc!";

	else
	{
		ifile >> graph.Nv;

		graph.init_Degree();

		for (int i = 0; i < graph.Nv; i++)
			for (int j = 0; j < graph.Nv; j++)
				ifile >> graph.adj[i][j];

		if (Check_Undirected_Graph(graph))
		{
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
		}

		else
		{
			for (int i = 0; i < graph.Nv; i++)
			{
				for (int j = 0; j < graph.Nv; j++)
				{
					if (graph.adj[i][j] != 0)
					{
						graph.Ne++;
						graph.in_degree[j]++;
						graph.out_degree[i]++;
					}
				}
			}
		}

		ifile.close();
	}
}

void Largest_Weight_Number(ofstream& ofile, Graph graph)
{
	int max = -100;
	for (int i = 0; i < graph.Nv; i++)
	{
		for (int j = 0; j < graph.Nv; j++)
		{
			if (graph.adj[i][j] > max && graph.adj[i][j] != 0)
				max = graph.adj[i][j];
		}
	}

	ofile << "Trong so lon nhat trong do thi la : " << max << endl;

	ofile << endl;
}

void Calculate_Degree(ofstream& ofile, Graph graph)
{

	if (Check_Undirected_Graph(graph))
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			ofile << "Bac cua dinh la : " << i + 1 << " la : " << graph.degree[i] << " ";
		}
	}

	else
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			ofile << "Dinh " << i + 1 << " gom : "
				<< "Ban ba vao la : " << graph.in_degree[i]
				<< ", Ban bac ra la : " << graph.out_degree[i] << endl;
		}
	}

	ofile << endl;
}

void Largest_Degree(ofstream& ofile, Graph graph)
{
	int max = -100;
	int pos = -1;
	vector<int> vec;

	if (Check_Undirected_Graph(graph))
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] > max)
			{
				max = graph.degree[i];
				pos = i;
			}
		}

		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] == max)
				vec.push_back(i);
		}
	}

	else
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			int total = graph.in_degree[i] + graph.out_degree[i];
			if (total > max)
			{
				max = total;
				pos = i;
			}
		}

		for (int i = 0; i < graph.Nv; i++)
		{
			int total = graph.in_degree[i] + graph.out_degree[i];

			if (total == max)
				vec.push_back(i);
		}
	}

	ofile << "Dinh co bac lon nhat la : ";
	if (vec.size() == 0) ofile << pos + 1;
	else if (vec.size() > 0)
		for (auto v : vec) ofile << v + 1 << " ";
	else ofile << "Khong co";

	ofile << endl;
}

void Lowest_Degree(ofstream& ofile, Graph graph)
{
	int min = 100;
	int pos = -1;
	vector<int> vec;

	if (Check_Undirected_Graph(graph))
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] < min)
			{
				min = graph.degree[i];
				pos = i;
			}
		}

		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] == min)
				vec.push_back(i);
		}
	}

	else
	{
		for (int i = 0; i < graph.Nv; i++)
		{
			int total = graph.in_degree[i] + graph.out_degree[i];
			if (total < min)
			{
				min = total;
				pos = i;
			}
		}

		for (int i = 0; i < graph.Nv; i++)
		{
			int total = graph.in_degree[i] + graph.out_degree[i];
			if (total == min)
				vec.push_back(i);
		}
	}

	ofile << "Dinh co bac nho nhat la : ";
	if (vec.size() == 0) ofile << pos + 1;
	else if (vec.size() > 0)
		for (auto v : vec) ofile << v + 1 << " ";
	else ofile << "Khong co";

	ofile << endl;
}

void Find_Even_Odd_Degree_Vertices(ofstream& ofile, Graph graph)
{
	if (Check_Undirected_Graph(graph))
	{
		ofile << "Cac dinh bac chan : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] % 2 == 0) ofile << i + 1 << " ";
		}

		ofile << endl;

		ofile << "Cac dinh bac le : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] % 2 != 0) ofile << i + 1 << " ";
		}
	}

	else
	{
		ofile << "Cac dinh vao bac chan : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.in_degree[i] % 2 == 0) ofile << i + 1 << " ";
		}

		ofile << endl;

		ofile << "Cac dinh vao bac le : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.in_degree[i] % 2 != 0) ofile << i + 1 << " ";
		}

		ofile << endl;

		ofile << "Cac dinh ra bac chan : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.out_degree[i] % 2 == 0) ofile << i + 1 << " ";
		}

		ofile << endl;

		ofile << "Cac dinh ra bac le : ";
		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.out_degree[i] % 2 != 0) ofile << i + 1 << " ";
		}
	}

	ofile << endl;
}

void Find_Pendant_Isolated_Vertices(ofstream& ofile, Graph graph)
{
	if (Check_Undirected_Graph(graph))
	{
		bool has_pendant = false;

		ofile << "Dinh treo : ";

		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] == 1)
			{
				ofile << i + 1 << " ";
				has_pendant = true;
			}
		}

		if (!has_pendant) ofile << "Khong co";

		ofile << endl;

		bool has_isolated = false;

		ofile << "Dinh co lap : ";

		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.degree[i] == 0)
			{
				ofile << i + 1 << " ";
				has_isolated = true;
			}
		}

		if (!has_isolated) ofile << "Khong co";
	}

	else
	{
		bool has_pendant = false;

		ofile << "Dinh treo : ";

		for (int i = 0; i < graph.Nv; i++)
		{
			if ((graph.in_degree[i] == 1 && graph.out_degree[i] == 0) ||
				(graph.in_degree[i] == 0 && graph.out_degree[i] == 1))
			{
				ofile << i + 1 << " ";
				has_pendant = true;
			}
		}

		if (!has_pendant) ofile << "Khong co" << endl;

		ofile << endl;

		ofile << "Dinh co lap : ";

		bool has_isolated = false;

		for (int i = 0; i < graph.Nv; i++)
		{
			if (graph.in_degree[i] == 0 && graph.out_degree[i] == 0)
			{
				ofile << i + 1 << " ";
				has_isolated = true;
			}
		}

		if (!has_isolated) ofile << "Khong co";
	}

	ofile << endl;
}

int visited_domain[100];
int interconnected_domain;

void Visit(Graph graph, int i, int interconnected_domain)
{
	visited_domain[i] = interconnected_domain;
	for (int j = 0; j < graph.Nv; j++)
	{
		if (visited_domain[j] == 0 && graph.adj[i][j] != 0)
		{
			Visit(graph, j, interconnected_domain);
		}
	}
}

void Consider_The_Connectivity_Of_Graph(Graph graph)
{
	interconnected_domain = 0;
	fill(visited_domain, visited_domain + graph.Nv, 0);

	for (int i = 0; i < graph.Nv; i++)
	{
		if (visited_domain[i] == 0)
		{
			interconnected_domain++;
			Visit(graph, i, interconnected_domain);
		}
	}
}

void Print_Interconnected_Domain(ofstream& ofile, Graph graph)
{
	ofile << "So mien lien thong: " << interconnected_domain << endl;

	for (int i = 1; i <= interconnected_domain; i++)
	{
		ofile << "Mien lien thong " << i << " gom cac dinh ";

		for (int j = 0; j < graph.Nv; j++)
		{
			if (visited_domain[j] == i)
			{
				ofile << setw(4) << j;
			}
		}
		ofile << endl;
	}
	ofile << endl;
}

void Edges_To_Connect_Graph(Graph graph, ofstream& ofile)
{
	Consider_The_Connectivity_Of_Graph(graph);

	if (interconnected_domain = 1)
	{
		ofile << "Do thi da lien thong, khong can them canh." << endl;
		return;
	}

	ofile << "Can " << interconnected_domain - 1 << " canh de do thi lien thong." << endl;
	ofile << "Nhung canh can them la : " << endl;

	int previous_vertex = -1;
	for (int i = 0; i < graph.Nv; i++)
	{
		if (visited_domain[i] == 1)
		{
			previous_vertex = i;
			break;
		}
	}

	for (int i = 2; i <= interconnected_domain; i++)
	{
		for (int j = 0; j < graph.Nv; j++)
		{
			if (visited_domain[j] == i)
			{
				ofile << previous_vertex + 1 << " - " << j + 1 << endl;
				previous_vertex = j;
				break;
			}
		}
	}

	ofile << endl;
}

bool visited[100];
int save[100];
vector<int> saving;

void DFS(Graph graph, int i) {
	visited[i] = true;
	for (int j = 0; j < graph.Nv; j++) {
		if (!visited[j] && graph.adj[i][j] != 0) {
			save[j] = i;
			saving.push_back(j);
			DFS(graph, j);
		}
	}
}

void BFS(Graph graph, int s) {
	fill(visited, visited + graph.Nv, false);
	fill(save, save + graph.Nv, -1);

	queue<int> q;
	q.push(s);
	visited[s] = true;

	while (!q.empty()) {
		int que = q.front();
		q.pop();
		saving.push_back(que);

		for (int i = 0; i < graph.Nv; i++) {
			if (graph.adj[que][i] && !visited[i]) {
				q.push(i);
				save[i] = que;
				visited[i] = true;
			}
		}
	}
}

void Find_Path(int Start, Graph graph, ofstream& ofile) {
	//DFS(graph, Start);

	BFS(graph, Start);

	if (!saving.empty()) {
		ofile << "Duyet theo chieu rong: " << endl;

		for (int i = 0; i < saving.size(); i++) {
			ofile << saving[i];
			if (i != saving.size() - 1) {
				ofile << "<---";
			}
		}
		ofile << endl;
	}
	else {
		ofile << "Khong co duong di tu " << Start << " den " << End << endl;
	}

	ofile << endl;

	ofile.close();
}


void Print_Graph(string ofs, Graph graph)
{
	ofstream ofile(ofs);

	if (!ofile.is_open()) {
		cout << "Khong mo file de ghi duoc!" << endl;
		return;
	}

	else
	{
		ofile << "So canh trong do thi : " << graph.Ne << endl;

		ofile << "Do thi : " << endl;

		for (int i = 0; i < graph.Nv; i++)
		{
			for (int j = 0; j < graph.Nv; j++)
			{
				ofile << setw(4) << graph.adj[i][j] << " ";
			}
			ofile << endl;
		}

		ofile << endl;

		if (Check_Undirected_Graph(graph))
			ofile << "La do thi vo huong." << endl;
		else
			ofile << "La do thi co huong." << endl;

		ofile << "So canh trong do thi : " << graph.Nv << endl;

		Largest_Weight_Number(ofile, graph);

		Calculate_Degree(ofile, graph);

		Largest_Degree(ofile, graph);

		Lowest_Degree(ofile, graph);

		Find_Even_Odd_Degree_Vertices(ofile, graph);

		Find_Pendant_Isolated_Vertices(ofile, graph);

		Consider_The_Connectivity_Of_Graph(graph);

		Print_Interconnected_Domain(ofile, graph);

		Edges_To_Connect_Graph(graph, ofile);

		Find_Path(Start, graph, ofile);
		//Find_Path(graph , ofile, Start, End);

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

//8
//0 1 0 0 0 1 0 0
//1 0 1 1 0 0 0 0
//0 1 0 0 1 0 0 0
//0 1 0 0 0 0 0 0
//0 0 1 0 0 0 0 0
//1 0 0 0 0 0 1 0
//0 0 0 0 0 1 0 1
//0 0 0 0 0 0 1 0

//undirected
//10  

//0 0 0 0 0 0 0 0 0 0  
//0 0 1 1 0 0 0 0 0 0
//0 1 0 0 1 0 0 0 0 0
//0 1 0 0 1 1 0 0 0 0
//0 0 1 1 0 1 0 0 0 0
//0 0 0 1 1 0 1 0 0 0
//0 0 0 0 0 1 0 0 0 0  
//0 0 0 0 0 0 0 0 1 1
//0 0 0 0 0 0 0 1 0 1
//0 0 0 0 0 0 0 1 1 0


//Co huong
//10  
//
//0 0 0 0 0 0 0 0 0 0  
//0 0 1 1 0 0 0 0 0 0
//0 0 0 0 1 0 0 0 0 0
//0 1 0 0 1 1 0 0 0 0
//0 0 0 1 0 1 0 0 0 0
//0 0 0 1 0 0 1 0 0 0  
//0 0 0 0 0 0 0 0 0 0  
//0 0 0 0 0 0 0 0 1 1
//0 0 0 0 0 0 0 1 0 1
//0 0 0 0 0 0 0 0 1 0
