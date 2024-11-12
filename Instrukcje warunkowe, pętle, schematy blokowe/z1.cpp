//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
void czyPrzestepny(int r){
    if(r%4==0){
        cout<<"Przestępny."<<endl;
    }else{
        cout<<"Nieprzestępny."<<endl;
    }
}
int main(){
    int rok;
    cout<<"Podaj rok: "; cin>>rok;
    czyPrzestepny(rok);
    return 0;
}