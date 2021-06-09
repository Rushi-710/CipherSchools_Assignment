//Determine whether the given number is an Amstrong number or not
#include<bits/stdc++.h>
using namespace std;

int main() {
    //Taking input from the user
    int n, num, temp, rem, sum = 0;
    cout << "Enter the order of the number : ";
    cin >> n;
    cout << "Enter the number : ";
    cin >> num;
    temp = num;

    //Check whether the number is an Amstrong number
    while(temp != 0) {
        rem = temp % 10;
        sum = sum + pow(rem, n);
        temp = temp / 10;
    }
    //Number is an Armstrong number
    if(sum == num) {
        cout << "Output : Yes" << endl;
        cout << num << " " << "is an Armstrong number." << endl;
    }
    //Number is not an Armstrong number
    else {
        cout << "Output : No" << endl;
        cout << num << " is not an Amstrong number." << endl;
    }

    return 0;
}
