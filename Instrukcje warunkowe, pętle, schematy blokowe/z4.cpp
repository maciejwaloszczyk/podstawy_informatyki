//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
int main(){
    int x;
    cout<<"Podaj numer dnia tygodnia: "; cin>>x;

    switch(x) {
        case 1:
            cout << "Niedziela" << endl;
            break;
        case 2:
            cout << "Poniedziałek" << endl;
            break;
        case 3:
            cout << "Wtorek" << endl;
            break;
        case 4:
            cout << "Środa" << endl;
            break;
        case 5:
            cout << "Czwartek" << endl;
            break;
        case 6:
            cout << "Piątek" << endl;
            break;
        case 7:
            cout << "Sobota" << endl;
            break;
        default:
            cout << "Niepoprawny numer dnia tygodnia!" << endl;
    }
    
    return 0;
}