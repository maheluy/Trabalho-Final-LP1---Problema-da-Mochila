  Código feito por Marcelo Heluy, Matheus Raposo e Paulo henrique Pinheiro.
 
  O código primeiramente lê o arquivo requerido para saber o numero de itens e o peso máximo do caminhão, criando um vetor struct "produtos" onde cada elemento do vetor é um objeto que pode ou não entrar no caminhão.
 
  Solução: Foi decidido usar um sistema de guia juntamente com a resolução para o problema da mochila, a função "ItensNaMochila" vai primeiro testar se o ultimo item do vetor tem o peso maior que o peso máximo, caso seja maior será usado recursividade da função, mas sem esse elemento no vetor "produtos", e caso o peso máximo seja igual a 0, ela retornará 0,
  Caso não seja maior, a função retornará uma outra função "MaxItens", que juntamente com a função "Mochila" irá comparar qual caminho é mais eficiente(Levará a um maior valor): Uma combinação de itens que possua o item atual ou uma outra combinação que não possua o item atual.
  
  [A Função "mochila" faz a mesma coisa que a função "ItensNaMochila", mas ao invés de usar o "MaxItens", ele usa um comparador normal de descobrir o maior entre dois valores, utilizando da recursividade dentro dele próprio]

  Dentro da função "MaxItens", caso seja escolhida a combinação que possua o item anterior, ele irá guardar o numero do item num vetor auxiliar "ArrayAux" e retornará a recursividade da função "ItensNaMochila", mas com o peso máximo reduzido pelo peso do item e sem o item no vetor "produtos".

  Caso seja escolhida uma combinação sem o item, será retornado a recursividade da função "ItensNaMochila", mas com o vetor "produtos" sem o item e com o peso máximo normal.

  Resultado: A função "ItensNaMochila" inicial irá retornar o valor total da combinação mais eficiente e o "ArrayAux" terá em seus elementos, somente zeros ou os itens escolhidos para ir no caminhão.

Escolha de design: Foi decidido dividir o código em 5 abas com fins de melhor entendimento:

—"main.c": Onde estará a int main do código, onde será chamado as funções!

—"arquivo.h": Onde estará sendo declarado as funções relacionadas à leitura e escrita de arquivos

—"arquivo.c": Onde estarão todas as funções que foram declaradas em "arquivo.h".

—"solução.h": Onde estará declarado as funções relacionadas à resolução do problema.

—"solução.c": Onde estarão as funções que foram declaradas em "solução.h"