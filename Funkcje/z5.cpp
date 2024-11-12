//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib>
#include <ctime>        
#include <unistd.h>     
using namespace std;
int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    cout << "Totolotek:\n";
    
    for (int i = 0; i < 6; ++i) {
        int liczba = rand() % 49 + 1;
        cout << "Liczba nr " << i+1 << ": " <<liczba << endl;
        sleep(1);
    }

    return 0;
}