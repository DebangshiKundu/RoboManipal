#include <iostream>
using namespace std;
int main()
{
    int i, j, m = 0, n = 0, a, b;
    cout << "Enter the dimension of the matrix: ";
    cin >> a >> b;
    int arr[a][b], res[a][b];
    cout << "Enter the elements:\n";
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
            cin >> arr[i][j];
    }
    cout << "The resultant matrix is:\n";
    // for (i = 0; i < a; i++)
    // {
    //     for (j = 0; j < b; j++)
    //     {
    //         if (arr[i][j] == 0)
    //         {
    //             while (m < a and n < b)
    //             {
    //                 arr[i][n++] = 0;
    //                 arr[m++][j] = 0;
    //             }
    //         }
    //     }
    // }
    // int m=matrix.size();
    //     int n=matrix[0].size(),i=0,j=0,a=0,b=0;
        vector<vector<bool> > mat(a, vector<bool>(b, false));
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if(arr[i][j]==0 and mat[i][j]==false)
                {
                    m=0,n=0;
                    while(m<a and n<b)
                    {
                        arr[i][n]=0;
                        mat[i][n++]=true;
                        arr[m][j]=0;
                        mat[m++][j]=true;
                    }
                }
            }
        }
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
            cout << arr[i][j] << "\t";
        cout << endl;
    }
}