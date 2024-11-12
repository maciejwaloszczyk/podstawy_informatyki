//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib> 
#include <map>
using namespace std;
map<int, int> wyrazyCiagu(int a1, int r) {
    map<int, int> ciagArytm;
    ciagArytm[1] = a1;
    for (int i=1; i<100; i++){
        ciagArytm[i+1] = ciagArytm[i] + r;
    }

    return ciagArytm;
}
int main() {
    int a1,r;
    cout<<"Wpisz pierwszy wyraz ciągu (a1): ";
    cin>>a1;

    cout<<"Wpisz różnicę ciągu (r): ";
    cin>>r;cout<<endl;

    map <int, int> an = wyrazyCiagu(a1,r);
    cout<<"Ciąg an:"<<endl;
    for (int i=1; i<101; i++){
        cout<<"Wyraz "<<i<<": "<<an[i]<<"; ";
    }
    cout<<endl;
    return 0;
}