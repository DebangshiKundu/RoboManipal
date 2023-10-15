#include <iostream>
using namespace std;
class mat
{
public:
    int a;
    char **arr;
    void getdata()
    {
        cout << "Enter number of rows: ";
        cin >> a;
        arr = new char *[a];
        fflush(stdin);
        cout << "Enter the strings:\n";
        for (int i = 0; i < a; i++)
        {
            char s[100];
            cin.getline(s, 100);
            arr[i] = new char[strlen(s)];
            strcpy(arr[i], s);
        }
    }
    void display()
    {
        for (int i = 0; i < a; i++)
            cout << arr[i] << endl;
    }
    void rearrange()
    {
        int i = 0, j = 0;
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < a - 1; j++)
            {
                if (strlen(arr[j]) > strlen(arr[j + 1]))
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void alphabet()
    {
        int i, j, k;
        for (i = 0; i < a; i++)
        {
            for (k = 0; k < strlen(arr[i]) - 1; k++)
            {
                for (j = 0; j < strlen(arr[i]) - 1; j++)
                {
                    if (int(arr[i][j]) > int(arr[i][j + 1]))
                        swap(arr[i][j], arr[i][j + 1]);
                }
            }
        }
    }
};
int main()
{
    mat A;
    A.getdata();
    A.rearrange();
    cout << "\nThe rearranged strings are:\n";
    A.display();
    A.alphabet();
    cout << "\nThe alphabetically arranged letters of string are:\n";
    A.display();
    cout<<endl;
}