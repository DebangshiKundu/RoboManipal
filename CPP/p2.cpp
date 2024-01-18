#include<iostream>
using namespace std;
int main()
{
   int a,b,c,d,i,j,k;
   cout<<"Enter dim of 1st mat: ";
   cin>>a>>b;
   int m1[a][b];
   cout<<"Enter the elements:\n";
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        cin>>m1[i][j];
    }
   cout<<"Enter dim of 2nd mat: ";
   cin>>c>>d;
   int m2[c][d];
   cout<<"Enter the elements:\n";
    for(i=0;i<c;i++)
    {
        for(j=0;j<d;j++)
        cin>>m2[i][j];
    }
    int res[a][d];
    if(b!=c)
    {
        cout<<"invalid input.\n";
    }
    else{
        for(i=0;i<a;i++)
        {
            for(j=0;j<d;j++)
            {
                res[i][j]=0;
                for(k=0;k<b;k++)
                    res[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    cout<<"The resultant matrix is:\n";
    for(i=0;i<a;i++)
    {
        for(j=0;j<d;j++)
        cout<<res[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
}