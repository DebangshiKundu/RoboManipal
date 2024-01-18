#include <iostream>
using namespace std;
int main()
{
    int a, b, i = 0, j = 0, k = 0, flag = 0, sum1 = 0, sum2 = 0;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    for (i = 0; i <= a / 2; i++)
    {
        if (a % i == 0)
            sum1 += i;
    }
    for (i = 0; i <= b / 2; i++)
    {
        if (b % i == 0)
            sum2 += i;
    }
    if (sum1 == b and sum2 == a)
        flag = 1;
    if (flag == 1)
    {
        cout << "\nAmicable numbers\n\n";
    }
    else
    {
        cout << "\nNot amicable\n\n";
    }
}