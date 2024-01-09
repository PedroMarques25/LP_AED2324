//
// Created by Pedro Marques on 04/10/2023.
//

#ifndef PROJETOLPAED1_PROJETO_H
#define PROJETOLPAED1_PROJETO_H

#define MAX_COLS_PALS 7
#define MAX_COLS_UFP6 (MAX_COLS_PALS * 6)

/***********************************************************************************************************************
****************************************** SECTION OF STRUCTURES *******************************************************
***********************************************************************************************************************/

typedef struct storewordufp6{
    char *palavra;
    char *codigoUFP6;
} STOREWORDUFP6;
// Estrutura que contém as matrizes dinâmicas
typedef struct dynamicmatriz{
    STOREWORDUFP6 **conjunto1; // Primeiro conjunto de palavras e códigos
    STOREWORDUFP6 **conjunto2; // Segundo conjunto de palavras e códigos
    int tamanho1;            // Tamanho do primeiro conjunto
    int tamanho2;            // Tamanho do segundo conjunto
} DYNAMICMATRIX;

typedef struct words_holder {
    DYNAMICMATRIX set1;
} WORDS_HOLDER;

 /*typedef struct words_holder {
    char words[100][50];
    int codes[100];
} WORDS_HOLDER;*/



typedef struct val_ad_words_holder {
    WORDS_HOLDER wordsHolder;
    long data;
} VAL_AD_WORDS_HOLDER;

typedef struct ad_words_holder {
    int size;
    int count;
    VAL_AD_WORDS_HOLDER *pvalwordsholder;
} AD_WORDS_HOLDER;

typedef struct Node_Ll_Words_Holder {
    WORDS_HOLDER data;
    char lastUpdate[20];
    struct Node_Ll_Words_Holder *next;
    struct Node_Ll_Words_Holder *prev;
} NODE_LL_WORDS_HOLDER;

typedef struct Ll_Words_Holder {
    struct Node_Ll_Words_Holder *head;
    int count;
} LL_WORDS_HOLDER;


/**********************************************************************************************************************/
/**********************************************************************************************************************/
/**********************************************************************************************************************/

int main_projeto(int argc, const char *argv[]);

DYNAMICMATRIX *criarMatrizDados();

char *content_to_binary(char *string);

void adicionarPalavra(DYNAMICMATRIX *matriz, int conjunto, char *palavra);

void listarPalavras(DYNAMICMATRIX *matriz, int conjunto);

void liberarMemoria(DYNAMICMATRIX *matriz);

void add_to_matrix(char **matrix, int row, int collum, int numRow, int numCollum, const char *palavra);

char* gerarPalavraAleatoria();

void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col);

void check_segment(DYNAMICMATRIX *dynamicmatrix);

void seach_string_word( char *sequence, DYNAMICMATRIX matrix);

void sort_crescent(int *vetor, int tamanho);

void sort(int *vetor, int *vAuxiliar, int posicaoInicial, int posicaoFinal);

void merge(int *vetor, int *vAuxiliar, int posicaoInicial, int metade, int posicaoFinal);

void sort_decrescent(int *vetor, int tamanho);

void sort_inverso(int *vetor, int *vAuxiliar, int posicaoInicial, int metade, int posicaoFinal);

char *create_matrix(int numRows, int numCollums, char **matrix);

char *string_to_binary(char *palavra);

int decimal_to_binary(int value, char *matriz,  int column);

void print_matrix(char **matrix);

AD_WORDS_HOLDER ARRDYN_WORDS_HOLDER(int size);

AD_WORDS_HOLDER resize_AD_WORDS_HOLDER(AD_WORDS_HOLDER ad_words_holder, int new_size);

AD_WORDS_HOLDER inserir_ordenado(AD_WORDS_HOLDER ad_words_holder, char *nova_data_modificacao);

void write_to_file(const char *filename, AD_WORDS_HOLDER ad_words_holder);

AD_WORDS_HOLDER read_from_file(const char *filename);

DYNAMICMATRIX* pesquisar_palavra_ll(LL_WORDS_HOLDER *list, const char *palavra,const char *code);

void deleteNodeAtIndex(LL_WORDS_HOLDER *list, int index);

void insertNodeAtIndex(LL_WORDS_HOLDER *list, WORDS_HOLDER data, char lastUpdate[], int index);

void insertNode(LL_WORDS_HOLDER *list, WORDS_HOLDER data, char lastUpdate[]);

AD_WORDS_HOLDER eliminar_elemento(AD_WORDS_HOLDER ad_words_holder, int posicao);

#endif //PROJETOLPAED1_PROJETO_H
