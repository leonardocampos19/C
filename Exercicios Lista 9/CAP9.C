#define ex14
#include "stdio.h"
#include "windows.h"
#include "string.h"
#include "conio.h"
#include "math.h"

/******************************************************************************

				FUNCOES

*******************************************************************************

1 - Conceito de funcao

Funcoes dividem grandes tarefas de computacao em tarefas menores, e permitem as
pessoas trabalhar sobre o que outras ja' fizeram, em vez de partir do inicio
novamente. Funcoes bem definidas podem frequentemente esconder detalhes de
operacao de partes de um programa. Nos ja' usamos a funcao printf() sem conhecer
os detalhes de sua programacao.

2 - Definicao

Funcao e' um conjunto de instrucoes e declaracoes desenhadas para cumprir uma
determinada tarefa e referencia-la por um nome.

A principal razao para usar funcoes e' dividir uma tarefa em outras pequenas
tarefas que simplificam e organizam o programa como um todo.

Outra razao para escrever funcoes e' a de reduzir o tamanho do programa.
Qualquer sequencia de instrucoes ou declaracoes que apareca no programa mais de
uma vez e' candidata a se transformar em uma funcao.

Uma funcao e' escrita no programa uma unica vez mas pode ser executado muitas
vezes durante a execucao do programa.

A funcao, uma vez desenvolvida e testada, passa a ser completamente transparente
ao usuario, que necessita saber sua utilidade, as informacoes de entradas e
infomacoes de saida, podendo abster-se de todos os detalhes de sua
implementacao. Exemplos disso sao as funcoes printf, scanf, gets, puts que
temos utilizado sem saber como foram construidas.

3 - Formato de uma funcao em C

A estrutura de uma funcao na linguaguem C e' semelhante a estrutura da funcao
main(). A unica diferenca e' que a funcao main() tem um nome especial.

O formato de uma funcao em C e':

<tipo_de_retorno> <nome_da_funcao> (<parametros ou informacoes>)
tipos dos parametros ou informacoes;

{
	declaracao de variaveis;
	comandos;
	funcoes;
        retorno da funcao;
}

tipo_de_retorno -----------> E' o tipo do dado que a funcao retornara'.

nome_da_funcao ------------> E' o nome pelo qual a funcao sera' chamada.

parametros ou informacoes ou
lista de argumentos -------> Sao as informacoes que a funcao recebe para
                             executar a tarefa definida.

tipos dos parametros  ou
informacoes ---------------> Se houve informacoes entao o tipo destes deve ser
                             declarado.

declaracao de variaveis----> Declaracao dos tipos das variaveis locais`a funcao
                             e que sao utilizados apenas dentro nesta.

comandos ------------------> Sao os comandos da linguaguem C que executam as
                             tarefas definidas para a funcao.

funcoes -------------------> Sao chamadas para funcoes de biblioteca e/ou outras
                             funcoes desenvolvidas pelo programador.

retorno da funcao ---------> Retorna uma informacao para a funcao que chamou.

4 - Chamando uma funcao

Chamar uma funcao e' desviar o fluxo do programa para que uma tarefa seja
executada. Terminada esta tarefa chamada, o fluxo do programa retorna para a
declaracao seguinte a da chamada da funcao.

Varias funcoes, como o printf(), sao desenvolvidas pelo fabricante do compilador
e juntadas ao programa pelo linkeditor. Sao as chamadas funcoes de biblioteca.

Podemos tambem escrever nossas proprias funcoes no programa e chama-las como
fazemos com as funcoes de biblioteca.

A sintaxe para chamar uma funcao e'

	<nome_da_funcao>(<parametros ou informacoes>);

Exemplo:
	printf("teste");  chama a funcao de bilioteca "printf" e passa a
                          informacao "teste".

	soma(a,b);   chama a funcao "soma" e passa as informacoes "a" e "b".

Exemplo:*/

#ifdef ex1
/*  a funcao imprimir mensagens na tela */

