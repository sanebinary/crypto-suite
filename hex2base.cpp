#include <iostream>
#include <string>

string hex2base(string hex, int size){
	char* base64 = "";
	if (size % 3 == 0){ 
		int size64 = size / 3 * 2;
	}
	for (int i = 0; i < size; i+=3){
		base64[i] += hex[i] 
	}
}
