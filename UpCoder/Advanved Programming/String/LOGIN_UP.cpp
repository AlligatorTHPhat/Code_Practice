#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string str) {
    vector<char> tmp = {'u', 'p', 'c', 'o', 'd', 'e', 'r'};
    int index = 0;
    for (char c : str) {
        if (c == tmp[index]) {
            index++;
            if (index == 7) { // Nếu đã tìm thấy chuỗi con, trả về true ngay lập tức
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    string str; 
    getline(cin, str);
    cout << (check(str) ? "YES" : "NO");

    return 0;
}