void imprimir_mensagem()
{
printf("\t\t Voce esta' na funcao imprimir_mensagem\n");
printf("\t\t esta funcao foi chamada pela funcao main()\n");
printf("\t\t fim da funcao imprimir_mensagem\n\n");
}

main()
{


printf("\nVoce esta' na funcao main()\n");
printf("Este exemplo mostra a chamada de uma funcao.\n\n");

imprimir_mensagem(); /*chama a funcao"imprimir_mensagem" desenvolvida pelo
                       programador e sem a passagem de informacoes para a funcao
                       chamada */

printf("Voce esta' de volta a funcao main()\n");
printf("Fim do programa\n");
}

#endif

/*

5 - Passagem de parametros ou informacoes

O que sao parametros ou informacoes ou argumentos de uma funcao?
Sao as informacoes que a funcao recebe para executar a tarefa para a qual foi
desenvolvida.

Existem dois metodos de passagem de parametros ou informacoes para uma funcao.

- O 1. metodo e' a passagem de parametros ou informacoes por "valor" ou "copia".

Neste metodo, na função que chamou faz-se uma copia dos valores a serem
enviados para a funcao chamada. Dessa forma os valores originais nao podem ser
alterados, pois a funcao chamada manipula apenas as copias dos mesmos. Na funcao
chamada sao criadas variaveis do mesmo tipo da funcao que chamou que receberao
as copias destes valores.

Lembrando que as variaveis que recebem os parametros ou informcoes da funcao que
chamou e as que estao dentro da funcao chamada, sao variaveis locais. Portanto,
quando a execucao da funcao se encerrar as variaveis sao destruidas ou seja, o
seu conteudo e' perdido.

Exemplo:*/

#ifdef ex2
void soma(int i,int j);
void troca(int x,int y);

main()		/* passagem de parametros por "valor" ou "copia" */
{
int a,b;
a = 10;
b = 20;


printf("main() -> antes da troca ---> a = %d  b = %d \n\n",a,b);

troca(a,b); /* chama a funcao "troca" passando como informacao a copia dos
               valores das variaveis "a" e "b" */

printf("main() -> depois da troca --> a = %d  b = %d \n\n",a,b);

soma(a,b);  /* chama a funcao "soma" passando como informacao a copia dos
               valores das variaveis "a" e "b" */

printf("Voce esta' de volta a funcao main()\n");
printf("Fim do programa\n");
}

/* funcao troca dois valores */

void troca(int x,int y)    /* recebe a copias dos valores das variaveis "a" e "b" da funcao
               main */
{
int c;

printf("\tfuncao troca()\n");
printf("\ttroca os valores da variaveis x e y que sao\n");
printf("\tcopias das variaveis a e b da funcao main().\n\n");

printf("\to valor de x e' %d, o de y e' %d\n",x,y);

c = x;
x = y;
y = c;

printf("\to valor de x e' %d, o de y e' %d\n",x,y);
printf("\tfim da funcao troca\n\n");
}

/* funcao soma dois valores */

void soma(int i,int j)
{
int k;

k = i + j;

printf("\tfuncao soma()\n");

printf("\to valor de i e' %d, o de j e' %d e a soma de i + j e'%d\n",i,j,k);
printf("\tfim da funcao soma\n\n");
}
#endif

/*

- O 2. metodo e' a passagem de parametros ou informacoes por "referencia" ou
"ponteiro" ou "endereco".

Como vimos, quando passamos parametros ou informacoes por "valor" ou "copia", a
funcao chamada cria novas variaveis do mesmo tipo dos parametros ou informacoes
passados e copia nelas os valores passados pela funcao que chamou.

Na passagem de parametros ou informacoes por "referencia" ou "ponteiro" ou
"endereco" a funcao que chama passa para a funcao chamada o endereco das
variaveis. A funcao chamada entao cria variaveis para receber esses enderecos ou
seja cria ponteiros que devem ser do mesmo tipo das variaveis que estao sendo
passada.

Diferentemente da passagem de parametros por "valor" ou "copia" onde nao se pode
alterar os valores das variaveis que sao passadas para a funcao chamada, aqui os
conteudos originais ou seja, das variaveis da funcao que chama, podem ser
alterados.

Lembrando que atraves dos ponteiros podemos acessar o conteudos da variaveis de
maneira indireta.

A passagem de parametros ou informacoes por "referencia" ou "ponteiro" ou
"endereco" e' normalmente utilizada para se trabalhar com vetores e estruturas
que nao devem utilizar a passagem por "valor" ou "copia".

Exemplos:*/

