#include <iostream>
using namespace std;

// Funkcja dla operacji implikacji
bool implikacja(bool p, bool q) {
    return !p || q;
}

// Funkcja dla operacji równoważności
bool rownowaznosc(bool p, bool q) {
    return p == q;
}

// Funkcja obliczająca wartości zdań złożonych na podstawie p, q, r
void ocena_zdan(bool p, bool q, bool r) {
    cout << "a) p ∧ q: " << (p && q) << endl;
    cout << "b) p ∨ q: " << (p || q) << endl;
    cout << "c) ¬p ∧ (p ∨ q): " << (!p && (p || q)) << endl;
    cout << "d) (p ∧ r) → q: " << implikacja(p && r, q) << endl;
    cout << "e) ¬(p ↔ (q ∨ r)): " << !rownowaznosc(p, (q || r)) << endl;
    cout << "f) [(p → r) ∨ ¬q] ↔ [p → (r ∧ ¬q)]: " << rownowaznosc((implikacja(p, r) || !q), implikacja(p, (r && !q))) << endl;
    cout << "g) [(¬r ∨ q) ∨ ¬(q ∧ r)] → [¬(q → p)]: " << implikacja((!r || q) || !(q && r), !implikacja(q, p)) << endl;
}

int main() {
    // Przykład użycia
    bool p = true;
    bool q = false;
    bool r = true;

    ocena_zdan(p, q, r);

    return 0;
}