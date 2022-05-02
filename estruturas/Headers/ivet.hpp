/*********************************************************************
* @brief   definicao estrutura ivet_t e auxiliares, prototipos funcao
* @file    ivet.hpp
* @author  MZ & Artur Ritzel
* @date    abril/2022
* @version 0.1
*********************************************************************/


// Essa eh a guarda do codigo - evita redefinicao
#ifndef IVET_HPP_INCLUDED
#define IVET_HPP_INCLUDED


//! tipo dado ivet_t - estrutura para armazenamento de vetores
struct ivet_t {
              int *dado=nullptr;       //!< ponteiro para area dados
              unsigned int nitens=0;  //!< numero de elementos vetor
              };


//! tipo dado el_ivet_t - valor de um elemento e sua posicao
struct el_ivet_t {
              int v=0;          //!< valor do elemento
              unsigned int p=0; //!< posicao do elemento
              };


//! tipo dado ivetERR_t - enumeracao codigos erro retorno funcoes usam ivet_t
enum ivetERR_t {E_ERR=-3, //!< vetor nao inicializado
                P_ERR,    //!< valor de parametros invalidos
                M_ERR,    //!< erro de memoria
                OK=0      //!< sucesso na execucao
                };



// Prototipos das funcoes

ivetERR_t cria(ivet_t &v,int n);

void destroi(ivet_t &v);

ivetERR_t preenche(ivet_t &v, int valor);

ivetERR_t sorteia(ivet_t v, int vmin, int vmax);

ivetERR_t ordena_cresc(ivet_t v);

ivetERR_t ordena_dec(ivet_t v);

ivetERR_t exibe(ivet_t &v);

ivetERR_t exibe(ivet_t &v, int elemLinha );

ivetERR_t acrescenta(ivet_t &v,int valor);

ivetERR_t retira(ivet_t &v,int pos);

ivetERR_t totaliza(ivet_t &v,int &total);

ivetERR_t soma(ivet_t &resultado,ivet_t v1,ivet_t v2);

ivetERR_t maiorValor(ivet_t v, el_ivet_t &maior);

ivetERR_t menorValor(ivet_t v, el_ivet_t &menor);

#endif // IVET_HPP_INCLUDED
