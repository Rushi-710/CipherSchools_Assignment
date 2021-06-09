/*Print all the prime numbers between a 
range whose limits are given by the user*/

#include<bits/stdc++.h>
using namespace std;

int main() {
    //Taking the values of limits
    int low, high, count = 0;

    cout << "Enter the lower limit : ";
    cin >> low;
    cout << "\nEnter the upper limit : ";
    cin >> high;

    cout << "Prime numbers between " << low << " and " << high << " are: " << endl;
    //Checking whether the number is a prime number or not
    for(int i = low; i <= high; i++) 
    {
        for(int j = 2; j < i; j++) 
        {
            if (i % j == 0) 
            {
                count++;
                break;
            }
        }
    //Printing the prime numbers
        if(count == 0 && i!=1)
            cout << i << endl;
        count = 0; 
    }
    cout << endl;
    return 0;
}