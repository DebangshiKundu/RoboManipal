#include<iostream>
#include <string.h>
using namespace std;
int main()
{
    string s;
    int i=0,j=0,n=0;
    cout<<"Enter the string: ";
    getline(cin,s);
    while(s[n]!='\0')
    n++;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(int(s[j])>int(s[j+1]))
            {
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }

    cout<<"Sorted: \n";
    cout<<s<<endl;

}