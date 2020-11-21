#include <iostream>
#include <string>
using namespace std;

int hexVal(char c)
{
	if (c >= 'a' && c <= 'f')
		return 10 + c - 'a';
	if (c >= 'A' && c <= 'F')
		return 10 + c - 'A';
	if (c >= '0' && c <= '9')
		return c - '0';
	return 0;
}

string str_xor(string const &s1, string const& s2){
    string result;
    for (int i = 0; i < s1.length(); ++i){
        result += to_string(hexVal(s1[i]) ^ hexVal(s2[i]));
    }
    return result;
}

int main(){
    string first_string;
    string second_string;
    cout << "XOR between two hexes: \n";
    cout << "Enter first hex string: \n";
    cin >> first_string;
    cout << "The value you entered is: \n" << first_string << "\n";
    cout << "Enter second hex string: \n";
    cin >> second_string;
    cout << "The value you entered is: \n" << second_string << "\n";
    cout << "The XOR is: " << "\n";
    cout << hex << str_xor(first_string, second_string) << "\n";
}

