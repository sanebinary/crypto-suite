#include <iostream>
#include <string>
using namespace std;
int main(){
	string s = "49";
	int num = strtol(s,0,16);
	cout << num;
}