#ifdef ex3
void troca(int *p1,int *p2);

main()		/* exemplo passando o endereco das variaveis simples */
{
int a,b;
a = 10;
b = 20;


printf("main() -> antes da troca ---> a = %d  b = %d \n\n",a,b);

troca(&a,&b); /* chama a funcao "troca" agora passando como informacao os
                 enderecos das variaveis "a" e "b" */

printf("main() -> depois da troca --> a = %d  b = %d \n",a,b);
printf("Fim do programa\n");

}

/* funcao "troca"-> troca dois valores recebidos da funcao que chamou*/

void troca(int *p1,int *p2)
{
int c;

printf("\tfuncao troca()\n");

printf("\ttroca os conteudos da variaveis a e b da funcao main()\n");

printf("\tatraves dos enderecos da variaveis.\n\n");

c = *p1;
*p1 = *p2;
*p2 = c;

printf("\tfim da funcao troca\n\n");
}
#endif

#ifdef ex4
void display(int *pont);

main()		/* Exemplo passando o endereco do 1. elemento do vetor */
{
int z[10],i;


printf("inicializa o vetor z com os valores de 10 a 19\n\n");

for(i=0;i < 10;++i)
	{
	z[i] = i+10;
	}

display(z);  /* chama a funcao "display" agora passando como informacao o
                endereco do 1. elemento da variavel vetor "z"  */

printf("\nde volta a funcao main()\n");
printf("Fim do programa\n");
}

/* funcao "display" que mostra o conteudo de um vetor de 10 elementos */

void display(int *pont)
{
int i;

printf("\tfuncao display\n");
printf("\timprime na tela os valores do vetor z via o ponteiro \n");
printf("\tpont que aponta para o 1. elemento do vetor\n");

for(i=0;i < 10;i++)
	{
	printf("\t  %d\n",pont[i]);
	}
printf("\tfim da funcao display\n\n");
}
#endif

#ifdef ex5
void imprimir(struct data *pont);

		/* exemplo passando um ponteiro para estrutura */
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[10];
	};
main()
{
static struct data calendario = {7,9,1822,250,"setembro"};
struct data *prt;


printf("inicializa o ponteiro prt e chama a funcao imprimir()\n\n");

prt=&calendario;  /* guarda o endereco da variavel "calendario" no
                     ponteiro "prt" */

imprimir(prt); /* chama a funcao "imprimir" agora passando como informacao o
                  endereco da variavel do tipo estrutura de dados "calendario"
                  atribuido ao ponteiro "prt"*/

printf("de volta a funcao main()\n");
printf("Fim do programa\n");
}

/*funcao "imprimir" que mostra os dados da estrutura recebida da funcao main()*/

void imprimir(struct data *pont)
{
printf("\tfuncao imprimir()\n");

printf("\timprime os elementos da estrutura de dados calendario \n");

printf("\ta partir do ponteiro pont.\n\n");

printf("\tdata da procalmacao da independencia:\n");
printf("\t  %d\n",pont->dia);
printf("\t  %d\n",pont->mes);
printf("\t  %d\n",pont->ano);
printf("\t  %d\n",pont->dia_ano);
printf("\t  %s\n\n",pont->nome_mes);

printf("\tfim da funcao imprimir\n\n");
}
#endif
/*

6 - Retorno de informacao de uma funcao

Uma funcao chamada pode retornar um ou nenhum valor a funcao que a chamou.
Para retornar uma valor a funcao que chamou utiliza-se o comando "return".

O formato geral e':

	return(informacao);	retorna o valor
	return();		nao retorna valor
	return;			nao retorna valor

A utilizacao do comando "return" e' opcional quando nao ha' retorno de valor.

IMPORTANTE: O comando "return" retorna uma unica informacao.

Exemplo: */

