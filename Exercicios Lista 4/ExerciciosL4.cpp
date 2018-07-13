#include <stdio.h>
#define ex3


#ifdef ex1
/*1 - Escreva um programa que tenha os vetores com as inicializacoes abaixo.
    Imprima-os no video. (utilize vetores unidimensional)

    string -> isto e' um teste de string dos alunos do 2. ciclo -> variavel
              global e imprimir como string
    string -> teste de vetores de string -> variavel local e imprimir todos os
              caracteres porem elemento por elemento*/
char texto1[] = "isto e' um teste de string dos alunos do 2. ciclo";
int main() {
    static char texto2[] = "teste de vetores de string";
    int i;
    printf("\nTexto utilizando string: %s",texto1);
    printf("\nCaractere por caractere: ");
    for(i=0;i<27;i++) {
        printf("%c ",texto2[i]);
    }
}
#endif
/*2 - Reescreva o exercicio anterior utilizando um vetor multidimensional.*/
#ifdef ex2
int main() {
    static char texto[2][50] = {"isto e' um teste de string dos alunos do 2. ciclo","teste de vetores de string"};
    int i;
    printf("\nUtilizando string: %s",texto[0]);
    printf("\nCaractere por caractere: ");
    for(i=0;i<50;i++) {
        printf("%c ",texto[1][i]);

    }
}
#endif

#ifdef ex3
/*
3 - Escreva um programa para receber um nome via teclado e imprima-o no video
    no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome                                    nome
                nome                nome
                          nome*/
int main() {
	char nome[20];
	puts("\nDigite seu nome: ");
	gets(nome);
    printf("\n        10        20        30        40        50");
    printf("\n12345678901234567890123456789012345678901234567890\n");
    printf("  %s                                       %s",nome,nome);
    printf("\n            %s                   %s",nome,nome);
    printf("\n                      %s",nome);
}
#endif

#ifdef ex4

/*4 - Escreva um programa para receber 3 strings de ate 10 caracteres cada via
    teclado e imprima-as no video no seguinte formato:
    (utilize vetores unidimensionais)

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        string1             string2             string3*/

int main() {
	char texto1[10],texto2[10],texto3[10];
    puts("\nTexto 1: ");
    gets(texto1);
    puts("\nTexto 2: ");
    gets(texto2);
    puts("\nTexto 3: ");
    gets(texto3);
    printf("\n        10        20        30        40        50        60");
    printf("\n123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %s                   %s                   %s",texto1,texto2,texto3);
}
#endif

#ifdef ex5

/*5 - Reescreva o exercicio anterior utilizando um vetor multidimensional.*/

int main() {
	char texto[3][10];
	int i,j;
	for(i=0;i<3;i++) {
		printf("\nTexto %d: ",i+1);
		gets(texto[i]);
	}
	printf("\n        10        20        30        40        50        60");
    printf("\n123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %s                   %s                   %s",texto[0],texto[1],texto[2]);
}
#endif
