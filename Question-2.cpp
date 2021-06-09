// C++ program to find first and last occurrence of
// an elements in given sorted array
#include <bits/stdc++.h>
using namespace std;
 
// Function to find first and last occurrence of an element
void findFirstAndLast(int arr[], int n, int x)
{
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (x != arr[i]) 
            continue;
        if (first == -1)
            first = i;
        last = i;
    }
    if (first != -1) {
        cout << "First Occurrence = " << first;
        cout << "\nLast Occurrence = " << last;
    }
    else {
        cout << "Not Found";
    }
}
 
int main()
{
    int arr[10] = {};
    cout << "Enter the values of the array in ascending order : ";

    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    int n = sizeof(arr) / sizeof(int);
    int x;
    cout << "Enter the element : ";
    cin >> x;
    findFirstAndLast(arr, n, x);
    
    return 0;
}