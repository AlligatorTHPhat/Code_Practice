#include<iostream>
#include<string>
using namespace std;
struct structure{
    string result;
};
int findGCD(int num1, int num2){
    if (num1==0) return num2;
    return (num2, num1 % num2);
}
void lowestFraction(int num1,int num2){
    structure fraction;
    fraction.result="/";
    int demon;
    demon = findGCD(num1,num2);
    num1/=demon;
    num2/=demon;
    cout<<num1<<fraction.result<<num2;
}
int main(){
    int num;
    int num1,num2;
    int num3,num4;
    cin>>num;
    cin>>num1>>num2;
    cin>>num3>>num4;
    lowestFraction(num3,num4);
}
