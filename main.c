#include <stdio.h>
#include <string.h>

#include "listaEncadeada.h"

int main(void) {
    TListaEncadeada lista;
    char comando[16];

    inicializarLista(&lista);

    while (scanf("%15s", comando) == 1) {
        if (strcmp(comando, "-ii") == 0) {
            int valor;
            if (scanf("%d", &valor) == 1) {
                inserirInicio(&lista, valor);
            }
        } else if (strcmp(comando, "-if") == 0) {
            int valor;
            if (scanf("%d", &valor) == 1) {
                inserirFim(&lista, valor);
            }
        } else if (strcmp(comando, "-i") == 0) {
            int valor;
            int posicao;
            if (scanf("%d %d", &valor, &posicao) == 2) {
                inserirPosicao(&lista, valor, posicao);
            }
        } else if (strcmp(comando, "-r") == 0) {
            int valor;
            if (scanf("%d", &valor) == 1) {
                removerValor(&lista, valor);
            }
        } else if (strcmp(comando, "-rp") == 0) {
            int posicao;
            int valorRemovido;
            if (scanf("%d", &posicao) == 1) {
                removerPosicao(&lista, posicao, &valorRemovido);
            }
        } else if (strcmp(comando, "-b") == 0) {
            int valor;
            int posicao;

            if (scanf("%d", &valor) != 1) {
                continue;
            }

            posicao = buscarValor(&lista, valor);
            if (posicao == -1) {
                printf("Elemento %d não encontrado.\n", valor);
            } else {
                printf("Elemento %d encontrado na posição %d.\n", valor, posicao);
            }
        } else if (strcmp(comando, "-t") == 0) {
            printf("Tamanho da lista: %d\n", obterTamanho(&lista));
        } else if (strcmp(comando, "-c") == 0) {
            esvaziarLista(&lista);
        } else if (strcmp(comando, "-s") == 0) {
            exibirLista(&lista);
        } else if (strcmp(comando, "-f") == 0) {
            break;
        }
    }

    esvaziarLista(&lista);
    return 0;
}
