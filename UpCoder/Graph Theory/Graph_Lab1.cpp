#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <vector>

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

void Largest_Weight_Number(GRAPH graph) {
    int max_weight = -100;
    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            if (graph.adj[i][j] > max_weight && graph.adj[i][j] != 0)
                max_weight = graph.adj[i][j];
        }
    }
    cout << "Trong so lon nhat trong do thi: " << max_weight << endl;
}

void Calculate_Degree(GRAPH graph) {
    if (Check_Undirected_Graph(graph)) {
        for (int i = 0; i < graph.Nv; i++) {
            cout << "Bac cua dinh " << i + 1 << " la: " << graph.degree[i] << endl;
        }
        return;
    }

    else {
        for (int i = 0; i < graph.Nv; i++) {
            cout << "Dinh " << i + 1
                << ": Ban bac ra la : " << graph.out_Degree[i]
                << ", Ban bac vao la : " << graph.in_Degree[i]
                << endl;
        }
        return;
    }

}

void Largest_Degree(GRAPH& graph) {
    int max_degree = -100;
    int v = -1;
    vector<int> vec;

    if (Check_Undirected_Graph(graph)) {
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] > max_degree) {
                max_degree = graph.degree[i];
                v = i;
            }
        }

        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] == max_degree)
                vec.push_back(i);
        }
    }
    else {
        for (int i = 0; i < graph.Nv; i++) {
            int total_degree = graph.in_Degree[i] + graph.out_Degree[i];
            if (total_degree > max_degree) {
                max_degree = total_degree;
                v = i;
            }
        }

        for (int i = 0; i < graph.Nv; i++) {
            int total_degree = graph.in_Degree[i] + graph.out_Degree[i];
            if (total_degree == max_degree)
                vec.push_back(i);
        }
    }

    cout << "Dinh co bac lon nhat la: ";
    if (vec.size() == 0) cout << v + 1;
    else
        for (auto x : vec) cout << x + 1 << " ";
    cout << endl;
}

void Lowest_Degree(GRAPH& graph) {
    int min_degree = 100;
    int v = -1;
    vector<int> vec;

    if (Check_Undirected_Graph(graph)) {
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] < min_degree) {
                min_degree = graph.degree[i];
                v = i;
            }
        }

        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] == min_degree)
                vec.push_back(i);
        }
    }
    else {
        for (int i = 0; i < graph.Nv; i++) {
            int total_degree = graph.in_Degree[i] + graph.out_Degree[i];
            if (total_degree < min_degree) {
                min_degree = total_degree;
                v = i;
            }
        }

        for (int i = 0; i < graph.Nv; i++) {
            int total_degree = graph.in_Degree[i] + graph.out_Degree[i];
            if (total_degree == min_degree)
                vec.push_back(i);
        }
    }

    cout << "Dinh co bac nho nhat la: ";
    if (vec.size() == 0) cout << v + 1;
    else
        for (auto x : vec) cout << x + 1 << " ";
    cout << endl;
}


void Find_Even_Odd_Degree_Vertices(GRAPH graph) {
    if (Check_Undirected_Graph(graph)) {
        cout << "Cac dinh bac chan: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] % 2 == 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        cout << "Cac dinh bac le: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] % 2 != 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
    else {
        vector<int> in_Degree(graph.Nv, 0);
        vector<int> out_Degree(graph.Nv, 0);
        for (int i = 0; i < graph.Nv; i++) {
            for (int j = 0; j < graph.Nv; j++) {
                if (graph.adj[i][j] != 0) {
                    out_Degree[i]++;
                    in_Degree[j]++;
                }
            }
        }

        cout << "Cac dinh bac ra chan: ";

        for (int i = 0; i < graph.Nv; i++) {
            if (out_Degree[i] % 2 == 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        cout << "Cac dinh bac ra le: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (out_Degree[i] % 2 != 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        cout << "Cac dinh bac vao chan: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (in_Degree[i] % 2 == 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        cout << "Cac dinh bac vao le: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (in_Degree[i] % 2 != 0) {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
    }
}

bool Check_Pendant_Vertices(GRAPH graph) {
    for (int i = 0; i < graph.Nv; i++) {
        if (graph.degree[i] == 1) {
            return true;
        }
    }
    return false;
}

bool Check_Isolated_Vertices(GRAPH graph) {
    for (int i = 0; i < graph.Nv; i++) {
        if (graph.degree[i] == 0) {
            return true;
        }
    }
    return false;
}

void Find_Pendant_Isolated_Vertices(GRAPH graph) {
    if (Check_Pendant_Vertices(graph)) {
        cout << "Dinh treo: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] == 1) {
                cout << i + 1 << " ";
            }
        }
    }
    else cout << "Khong co dinh treo";

    cout << endl;

    if (Check_Isolated_Vertices(graph)) {
        cout << "Dinh co lap: ";
        for (int i = 0; i < graph.Nv; i++) {
            if (graph.degree[i] == 0) {
                cout << i + 1 << " ";
            }
        }
    }
    else cout << "Khong co dinh co lap";

    cout << endl;
}

int main() {
    GRAPH graph;
    Read_Graph("dothi.txt", graph);
    Print_Graph(graph);

    // Cau 1
    if (Check_Undirected_Graph(graph))
        cout << RED << "La do thi vo huong" << RESET << endl;
    else
        cout << BLUE << "La do thi co huong" << RESET << endl;

    cout << endl;
    // Cau 2
    cout << "So canh trong do thi : " << graph.Ne << endl;
    cout << endl;

    // Cau 3
    Largest_Weight_Number(graph);
    cout << endl;

    // Cau 4
    Calculate_Degree(graph);
    cout << endl;

    // Cau 5
    Largest_Degree(graph);
    Lowest_Degree(graph);

    cout << endl;

    Find_Even_Odd_Degree_Vertices(graph);
    cout << endl;

    // Cau 6
    Find_Pendant_Isolated_Vertices(graph);

    return 0;
}
