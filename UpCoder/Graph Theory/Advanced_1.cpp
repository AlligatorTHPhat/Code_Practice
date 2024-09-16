#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Edge {
    int i;
    int j;
    int w;
};

void read_GRAPH(string filename, vector<Edge>& E, int& sodinh) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Khong duoc mo file!!!" << endl;
        return;
    }

    Edge e;
    sodinh = 0; 
    while (file >> e.i >> e.j >> e.w) {
        E.push_back(e);
        sodinh = max({ sodinh, e.i, e.j });
    }

    file.close();
}

void print_Graph(vector<Edge>& E) {
    for (const auto& e : E) {
        cout << e.i << " "  << e.j << " " << e.w << endl;
    }
}

int dem_So_Canh(vector<Edge>& edges) {
    return edges.size();
}

void Tim_Bac_Co_Dinh_Lon_Nhat(vector<Edge>& E, int sodinh) {
    unordered_map<int, int> bac; 

    for (const auto& e : E) {
        bac[e.i]++;
        bac[e.j]++;
    }

    int baclonI = 0;
    int dinhbacI = -1;
    for (auto& pair : bac) {
        if (pair.second > baclonI) {
            baclonI = pair.second;
            dinhbacI = pair.first;
        }
    }

    cout << "Dinh co bac lon nhat la: " << dinhbacI << endl;
}

int main() {
    vector<Edge> E;
    int num_vertices;

    read_GRAPH("dothi.txt", E, num_vertices);

    print_Graph(E);

    cout << "So canh: " << dem_So_Canh(E) << endl;

    Tim_Bac_Co_Dinh_Lon_Nhat(E, num_vertices);

    return 0;
}
