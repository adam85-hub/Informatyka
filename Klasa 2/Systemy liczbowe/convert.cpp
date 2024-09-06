#include <iostream>
#include <math.h>
#include <string>

using namespace std;

string DECtoBIN(string dec) {
    string bin = "";
    int d = atoi(dec.c_str());
    if(d == 0) return "0";
    while(d > 0) {
        bin += to_string(d%2);
        d /= 2;
    }
    string nbin = "";
    for(int i = bin.size()-1; i >= 0; i--) {
        nbin += bin[i];
    }
    return nbin;
}

string BINtoDEC(string bin) {
    int dec = 0;
    for(int i = bin.size()-1; i >= 0; i--) {
        dec += (bin[i]-int('0')) * pow(2, bin.size()-i-1);
    }
    return to_string(dec);
}

string DECtoHEX(string dec) {
    string hex = "";
    int h = atoi(dec.c_str());
    if(h == 0) return "0";
    int x = 0;
    while(h > 0) {
        x = h%16;
        if(x>9) hex += char(int('A')+x-10);
        else hex += to_string(x);
        h /= 16;
    }
    string nhex = "";
    for(int i = hex.size()-1; i >= 0; i--) {
        nhex += hex[i];
    }
    return nhex;
}

string HEXtoDEC(string hex) {
    int dec = 0;
    int x = 0;
    for(int i = hex.size()-1; i >= 0; i--) {
        if(hex[i] >= char('A') && hex[i] <= char('F')) {
            dec += (hex[i]-int('A')+10) * pow(16, hex.size()-i-1);
        }
    }
    return to_string(dec);
}

int main()
{
    cout << BINtoDEC("1101") << endl;
    cout << DECtoBIN("13") << endl;
    cout << DECtoHEX("250") << endl;
    cout << HEXtoDEC("FA") << endl;
    return 0;
}
