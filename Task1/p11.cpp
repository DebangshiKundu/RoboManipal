#include <iostream>
using namespace std;
void sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
}
int search(int arr[], int t, int l, int m, int r)
{
    if (arr[m] == t)
        return m;
    else
    {
        if (t > arr[m])
            return search(arr, t, m + 1, m + 1 + (r - l) / 2, r);
        else
            return search(arr, t, l, m / 2, m - 1);
    }
}
void display(int arr[], int n)
{
    cout << "\nThe sorted array is:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
int main()
{
    int n, i, t, pos;
    cout << "Size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, n);
    display(arr, n);
    cout << "Enter target: ";
    cin >> t;
    pos = search(arr, t, 0, n / 2, n);
    cout<<"\nPosition: "<<pos+1<<endl;
}