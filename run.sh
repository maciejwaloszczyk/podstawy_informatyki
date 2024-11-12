#!/bin/bash

# Funkcja pomocnicza do wyświetlania komunikatu o użyciu
usage() {
    echo "Użycie: $0 -f <wartość>"
    exit 1
}

# Sprawdzanie argumentów
while getopts ":f:" opt; do
    case $opt in
        f)
            wartosc="$OPTARG"  # Przypisz wartość do zmiennej
            ;;
        \?)
            echo "Nieznany opcja: -$OPTARG" >&2
            usage
            ;;
        :)
            echo "Opcja -$OPTARG wymaga wartości." >&2
            usage
            ;;
    esac
done

# Sprawdź, czy zmienna wartosc jest ustawiona
if [ -z "$wartosc" ]; then
    echo "Wartość -f nie została podana." >&2
    usage
fi

# Wyświetl pobraną wartość
echo "Kompilator clang++  -  plik: $wartosc"
clang++ $wartosc -o runner.out -w
./runner.out
rm -rf ./runner.out
