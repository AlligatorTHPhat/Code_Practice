#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

struct GRAPH
{
    int Nv, Ne;
    vector<vector<pair<int, int>>> adj; // adj[u] chứa các cặp {v, w}, trong đó v là đỉnh kề với u và w là trọng số

    GRAPH(int n) : Nv(n) {
        adj.resize(Nv);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // Nếu là đồ thị vô hướng
    }
};

vector<int> Dijkstra(const GRAPH& graph, int src) {
    vector<int> dist(graph.Nv, INF); // Khoảng cách từ src đến các đỉnh
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {khoảng cách, đỉnh}

    dist[src] = 0;
    pq.push({ 0, src });

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Nếu khoảng cách hiện tại lớn hơn khoảng cách đã lưu, bỏ qua
        if (d > dist[u])
            continue;

        // Duyệt các đỉnh kề
        for (auto edge : graph.adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Nếu tìm thấy khoảng cách ngắn hơn
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist; // Trả về khoảng cách từ src đến các đỉnh khác
}

void Print_Distances(const vector<int>& dist) {
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == INF)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, e;
    cout << "Nhap so dinh va so canh: ";
    cin >> n >> e;

    GRAPH graph(n);

    cout << "Nhap cac canh theo dang (u v w) voi u, v la dinh va w la trong so:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int src;
    cout << "Nhap dinh bat dau: ";
    cin >> src;

    vector<int> dist = Dijkstra(graph, src);
    cout << "Khoang cach tu dinh " << src << " den cac dinh khac:" << endl;
    Print_Distances(dist);

    return 0;
}