#ifdef ex6
int soma(int x,int y);

main()
{
int a,b,c;
a = 100;
b = 200;


printf("chama a funcao soma(). \n");
printf("A funcao soma() retorna o resultado que e' atribuido a variavel c\n\n");

c = soma(a,b); /* chama a funcao "soma" e passa como informacao uma copia dos
                  valores de "a" e "b" */

printf("soma de a + b e': %d + %d = %d \n",a,b,c);
}

/* funcao "soma" que recebe 2 valores por passagem de informacoes por "valor"
ou "copia", soma estes valores e retorna o resultado */

int soma(int x,int y)
{
int z;

printf("\tfuncao soma() \n");
printf("\ta funcao soma os valores x e y \n");
printf("\tretorna o resultado com o comando return\n\n");

z = x + y;

return(z); /* retorna o resultado da soma dos valores recebidos */
}
#endif

/*
7 - Definindo o tipo do valor de retorno

Os valores devolvidos pelo comando "return" sao inteiros por default como no
exemplo anterior. Quando nao existe valor devolvido, se a funcao que chamou
estiver esperando algum valor, recebera lixo e ocorrera um erro de logica nao
detectavel pelo compilador.

As funcoes podem devolver valores nao inteiros. Para isto devemos especificar
claramente o "tipo_de_retorno" na funcao chamada e declarar tambem este mesmo
tipo na funcao de chamada.

O formato geral para chamar uma funcao que retorna uma valor diferente de
inteiro e':

	<nome_da_função> (parametros ou informacoes);

Deve-se tambem declarar o tipo da informacao retornada na funcao que chamou
junto com as variaveis locais desta.

O formato geral é:
	<tipo> <nome_da_funcao>();

Exemplo:
	float soma();

Lembrando que o formato para se declarar uma variavel simples e':
	<tipo> <nome_da_variavel>;

Exemplo:
	float numero;

Note que a declaracao do tipo de "retorno da funcao" e' semelhante a declaracao
de uma variavel simples.

O formato geral para declarar uma funcao que retorna uma valor diferente de
inteiro e':
	<tipo_de_retorno> <nome_da_funcao>(parametros ou informacoes);

Exemplo:
      float soma(a,b) Atencao: aqui nao tem ";" pois e' a declaracao da funcao
      float a,b;
      {
      }

Exemplo:*/

#ifdef ex7
float soma(float x,float y);

main()
{
float a,b,c;
//float soma(); /* declara que a funcao "soma" retornara' um valor do tipo float*/

a = 3957.779;
b = 43558.357;


printf("chama a funcao soma(). \n");
printf("A funcao soma() retorna o resultado que e' atribuido a variavel c\n\n");

c = soma(a,b);   /* chama a funcao "soma" e passa como informacao uma copia dos
                    valores de "a" e "b" e espera o retorno de um valor do
                    tipo "float" */

printf("soma de a + b e': %.3f + %.3f = %.3f \n",a,b,c);
}

/* funcao "soma" que recebe 2 valores por passagem de informacoes por "valor",
soma estes valores e retorna o resultado como "float" pois o "tipo_de_retorno"
desta funcao esta declarado como "float" */

