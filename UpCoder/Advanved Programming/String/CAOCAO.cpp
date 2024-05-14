#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string player_name[5]{ "Su", "Lu", "Bu", "Ti", "Teo" };
	string str[5], tmp;

	for (int i = 0; i < 5; i++) 
		getline(cin, str[i]);

	int max_point = 0;
	int sum_point[5]{ 0,0,0,0,0 };

	for (int i = 0; i < 5; i++) {
		stringstream ss(str[i]);
		int luck = 0;

		while (ss >> tmp) {
			if (tmp == "J" || tmp == "Q" || tmp == "K") {
				sum_point[i] += 10;
				luck++;
			}
			else if (tmp == "A") {
				sum_point[i]++;
			}
			else sum_point[i] += stoi(tmp);
		}
		
		if (luck == 3) sum_point[i] = 10;
		else if (sum_point[i] > 30) sum_point[i] = 0;
		else sum_point[i] %= 10;

		max_point = max(max_point, sum_point[i]);
	}

	for (int i = 0; i < 5; i++) {
		if (sum_point[i] == max_point)
			cout << player_name[i] << " ";
	}

	return 0;
}
