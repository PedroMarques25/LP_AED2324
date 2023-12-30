/**
    * ==================================================================================================================
    * PROJETO REALIZADO POR:                                                                                           *
    * - PEDRO MARQUES - 38688                                                                                          *
    * - PEDRO MONTEIRO  - 2022110782                                                                                             *
    * - DIONE ARANTES - 40395                                                                                             *
    * ==================================================================================================================
    * @todo
    * 2
    * funcao que converte decimal para binario
    * funcao que converte string ou char para binario
    *
    * 3
    * funcao de inserir e remover para uma matriz, e o respestivo binario
    *
    * 4
    * correr ambos as matrizes e verificar combinacoes iguais
    *
    * 5
    * passar como argumento a string de pesquisa, corres as matrizes e ves
    * onde se enquadra o segmento em cada parcela da matriz
    * dar print dessa palavra e posicao e versao binaria
    * (passar por argumento para a que converte para binario)
    *
    * 6
    * Ordenar por ordem crescente ou decrescente
    * crescente encontrar o minimo e passar esse para a ultima posicao
    * descrescente encontrar o maximo e passar esse para a primeira posicao
    *
    * 7
    * criar uma struct que deia para passar ambas as matrizes
    *
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
VAL_AD_WORDS_HOLDER val_Ad_Words_Holder;
NODE_LL_WORDS_HOLDER Node_Ll_Words_Holder;

char * UFP6[] = { //UFP6 CORRIGIDO
        // 0          1           2         3         4           5          6           7          8           9           a              b           c            d            e            f            g            h              i            j              k             l             m            n             o             p             q              r            s             t             u             v              w             x                y             z              A             B              C               D             E               F             G               H              I              J             K               L              M            N               O                P              Q              R             S               T               U               V              W            X               Y             Z
        "0",  "1",  "10", "11",  "100", "101", "110", "111", "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111", "10000", "10001", "10010", "10011", "10100", "10101", "10110", "10111", "11000", "11001", "11010", "11011", "11100", "11101", "11110", "11111", "100000", "100001", "100010", "100011", "100100", "100101", "100110", "100111", "101000", "101001", "101010", "101011", "101100", "101101", "101110", "101111", "110000", "110001", "110010", "110011", "110100", "110101", "110110", "110111", "111000", "111001", "111010", "111011", "111100", "111101",
};


char** create_Dynamic_Matrix(int lines, int cols) {
    char** matrix = (char**)calloc(lines, sizeof(char*));
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


/**requisito 2
 *
 * a codificação tem que ser feito perante  UFP6
 * temos que criar uma funcao para criar a matriz vazia
 * funcao para adicionar os valores na matriz
 * a codificacao tem que ser feita pertante ufp6, em vez de usar acii temos que passar por UFP6[]
 * passar como argumento o array UFP6 para depois comparar o valor que temos com esse
 *
 *
 * **/

/** req 2 **/
int decimal_to_binary(int value, char **matriz, int line, int column) {
    //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    // counter for binary array

    printf("\nThe string in binary is ");

    int h = 0;
    char charvalue='\0';
    int binaryNum[8];

    while (value > 0) {
        // storing remainder in binary array
        binaryNum[h] = value % 2;
        value = value / 2;
        h++;
    }
    // printing binary array in reverse order
    for (int j = h - 1; j >= 0; j--, column++) {
        printf("%d", binaryNum[j]);
        charvalue = binaryNum[j]+'0';
        matriz[line][column] = charvalue;
    }
    return column;
}
/** req 2 **/
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

/*
 *
 * funlção para inserir os dados num char e uma nos binarios ou seja uma big função para 2 mini funções
 * função para chamar structs pois estas vao ter
void add_to_matrix(DYNAMICMATRIX *matrix, int row, int col, char value) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        *(*(matrix->data + row) + col) = value;
    } else {
        printf("Posição inválida na matriz.\n");
    }
}*/

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

/** req 3
 * aqui podemos definir onde colocamos os determinados valores dentro das matrizes
 * para teste primeiro damos print a matriz inicial e depois print com a insercao
 *
 * **/


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