float soma(float x,float y) /* na frente do <nome_da_funcao> esta' declarado o
                   <tipo_de_retorno> ou o tipo de valor que o comando "return"
                   vai retornar */
{
float z;

printf("\tfuncao soma() \n");
printf("\ta funcao soma os valores x e y \n");
printf("\tretorna o resultado com o comando return\n\n");

z = x + y;

return(z); /* retorna o resultado da soma dos valores de guardados em "z" neste
              caso "float" */
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************

1 - Escreva um programa que receba na funcao main() 2 valores inteiro. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main().

2 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.

3 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
    para transforma-lo em uma calculadora. (utilize o comando switch).

4 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao o vetor e a
    letra digitada.(utilize o comando return)

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y

5 - Reescreva o exercicio 1 do capitulo de ponteiro utilizando funcoes na recepcao
    e na impressão dos dados.

6 - Reescreva o programa do exercicio 4 de ponteiros, transformando a
    entrada de dados e a impressao no video em funcoes. Transforme ainda
    estas duas funcoes em opcoes de um menu. (nao esqueca da opcao de
    fim de programa). Utilize o comando switch.

7 - Acrescente ao exercicio anterior as funcoes de procura, altera e exclui um
    registro. Inclua-as como opcoes do menu.

*/


/*1 - Escreva um programa que receba na funcao main() 2 valores inteiros. Escreva
    uma funcao para cada operacoes aritmeticas e passe como parametro os 2
    valores recebidos na funcao main(). Retorne os resultados usando o comando
    return e imprima-os no video na funcao main(). */
#ifdef ex8

//declaração
int soma(int x, int y);
int subt(int x, int y);
int multi(int x, int y);
float divis(int x, int y);

main() {
    int num1, num2;
    printf("Digite um numero: ");
    scanf("%d",&num1);
    printf("\nDigite outro numero: ");
    scanf("%d",&num2);

    printf("\nSoma: %d\nSubtracao: %d\nMultiplicacao: %d\nDivisao: %.2f", soma(num1,num2), subt(num1,num2), multi(num1, num2), divis(num1,num2));

}

//Funções
int soma(int x, int y) {
    return x + y;
}

int subt(int x, int y) {
    return x - y;
}

int multi(int x, int y) {
    return x * y;
}

float divis(int x, int y) {
    return (float) x / (float) y;
}
#endif // ex8

/*2 - Reescreva o programa do exercicio anterior para receber via teclado n
    valores. Os n valores nao sao definidos previamente.*/

#ifdef ex9
//declaração
int soma(int x, int y);
int subt(int x, int y);
int multi(int x, int y);
float divis(int x, int y);

main() {
    int num1, num2, es;

    do {
        printf("Digite um numero: ");
        scanf("%d",&num1);
        printf("\nDigite outro numero: ");
        scanf("%d",&num2);
        printf("\nSoma: %d\nSubtracao: %d\nMultiplicacao: %d\nDivisao: %.2f\n", soma(num1,num2), subt(num1,num2), multi(num1, num2), divis(num1,num2));
        printf("Deseja continuar ? 1 = [SIM]\n--> ");
        scanf("%d",&es);
        if(es != 1) {
            break;
        }
    } while(1==1);
}

//Funções
int soma(int x, int y) {
    return x + y;
}

int subt(int x, int y) {
    return x - y;
}

int multi(int x, int y) {
    return x * y;
}

float divis(int x, int y) {
    return (float) x / (float) y;
}
#endif // ex9

/*3 - Aproveitando o programa anterior inclua a selecao das operacoes aritmeticas
    para transforma-lo em uma calculadora. (utilize o comando switch).*/
#ifdef ex10
//declaração
int soma(int x, int y);
int subt(int x, int y);
int multi(int x, int y);
float divis(int x, int y);

main() {
    int num1, num2, res = 0;
    char op;

    printf("Digite um numero: ");
    scanf("%d",&num1);

    do {
        op = _getche();
        if(op == '=') {
            break;
        }
        printf("\nDigite outro numero: ");
        scanf("%d",&num2);

        switch(op) {
            case '+': res = soma(num1,num2);
                printf("= %d",soma(num1,num2));
            break;
            case '-': res = subt(num1,num2);
                printf("= %d",subt(num1,num2));
            break;
            case '*': res = multi(num1,num2);
                printf("= %d",multi(num1,num2));
            break;
            case '/': res = (int) divis(num1,num2);
                printf("= %2.f", divis(num1,num2));
            break;
        }
        num1 = res;
        printf("\n\n");
    } while(1==1);
    printf("\nUltimo resultado: %d", res);
}

//Funções
int soma(int x, int y) {
    return x + y;
}

int subt(int x, int y) {
    return x - y;
}

int multi(int x, int y) {
    return x * y;
}

float divis(int x, int y) {
    return (float) x / (float) y;
}
#endif // ex10

/* 4 - Escreva um programa que receba uma letra via teclado. Escreva uma funcao que
    pesquise esta letra dentro do vetor abaixo. Imprima o resultado da pesquisa
    no video na funcao main(). Passe como informacao para a funcao o vetor e a
    letra digitada.(utilize o comando return)

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y*/
#ifdef ex11

bool pesquisa(char letra, char *vetor, int tamanho);

main() {
    static char vetor[] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};
    char letra;
    puts("Digite uma letra: ");
    letra = getchar();
    puts("Resultado: ");
    if(pesquisa(letra,&vetor[0],sizeof(vetor))) {
        puts("valor encontado");
    } else {
        puts("valor nao encontrado");
    }
}

