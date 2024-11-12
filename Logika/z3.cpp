//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
using namespace std;
bool implikacja(bool p, bool q) {
    return !p || q;
}
bool rownowaznosc(bool p, bool q) {
    return p == q;
}
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
    bool p = true;
    bool q = false;
    bool r = true;
    ocena_zdan(p, q, r);

    return 0;
}
