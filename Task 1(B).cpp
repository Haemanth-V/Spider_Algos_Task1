#include<bits/stdc++.h>

using namespace std;

//Recursive function to repeatedly find degree of symmetry 
// of substrings that are symmetrical in a given string

int degree_of_symmetry(string str, int length){
	if(length%2)
	   return 0;
	string first_half = str.substr(0,length/2);
	
	//Checking if given string is symmetrical
	if(str.substr(length/2,length/2).compare(first_half)==0)
	   return 1 + degree_of_symmetry(first_half, length/2); 
	else return 0;
}

int main(){
	int length;
	string input;
	cin>>length>>input;
	cout<<degree_of_symmetry(input,length);
}
