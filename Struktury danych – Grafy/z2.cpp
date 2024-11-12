//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;

int main() {
    int wierzcholki, krawedzie;
    cout << "Podaj liczbe wierzchołkow: ";
    cin >> wierzcholki;
    cout << "Podaj liczbe krawędzi: ";
    cin >> krawedzie;

    // Inicjalizacja macierzy sasiedztwa zerami
    int macierzSasiedztwa[wierzcholki][wierzcholki];
    for (int i = 0; i < wierzcholki; ++i) {
        for (int j = 0; j < wierzcholki; ++j) {
            macierzSasiedztwa[i][j] = 0;
        }
    }

    cout << "Podaj pary wierzchołkow (u v) dla kazdej krawędzi:" << endl;
    for (int i = 0; i < krawedzie; ++i) {
        int u, v;
        cin >> u >> v;
        macierzSasiedztwa[u][v] = 1;
        //macierzSasiedztwa[v][u] = 1;
    }
    cout << "Macierz sąsiedztwa:" << endl;
    for (int i = 0; i < wierzcholki; ++i) {
        for (int j = 0; j < wierzcholki; ++j) {
            cout << macierzSasiedztwa[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
