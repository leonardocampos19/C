#include <stdio.h>
#include <locale.h> // Necessário para utilizar a função "setlocale()"
#include <windows.h>
#define ex1

#ifdef ex1
/*
	1 - Escreva um programa e inicialize as variaveis do tipo char, int, short,
    long, unsigned(char, int, short, long), float e double com seus valores
    limites e imprima-os no video. Utilize variaveis globais para os valores
    positivos e locais para os negativos.
*/

//Valores positivos, variáveis globais.
char caractere = 127;
int inteiro = 32767;
short curto = 32767;
long longo = 2147483647;
unsigned char caractereSemSinal = 255;
unsigned int inteiroSemSinal = 65535;
unsigned short curtoSemSinal = 65535;
unsigned long longoSemSinal = 4294967295;
float pontoFlutuante = 3.4E+38;
double pontoFlutuanteLongo = 1.7E+308;

int main() {
	//Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

	//Valores negativos, variáveis locais.
	char caractereNegativo = -128;
	int inteiroNegativo = -32768;
	short curtoNegativo = -32768;
	long longoNegativo = -2147483648;
	float pontoFlutuanteNegativo = -3.4E-38;
	double pontoFlutuanteLongoNegativo = -1.7E-307;
	printf("\n%50s\n","\n1) Valores limites de cada tipo de variável\n\n");
	//PRINT ALTAMENTE PERIGOSO!
	printf("%18s%25s\n\n\tChar:\t\t\tde %d a %d\n\tInt:\t\t\tde %d a %d\n\tShort:\t\t\tde %d a %d\n\tLong:\t\t\tde %d a %d\n\tUnsigned Char:\t\tde 0 a %d\n\tUnsigned Int:\t\tde 0 a %d\n\tUnsigned Short:\t\tde 0 a %d\n\tUnsigned Long:\t\tde 0 a %ul\n\tFloat:\t\t\tde %.2e a %.2e\n\tDouble:\t\t\tde %.2e a %.2e\n","TIPO","LIMITE",caractereNegativo,caractere,inteiroNegativo,inteiro,curtoNegativo,curto,longoNegativo,longo,caractereSemSinal,inteiroSemSinal,curtoSemSinal,longoSemSinal,pontoFlutuanteNegativo,pontoFlutuante,pontoFlutuanteLongoNegativo,pontoFlutuanteLongo);
}
#endif

#ifdef ex2
/*2 - Escreva um programa que recebe via teclado os valores limites sem sinal para
    as variaveis do tipo char, int e long int e imprima-os no video. */
int main() {
    //Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

    unsigned char caractere;
    unsigned int inteiro;
    unsigned long int inteirolongo;

    do{
        printf("\nValor limite da variável do tipo Unsigned Char: ");
        scanf("%u",&caractere);
        if(caractere!=255) {
            printf("\nValor inválido!\n");
            system("pause");
            system("cls");
        }
    } while (caractere!=255);

    do{
        printf("\nValor limite da variável do tipo Unsigned Int: ");
        scanf("%ud",&inteiro);
        if(inteiro!=65535) {
            printf("\nValor inválido!\n");
            system("pause");
            system("cls");
        }
    } while (inteiro!=65535);

    do{
        printf("\nValor limite da variável do tipo Unsigned Long Int: ");
        scanf("%ul",&inteirolongo);
        if(inteirolongo!=4294967295) {
            printf("\nValor inválido!\n");
            system("pause");
            system("cls");
        }
    } while (inteirolongo!=4294967295);

    printf("\nResultado:\nChar: %u\nInt: %u\nLong Int: %u\n",caractere,inteiro,inteirolongo);
}
#endif
/* 3 - Escreva um programa que receba dados via teclado para variaveie do tipo short,
    long, unsigned, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                unsigned
                   float               double              char */
