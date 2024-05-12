#include <iostream>
#include <vector>

using namespace std;

// Hàm tính diện tích của hình chữ nhật
int maxRectangleArea(vector<vector<int>>& matrix, int n, int m) {
    // Khởi tạo một vector 1D để lưu chiều rộng của hình chữ nhật tại mỗi hàng
    vector<int> height(m, 0);
    int maxArea = 0;

    // Quét hàng (row-wise) từ hàng đầu tiên đến hàng cuối cùng
    for (int i = 0; i < n; ++i) {
        // Cập nhật chiều rộng của hình chữ nhật tại hàng i
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                height[j] = 0; // Nếu có ký tự 0 thì reset chiều rộng của cột j
            } else {
                height[j]++; // Nếu có ký tự 1 thì tăng chiều rộng của cột j
            }
        }

        // Tính diện tích tối đa của hình chữ nhật tại hàng i
        int area = 0;
        for (int j = 0; j < m; ++j) {
            int minHeight = height[j];
            // Tính chiều rộng của hình chữ nhật có thể mở rộng tới cột j
            for (int k = j; k < m; ++k) {
                if (height[k] == 0) {
                    break; // Nếu gặp cột có chiều rộng bằng 0 thì thoát
                }
                minHeight = min(minHeight, height[k]);
                area = max(area, (k - j + 1) * minHeight);
            }
        }
        maxArea = max(maxArea, area); // So sánh và cập nhật diện tích lớn nhất
    }
    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;

    // Nhập ma trận
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Tìm diện tích lớn nhất của hình chữ nhật
    int maxArea = maxRectangleArea(matrix, n, m);
    cout << maxArea << endl;

    return 0;
}
