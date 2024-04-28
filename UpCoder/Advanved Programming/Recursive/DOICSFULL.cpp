#include <iostream>
#include <stack>
#include <string>

using namespace std;

void chuyenCoSo(long soHe10, int heCoSoMoi);

int main() {
	long soHe10; cin >> soHe10;
	int heCoSoMoi; cin >> heCoSoMoi;
	chuyenCoSo(soHe10, heCoSoMoi);

	return 0;
}

void chuyenCoSo(long soHe10, int heCoSoMoi) {

	stack<string> stk;
	string hecoso16 = "0123456789ABCDEF";
	switch (heCoSoMoi) {
	case 0:
		while (soHe10 > 0) {
			stk.push(to_string(soHe10 % 2));
			soHe10 /= 2;
		}
		break;
	case 1:
		while (soHe10 > 0) {
			stk.push(to_string(soHe10 % 8));
			soHe10 /= 8;
		}
		break;
	case 2:
		while (soHe10 > 0) {
			stk.push(string(1, hecoso16[soHe10 % 16]));
			soHe10 /= 16;
		}
		break;
	}

	while (!(stk.empty())) {
		cout << stk.top();
		stk.pop();
	}

	return;

}
