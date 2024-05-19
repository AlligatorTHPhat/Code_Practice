#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string str; 
	getline(cin, str);
	queue<char> Queue;

	for (char c : str) {
		if (c == '*' && !Queue.empty()) {
			cout << Queue.front();
			Queue.pop();
		}
		else if (c != '*')
			Queue.push(c);
	}
	return 0;
}
