#include "solucao.h"

// DIRETIVA DE COMPILACAO UTILIZADA PARA RETORNAR O MAIOR ENTRE DOIS VALORES
#define max(a, b) (a) > (b) ? (a) : (b)

// FUNCAO QUE CALCULA RECURSIVAMENTE O MAIOR VALOR NUMERICO DE RETORNO POSSIVEL
float mochila(int capacidade, int numeroItens, Item *itens) {
  // CASO O NUMERO DE ITENS DISPONIVEIS SEJA 0 OU A CAPACIADE DO CAMINHAO TENHHA
  // ALCANCADA SEU MAXIMO A FUNCAO RETORNARA 0
  if (numeroItens == 0 || capacidade == 0)
    return 0;
  // CASO O ITEM QUE TENTAREMOS ADICIONAR AO CAMINHAO TIVER PESO MAIOR QUE A
  // CAPACIDADE DO CAMINHAO TENTAREMOS O PROXIMO ITEM
  else if (itens[numeroItens - 1].peso > capacidade)
    return mochila(capacidade, numeroItens - 1, itens);
  // RETORNARA O VALOR MAXIMO ENTRE ADICIONAR UM ITEM OU NAO ADICIONALO AO
  // CAMINHAO
  else
    return max(itens[numeroItens - 1].valor +
                   mochila(capacidade - itens[numeroItens - 1].peso,
                           numeroItens - 1, itens),
               mochila(capacidade, numeroItens - 1, itens));
}

// FUNCAO REPONSAVEL POR MAPEAR OS ITENS QUE SERAO ADICIONADOS AO CAMINHAO
float itensNaMochila(int capacidade, int numeroItens, int *arrayAux,
                     Item *itens) {
  // CASO O NUMERO DE ITENS DISPONIVEIS SEJA 0 OU A CAPACIADE DO CAMINHAO TENHHA
  // ALCANCADA SEU MAXIMO A FUNCAO RETORNARA 0
  if (numeroItens == 0 || capacidade == 0)
    return 0;
  // CASO O ITEM QUE TENTAREMOS ADICIONAR AO CAMINHAO TIVER PESO MAIOR QUE A
  // CAPACIDADE DO CAMINHAO TENTAREMOS O PROXIMO ITEM
  else if (itens[numeroItens - 1].peso > capacidade)
    return itensNaMochila(capacidade, numeroItens - 1, arrayAux, itens);
  // RETORNARA O VALOR MAXIMO ENTRE ADICIONAR UM ITEM OU NAO ADICIONALO AO
  // CAMINHAO E CHAMA A FUNCAO QUE INDICARA QUAIS ITENS FORAM ADICIONADOS AO
  // CAMINHAO
  else
    return MaxItens(itens[numeroItens - 1].valor +
                        mochila(capacidade - itens[numeroItens - 1].peso,
                                numeroItens - 1, itens),
                    mochila(capacidade, numeroItens - 1, itens), capacidade,
                    numeroItens, arrayAux, itens);
}

// FUNCAO RESPONSAVEL POR INDICAR QUAIS ITENS ESTAO SENDO SELECIONADOS
float MaxItens(int a, int b, int capacidade, int numeroItens, int *arrayAux,
               Item *itens) {
  // CASO A ESCOLHER UM ITEM SEJA MAIS VANTAJOSO QUE NAO ESCOLHELO, ENTAO O
  // VETOR AUXILIAR IRA RECEBER O VALOR DO ITEM NA POSICAO DO NUMERO DO ITEM
  // ESCOLHIDO + 1
  if (max(a, b) == a) {
    *(arrayAux + numeroItens - 1) = (numeroItens);
    // CHAMARA A FUNCAO NOVAMENTE PARA VERIFICAR PARA OS PROXIMOS ITENS
    return itens[numeroItens - 1].valor +
           itensNaMochila(capacidade - itens[numeroItens - 1].peso,
                          numeroItens - 1, arrayAux, itens);
  }
  // CASO A ESCOLHER UM ITEM NAO SEJA MAIS VANTAJOSO CHAMARA A FUNCAO PASSANDO O
  // PROXIMO ITEM
  return itensNaMochila(capacidade, numeroItens - 1, arrayAux, itens);
}