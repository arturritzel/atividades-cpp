/* *******************************************************************
 @brief   calcula a partir de uma base de dados o dia com maior
          media movel de casos de covid-19
 @file    main.cpp
 @author  Artur Ritzel
 @date    maio/2022
 @version 1
******************************************************************** */

#include <iostream>,

using namespace std;
/***

Novos casos covid-19 Brasil
Data inicial : 01/04/2022
Fonte : https://ourworldindata.org/

***/

#define DATA_INI "01/04/2022"
const float casosCovidBR[]={26843.0,17062.0,7210.0,12572.0,26915.0,26822.0,26234.0,30212.0,21229.0,7210.0,7930.0,
                            22377.0,26648.0,23090.0,13278.0,2775.0,2541.0,8470.0,14131.0,36750.0,18660.0,8068.0,
                            7111.0,3655.0,6456.0,22142.0,20943.0,19916.0,14122.0,15194.0,6498.0,21432.0,20072.0,
                            21682.0,19725.0,14622.0,6006.0};


/****************************
Como indicador de evolucao da epidemia de covid-19 utilizou-se (entre outros), o numero de novos casos dia.
Para avaliar de forma mais apropriada, calcula-se a media movel de novos casos/dia.

A media movel consiste em considerar o valor do dia como a media dos N dias anteriores

Este codigo tem por objetivo analisar os dados referentes a covid-19, identificando o dia de maior crescimento e a tendenciatual

Complete o codigo, seguindo as orientacoes dadas em aula.


****************************/

//! tipo dado ivet_t - estrutura para armazenamento de vetores
struct fvet_t {
              float *dado=nullptr;       //!< ponteiro para area dados
              unsigned int nitens=0;  //!< numero de elementos vetor
              };


//! tipo dado el_ivet_t - valor de um elemento e sua posicao
struct el_fvet_t {
              float v=0;          //!< valor do elemento
              unsigned int p=0; //!< posicao do elemento
              };


//! tipo dado ivetERR_t - enumeracao codigos erro retorno funcoes usam ivet_t
enum fvetERR_t {E_ERR=-3, //!< vetor nao inicializado
                P_ERR,    //!< valor de parametros invalidos
                M_ERR,    //!< erro de memoria
                OK=0      //!< sucesso na execucao
                };

/// FUNCOES

/*************************************************
* @brief inicializa vetor
* @param vetor
* @param numero de elementos da estrutura
* @param vetor com valores iniciais
* @retval M_ERR se faltou memoria na alocacao
*          OK se sucesso
* Aloca memoria para vetor e registra valor de n
*************************************************/
fvetERR_t cria(fvet_t &v, int n,const float valorInicial[])
{
v.nitens=n;           // acertando numero de itens
v.dado = new float [n]; // alocando memoria para os itens

if (v.dado==nullptr)  // alocacao deu errado, avisa
    return M_ERR;

for (int i=0;i<n;i++)
    v.dado[i]=valorInicial[i];

return OK;
}

/**************************************************
* @brief exibe vetor
* @param vetor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
fvetERR_t exibe(fvet_t &v)
{
    // checando consistencia vetor
    if (v.nitens < 1 || v.dado==nullptr) // vetor foi inicializado ?
            return E_ERR;
    for (unsigned int i=0; i<v.nitens;i++)
        cout << v.dado[i] << "  ";
    cout << endl;
   return OK;
}

/*************************************************
* @brief desaloca memora do vetor
* @param vetor tipo ivet_t
* @retval nenhum
* Libera memoria  alocada para vetor
*************************************************/

void destroi(fvet_t &v)
{

delete (v.dado);
v.nitens=0;
}


/**********************************************
* @brief  preenche vetor com um valor constante
* @param  vetor tipo ivet_t
* @param  valor constante
* @retval OK se sucesso
***********************************************/
fvetERR_t preenche(fvet_t &v, float valor)
{
    // checando consistencia vetor
    if (v.nitens < 1 || v.dado==nullptr) // vetor foi inicializado ?
            return E_ERR;

    for (unsigned int i=0; i<v.nitens;i++)
        v.dado[i]=valor;

return OK;
}

/**********************************************
* @brief  calcula a media movel do vetor v considerando mm elementos
* @param  dados entrada
* @param  media movel
* @param  numero de itens a considerar para a media movel
* @retval OK se sucesso
***********************************************/
fvetERR_t mediaMovel(fvet_t &v, fvet_t &vmm,int mm)
{
    for(int i = 0; i < 35; i++){
        if(i < mm-1){
            vmm.dado[i] = 0;
        }
        else{
            int totalAntesDivisao = 0, totalDepoisDivisao = 0;

            for(int j = 0; j < mm; j++){
                totalAntesDivisao = totalAntesDivisao + v.dado[i-j];
            }

            totalDepoisDivisao = totalAntesDivisao / mm;
            vmm.dado[i] = totalDepoisDivisao;
        }
    }

return OK;
}


/**************************************************
* @brief encontra maior valor do vetor
* @param vetor
* @param valor e posicao maior valor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
fvetERR_t maiorValor(fvet_t v,el_fvet_t &maior)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    maior.p = 0;
    maior.v = v.dado[0];

    for(int i = 0; i < v.nitens; i++){
        if(v.dado[i] > maior.v){
            maior.p = i;
            maior.v = v.dado[i];
        }
    }

    return OK;
}

/// MAIN

int main()
{


cout << "Covid-19 Brasil\nAnalise a partir de " << DATA_INI << endl;

fvet_t novosCovid;
el_fvet_t maisCasos;
fvet_t MnovosCovid;

if(cria(novosCovid, 35 , casosCovidBR) == M_ERR){ /// cria um vetor com os valores dos novos casos de covid
    cout << "erro de memoria" << endl;
    return 1;
}

/*
if(exibe(novosCovid) == E_ERR){ /// exibe esse vetor/           //////// debug
    cout << "erro; vetor vazio" << endl; ///                    //////// debug
}                   ///                                         //////// debug
// */

if(cria(MnovosCovid, 35, casosCovidBR) == M_ERR){ /// cria um vetor para a media movel de casos
    cout << "erro de memoria" << endl;
    return 0;
}

mediaMovel(novosCovid, MnovosCovid,5); /// define os valores para o vetor com a media movel de casos

/*
cout << "MEDIA MOVEL" << endl;
if(exibe(MnovosCovid) == E_ERR){ /// exibe esse vetor/           //////// debug
    cout << "erro; vetor vazio" << endl; ///                    //////// debug
}                   ///                                         //////// debug
// */

if(maiorValor(MnovosCovid,maisCasos) == E_ERR){
    cout << "erro; vetor vazio" << endl;
    return 0;
}

cout << "O maior numero de casos do periodo foi de " << maisCasos.v << " ocorridos no " << maisCasos.p+1 << "o dia." << endl;
}
