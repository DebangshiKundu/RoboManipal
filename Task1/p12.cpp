#include<iostream>
using namespace std;
int rec(int n)
{
    if(n==0 or n==1) return 1;
    else return n*rec(n-1);
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The factorial is: "<<rec(n)<<endl;
}