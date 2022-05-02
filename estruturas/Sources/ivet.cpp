/*************************************************************
* @brief   funcoes manipulacao e operacao vetores tipo ivet_t
* @file    ivet.cpp
* @author  MZ & Artur Ritzel
* @date    abril/2022
* @version 0.1
*************************************************************/

#include <iostream>
#include "ivet.hpp"
#include <time.h>

using namespace std;

/************************************************************
* Este eh o arquivo-fonte que implementa as funcoes utilizadas
* na manipulacao e operacao de vetores ivet
*
* Complete as funcoes de forma que realizem as tarefas especificads
* atraves dos comentarios localizados no inicio da funcao
* Atente aos parametros recebidos e ao retorno esperado
* Realize adequada documentacao do codigo :
*    - Escolha de nome de variaveis / defines / funcoes adequado
*    - Comentarios em estruturas de codigo com funcionalidades especificas
*
* Implemente o teste das funcoes no arquivo teste_ivet.cpp
***********************************************************/




/*************************************************
* @brief inicializa vetor
* @param vetor
* @param numero de elementos da estrutura
* @retval M_ERR se faltou memoria na alocacao
*          OK se sucesso
* Aloca memoria para vetor e registra valor de n
*************************************************/

ivetERR_t cria(ivet_t &v, int n)
{
v.nitens=n;           // acertando numero de itens
v.dado = new int [n]; // alocando memoria para os itens

if (v.dado==nullptr)  // alocacao deu errado, avisa
    return M_ERR;

preenche(v,0);        // zerando todos os elementos

return OK;
}

/*************************************************
* @brief desaloca memora do vetor
* @param vetor tipo ivet_t
* @retval nenhum
* Libera memoria  alocada para vetor
*************************************************/

void destroi(ivet_t &v)
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
ivetERR_t preenche(ivet_t &v, int valor)
{
    // checando consistencia vetor
    if (v.nitens < 1 || v.dado==nullptr) // vetor foi inicializado ?
            return E_ERR;

    for (unsigned int i=0; i<v.nitens;i++)
        v.dado[i]=valor;

return OK;
}


