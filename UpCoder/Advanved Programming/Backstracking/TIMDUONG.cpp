#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Định nghĩa một cặp đỉnh kề và trọng số của cạnh
typedef pair<int, int> pii;

// Hàm tìm đường đi ngắn nhất từ đỉnh S đến đỉnh T
int shortest_path(vector<vector<pii>>& graph, int S, int T) {
    int n = graph.size();
    // Khởi tạo mảng dist lưu độ dài ngắn nhất từ đỉnh S đến mỗi đỉnh khác
    vector<int> dist(n, INT_MAX);
    // Queue để duyệt các đỉnh theo BFS
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Đặt độ dài từ đỉnh S đến chính nó là 0 và thêm nó vào hàng đợi
    dist[S] = 0;
    pq.push({0, S});

    // Duyệt các đỉnh trong hàng đợi
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();

        // Dừng nếu đến đỉnh T
        if (u == T) break;

        // Duyệt qua tất cả các đỉnh kề của u
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            // Nếu có đường đi ngắn hơn từ S đến v thông qua u
            if (dist[v] > dist[u] + weight) {
                // Cập nhật độ dài đường đi ngắn nhất từ S đến v
                dist[v] = dist[u] + weight;
                // Thêm v vào hàng đợi để xem xét
                pq.push({dist[v], v});
            }
        }
    }
    // Trả về độ dài đường đi ngắn nhất từ S đến T
    return dist[T];
}

int main() {
    int nV, nE, S, T;
    cin >> nV >> nE >> S >> T;

    // Khởi tạo đồ thị với nV đỉnh
    vector<vector<pii>> graph(nV + 1);

    // Nhập cạnh của đồ thị
    for (int i = 0; i < nE; ++i) {
        int a, b;
        cin >> a >> b;
        // Thêm cạnh từ a đến b và từ b đến a vì đồ thị vô hướng
        graph[a].push_back({b, 1});
        graph[b].push_back({a, 1});
    }

    // Tìm đường đi ngắn nhất từ S đến T
    int shortest = shortest_path(graph, S, T);
    cout << shortest << endl;

    return 0;
}

