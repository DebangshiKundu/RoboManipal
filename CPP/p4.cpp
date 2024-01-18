#include <iostream>
using namespace std;
int main()
{
    int i, j = 0, num, flag = 0, a[10], idx = 0;
    cout << "Enter the number: ";
    cin >> num;
    while (num != 0)
    {
        i = num % 10;
        a[j++] = i;
        num = num / 10;
    }
    int max = a[0];
    for (i = 0; i < j; i++)
    {
        if (max < a[i])
        {
            max = a[i];
            idx = i;
        }
    }
    if (idx == 0 or idx == j - 1)
        flag = 1;
    for (i = 0; i < j; i++)
    {
        if (i < idx)
            if (a[i] >= a[i + 1])
                flag = 1;
        if (i >= idx and i < j - 1)
            if (a[i] <= a[i + 1])
                flag = 1;
    }
    if (flag == 1)
        cout << "Not a hill number\n";
    else
        cout << "Hill number\n";
}