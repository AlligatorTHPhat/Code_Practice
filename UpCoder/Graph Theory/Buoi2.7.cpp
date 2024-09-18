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
int save[MAX];

struct GRAPH {
    int Nv, Ne;
    int adj[MAX][MAX];
    int degree[MAX];

    bool visited[MAX];

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

void DFS(GRAPH graph, int i)
{
    graph.visited[i] = true;
    for (int j = 0; j < graph.Nv; j++)
    {
        if (graph.visited[j] == false && graph.adj[i][j])
        {
            save[j] = i;
            DFS(graph, j);
        }
    }
}

struct QUEUE
{
    int size;
    int values[MAX];
};

void init(QUEUE& q)
{
    q.size = 0;
}

bool Push(int &k, QUEUE& q)
{
    if (q.size + 1 > MAX) return false;
    q.values[q.size] = k;
    q.size++;
    return true;
}

bool Empty(QUEUE& q)
{
    return q.size == 0;
}

bool Pop(int& v, QUEUE& q)
{
    if (Empty(q)) return false;
    v = q.values[0];
    for (int i = 0; i < q.size - 1; i++)
    {
        q.values[i] = q.values[i + 1];
    }
    q.size--;
    return true;
}

void BFS(GRAPH& graph, int s)
{
    QUEUE q;
    init(q);
    Push(s, q);

    while (!Empty(q))
    {
        Pop(s, q);
        graph.visited[s] = 1;

        for (int i = 0; i < graph.Nv; i++)
        {
            if (graph.visited[i] == 0 && graph.adj[s][i] != 0)
            {
                Push(i, q);
                save[i] = s;
            }
        }

    }
}

void Print_BFS(int s, int f, GRAPH graph)
{
    for (int i = 0; i < graph.Nv; i++)
    {
        graph.visited[i] = 0;
        save[i] = -1;
    }

    BFS(graph, s);
    
    if (graph.visited[f] != 0)
    {
        int j = f;

        while (j != s)
        {
            cout << j << "<---";
            j = save[j];
        }
        cout << s << endl;
    }
    else cout << "Khong co dung di tu " << s << " toi " << f << endl;
       
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

    Print_BFS(0,7,graph);
}
