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

int visited[MAX];
int interconnected_domain;

void Visit(GRAPH graph, int i, int interconnected_domain) {
    visited[i] = interconnected_domain;
    for (int j = 0; j < graph.Nv; j++) {
        if (visited[j] == 0 && graph.adj[i][j] != 0) {
            Visit(graph, j, interconnected_domain);
        }
    }
}

void Visit_Queue(GRAPH graph, int i, int domain) {
    queue<int> q;
    q.push(i);
    visited[i] = domain;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int j = 0; j < graph.Nv; j++) {
            if (visited[j] == 0 && graph.adj[current][j] != 0) {
                visited[j] = domain;
                q.push(j);
            }
        }
    }
}

void Consider_The_Connectivity_Of_Graph(GRAPH graph) {
    interconnected_domain = 0;
    fill(visited, visited + graph.Nv, 0); // Reset the visited array to 0

    for (int i = 0; i < graph.Nv; i++) {
        if (visited[i] == 0) {
            interconnected_domain++;
            Visit(graph, i, interconnected_domain);
        }
    }
}

void Print_Interconnected(GRAPH graph) {
    cout << "So mien lien thong: " << interconnected_domain << endl;
    for (int i = 1; i <= interconnected_domain; i++) {
        cout << "Mien lien thong " << i << " gom cac dinh: ";
        for (int j = 0; j < graph.Nv; j++) {
            if (visited[j] == i) {
                cout << setw(4) << j;
            }
        }
        cout << endl;
    }
}

int main() {
    GRAPH graph;
    Read_Graph("dothi.txt", graph);
    Print_Graph(graph);

    if (Check_Undirected_Graph(graph))
        cout << RED << "La do thi vo huong" << RESET << endl;
    else
        cout << BLUE << "La do thi co huong" << RESET << endl;

    cout << endl;

    Consider_The_Connectivity_Of_Graph(graph);

    Print_Interconnected(graph);
}
 //7
 //0 1 0 0 0 0 1
 //1 0 1 0 0 0 0
 //0 1 0 0 0 0 1
 //0 0 0 0 1 0 0  
 //0 0 0 1 0 1 0
 //0 0 0 0 1 0 0 
 //1 0 1 0 0 0 0 
