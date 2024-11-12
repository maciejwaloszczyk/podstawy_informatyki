//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string DecimalToBinary(int n){
    string res = "";
    while (n > 0)
    {
        res = to_string(n % 2) + res;
        n = n / 2;
    }
    return res;
}
string DecimalToHexadecimal(int n){
    string res = "";
    while (n > 0){
        int temp = n % 16;
        if (temp < 10){
            res = to_string(temp) + res;
        }
        else{
            if (temp == 10)
                res = 'A' + res;
            else if (temp == 11)
                res = 'B' + res;
            else if (temp == 12)
                res = 'C' + res;
            else if (temp == 13)
                res = 'D' + res;
            else if (temp == 14)
                res = 'E' + res;
            else if (temp == 15)
                res = 'F' + res;
        }
        n = n / 16;
    }
    return res;
}
int BinaryToDecimal(string n){
    int res = 0;
    int j = 0;
    for (int i = n.length() - 1; i >= 0; i--){
        res += (n[i] - '0') * pow(2, j);
        j++;
    }
    return res;
}
string BinaryToHexadecimal(string n){
    int decimal = BinaryToDecimal(n);
    return DecimalToHexadecimal(decimal);
}
string OctalToBinary(int n) {
    string res = "";
    while (n > 0) {
        int digit = n % 10;
        string binary = DecimalToBinary(digit);
        while (binary.length() < 3) {
            binary = "0" + binary;
        }
        res = binary + res;
        n = n / 10;
    }
    while(res[0]=='0'){
        res.erase(0,1);
    }
    return res;
}

int main(){
    int a;
    cout << "a): " << DecimalToBinary(44) << endl;
    cout << "b): " << DecimalToHexadecimal(44) << endl;
    cout << "c): " << BinaryToDecimal("101") << endl;
    cout << "d): " << BinaryToHexadecimal("101100") << endl;
    cout << "e): " << OctalToBinary(115) << endl;
    return 0;
}
