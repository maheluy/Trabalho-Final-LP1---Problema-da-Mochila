#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include "solucao.h"
#include <stdio.h>

// CABECALHO DAS FUNCOES QUE SERAO ULTILIZADAS PARA MANIPULACAO DE ARQUIVOS
FILE *abrir_arquivo(char *, char *);
void ler_dados(FILE *, Item *);
void salvar_dados(Item *, int *, int, float);

#endif