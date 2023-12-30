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

typedef struct dynamicmatrix {
    char **data;
    int rows;
    int cols;
} DYNAMICMATRIX;

typedef struct set {
    DYNAMICMATRIX *DynamicMatrixPals;
    DYNAMICMATRIX *DynamicMatrixCodes;
} SET;

typedef struct words_holder {
    SET set1;
    SET set2;
} WORDS_HOLDER;

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

AD_WORDS_HOLDER ARRDYN_WORDS_HOLDER(int size);

AD_WORDS_HOLDER resize_AD_WORDS_HOLDER(AD_WORDS_HOLDER ad_words_holder, int new_size);

AD_WORDS_HOLDER inserir_ordenado(AD_WORDS_HOLDER ad_words_holder, char *nova_data_modificacao);

char *content_to_binary(char *string);

void add_to_matrix(char **matrix, int row, int collum, int numRow, int numCollum, const char *palavra);

char gerarPalavraAleatoria(char *palavra, int tamanho);

void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col);

void check_segment(char **matrix, char **matrix2, int palavras1, int palavras2);

void seach_string(const char *sequence, const char *words[], int numWords);

void sort_crescent(int *vetor, int tamanho);

void sort(int *vetor, int *vAuxiliar, int posicaoInicial, int posicaoFinal);

void merge(int *vetor, int *vAuxiliar, int posicaoInicial, int metade, int posicaoFinal);

void sort_decrescent(int *vetor, int tamanho);

void sort_inverso(int *vetor, int *vAuxiliar, int posicaoInicial, int metade, int posicaoFinal);

char *create_matrix(int numRows, int numCollums, char **matrix);

char **string_to_binary(char **matriz, int numpalavras);

int decimal_to_binary(int value, char **matriz, int line, int column);

void print_matrix(char **matrix);

#endif //PROJETOLPAED1_PROJETO_H
