//Maciej Waloszczyk - ITE-1sem WIMiIP 2024
#include<iostream>
#include<fstream>
#include <cstring>
#include <unordered_map>
#include <sstream>

using namespace std;

unordered_map<char, string> kodMorsea;
unordered_map<string, char> odwrotnyKodMorsea;

void szyfrCezara(int klucz, char tab[])
{
	int length = strlen(tab);
	if(!(klucz >= -26 && klucz <= 26)) return;
	if(klucz >= 0)
		for(int i=0;i<length;i++)
		if(tab[i] + klucz <= 'Z')
			tab[i] += klucz;
		else
			tab[i] = tab[i] + klucz - 26; 
	else
		for(int i=0;i<length;i++)
		if(tab[i] + klucz >= 'A')
			tab[i] += klucz;
		else
			tab[i] = tab[i] + klucz + 26;
}

string szyfrMorsea(const string& text) {
    string morseTekst;
    for (char c : text) {
        c = toupper(c);
        if (kodMorsea.find(c) != kodMorsea.end()) {
            morseTekst += kodMorsea[c] + " ";
        }
    }
    return morseTekst;
}

string deszyfrMorsea(const string& morseTekst) {
    stringstream ss(morseTekst);
    string symbolMorsea;
    string gotowyTekst;
    while (ss >> symbolMorsea) {
        if (odwrotnyKodMorsea.find(symbolMorsea) != odwrotnyKodMorsea.end()) {
            gotowyTekst += odwrotnyKodMorsea[symbolMorsea];
        } else if (symbolMorsea == "/") {
            gotowyTekst += ' ';
        }
    }
    return gotowyTekst;
}


int main()
{
    kodMorsea['A'] = ".-";   kodMorsea['B'] = "-..."; kodMorsea['C'] = "-.-.";
    kodMorsea['D'] = "-..";  kodMorsea['E'] = ".";    kodMorsea['F'] = "..-.";
    kodMorsea['G'] = "--.";  kodMorsea['H'] = "...."; kodMorsea['I'] = "..";
    kodMorsea['J'] = ".---"; kodMorsea['K'] = "-.-";  kodMorsea['L'] = ".-..";
    kodMorsea['M'] = "--";   kodMorsea['N'] = "-.";   kodMorsea['O'] = "---";
    kodMorsea['P'] = ".--."; kodMorsea['Q'] = "--.-"; kodMorsea['R'] = ".-.";
    kodMorsea['S'] = "...";  kodMorsea['T'] = "-";    kodMorsea['U'] = "..-";
    kodMorsea['V'] = "...-"; kodMorsea['W'] = ".--";  kodMorsea['X'] = "-..-";
    kodMorsea['Y'] = "-.--"; kodMorsea['Z'] = "--..";
    kodMorsea['1'] = ".----"; kodMorsea['2'] = "..---"; kodMorsea['3'] = "...--";
    kodMorsea['4'] = "....-"; kodMorsea['5'] = "....."; kodMorsea['6'] = "-....";
    kodMorsea['7'] = "--..."; kodMorsea['8'] = "---.."; kodMorsea['9'] = "----.";
    kodMorsea['0'] = "-----"; kodMorsea[' '] = "/";
    
    for (auto pair : kodMorsea) {
        odwrotnyKodMorsea[pair.second] = pair.first;
    }

    int program;
    string plik;
	int klucz;


    cout<<"Funkcje szyfrujące: "<<endl;
    cout<<"[1] Szyfr Cezara"<<endl;
    cout<<"[2] Szyfr Morse'a\n"<<endl;

    cout<<"Funkcje deszyfrujące: "<<endl;
    cout<<"[3] Szyfr Cezara"<<endl;
    cout<<"[4] Szyfr Morse'a"<<endl;

    cout<<"\nOpcja >> ";cin>>program;cout<<endl;
    if (program == 1){
    	char tab[1001];
	
	    cout<<"Podaj wyraz składający się z dużych liter: ";
    	cin>>tab;
	
	    cout<<"Podaj klucz z przedziału [-26..26]: ";
	    cin>>klucz;

	    szyfrCezara(klucz,tab); //szyfrowanie	
	    cout<<"Po zaszyfrowaniu: "<<tab<<endl;
        cout<<"Zapis do pliku: "; cin>>plik;
        ofstream zapis(plik);
        zapis<<tab;
        zapis.close();
    }
    else if(program == 2){
        string napis; 	
	    cout<<"Podaj napis składający się z dużych liter: ";
    	cin>>napis;
        string gotowyTekst = szyfrMorsea(napis);
        cout << "Zaszyfrowany tekst (Morse): " << gotowyTekst << endl;
        cout<<"Zapis do pliku: "; cin>>plik;
        ofstream zapis(plik);
        zapis<<gotowyTekst;
        zapis.close();

    }
    else if(program == 3){
        cout<<"Wpisz nazwę pliku: "; cin>>plik;
        cout<<"Podaj klucz tajny z przedziału [-26..26]: ";
	    cin>>klucz;
        ifstream odczyt(plik);
        string linia;
        getline(odczyt, linia);
        char tab[1001];
        strncpy(tab, linia.c_str(), sizeof(tab) - 1);
        tab[sizeof(tab) - 1] = '\0';
        cout << "Pierwsza linia jako tablica znaków: " << tab << endl;
        szyfrCezara(-klucz,tab); //deszyfrowanie
	    cout<<"Po rozszyfrowaniu: "<<tab<<endl;
    }
    else if(program == 4){
        cout<<"Wpisz nazwę pliku: "; cin>>plik;
        ifstream odczyt(plik);
        string linia;
        getline(odczyt, linia);
        string gotowyTekst = deszyfrMorsea(linia);
        cout << "Odszyfrowany tekst: " << gotowyTekst << endl; 
    }
    else{
        cout<<"Błąd\n";
    }

	return 0;
}