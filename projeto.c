/**
    * ==================================================================================================================
    *   PROJETO REALIZADO POR:                                                                                         *
    * - PEDRO MARQUES - 38688                                                                                          *
    * - PEDRO MONTEIRO  - 2022110782                                                                                   *
    * ==================================================================================================================
 **/

#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include "projeto.h"
#include "ctype.h"
#include <time.h>
#include <stddef.h>

#define NULL0 -1;
#define NUMROWS 10
#define NUMCOLS 7

DYNAMICMATRIX DynamicMatrix;
void *val_Ad_Words_Holder;
NODE_LL_WORDS_HOLDER Node_Ll_Words_Holder;

char * UFP6[] = { //Código UFP6
        // 0          1           2         3         4           5          6           7          8           9           a              b           c            d            e            f            g            h              i            j              k             l             m            n             o             p             q              r            s             t             u             v              w             x                y             z              A             B              C               D             E               F             G               H              I              J             K               L              M            N               O                P              Q              R             S               T               U               V              W            X               Y             Z
        "0",  "1",  "10", "11",  "100", "101", "110", "111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111", "100000", "100001", "100010", "100011", "100100", "100101", "100110", "100111", "101000", "101001", "101010", "101011", "101100", "101101", "101110", "101111", "110000", "110001", "110010", "110011", "110100", "110101", "110110", "110111", "111000", "111001", "111010", "111011", "111100", "111101",
};


