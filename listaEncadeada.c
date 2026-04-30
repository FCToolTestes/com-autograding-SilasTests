#include <stdio.h>
#include <stdlib.h>

#include "listaEncadeada.h"

static TNo *criarNo(int valor) {
    TNo *novo = (TNo *) malloc(sizeof(TNo));

    if (novo == NULL) {
        return NULL;
    }

    novo->valor = valor;
    novo->prox = NULL;
    return novo;
}

void inicializarLista(TListaEncadeada *lista) {
    lista->inicio = NULL;
    lista->tamanho = 0;
}

int listaVazia(const TListaEncadeada *lista) {
    return lista->inicio == NULL;
}

void exibirLista(const TListaEncadeada *lista) {
    TNo *atual;

    if (listaVazia(lista)) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista:");
    atual = lista->inicio;
    while (atual != NULL) {
        printf(" %d", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void esvaziarLista(TListaEncadeada *lista) {
    TNo *atual = lista->inicio;

    while (atual != NULL) {
        TNo *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    lista->inicio = NULL;
    lista->tamanho = 0;
}

int inserirInicio(TListaEncadeada *lista, int valor) {
    TNo *novo = criarNo(valor);

    if (novo == NULL) {
        return 0;
    }

    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;
    return 1;
}

int inserirFim(TListaEncadeada *lista, int valor) {
    TNo *novo = criarNo(valor);
    TNo *atual;

    if (novo == NULL) {
        return 0;
    }

    if (listaVazia(lista)) {
        lista->inicio = novo;
        lista->tamanho++;
        return 1;
    }

    atual = lista->inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    lista->tamanho++;
    return 1;
}

int inserirPosicao(TListaEncadeada *lista, int valor, int posicao) {
    TNo *novo;
    TNo *anterior;
    int indice;

    if (posicao < 1 || posicao > lista->tamanho + 1) {
        return 0;
    }

    if (posicao == 1) {
        return inserirInicio(lista, valor);
    }

    if (posicao == lista->tamanho + 1) {
        return inserirFim(lista, valor);
    }

    novo = criarNo(valor);
    if (novo == NULL) {
        return 0;
    }

    anterior = lista->inicio;
    for (indice = 1; indice < posicao - 1; indice++) {
        anterior = anterior->prox;
    }

    novo->prox = anterior->prox;
    anterior->prox = novo;
    lista->tamanho++;
    return 1;
}

int removerValor(TListaEncadeada *lista, int valor) {
    TNo *atual = lista->inicio;
    TNo *anterior = NULL;
    int removidos = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            TNo *proximo = atual->prox;

            if (anterior == NULL) {
                lista->inicio = proximo;
            } else {
                anterior->prox = proximo;
            }

            free(atual);
            atual = proximo;
            lista->tamanho--;
            removidos++;
            continue;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return removidos;
}

int removerPosicao(TListaEncadeada *lista, int posicao, int *valorRemovido) {
    TNo *atual;
    TNo *anterior;
    int indice;

    if (posicao < 1 || posicao > lista->tamanho || listaVazia(lista)) {
        return 0;
    }

    atual = lista->inicio;
    anterior = NULL;

    for (indice = 1; indice < posicao; indice++) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    if (valorRemovido != NULL) {
        *valorRemovido = atual->valor;
    }

    free(atual);
    lista->tamanho--;
    return 1;
}

int buscarValor(const TListaEncadeada *lista, int valor) {
    TNo *atual = lista->inicio;
    int posicao = 1;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }

        atual = atual->prox;
        posicao++;
    }

    return -1;
}

int obterTamanho(const TListaEncadeada *lista) {
    return lista->tamanho;
}
