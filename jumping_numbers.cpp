#include <bits/stdc++.h>

#define li unsigned long long int

using namespace std;

// Global vector to store the jumping numbers
std::vector<li> v;

void next(li i, li ud, li n) {

	if( (i%10 == 9 && ud == 1) || (i%10 == 0 && ud == -1) ) { return; }
	//If Least significant digit is 9 then it should not be incremented to 10
	//If Least significant digit is 0 then it should not be decremented to -1

	li temp = (i*10) + (i%10 + ud); //Generate the next jumping number
	
	//If the generated number is greater than given number (input n), return else push into vector 
	if(temp <= n) { v.push_back(temp); } else { return; }

	next(temp, 1, n); next(temp, -1, n);
}

void printjumpingnumbers(li n)
{
	v.push_back(0);
	
	for(auto i = 1; i < 10; ++i) {
		//Push the single digit number into vector
		v.push_back(i);
		next(i, 1, n); //Jumping numbers with next digit greater than the current single digit 
		next(i, -1, n); //Jumping numbers with next digit lesser than the current single digit 
	}
	
	sort(v.begin(), v.end()); //Sort the jumping numbers 

	for(auto i: v) { cout << i <<" "; } cout << endl; //Print the numbers
}

//Driver program
int main()
{
	li n;
	cout <<"\nPrint all Jumping Numbers smaller than or equal to ? (+ve integer): "; cin >> n;
	cout <<"\nThe jumping numbers are: "; printjumpingnumbers(n); cout << endl;
	return 0;
}