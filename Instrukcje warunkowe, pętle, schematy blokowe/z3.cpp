//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
int main(){
    int liczby[5];
    for(int i=0;i<5;i++){
        int x = 0;
        cout<<"Podaj "<<i+1<<" liczbę: "; cin>>x;
        liczby[i]=x;
    }
    int min_liczby = liczby[0];
    int max_liczby = liczby[0];
    for(int i=1;i<5;i++){
        if (min_liczby > liczby[i]){
            min_liczby = liczby[i];
        }
        if (max_liczby < liczby[i]){
            max_liczby = liczby[i];
        }
    }
    cout<<"\nNajmniejsza liczba: "<<min_liczby<<endl;
    cout<<"Największa liczba: "<<max_liczby<<endl;

    cout<<"Różnica liczb: "<<max_liczby-min_liczby<<endl;
    
    return 0;
}