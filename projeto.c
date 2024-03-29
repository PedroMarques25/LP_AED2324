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

STOREWORDUFP6 *criarPalavraUFP6(char *palavra) {
    STOREWORDUFP6 *novaPalavra = (STOREWORDUFP6 *)malloc(sizeof(STOREWORDUFP6));
    if (novaPalavra == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    novaPalavra->palavra = strdup(palavra);

    char* codigoufp6=string_to_binary(palavra);

    novaPalavra->codigoUFP6 = strdup(codigoufp6);

    return novaPalavra;
}

// Função para criar uma matriz de palavras e códigos UFP6
DYNAMICMATRIX *criarMatrizDados() {
    DYNAMICMATRIX *matriz = (DYNAMICMATRIX *)malloc(sizeof(DYNAMICMATRIX));

    if (matriz == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }

    matriz->conjunto1 = NULL;
    matriz->conjunto2 = NULL;
    matriz->tamanho1 = 0;
    matriz->tamanho2 = 0;

    return matriz;
}

// Função para adicionar uma palavra com seu código UFP6 a um conjunto
void adicionarPalavra(DYNAMICMATRIX *matriz, int conjunto, char *palavra) {
    STOREWORDUFP6 *novaPalavra = criarPalavraUFP6(palavra);

    if (conjunto == 1) {
        matriz->conjunto1 = realloc(matriz->conjunto1, (matriz->tamanho1+1) * sizeof(STOREWORDUFP6 *));
        matriz->conjunto1[matriz->tamanho1] = novaPalavra;
        matriz->tamanho1++;
    } else if (conjunto == 2) {
        matriz->conjunto2 = realloc(matriz->conjunto2, (matriz->tamanho2+1) * sizeof(STOREWORDUFP6 *));
        matriz->conjunto2[matriz->tamanho2] = novaPalavra;
        matriz->tamanho2++;
    }
}

// Função para listar na consola as palavras e respectivos códigos UFP6
void listarPalavras(DYNAMICMATRIX *matriz, int conjunto) {
    if (conjunto == 1) {
        for (int i = 0; i < matriz->tamanho1; i++) {
            printf("Palavra: %s, Codigo UFP6: %s\n", matriz->conjunto1[i]->palavra, matriz->conjunto1[i]->codigoUFP6);
        }
    } else if (conjunto == 2) {
        for (int i = 0; i < matriz->tamanho2; i++) {
            printf("Palavra: %s, Codigo UFP6: %s\n", matriz->conjunto2[i]->palavra, matriz->conjunto2[i]->codigoUFP6);
        }
    }
}

// Função para liberar a memória alocada para as estruturas de dados
void liberarMemoria(DYNAMICMATRIX *matriz) {
    for (int i = 0; i < matriz->tamanho1; i++) {
        free(matriz->conjunto1[i]->palavra);
        free(matriz->conjunto1[i]->codigoUFP6);
        free(matriz->conjunto1[i]);
    }
    free(matriz->conjunto1);

    for (int i = 0; i < matriz->tamanho2; i++) {
        free(matriz->conjunto2[i]->palavra);
        free(matriz->conjunto2[i]->codigoUFP6);
        free(matriz->conjunto2[i]);
    }
    free(matriz->conjunto2);

    free(matriz);
}
// O(n)
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
//O(n)
/*void free_Dynamic_Matrix(char** matrix, int lines) {
    for (int i = 0; i < lines; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
//O(n)
void fill_Matrix(char** matrix, int lines, int cols, char dados[][MAX_COLS_PALS]) {
    for (int i = 0; i < lines; i++) {
        if (matrix[i] == NULL) {
            printf("Erro: matriz[%d] não alocada corretamente.\n", i);
            exit(EXIT_FAILURE);
        }

        strncpy(matrix[i], dados[i], cols);
    }
}*/
/**requisito 2 **/
//O(n)
int decimal_to_binary(int value, char *matriz, int column) {
    //  printf("TESTE-> valor em decimal fica %d\n", value);
    //array com os valores de binario
    // counter for binary array

    //printf("\nThe string in binary is ");

    int h = 0;
    char charvalue='\0';
    int binaryNum[8];

    while (value > 0) {

        binaryNum[h] = value % 2;
        value = value / 2;
        h++;
    }

    for (int j = h - 1; j >= 0; j--, column++) {
        //printf("%d", binaryNum[j]);
        charvalue = binaryNum[j]+'0';
        matriz[column] = charvalue;
    }
    return column;
}

/** req 2 (cont.)**/
//O(n^2)
char* string_to_binary(char* palavra) {
    char* codigoufp6;
    codigoufp6 = malloc(MAX_COLS_UFP6);

        size_t size = strlen(palavra);

        int g = 0;
        int value;

        for (int j = 0; j < size; j++) {
            value = palavra[j] - '0';
            if (isupper(palavra[j])) {
                value = value + 19;
                g = decimal_to_binary(value, codigoufp6, g);
            } else if (value <= 9) {
                g = decimal_to_binary(value, codigoufp6,  g);
            } else {
                value = value - 39;
                g = decimal_to_binary(value, codigoufp6, g);
            }
        }
    codigoufp6[g] = '\0';

    return codigoufp6;
}
/** req 3**/
char* gerarPalavraAleatoria() {
    char temppalavra[MAX_COLS_PALS];
    char *palavra;
    const char caracteresPermitidos[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int lenCaracteresPermitidos = strlen(caracteresPermitidos);
    const char numerocaracteresPermitidos[] = "1234567";
    int lennumeroCaracteresPermitidos= strlen(numerocaracteresPermitidos);
    char tamanho = numerocaracteresPermitidos[rand() % lennumeroCaracteresPermitidos];
   tamanho = tamanho -'0';
    for (int i = 0; i < tamanho; i++) {
        temppalavra[i] = caracteresPermitidos[rand() % lenCaracteresPermitidos];
    }
    temppalavra[tamanho] = '\0'; // Adicionar o char nulo no final
    palavra= strdup(temppalavra);

    return palavra;
}
void adicionarPalavrarandom(DYNAMICMATRIX *matriz, int conjunto) {
    char* palavra=gerarPalavraAleatoria();

    STOREWORDUFP6 *novaPalavra = criarPalavraUFP6(palavra);

    if (conjunto == 1) {
        matriz->conjunto1 = realloc(matriz->conjunto1, (matriz->tamanho1+1) * sizeof(STOREWORDUFP6 *));
        matriz->conjunto1[matriz->tamanho1] = novaPalavra;
        matriz->tamanho1++;
    } else if (conjunto == 2) {
        matriz->conjunto2 = realloc(matriz->conjunto2, (matriz->tamanho2+1) * sizeof(STOREWORDUFP6 *));
        matriz->conjunto2[matriz->tamanho2] = novaPalavra;
        matriz->tamanho2++;
    }
}



//O(n^2)
void removepalavra(DYNAMICMATRIX *matrix, char* palavra,int conjunto) {

    int j;
    int value;
    if (conjunto == 1) {
        for ( int i=0;i<matrix->tamanho1;i++) {
           value = strcmp(matrix->conjunto1[i]->palavra,palavra);
            if(value==0){
                j=i;
                while( j!=matrix->tamanho1) {
                    matrix->conjunto1[j]->palavra=matrix->conjunto1[j+1]->palavra;
                    matrix->conjunto1[j]->codigoUFP6=matrix->conjunto1[j+1]->codigoUFP6;
                    j++;
                }free(matrix->conjunto1[i]->palavra);
                 free(matrix->conjunto1[i]->codigoUFP6);
                 matrix->conjunto1 = realloc(matrix->conjunto1, (matrix->tamanho1-1) * sizeof(STOREWORDUFP6 *));
                 matrix->tamanho1--;
            }
        }
    } else if (conjunto == 2){
        for (int i=0;i<matrix->tamanho2;i++) {
           value = strcmp(matrix->conjunto2[i]->palavra,palavra);
            if(value==0){
                j=i;
                while( j!=matrix->tamanho1) {
                    matrix->conjunto2[i]->palavra=matrix->conjunto2[i+1]->palavra;
                    matrix->conjunto2[j]->codigoUFP6=matrix->conjunto2[j+1]->codigoUFP6;
                    j++;
                }free(matrix->conjunto2[i]->palavra);
                free(matrix->conjunto2[i]->codigoUFP6);
                matrix->conjunto2 = realloc(matrix->conjunto2, (matrix->tamanho2-1) * sizeof(STOREWORDUFP6 *));
                matrix->tamanho2--;
            }
        }
}else {
        printf("Posição inválida na matriz.\n");
    }
}

/** req 4 **/
//O(n^2)
void check_segment(DYNAMICMATRIX *matriz) {
    int value;
    STOREWORDUFP6** primeiro = matriz->conjunto1;
    STOREWORDUFP6** segundo = matriz->conjunto2;
    for(int i=0;i<matriz->tamanho1;i++) {
        for (int j = 0; j <matriz->tamanho2;j++){
            value = strcmp(primeiro[i]->codigoUFP6,segundo[j]->codigoUFP6);
            if(value == 0){
                printf("\n");
                printf("%s %s sao combinacoes iguais\n",matriz->conjunto1[i]->codigoUFP6,matriz->conjunto2[i]->codigoUFP6);
            }
        }
    }
}

/** req 5 **/
//O(n)
void seach_string_word(char *sequencia,  DYNAMICMATRIX matrix) {

    for (int i = 0; i < matrix.tamanho1; i++) {
        //Verifica se a sequência de pesquisa ocorre na palavra
        if (strstr(matrix.conjunto1[i]->palavra, sequencia) != NULL) {
            printf("palavra com sequencia de pesquisa: %s  %s\n", matrix.conjunto1[i]->palavra, matrix.conjunto1[i]->codigoUFP6);
        }
    }
        for (int i = 0; i < matrix.tamanho2; i++) {
            //Verifica se a sequência de pesquisa ocorre na palavra
            if (strstr(matrix.conjunto2[i]->palavra, sequencia) != NULL) {
                printf("palavra com sequencia de pesquisa: %s  %s\n", matrix.conjunto2[i]->palavra, matrix.conjunto2[i]->codigoUFP6);
            }
        }
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

WORDS_HOLDER Init_Wordsholder(DYNAMICMATRIX matrix) {
    // Allocate memory for the main structure
    WORDS_HOLDER *strt = (WORDS_HOLDER*)malloc(sizeof(WORDS_HOLDER));

    if (strt == NULL) {
        perror("Erro ao alocar memória para WORDS_HOLDER");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the first set of conjunto1
    strt->set1.conjunto1 = (STOREWORDUFP6 **)malloc(matrix.tamanho1 * sizeof(STOREWORDUFP6*));

    if (strt->set1.conjunto1 == NULL) {
        perror("Erro ao alocar memória para conjunto1");
        free(strt);  // Free the previously allocated memory
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the second set of conjunto2
    strt->set1.conjunto2 = (STOREWORDUFP6 **)malloc(matrix.tamanho2 * sizeof(STOREWORDUFP6*));

    if (strt->set1.conjunto2 == NULL) {
        perror("Erro ao alocar memória para conjunto2");
        free(strt->set1.conjunto1);  // Free the previously allocated memory
        free(strt);  // Free the main structure memory
        exit(EXIT_FAILURE);
    }

    // Copy data from matrix to strt
    for(int i = 0; i < matrix.tamanho1; i++) {
        strt->set1.conjunto1[i] = (STOREWORDUFP6 *)malloc(sizeof(STOREWORDUFP6));
        if (strt->set1.conjunto1[i] == NULL) {
            perror("Erro ao alocar memória para conjunto1[i]");
            // You might want to free allocated memory before exiting
            exit(EXIT_FAILURE);
        }
        strt->set1.conjunto1[i]->palavra = matrix.conjunto1[i]->palavra;
        strt->set1.conjunto1[i]->codigoUFP6 = matrix.conjunto1[i]->codigoUFP6;
    }
        strt->set1.tamanho1=matrix.tamanho1;
    for(int i = 0; i < matrix.tamanho2; i++) {
        strt->set1.conjunto2[i] = (STOREWORDUFP6 *)malloc(sizeof(STOREWORDUFP6));
        if (strt->set1.conjunto2[i] == NULL) {
            perror("Erro ao alocar memória para conjunto2[i]");
            // You might want to free allocated memory before exiting
            exit(EXIT_FAILURE);
        }
        strt->set1.conjunto2[i]->palavra = matrix.conjunto2[i]->palavra;
        strt->set1.conjunto2[i]->codigoUFP6 = matrix.conjunto2[i]->codigoUFP6;
    }
    strt->set1.tamanho2=matrix.tamanho2;
    return *strt;
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
                current = newNode;
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
        list->head = newNode;
    } else {
        NODE_LL_WORDS_HOLDER *current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current = newNode;
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
    } else {

        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current = current->next;
        if (current->next != NULL) {
            current = current->prev;
        }
    }

    free(current);
    list->count--;
}

DYNAMICMATRIX* pesquisar_palavra_ll(LL_WORDS_HOLDER *list, const char *palavra,const char *code) {
    for (int i = 0; i < list->count; i++) {

        if (strcmp((const char *) list->head->data.set1.conjunto1, palavra) == 0 ||
            (strcmp((const char *) list->head->data.set1.conjunto1, code)== 0)) {

            return (DYNAMICMATRIX *) list->head->data.set1.conjunto1;
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
        if (ad_words_holder.pvalwordsholder->wordsHolder.set1.conjunto1 != NULL) {
            fprintf(file, "Words: %s,Data: %ld\n",ad_words_holder.pvalwordsholder->wordsHolder.set1.conjunto1, ad_words_holder.pvalwordsholder->data);
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

        sscanf(line, "%s %ld", ad_words_holder.pvalwordsholder[ad_words_holder.count].wordsHolder.set1.conjunto1, &ad_words_holder.pvalwordsholder[ad_words_holder.count].data);

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

    DYNAMICMATRIX *matriz = criarMatrizDados();

    // Adicionar palavras aos conjuntos
    for(int i =0;i<10;i++){
        adicionarPalavrarandom(matriz, 1);
    }
    for(int i =0;i<10;i++){
        adicionarPalavrarandom(matriz, 2);
    }
    //removepalavra(matriz,"Palavra2",1);
    check_segment(matriz);

    seach_string_word("al",*matriz);

    printf("Conjunto 1:\n");
    listarPalavras(matriz, 1);

    printf("\nConjunto 2:\n");
    listarPalavras(matriz, 2);

    WORDS_HOLDER data1 = Init_Wordsholder(*matriz);
    STOREWORDUFP6** primeiro = data1.set1.conjunto1;
    STOREWORDUFP6** segundo = data1.set1.conjunto2;
    DYNAMICMATRIX  size = data1.set1;

    for (int i = 0; i < size.tamanho1; i++) {
       printf("Wordholder: %s code:%s\n", primeiro[i]->palavra,primeiro[i]->codigoUFP6);
   }
    for (int j = 0; j < size.tamanho2; j++) {
        printf("Wordholde: %s code:%s\n",segundo[j]->palavra,segundo[j]->codigoUFP6);
    }

    LL_WORDS_HOLDER wordList;
    wordList.head = NULL;
    wordList.count = 0;

    char update1[] = "1/1/23";
    char update2[] = "2/1/23";
    char update3[] = "3/1/23";
    char update4[] = "4/1/23";

    insertNode(&wordList, data1, update1);
    insertNodeAtIndex(&wordList, data1, update2,0);



    for (int i = 0; i < wordList.head->data.set1.tamanho1; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->data.set1.conjunto1[i]->palavra, wordList.head->data.set1.conjunto1[i]->codigoUFP6);
  }
    for (int i = 0; i < wordList.head->data.set1.tamanho2; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->data.set1.conjunto2[i]->palavra, wordList.head->data.set1.conjunto2[i]->codigoUFP6);
    }
    printf("%s",wordList.head->lastUpdate);
    for (int i = 0; i < wordList.head->data.set1.tamanho1; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->next->data.set1.conjunto1[i]->palavra, wordList.head->next->data.set1.conjunto1[i]->codigoUFP6);
    }
    for (int i = 0; i < wordList.head->data.set1.tamanho2; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->next->data.set1.conjunto2[i]->palavra, wordList.head->next->data.set1.conjunto2[i]->codigoUFP6);
    }
    printf("%s",wordList.head->next->lastUpdate);

    deleteNodeAtIndex(&wordList,0);

    for (int i = 0; i < wordList.head->data.set1.tamanho1; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->data.set1.conjunto1[i]->palavra, wordList.head->data.set1.conjunto1[i]->codigoUFP6);
    }
    for (int i = 0; i < wordList.head->data.set1.tamanho2; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->data.set1.conjunto2[i]->palavra, wordList.head->data.set1.conjunto2[i]->codigoUFP6);
    }
    printf("%s",wordList.head->lastUpdate);
    for (int i = 0; i < wordList.head->data.set1.tamanho1; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->next->data.set1.conjunto1[i]->palavra, wordList.head->next->data.set1.conjunto1[i]->codigoUFP6);
    }
    for (int i = 0; i < wordList.head->data.set1.tamanho2; i++) {
        printf("llWords: %s, Code: %s\n", wordList.head->next->data.set1.conjunto2[i]->palavra, wordList.head->next->data.set1.conjunto2[i]->codigoUFP6);
    }
    printf("%s",wordList.head->next->lastUpdate);

    // Liberar memória alocada
   liberarMemoria(matriz);



    //Criação da matrix TESTE c1
    //char **DynamicMatrixC1 = (char **) create_Dynamic_Matrix(linhasC1, colunasC1);
    //fill_Matrix(DynamicMatrixC1, linhasC1, colunasC1, dadosC1);

    //Criação da matrix TESTE c2
    //char **DynamicMatrixC2 = create_Dynamic_Matrix(linhasC2, colunasC2);
    //fill_Matrix(DynamicMatrixC2, linhasC2, colunasC2, dadosC2);

    //char **ufp6 = seach_string_word("la",DynamicMatrixC1,linhasC1);

    //gerarPalavraAleatoria(palavra,26);



    //Criação do Array Dinamico
    //AD_WORDS_HOLDER array_dinamico = ARRDYN_WORDS_HOLDER(NUMROWS);
    //inserir_ordenado(array_dinamico, dadosarray);

    //printArray(array_dinamico);

    //check_segment(DynamicMatrixC1,DynamicMatrixC2,6,3);

   // print_Matrix(DynamicMatrixC1, linhasC1,colunasC1);




    //AD_WORDS_HOLDER ad_words_holder = ARRDYN_WORDS_HOLDER(10);
    //ad_words_holder.size = 10;
    //ad_words_holder.count = 3;
    //ad_words_holder.pvalwordsholder = malloc(sizeof(VAL_AD_WORDS_HOLDER) * ad_words_holder.size);


    //ad_words_holder = inserir_ordenado(ad_words_holder, "10");
    //ad_words_holder = inserir_ordenado(ad_words_holder, "5");
    //ad_words_holder = inserir_ordenado(ad_words_holder, "8");

    //int posicao_para_eliminar = 1;
    //ad_words_holder = eliminar_elemento(ad_words_holder, posicao_para_eliminar);

    //for (int i = 0; i < ad_words_holder.count; i++) {
      //  printf("%ld\n", ad_words_holder.pvalwordsholder[i].data);
    //}

    // os varios frees
   // free_Dynamic_Matrix(DynamicMatrixC1, linhasC1);
    //free_Dynamic_Matrix(DynamicMatrixC2, linhasC2);
    //free(val_Ad_Words_Holder);
    //free_Dynamic_Matrix(DynamicMatrixCodesC1, linhasC1);


//    write_to_file("output",ad_words_holder);
  //  writeToFileBinary("outputbinary",ad_words_holder);
    //read_from_file("output");
    //free(ad_words_holder.pvalwordsholder);

    return 0;
}
