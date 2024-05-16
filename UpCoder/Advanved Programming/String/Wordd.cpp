#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int split_string(string str) {
	vector <string>vec;
	
	str[0] = tolower(str[0]);
	int i = 0; // Chỉ số để duyệt qua chuỗi
	int check = 0; // Chỉ số bắt đầu của một chuỗi con có các ký tự liên tiếp giống nhau

	// Vòng lặp duyệt qua chuỗi
	while (i < str.size()) {
		// Kiểm tra nếu ký tự hiện tại giống với ký tự tiếp theo
		if (str[i] == str[i + 1]) {

			// Nếu chúng giống nhau, trích xuất chuỗi con và thêm vào vector
			vec.push_back(str.substr(check, i - check + 1)); // Thêm chuỗi con vào vector

			// Bỏ qua tất cả các ký tự liên tiếp giống nhau
			while (str[i] == str[i + 1]) {
				++i; // Di chuyển đến ký tự tiếp theo
				if (i + 1 >= str.size()) // Kiểm tra nếu đã đến cuối chuỗi
					return vec.size(); // Trả về kích thước của vector nếu đã đến cuối chuỗi
			}
			check = i + 1; // Cập nhật chỉ số bắt đầu của chuỗi con tiếp theo
		}
		++i; // Di chuyển đến ký tự tiếp theo
	}
	// Loại bỏ các chuỗi con trùng lặp trong vector

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	// Trả về kích thước của vector cộng thêm một
	return vec.size() + 1;
}

int main() {
	string str;
	getline(cin, str);

	cout << split_string(str);
}
