//#include <iostream>
//#include <iomanip>
//#include <string>
//#include <fstream>
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
//
//struct GRAPH {
//    int Nv, Ne;
//    int adj[MAX][MAX];
//    int degree[MAX];
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
//
//int visited_domain[MAX];
//int interconnected_domain;
//
//// DFS visit function to explore a connected component
//void Visit(GRAPH graph, int i, int interconnected_domain) {
//    visited_domain[i] = interconnected_domain;
//    for (int j = 0; j < graph.Nv; j++) {
//        if (visited_domain[j] == 0 && graph.adj[i][j] != 0) {
//            Visit(graph, j, interconnected_domain);
//        }
//    }
//}
//
//// Function to calculate the number of connected components
//void Consider_The_Connectivity_Of_Graph(GRAPH graph) {
//    interconnected_domain = 0;
//    fill(visited_domain, visited_domain + graph.Nv, 0);
//
//    for (int i = 0; i < graph.Nv; i++) {
//        if (visited_domain[i] == 0) {
//            interconnected_domain++;
//            Visit(graph, i, interconnected_domain);
//        }
//    }
//}
//
//// Function to print connected components
//void Print_Interconnected(GRAPH graph) {
//    cout << "So mien lien thong: " << interconnected_domain << endl;
//    for (int i = 1; i <= interconnected_domain; i++) {
//        cout << "Mien lien thong " << i << " gom cac dinh: ";
//        for (int j = 0; j < graph.Nv; j++) {
//            if (visited_domain[j] == i) {
//                cout << setw(4) << j;
//            }
//        }
//        cout << endl;
//    }
//}
//
//// Function to calculate edges required to connect all disconnected components
//void Edges_To_Connect_Graph(GRAPH graph) {
//    // Xét số miền liên thông và in ra số miền
//    Consider_The_Connectivity_Of_Graph(graph);
//
//    // Nếu số miền liên thông <= 1, đồ thị đã liên thông
//    if (interconnected_domain <= 1) {
//        cout << "Do thi da lien thong, khong can them canh nao." << endl;
//        return;
//    }
//
//    cout << "Can " << interconnected_domain - 1 << " canh de do thi lien thong." << endl;
//    cout << "Nhung canh can them la: " << endl;
//
//    // Duyệt qua các miền liên thông và thêm cạnh nối các miền khác nhau
//    int previous_vertex = -1;
//    for (int i = 0; i < graph.Nv; ++i) {
//        // Tìm một đỉnh thuộc mỗi miền liên thông
//        if (visited_domain[i] == 1) {
//            previous_vertex = i;
//            break;
//        }
//    }
//
//    // Nối các miền liên thông với nhau bằng cách chọn một đỉnh từ mỗi miền
//    for (int i = 2; i <= interconnected_domain; ++i) {
//        for (int j = 0; j < graph.Nv; ++j) {
//            if (visited_domain[j] == i) {
//                // Thêm cạnh giữa miền trước đó và miền hiện tại
//                cout << previous_vertex << " - " << j << endl;
//                previous_vertex = j;
//                break;
//            }
//        }
//    }
//}
//
//bool visited_DFS[MAX];  // Mảng bool để đánh dấu đỉnh đã duyệt trong DFS
//int save_DFS[MAX];      // Mảng để lưu lại các đỉnh theo thứ tự DFS
//
//void DFS(GRAPH graph, int i) {
//    visited_DFS[i] = true;
//    for (int j = 0; j < graph.Nv; j++) {
//        if (!visited_DFS[j] && graph.adj[i][j]) {
//            save_DFS[j] = i;
//            DFS(graph, j);
//        }
//    }
//}
//
//void Print_DFS(int s, int f, GRAPH graph) {
//    // Reset lại các giá trị trước khi duyệt DFS
//    fill(visited_DFS, visited_DFS + graph.Nv, false);
//    fill(save_DFS, save_DFS + graph.Nv, -1);
//
//    DFS(graph, s);
//
//    // Kiểm tra xem có đường từ đỉnh `s` đến `f` hay không
//    if (visited_DFS[f]) {
//        cout << "Duyet theo chieu sau : " << endl;
//
//        int j = f;
//
//        // In ngược đường đi từ `f` về `s`
//        while (j != s) {
//            cout << j << "<---";
//            j = save_DFS[j];
//        }
//        cout << s << endl;
//    }
//    else {
//        cout << "Khong co duong di tu " << s << " toi " << f << endl;
//    }
//}
//
//bool visited_BFS[MAX];   // Mảng bool để đánh dấu đỉnh đã duyệt trong BFS
//int save_BFS[MAX];       // Mảng để lưu lại các đỉnh theo thứ tự BFS
//vector<int> saving;      // Lưu lại các đỉnh theo thứ tự đã duyệt BFS
//
//void BFS(GRAPH& graph, int s) {
//    queue<int> q;  // Sử dụng hàng đợi chuẩn của C++
//    q.push(s);
//    visited_BFS[s] = true;
//
//    while (!q.empty()) {
//        int que = q.front();
//        q.pop();
//        saving.push_back(que);
//
//        for (int i = 0; i < graph.Nv; i++) {
//            if (graph.adj[que][i] && !visited_BFS[i]) {
//                q.push(i);
//                save_BFS[i] = que;
//                visited_BFS[i] = true;
//            }
//        }
//    }
//}
//
//void Print_BFS(int s, int f, GRAPH graph) {
//    BFS(graph, s);
//
//    if (!saving.empty()) {
//        cout << "Duyet theo chieu rong :" << endl;
//        for (int i = 0; i < saving.size(); i++)
//        {
//            cout << saving[i];
//            if (i != saving.size() - 1) cout << "<---";
//        }
//    }
//    else cout << "Khong co duong di tu " << s << " den " << f;
//}

