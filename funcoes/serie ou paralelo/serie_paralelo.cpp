/*

Elabore uma função que receba 3 parâmetros :
R1 - valor do resistor 1
R2 - valor do resistor 2
Req - resistência equivalente

Considerando que Req é a resistencia equivalente da associação R1 e R2,
identifique a associação utilizada, informando através do valor de retorno da função

*/

#include <iostream>

using namespace std;

enum conexao_t {ERR=-1,   // erro de parametros / valores
                SERIE=1, // conexao serie
                PARALELO};  // conexao paralelo

conexao_t testeConexao(float r1, float r2, float req){
    if(r1 <= 0 || r2 <= 0 || req <= 0){
        return ERR;
    }
    if(req == r1+r2){
        return SERIE;
    }

    float prl = (r1 * r2)/(r1 + r2);

    if(req <= prl * 1.05 && req >= prl * 0.95){
        return PARALELO;
    }
    return ERR;
}

int main()
{
    cout << "descobrindo o tipo de conexao:" << endl;

    cout << "digite o valor do resistor 1: " << endl;
    float r1;
    cin >> r1;

    cout << "digite o valor do resistor 2: " << endl;
    float r2;
    cin >> r2;

    cout << "digite a resistencia equivalente: " << endl;
    float req;
    cin >> req;

    cout << endl;
    conexao_t teste = testeConexao(r1, r2, req);
    switch(teste){
    case SERIE:
        cout << "a associacao e de resistores em serie" << endl;
        break;

    case PARALELO:
        cout << "a associacao e de resistores em paralelo" << endl;
        break;

    default:
        cout << "erro: valores não condizentes" << endl;
    }
}
