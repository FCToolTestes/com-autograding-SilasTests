#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct No {
    int valor;
    struct No *prox;
} TNo;

typedef struct {
    TNo *inicio;
    int tamanho;
} TListaEncadeada;

void inicializarLista(TListaEncadeada *lista);
int listaVazia(const TListaEncadeada *lista);
void exibirLista(const TListaEncadeada *lista);
void esvaziarLista(TListaEncadeada *lista);
int inserirInicio(TListaEncadeada *lista, int valor);
int inserirFim(TListaEncadeada *lista, int valor);
int inserirPosicao(TListaEncadeada *lista, int valor, int posicao);
int removerValor(TListaEncadeada *lista, int valor);
int removerPosicao(TListaEncadeada *lista, int posicao, int *valorRemovido);
int buscarValor(const TListaEncadeada *lista, int valor);
int obterTamanho(const TListaEncadeada *lista);

#endif
