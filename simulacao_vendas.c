/* Trabalho N2 - Algoritmos I
   Prof: Alessandro Joao Brassanini
   Aluno: Hiago Brambatti

   Simula um dia de vendas de uma loja.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUTOS 200
#define MAX_CLIENTES 50

int main(){

    float preco[MAX_PRODUTOS];
    int compra[MAX_CLIENTES];
    int qtdProdutos, qtdClientes;
    int i;
    float total = 0;

    srand(time(NULL)); // semente pra mudar os numeros toda vez

    qtdProdutos = (rand() % MAX_PRODUTOS) + 1;
    qtdClientes = (rand() % MAX_CLIENTES) + 1;

    // gera o preco de cada produto (de 500 a 10000 centavos)
    for(i=0; i<qtdProdutos; i++){
        int cent = (rand() % 9501) + 500;
        preco[i] = cent / 100.0;
    }

    // cada cliente compra um produto qualquer
    for(i=0; i<qtdClientes; i++){
        compra[i] = rand() % qtdProdutos;
    }

    printf("        SIMULACAO DE UM DIA DE VENDAS\n");

    printf("A loja tem %d produtos hoje\n", qtdProdutos);
    printf("Apareceram %d clientes hoje\n\n", qtdClientes);

    printf("LISTA DE PRODUTOS E PRECOS\n");
    for(i=0; i<qtdProdutos; i++){
        printf("Produto %3d -> R$ %6.2f\n", i, preco[i]);
    }

    printf("\nCOMPRAS DOS CLIENTES\n");

    for(i=0; i<qtdClientes; i++){
        printf("Cliente %2d comprou o produto %3d  (R$ %6.2f)\n", i, compra[i], preco[compra[i]]);
        total = total + preco[compra[i]];
    }

    printf("\n------ RESUMO DO DIA ------\n");
    printf("Total de clientes atendidos: %d\n", qtdClientes);
    printf("Total vendido no dia: R$ %.2f\n", total);
    printf("Valor medio por cliente: R$ %.2f\n", total/qtdClientes);

    printf("\n");
    system("pause");
    return 0;
}
