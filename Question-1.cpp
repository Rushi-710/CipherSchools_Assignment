//Determine whether the given number is an Amstrong number or not
#include<bits/stdc++.h>
using namespace std;

int main() {
    //Taking input from the user
    int num, temp, rem, sum = 0;
    cout << "Input : ";
    cin >> num;
    temp = num;

    //Check whether the number is an Amstrong number
    while(temp != 0) {
        rem = temp % 10;
        sum += pow(rem, rem);
        temp = temp / 10;
    }
    //Number is an Armstrong number
    if(sum == num) {
        cout << "Output : Yes" << endl;
        cout << num << " " << "is an Armstrong number." << endl;
    }
    //Number is not an Armstrong number
    else(sum != num); {
        cout << "Output : No" << endl;
        cout << num << " is not an Amstrong number." << endl;
    }

    return 0;
}