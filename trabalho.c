#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char sexoClinte[5];
  int pedidoCliente[5];
  int pizza[5];
  // PARTE 2
  int opcao;
  int erro = 0;
  int codigo = 0;
  // PARTE 3
  int pedidoEcontrado = 0;
  // regitro dos pedidos

  for (int i = 0; i < 5; i++) {
    erro = 0;
    printf("\nQual é o seu sexo? ");
    scanf(" %c", &sexoClinte[i]);
    if ((sexoClinte[i] != 'm' && sexoClinte[i] != 'M') &&
        (sexoClinte[i] != 'f' && sexoClinte[i] != 'F') &&
        (sexoClinte[i] != 'o' && sexoClinte[i] != 'O')) {
      printf("\nCategoria inválida\n");
      erro = 1;
    }

    printf("\nEscolha o pedido de 1 a 10: ");
    scanf("%d", &pedidoCliente[i]);

    if (pedidoCliente[i] < 1 || pedidoCliente[i] > 10) {
      printf("\ncodigo do pedido invalido\n");
      erro = 1;
    }

    printf("\nQual é a quantidade de pizza? ");
    scanf("%d", &pizza[i]);
    if (pizza[i] < 1) {

      printf("valor invalido\n");
      erro = 1;
    }

    if (erro != 0) {
      i--;
      printf("\nErro encontrado, reniciando\n");

    } else {
      printf("\nCodigo cadastrado\n");
    }
  }

  // menu dos pedidos

  while (1) {

    printf("\nMenu principal\n");
    printf("\n1 - Pesquisar pedido\n");
    printf("\n2 - Ver todos os pedidos\n");
    printf("\n0 - Encerrar programa!\n");
    printf("\nEscolha uma das opções: ");
    scanf("%d", &opcao);
    // parte 3
    switch (opcao) {
    case 1:

      printf("\ninforme o codigo\n");
      scanf("%d", &codigo);
      pedidoEcontrado = 0;
      for (int i = 0; i < 5; i++) {

        if (pedidoCliente[i] == codigo) {
          printf("\npedido do cliente: %d: ", pedidoCliente[i]);
          printf("\nsexo do cliente: %c ", sexoClinte[i]);
          printf("\nQuantidade de pizza: %d ", pizza[i]);
          pedidoEcontrado = 1;
        }
      }
      if (!pedidoEcontrado) {
        printf("\npedido não encontrado\n");
      }
      break;
      case 2:
      for (int i = 0; i < 5; i++) {
          printf("\npedido do cliente: %d ", pedidoCliente[i]);
          printf("\nsexo do cliente: %c ", sexoClinte[i]);
          printf("\nQuantidade de pizza: %d \n", pizza[i]);
      }
      break;
    case 0:
      printf("\nPrograma encerrado\n");
      return 0;
      break;
    default:
      printf("\nCodigo não registrado\n");
    }
  } // final do while
}