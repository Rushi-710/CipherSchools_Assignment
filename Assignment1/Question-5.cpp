//Toggle the case of every character of a string
#include<bits/stdc++.h>
using namespace std;

int main() {
	string str1;

  	cout <<"\n Please Enter any String to Toggle : ";
	cin >> str1;
	int len = str1.length();
  	
  	for (int i = 0; i < len; i++) {
  	//If the character is upper-cased	
		  if(str1[i] >= 'A' && str1[i] <= 'Z') {

			  str1[i] = 'a' + (str1 [i] - 'A');
		  }
  	//If the character is lower-cased
  		else if(str1[i] >= 'a' && str1[i] <= 'z') {
			  str1[i] = 'A' + (str1[i] - 'a');
		  }
  	}
	//Printing the output after we toggled the string
  	cout << "\n The Given String after Toggling Case of all Characters = ";
	cout << str1 << endl;
  	
    return 0;
}