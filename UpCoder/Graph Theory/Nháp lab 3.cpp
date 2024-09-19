//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <fstream>
//#include <limits>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//#define RESET   "\033[0m"
//#define RED     "\033[31m"
//#define BLUE    "\033[34m"
//
//const int MAX = 100;
//int save[MAX];
//
//struct GRAPH {
//    int Nv, Ne;
//    int adj[MAX][MAX];
//    int degree[MAX];
//
//    bool visited[MAX];
//
//    vector<int> in_Degree;
//    vector<int> out_Degree;
//
//    GRAPH() : Nv(0), Ne(0), in_Degree(0), out_Degree(0) {
//        for (int i = 0; i < MAX; ++i) {
//            degree[i] = 0;
//            for (int j = 0; j < MAX; ++j) {
//                adj[i][j] = 0;
//            }
//        }
//    }
//
//    void Init_Degrees() {
//        in_Degree.resize(Nv, 0);
//        out_Degree.resize(Nv, 0);
//    }
//};
//
//bool Check_Undirected_Graph(GRAPH graph) {
//    for (int i = 0; i < graph.Nv; i++) {
//        for (int j = 0; j < graph.Nv; j++) {
//            if (graph.adj[i][j] != graph.adj[j][i])
//                return false;
//        }
//    }
//    return true;
//}
//
//void Read_Graph(string fn, GRAPH& graph) {
//    ifstream file(fn);
//
//    if (file.is_open()) {
//        file >> graph.Nv;
//
//        for (int i = 0; i < graph.Nv; i++) {
//            for (int j = 0; j < graph.Nv; j++) {
//                file >> graph.adj[i][j];
//            }
//        }
//
//        graph.Init_Degrees();
//
//        graph.Ne = 0;
//
//        if (Check_Undirected_Graph(graph)) {
//            for (int i = 0; i < graph.Nv; i++) {
//                for (int j = 0; j < graph.Nv; j++) {
//                    if (graph.adj[i][j] != 0) {
//                        graph.Ne++;
//                        graph.degree[i]++;
//                    }
//                }
//            }
//            graph.Ne /= 2;
//        }
//        else {
//            for (int i = 0; i < graph.Nv; i++) {
//                for (int j = 0; j < graph.Nv; j++) {
//                    if (graph.adj[i][j] != 0) {
//                        graph.Ne++;
//                        graph.out_Degree[i]++;
//                        graph.in_Degree[j]++;
//                    }
//                }
//            }
//        }
//        file.close();
//    }
//    else {
//        cout << "Khong doc duoc file!" << endl;
//    }
//}
//
//void Print_Graph(GRAPH graph) {
//    cout << "So dinh cua do thi : " << graph.Nv << endl;
//    cout << "Do thi : " << endl;
//    for (int i = 0; i < graph.Nv; i++) {
//        for (int j = 0; j < graph.Nv; j++) {
//            cout << setw(4) << graph.adj[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void DFS(GRAPH graph, int i)
//{
//    graph.visited[i] = true;
//    for (int j = 0; j < graph.Nv; j++)
//    {
//        if (graph.visited[j] == false && graph.adj[i][j])
//        {
//            save[j] = i;
//            DFS(graph, j);
//        }
//    }
//}
//
////struct QUEUE
////{
////    int size;
////    int values[MAX];
////};
////
////void init(QUEUE& q)
////{
////    q.size = 0;
////}
////
////bool Push(int& k, QUEUE& q)
////{
////    if (q.size + 1 > MAX) return false;
////    q.values[q.size] = k;
////    q.size++;
////    return true;
////}
////
////bool Empty(QUEUE& q)
////{
////    return q.size == 0;
////}
////
////bool Pop(int& v, QUEUE& q)
////{
////    if (Empty(q)) return false;
////    v = q.values[0];
////    for (int i = 0; i < q.size - 1; i++)
////    {
////        q.values[i] = q.values[i + 1];
////    }
////    q.size--;
////    return true;
////}
//
//struct QUEUE {
//    int data[MAX]; 
//    int Front_Index;
//    int Rear_Index;
//    
//    void Init() {
//        this->Front_Index = 0;
//        this->Rear_Index = -1;
//        return;
//    }
//
//    bool Empty() {
//        return this->Front_Index > this->Rear_Index;
//    }
//
//    bool Full() {
//        return this->Rear_Index == 99;
//    }
//
//    void Push(int value) {
//        if (!this->Full()) {
//            this->data[++this->Rear_Index] = value;
//        }
//        return;
//    }
//
//    int Front() {
//        if (!this->Empty()) {
//            return this->data[this->Front_Index];
//        }
//        return -1; 
//    }
//
//    void Pop() {
//        if (!this->Empty()) {
//            this->Front_Index++;
//        }
//        return;
//    }
//};
//
//void BFS(GRAPH& graph, int s)
//{
//    QUEUE q;
//    q.Init();
//    q.Push(s);
//
//    graph.visited[s] = true;
//
//    while (!q.Empty())
//    {
//        int que = q.Front();
//        q.Pop();
//
//        cout << que << " ";
//
//        for (auto i : adj[q])
//        {
//            if (!graph.visited[i])
//            {
//                q.Push(i);
//                save[i] = s;
//                graph.visited[i] = true;
//            }
//        }
//
//    }
//}
//
////void Print_BFS(int s, int f, GRAPH graph)
////{
////    for (int i = 0; i < graph.Nv; i++)
////    {
////        graph.visited[i] = 0;
////        save[i] = -1;
////    }
////
////    BFS(graph, s);
////
////    if (graph.visited[f] != 0)
////    {
////        int j = f;
////
////        while (j != s)
////        {
////            cout << j << "<---";
////            j = save[j];
////        }
////        cout << s << endl;
////    }
////    else cout << "Khong co dung di tu " << s << " toi " << f << endl;
////
////}
//
//int main()
//{
//    GRAPH graph;
//    Read_Graph("dothi.txt", graph);
//    Print_Graph(graph);
//
//    if (Check_Undirected_Graph(graph))
//        cout << RED << "La do thi vo huong" << RESET << endl;
//    else
//        cout << BLUE << "La do thi co huong" << RESET << endl;
//
//    cout << endl;
//
//    BFS(graph, 0);
//
//    //Print_BFS(0, 7, graph);
//}
//
////8
////
////0 1 0 0 0 1 0 0
////1 0 1 1 0 0 0 0
////0 1 0 0 1 0 0 0
////0 1 0 0 0 0 0 0
////0 0 1 0 0 0 0 0
////1 0 0 0 0 0 1 0
////0 0 0 0 0 1 0 1
////0 0 0 0 0 0 1 0



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
vector<int>saving;

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
            visited[i] = false;
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

