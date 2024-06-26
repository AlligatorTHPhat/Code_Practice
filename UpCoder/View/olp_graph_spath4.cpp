#include <iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
//map<pair<int,int>, int> mp;
int dem,Max;
int dd[400005],DD[400005];
int vet[400005];
int Dau[400005],dau[400005];
int n, k;
struct ca // cấu trúc lưu đỉnh và số lần xuất hiện của cạnh
{
   int v;
   int s; // số lần xuất hiện của cạnh (ca được dùng trong mảng 2 chiều, u sẽ lưu ở trọng số mảng)
   ca(int _v = 0, int _s = 1)
   {
       v = _v; s = _s;
   }
};
vector<int> Canh[400005]; // lưu cạnh u v với đỉnh u là trọng số mảng, v là giá trị ô
vector<vector<ca> > canh(400005); // tương tự Canh nhưng là cấu trúc ca, có chứa số lần xuất hiện cạnh


void BFS(int x)
{
    int st = 0;
    queue<int> q;
    q.push(x);
    bool flag = false; // cờ báo hiện đây là cây hay 1 đồ thị có chu trình
    while(!q.empty())
    {
        int u = q.front();
        ++st; // biến lưu số phần tử của miền liên thông
        dd[u] = 1; // đánh dấu đã duyệt
        q.pop();
        for(ca y: canh[u])
        {
            int v = y.v;
            if(!flag)
            {
                if(dd[v] && vet[u] != v) // nếu nó gặp lại đỉnh nào đó đã duyệt 
                    flag = true;        // và đỉnh đó không phải là đầu kia 1 cạnh của nó
                if(y.s > 1) // số lượng cạnh nhiều hơn 1, chắc chắn ko phải cây
                    flag = true;
            }
            if(!dd[v])
            {
                q.push(v);
                vet[v] = u; // lưu vết để gặp lại u thì biết u với v chung cạnh
                dd[v] = 1;
            }
            
        }
    }
    
    if(flag) // không phải là cây
    {
        dem += st;
    }
    else // là cây
    {
        if(st > 1) // cây nhiều lá bình thường ;
            dem += st - 1;
        else            // cây 1 lá 1 gốc, chứng tỏ là 1 cạnh mà 2 đỉnh trùng màu
            ++dem; 
    }
   
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for (int i = 1; i <= n; i++) 
	{
	   int a,b;
	   cin>>a>>b;
	
	   Max = max(Max,max(a,b));// để biết màu nào bự nhất, để không phải duyệt cả 400000
	 
       Canh[a].push_back(b);
       Canh[b].push_back(a);
	   DD[a] = true; // đánh dấu đỉnh đó có trong đồ thị
	   DD[b] = true;
	}
	for(int u = 1; u <= Max; ++u) // xử lý lại vector cạnh,để biết 1 cạnh xuất hiện nhiều lần
	{
	    vector<int> tmp; // vector lưu các đỉnh còn lại có trong cạnh chứa đỉnh u
	  
	    if(Canh[u].size())
	    {
	         for(int v : Canh[u]) // reset mảng đánh dấu (đếm phân phối)
	        {
	            Dau[v] = 0;
	        }
	        for(int v: Canh[u])
	        {
	            ++Dau[v];
	            if(Dau[v] == 1) // gặp lần đầu thì thêm vào tmp
	            {
	                tmp.push_back(v);
	            }
	        }
	       
	        for(int v : tmp) // xử lý lại các đỉnh bị lặp nhiều lần
	        {
	            canh[u].push_back(ca(v,Dau[v])); // lưu đỉnh v và số lần xuất hiện cạnh u v
	           // dau[v] = Dau[v];
	        }
	    }
	}
	
	for(int i = 1; i<= Max; ++i)
	{
	    if(DD[i] && !dd[i]) // nếu có trong tập đỉnh và chưa được duyệt
	    {
	        BFS(i); // duyệt theo chiều rộng
	    }
	}
	cout<<dem;
	return 0;
}
