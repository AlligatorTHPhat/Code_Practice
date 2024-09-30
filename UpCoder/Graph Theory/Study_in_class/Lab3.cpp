#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const int INF = 10e9;
struct Edge {
    int u, v, w;
};

struct Graph {
    int Nv;                           // Number of vertices

    Graph() : Nv(0) {}
    vector<vector<int>> adj;          // Adjacency matrix
    vector<Edge> T;                   // Array to store edges of the spanning tree
};

// Read the graph from file
void Read_Graph(Graph& g, string fn) {
    ifstream f(fn);

    if (f.is_open()) {
        f >> g.Nv;

        g.adj.resize(g.Nv, vector<int>(g.Nv));  // Initialize NxN adjacency matrix

        for (int i = 0; i < g.Nv; i++) {
            for (int j = 0; j < g.Nv; j++) {
                f >> g.adj[i][j];
            }
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file input!" << endl;
    }
}

// Find the edge with the minimum weight
Edge Find_Min_Edge(vector<Edge> e) {
    if (e.empty()) {
        cout << "Khong co canh!" << endl;
        return { -1, -1, INF }; // Invalid edge
    }

    Edge min_edge = e[0];
    for (auto edge : e) {
        if (min_edge.w > edge.w)
            min_edge = edge;
    }
    return min_edge;
}

// Find the edge with the maximum weight
Edge Find_Max_Edge(vector<Edge> e) {
    if (e.empty()) {
        cout << "Khong co canh!" << endl;
        return { -1, -1, INT_MIN }; // Invalid edge
    }

    Edge max_edge = e[0];
    for (const auto& edge : e) {
        if (max_edge.w < edge.w)
            max_edge = edge;
    }
    return max_edge;
}

// Prim's algorithm to find the minimum spanning tree
void Prim(Graph& g, vector<bool>& visited) {
    visited[0] = true;
    int nT = 0;

    while (nT < g.Nv - 1) {
        vector<Edge> e;  // Temporary vector to store available edges

        // Explore visited vertices
        for (int i = 0; i < g.Nv; i++) {
            if (visited[i]) {
                // Explore unvisited vertices
                for (int j = 0; j < g.Nv; j++) {
                    if (!visited[j] && g.adj[i][j] != 0) {
                        e.push_back({ i, j, g.adj[i][j] });
                    }
                }
            }
        }

        if (e.empty()) break;

        // Select the edge with minimum weight
        Edge min_edge = Find_Min_Edge(e);
        g.T.push_back(min_edge); // Store the edge in the spanning tree
        visited[min_edge.v] = true;
        nT++;
    }
}

// Calculate the total weight of the spanning tree
int Sum_T(vector<Edge> e) {
    int total_W = 0;
    for (const Edge& edge : e) {
        total_W += edge.w;
    }
    return total_W;
}

// Output the edges of the graph to the provided stream
void Edges_in_Graph(vector<Edge> e, ostream& ofile) {
    for (Edge edge : e) {
        ofile << "(" << edge.u + 1 << "," << edge.v + 1 << ") : " << edge.w << "\n\n";
    }
}

// Print the smallest and largest edge in the spanning tree
void Print_Max_Min_Edge(vector<Edge> e, ostream& ofile) {
    Edge max_edge = Find_Max_Edge(e);
    Edge min_edge = Find_Min_Edge(e);

    ofile << "Minimum edge: (" << min_edge.u + 1 << "," << min_edge.v + 1 << ") \n\n";
    ofile << "Maximum edge: (" << max_edge.u + 1 << "," << max_edge.v + 1 << ") \n\n";
}

void Print_Spinning_Matrix(ofstream& os, Graph graph)
{
    os << "Do thi cay khung nho nhat co ma tran la:\n";

    vector<vector<int>> spanning_Matrix(graph.Nv, vector<int>(graph.Nv, 0));

    for (auto& edge : graph.T)
    {
        spanning_Matrix[edge.u][edge.v] = edge.w;
        spanning_Matrix[edge.v][edge.u] = edge.w;
    }

    for (int i = 0; i < graph.Nv; i++)
    {
        for (int j = 0; j < graph.Nv; j++)
        {
            os << setw(4) << spanning_Matrix[i][j];
        }
        os << "\n";
    }
}

// Write the results of the spanning tree to a file
void Print_Spanning_Tree(Graph g, string fn) {
    ofstream ofile(fn);

    if (ofile.is_open()) {
        vector<bool> visited(g.Nv, false);  // Array to track visited vertices

        Prim(g, visited);                   // Find the minimum spanning tree

        ofile << "Total weight of the minimum spanning tree: " << Sum_T(g.T) << "\n\n";
        ofile << "Edges in the minimum spanning tree:\n";

        Edges_in_Graph(g.T, ofile);
        Print_Max_Min_Edge(g.T, ofile);

        Print_Spinning_Matrix(ofile, g);

        ofile.close();
    }
    else {
        cout << "Could not open output file!" << endl;
    }
}

int main() {
    Graph g;

    Read_Graph(g, "input.txt");
    Print_Spanning_Tree(g, "output.txt");

    return 0;
}
