#include <iostream>

using namespace std;

int n, sum, count;
int pointX[] = { -1,-2,1,-2,-1,2,2,1 };
int pointY[] = { -2,-1,-2,1,2,-1,1,2 };
bool adj[1000][1000];

void Try(int x, int y);

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adj[i][j] = true; count++; Try(i, j);
            adj[i][j] = false, count--;
        }
    }
    cout << sum;
}

void Try(int x, int y)
{
    if (count == n * n)
    {
        sum++; return;
    }

    for (int i = 0; i < 8; i++)
    {
        int u = x + pointX[i];
        int v = y + pointY[i];

        if (1 <= u && u <= n && 1 <= v && v <= n && !adj[u][v])
        {
            adj[u][v] = true; count++; Try(u, v);
            adj[u][v] = false, count--;
        }
    }
}

#include <iostream>
using namespace std;
int DAYSO(int n)
{
    if (n <= 1)
        return n;
    if (n % 2 == 0)
        return DAYSO(n / 2);
    else
        return DAYSO(n / 2) + DAYSO(n / 2 + 1);
}
int main()
{
    int n; cin >> n;
    int max = -1;
    for (int i = 0; i <= n; i++)
        if (max < DAYSO(i))
            max = DAYSO(i);
    cout << max;

    return 0;
}

#include <iostream>
using namespace std;

int n, dem = 0;
int dong[100], cot[100];
int cheoxuoi[100], cheonguoc[100];

void printResult()
{
    cout << dem;
}

void Try(int i)
{
    if (i == n)
        dem++;
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (cot[j] == 0 && cheoxuoi[i - j + n] == 0 && cheonguoc[i + j] == 0)
            {
                dong[i] = j; cot[j] = 1;
                cheoxuoi[i - j + n] = 1;
                cheonguoc[i + j] = 1;
                Try(i + 1);
                cheoxuoi[i - j + n] = 0;
                cheonguoc[i + j] = 0;
                dong[i] = 0; cot[j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n;
    Try(0);
    printResult();
    return 0;
}
