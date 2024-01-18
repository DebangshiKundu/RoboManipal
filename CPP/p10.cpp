#include <iostream>
using namespace std;
int fibo(int n, int arr[])
{
    if (n == 0 or n == 1)
        return n;
    if (arr[n] == 0){
        arr[n] = fibo(n - 2, arr) + fibo(n - 1, arr);
    }
    return arr[n];
    
}
int main()
{
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    int arr[n], i;
    while (i < n)
        arr[i++] = 0;
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i, arr) << "\t";
    }
    cout << endl;
}