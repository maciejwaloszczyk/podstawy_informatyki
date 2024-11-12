//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
double Pa2bar(double x){
    return (x * (pow(10,-5)));
}
double Pa2tor(double x){
    return (x * 0.0075);
}
double Pa2psi(double x){
    return (x * (145.038 * (pow(10,-6))));
}
int main() {
    double pa;
    int program;
    cout<<"Wpisz liczbę Pa: "; cin>>pa; cout<<endl;
    cout<<"Konwerter: \n";
    cout<<"[1] Pa => bar: \n";
    cout<<"[2] Pa => tor: \n";
    cout<<"[3] Pa => psi: \n";
    cout<<"\nOpcja >> ";cin>>program;cout<<endl;

    switch(program){
        case 1:
            cout<< pa << "[Pa] = " << Pa2bar(pa) << "[bar]\n";
            break;
        case 2:
            cout<< pa << "[Pa] = " << Pa2tor(pa) << "[tor]\n";
            break;
        case 3:
            cout<< pa << "[Pa] = " << Pa2psi(pa) << "[psi]\n";
            break;
        default:
            return 0;
    }
    return 0;
}