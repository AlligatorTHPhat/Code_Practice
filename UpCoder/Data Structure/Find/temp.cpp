#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,a[100];
    cin>>n>>m;
    int check=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            check+=1;
        }
    }
    sort(a, a + n);
    int count=0;
   // if(check>0){
        for(int i =0;i<m;i++){
            if(a[i]<=0){
            count+=a[i];        
            }
        }
    //}else{
      //  count+=a[0];
   // }
    cout<<abs(count);
}