/** req 3 **/
void remove_from_matrix(DYNAMICMATRIX *matrix, int row, int col) {
    if (matrix != NULL && row >= 0 && row < matrix->rows && col >= 0 && col < matrix->cols) {
        // Deslocar os elementos da matriz para cobrir a posição removida
        for (int i = row; i < matrix->rows - 1; i++) {
            for (int j = col; j < matrix->cols - 1; j++) {
                *(*(matrix->data + i) + j) = *(*(matrix->data + i + 1) + j + 1);
            }
        }

        // Reduzir o número de linhas e colunas na matriz
        matrix->rows--;
        matrix->cols--;

        // Realocar memória para a matriz com o novo tamanho
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
void seach_string(const char *sequencia, const char *palavra[], int numPalavras) {

    for (int i = 0; i < numPalavras; i++) {
        //Verifica se a sequência de pesquisa ocorre na palavra
        if (strstr(palavra[i], sequencia) != NULL) {
            printf("%s\n", palavra[i]);
        }
    }
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

//novo fill array
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

int pesquisar_palavra(AD_WORDS_HOLDER ad_words_holder, const char *palavra) {
    // Supondo que desejamos pesquisar em todos os elementos
    for (int i = 0; i < ad_words_holder.count; i++) {
        if (strcmp((const char *) ad_words_holder.pvalwordsholder[i].wordsHolder.set1.DynamicMatrixPals, palavra) == 0) {
            // Palavra encontrada, retornar o código UFP6 associado a ela
            return ad_words_holder.pvalwordsholder[i].data;
        }
    }

    // Palavra não encontrada
    return -1;
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
        // Realizar a pesquisa apenas nos elementos desejados (ajuste conforme necessário)
        if (strcmp((const char *) list->head->data.set1.DynamicMatrixPals->data, palavra) == 0 ||
            (strcmp((const char *) list->head->data.set1.DynamicMatrixCodes->data, code)== 0)) {
            // Palavra encontrada, retornar o código UFP6 ou índice do elemento
            return list->head->data.set1.DynamicMatrixPals;
        }
    }

    return NULL;
}

void printArray(AD_WORDS_HOLDER array_dinamico) {
    for (int i = 0; i < array_dinamico.count; ++i) {
        printf("%ld", array_dinamico.pvalwordsholder[i].data);
        // Print other fields as needed
    }
    printf("\n");
}



int main_projeto(int argc, const char *argv[]) {

    srand(time(NULL)); //gera a aleatoriedade

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

    //Criação do Array Dinamico
    AD_WORDS_HOLDER array_dinamico = ARRDYN_WORDS_HOLDER(NUMROWS);
    inserir_ordenado(array_dinamico, dadosarray);

    printArray(array_dinamico);

    /*Criação da matrix Matrix1
    char **Matrix1 = create_Dynamic_Matrix(linhasC1, colunasC1);
    fill_Matrix(Matrix1, linhasC1, colunasC1, dadosC1);*/

    //fill_Matrix(Matrix1, LINES, COLS, (char[10]) palavra);

    /** Imprimir as matrizes para teste
     *
     *  printf("Matriz Dinâmica C1:\n");
     *  print_Matrix(DynamicMatrixC1, linhasC1, colunasC1);
     *  printf("\nMatriz Dinâmica C2:\n");
     *  print_Matrix(DynamicMatrixC2, linhasC2, colunasC2);
     *
     */



    /* teste decimal to binary e string to binary
     * decimal to binary com os numeros funciona bem, o string to binary não está a dar o
     * resultado esperado, por exemplo "aba" segundo o enunciado tem que dar:
     * 101010111010 , mas deu isto : 101010101111101010
     */

    // Exemplo de uso

    /* for(int j=0;j<7;j++){
         gerarPalavraAleatoria(palavra, 7);
         printf("\n");
         add_to_matrix(Matrix1, j, 0, 7, 20, valor);
     }*/
    // print_Matrix(Matrix1, linhasC1,colunasC1);

    check_segment(DynamicMatrixC1,DynamicMatrixC2,6,3);

    print_Matrix(DynamicMatrixC1, linhasC1,colunasC1);

    char ** DynamicMatrixCodesC1 = string_to_binary(DynamicMatrixC1,linhasC1);

    //check_segment(DynamicMatrixC1,DynamicMatrixCodesC1);
    //string_to_binary(Matrix1);
    //add_to_matrix(DynamicMatrixC1, 3, 4, 4, 5, valor,palavra);
    // a usar notação array funciona, apontadores já não(nao sei porquê)
    /*
     * free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
     * free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);
     */
    print_Matrix(DynamicMatrixCodesC1, linhasC1,colunasC1);

    //free_Dynamic_Matrix(DynamicMatrixC1,linhasC1);
    free_Dynamic_Matrix(DynamicMatrixCodesC1,linhasC1);
    AD_WORDS_HOLDER ad_words_holder = ARRDYN_WORDS_HOLDER(10);
    ad_words_holder.size = 10;
    ad_words_holder.count = 0;
    ad_words_holder.pvalwordsholder = malloc(ad_words_holder.size * sizeof(VAL_AD_WORDS_HOLDER));

    // Insert elements in sorted order
    ad_words_holder = inserir_ordenado(ad_words_holder, "10");
    ad_words_holder = inserir_ordenado(ad_words_holder, "5");
    ad_words_holder = inserir_ordenado(ad_words_holder, "8");

    int posicao_para_eliminar = 2;
    ad_words_holder = eliminar_elemento(ad_words_holder, posicao_para_eliminar);

    // Inicializar alguns elementos fictícios para o exemplo
    ad_words_holder.pvalwordsholder[0].data = 123;
    strcpy((char *) ad_words_holder.pvalwordsholder[0].wordsHolder.set1.DynamicMatrixPals, "exemplo1");

    ad_words_holder.pvalwordsholder[1].data = 456;
    strcpy((char *) ad_words_holder.pvalwordsholder[0].wordsHolder.set1.DynamicMatrixPals, "exemplo2");

    ad_words_holder.pvalwordsholder[2].data = 789;
    strcpy((char *) ad_words_holder.pvalwordsholder[0].wordsHolder.set1.DynamicMatrixPals, "exemplo3");

    const char *palavra_a_pesquisar = "exemplo2";
    int resultado_pesquisa = pesquisar_palavra(ad_words_holder, palavra_a_pesquisar);

    if (resultado_pesquisa != -1) {
        printf("A palavra \"%s\" foi encontrada com o código UFP6: %d\n", palavra_a_pesquisar, resultado_pesquisa);
    } else {
        printf("A palavra \"%s\" não foi encontrada.\n", palavra_a_pesquisar);
    }

    // Print the result
    for (int i = 0; i < ad_words_holder.count; i++) {
        printf("%ld\n", ad_words_holder.pvalwordsholder[i].data);
    }

    // os varios frees
    free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
    free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);
    //free_Dynamic_Matrix(DynamicMatrixCodesC1, linhasC1); ESTE FREE EM CONCRETO CAUSA SEGMENTATION FAULT
    free(ad_words_holder.pvalwordsholder);


    //  LL_WORDS_HOLDER wordList;
    // wordList.head = NULL;
    //  wordList.count = 0;

    // WORDS_HOLDER data1;

    //  strcpy(data1..set1.[0], "Apple");
    // data1.codes[0] = 101;

    // strcpy(data1.words[1], "Banana");
    // data1.codes[1] = 102;

    // strcpy(data1.words[2], "Cherry");
    // data1.codes[2] = 103;


    //  for (int i = 0; i < 3; i++) {
    //      printf("Word: %s, Code: %d\n", data1.words[i], data1.codes[i]);
    //  }

    //  char update1[] = "2023-01-01";
    //   insertNode(&wordList, data1, update1);

    //  for (int i = 0; i < 3; i++) {
    //      printf("Word: %s, Code: %d,%s\n", wordList.head->data.words[i], wordList.head->data.codes[i],wordList.head->lastUpdate);
    //}



    return 0;
}