#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int start, end;
const int MAX = 100;

struct Graph
{
    int Nv, Ne = 0;
    vector<int> degree;
    vector<vector<int>> adj;

    void init_degree()
    {
        degree.resize(Nv, 0);
        adj.resize(Nv, vector<int>(Nv, 0));
    }
};

struct Queue
{
    vector<int> data;
    int Front_index, Rear_index;
};

void init(Queue& q)
{
    q.Front_index = 0;
    q.Rear_index = -1;
}

bool Empty(Queue& q)
{
    return q.Front_index > q.Rear_index;
}

void Push(int value, Queue& q)
{
    q.data.push_back(value);
    q.Rear_index++;
}

int Front(Queue& q)
{
    if (!Empty(q))
        return q.data[q.Front_index];
    return -1;
}

void Pop(Queue& q)
{
    if (!Empty(q))
        q.Front_index++;
}

void Read_Graph(string fn, Graph& graph)
{
    ifstream ifile(fn);

    if (!ifile.is_open())
    {
        cout << "Khong doc duoc file!" << endl;
        return;
    }
    ifile >> graph.Nv >> start;

    graph.init_degree();

    for (int i = 0; i < graph.Nv; i++)
    {
        for (int j = 0; j < graph.Nv; j++)
        {
            ifile >> graph.adj[i][j];
        }
    }

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

void BFS(Graph& graph, int s, vector<int>& saving)
{
    vector<bool> visited(graph.Nv, false);  

    Queue q;
    init(q);
    Push(s, q);
    visited[s] = true;

    while (!Empty(q))
    {
        int que = Front(q);
        Pop(q);
        saving.push_back(que);  

        for (int i = 0; i < graph.Nv; i++)
        {
            if (!visited[i] && graph.adj[que][i] != 0)
            {
                Push(i, q);
                visited[i] = true;
            }
        }
    }
}

void Print_BFS(int start, ofstream& ofile, Graph& graph)
{
    vector<int> saving;  

    BFS(graph, start, saving);

    if (!saving.empty())
    {
        ofile << "BFS : ";
        for (int i = 0; i < saving.size(); i++)
        {
            ofile << saving[i];
            if (i != saving.size() - 1)
            {
                ofile << " <-- ";
            }
        }
        ofile << endl;
    }
    else ofile << "Khong co duong di" << endl;
}

void Print_Graph(string fn, Graph& graph)
{
    ofstream ofile(fn);

    if (!ofile.is_open())
    {
        cout << "Khong ghi duoc file!" << endl;
        return;
    }

    ofile << "So dinh trong do thi la: " << graph.Nv << endl;
    ofile << "Do thi: " << endl;

    for (int i = 0; i < graph.Nv; i++)
    {
        for (int j = 0; j < graph.Nv; j++)
        {
            ofile << setw(4) << graph.adj[i][j] << " ";
        }
        ofile << endl;
    }

    Print_BFS(start, ofile, graph);

    ofile.close();
}

int main()
{
    Graph graph;

    Read_Graph("dothi.txt", graph);

    Print_Graph("output.txt", graph);

    return 0;
}
