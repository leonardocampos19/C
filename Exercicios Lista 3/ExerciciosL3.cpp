#include <stdio.h>
#include <locale.h>
#define ex3

#ifdef ex1
/*1 - Escreva um programa que tenha os vetores com as inicializacoes abaixo e
    imprima-os no video.
    valores -> 1,10,100,1000,10000,100000,1000000 -> variavel global
    valores -> 1.1,103.34,156987012.456,33.78954e+30 -> variavel local*/

int vet[] = {1,10,100,1000,10000,100000,1000000};

int main() {
	int i = 0;
	static float val[] = {1.1,103.34,156987012.456,33.78954e+30};

	for(i=0;i<7;i++) {
		printf("%i ",vet[i]);
	}
	printf("\n");
	for(i=0;i<4;i++) {
		printf("%.2f ",val[i]);
	}
}
#endif // ex1

#ifdef ex2
/*2 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/
int inteiro[3];
float flutuante[3];
long longo[3];
double dobro[3];
unsigned semsinal[3];
int main() {
	int i;

	for(i=0; i<3; i++) {
		printf("\nDigite um valor para INT: ");
		scanf("%d",&inteiro[i]);
		printf("\nDigite um valor para LONG: ");
		scanf("%ld",&longo[i]);
		printf("\nDigite um valor para UNSIGNED: ");
		scanf("%u",&semsinal[i]);
		printf("\nDigite um valor para FLOAT: ");
		scanf("%f",&flutuante[i]);
		printf("\nDigite um valor para DOUBLE: ");
		scanf("%lf",&dobro[i]);
	}
	printf("\n        10        20        30        40        50\n");
    printf("12345678901234567890123456789012345678901234567890\n");
	for(i=0; i<3; i++) {
    printf("  %d                  %d                  %d\n",inteiro[i],longo[i],semsinal[i]);
    printf("            %.2f               %.2lf\n",flutuante[i],dobro[i]);
	}
}
#endif

#ifdef ex3
/*3 - Escreva um programa que receba via teclado 7 valores inteiros armazene-os
    em um vetor. Imprima no video o vetor mostrando o indice de cada posições
    e seu respectivo valor.*/
int main() {
	int vet[7],i;
	for(i=0;i<7;i++) {
		printf("\nDigite um valor inteiro: ");
		scanf("%d",&vet[i]);
	}
	for(i=0;i<7;i++) {
		printf("VET[%d] = %d\n",i,vet[i]);
	}
}
#endif // ex3

#ifdef ex4
/*4 - Escreva um programa declarando um vetor multidimensional de 2x3x3 de n.
    inteiros e inicialize-o com "0". Receba via teclado novos valores para
    todos os elementos do vetor e imprima no video estes novos conteudos.*/
int main() {
	static int vet[2][3][3] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int a,b,c;
	for(a=0;a<2;a++) {
		for(b=0;b<3;b++){
			for(c=0;c<3;c++) {
				printf("\nDigite um valor: ");
				scanf("%d",&vet[a][b][c]);
			}
		}
	}
	for(a=0;a<2;a++) {
		for(b=0;b<3;b++){
			for(c=0;c<3;c++) {
				printf("\n vet[%d][%d][%d] = %d\n",a,b,c,vet[a][b][c]);
			}
		}
	}
}
#endif

#ifdef ex5
/*5 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    multiplicacao "*", multiplique os elementos de mesmo indice dos 2 vetores
    e guarde o resultado num 3. vetor. Imprima na tela o indice, os valores e
    o resultado dos 6 elementos dos vetores.*/
int main() {
	int i, j, vet1[2][3], vet2[2][3], vetr[2][3];

	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			printf("\nDigite um valor para vet1: ");
			scanf("%d",&vet1[i][j]);
			printf("\nDigite um valor para vet2: ");
			scanf("%d",&vet2[i][j]);
			vetr[i][j] = vet1[i][j]*vet2[i][j];
		}
	}
	for(i=0;i<2;i++) {
		for(j=0;j<3;j++) {
			printf("\nvet1[%d][%d] = %d\nvet2[%d][%d] = %d\nvetr[%d][%d] = %d\n\n",i,j,vet1[i][j],i,j,vet2[i][j],i,j,vetr[i][j]);
		}
	}
}
#endif

