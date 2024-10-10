#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <iomanip>
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

// --- Helper Functions ---

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
        cout << "Cannot open file!" << endl;
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

// --- Algorithms ---

// Dijkstra's Algorithm
void Dijkstra(const Graph& graph, int src, ofstream& os)
{
    vector<int> dist(graph.nV, INF);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, src });

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < graph.nV; v++)
        {
            if (graph.adj[u][v] != 0)
            {
                int weight = graph.adj[u][v];
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({ dist[v], v });
                }
            }
        }
    }

    os << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < graph.nV; i++)
    {
        os << "Vertex " << i << ": " << dist[i] << "\n";
    }
}

// Bellman-Ford Algorithm
bool BellmanFord(const Graph& graph, int src, ofstream& os)
{
    vector<int> dist(graph.nV, INF);
    dist[src] = 0;

    for (int i = 1; i <= graph.nV - 1; i++)
    {
        for (const Edge& edge : graph.edges)
        {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.w;
            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative weight cycle
    for (const Edge& edge : graph.edges)
    {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.w;
        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            os << "Graph contains negative weight cycle\n";
            return false;
        }
    }

    os << "Shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < graph.nV; i++)
    {
        os << "Vertex " << i << ": " << dist[i] << "\n";
    }
    return true;
}

// Prim's Algorithm
void Prim(const Graph& graph, ofstream& os)
{
    vector<int> key(graph.nV, INF);
    vector<bool> inMST(graph.nV, false);
    vector<int> parent(graph.nV, -1);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < graph.nV - 1; count++)
    {
        int u = -1;
        for (int i = 0; i < graph.nV; i++)
        {
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }

        inMST[u] = true;

        for (int v = 0; v < graph.nV; v++)
        {
            if (graph.adj[u][v] && !inMST[v] && graph.adj[u][v] < key[v])
            {
                key[v] = graph.adj[u][v];
                parent[v] = u;
            }
        }
    }

    os << "Edges in MST:\n";
    for (int i = 1; i < graph.nV; i++)
    {
        os << parent[i] << " - " << i << " : " << graph.adj[i][parent[i]] << "\n";
    }
}

// Floyd-Warshall Algorithm
void FloydWarshall(const Graph& graph, ofstream& os)
{
    vector<vector<int>> dist(graph.nV, vector<int>(graph.nV, INF));

    for (int i = 0; i < graph.nV; i++)
    {
        for (int j = 0; j < graph.nV; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else if (graph.adj[i][j] != 0)
                dist[i][j] = graph.adj[i][j];
        }
    }

    for (int k = 0; k < graph.nV; k++)
    {
        for (int i = 0; i < graph.nV; i++)
        {
            for (int j = 0; j < graph.nV; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    os << "Shortest distances matrix:\n";
    for (int i = 0; i < graph.nV; i++)
    {
        for (int j = 0; j < graph.nV; j++)
        {
            if (dist[i][j] == INF)
                os << "INF ";
            else
                os << dist[i][j] << " ";
        }
        os << "\n";
    }
}

// Kruskal's Algorithm
struct DisjointSet
{
    vector<int> parent, rank;

    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

void Kruskal(const Graph& graph, ofstream& os)
{
    vector<Edge> result;  // Store the resulting MST
    int mst_weight = 0;

    // Sort edges by weight
    vector<Edge> edges = graph.edges;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.w < b.w; });

    DisjointSet ds(graph.nV);

    for (const Edge& edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v))
        {
            result.push_back(edge);
            mst_weight += edge.w;
            ds.unite(u, v);
        }
    }

    os << "Edges in MST (Kruskal's):\n";
    for (const Edge& edge : result)
    {
        os << edge.u << " - " << edge.v << " : " << edge.w << "\n";
    }
    os << "Total weight of MST: " << mst_weight << "\n";
}

void print_graph(string ofs, const Graph& graph)  // Pass by const reference
{
    ofstream os(ofs);

    if (!os.is_open())
        cout << "Cannot open file!" << endl;
    else
    {
        os << "Number of vertices: " << graph.nV << "\n";
        os << "Adjacency matrix:\n";
        for (int i = 0; i < graph.nV; i++)
        {
            for (int j = 0; j < graph.nV; j++)
            {
                os << setw(4) << graph.adj[i][j];
            }
            os << "\n";
        }
        os << "Number of edges: " << graph.edges.size() << "\n";

        if (check_undirected_graph(graph))
        {
            os << "Undirected graph!\n\n";

            os << "\nRunning Dijkstra's Algorithm:\n\n";
            Dijkstra(graph, 0, os);

            os << "\nRunning Bellman-Ford Algorithm:\n\n";
            BellmanFord(graph, 0, os);

            os << "\nRunning Prim's Algorithm:\n\n";
            Prim(graph, os);

            os << "\nRunning Floyd-Warshall Algorithm:\n\n";
            FloydWarshall(graph, os);

            os << "\nRunning Kruskal's Algorithm:\n\n";
            Kruskal(graph, os);
        }
        else
        {
            os << "Directed graph!\n\n";

            os << "\nRunning Dijkstra's Algorithm:\n\n";
            Dijkstra(graph, 0, os);

            os << "\nRunning Bellman-Ford Algorithm:\n";
            BellmanFord(graph, 0, os);

            os << "\nRunning Prim's Algorithm:\n";
            Prim(graph, os);

            os << "\nRunning Floyd-Warshall Algorithm:\n";
            FloydWarshall(graph, os);

            os << "\nRunning Kruskal's Algorithm:\n";
            Kruskal(graph, os);
        }
        os.close();

    }
}


// --- Main Program ---

int main()
{
    Graph graph;
    read_graph("input.txt", graph);
    print_graph("output.txt", graph);

    return 0;
}