char** create_Dynamic_Matrix(int lines, int cols) {
    char** matrix = (char**)calloc(lines * sizeof(char*), sizeof(char*));
    if (matrix == NULL) {
        printf("Erro na alocação de memória para linhas.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < lines; i++) {
        matrix[i] = (char*)calloc(cols, sizeof(char));
        if (matrix[i] == NULL) {
            printf("Erro na alocação de memória para colunas.\n");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}

void free_Dynamic_Matrix(char** matrix, int lines) {
    for (int i = 0; i < lines; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void fill_Matrix(char** matrix, int lines, int cols, char dados[][MAX_COLS_PALS]) {
    for (int i = 0; i < lines; i++) {
        if (matrix[i] == NULL) {
            printf("Erro: matriz[%d] não alocada corretamente.\n", i);
            exit(EXIT_FAILURE);
        }

        strncpy(matrix[i], dados[i], cols);
    }
}

void print_Matrix(char** matrix, int numRow, int numCollum) {
    for (int i = 0; i < numRow; i++) {
        /*for (int j = 0; j < numCollum; j++) {
            printf("%c ", *(*(matrix+i)+j));

        printf("|\n");*/
        printf("%s|\n",*(matrix+i));
    }
}

/**requisito 2 **/

int decimal_to_binary(int value, char **matriz, int line, int column) {
    //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    // counter for binary array

    printf("\nThe string in binary is ");

    int h = 0;
    char charvalue='\0';
    int binaryNum[8];

    while (value > 0) {

        binaryNum[h] = value % 2;
        value = value / 2;
        h++;
    }

    for (int j = h - 1; j >= 0; j--, column++) {
        printf("%d", binaryNum[j]);
        charvalue = binaryNum[j]+'0';
        matriz[line][column] = charvalue;
    }
    return column;
}

/** req 2 (cont.)**/
char** string_to_binary(char** matriz, int numpalavras) {
    char** DynamicMatrixCodes = create_Dynamic_Matrix(numpalavras, MAX_COLS_UFP6);

    for (int i = 0; i < numpalavras; i++) {
        size_t size = strlen(matriz[i]);

        DynamicMatrixCodes[i] = (char*)malloc((MAX_COLS_UFP6 + 1) * sizeof(char)); // +1 for the null terminator

        int g = 0;
        int value;

        for (int j = 0; j < size; j++) {
            value = matriz[i][j] - '0';
            if (isupper(matriz[i][j])) {
                value = value + 19;
                g = decimal_to_binary(value, DynamicMatrixCodes, i, g);
            } else if (value <= 9) {
                g = decimal_to_binary(value, DynamicMatrixCodes, i, g);
            } else {
                value = value - 39;
                g = decimal_to_binary(value, DynamicMatrixCodes, i, g);
            }
        }
        DynamicMatrixCodes[i][g] = '\0';
    }

    return DynamicMatrixCodes;
}

char gerarPalavraAleatoria(char *palavra, int tamanho) {
    const char caracteresPermitidos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int lenCaracteresPermitidos = strlen(caracteresPermitidos);

    for (int i = 0; i < tamanho - 1; i++) {
        palavra[i] = caracteresPermitidos[rand() % lenCaracteresPermitidos];
    }

    palavra[tamanho - 1] = '\0'; // Adicionar o char nulo no final
    printf(" %s", palavra);

    return *palavra;
}

/** req 3 **/

void add_to_matrix(char **Matrix1, int row, int collum, int numRow, int numCollum, const char *palavra) {
    if (row >= 0 && row < numRow && collum >= 0 && collum < numCollum) {
        *(*(Matrix1 + row) + collum) = *palavra;
        //string_to_binary(value);
        //print_Matrix(matrix, row,collum);
        //gerarPalavraAleatoria(palavra, 7);
        strncpy((*(Matrix1 + row) + collum), palavra, strlen(palavra));
    } else {
        printf("invalid insert\n");
    }
}

/** req 3 (cont.)**/
void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {

        for (int i = row; i < matrix->rows - 1; i++) {
            for (int j = col; j < matrix->cols - 1; j++) {
                *(*(matrix->data + i) + j) = *(*(matrix->data + i + 1) + j + 1);
            }
        }


        matrix->rows--;
        matrix->cols--;


        matrix->data = (char **) realloc(matrix->data, matrix->rows * sizeof(char *));
        for (int i = 0; i < matrix->rows; i++) {
            matrix->data[i] = (char *) realloc(matrix->data[i], matrix->cols * sizeof(char));
        }
    } else {
        printf("Posição inválida na matriz.\n");
    }
}

/** req 4 **/
void check_segment(char **matrix,char **matrix2,int palavras1,int palavras2) {
    int value;
    for(int i=0;i<=palavras1;i++) {
        for (int j = 0; j <=palavras2;j++){
            value = strcmp(*(matrix+i),*(matrix2+j));
            if(value == 0){
                printf("\n");
                printf("%s %s sao combinacoes iguais\n",*(matrix+i),*(matrix2+j));
            }
        }
    }
}

/** req 5 **/
char** seach_string_word(char *sequencia,  char **matrix, int numWords) {
    char **ufp6 = create_Dynamic_Matrix(numWords, MAX_COLS_UFP6);
    int j=0;
    for (int i = 0; i < numWords; i++) {
        //Verifica se a sequência de pesquisa ocorre na palavra
        if (strstr(matrix[i], sequencia) != NULL) {
            printf("%s\n", matrix[i]);
            ufp6[j]=matrix[i];
            j++;
        }
    }
    return ufp6;
}

/** req 6 **/
void sort_crescent(int *vetor, int tamanho) {
    /**
     *  implementação do merge sort (sugestão Prof. Torres)
     */

    //Alocando um espaço na memória para servir de vetor auxiliar
    int *vAuxiliar = malloc(sizeof(int)*tamanho);
    //Chamando a função sort para começar o processo de divisão do vetor
    sort(vetor,vAuxiliar,0,tamanho-1);
    free(vAuxiliar);

}

void sort(int *vetor, int *vAuxiliar , int posicaoInicial , int posicaoFinal){
    //Verificando se o vetor tem tamanho maior que 1
    if(posicaoInicial>=posicaoFinal)
        return;

    //Com o vetor de tamanho maior que 1 ele divide esse vetor pegando a posicao que fica na metade do vetor;
    int metade = (posicaoInicial+posicaoFinal) / 2;

    //Fazendo uma chamada recursiva para ordenar a primeira metade do vetor
    sort(vetor,vAuxiliar,posicaoInicial,metade);
    //Fazendo uma chamada recursiva para ordenar a segunda metade do vetor
    sort(vetor,vAuxiliar,metade+1,posicaoFinal);

    //Faz uma verificação para saber se os vetores estão ordenados entre si
    if(vetor[metade]<=vetor[metade+1])
        return;

    //Chamando a função merge para reorganizar o vetor
    merge(vetor,vAuxiliar,posicaoInicial,metade,posicaoFinal);

}

void merge(int *vetor, int *vAuxiliar , int posicaoInicial , int metade , int posicaoFinal){

    int contador;
    //Armazena a posição inicial do vetor principal
    int inicioVetor = posicaoInicial;
    //Armazena a posição inicial do vetor auxiliar
    int inicioVAuxiliar = metade + 1;

    //Fazendo uma cópia do vetor princpal para o vetor auxiliar
    for(contador = posicaoInicial ; contador <= posicaoFinal ; contador ++)
        vAuxiliar[contador]=vetor[contador];

    //Reiniciando o contador
    contador = posicaoInicial;

    //Percorrendo os vetores
    while(inicioVetor <= metade && inicioVAuxiliar <= posicaoFinal){
        //Verifica qual valores são maior e menor  e reorganiza o vator principal
        if(vAuxiliar[inicioVetor]<vAuxiliar[inicioVAuxiliar])
            vetor[contador++]=vAuxiliar[inicioVetor++];
        else
            vetor[contador++]=vAuxiliar[inicioVAuxiliar++];

    }

    //Passando o que sobrar da primeira metade para o vetor principal
    while(inicioVetor<=metade)
        vetor[contador++] = vAuxiliar[inicioVetor++];

    //Passando o que sobrar da segunda metade para o vetor principal
    while(inicioVAuxiliar<=posicaoFinal)
        vetor[contador++] = vAuxiliar[inicioVAuxiliar++];
}

/** req 6 **/
void sort_decrescent(int *vetor, int tamanho) {
    /**
     *  implementação do merge sort ou MSD para os chars(sugestão Prof. Torres)
     */
    //Alocando um espaço na memória para servir de vetor auxiliar
    int *vAuxiliar = malloc(sizeof(int)*tamanho);
    //Chamando a função sort para começar o processo de divisão do vetor
    sort_inverso(vetor,vAuxiliar,0,tamanho / 2, tamanho-1);
    free(vAuxiliar);
}

void sort_inverso(int *vetor, int *vAuxiliar, int posicaoInicial, int metade, int posicaoFinal){
    int contador;
    int inicioVetor = posicaoInicial;
    int inicioVAuxiliar = metade + 1;

    for (contador = posicaoInicial; contador <= posicaoFinal; contador++)
        vAuxiliar[contador] = vetor[contador];

    contador = posicaoInicial;

    while (inicioVetor <= metade && inicioVAuxiliar <= posicaoFinal) {
        if (vAuxiliar[inicioVetor] >= vAuxiliar[inicioVAuxiliar]) // Inverte a lógica de comparação
            vetor[contador++] = vAuxiliar[inicioVetor++];
        else
            vetor[contador++] = vAuxiliar[inicioVAuxiliar++];
    }

    while (inicioVetor <= metade)
        vetor[contador++] = vAuxiliar[inicioVetor++];

    while (inicioVAuxiliar <= posicaoFinal)
        vetor[contador++] = vAuxiliar[inicioVAuxiliar++];

}

AD_WORDS_HOLDER ARRDYN_WORDS_HOLDER(int size) {
    AD_WORDS_HOLDER ad_words_holder;
    ad_words_holder.size = size;
    ad_words_holder.count = 0;
    ad_words_holder.pvalwordsholder = (VAL_AD_WORDS_HOLDER*)malloc(size * sizeof(VAL_AD_WORDS_HOLDER));

    if (ad_words_holder.pvalwordsholder == NULL) {
        printf("Erro na alocação de memória para ad_words_holder.pvalwordsholder.\n");
        exit(EXIT_FAILURE);
    }

    return ad_words_holder;
}

// fill array
AD_WORDS_HOLDER resize_AD_WORDS_HOLDER(AD_WORDS_HOLDER ad_words_holder, int new_size) {
    ad_words_holder.pvalwordsholder = realloc(ad_words_holder.pvalwordsholder, new_size * sizeof(VAL_AD_WORDS_HOLDER));
    ad_words_holder.size = new_size;
    return ad_words_holder;
}

// Função para inserir um elemento ordenadamente em AD_WORDS_HOLDER
AD_WORDS_HOLDER inserir_ordenado(AD_WORDS_HOLDER ad_words_holder, char* nova_data_modificacao) {
    // Verificar se há espaço para mais elementos
    if (ad_words_holder.count >= ad_words_holder.size) {
        // Se não houver espaço suficiente, redimensionar o array
        ad_words_holder = resize_AD_WORDS_HOLDER(ad_words_holder, ad_words_holder.size * 2);
    }

    // Encontrar a posição correta para inserir o novo elemento
    int posicao_insercao = 0;
    while (posicao_insercao < ad_words_holder.count &&
           strtol(nova_data_modificacao, NULL, 10) > ad_words_holder.pvalwordsholder[posicao_insercao].data) {
        posicao_insercao++;
    }

    // Deslocar os elementos à direita para abrir espaço para o novo elemento
    for (int i = ad_words_holder.count; i > posicao_insercao; i--) {
        ad_words_holder.pvalwordsholder[i] = ad_words_holder.pvalwordsholder[i - 1];
    }

    // Inserir o novo elemento na posição correta
    ad_words_holder.pvalwordsholder[posicao_insercao].data = strtol(nova_data_modificacao, NULL, 10);

    // Incrementar o contador de elementos
    ad_words_holder.count++;

    return ad_words_holder;
}

AD_WORDS_HOLDER eliminar_elemento(AD_WORDS_HOLDER ad_words_holder, int posicao) {
    // Verificar se a posição é válida
    if (posicao < 0 || posicao >= ad_words_holder.count) {
        printf("Posicao invalida\n");
        return ad_words_holder;  // Retornar sem modificar se a posição for inválida
    }

    // Deslocar os elementos à esquerda para preencher a posição do elemento removido
    for (int i = posicao; i < ad_words_holder.count - 1; i++) {
        ad_words_holder.pvalwordsholder[i] = ad_words_holder.pvalwordsholder[i + 1];
    }

    // Decrementar o contador de elementos
    ad_words_holder.count--;

    // Verificar se é necessário redimensionar o array (por exemplo, se a contagem estiver muito abaixo do tamanho)
    if (ad_words_holder.count < ad_words_holder.size / 2) {
        ad_words_holder = resize_AD_WORDS_HOLDER(ad_words_holder, ad_words_holder.size / 2);
    }

    return ad_words_holder;
}

void insertNode(LL_WORDS_HOLDER *list, WORDS_HOLDER data, char lastUpdate[]) {
    NODE_LL_WORDS_HOLDER *newNode = (NODE_LL_WORDS_HOLDER *)malloc(sizeof(NODE_LL_WORDS_HOLDER));
    newNode->data = data;
    strcpy(newNode->lastUpdate, lastUpdate);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        NODE_LL_WORDS_HOLDER *current = list->head;
        while (current->next != NULL && strcmp(lastUpdate, current->lastUpdate) > 0) {
            current = current->next;
        }

        if (strcmp(lastUpdate, current->lastUpdate) > 0) {
            newNode->prev = current;
            current->next = newNode;
        } else {
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->next = newNode;
            } else {
                list->head = newNode;
            }
            current->prev = newNode;
        }
    }
    list->count++;
}

void insertNodeAtIndex(LL_WORDS_HOLDER *list, WORDS_HOLDER data, char lastUpdate[], int index) {
    if (index < 0 || index > list->count) {
        printf("Índice inválido para inserção.\n");
        return;
    }
    NODE_LL_WORDS_HOLDER *newNode = (NODE_LL_WORDS_HOLDER *)malloc(sizeof(NODE_LL_WORDS_HOLDER));
    newNode->data = data;
    strcpy(newNode->lastUpdate, lastUpdate);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (index == 0) {
        newNode->next = list->head;
        if (list->head != NULL) {
            list->head->prev = newNode;
        }
        list->head = newNode;
    } else {
        NODE_LL_WORDS_HOLDER *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    list->count++;
}

void deleteNodeAtIndex(LL_WORDS_HOLDER *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Índice inválido para exclusão.\n");
        return;
    }

    NODE_LL_WORDS_HOLDER *current = list->head;

    if (index == 0) {

        list->head = current->next;
        if (list->head != NULL) {
            list->head->prev = NULL;
        }
    } else {

        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    free(current);
    list->count--;
}

DYNAMICMATRIX* pesquisar_palavra_ll(LL_WORDS_HOLDER *list, const char *palavra,const char *code) {
    for (int i = 0; i < list->count; i++) {

        if (strcmp((const char *) list->head->data.set1.DynamicMatrixPals->data, palavra) == 0 ||
            (strcmp((const char *) list->head->data.set1.DynamicMatrixCodes->data, code)== 0)) {

            return list->head->data.set1.DynamicMatrixPals;
        }
    }

    return NULL;
}

void printArray(AD_WORDS_HOLDER array_dinamico) {
    for (int i = 0; i < array_dinamico.count; ++i) {
        printf("%ld", array_dinamico.pvalwordsholder[i].data);

    }
    printf("\n");
}

void write_to_file(const char *filename, AD_WORDS_HOLDER ad_words_holder) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ad_words_holder.count; i++) {
        if (ad_words_holder.pvalwordsholder->wordsHolder.set1.DynamicMatrixPals != NULL) {
            fprintf(file, "Words: %s,Data: %ld\n",ad_words_holder.pvalwordsholder->wordsHolder.set1.DynamicMatrixPals->data[0], ad_words_holder.pvalwordsholder->data);
        } else {
            fprintf(file, "Error: DynamicMatrixPals is NULL. Cannot print data.\n");
        }

        fclose(file);
    }
}

AD_WORDS_HOLDER read_from_file(const char *filename) {
    AD_WORDS_HOLDER ad_words_holder;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for reading: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[100];

    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        count++;
    }

    ad_words_holder.size = count;
    ad_words_holder.count = 0;
    ad_words_holder.pvalwordsholder = malloc(ad_words_holder.size * sizeof(VAL_AD_WORDS_HOLDER));

    fseek(file, 0, SEEK_SET);


    while (fgets(line, sizeof(line), file) != NULL) {

        sscanf(line, "%s %ld", ad_words_holder.pvalwordsholder[ad_words_holder.count].wordsHolder.set1.DynamicMatrixPals->data[0], &ad_words_holder.pvalwordsholder[ad_words_holder.count].data);

        ad_words_holder.count++;
    }

    fclose(file);

    return ad_words_holder;
}

