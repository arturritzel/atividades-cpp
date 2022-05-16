/*
 *
 * 1.  Assumindo que R1 e R2 formam um divisor de tensão (R2 paralelo a Vout).
 * Dado valores de R1, R2 e Vin, calcule Vout.
 *
 */


#include <iostream>

using namespace std;

int main()
{
    int r1, r2, vin, vout;

    cout << "Entre o valor do resistor 1: ";
    cin >> r1;
    cout << "Entre o valor do resistor 2: ";
    cin >> r2;
    cout << "Entre o valor de tensão da fonte: ";
    cin >> vin;

    vout = vin*r2/(r1+r2);

    cout << endl << "A tensão de saída será igual à " << vout << "V" << endl;

}
