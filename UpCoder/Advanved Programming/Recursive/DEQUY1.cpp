#include <iostream>
#include <vector>
#include <string>

// Hàm đệ quy để tạo tất cả các chuỗi k-phân có độ dài n
void generateKaryStrings(int k, int n, std::vector<std::string>& result, std::string prefix = "") {
    // Nếu độ dài chuỗi là 0, thêm chuỗi đã tạo vào vector kết quả
    if (n == 0) {
        result.push_back(prefix);
    }
    else {
        // Duyệt qua tất cả các chữ số từ 1 đến k
        for (int i = 1; i <= k; ++i) {
            // Gọi đệ quy để tạo các chuỗi con có độ dài nhỏ hơn
            generateKaryStrings(k, n - 1, result, prefix + std::to_string(i));
        }
    }
}

int main() {
    // Nhập số chữ số (k) và độ dài chuỗi (n)
    int k, n;
    std::cin >> k >> n;

    // Vector để lưu trữ các chuỗi k-phân được tạo
    std::vector<std::string> result;

    // Gọi hàm để tạo các chuỗi k-phân
    generateKaryStrings(k, n, result);

    // In số lượng chuỗi k-phân được tạo
    std::cout << result.size() << std::endl;

    // In tất cả các chuỗi k-phân theo thứ tự từ điển
    for (const std::string& str : result) {
        std::cout << str << std::endl;
    }

    return 0;
}
