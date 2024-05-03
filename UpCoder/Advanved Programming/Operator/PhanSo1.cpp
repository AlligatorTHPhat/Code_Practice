#include<iostream>
using namespace std;
struct PhanSo{
    int tu,mau;
};
int main(){
    PhanSo p1,p2;
    cin>>p1.tu>>p1.mau>>p2.tu>>p2.mau;
    if(p1.mau*p2.mau==0){
        cout<<-1;
    }
    else{
        PhanSo tong;
        tong.tu=p1.tu*p2.mau+p1.mau*p2.tu;
        tong.mau=p1.mau*p2.mau;
        int a=tong.tu,b=tong.mau;
        //tim UCLN de rut gon
        while(a!=b){
            if(a>b) a-=b;
            if(a<b) b-=a;
        }
        tong.tu/=a;
        tong.mau/=a;
        cout<<tong.tu<<"/"<<tong.mau;
    }
    return 0;
}

