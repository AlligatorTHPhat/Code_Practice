#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"

const int MAX = 100;

struct GRAPH {
    int Nv, Ne;
    int adj[MAX][MAX];
    int degree[MAX];

    vector<int> in_Degree;
    vector<int> out_Degree;

    GRAPH() : Nv(0), Ne(0), in_Degree(0), out_Degree(0) {
        for (int i = 0; i < MAX; ++i) {
            degree[i] = 0;
            for (int j = 0; j < MAX; ++j) {
                adj[i][j] = 0;
            }
        }
    }

    void Init_Degrees() {
        in_Degree.resize(Nv, 0);
        out_Degree.resize(Nv, 0);
    }
};

bool Check_Undirected_Graph(GRAPH graph) {
    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            if (graph.adj[i][j] != graph.adj[j][i])
                return false;
        }
    }
    return true;
}

void Read_Graph(string fn, GRAPH& graph) {
    ifstream file(fn);

    if (file.is_open()) {
        file >> graph.Nv;

        for (int i = 0; i < graph.Nv; i++) {
            for (int j = 0; j < graph.Nv; j++) {
                file >> graph.adj[i][j];
            }
        }

        graph.Init_Degrees();

        graph.Ne = 0;

        if (Check_Undirected_Graph(graph)) {
            for (int i = 0; i < graph.Nv; i++) {
                for (int j = 0; j < graph.Nv; j++) {
                    if (graph.adj[i][j] != 0) {
                        graph.Ne++;
                        graph.degree[i]++;
                    }
                }
            }
            graph.Ne /= 2;
        }
        else {
            for (int i = 0; i < graph.Nv; i++) {
                for (int j = 0; j < graph.Nv; j++) {
                    if (graph.adj[i][j] != 0) {
                        graph.Ne++;
                        graph.out_Degree[i]++;
                        graph.in_Degree[j]++;
                    }
                }
            }
        }
        file.close();
    }
    else {
        cout << "Khong doc duoc file!" << endl;
    }
}

void Print_Graph(GRAPH graph) {
    cout << "So dinh cua do thi : " << graph.Nv << endl;
    cout << "Do thi : " << endl;
    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            cout << setw(4) << graph.adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool visited[MAX];
int save[MAX];

void DFS(GRAPH graph, int i)
{
    visited[i] = true;
    for (int j = 0; j < graph.Nv; j++)
    {
        if (visited[j] == false && graph.adj[i][j])
        {
            save[j] = i;
            DFS(graph, j);
        }
    }
}

//void BFS(GRAPH graph, int start) {
//    queue<int> q;
//    bool visited[MAX] = { false };
//
//    q.push(start);
//    visited[start] = true;
//
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        cout << u << " ";
//
//        for (int v = 0; v < graph.Nv; v++) {
//            if (graph.adj[u][v] && !visited[v]) {
//                visited[v] = true;
//                q.push(v);
//            }
//        }
//    }
//    cout << endl;
//}
//
//void Print_DFS(int s, int f, GRAPH graph)
//{
//    for (int i = 0; i < graph.Nv; i++)
//    {
//        visited[i] = 0;
//        save[i] = -1;
//    }
//    DFS(graph, s);
//
//    if (visited[f] != 0)
//    {
//        int j = f;
//
//        while (j != s)
//        {
//            cout << j << "<---";
//            j = save[j];
//        }
//        cout << s << endl;
//    }
//    else cout << "Khong co dung di tu " << s << " toi " << f << endl;
//
//}

void BFS(GRAPH graph, int start) {
    queue<int> q;

    for (int i = 0; i < graph.Nv; i++) {
        visited[i] = false;
        save[i] = -1;
    }

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        cout << u << " ";
        for (int v = 0; v < graph.Nv; v++) {
            if (graph.adj[u][v] && !visited[v]) {
                visited[v] = true;
                save[v] = u; 
                q.push(v);
            }
        }
    }
    cout << endl;
}

void Print_BFS(int s, int f, GRAPH graph) {
    BFS(graph, s); 

    if (visited[f]) { 
        int j = f;
        vector<int> path;

        
        while (j != s) {
            path.push_back(j);
            j = save[j];
        }
        path.push_back(s);

        
        for (int i = path.size() - 1; i > 0; i--) {
            cout << path[i] << "<--";
        }
        cout << path[0] << endl;
    }
    else {
        cout << "Khong co duong di tu " << s << " toi " << f << endl;
    }
}


int main()
{
    GRAPH graph;
    Read_Graph("dothi.txt", graph);
    Print_Graph(graph);

    if (Check_Undirected_Graph(graph))
        cout << RED << "La do thi vo huong" << RESET << endl;
    else
        cout << BLUE << "La do thi co huong" << RESET << endl;

    cout << endl;

    Print_BFS(0, 7, graph);
}

// 8
// 0 1 0 0 0 1 0 0
// 1 0 1 1 0 0 0 0 
// 0 1 0 0 1 0 0 0 
// 0 0 1 0 0 0 0 0
// 1 0 0 0 0 0 1 0
// 0 0 0 0 0 1 0 1
// 0 0 0 0 0 0 1 0
