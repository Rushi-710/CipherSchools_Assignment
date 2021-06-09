//Create a pattern of '*'s as given in the problem
#include<bits/stdc++.h>
using namespace std;

int main() {
    //Taking input from user
    int n;

    cout << "Input : ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
    //Loop for printing spaces 
        for (int k = n - i; k > 0; k--) {
            cout << "     ";
        }
    //Loop for printing '*'s
        for (int j = 1; j <= i; j++) {
            cout << "    *" ;
        }

        cout  << endl;
    }
    return 0;
}