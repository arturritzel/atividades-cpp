#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <locale>
#include <cmath>

using namespace std;

int main()
{
    string nomeArq = "senoide.txt";
    ofstream arquivo;

    arquivo.open(nomeArq, ios::out);
    if(! arquivo){
        cout << "nao deu pra abrir";
        return - 1;
    }

    ///

    cout << "Calculando os valores de uma senoide:\n";
    cout << "Digite a quantidade de pontos que deseja calcular: ";
    int qtd;
    cin >> qtd;


    float ponto_x[qtd], ponto_y[qtd];

    arquivo << "Calculando " << qtd << " pontos de uma senoide;" << endl;
    arquivo << "metodo 1:\n";

    for(int i = 0; i < qtd; i++){
        float mult = i;
        ponto_x[i] = (mult/4) * M_PI;

        ponto_y[i] = round(std::sin(ponto_x[i])*1000)/1000;
        arquivo << "x = " << mult/4 << "pi : " << "y = " << ponto_y[i] << endl;
    }

    arquivo << "\nmetodo 2:\n";

    for(int i = 0; i < qtd; i++){
        float mult = i;
        ponto_x[i] = i;

        ponto_y[i] = round(std::sin(ponto_x[i])*1000)/1000;
        arquivo << "x = " << ponto_x[i] << " : " << "y = " << ponto_y[i] << endl;
    }

    arquivo.close();

    cout << "\nArquivo pronto." << endl;


}
