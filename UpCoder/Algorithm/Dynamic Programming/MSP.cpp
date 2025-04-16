#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> values;
    
    int n;
    while (cin >> n)
        values.push_back(n);
        
    vector<int> dp(values.size());   
    
    dp[0] = values[0];
    
    int maxSum = dp[0];
    for(int i = 1; i < values.size(); i++)
    {
        if(dp[i - 1] + values[i] > values[i])
            dp[i] = dp[i - 1] + values[i];
        else
            dp[i] = values[i];
        
        if(dp[i] > maxSum)
            maxSum = dp[i];
    }
    cout << maxSum;
    
    return 0;
}
