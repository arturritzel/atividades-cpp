/*

Elabore uma função que identifique o maior valor em um vetor de inteiros.
parametros : vetor de dados
	        quantidade de elementos
retorno :      maior valor contido neste vetor


*/


#include <iostream>

using namespace std;

int main()
{
    cout << "Digite o numero de valores a ser entrado: ";
    int tamanho;
    cin >> tamanho;
    int valores[tamanho];

    // entrada
    for(int i = 0; i < tamanho; i++){
        cout << "Digite o valor " << i+1 << ": ";
        cin >> valores[i];
    }

    // testagem
    int maior = valores[0];

    for(int i = 0; i < tamanho; i++){
        if(valores[i] > maior){
            maior = valores[i];
        }
    }

    cout << endl << "maior valor: " << maior << endl;
}
