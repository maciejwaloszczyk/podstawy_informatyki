//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include <iostream>
#include <cstdlib> 
using namespace std;
int main() {
    int program;
    cout<<"Wybierz program [1-5]: ";
    cin>>program;cout<<endl;
    switch(program){
        case 1:
            system("clang++ ../Instrukcje\\ warunkowe\\,\\ pętle\\,\\ schematy\\ blokowe/z1.cpp -o z1");
            system("./z1");
            break;
        case 2:
            system("clang++ ../Instrukcje\\ warunkowe\\,\\ pętle\\,\\ schematy\\ blokowe/z2.cpp -o z2");
            system("./z2");
            break;
        case 3:
            system("clang++ ../Instrukcje\\ warunkowe\\,\\ pętle\\,\\ schematy\\ blokowe/z3.cpp -o z3");
            system("./z3");
            break;
        case 4:
            system("clang++ ../Instrukcje\\ warunkowe\\,\\ pętle\\,\\ schematy\\ blokowe/z4.cpp -o z4");
            system("./z4");        
            break;
        case 5:
            system("clang++ ../Instrukcje\\ warunkowe\\,\\ pętle\\,\\ schematy\\ blokowe/z5.cpp -o z5");
            system("./z5");
            break;
        case 6:
            return 0;
        default:
            cout<<"Błąd!"<<endl;           
    }
    return 0;
}