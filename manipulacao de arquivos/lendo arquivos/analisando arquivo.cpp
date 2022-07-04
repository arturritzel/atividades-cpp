/*
Abra um arquivo no formato txt contendo um texto. Analise o conteúdo
e gere o seguinte relatório (na tela).
a. Quantidade de caracteres espaço.
b. Quantidade de linhas do texto.
c. Quantidade de vogais.
d. Quantidade de artigos definidos.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <locale>

using namespace std;

/*
Modos de abertura Descrição
ios::in Abre para leitura (default de ifstream).
ios::out Abre para gravação (default de ofstream),
ios::ate Abre e posiciona no final do arquivo.
(Este modo trabalha com leitura e gravação)
ios::app Grava a partir do fim do arquivo
ios::trunc Abre e apaga todo o conteúdo do arquivo
ios::nocreate Erro de abertura se o arquivo não existe
ios::noreplace Erro de abertura se o arquivo existir
ios::binary Abre em binário (default é texto)
*/


#define MAXCHAR 200
#define LINHA

int main()
{
    cout << "digite o nome do arquivo" << endl;
    cout << "(digite tambem sua extensao. ex: \"texto_exemplo.txt\")" << endl;
    string arquivo;
    cin >> arquivo;
    //string arquivo = "texto_exemplo.txt";

  ifstream inFile; // inFile é o arquivo de leitura dos dados

  setlocale(LC_ALL,"");

  inFile.open(arquivo, ios::in); // abre o arquivo para leitura
  if (! inFile)
     { cerr << "Arquivo "<< arquivo << " nao pode ser aberto" << endl;
      return -1;
     }

    string palavra;
    int palavras = 0, artigos = 0;
    while (inFile >> palavra){
        palavras++;
        //if(strcmp(palavra,"dois") == 0) artigos++;
    }
    inFile.close();


    ///     contando vogais!!

    inFile.open(arquivo, ios::in);

    char letra;
    int vogais = 0;
    while (inFile >> letra){
            if(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
                vogais++;
    }

    inFile.close();

    /// contando linhas!

    inFile.open(arquivo, ios::in);

    char linha[MAXCHAR];
    int linhas = 0;
    while (inFile.getline(linha,MAXCHAR)){
            linhas++;
    }

    inFile.close();

    cout << endl << endl;
    cout << "quantidade de caracteres espaço: " << palavras-1-(linhas-1) << endl;
    cout << "quantidade de linhas: " << linhas << endl;
    cout << "quantidade de vogais: " << vogais << endl;
    cout << "quantidade de artigos definidos: " << "?" << endl;


 return 0;
 }
