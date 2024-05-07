#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (a[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][w] << endl;

    int i = n, j = w;
    vector<int> chosen_items;
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            chosen_items.push_back(i - 1);
            j -= a[i - 1];
        }
        --i;
    }

    for (int k = chosen_items.size() - 1; k >= 0; --k) {
        cout << chosen_items[k] << " ";
    }
    
    return 0;
}
