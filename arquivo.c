#include "arquivo.h"

// FUNCAO QUE IRA ABRIR OS ARQUIVOS
FILE *abrir_arquivo(char *nome_arquivo, char *modo) {
  FILE *arquivo = fopen(nome_arquivo, modo);
  return arquivo;
}

void ler_dados(FILE *arquivo, Item *produtos) {
  // DECLARACAO DE VARIAVEL QUE IRA AUXILIAR NA ALOCACAO DOS VALORES DENTRO DO
  // ARRAY DE ITENS
  unsigned int aux = 0;

  // LEITURA DOS DADOS DO ARQUIVO
  while (!feof(arquivo)) {
    fscanf(arquivo, "%f", &produtos[aux].valor);
    fscanf(arquivo, "%f", &produtos[aux].peso);
    aux++;
  }
  // FECHANDO O ARQUIVO APOS REALIZAR A LEITURA DOS DADOS
  fclose(arquivo);
}

void salvar_dados(Item *produtos, int *arrayAux, int tamanho, float maximo) {
  // ABERTURA DE ARQUIVO PARA ESCRITA DOS ITENS SELECIONADOS
  FILE *out = abrir_arquivo("outFile.txt", "w");
  // VERIFICA SE FOI POSSIVEL ABRIR O ARQUIVO EM MODO DE ESCRITA
  if (out == NULL)
    printf("Erro ao abrir o arquivo");
  // CASO A ABERTURA DO ARQUIVO TENHA SIDO BEM SUCEDIDA, ESCREVE OS DADOS DA
  // SOLUCAO
  else {
    // IMPRESSAO DOS ITENS SELECIONADOS
    fprintf(out, "O caminhao levara os itens:\n\n");
    for (int i = 0; i < tamanho; i++) {
      if (arrayAux[i] != 0) {
        int temp = arrayAux[i] - 1;
        fprintf(out, "Item %d (valor: %f e peso: %f)\n", temp,
                produtos[temp].valor, produtos[temp].peso);
      }
    }
    fprintf(out, "\nCom valor agregado: %f", maximo);
  }

  fclose(out);
}