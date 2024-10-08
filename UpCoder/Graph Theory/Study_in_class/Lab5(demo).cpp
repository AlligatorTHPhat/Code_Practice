//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <iomanip>
//
//using namespace std;
//
//const int INF = 10e9;
//
//struct Edge
//{
//	int u, v, w;
//};
//
//struct Graph
//{
//	int nV;
//	vector<Edge> edges;
//	vector<vector<int>> adj;
//
//	Graph() : nV(0) {}
//
//	void init_Graph()
//	{
//		edges.clear();
//		adj.resize(nV, vector<int>(nV, 0));
//	}
//};
//
//bool check_undiracted_graph(Graph graph)
//{
//	for (int i = 0; i < graph.nV; i++)
//	{
//		for (int j = 0; j < graph.nV; j++)
//		{
//			if (graph.adj[i][j] != graph.adj[i][j])
//				return false;
//		}
//	}
//	return true;
//}
//
//
//void read_graph(string fn, Graph& graph) {
//	ifstream is(fn);
//
//	if (is.is_open()) {
//		is >> graph.nV;
//
//		graph.init_Graph();
//
//		if (check_undiracted_graph(graph))
//		{
//			for (int i = 0; i < graph.nV; i++) {
//				for (int j = 0; j < graph.nV; j++) {
//					is >> graph.adj[i][j];
//					if (graph.adj[i][j] != 0 && j > i) {
//						graph.edges.push_back({ i, j, graph.adj[i][j] });
//					}
//				}
//			}
//		}
//		else
//		{
//			for (int i = 0; i < graph.nV; i++) {
//				for (int j = 0; j < graph.nV; j++) {
//					is >> graph.adj[i][j];
//					if (graph.adj[i][j] != 0) {
//						graph.edges.push_back({ i, j, graph.adj[i][j] });
//					}
//				}
//			}
//		}
//		
//		is.close();
//	}
//	else {
//		cout << "Khong mo duoc file!";
//	}
//}
//
//
//
//void print_graph(string fn, Graph& graph) {
//    ofstream os(fn);
//    if (os.is_open()) {
//		os << "So canh trong do thi la: " << graph.nV << "\n";
//
//		for (int i = 0; i < graph.nV; i++)
//		{
//			for (int j = 0; j < graph.nV; j++)
//			{
//				os << setw(4) << graph.adj[i][j];
//			}
//			os << "\n";
//		}
//
//        os.close();
//    }
//    else {
//        cout << "Khong mo duoc file!";
//    }
//}
//
//
//int main()
//{
//	Graph graph;
//
//	read_graph("input.txt", graph);
//	print_graph("output.txt", graph);
//}


//vector<int> Dijkstra(Graph& graph, int start, int end)
//{
//	vector<int> lastV(graph.nV, -1);
//	vector<int> length(graph.nV, INF);
//	vector<bool> visited;
//
//	for (int i = 0; i < graph.nV; i++)
//	{
//
//	}
//
//	int v = start;
//	while (visited[end] == true)
//	{
//		for (int k = 0; k < graph.nV; k++)
//		{
//			if (visited[k] && graph.adj[v][k] != 0 &&
//				(length[v] || graph.adj[v][k] + length[v] < length[v]))
//				length[k] = graph.adj[v][k] + length[v];
//		}
//	}
//
//}

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Edge
{
    int u, v, w;
};

struct Graph
{
    int nV;
    vector<Edge> edges;
    vector<vector<int>> adj;

    Graph() : nV(0) {}

    void init_Graph()
    {
        edges.clear();
        adj.resize(nV, vector<int>(nV, INF)); 
        for (int i = 0; i < nV; i++) adj[i][i] = 0; 
    }
};

bool check_undirected_graph(Graph graph)
{
    for (int i = 0; i < graph.nV; i++)
    {
        for (int j = i + 1; j < graph.nV; j++)
        {
            if (graph.adj[i][j] != graph.adj[j][i])
                return false;
        }
    }
    return true;
}

void read_graph(string fn, Graph& graph) {
    ifstream is(fn);

    if (is.is_open()) {
        is >> graph.nV;

        graph.init_Graph();

        for (int i = 0; i < graph.nV; i++) {
            for (int j = 0; j < graph.nV; j++) {
                is >> graph.adj[i][j];
                if (graph.adj[i][j] != 0 && graph.adj[i][j] != INF) {
                    graph.edges.push_back({ i, j, graph.adj[i][j] });
                }
            }
        }

        is.close();
    }
    else {
        cout << "Cannot open input file!" << endl;
    }
}

void print_graph(string fn, Graph& graph) {
    ofstream os(fn);
    if (os.is_open()) {
        os << "Graph adjacency matrix (" << graph.nV << " vertices):\n";
        for (int i = 0; i < graph.nV; i++) {
            for (int j = 0; j < graph.nV; j++) {
                if (graph.adj[i][j] == INF)
                    os << setw(4) << "INF";
                else
                    os << setw(4) << graph.adj[i][j];
            }
            os << "\n";
        }
        os.close();
    }
    else {
        cout << "Cannot open output file!" << endl;
    }
}

// Dijkstra's algorithm for a single source
void Dijkstra(Graph& graph, int src, vector<int>& dist) {
    int V = graph.nV;
    vector<bool> visited(V, false);
    dist.resize(V, INF);
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;

        // Select the vertex with the minimum distance
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;
        }

        visited[u] = true;

        // Relax adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph.adj[u][v] != INF && dist[u] + graph.adj[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.adj[u][v];
            }
        }
    }
}

// Floyd-Warshall algorithm for all pairs shortest paths
void FloydWarshall(Graph& graph, vector<vector<int>>& dist) {
    int V = graph.nV;
    dist = graph.adj; // Start with the adjacency matrix as initial distances

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void print_Dijkstra_result(const vector<int>& dist, int src, const string& fn) {
    ofstream os(fn, ios::app); // Append to file
    if (os.is_open()) {
        os << "Dijkstra shortest paths from vertex " << src << ":\n";
        for (int i = 0; i < dist.size(); i++) {
            if (dist[i] == INF)
                os << "Vertex " << src << " to Vertex " << i << ": INF\n";
            else
                os << "Vertex " << src << " to Vertex " << i << ": " << dist[i] << "\n";
        }
        os.close();
    }
    else {
        cout << "Cannot open output file!" << endl;
    }
}

void print_FloydWarshall_result(const vector<vector<int>>& dist, const string& fn) {
    ofstream os(fn, ios::app); // Append to file
    if (os.is_open()) {
        os << "\nFloyd-Warshall all pairs shortest paths:\n";
        for (int i = 0; i < dist.size(); i++) {
            for (int j = 0; j < dist.size(); j++) {
                if (dist[i][j] == INF)
                    os << setw(4) << "INF";
                else
                    os << setw(4) << dist[i][j];
            }
            os << "\n";
        }
        os.close();
    }
    else {
        cout << "Cannot open output file!" << endl;
    }
}

int main() {
    Graph graph;
    read_graph("input.txt", graph);
    print_graph("output.txt", graph);

    // Dijkstra from vertex 0
    vector<int> dist;
    Dijkstra(graph, 0, dist);
    print_Dijkstra_result(dist, 0, "output.txt");

    // Floyd-Warshall for all pairs shortest paths
    vector<vector<int>> dist_fw;
    FloydWarshall(graph, dist_fw);
    print_FloydWarshall_result(dist_fw, "output.txt");

    return 0;
}
