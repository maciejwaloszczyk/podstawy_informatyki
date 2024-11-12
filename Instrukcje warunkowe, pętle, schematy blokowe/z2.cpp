//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
int main(){
    int x,y;
    int suma = 0;
    cout<<"Podaj x: "; cin>>x;
    cout<<"Podaj y: "; cin>>y;
    if (x>y){
        cout<<"Błąd: x>y"<<endl;
        return 0;
    }
    cout<<"Liczby całkowite z przedziału ["<<x<<","<<y<<"]:"<<endl;
    for(int i=0; i<=(y-x); i++){
        cout<<x+i<<" ";
        if ((x+i)%2==0){
            suma += x+i;
        }
    }
    cout<<"\nSuma parzystych liczb całkowitych z przedziału ["<<x<<","<<y<<"]:"<<suma<<endl;
    
    return 0;
}