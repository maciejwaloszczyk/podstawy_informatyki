//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
int LiczbyPitagorejskie(int a, int b, int c){
    if (pow(a,2)+pow(b,2)==pow(c,2)){
        return 1;
    }
    return 0;
}
int main() {
    int a,b,c;
    cout<<"Wpisz liczbę a: "; cin>>a;
    cout<<"Wpisz liczbę b: "; cin>>b;
    cout<<"Wpisz liczbę c: "; cin>>c; cout<<endl;
    cout<<LiczbyPitagorejskie(a,b,c)<<endl;
    return 0;
}