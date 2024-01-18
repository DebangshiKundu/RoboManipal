#include <iostream>
using namespace std;
void sort(int arr[], int n, int i, int j)
{
    if (i == n and j == n - 1)
        return;
    else
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
        if (j == n - 1)
            return sort(arr, n, i + 1, 0);
        else
            return sort(arr, n, i, j + 1);
    }
}
int main()
{
    int n, i, j;
    cout << "Size: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, n - 1, 0, 0);
    cout << "\nThe sorted array is:\n";
    for (i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl<<endl;
}