#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm đệ quy để tạo tất cả các chuỗi k-phân có độ dài n
void generateKaryStrings(int k, int n, vector<string>& result, string prefix = "") {
    // Nếu độ dài chuỗi là 0, thêm chuỗi đã tạo vào vector kết quả
    if (n == 0) {
        result.push_back(prefix);
    } else {
        // Duyệt qua tất cả các chữ số từ 1 đến k
        for (int i = 1; i <= k; ++i) {
            // Gọi đệ quy để tạo các chuỗi con có độ dài nhỏ hơn
            generateKaryStrings(k, n - 1, result, prefix + to_string(i));
        }
    }
}

int main() {
    // Nhập số chữ số (k) và độ dài chuỗi (n)
    int k, n;
    cin >> k >> n;

    // Vector để lưu trữ các chuỗi k-phân được tạo
    vector<string> result;

    // Gọi hàm để tạo các chuỗi k-phân
    generateKaryStrings(k, n, result);

    // In số lượng chuỗi k-phân được tạo
    cout << result.size() << endl;

    // In tất cả các chuỗi k-phân theo thứ tự từ điển
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}
