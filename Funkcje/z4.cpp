//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void zgadywankaLiczbowa() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int liczba = rand() % 100 + 1;
    int proba;
    int licznik_prob = 0;

    cout << "Zgadnij liczbę od 1 do 100!\n";

    do {
        cout << "Podaj liczbę: ";
        cin >> proba;
        licznik_prob++;

        if (proba > liczba) {
            cout << "ZA DUŻO!\n";
        } else if (proba < liczba) {
            cout << "ZA MAŁO!\n";
        } else {
            cout << "Gratulacje! Zgadłeś liczbę w " << licznik_prob << " próbach.\n";
        }
    } while (proba != liczba);
}
int main() {
    zgadywankaLiczbowa();
    return 0;
}