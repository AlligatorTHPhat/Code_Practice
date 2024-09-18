#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
vector<int> vec;

void input(int& n, int& x, int& y, vector<int>& vec) {
    cin >> n >> x >> y;
    vec.resize(n);
    for (int i = 0; i < vec.size(); i++)
        cin >> vec[i];
}

int relative_search(int n, int x, int y, vector<int> vec)
{
    int closet_index = -1;
    int min_difference = y + 1;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == x) return i;
        else if (abs(x - vec[i]) <= y)
        {
            int difference = abs(x - vec[i]);
            if (min_difference > difference)
            {
                closet_index = i;
                min_difference = difference;
            }
        }
    }
    return closet_index;
}

int main()
{
    input(n, x, y, vec);
    cout << relative_search(n, x, y, vec);

    return 0;
}

// 7 5 2
// 10 2 8 7 4 6 1
	
// 7 13 1
// 17 2 11 7 1 10 15

// #include <iostream>
// #include <vector>

// using namespace std;

// int n, x, y;
// vector<int> vec;

// void input(int& n, int& x, int& y, vector<int>& vec)
// {
// 	cin >> n >> x >> y;

// 	vec.resize(n);

// 	for (int i = 0; i < vec.size(); i++)
// 		cin >> vec[i];
// }

// int sequential_search(int n, int x, int y, vector<int>vec)
// {
// 	int result = -1;
// 	for (int i = 0; i < vec.size(); i++)
// 	{
// 		if (vec[i] == x) { return i; }
// 	}

// 	int a = x, b = x;
// 	while (a >= x - y && b <= x + y) {
// 		for (int i = 0; i < n; i++) {
// 			if (vec[i] == a || vec[i] == b) {
// 				return i;
// 			}
// 		} a--, b++;
// 	} return - 1;
// }

// int main()
// {
// 	input(n, x, y, vec);
// 	cout << sequential_search(n, x, y, vec);

// 	return 0;
// }
