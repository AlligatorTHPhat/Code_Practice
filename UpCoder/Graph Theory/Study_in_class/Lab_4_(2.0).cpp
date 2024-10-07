#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;
vector<bool> visited;
struct Edge {
    int u, v, w;
};

struct Graph {
    int nV;

    vector<Edge> edges;

    vector<Edge> T_min, T_max;

    vector<vector<int>> adj;

    Graph() : nV(0) {}

    void init_Graph()
    {
        edges.clear();
        adj.resize(nV, vector<int>(nV, 0));
    }
};

void Read_Graph(string fn, Graph& graph) {
    ifstream is(fn);

    if (is.is_open()) {
        is >> graph.nV;

        graph.init_Graph();

        for (int i = 0; i < graph.nV; i++) {
            for (int j = 0; j < graph.nV; j++) {
                is >> graph.adj[i][j];
                if (graph.adj[i][j] != 0 && j > i) {
                    graph.edges.push_back({ i, j, graph.adj[i][j] });
                }
            }
        }
        is.close();
    }
    else {
        cout << "Khong mo duoc file!";
    }
}

void Init_Arr_Edge(int nV, vector<vector<int>>& adj, int& nEdge, vector<Edge>& listEdge) {
    listEdge.clear();
    for (int i = 0; i < nV; i++) {
        for (int j = i + 1; j < nV; j++) {
            if (adj[i][j] != 0) {
                listEdge.push_back({ i, j, adj[i][j] });
            }
        }
    }
    nEdge = listEdge.size();
}

void DFS(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);

    for (int v = 0; v < adj.size(); v++) {
        if (adj[u][v] != 0 && !visited[v]) {
            DFS(v, adj, visited, component);
        }
    }
}

bool Check_Connected(int nV, vector<vector<int>>& adj) {
    vector<bool> visited(nV, false);
    vector<int> component;

    DFS(0, adj, visited, component);

    for (int i = 0; i < nV; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void Bubble_Sort_Edge_U_Or_V(vector<Edge>& edges) {
    int n = edges.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].u > edges[j + 1].u) {
                swap(edges[j], edges[j + 1]);
                swapped = true;
            }
            else if (edges[j].u == edges[j + 1].u && edges[j].v > edges[j + 1].v) {
                swap(edges[j], edges[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void Bubble_Sort_Edge_Min(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }
}

void Bubble_Sort_Edge_Max(vector<Edge>& edges) {
    int n = edges.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (edges[j].w < edges[j + 1].w) {
                swap(edges[j], edges[j + 1]);
            }
        }
    }
}
bool HaveLoop(int u, int v, vector<int>& Acp) {
    return Acp[u] == Acp[v];
}

void Union(int u, int v, vector<int>& Acp) {
    int oldLabel = Acp[v];
    int newLabel = Acp[u];
    for (int i = 0; i < Acp.size(); i++) {
        if (Acp[i] == oldLabel) {
            Acp[i] = newLabel;
        }
    }
}

void Kruskal_Min(int nV, vector<vector<int>>& adj, vector<Edge>& T) {
    int nEdge;
    vector<int> Acp(nV);
    vector<Edge> listEdge;

    Init_Arr_Edge(nV, adj, nEdge, listEdge);
    Bubble_Sort_Edge_Min(listEdge);

    for (int i = 0; i < nV; i++) {
        Acp[i] = i;
    }

    for (int i = 0; i < nV; i++) {
        if (Acp[i] == i) {
            int nT = 0;
            int iMin = 0;

            while (nT < nV - 1 && iMin < nEdge) {
                int u = listEdge[iMin].u;
                int v = listEdge[iMin].v;

                if (!HaveLoop(u, v, Acp)) {
                    T.push_back(listEdge[iMin]);
                    nT++;
                    Union(u, v, Acp);
                }
                iMin++;
            }
        }
    }
}

void Kruskal_Max(int nV, vector<vector<int>>& adj, vector<Edge>& edges) {
    int nEdge = edges.size();
    vector<int> Acp(nV);
    vector<Edge> listEdge;

    Init_Arr_Edge(nV, adj, nEdge, listEdge);
    Bubble_Sort_Edge_Max(listEdge);

    for (int i = 0; i < nV; i++) {
        Acp[i] = i;
    }

    for (int i = 0; i < nV; i++) {
        if (Acp[i] == i) {
            int nT = 0;
            int iMin = 0;

            while (nT < nV - 1 && iMin < nEdge) {
                int u = listEdge[iMin].u;
                int v = listEdge[iMin].v;

                if (!HaveLoop(u, v, Acp)) {
                    edges.push_back(listEdge[iMin]);
                    nT++;
                    Union(u, v, Acp);
                }
                iMin++;
            }
        }
    }
}

int SumT(vector<Edge> e) {
    int totalW = 0;
    for (const auto& edge : e) {
        totalW += edge.w;
    }
    return totalW;
}

void Edge_Tree(ostream& os, vector<Edge>& edges) {
    Bubble_Sort_Edge_U_Or_V(edges);
    for (int i = 0; i < edges.size(); i++) {
        os << "(" << edges[i].u << "," << edges[i].v << ") : " << edges[i].w;
        if (i != edges.size() - 1) os << "; ";
    }
    os << "\n";
}

void Build_Spanning_Tree_Matrix(int nV, vector<vector<int>>& matrix, vector<Edge>& edges) {
    matrix.resize(nV, vector<int>(nV, 0));
    for (auto edge : edges) {
        matrix[edge.u][edge.v] = edge.w;
        matrix[edge.v][edge.u] = edge.w;
    }
}

void Print_Matrix(ostream& os, vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto val : row) {
            os << setw(3) << val << " ";
        }
        os << "\n";
    }
}

