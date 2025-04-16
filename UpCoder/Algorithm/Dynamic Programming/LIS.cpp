#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    
    int n;
    while(cin >> n)
        arr.push_back(n);
    
    vector<int> dp(arr.size());
    
    dp[0] = arr[0];
    
    int size = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        dp[i] = 1;
        
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }
        
        if(dp[i] > size)
            size = dp[i];
    }
    
    cout << size;
        
    return 0;
}
