#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, w; cin >> n >> w;
    vector<int> a(n + 1), c(n + 1);
    
    for(int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
        
    
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    vector<vector<bool>> take(n + 1, vector<bool>(w + 1, false));
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            
            if(j >= a[i])
            {
                int newVal = dp[i - 1][j - a[i]] + c[i];
                if(newVal > dp[i][j])
                {
                    dp[i][j] = newVal;
                    take[i][j] = true;
                }
            }
        }

    vector<int> num(n + 1, 0); int j = w;
    for(int i = n; i >= 1; --i)
    {
        if(take[i][j])
        {
            num[i] = 1;
            j -= a[i];
        }
    }
    cout << dp[n][w] << "\n";
    
    for(int i = 1; i <= n; i++)
        cout << num[i] << " ";
}
