/*
 *
 * Assumindo que R1 e R2 formam um divisor de tensão (R2 paralelo a Vout).
 * Dado conjunto de valores iniciais, calcule o valor do elemento informado como zero, ou diga que é impossivel calcular.
 *
 */


#include <iostream>

using namespace std;

int main()
{
    float r1, r2, vin, vout;

    cout << "Entrada de valores: digite 0 para o valor que deseja calcular." << endl << endl;

    cout << "Entre o valor de R1: ";
    cin >> r1;
    cout << "Entre o valor de R2: ";
    cin >> r2;
    cout << "Entre o valor de Vin: ";
    cin >> vin;
    cout << "Entre o valor de Vout: ";
    cin >> vout;

    int zerados = 0;
    if(r1 == 0) zerados++;
    if(r2 == 0) zerados++;
    if(vin == 0) zerados++;
    if(vout == 0) zerados++;

    if(zerados == 0){
        cout << endl << "Erro: nenhum valor e igual a zero. Qual valor voce deseja calcular?" << endl;
        return 0;
    }

    if(zerados > 1){
        cout << endl << "Erro: mais de um valor e igual a zero. Qual valor voce deseja calcular?" << endl;
        return 0;
    }

    // vout = vin*r2/(r1+r2);
    cout << endl;

    if(r1 == 0){
        r1 = (vin*r2/vout) - r2;
        cout << "Valor a ser calculado: R1 = " << r1 << " ohms." << endl;
    }

    if(r2 == 0){
        r2 = vout * r1/(vin-vout);
        cout << "Valor a ser calculado: R2 = " << r2 << " ohms." << endl;
    }

    if(vin == 0){
        vin = vout * (r1+r2) / r2;
        cout << "Valor a ser calculado: Vin = " << vin << "V." << endl;
    }

    if(vout == 0){
        vout = vin * r2 / (r1+r2);
        cout << "Valor a ser calculado: Vout = " << vout << "V." << endl;
    }

}
