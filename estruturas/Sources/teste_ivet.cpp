/* *******************************************************************
 @brief   testa funcoes de manipulacao ivet_t
 @file    teste_ivet.cpp
 @author  MZ & Artur Ritzel
 @date    abril/2022
 @version 0.1
******************************************************************** */

#include <iostream>
#include "ivet.hpp"
#include "time.h"

using namespace std;


int main(void)
{
    srand(time(0));
    srand(rand() % time(0));

    ivet_t vetor;   //!< vetor tipo ivet usado nos testes
    // Testando criacao
    if (cria(vetor,5)==M_ERR)
    {
        cerr << "Falha alocacao memoria" << endl;
        return -1;
    }
    cout << "Vetor criado !\n" << endl;

    // Vamos preencher
    if (preenche(vetor,23769)==E_ERR)
    {
        cerr << "vetor VAZIO\n" << endl;
    }
    else
        cout << "Preenchimento feito !\n" << endl;

    // exibindo
      cout << "\nExibindo vetor : " << endl;
    if (exibe(vetor)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;

    // destruindo
    destroi(vetor);
    cout << "vetor destruido!" << endl;

    // exibindo
      cout << "\nExibindo vetor :  "<< endl;
    if (exibe(vetor)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;

    // Criando novamente
    cout << "criando novamente:" << endl;
    if (cria(vetor,5)==M_ERR)
    {
        cerr << "Falha alocacao memoria" << endl;
        return -1;
    }
    cout << "Vetor criado !\n" << endl;


 // Vamos preencher novamente
    preenche(vetor,69); // se funcionou antes, assumi que vai funcionar

    // exibindo
      cout << "\nExibindo vetor :" << endl;
    if (exibe(vetor,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;

    // divisor
    cout << "===========================" << endl << endl;
    // divisor

// sorteia

    cout << "sorteando" << endl;
    if(sorteia(vetor, 0, 99) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    // exibindo
      cout << "\nExibindo vetor :" << endl;
    if (exibe(vetor,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;

    // totalizando
    cout << "total: ";
    int total;
    if(totaliza(vetor, total) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    else{
        cout << total << endl << endl;
    }

    // ordenar cresc
    cout << "ordenando (crescente)" << endl;
    if(ordena_cresc(vetor) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    // exibindo
      cout << "\nExibindo vetor :" << endl;
    if (exibe(vetor,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;

    // ordenar decresc
    cout << "ordenando (decrescente)" << endl;
    if(ordena_dec(vetor) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    // exibindo
      cout << "\nExibindo vetor :" << endl;
    if (exibe(vetor,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;
    else
        cout << endl;


    // divisor
    cout << "===========================" << endl << endl;
    // divisor





    cout << "=== SOMANDO ===" << endl;
    ivet_t vetor_aux, vetor_resultado;

    //criando vetor aux
    if (cria(vetor_aux,5)==M_ERR)
    {
        cerr << "Falha alocacao memoria" << endl;
        return -1;
    }
    cout << "vetor auxiliar criado!\n" << endl;

    //criando vetor resultado
    if (cria(vetor_aux,5)==M_ERR)
    {
        cerr << "Falha alocacao memoria" << endl;
        return -1;
    }
    cout << "vetor resultado criado!\n" << endl;

    //definindo vetor aux

    cout << "sorteando" << endl;
    if(sorteia(vetor_aux, 0, 99) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    // criando struct pra maior/menor valor
    el_ivet_t maiormenor;

    // exibindo
      cout << "\nvetores: " << endl;

    // exibindo vetor principal
    cout << "1: ";
    if (exibe(vetor,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;

    if(maiorValor(vetor, maiormenor) == E_ERR){
        cerr << "vetor VAZIO\n" << endl;
    }
    else{
        cout << "maior valor: " << maiormenor.v << " / posicao " << maiormenor.p << endl;
    }

    if(menorValor(vetor, maiormenor) == E_ERR){
        cerr << "vetor VAZIO\n" << endl;
    }
    else{
        cout << "menor valor: " << maiormenor.v << " / posicao " << maiormenor.p << endl;
    }

    cout << "total: ";
    if(totaliza(vetor, total) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    else{
        cout << total << endl << endl;
    }

    // exibindo vetor aux
    cout << "2: ";
    if (exibe(vetor_aux,5)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;

    if(maiorValor(vetor_aux, maiormenor) == E_ERR){
        cerr << "vetor VAZIO\n" << endl;
    }
    else{
        cout << "maior valor: " << maiormenor.v << " / posicao " << maiormenor.p << endl;
    }

    if(menorValor(vetor_aux, maiormenor) == E_ERR){
        cerr << "vetor VAZIO\n" << endl;
    }
    else{
        cout << "menor valor: " << maiormenor.v << " / posicao " << maiormenor.p << endl;
    }

    cout << "total: ";
    if(totaliza(vetor_aux, total) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    else{
        cout << total << endl << endl;
    }

    // somando
    cout << "somando:" << endl;
    if(soma(vetor_resultado, vetor, vetor_aux) == E_ERR || soma(vetor_resultado, vetor, vetor_aux) == P_ERR){
        if(soma(vetor_resultado, vetor, vetor_aux) == E_ERR){
            cout << "erro: vetor vazio" << endl;
        }
        else{
            cout << "erro: vetores de tamanhos diferentes" << endl;
        }
    }

    else{
        if (exibe(vetor_resultado,5)==E_ERR)
            cerr << "vetor VAZIO\n" << endl;
    }

    cout << "total: ";
    if(totaliza(vetor_resultado, total) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    else{
        cout << total << endl << endl;
    }


    // divisor
    cout << "===========================" << endl << endl;
    // divisor

    // acrescentando
    cout << "acrescentando valor (15) ao final do vetor:" << endl;
    if(acrescenta(vetor,15) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    if (exibe(vetor,10)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;


    cout << endl;

    // acrescentando
    cout << "retirando posicao 2 do vetor:" << endl;
    if(retira(vetor,2) == E_ERR){
        cout << "erro: vetor vazio" << endl;
        return -1;
    }

    if (exibe(vetor,10)==E_ERR)
        cerr << "vetor VAZIO\n" << endl;


    return 0;
}
