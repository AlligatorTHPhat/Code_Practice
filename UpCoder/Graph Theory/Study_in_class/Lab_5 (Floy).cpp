#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int Max = 100;
const int INF = 100; 

int x, y;

struct Graph {
    int sodinh;  
    int a[Max][Max];  
};

int L[Max][Max];  
int P[Max][Max];  

void readgraph(Graph& g, string fn) {
    ifstream f;
    f.open(fn);
    if (f.is_open()) {
        f >> g.sodinh >> x >> y; 
        for (int i = 0; i < g.sodinh; i++) {
            for (int j = 0; j < g.sodinh; j++) {
                f >> g.a[i][j]; 
                if (g.a[i][j] == 0 && i != j) {
                    g.a[i][j] = INF;
                }
            }
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file";
    }
}

void Floyd(Graph g) {
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            P[i][j] = i;  
            L[i][j] = g.a[i][j];  
        }
    }

    for (int k = 0; k < g.sodinh; k++) {
        for (int i = 0; i < g.sodinh; i++) {
            if (L[i][k] != INF) {  
                for (int j = 0; j < g.sodinh; j++) {
                    if (L[k][j] != INF) {  
                        if (L[i][j] > L[i][k] + L[k][j]) {
                            L[i][j] = L[i][k] + L[k][j];  
                            P[i][j] = P[k][j]; 
                        }
                    }
                }
            }
        }
    }
}

void printFloyd(Graph g, int x, int y, string fn) {
    ofstream f(fn);  
    if (f.is_open()) {
        if (L[x][y] == INF) { 
            f << "Khong co duong di tu " << x << " den " << y << "\n";
        }
        else {
            int i = y;
            f << "Di tu " << x << " den " << y << ": ";
            while (i != x) {
                f << i << " <-- ";  
                i = P[x][i];
            }
            f << x << "\n";  
            f << "Trong so: " << L[x][y] << "\n\n";  
        }
        f.close();
    }
    else {
        cout << "Khong mo duoc file\n";
    }
}

void print_graph(string fn, Graph& graph) {
    ofstream os(fn);  
    if (os.is_open()) {
        os << "\nMa tran trong so cua do thi:\n";
        for (int i = 0; i < graph.sodinh; i++) {
            for (int j = 0; j < graph.sodinh; j++) {
                if (graph.a[i][j] == INF)
                    os << setw(5) << "INF"; 
                else
                    os << setw(5) << graph.a[i][j];  
            }
            os << "\n";
        }
        os.close();
    }
    else {
        cout << "Khong mo duoc file!" << endl;
    }
}

int main() {
    Graph g;
    readgraph(g, "input.txt");  
    Floyd(g);  

    printFloyd(g, x, y, "output.txt");

    //print_graph("output.txt", g);

    return 0;
}
