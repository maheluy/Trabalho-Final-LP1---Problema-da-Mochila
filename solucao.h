#ifndef SOLUCAO_H_INCLUDED
#define SOLUCAO_H_INCLUDED

// ESTRUTURA DE DADOS QUE REPRESENTARA OS ITENS DISPONIVEIS
typedef struct {
  float valor;
  float peso;
} Item;

// CABECALHO DAS FUNCOES QUE SERAO ULTILIZADAS PARA RESOLUCAO DO PROBLEMA
float mochila(int, int, Item *);
float itensNaMochila(int, int, int *, Item *);
float MaxItens(int, int, int, int, int *, Item *);

#endif