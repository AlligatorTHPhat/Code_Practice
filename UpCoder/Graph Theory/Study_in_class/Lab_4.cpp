#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

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

    void Init_Graph()
    {
        edges.resize(0);
        adj.resize(nV, vector<int>(nV, 0));
    }
};

void Read_Graph(const string& fn, Graph& graph)
{
    ifstream is(fn);
    if (is.is_open())
    {
        is >> graph.nV;
        graph.Init_Graph();
        for (int i = 0; i < graph.nV; i++)
        {
            for (int j = 0; j < graph.nV; j++)
            {
                is >> graph.adj[i][j];
                if (graph.adj[i][j] != 0 && j > i)
                    graph.edges.push_back({ i, j, graph.adj[i][j] });
            }
        }
        is.close();
    }
    else
    {
        cout << "Khong mo file duoc!\n";
    }
}

int Sum_T(vector<Edge> e) {
    int total_W = 0;
    for (Edge edge : e) {
        total_W += edge.w;
    }
    return total_W;
}

int find(vector<int>& parent, int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void Union(vector<int>& parent, vector<int>& rank, int u, int v)
{
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rootU != rootV)
    {
        if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void Kruskal_Min(Graph& graph, vector<Edge>& mst)
{
    vector<int> parent(graph.nV);
    vector<int> rank(graph.nV, 0);
    for (int i = 0; i < graph.nV; i++) parent[i] = i;

    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    for (Edge edge : graph.edges)
    {
        if (find(parent, edge.u) != find(parent, edge.v))
        {
            mst.push_back(edge);
            Union(parent, rank, edge.u, edge.v);
            if (mst.size() == graph.nV - 1) break;
        }
    }
}

void Kruskal_Max(Graph& graph, vector<Edge>& mst)
{
    vector<int> parent(graph.nV);
    vector<int> rank(graph.nV, 0);
    for (int i = 0; i < graph.nV; i++) parent[i] = i;

    sort(graph.edges.begin(), graph.edges.end(), [](Edge a, Edge b) { return a.w > b.w; });

    for (Edge edge : graph.edges)
    {
        if (find(parent, edge.u) != find(parent, edge.v))
        {
            mst.push_back(edge);
            Union(parent, rank, edge.u, edge.v);
            if (mst.size() == graph.nV - 1) break;
        }
    }
}

void Print_Spanning_Tree(ofstream& os, int nV, vector<Edge> mst)
{
    vector<vector<int>> spanningMatrix(nV, vector<int>(nV, 0));
    for (auto edge : mst)
    {
        spanningMatrix[edge.u][edge.v] = edge.w;
        spanningMatrix[edge.v][edge.u] = edge.w;
    }

    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            os << setw(4) << spanningMatrix[i][j];
        }
        os << "\n";
    }
}

void Edge_Graph(ofstream& os, vector<Edge> edges)
{
    for (const auto& e : edges)
    {
        os << "(" << e.u << "," << e.v << "): " << e.w << " ";
    }
    os << "\n";
}

void Print_Graph(const string& fn, Graph& graph)
{
    ofstream os(fn);

    if (os.is_open())
    {
        os << "So luong dinh cua do thi la: " << graph.nV << "\n";
        os << "Do thi:\n";
        for (int i = 0; i < graph.nV; i++)
        {
            for (int j = 0; j < graph.nV; j++)
            {
                os << setw(4) << graph.adj[i][j] << " ";
            }
            os << "\n";
        }

        os << "So luong canh cua do thi la: " << graph.edges.size() << "\n";

        os << "\n";

        vector<Edge> mstMin, mstMax;
        Kruskal_Min(graph, mstMin);
        Kruskal_Max(graph, mstMax);

        os << "Tong trong so trong do thi cay nho nhat la : " << Sum_T(mstMin) << "\n";
        os << "Do thi cay khung nho nhat co ma tran la:\n";
        Print_Spanning_Tree(os, graph.nV, mstMin);
        os << "Cac canh do thi cay khung nho nhat:\n";
        Edge_Graph(os, mstMin);
        os << "\n";

        os << "Tong trong so trong do thi cay lon nhat la : " << Sum_T(mstMax) << "\n";
        os << "Do thi cay khung lon nhat co ma tran la:\n";
        Print_Spanning_Tree(os, graph.nV, mstMax);
        os << "Cac canh do thi cay khung lon nhat:\n";
        Edge_Graph(os, mstMax);
        os << "\n";

        os.close();
    }
    else
    {
        cout << "Khong mo file duoc\n";
    }
}

int main()
{
    Graph graph;
    Read_Graph("input.txt", graph);
    Print_Graph("output.txt", graph);

    return 0;
}
