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

int hexByte(string hex, int index){
  int hex1 = hexVal(hex[index]) << 4;
  int hex2 = hexVal(hex[index+1]);
  int test = hex1 | hex2;
  return test;
}

void b64quads(string hex, string *b64_p, int pad, int index = 0){
  string dec2base = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	char h1 = hexByte(hex, index);
  char h2 = hexByte(hex, index + 2);
  char h3 = hexByte(hex, index + 4);
  char b1 = h1 >> 2;
  char b2 = ((h1 & 0x03) << 4) + (h2 >> 4);
  char b3 = ((h2 & 0x0f) << 2) + (h3 >> 6);
  char b4 = h3 & 0x3f;
  *b64_p += dec2base[b1];
  *b64_p += dec2base[b2];
  *b64_p += (pad == 2 && !b3 ? '=' : dec2base[b3]);
  *b64_p += (pad && !b4 ? '=' : dec2base[b4]);
  return;
}

string hex2base64(string hex)
{
    string base64 = "";
    string *base64_p = &base64; 
    int hex_size = hex.length();
    if (!hex_size)
        return NULL;
    if (hex_size % 2 != 0)
        return NULL;
    int index = 0;
    while (hex_size > 6){
      b64quads(hex, base64_p, 0, index);
      index += 6;
      hex_size -= 6;
      cout << base64;
    }
    if (hex_size > 0){
      string temphex = "000000";
      b64quads(temphex, base64_p, hex_size);
    }
}

int main(){
  string input = "49";
	string test = hex2base64(input); 
}
