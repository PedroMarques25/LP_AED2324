# Sistema de Codificação Binária e Combinação de Palavras
## _Usando Funções e Estruturas Dinâmicas de Dados em C_

Projeto final de Algoritmo e Estrutura de Dados e Linguagens de Programação 1

# Membros de projeto

38688 - Pedro Marques 38688@ufp.edu.pt

2022110782 - Pedro Monteiro 2022110782@ufp.edu.pt

## Funcionalidades

1. Numa primeira fase pretende-se definir as estruturas de dados matriciais para
guardar os dois conjuntos de palavras e respectivos códigos UFP6 dessas palavras.
As estruturas de dados devem basear-se em matrizes dinâmicas de caracteres;
Devem ainda ser implementadas as funções para criar estas estruturas dinâmicas e
para listar na consola as palavras e respectivos códigos UFP6, na ordem em que se
encontram inseridas;

2. Implementar funções para a conversão de cada palavra (dos conjuntos de palavras)
para obter a sua representação UFP6, tal como descrito anteriormente;

3. Implementar funções para inserir e remover uma ou mais palavras e respectivas
codificações UFP6 nas estruturas de dados disponíveis. Inicialmente a inicialização
das estruturas deverá ser efectuada por geração aleatória das palavras e cálculo
dos respectivos códigos UFP6 (NB: mais tarde deve ser considerada e
implementada, também, a leitura de palavras através de ficheiros);

4. Implementar as funcionalidades que utilizam a versão codificada UFP6 das palavras
de ambos os conjuntos para explorar/determinar se existe alguma combinação do 1º
conjunto que seja igual a outra combinação de palavras do 2º conjunto;

5. Implementar funções de pesquisa de palavras nos conjuntos dados, ou seja, dada
uma sequência de caracteres de pesquisa, pretende-se encontrar todas as palavras
que contêm essa sequência de pesquisa. Deverá ainda ser possível obter os
códigos binários das palavras encontrados na pesquisa;

6. Implementar funções para ordenar os conjuntos de palavras e respectivos códigos
UFP6, por ordem alfabética (crescente ou decrescente) ou por ordem de tamanho
das palavras (também crescente ou decrescente);

7. Numa segunda fase pretende-se agregar numa estrutura de dados designada por
WORDS_HOLDER, as duas matrizes de palavras em alfanumérico e duas matrizes
respectivas de palavras codificadas em UFP6.

8. De seguida, pretende-se definir um Array Dinâmico AD_WORDS_HOLDER de vários
valores VAL_AD_WORDS_HOLDER. A estrutura que define o Array Dinâmico
AD_WORDS_HOLDER deverá conter: i) o tamanho do array, ii) o número de elementos
ocupados/inseridos no array e iii) um apontador para o primeiro elemento do array.
Por sua vez, a estrutura VAL_AD_WORDS_HOLDER irá conter: i) os dados de uma
WORDS_HOLDER (cf. um conjunto de 2 matrizes de palavras e respectivas matrizes
codificadas em UFP6) e ii) a data da última actualização/modificação das matrizes
de palavras e/ou respectivos códigos UFP6. Devem ser ainda criadas várias funções
para gerir o array dinâmico:
a. Criar e/ou redimensionar o array dinâmico;
b. Inserir um elemento no array, ordenado cronologicamente pelas datas de
modificação.
c. Inserir um elemento no array numa dada posição/índice do array, ajustando
as posições dos restantes elementos;
d. Eliminar um elemento no array que está numa dada posição/índice,
ajustando as posições dos restantes elementos;
e. Pesquisar palavras e respectivos códigos UFP6, apenas em determinados
elementos do array;

9. Posteriormente, deve definir-se uma Lista Ligada LL_WORDS_HOLDER de vários nós
NODE_LL_WORDS_HOLDER. A estrutura que define a Lista Ligada
LL_WORDS_HOLDER deverá conter: i) um apontador para o primeiro nó da lista
NODE_LL_WORDS_HOLDER e ii) o número de nós existentes/inseridos na lista. Por sua
vez, cada nó da lista NODE_LL_WORDS_HOLDER irá conter: i) uma WORDS_HOLDER
(cf. matrizes de palavras e respectivos códigos); ii) a data da última
actualização/modificação das matrizes; iii) um apontador para o próximo nó e outro
para o nó anterior. Devem ser ainda criadas várias funções para gerir a lista ligada:
a. Inserir um nó na lista, ordenado cronologicamente pelas datas de
modificação.
b. Inserir um nó numa dada posição/índice da sequência;
c. Eliminar um nó que está numa dada posição/índice;
d. Pesquisar palavras e respectivos códigos UFP6, apenas em determinados
nós da lista;

10. Pretende-se também utilizar ficheiros de texto para input e output de vários
conjuntos de palavras e respectivos códigos UFP6, i.e. escrever e ler informação
organizada de um ou mais conjuntos de palavras e respectivos códigos UFP6, em
ficheiros de texto. As funções de pesquisa de chaves definidas anteriormente podem
também ter como output ficheiros de texto;

11. Finalmente, deve-se permitir utilizar ficheiros binários para output e input de vários
conjuntos de palavras, i.e. escrever e ler informação organizada de um ou mais
conjuntos de palavras e respectivos códigos UFP6, em ficheiros binários.

● Funcionalidades implementadas:

1
2
3
4
5
7
8
9

● Funcionalidades parcialmente implementadas:

6
10
11

● Funcionalidades não implementadas:
