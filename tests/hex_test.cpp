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

int hexByte(string hex, int index)
{
    return (hexVal(hex[index]) << 4) | hexVal(hex[index + 1]);
}

void b64quads(string hex){
    char h1 = hexByte(hex, 0);
    char h2 = hexByte(hex, 2);
    char h3 = hexByte(hex, 4);
    char b1 = h1 >> 2;
    char b2 = ((h1 & 0x03) << 4) + (h2 >> 4);
    char b3 = ((h2 & 0x0f) << 2) + (h3 >> 6);
    char b4 = h2 & 0x3f;
    cout << b1 << "\n" << b2 << "\n" << b3 << "\n" << b4 << "\n";
}
int main(){
    string sample = "492d";
    cout << (hexByte(sample,0) >> 2);
}