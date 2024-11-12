#include<iostream>
using namespace std;
bool negacja(bool p){
    return !p;
}
bool koniunkcja(bool p, bool q){
    return p && q;
}
bool alternatywa(bool p, bool q){
    return p || q;
}
bool implikacja(bool p, bool q){
    if(p == 1 && q == 0) return 0;
    return 1;
}
bool rownowaznosc(bool p, bool q){
    return p == q;
}
int main(){
    cout << negacja(1) << endl;
    cout << koniunkcja(1,0) << endl;
    cout << alternatywa(1,0) << endl;
    cout << implikacja(0,1) << endl;
    cout << rownowaznosc(0,0) << endl;

}