void Find_Connected_Components(int nV, vector<vector<int>>& adj, vector<vector<int>>& components) {
    vector<bool> visited(nV, false);
    for (int u = 0; u < nV; u++) {
        if (!visited[u]) {
            vector<int> component;
            DFS(u, adj, visited, component);
            components.push_back(component);
        }
    }
}

void Create_Min_Spanning_Tree(int nV, vector<vector<int>>& adj, vector<int> component, vector<Edge>& edges) {
    vector<Edge> listEdge;
    for (int u = 0; u < component.size(); u++) {
        for (int v = u + 1; v < component.size(); v++) {
            int from = component[u];
            int to = component[v];
            if (adj[from][to] != 0) {
                listEdge.push_back(Edge{ from, to, adj[from][to] });
            }
        }
    }

    Bubble_Sort_Edge_Min(listEdge);
    vector<int> Acp(nV);
    for (int j = 0; j < nV; j++) {
        Acp[j] = j;
    }

    for (auto edge : listEdge) {
        if (!HaveLoop(edge.u, edge.v, Acp)) {
            edges.push_back(edge);
            Union(edge.u, edge.v, Acp);
        }
    }
}

void Create_Max_Spanning_Tree(int nV, vector<vector<int>>& adj, const vector<int>& component, vector<Edge>& edges) {
    vector<Edge> listEdge;
    for (int u = 0; u < component.size(); u++) {
        for (int v = u + 1; v < component.size(); v++) {
            int from = component[u];
            int to = component[v];
            if (adj[from][to] != 0) {
                listEdge.push_back(Edge{ from, to, adj[from][to] });
            }
        }
    }

    Bubble_Sort_Edge_Max(listEdge);
    vector<int> Acp(nV);
    for (int j = 0; j < nV; j++) {
        Acp[j] = j;
    }

    for (auto edge : listEdge) {
        if (!HaveLoop(edge.u, edge.v, Acp)) {
            edges.push_back(edge);
            Union(edge.u, edge.v, Acp);
        }
    }
}