/***************************************************
* @brief  preenche vetor com um valores aleatorios
* @param  vetor
* @param  valor minimo faixa sorteio
* @param  valor maximo faixa sorteio
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/

ivetERR_t sorteia(ivet_t v, int vmin, int vmax)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    for(int i = 0; i < v.nitens; i++){
        v.dado[i] = vmin + rand() % (vmax+1 - vmin);
    }

return OK;
}

/***************************************************
* @brief ordena vetor ordem crescente
* @param vetor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/

ivetERR_t ordena_cresc(ivet_t v)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    for(int i = 0; i < v.nitens; i++){
        for(int j = i + 1; j < v.nitens; j++){
            if(v.dado[i] > v.dado[j]){
                int temp = v.dado[i];
                v.dado[i] = v.dado[j];
                v.dado[j] = temp;
            }
        }
    }

return OK;
}


/***************************************************
* @brief ordena vetor ordem decrescente
* @param vetor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
ivetERR_t ordena_dec(ivet_t v)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    for(int i = 0; i < v.nitens; i++){
        for(int j = i + 1; j < v.nitens; j++){
            if(v.dado[i] < v.dado[j]){
                int temp = v.dado[i];
                v.dado[i] = v.dado[j];
                v.dado[j] = temp;
            }
        }
    }

return OK;
}


/**************************************************
* @brief exibe vetor
* @param vetor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
ivetERR_t exibe(ivet_t &v)
{
    // checando consistencia vetor
    if (v.nitens < 1 || v.dado==nullptr) // vetor foi inicializado ?
            return E_ERR;
    for (unsigned int i=0; i<v.nitens;i++)
        cout << v.dado[i] << "  ";
    cout << endl;
   return OK;
}

/**************************************************
* @brief exibe vetor
* @param vetor
* @param numero elementos / linha
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
ivetERR_t exibe(ivet_t &v, int elemLinha )
{
        // checando consistencia vetor
    if (v.nitens < 1 || v.dado==nullptr) // vetor foi inicializado ?
            return E_ERR;

    int novalinha=elemLinha;

    for (unsigned int i=0; i<v.nitens;i++)
    {
        cout << v.dado[i] << "  ";
        if (--novalinha==0)       // se o numero de itens/linha jah foi exibido
        {
            cout << endl;
            novalinha=elemLinha;
        }
    }

   if (novalinha!=elemLinha) // se não finalizou com nova linha, vamos finalizar
        {
            cout << endl;
        }


    return OK;
}


/**************************************************
* @brief soma todos os valores contidos no vetor
* @param vetor
* @param total do somatorio
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
ivetERR_t totaliza(ivet_t &v,int &total)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    total = 0;
    for(int i = 0; i < v.nitens; i++){
        total = total + v.dado[i];
    }

    return OK;

}
/**************************************************
* @brief soma dois vetores (elemento a elemento)
* @param vetor resultado do somatorio
* @param vetor operando 1
* @param vetor operando 2
* @retval E_ERR para vetor vazio
*         P_ERR se os vetores nao tem o mesmo tamanho
*         OK se sucesso
* adequar tamanho do vetor resultado
****************************************************/
ivetERR_t soma(ivet_t &resultado,ivet_t v1,ivet_t v2)
{
    // checagem de erros
    if(v1.nitens != v2.nitens){
        return P_ERR;
    }
    if(v1.nitens <= 0 || v1.dado==nullptr){
        return E_ERR;
    }
    if(v2.nitens <= 0 || v2.dado==nullptr){
        return E_ERR;
    }

    // adequando tamanho do resultado
    destroi(resultado);
    cria(resultado, v1.nitens);

    // somando
    for(int i = 0; i < resultado.nitens; i++){
        resultado.dado[i] = v1.dado[i] + v2.dado[i];
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
ivetERR_t maiorValor(ivet_t v,el_ivet_t &maior)
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
/**************************************************
* @brief encontra menor valor do vetor
* @param vetor
* @param valor e posicao maior valor
* @retval E_ERR para vetor vazio
*         OK se sucesso
****************************************************/
ivetERR_t menorValor(ivet_t v,el_ivet_t &menor)
{
    if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
    }

    menor.p = 0;
    menor.v = v.dado[0];

    for(int i = 0; i < v.nitens; i++){
        if(v.dado[i] < menor.v){
            menor.p = i;
            menor.v = v.dado[i];
        }
    }

    return OK;
}
/**************************************************
* @brief adiciona um item ao final do  vetor
* @param vetor
* @param valor do item adicionado
* @retval E_ERR para vetor vazio
*         M_ERR se faltou memoria na alocacao
*         OK se sucesso
****************************************************/
ivetERR_t acrescenta(ivet_t &v,int valor)
{
    int bkp[v.nitens + 1];
    for(int i = 0; i < v.nitens; i++){
        bkp[i] = v.dado[i];
    }

    bkp[v.nitens] = valor;

    v.nitens = v.nitens + 1;
    v.dado = new int [v.nitens];

    for(int i = 0; i < v.nitens; i++){
        v.dado[i] = bkp[i];
    }

    return OK;
}
/**************************************************
* @brief  elimina um item do  vetor
* @param  vetor
* @param  item a ser eliminado
* @retval E_ERR para vetor vazio
*         M_ERR se faltou memoria na alocacao
*         OK se sucesso
****************************************************/
ivetERR_t retira(ivet_t &v,int pos)
 {
     if(v.nitens <= 0 || v.dado==nullptr){
        return E_ERR;
     }

    int bkp[v.nitens - 1];

    for(int i = 0; i < pos; i++){
        bkp[i] = v.dado[i];
    }
    for(int i = pos+1; i < v.nitens; i++){
        bkp[i-1] = v.dado[i];
    }


    v.nitens = v.nitens - 1;
    v.dado = new int [v.nitens];

    for(int i = 0; i < v.nitens; i++){
        v.dado[i] = bkp[i];
    }


     return OK;
 }