//void Print_BFS(int s, int f, GRAPH graph) {
//    // Reset lại các giá trị trước khi duyệt BFS
//    fill(visited_BFS, visited_BFS + graph.Nv, false);
//    fill(save_BFS, save_BFS + graph.Nv, -1);
//    saving.clear();  // Xóa dữ liệu trước đó
//
//    BFS(graph, s);
//
//    if (visited_BFS[f]) {
//        cout << "Duyet theo chieu rong : " << endl;
//
//        int j = f;
//
//        // In ngược đường đi từ `f` về `s`
//        while (j != s) {
//            cout << j << "<---";
//            j = save_BFS[j];
//        }
//        cout << s << endl;
//    }
//    else {
//        cout << "Khong co duong di tu " << s << " den " << f << endl;
//    }
//}
//
//int main() {
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
//    // Yêu cầu 1: In các miền liên thông
//    Consider_The_Connectivity_Of_Graph(graph);
//    Print_Interconnected(graph);
//
//    cout << endl;
//
//    // Yêu cầu 2: DFS
//    Print_DFS(0, 7, graph);
//
//    //cout << endl;
//
//    // Yêu cầu 3: BFS
//    Print_BFS(0, 7, graph);
//
//    cout << endl;
//
//    //Yêu cầu 4
//    Edges_To_Connect_Graph(graph);
//}

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100;
struct GRAPH {
    int Nv, Ne;
    vector<vector<int>> adj; // Change to a 2D vector
    vector<int> degree;
    vector<int> in_Degree;
    vector<int> out_Degree;

    GRAPH() : Nv(0), Ne(0) {}

    void Init_Degrees() {
        in_Degree.resize(Nv, 0);
        out_Degree.resize(Nv, 0);
        degree.resize(Nv, 0);
    }
};

bool Check_Undirected_Graph(const GRAPH& graph) {
    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            if (graph.adj[i][j] != graph.adj[j][i])
                return false;
        }
    }
    return true;
}

