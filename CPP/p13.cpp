#include<iostream>
using namespace std;
int rec(int n,int sum)
{
    if (n==0) return sum;
    else{
        sum+=n%10;
        return rec(n/10,sum);
    }
}
int main()
{
    int n,sum=0,ch=0;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"1)sum with recursion\n2)sum without recursion\n\nEnter choice: ";
    cin>>ch;
    switch (ch)
    {
        case 1:
        {
            cout<<"The sum (with recursion) is: "<<rec(n,sum)<<endl<<endl;
            break;
        }
        case 2:
        {
            while(n!=0)
            {
                sum+=n%10;
                n=n/10;
            }
            cout<<"The sum (without recursion) is: "<<sum<<endl<<endl;
            break;
        }
        default:cout<<"Invalid choice\n";
    }
}