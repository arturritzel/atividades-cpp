/*

Elabore uma função que ordena (ordem crescente) um vetor numérico de inteiros.
parametros : vetor de dados
       quantidade de elementos
retorno :      nenhum

*/


#include <iostream>

using namespace std;

int main()
{
    cout << "Digite a quantidade de valores a ser entrado: ";
    int tamanho;
    cin >> tamanho;
    int valores[tamanho];

    // entrada
    for(int i = 0; i < tamanho; i++){
        cout << "Digite o valor " << i+1 << ": ";
        cin >> valores[i];
    }

    // testagem menor

    int menor = valores[0];

    for(int i = 0; i < tamanho; i++){
        if(valores[i] < menor){
            menor = valores[i];
        }
    }
    // ordenar
    int ordenado[tamanho];

    for (int i = 0; i < tamanho; ++i){
        for (int j = i + 1; j < tamanho; ++j){
            if (valores[i] > valores[j]){

                int temp = valores[i];
                valores[i] = valores[j];
                valores[j] = temp;

            }
        }
    }

    // printar ordem
    for(int i = 0; i < tamanho; i++){
        cout << valores[i] << ", ";
    }


}