void Read_Graph(const string& fn, GRAPH& graph) {
    ifstream file(fn);

    if (file.is_open()) {
        file >> graph.Nv;
        graph.adj.resize(graph.Nv, vector<int>(graph.Nv, 0));  // Resize vector

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

void Print_Graph(const GRAPH& graph, const string& filename) {
    ofstream outfile(filename);
    if (!outfile.is_open()) {
        outfile << "Khong mo duoc file " << filename << " de ghi!" << endl;
        return;
    }

    if (Check_Undirected_Graph(graph))
        outfile << "La do thi vo huong" << endl;
    else
        outfile << "La do thi co huong" << endl;

    outfile << "So dinh cua do thi : " << graph.Nv << endl;
    outfile << "Do thi : " << endl;
    for (int i = 0; i < graph.Nv; i++) {
        for (int j = 0; j < graph.Nv; j++) {
            outfile << setw(4) << graph.adj[i][j] << " ";
        }
        outfile << endl;
    }

    outfile << endl;

    outfile.close();
}

int visited_domain[MAX];
int interconnected_domain;

void Visit(GRAPH graph, int i, int interconnected_domain) {
    visited_domain[i] = interconnected_domain;
    for (int j = 0; j < graph.Nv; j++) {
        if (visited_domain[j] == 0 && graph.adj[i][j] != 0) {
            Visit(graph, j, interconnected_domain);
        }
    }
}

void Consider_The_Connectivity_Of_Graph(GRAPH graph) {
    interconnected_domain = 0;
    fill(visited_domain, visited_domain + graph.Nv, 0);

    for (int i = 0; i < graph.Nv; i++) {
        if (visited_domain[i] == 0) {
            interconnected_domain++;
            Visit(graph, i, interconnected_domain);
        }
    }
}

void Print_Interconnected(GRAPH graph, const string& filename) {
    ofstream outfile(filename, ios::app);  // Append mode
    if (!outfile.is_open()) {
        outfile << "Khong mo duoc file " << filename << " de ghi!" << endl;
        return;
    }

    outfile << "So mien lien thong: " << interconnected_domain << endl;
    for (int i = 1; i <= interconnected_domain; i++) {
        outfile << "Mien lien thong " << i << " gom cac dinh: ";
        for (int j = 0; j < graph.Nv; j++) {
            if (visited_domain[j] == i) {
                outfile << setw(4) << j;
            }
        }
        outfile << endl;
    }

    outfile << endl;

    outfile.close();
}

void Edges_To_Connect_Graph(GRAPH graph, const string& filename) {
    Consider_The_Connectivity_Of_Graph(graph);

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        outfile << "Khong mo duoc file " << filename << " de ghi!" << endl;
        return;
    }

    if (interconnected_domain <= 1) {
        outfile << "Do thi da lien thong, khong can them canh nao." << endl;
        outfile.close();
        return;
    }

    
    outfile << "Can " << interconnected_domain - 1 << " canh de do thi lien thong." << endl;
    outfile << "Nhung canh can them la: " << endl;

    int previous_vertex = -1;
    for (int i = 0; i < graph.Nv; ++i) {
        if (visited_domain[i] == 1) {
            previous_vertex = i;
            break;
        }
    }

    for (int i = 2; i <= interconnected_domain; ++i) {
        for (int j = 0; j < graph.Nv; ++j) {
            if (visited_domain[j] == i) {
                outfile << previous_vertex << " - " << j << endl;
                outfile << previous_vertex << " - " << j << endl;
                previous_vertex = j;
                break;
            }
        }
    }

    outfile << endl;

    outfile.close();
}

bool visited_DFS[100];  // Assuming max size is 100
int save_DFS[100];      // Array to store DFS order

void DFS(GRAPH graph, int i) {
    visited_DFS[i] = true;
    for (int j = 0; j < graph.Nv; j++) {
        if (!visited_DFS[j] && graph.adj[i][j]) {
            save_DFS[j] = i;
            DFS(graph, j);
        }
    }
}

void Print_DFS(int s, int f, GRAPH graph, const string& filename) {
    fill(visited_DFS, visited_DFS + graph.Nv, false);
    fill(save_DFS, save_DFS + graph.Nv, -1);

    DFS(graph, s);

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        outfile << "Khong mo duoc file " << filename << " de ghi!" << endl;
        return;
    }

    if (visited_DFS[f]) {
        outfile << "Duyet theo chieu sau: " << endl;

        int j = f;

        while (j != s) {
            outfile << j << "<---";
            j = save_DFS[j];
        }
        outfile << s << endl;
    }
    else {
        outfile << "Khong co duong di tu " << s << " toi " << f << endl;
    }

    outfile << endl;

    outfile.close();
}

bool visited_BFS[100];   // Assuming max size is 100
int save_BFS[100];
vector<int> saving;

void BFS(GRAPH& graph, int s) {
    queue<int> q;
    q.push(s);
    visited_BFS[s] = true;

    while (!q.empty()) {
        int que = q.front();
        q.pop();
        saving.push_back(que);

        for (int i = 0; i < graph.Nv; i++) {
            if (graph.adj[que][i] && !visited_BFS[i]) {
                q.push(i);
                save_BFS[i] = que;
                visited_BFS[i] = true;
            }
        }
    }
}

void Print_BFS(int s, int f, GRAPH graph, const string& filename) {
    BFS(graph, s);

    ofstream outfile(filename, ios::app);
    if (!outfile.is_open()) {
        outfile << "Khong mo duoc file " << filename << " de ghi!" << endl;
        return;
    }

    if (!saving.empty()) {
        outfile << "Duyet theo chieu rong: " << endl;

        for (int i = 0; i < saving.size(); i++) {
            outfile << saving[i];
            if (i != saving.size() - 1) {
                outfile << "<---";
            }
        }
        outfile << endl;
    }
    else {
        outfile << "Khong co duong di tu " << s << " den " << f << endl;
    }

    outfile << endl;

    outfile.close();
}

//void Print_BFS(int s, int f, GRAPH graph, const string& filename) {
//    // Reset lại các giá trị trước khi duyệt BFS
//    fill(visited_BFS, visited_BFS + graph.Nv, false);
//    fill(save_BFS, save_BFS + graph.Nv, -1);
//    saving.clear();  // Xóa dữ liệu trước đó
//
//    BFS(graph, s);
//
//    ofstream outfile(filename, ios::app);
//
//    if (visited_BFS[f]) {
//        outfile << "Duyet theo chieu rong : " << endl;
//
//        int j = f;
//
//        // In ngược đường đi từ `f` về `s`
//        while (j != s) {
//            outfile << j << "<---";
//            j = save_BFS[j];
//        }
//        outfile << s << endl;
//    }
//    else {
//        outfile << "Khong co duong di tu " << s << " den " << f << endl;
//    }
//}

int main() {
    GRAPH graph;
    Read_Graph("dothi.txt", graph);
    Print_Graph(graph, "output.txt");

    Consider_The_Connectivity_Of_Graph(graph);
    Print_Interconnected(graph, "output.txt");

    Edges_To_Connect_Graph(graph, "output.txt");
    Print_DFS(0, 4, graph, "output.txt");
    Print_BFS(0, 4, graph, "output.txt");

    return 0;
}

