#include <iostream>
#include <vector>
using namespace std;

struct ToaDo
{
    int x, y;
};

int m, n, sum, max_oil; // m dong, n cot, sum_oil, max_oil

vector<ToaDo> tmp, res;  // luu ketqua = vector
ToaDo save;             // luu == toa do

void Try(vector<vector<int>>& array, int x, int y)
{
    // dieu kien tim max;
    if (x < 0 || x >= m || y < 0 || y >= n)
    {
        if (sum > max_oil)
        {
            max_oil = sum;
            res = tmp;
        }
        return;
    }

    sum += array[x][y];
    save.x = x + 1;
    save.y = y + 1;
    tmp.push_back(save);

    Try(array, x + 1, y);
    Try(array, x, y + 1);

    sum -= array[x][y];
    tmp.pop_back();
}

int main()
{
    cin >> m >> n;

    vector<vector<int>> arr(m); // tao mang arr = vector

    for (auto& row : arr)
    {
        vector<int> col(n);
        for (auto& values : col)
        {
            cin >> values; // cin gia tri == arr[i][j]
        }
        row = col;
    }

    Try(arr, 0, 0);

    cout << max_oil << "\n"; // xuat ra luong dau lon nhat ma minh dat dc

    for (auto& point : res)
    {
        cout << point.x << " " << point.y << "\n";  // xuat toado duong di
    }
    return 0;
}

