#include <malloc.h>
#include <stdio.h>
// INSERCAO DA BIBLIOTECA QUE CONTEM AS FUNCOES PARA MANIPULACAO DE ARQUIVOS
#include "arquivo.h"
// INSERCAO DA BIBLIOTECA QUE CONTEM AS FUNCOES NECESSARIAS PARA RESOLUCAO DO
// PROBLEMA
#include "solucao.h"

int main() {
  // DECLARACAO DAS VARIAVEIS QUE RECEBERAO A QUANTIDADE DE ITENS E O PESO
  // MAXIMO DA MOCHILA
  unsigned int tamanho = 0, pesoMax = 0;
  // DECLARACAO DA VARIAVEL QUE IRA RECEBER O MAIOR VALOR QUE PODERA SER
  // INSERIDO NO CAMINHAO
  float combinacaoMax = 0.0;
  // DECLARACAO DE ARRAY AUXILIAR PARA MAPEAR QUAIS ITENS SERAO ADICIONADOS AO
  // CAMINHAO
  int *arrayAux;
  // DECLARACAO DE ARRAY DE ITENS
  Item *produtos;
  // DECLARACAO DA STRING QUE RECEBERA O NOME DO ARQUIVO QUE SERA ABERTO PARA
  // LEITURA
  char nome_arquivo[100];

  printf("Informe o nome do arquivo para leitura dos dados: ");
  scanf("%[^\n]s", nome_arquivo);

  // ABERTURA DE ARQUIVO PARA LEITURA DOS ITENS DISPONIVEIS
  FILE *arq = abrir_arquivo(nome_arquivo, "r");
  if (arq == NULL) {
    printf("Erro ao abrir o arquivo de leitura");
    return -1;
  }

  // LEITURA DA QUANTIDADE DE ITENS E PESO MAXIMO
  fscanf(arq, "%d", &tamanho);
  fscanf(arq, "%d", &pesoMax);

  // ALOCACAO DINAMICA DE MEMORIA PARA ARRAY AUXILIAR
  arrayAux = (int *)malloc(sizeof(Item) * tamanho);
  ;
  if (arrayAux == NULL)
    return -1;

  // ALOCACAO DINAMICA DE MEMORIA PARA ARRAY DE ITENS
  produtos = (Item *)malloc(sizeof(Item) * tamanho);
  if (produtos == NULL)
    return -1;

  // FUNCAO RESPONSAVEL POR LER OS DADOS DO ARQUIVO E ARMAZENAR EM UM ARRAY DE
  //  ITENS
  ler_dados(arq, produtos);

  // CHAMADA DA FUNCAO PARA RESOLUCAO DO PROBLEMA
  combinacaoMax = itensNaMochila(pesoMax, tamanho, arrayAux, produtos);

  // FUNCAO RESPONSAVEL POR SALVAR OS DADOS DA SOLUCAO EM UM ARQUIVO
  salvar_dados(produtos, arrayAux, tamanho, combinacaoMax);

  // LIBERANDO A MEMORIA ALOCADA
  free(produtos);
  free(arrayAux);

  return 0;
}