void writeToFileBinary(const char *filename, AD_WORDS_HOLDER ad_words_holder) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    fwrite(&ad_words_holder, sizeof(AD_WORDS_HOLDER), 1, file);

    fclose(file);
}

AD_WORDS_HOLDER readFromFileBinary(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    AD_WORDS_HOLDER ad_words_holder;

    fread(&ad_words_holder, sizeof(AD_WORDS_HOLDER), 1, file);

    fclose(file);

    return ad_words_holder;
}


int main_projeto(int argc, const char *argv[]) {

    srand(time(NULL));

    int linhasC1 = 7;
    int colunasC1 = MAX_COLS_PALS;


    char dadosC1[][MAX_COLS_PALS] = {
            "o",
            "Ola",
            "xpto",
            "LP",
            "1",
            "aba",
            "fgagj9"
    };

    int linhasC2 = 4;
    int colunasC2 = MAX_COLS_PALS;

    char dadosC2[][MAX_COLS_PALS] = {
            "b",
            "MunDo",
            "LP",
            "aba"
    };

    char dadosarray[] = {1,2,3,4,5,6,7};

    char palavra[8]="";
    char *valor = palavra;
    int sizeAD=20;

    //Criação da matrix TESTE c1
    char **DynamicMatrixC1 = (char **) create_Dynamic_Matrix(linhasC1, colunasC1);
    fill_Matrix(DynamicMatrixC1, linhasC1, colunasC1, dadosC1);

    //Criação da matrix TESTE c2
    char **DynamicMatrixC2 = create_Dynamic_Matrix(linhasC2, colunasC2);
    fill_Matrix(DynamicMatrixC2, linhasC2, colunasC2, dadosC2);

    char **ufp6 = seach_string_word("la",DynamicMatrixC1,linhasC1);

    char ** ufp26 = string_to_binary(ufp6,1);

    //Criação do Array Dinamico
    AD_WORDS_HOLDER array_dinamico = ARRDYN_WORDS_HOLDER(NUMROWS);
    inserir_ordenado(array_dinamico, dadosarray);

    printArray(array_dinamico);

    check_segment(DynamicMatrixC1,DynamicMatrixC2,6,3);

    print_Matrix(DynamicMatrixC1, linhasC1,colunasC1);

    char ** DynamicMatrixCodesC1 = string_to_binary(DynamicMatrixC1,linhasC1);

    print_Matrix(DynamicMatrixCodesC1, linhasC1,colunasC1);

    free_Dynamic_Matrix(DynamicMatrixCodesC1,linhasC1);

    AD_WORDS_HOLDER ad_words_holder = ARRDYN_WORDS_HOLDER(10);
    ad_words_holder.size = 10;
    ad_words_holder.count = 3;
    ad_words_holder.pvalwordsholder = malloc(sizeof(VAL_AD_WORDS_HOLDER) * ad_words_holder.size);


    ad_words_holder = inserir_ordenado(ad_words_holder, "10");
    ad_words_holder = inserir_ordenado(ad_words_holder, "5");
    ad_words_holder = inserir_ordenado(ad_words_holder, "8");

    int posicao_para_eliminar = 1;
    ad_words_holder = eliminar_elemento(ad_words_holder, posicao_para_eliminar);

    for (int i = 0; i < ad_words_holder.count; i++) {
        printf("%ld\n", ad_words_holder.pvalwordsholder[i].data);
    }

    // os varios frees
    free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
    free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);
    free(val_Ad_Words_Holder);
    //free_Dynamic_Matrix(DynamicMatrixCodesC1, linhasC1);


    write_to_file("output",ad_words_holder);
    //read_from_file("output");
    free(ad_words_holder.pvalwordsholder);

    return 0;
}