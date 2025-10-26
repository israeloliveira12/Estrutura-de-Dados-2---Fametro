Utilitários de Ponteiros em C

Coleção de programas e funções em C demonstrando manipulação avançada de ponteiros, manipulação de strings e operações aritméticas básicas. Projetado para operações limpas, reutilizáveis e eficientes com ponteiros.

Módulos
1. Troca de Valores

Função para trocar dois valores inteiros usando ponteiros.

void swap(int *a, int *b);

2. Análise de Array

Determina os valores máximo e mínimo de um array utilizando ponteiros.

void findMaxMin(int *array, int size, int *max, int *min);

3. Inspeção de Memória

Demonstra como acessar o valor de uma variável, seu endereço, o valor do ponteiro e o valor apontado.

4. Dobro do Valor

Função que dobra o valor de um inteiro via ponteiro.

void doubleValue(int *num);

5. Cópia de String

Copia uma string para outra usando ponteiros, sem utilizar strcpy.

void copyString(char *source, char *destination);

6. Contador de Vogais e Consoantes

Conta vogais e consoantes de uma string e retorna os valores via ponteiros.

void countVowelsConsonants(char *str, int *vowels, int *consonants);

7. Inversão de String In-Place

Inverte uma string diretamente na memória usando ponteiros.

void reverseString(char *str);

8. Calculadora Básica

Realiza adição, subtração, multiplicação e divisão entre dois números float e armazena os resultados via ponteiros.

void calculator(float a, float b, float *sum, float *sub, float *mul, float *div);

Conceitos-Chave

Ponteiros: armazenam endereços de memória, permitindo manipulação indireta de variáveis.

Desreferenciação (*): acessar ou modificar o valor de um endereço.

Operador &: obter o endereço de uma variável.

Operações in-place: modificam os dados originais sem alocar memória adicional.