struct QUEUE {
    int data[MAX];
    int Front_Index;
    int Rear_Index;

    void Init() {
        this->Front_Index = 0;
        this->Rear_Index = -1;
        return;
    }

    bool Empty() {
        return this->Front_Index > this->Rear_Index;
    }

    bool Full() {
        return this->Rear_Index == 99;
    }

    void Push(int value) {
        if (!this->Full()) {
            this->data[++this->Rear_Index] = value;
        }
        return;
    }

    int Front() {
        if (!this->Empty()) {
            return this->data[this->Front_Index];
        }
        return -1;
    }

    void Pop() {
        if (!this->Empty()) {
            this->Front_Index++;
        }
        return;
    }
};

void BFS(GRAPH& graph, int s) {
    QUEUE q;
    q.Init();
    q.Push(s);

    graph.visited[s] = true;

    while (!q.Empty()) {
        int que = q.Front();
        q.Pop();


        cout << que << " ";

        saving.push_back(que);

        // Duyệt qua các đỉnh kề với đỉnh hiện tại (sử dụng ma trận kề)
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.adj[que][i] && !graph.visited[i]) {
                q.Push(i);
                save[i] = que;
                graph.visited[i] = true;
            }
        }
    }
    cout << endl;
}

void Print_BFS(int s, int f, GRAPH graph) {
    BFS(graph, s);

    if (!saving.empty()) {
        for (int i = 0; i < saving.size(); i++)
        {
            cout << saving[i];
            if (i != saving.size() - 1) cout << "<---";
        }
    }
    else cout << "Khong co duong di tu " << s << " den " << f;
}

//void Print_BFS(int s, int f, GRAPH graph)
//{
//    for (int i = 0; i < graph.Nv; i++)
//    {
//        graph.visited[i] = 0;
//        save[i] = -1;
//    }
//
//    BFS(graph, s);
//
//    if (graph.visited[f] != 0)
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

int main() {
    GRAPH graph;
    Read_Graph("dothi.txt", graph);
    Print_Graph(graph);

    if (Check_Undirected_Graph(graph))
        cout << RED << "La do thi vo huong" << RESET << endl;
    else
        cout << BLUE << "La do thi co huong" << RESET << endl;

    cout << endl;

    Print_BFS(0, 7, graph);

    return 0;
}