#ifdef ex3
int main() {
    //Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

	short curto;
	long longo;
	unsigned semsinal;
	float flutuante;
	double flutuantelongo;
    char caractere;

	printf("\nDigite um valor para a variável do tipo Short: ");
	scanf("%hd",&curto);
	printf("\nDigite um valor para a variável do tipo Long: ");
	scanf("%ld",&longo);
	printf("\nDigite um valor para a variável do tipo Unsigned: ");
	scanf("%u",&semsinal);
	printf("\nDigite um valor para a variável do tipo Float: ");
	scanf("%f",&flutuante);
	printf("\nDigite um valor para a variável do tipo Double: ");
	scanf("%lf",&flutuantelongo);
	printf("\nDigite um valor para a variável do tipo Char: ");
	scanf("%d",&caractere);
    printf("\n\n        10        20        30        40        50        60\n");
	printf("12345678901234567890123456789012345678901234567890123456789012345\n");
	printf("    %hd                  %ld                  %u\n",curto,longo,semsinal);
	printf("\n              %.2f               %.2f               %d",flutuante,flutuantelongo,caractere);

}
#endif // ex3

#ifdef ex4
/*4 - Acrescente ao exercicio anterior mais uma linha. Receba via teclado os valores
    sem sinal char, int e long int e escrevendo nas coluna 10, 30 e 50.*/
int main(){
    //Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

	short curto;
	long longo;
	unsigned semsinal;
	float flutuante;
	double flutuantelongo;
    char caractere;
    unsigned char caracteresemsinal;
    unsigned int inteirosemsinal;
    unsigned long int inteirolongoss;

	printf("\nDigite um valor para a variável do tipo Short: ");
	scanf("%hd",&curto);
	printf("\nDigite um valor para a variável do tipo Long: ");
	scanf("%ld",&longo);
	printf("\nDigite um valor para a variável do tipo Unsigned: ");
	scanf("%u",&semsinal);
	printf("\nDigite um valor para a variável do tipo Float: ");
	scanf("%f",&flutuante);
	printf("\nDigite um valor para a variável do tipo Double: ");
	scanf("%lf",&flutuantelongo);
	printf("\nDigite um valor para a variável do tipo Char: ");
	scanf("%d",&caractere);
	printf("\nDigite um valor para a variável do tipo Unsigned Char: ");
	scanf("%u",&caracteresemsinal);
    printf("\nDigite um valor para a variável do tipo Unsigned Int: ");
	scanf("%u",&inteirosemsinal);
    printf("\nDigite um valor para a variável do tipo Unsigned Long Int: ");
	scanf("%u",&inteirolongoss);

    printf("\n\n        10        20        30        40        50        60\n");
	printf("12345678901234567890123456789012345678901234567890123456789012345\n");
	printf("    %hd                  %ld                  %u\n",curto,longo,semsinal);
	printf("\n              %.2f               %.2f               %d",flutuante,flutuantelongo,caractere);
	printf("\n         %u                  %u                  %u",caracteresemsinal,inteirosemsinal,inteirolongoss);
}
#endif // ex4

#ifdef ex5
/*5 - Usando os operadores aritmeticos soma "+", subtracao "-" e multiplicacao "*"
    receba 2 numeros inteiro via teclado e execute as 3 operacoes.
    Guarde os resultados em variaveis. Imprima na tela os valores recebidos e
    os resultados da 3 operacoes.*/
int main() {
    //Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

    int n1,n2,r;
	printf("Digite o primeiro número: ");
	scanf("%d",&n1);
	printf("\nDigite o segundo número: ");
	scanf("%d",&n2);
	r = n1+n2;
	printf("\nResultados:\n");
	printf("\nSoma: %d",r);
	r = n1-n2;
	printf("\nSubtracao: %d",r);
	r = n1*n2;
	printf("\nMultiplicacao: %d\n\n",r);
}
#endif // ex5

#ifdef ex6
/*6 - Reescreva o exercicio anterior recebendo via teclado 2 numeros reais em
    ponto flutuante e mostre na tela em notacao cientifica. Acrescente o operador
    aritmetico divisao "/".*/
int main() {
    //Definindo o idioma
	setlocale(LC_ALL,"Portuguese");

    float n1,n2,r;
	printf("Digite o primeiro número: ");
	scanf("%f",&n1);
	printf("\nDigite o segundo número: ");
	scanf("%f",&n2);
	r = n1+n2;
	printf("\nResultados:\n");
	printf("\nSoma: %.2e",r);
	r = n1-n2;
	printf("\nSubtracao: %.2e",r);
	r = n1*n2;
	printf("\nMultiplicacao: %.2e",r);
	r = n1/n2;
	printf("\nDivisão: %.2e\n\n",r);
}
#endif // ex6
