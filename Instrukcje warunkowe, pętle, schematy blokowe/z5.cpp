//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
int main(){
    int n;
    double suma = 0;

    cout << "Podaj ile liczb chcesz wprowadzić: ";
    cin >> n;

    if (n <= 0) {
        cout << "Błąd: n<0" << endl;
        return 0;
    }

    double liczba;
    for (int i = 0; i < n; i++) {
        cout << "Podaj liczbę " << i + 1 << ": ";
        cin >> liczba;
        suma += liczba;
    }

    double avg = suma / n;

    cout << "Średnia arytmetyczna wprowadzonych liczb: " << avg << endl;

    int x = static_cast<int>(avg);
    cout << "Liczba 0 wypisana " << x << " razy:" << endl;
    for (int i = 0; i < x; i++) {
        cout << "0 ";
    }
    cout<<endl;
    return 0;
}