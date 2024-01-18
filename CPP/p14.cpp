#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if (a==0) return b;
    else if(b==0) return a;
    else return gcd(b,a%b);
}
int main()
{
    int a,b;
    cout<<"Enter the two numbers: ";
    cin>>a>>b;
    cout<<"The gcd of the numbers is: "<<gcd(a,b);
}