bool pesquisa(char letra,char *vetor,int tamanho) {
    int i;
    for(i=0;i<tamanho;i++) {
        if(letra==vetor[i]) {
            return 1;
        } else {
            return 0;
        }
    }
}
#endif // ex11

/*5 - Reescreva o exercicio 1 do capitulo de ponteiro utilizando funcoes na recepcao
    e na impressão dos dados.

    Exercicio 1 do capitulo de ponteiro:
    Escreva um programa que receba via teclado um char, int, long, unsigned,
    float, double, unsigned long e unsigned char, declare ponteiros para os
    mesmos e imprima-os no video utilizando o operador de conteudo * no
    seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char
     */
#ifdef ex12

void recepcao();
void exibicao(char *pc, int *pi, long int *pl, unsigned *pu, float *pf, double *pd, unsigned long *plu, unsigned char *puc);

main() {
    recepcao();
}

void recepcao() {
    char c;
    int i;
    long l;
    unsigned u;
    float f;
    double d;
    unsigned long lu;
    unsigned char uc;

    puts("Char: ");
    c = getchar();

    puts("\nInt: ");
    scanf("%d",&i);

    puts("\nLong: ");
    scanf("%ld",&l);

    puts("\nUnsigned: ");
    scanf("%u",&u);

    puts("\nFloat: ");
    scanf("%f",&f);

    puts("\nDouble: ");
    scanf("%lf",&d);

    puts("\nUnsigned Long: ");
    scanf("%u",&lu);

    puts("\nUnsigned Char: ");
    scanf("%u",&uc);

    exibicao(&c, &i, &l, &u, &f, &d, &lu, &uc);
}

void exibicao(char *pc, int *pi, long int *pl, unsigned *pu, float *pf, double *pd, unsigned long *plu, unsigned char *puc) {
    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                   %ld                   %u        \n",*pi,*pl,*pu);
    printf("              %.2f               %.2f                 %c\n",*pf,*pd,*pc);
    printf("         %u                  %u\n",*plu,*puc);
}
#endif // ex12


/*6 - Reescreva o programa do exercicio 4 de ponteiros, transformando a
    entrada de dados e a impressao no video em funcoes. Transforme ainda
    estas duas funcoes em opcoes de um menu. (nao esqueca da opcao de
    fim de programa). Utilize o comando switch.

    3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo
    e inicialize-a com algum conteudo. Imprima os conteudos no video usando
    ponteiros.
             nome, end, cidade, estado, cep

    4 - Com a estrutura do exercicio acima, defina um vetor de estruturas de 3
    elementos. Receba os dados pelo teclado e imprima-os no video usando
    ponteiros. Utilize um comando de loop. (vetor de estruturas)*/
#ifdef ex13

struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(dados *pessoas);
void exibicao(dados *pessoas);

main() {
    int i, op;
    struct dados pessoas[3];
    do {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados\n3 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: recepcao(pessoas);
            break;
            case 2: exibicao(pessoas);
            break;
            case 3: printf("\nEncerrando...\n");
            break;
        }
    } while(op != 3);
}

