#include <iostream>
using namespace std;
class matrix
{
public:
    int a, b, arr[10][10];

    void getdata()
    {
        cout << "\nEnter the dimensions of the matrix: ";
        cin >> a >> b;
        cout << "Enter the elements:\n";
        for (int i = 0; i < a; i++)
            for (int j = 0; j < b; j++)
                cin >> arr[i][j];
    }
    void display()
    {
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
                cout << arr[i][j] << "\t";
            cout << endl;
        }
    }
    matrix mul(matrix m)
    {
        matrix temp;
        temp.a = a;
        temp.b = m.b;
        for (int i = 0; i < temp.a; i++)
        {
            for (int j = 0; j < temp.b; j++)
            {
                temp.arr[i][j] = 0;
                for (int k = 0; k < b; k++)
                    temp.arr[i][j] += arr[i][k] * m.arr[k][j];
            }
        }
        return temp;
    }
    matrix transpose()
    {
        matrix res;
        res.a = b;
        res.b = a;
        for (int i = 0; i < res.a; i++)
        {
            for (int j = 0; j < res.b; j++)
                res.arr[i][j] = arr[j][i];
        }
        return res;
    }
};
int main()
{
    int i, j, flag = 0;
    matrix A, B, res1, res2, trans, trans1, trans2;
    A.getdata();
    cout << "\nmatrix A:\n";
    A.display();
    B.getdata();
    cout << "\nmatrix B:\n";
    B.display();
    if (A.b == B.a)
    {
        res1 = A.mul(B);
        cout << "\ndisplay A.B :\n";
        res1.display();
        trans = res1.transpose();
        cout << "\ndisplay (A.B)' :\n";
        trans.display();
        cout << endl
             << endl
             << endl;
        trans1 = A.transpose();
        cout << "\ndisplay A' :\n";
        trans1.display();
        trans2 = B.transpose();
        cout << "\ndisplay B' :\n";
        trans2.display();
        res2 = trans2.mul(trans1);
        cout << "\ndisplay A'.B' :\n";
        res2.display();

        if (trans.a == res2.a and trans.b == res2.b)
        {
            for (i = 0; i < res2.a; i++)
                for (j = 0; j < res2.b; j++)
                    if (trans.arr[i][j] != res2.arr[i][j])
                    {
                        flag = 1;
                        break;
                    }
        }
        else
            flag = 1;

        if (flag == 0)
            cout << "\nThe identity is correct and verified\n";
        else
            cout << "\nnot verified\n";
    }
    else
    {
        cout << "\nInvalid input\n";
    }
    return 0;
}