void Find_Spanning_Trees_Per_Component(ostream& os, Graph graph) {
    vector<vector<int>> components;
    Find_Connected_Components(graph.nV, graph.adj, components);

    os << "\nSo thanh phan lien thong: " << components.size() << "\n\n";
    for (int i = 0; i < components.size(); i++) {
        os << "Thanh phan lien thong " << i + 1 << ": ";
        for (int v : components[i]) {
            os << v << " ";
        }
        os << "\n";

        vector<Edge> T_min;
        Create_Min_Spanning_Tree(graph.nV, graph.adj, components[i], T_min);

        vector<Edge> T_max;
        Create_Max_Spanning_Tree(graph.nV, graph.adj, components[i], T_max);

        int sumMin = SumT(T_min);
        int sumMax = SumT(T_max);

        os << "Cay khung nho nhat cua thanh phan " << i + 1 << ":\n";

        os << "\nTong trong so cua cay khung nho nhat la: " << sumMin << "\n";
        os << "Cac canh cua cay khung nho nhat:\n";
        Edge_Tree(os, T_min);


        os << "Cay khung lon nhat cua thanh phan " << i + 1 << ":\n";

        os << "\nTong trong so cua cay khung lon nhat la: " << sumMax << "\n";
        os << "Cac canh cua cay khung lon nhat:\n";
        Edge_Tree(os, T_max);

        os << "\n";
    }
}

void Print_Spanning_Tree(string fn, Graph& graph) {
    ofstream os(fn);
    if (os.is_open()) {
        os << "Kiem tra do thi lien thong: ";

        if (Check_Connected(graph.nV, graph.adj) == true) {
            os << "Do thi co lien thong!\n\n";
            vector<Edge> T_min, T_max;
            Kruskal_Min(graph.nV, graph.adj, T_min);
            Kruskal_Max(graph.nV, graph.adj, T_max);

            vector<vector<int>> min_Tree_Matrix, max_Tree_Matrix;

            os << "Cay khung lon nhat:\n";
            if (T_max.empty()) {
                os << "Khong co cay khung!\n";
            }
            else {
                os << "Tong trong so cua cay khung lon nhat la: " << SumT(T_max) << "\n";
                os << "Cac canh cua cay khung lon nhat:\n";
                Edge_Tree(os, T_max);

                Build_Spanning_Tree_Matrix(graph.nV, max_Tree_Matrix, T_max);
                os << "Ma tran cay khung lon nhat:\n";
                Print_Matrix(os, max_Tree_Matrix);
            }

            os << "\n";

            os << "Cay khung nho nhat:\n";
            if (T_min.empty()) {
                os << "Khong co cay khung!\n";
            }
            else {
                os << "Tong trong so cua cay khung nho nhat la: " << SumT(T_min) << "\n";
                os << "Cac canh cua cay khung nho nhat:\n";
                Edge_Tree(os, T_min);

                Build_Spanning_Tree_Matrix(graph.nV, min_Tree_Matrix, T_min);
                os << "Ma tran cay khung nho nhat:\n";
                Print_Matrix(os, min_Tree_Matrix);
            }
        }
        else {
            os << "Do thi khong lien thong!\n";
            Find_Spanning_Trees_Per_Component(os, graph);
        }
        os.close();
    }
    else {
        cout << "Khong mo duoc file!";
    }
}

int main() {
    Graph graph;
    Read_Graph("input.txt", graph);
    Print_Spanning_Tree("output.txt", graph);
    return 0;
}


//lien thong
//7
//0 7 0 5 0 0 0
//7 0 8 9 7 0 0
//0 8 0 0 5 0 0
//5 9 0 0 15 6 0
//0 7 5 15 0 8 9
//0 0 0 6 8 0 11
//0 0 0 0 9 11 0

//Khong lien thong
//7
//0 1 2 0 0 0 0
//1 0 3 0 0 0 0
//2 3 0 0 0 0 0
//0 0 0 0 8 0 0
//0 0 0 8 0 9 11
//0 0 0 0 9 0 10
//0 0 0 0 10 11 0
