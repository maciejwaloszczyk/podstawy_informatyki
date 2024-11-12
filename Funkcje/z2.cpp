//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>  
using namespace std;
int* robocik(int a,  int b, int c, int d){
    int pozycja[2];
    pozycja[0] = 0;
    pozycja[1] = 0;
    //N
    pozycja[1] += a;
    //E
    pozycja[0] += b;
    //S
    pozycja[1] -= c;
    //W
    pozycja[0] -= d;

    return pozycja;
}
int main() {
    int w,x,y,z;
    cout<<"Wpisz pierwszy ruch: ";
    cin>>w;

    cout<<"Wpisz drugi ruch: ";
    cin>>x;

    cout<<"Wpisz trzeci ruch: ";
    cin>>y;

    cout<<"Wpisz czwarty ruch: ";
    cin>>z;cout<<endl;
    cout<<"Robocik poruszył się na pole x,y = {"<<robocik(w,x,y,z)[0]<<","<<robocik(w,x,y,z)[1]<<"}"<<endl;
    return 0;
}