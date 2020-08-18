#include <bits/stdc++.h>

using namespace std;

//Function that finds input-1 and input+1 strings
//Logic : traverses the input to find the first occurence of check in input string 
// 0 for adding 1 and 1 for subtracting 1 and alters the input string
// upto that position and returns the final result after checking for a left out 1
// obtained by adding 1 to for instance 1111
//Using +1 and -1 because if they dont satisfy the legnth constraint then nothing else would 

string new_number(string num, int length, char check){
	int i;
	string result = num;
	for(i=0;i<length;i++){
		if(result[i]==check)
		  break;
	}
	for(int j=0;j<=i;j++){
		if(result[j]=='0')
		   result[j]='1';
		else 
		   result[j]='0';
	}
	if(result[length-1]=='0' && check=='0' && num[length-1]!='0') //checking for leading zeroes also as in 0001 in input
	   result.push_back('1');
	return result;
}

int main(){
	
	int length;
	string number,number1,number2;
	cin>>length>>number;

    //reversing string for traversing from 0 index
	reverse(number.begin(), number.end());
	
	//input +1 string
	number1 = new_number(number, length, '0');
    
	//input -1 string
	number2 = new_number(number, length, '1');
	
	//Reversing to print back
	reverse(number1.begin(), number1.end());
	reverse(number2.begin(), number2.end());
	
	if(number1.length()!=number2.length() || number == "0")
	    cout<<"-1";
	else if(number2[0]!='1' && number[length-1]=='1') //checking for leading zeroes also as in 0001 in input
	    cout<<"-1";
	else
		cout<<number2<<" "<<number1;

}
