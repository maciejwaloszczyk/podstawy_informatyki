//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

// Funkcja do generowania losowych wartości w tablicy
void wypelnijTablice(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = rand() % 1000 + 1;
    }
}

// Sortowanie bąbelkowe (Bubble Sort)
void sortowanieBabelkowe(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                swap(tablica[j], tablica[j + 1]);
            }
        }
    }
}

// Sortowanie przez wybór (Selection Sort)
void sortowanieWyborem(int* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < rozmiar; ++j) {
            if (tablica[j] < tablica[minIndex]) {
                minIndex = j;
            }
        }
        swap(tablica[i], tablica[minIndex]);
    }
}

// Sortowanie szybkie (Quick Sort)
int partycja(int* tablica, int niskie, int wysokie) {
    int pivot = tablica[wysokie];
    int i = niskie - 1;
    for (int j = niskie; j < wysokie; ++j) {
        if (tablica[j] < pivot) {
            i++;
            swap(tablica[i], tablica[j]);
        }
    }
    swap(tablica[i + 1], tablica[wysokie]);
    return i + 1;
}

void sortowanieSzybkie(int* tablica, int niskie, int wysokie) {
    if (niskie < wysokie) {
        int pi = partycja(tablica, niskie, wysokie);
        sortowanieSzybkie(tablica, niskie, pi - 1);
        sortowanieSzybkie(tablica, pi + 1, wysokie);
    }
}

// Sortowanie przez kopcowanie (Heap Sort)
void kopcowanie(int* tablica, int rozmiar, int korzen) {
    int najwiekszy = korzen; // Inicjalizujemy największy jako korzeń
    int lewy = 2 * korzen + 1; // Lewy = 2*i + 1
    int prawy = 2 * korzen + 2; // Prawy = 2*i + 2

    // Sprawdzenie, czy lewy syn jest większy od korzenia
    if (lewy < rozmiar && tablica[lewy] > tablica[najwiekszy]) {
        najwiekszy = lewy;
    }

    // Sprawdzenie, czy prawy syn jest większy od największego do tej pory
    if (prawy < rozmiar && tablica[prawy] > tablica[najwiekszy]) {
        najwiekszy = prawy;
    }

    // Jeśli największy nie jest korzeniem, zamień je
    if (najwiekszy != korzen) {
        swap(tablica[korzen], tablica[najwiekszy]);
        // Rekurencyjnie kopcuj poddrzewo
        kopcowanie(tablica, rozmiar, najwiekszy);
    }
}

void sortowanieKopcowanie(int* tablica, int rozmiar) {
    // Budowanie kopca (przy użyciu odwróconego sortowania)
    for (int i = rozmiar / 2 - 1; i >= 0; i--) {
        kopcowanie(tablica, rozmiar, i);
    }
    // Jeden po drugim wydobywaj elementy z kopca
    for (int i = rozmiar - 1; i >= 0; i--) {
        swap(tablica[0], tablica[i]); // Przenieś bieżący korzeń na koniec
        kopcowanie(tablica, i, 0); // Wywołaj funkcję kopcowania na zmniejszonym kopcu
    }
}

// Funkcja do mierzenia czasu działania dla sortowania bąbelkowego
void mierzenieCzasuSortowaniaBabelkowego(int* tablica, int rozmiar) {
    int* kopia = new int[rozmiar];
    copy(tablica, tablica + rozmiar, kopia);  // Tworzymy kopię tablicy

    auto start = chrono::high_resolution_clock::now();
    sortowanieBabelkowe(kopia, rozmiar);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> czas = end - start;

    cout << "\tSortowanie bąbelkowe czas: " << czas.count() << " sekund" << endl;

    delete[] kopia;
}

// Funkcja do mierzenia czasu działania dla sortowania przez wybór
void mierzenieCzasuSortowaniaWyborem(int* tablica, int rozmiar) {
    int* kopia = new int[rozmiar];
    copy(tablica, tablica + rozmiar, kopia);  // Tworzymy kopię tablicy

    auto start = chrono::high_resolution_clock::now();
    sortowanieWyborem(kopia, rozmiar);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> czas = end - start;

    cout << "\tSortowanie przez wybór czas: " << czas.count() << " sekund" << endl;

    delete[] kopia;
}

// Funkcja do mierzenia czasu działania dla sortowania szybkiego
void mierzenieCzasuSortowaniaSzybkiego(int* tablica, int rozmiar) {
    int* kopia = new int[rozmiar];
    copy(tablica, tablica + rozmiar, kopia);  // Tworzymy kopię tablicy

    auto start = chrono::high_resolution_clock::now();
    sortowanieSzybkie(kopia, 0, rozmiar - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> czas = end - start;

    cout << "\tSortowanie szybkie czas: " << czas.count() << " sekund" << endl;

    delete[] kopia;
}

// Funkcja do mierzenia czasu działania dla sortowania przez kopcowanie
void mierzenieCzasuSortowaniaKopcowanie(int* tablica, int rozmiar) {
    int* kopia = new int[rozmiar];
    copy(tablica, tablica + rozmiar, kopia);  // Tworzymy kopię tablicy

    auto start = chrono::high_resolution_clock::now();
    sortowanieKopcowanie(kopia, rozmiar);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> czas = end - start;

    cout << "\tSortowanie przez kopcowanie czas: " << czas.count() << " sekund" << endl;

    delete[] kopia;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Ustawienie ziarna dla rand()

    const int rozmiar = 1000;
    cout<<"Tablica "<<rozmiar<<" elementowa."<<endl;
    int* tablica = new int[rozmiar];
    wypelnijTablice(tablica, rozmiar);

    mierzenieCzasuSortowaniaBabelkowego(tablica, rozmiar);
    mierzenieCzasuSortowaniaWyborem(tablica, rozmiar);
    mierzenieCzasuSortowaniaSzybkiego(tablica, rozmiar);
    mierzenieCzasuSortowaniaKopcowanie(tablica, rozmiar);

    delete[] tablica;

    return 0;
}