void recepcao(dados *pessoas) {
    int i;
    for(i=0; i<3; i++) {
        puts("Digite seu nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void exibicao(dados *pessoas) {
    int i;
    for(i=0;i<3;i++) {
        printf("\n");
        printf("Nome: %s\n",pessoas[i].nome);
        printf("Endereco: %s\n",pessoas[i].end);
        printf("Cidade: %s\n",pessoas[i].cidade);
        printf("Estado: %s\n",pessoas[i].estado);
        printf("Cep: %s\n",pessoas[i].cep);
    }
}

#endif // ex13

/*7 - Acrescente ao exercicio anterior as funcoes de procura, altera e exclui um
      registro. Inclua-as como opcoes do menu.*/
#ifdef ex14
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(dados *pessoas);
void exibicao(dados *pessoas);
void procurar(dados *pessoas);
void alterar(dados *pessoas);
void excluir(dados *pessoas);
int checarNome(char *nome, dados *pessoas);

main() {
    int i, op; //             nome, end, cidade, estado, cep
    struct dados pessoas[3] = {"Leonardo","Avenida Central","Sao Vicente","sp","11348000",
                               "Amanda","Rua Bartolomeu","Sao Vicente","sp","11399000",
                               "Cristina","Avenida Goias","Sao Paulo","sp","11247000"};
    do {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n4 - Alterar\n5 - Excluir\n6 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: recepcao(pessoas);
            break;
            case 2: exibicao(pessoas);
            break;
            case 3: procurar(pessoas);
            break;
            case 4: alterar(pessoas);
            break;
            case 5: excluir(pessoas);
            break;
            case 6: printf("\nEncerrando...\n");
            break;
        }
    } while(op != 6);
}

void recepcao(dados *pessoas) {
    int i;
    for(i=0; i<3; i++) {
        puts("Digite seu nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void exibicao(dados *pessoas) {
    int i;
    for(i=0;i<3;i++) {
        printf("\n");
        printf("Nome: %s\n",pessoas[i].nome);
        printf("Endereco: %s\n",pessoas[i].end);
        printf("Cidade: %s\n",pessoas[i].cidade);
        printf("Estado: %s\n",pessoas[i].estado);
        printf("Cep: %s\n",pessoas[i].cep);
    }
}

void procurar(dados *pessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0){
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n", pessoas[i].nome,pessoas[i].end,pessoas[i].cidade,pessoas[i].estado,pessoas[i].cep);
    }
}

void alterar(dados *pessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0) {
        puts("Digite seu novo nome: ");
        gets(pessoas[i].nome);
        puts("Digite seu novo endereco: ");
        gets(pessoas[i].end);
        puts("Digite sua nova cidade: ");
        gets(pessoas[i].cidade);
        puts("Digite seu novo estado: ");
        gets(pessoas[i].estado);
        puts("Digite seu novo cep: ");
        gets(pessoas[i].cep);
        printf("\n");
    }
}

void excluir(dados *pessoas) {
    int i, j;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, pessoas);
    if(i >= 0) {
        strcpy(pessoas[i].nome,"");
        strcpy(pessoas[i].end,"");
        strcpy(pessoas[i].cidade,"");
        strcpy(pessoas[i].estado,"");
        strcpy(pessoas[i].cep,"");
        printf("\n\"Excluido\"\n");
    }
}

int checarNome(char *nome, dados *pessoas) {
    int i,j,c = 0;
    for(i=0; i<3; i++) {
        if(strlen(nome)==strlen(pessoas[i].nome)) {
            for(j=0; j<strlen(nome); j++) {
                if(nome[j]==pessoas[i].nome[j]) {
                    c++;
                }
            }
            if(c == strlen(pessoas[i].nome)) {
                puts("Nome encontrado!");
                return i;
            } else {
                c = 0;
            }
        }
    }
    puts("Nome nao encontrado!");
    return -1;
}
#endif // ex14
