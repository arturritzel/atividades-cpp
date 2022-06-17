/*

Uma pesquisa visa levantar a quantidade de televisores presentes nos lares.
Para tanto são realizadas consultas a pessoas em locais públicos.
Para auxiliar esta pesquisa, elabore um programa para gerar o relatório diário de cada pesquisador.

O programa consiste das seguintes tarefas:
    - Identificação do número de questionários respondidos no dia.
    - Registro individual do número de televisores de cada questionario,
    em um vetor do exato tamanho da quantidade de questionários respondidos.

    Gere um relatorio (no console), informando :
        A quantidade de respostas do dia
        A quantidade de residências sem televisor
        A média de televisores/residenciais, desconsiderando as residencias sem televisor.

*/


#include <iostream>

using namespace std;

int main()
{
    cout << "digite o numero de pesquisas feitas hoje: ";
    int p_qtd; // pesquisas quantidade
    cin >> p_qtd;
    cout << endl;

    int form[p_qtd];

    // entrada
    for(int i = 0; i < p_qtd; i++){
        cout << "televisoes na residencia " << i+1 << ": ";
        cin >> form[i];
    }

    // calculo sem tv/media com tv
    int qts = 0; //quantidade sem
    int qtc = 0; //quantidade com
    int total = 0;

    for(int i = 0; i < p_qtd; i++){
        if(form[i] == 0){
            qts++;
        }
        if(form[i] != 0){
            qtc++;
            total = total + form[i];
        }
    }

    float totalfloat = total, qtcfloat = qtc, media = totalfloat/qtcfloat;

    // print
    cout << endl;
    cout << "numero de pesquisas feitas: " << p_qtd << endl;
    cout << endl;
    cout << "numero de residencias sem tv: " << qts << endl;
    cout << endl;
    cout << "media de tv em casas com tv: " << media << endl;
    cout << endl;
}
