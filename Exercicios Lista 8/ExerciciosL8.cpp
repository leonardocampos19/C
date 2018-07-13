#define ex24
#include "stdio.h"
#include "stdlib.h"

/******************************************************************************

			 PONTEIROS OU APONTADORES

*******************************************************************************

1. Como funciona os ponteiros?

Os ints guardam numeros inteiros. Os floats guardam numeros de ponto flutuante.
Os chars guardam caracteres. Ponteiros guardam enderecos de memoria.

Quando voce anota o endereco de um colega voce esta' criando um ponteiro. O
ponteiro e' este seu pedaco de papel. Ele tem anotado um endereço. Qual e' o
sentido disto? Simples. Quando voce anota o endereco de um colega, depois voce
vai usar este endereco para acha'-lo. Na linguaguem C funciona assim. Voce anota
o endereco de uma variavel num ponteiro para depois usa-la.

Um ponteiro tambem tem tipo. Veja: quando voce anota o endereco de um amigo voce
o trata diferente de quando voce anota o endereco de uma empresa. Apesar do
endereco dos dois locais ter o mesmo formato (rua, numero, bairro, cidade, etc.)
eles indicam locais cujos conteudos são diferentes. Entao os dois enderecos sao
ponteiros de tipos diferentes.
                            p                               f
                            -------------------------------->
                           |                                |
        -------------------------------------------------------------------
	....| xxx | xxx | 308 |    ......    | xxx | xxx | ´i´ | xxx | ....
        -------------------------------------------------------------------
             $100  $101  $102                 $306  $307  $308  $309

Na figura acima, "p" e' um ponteiro para a variavel "f'. Ou seja, "p" contem o
endereco de memoria onde esta' armazenada a variável "f".

2.  Definicao

Ponteiro e' uma variavel que, diferentemente das outras, nao contem o valor
de um dado, mas aponta para o endereco de outra variavel que o contem.

3. Ponteiros para variaveis simples

Na linguaguem C quando declaramos ponteiros nos informamos ao compilador para
que tipo de variável vamos aponta'-lo. Um ponteiro int aponta para uma variavel
do tipo inteira, isto é, guarda o endereço de um inteiro.

O formato geral para a declaracao de um ponteiro para variaveis simples e':

	tipo *nome_variavel;

onde "tipo" indica o tipo da variavel (int, char, estrutura, etc..)
e "nome_variavel" e' o nome da variavel ponteiro.

exemplos
	char *pc;         declara um ponteiro do tipo char de nome "pc"
	int *pi;         declara um ponteiro do tipo int de nome "pi"
	float *pfl;      declara um ponteiro do tipo float de nome "pfl"
	unsigned *pu;    declara um ponteiro do tipo unsigned de nome "pu"

Para atribuir-se diretamente o endereco da variavel apontada, deve-se utilizar
o operador de endereco "&" (E comercial) antes do nome da variavel a ser
apontada; isto indicara' que se quer acessar o endereco da mesma e nao seu
conteudo.

O formato geral e':
		ponteiro = &nome_variavel;

Olhando a figura inicial temos:
	p = &f;	   atribui ao ponteiro "p" o end. da variavel "f".
                   Em outras palavras atribui a "p" o endereco $308.

Exemplos:
declaracao de variaveis
	char a = 'p';
	int b = 700;
	float c = 9.777;
	unsigned d = 4000000007;

Atribuindo os enderecos aos ponteiros;
	pc = &a;    atribui ao ponteiro "pc" o end. da variavel "a".
	pi = &b;    atribui ao ponteiro "pi" o end. da variavel "b".
	pf = &c;    atribui ao ponteiro "pf" o end. da variavel "c".
	pu = &d;    atribui ao ponteiro "pu" o end. da variavel "d".

Para se obter o valor armazenado numa variavel atraves do seu ponteiro,
utiliza-se o operador de conteudo "*" (asterisco), obtendo como resultado o
conteudo da variavel apontada pelo ponteiro.

O formato geral e':
		variavel = *ponteiro;

Olhando a figura inicial temos:
	k = *p;	 atribui a "k" o conteudo da variavel apontada por "p"
                 Em outras palavras atribui a "k" o conteudo de "f"
                 que e' a letra "i".

Exemplos:

Buscando os conteudos das variaveis atraves dos seus ponteiros.
	w = *pc;   atribui a "w" o conteudo da variavel "a" que e'"p"
	x = *pi;   atribui a "x" o conteudo da variavel "b" que e'"700"
	y = *pf;   atribui a "y" o conteudo da variavel "c" que e'"9.777"
	z = *pu;   atribui a "z" o conteudo da variavel "d" que e'"4000000007"

Exemplo com variaveis simples:*/

#ifdef ex1
main()
{
char *pc,a,w;
int *pi,b,x;
float *pf,c,y;
unsigned long *pu,d,z;

a = 'p';
b = 700;
c = 9.777;
d = 4000000007;

pc = &a;    /*atribui ao ponteiro "pc" o end. da variavel "a".*/
pi = &b;    /*atribui ao ponteiro "pi" o end. da variavel "b".*/
pf = &c;    /*atribui ao ponteiro "fl" o end. da variavel "c".*/
pu = &d;    /*atribui ao ponteiro "pu" o end. da variavel "d".*/

w = *pc;   /*atribui a "w" o conteudo da variavel "a" que e'"p"*/
x = *pi;   /*atribui a "x" o conteudo da variavel "b" que e'"700"*/
y = *pf;   /*atribui a "y" o conteudo da variavel "c" que e'"9.777"*/
z = *pu;   /*atribui a "z" o conteudo da variavel "d" que e'"4000000007"*/

printf("exibe o conteudo da variavel a '%c' \n",a);
printf("exibe o conteudo da variavel b '%d' \n",b);
printf("exibe o conteudo da variavel c '%f' \n",c);
printf("exibe o conteudo da variavel d '%lu' \n\n",d);

printf("exibe o conteudo da variavel direto atraves do ponteiro '%c'\n",*pc);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%d'\n",*pi);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%f'\n",*pf);
printf("exibe o conteudo da variavel direto atraves do ponteiro '%lu'\n\n",*pu);

printf("exibe o conteudo da var. w que recebeu o dado via ponteiro '%c'\n",w);
printf("exibe o conteudo da var. x que recebeu o dado via ponteiro '%d'\n",x);
printf("exibe o conteudo da var. y que recebeu o dado via ponteiro '%f'\n",y);
printf("exibe o conteudo da var. z que recebeu o dado via ponteiro '%lu'\n",z);

}
#endif

#ifdef ex2
main ()
{
int num;
int *p;

num = 55;
p = &num;          /* atribui o endereco da variavel "num" ao ponteiro "p"*/

printf ("\nValor inicial: %d\n",num);
*p = 100;     /* atribui o valor 100 a variavel "num" atraves do ponteiro "p"*/
printf ("\nValor final: %d\n",num);

}
#endif

#ifdef ex3
main()
{
int rx;
int *p;

rx = 200;
p = &rx;          /* atribui o endereco da variavel "rx" ao ponteiro "p"*/


printf ("\nValor inicial: %d\n",rx);
printf("digite um valor inteiro: ");
scanf("%d",p);   /*recebe via teclado um numero inteiro usando o ponteiro "p"*/
getchar();
printf ("\nO valor recebido via teclado e': %d ou %d\n",*p,rx);

}
#endif

/*
4. Ponteiros para estruturas

Podemos utilizar ponteiros para estruturas assim como usamos para variaveis
simples(int,char,...). Uma estrutura e' um tipo de dado como os outros, por isso
tambem podemos utilizar ponteiros para elas.

Para declarar um ponteiro para uma estrutura usa-se o seguinte formato:
	struct nome da estrutura *nome da variavel;

Exemplo:
    struct data *pc;  declara um ponteiro "pc" para a estrutura de nome "data"

Para atribuir-se o endereco de uma estrutura de dados a um ponteiro utiliza-se
tambem o operador de endereco "&" (E comercial) no seguinte formato:
	ponteiro = &nome_variavel;

Exemplo:
	pc = &calendario;

Fazendo uma analogia com a atribuicao do endereco das variaveis simples com
a mesma declaracao para estruturas, observa-se que sao iguais. Vamos a um
exemplo que mostra isso.

variaveis simples
   int *pa, x;     declara um ponteiro "pa" e uma variavel "x" do tipo "int"
   pa = &x;        atribui o endereco da variavel "x" ao ponteiro "pa"

estruturas
struct data *pc, calendario;     declara um ponteiro "pc" e uma variavel
                                 "calendario" do tipo "struct data"
pc = &calendario;  atribui o endereco da variavel "calendario" ao ponteiro "pc"

A diferenca aparece na busca dos dados na variavel. No caso das variaveis
simples buscamos assim:
	y = *pa;    atribui o conteudo apontado por "pa" a variavel "y"

Para as estruturas alem do ponteiro temos que acessar o membro da estrutura.
Para isso utiliza-se o mesmo operador ponto(.) usado para acessar os membros de
uma estrutura.

O formato geral e':
	(*ponteiro).membro;

Exemplo:
        y = (*pc).dia;   atribui o conteudo apontado por "pc" do membro "dia" a
                         variavel "y"

Nesta declaracao e' necessario utilizar o operador parenteses "()" pois o
operador ponto "." tem maior prioridade que o operador de conteudo "*".

Exemplo:*/

#ifdef ex4
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

struct data calendario = {7,9,1822,250,"setembro"};

main()
{
struct data *pc;


pc = &calendario;/*atribui o endereco da variavel"calendario"ao ponteiro "pc"*/

printf("\nProclamacao da Independencia: ");
printf("%d/",(*pc).dia);
printf("%d/",(*pc).mes);
printf("%d - ",(*pc).ano);
printf("%d - ",(*pc).dia_ano);
printf("%s\n",(*pc).nome_mes);

}
#endif

/*
Mas raramente encontramos referencias feitas a um membro de uma estrutura com o
uso explicito do operador de conteudo "*". O acesso a um membro de uma estrutura
por meio de um ponteiro e' tão comum, que um operador especial foi definido pela
linguagem C para realiza esta tarefa. Ele é o operador seta "->". Este operador
e' formado utilizando-se o sinal de menos(-) seguido do sinal de maior que(>).
O operador seta "->" e' usada no lugar do operador ponto "." para se acessar
um membro da estrutura utilizando ponteiro.

O formato geral e':
	ponteiro -> membro;

Exemplo:*/

#ifdef ex5
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9];
	};

main()
{
struct data *pc;

static struct data calendario = {15,11,1889,319,"novembro"};


pc = &calendario;

printf("\nProclamacao da republica: ");
printf("%d/",pc->dia);
printf("%d/",pc->mes);
printf("%d - ",pc->ano);
printf("%d - ",pc->dia_ano);
printf("%s\n",pc->nome_mes);

}
#endif

/*
5. Ponteiros para vetores

E'importante lembra que um vetor e' um conjunto de posicoes contiguas de
memoria ao passo que um ponteiro e' constituido normalmente por 2 ou 4 bytes
que armazena o endereco da variavel apontada.

Para declarar um ponteiro para um vetor usa-se o seguinte formato:

	tipo *nome_variavel;

Exemplo:
	char *pc;	 declara um ponteiro do tipo char de nome "pc"
	int *pi;	 declara um ponteiro do tipo int de nome "pi"
	float *pf;	 declara um ponteiro do tipo float de nome "pf"
	double *pd;	 declara um ponteiro do tipo double de nome "pd"
	struct data *ps; declara um ponteiro do tipo struct data de nome "ps"

Para atribuir-se o endereco a um ponteiro no caso de vetores, utilizamos o
seguinte formato:
		ponteiro = &nome_variavel [n._elemento];

Se compararmos as declaracoes de atribuicao do endereco para os vetores com a
de variaveis simples, observamos que para os vetores acrescenta-se o indice do
elemento do vetor (caracteristica dos vetores).

Exemplo:

variaveis simples
   pc = &a;    atribui ao ponteiro "pc" o end. da variavel "a".

vetores
   pb = &z[0];  atribui o endereco do 1. elemento do vetor "z" ao ponteiro "pb"

A declaracao pb = &z[0] aponta para o elemento de indice[0] do vetor "z". Ora
o elemento de indice[0] do vetor tem o mesmo endereco do vetor "z", que por
sua vez tambem e' um endereco. Portanto, pode-se dizer que pb = z. Esta
declaracao so' e' valida para o elemento de indice "0" do vetor. Pode-se dizer
que esta declaracao e' uma simplificacao de notacao e que sao declaracoes
equivalentes.

Exemplo:
   pb = &z[0];   podemos dizer que esta e' a notacao "por extenso"
   pb = z;       podemos dizer que esta e' a notacao "simplificada"

Para se obter o conteudo de um dos elementos do vetor atraves de seu ponteiro
utiliza-se o mesmo operador de conteudo "*"(asterisco).

O formaro geral e':
	variavel = *ponteiro;

Exemplo:
     y = *pb;   atribui o conteudo apontado por "pb" a variavel "y" ou seja
                o conteudo do 1. elemento do vetor "z", o elemento de indice[0]

Observe que a declaracao para buscar o conteudo de um elemento do vetor atraves
do ponteiro e' igual a declaracao para buscar o conteudo de uma variavel
simples.

Exemplo
*/
#ifdef ex6
main()
{
static int z[5]={1,2,3,4,5}; 	 /* declara um vetor de 5 elementos*/
int *pb;			 /* declara um ponteiro int */
int b;

pb = &z[0];	/* "pb" aponta para o elemento de indice[0] do vetor "z" ou
		   "pb" contem o endereco de z[0] */

b = *pb;	/* o conteudo apontado por "pb" e' atribuido a variavel "b" */
printf("imprime o conteudo de b = %d\n",b);
}
#endif

#ifdef ex7
main()
{
static int z[5]={10,20,30,40,50};  	/* declara um vetor de 5 elementos*/
int *pb;				/* declara um ponteiro int */
int b;

pb = z;	    /* usando o conceito da igualdade de end. -> z[0] equivale a "z"*/

b = *pb;    /* se o conceito da igualdade de end. for verdade,entao o valor
	       atribuido sera' o mesmo do exemplo anterior*/

printf("imprime o conteudo de b = %d\n",b);
}
#endif

#ifdef ex8
int z[5]={100,200,300,400,500};  /* declara um vetor de 5 elementos*/
main()
{
int *pb;	/* declara um ponteiro int */
int b;


for(b=0;b <5 ;b++)
	{
	pb = &z[b];	/* atribui ao ponteiro "pb" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*pb);
	}
}
#endif

#ifdef ex9
main()
{
static char z[16]="teste de string";
char *px;
int b;

for(b=0;b <15 ;b++)
	{
	px = &z[b];	/* atribui ao ponteiro "px" o end. de cada
			   um dos elementos do vetor "z" */

	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*px);
	}

px = &z[0];	/* atribui ao ponteiro "px" o end. do 1. elemento do vetor "z"*/

printf("\nOutra forma de exibir a string: %s \n",px);
}
#endif

#ifdef ex10
main()
{
int z[5];   		/* declara um vetor de 5 elementos*/
int *pk;		/* declara um ponteiro int */
int b;


for(b=0;b <5 ;b++)
	{
	pk = &z[b];	/* atribui ao ponteiro "pk" o end. de cada
			   um dos elementos do vetor "z" */
	printf("\nDigite o %d elemento do vetor z. Um numero: ",b+1);
	scanf("%d",pk);
	getchar();
	}
for(b=0;b <5 ;b++)
	{
	pk = &z[b];	/* atribui ao ponteiro "pk" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*pk);
	}
}
#endif

#ifdef ex11
main()
{
char z[5];   		/* declara um vetor de 5 elementos*/
char *p;		/* declara um ponteiro int */
int b;

for(b=0;b <5 ;b++)
	{
	p=&z[b];	/* atribui ao ponteiro "p" o end. de cada
			   um dos elementos do vetor "z" */
	printf("\nDigite o %d elemento do vetor z. Uma letra: ",b+1);
	scanf("%c",p);
	getchar();
	}
for(b=0;b <5 ;b++)
	{
	p=&z[b];	/* atribui ao ponteiro "p" o end. de cada
			   um dos elementos do vetor "z" */
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*p);
	}
p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/

printf("\noutra forma de exibir a string: %s \n",p); /*atencao na impressao*/
}
#endif

/*
6. Vetor de ponteiros

Como os ponteiros sao variaveis como as outras pode-se tambem montar vetor de
ponteiros. Este tipo de construcao normalmente e' usada para enderecar string.
O ponteiro aponta para o end. o 1. elemento da string(elemento de indice 0).

O vetor de ponteiros e' util quando se trabalha com informacoes de tamanho
diferente.

O formato para declaracao de um vetor de ponteiros e':
	tipo *nome_variavel[n._elementos];

onde "tipo" indica o tipo da variavel (int, char, estrutura, etc..)
e "nome_variavel" contem os ponteiros (enderecos) do vetor apontado, com o
tamanho definido por "n._elementos".

exemplos:
	char *pc[5];		vetor de ponteiros para caracter
	int *pont[10];		vetor de ponteiros para inteiro
	float *fl[20];		vetor de ponteiros para pto. flut.
	struct data *prt[30];	vetor de ponteiros para estruturas

Para atribuir o endereco de uma variavel a um elemento de um vetor de ponteiros
utiliza-se o seguinte formato:
		ponteiro [n._elemento] = &nome_variavel;

exemplo:
	p[2]=&x;	atribui ao 3. elementos do vetor de ponteiros
			"p" o end. da variavel "x"

Para se obter o conteudo apontado por um dos elementos do vetor de ponteiros
utiliza-se o seguinte forma:
		*ponteiro[indice]; para variavel simples
e
		ponteiro[indice];  para serie de caracteres(string)

Lembrando que os elementos de um vetor de ponteiros somente pode conter
endereco de variaveis.

Exemplo com vetor de ponteiros:
*/
#ifdef ex12
	char a = 'Z';
	char b = 'Y';
	char c = 'X';
	char d = 'W';
	char e = 'V';
main()
{
int x;
char *z[5];	/* declara um vetor de ponteiros */

	z[0] = &a;  /*atribui o endereco da variavel simples*/
	z[1] = &b;
	z[2] = &c;
	z[3] = &d;
	z[4] = &e;

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. Elemento do vetor z = %c\n",x,*z[x]);
	}
}
#endif
#ifdef ex13
	char a[] = "erro de digitacao";
	char b[] = "erro de conversao";
	char c[] = "erro de sintaxe";
	char d[] = "erro de declaracao";
	char e[] = "erro de parenteses";
main()
{
int x;
char *z[5];	/* declara um vetor de ponteiros */

	/*atribui o endereco do vetor de caracteres ao ponteiro*/
	z[0] = &a[0];	/*"notacao por extenso"*/
	z[1] = &b[0];
	z[2] = c;	/*"notacao simplificada"*/
	z[3] = d;
	z[4] = e;

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. Elemento do vetor z = %s\n",x,z[x]);
	}
}
#endif

#ifdef ex14
main()
{
int x;
char *z[5];
		/* inicializa o vetor de ponteiros */
	z[0] = "erro de digitacao";
	z[1] = "erro de conversao";
	z[2] = "erro de sintaxe";
	z[3] = "erro de declaracao";
	z[4] = "erro de parenteses";

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. elemento do vetor z = %s\n",x,z[x]);
	}
}
#endif

#ifdef ex15
main()
{
int x;
char *z[5][20];

for(x=0;x <5 ;x++)
	{
	printf("digite a string de indice %d: ",x);
	scanf("%s",z[x]);
	}

for(x=0;x <5 ;x++)
	{
	printf("imprime o conteudo do indice %d. elemento do vetor z = %s\n",x,z[x]);
	}
}
#endif

/*Incializa o vetor de ponteiro atribuindo a serie de caracteres diretamente*/

#ifdef ex16
main()
{
static char *psemana [7] = {  "Domingo" ,
       		              "Segunda-feira",
	                      "Terca-feira",
        	              "Quarta-feira",
                	      "Quinta-feira",
	                      "Sexta-feira",
        	              "Sabado",
                	    };

printf(" Dias da semana \n\n");
printf(" %s\n",psemana [0]);
printf(" %s\n",psemana [1]);
printf(" %s\n",psemana [2]);
printf(" %s\n",psemana [3]);
printf(" %s\n",psemana [4]);
printf(" %s\n",psemana [5]);
printf(" %s\n",psemana [6]);
}
#endif

/*
7. Aritmetica de ponteiros

Com ponteiros pode-se executar um n. limitado de operacao sao elas:

-Atribuir um end. de memoria determinado direto a um ponteiro.

Isto porem e' perigoso quando nao se conhece o hardware e firmware da maquina
que se esta utilizando.

exemplo:
	px=0xf853;     o ponteiro "px" aponta para o end. f853(hexa) da memoria

- Somar e subtrar valores inteiros dos ponteiros

A soma e subtracao so' e' usada para vetores.

Quando se soma um numero inteiro a um ponteiro, equivale a enderecar posicoes
contiguas de memoria  ou seja, fazer a multiplicacao do numero inteiro pelo
numero de bytes do tipo do ponteiro e somar ao endereco guardado no ponteiro.
Esta e' a razao porque o tipo do ponteiro tem que ser igual ao tipo da variavel
que ele aponta.

Usando este conceito e' usual se atribuir o endereco do 1. elemento do vetor ou
elemento de indice "0" ao ponteiro que sera' utilizado como referencia para
acessar aos demais elementos.

Relembrando: O formato para acessar o conteudo dos elementos de um vetor como
vimos no capitulo de vetores e':
	nome da variavel[indice];

O formato para acessar este mesmo conteudo utilizando o ponteiro e aritmetica
de ponteiros e':
	*(ponteiro + indice);

E temos mais uma forma para acessar o conteudo deste mesmo elemento usando
ponteiros que e':
	ponteiro[indice];

Esta forma e' possivel por que se o ponteiro aponta para um elemento no vetor
e o indice soma o numero de elementos para o qual se quer aponta, lembrando
que o ponteiro leva em conta o tipo de variavel apontada, entao esta expressão
e' equivale a expressao da aritmetica de ponteiro.

Exemplos:
*/
#ifdef ex17
main()
{
static int z[5]={1000,2000,3000,4000,5000};/* declara um vetor de 5 elementos*/
int *p;		/* declara um ponteiro int */
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/
for(b=0;b <5 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,*(p+b));
	}
}
#endif

#ifdef ex18
main()
{
static int z[5]={6000,7000,8000,9000,10000};
int *p;
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/
for(b=0;b <5 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %d\n",b+1,p[b]);
	}
}
#endif

#ifdef ex19
main()
{
static char z[16]="teste de string";
char *p;
int b;

p=&z[0];	/* atribui ao ponteiro "p" o end. do 1. elemento do vetor "z"*/
for(b=0;b <15 ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*(p+b));
	}
printf("\noutra forma de exibir a string: %s \n",p);
}
#endif

#ifdef ex20
main()
{
static char *p ="string com ponteiro";
int b;

for(b=0; p[b] != '\0' ;b++)
	{
	printf("exibe o conteudo do %d. elemento do vetor z = %c\n",b+1,*(p+b));
	}
printf("\noutra forma de exibir a string: %s \n",p);
}
#endif

/****************************************************************************

			EXERCICIOS

*****************************************************************************

1 - Escreva um programa que receba via teclado um char, int, long, unsigned,
    float, double, unsigned long e unsigned char, declare ponteiros para os
    mesmos e imprima-os no video utilizando o operador de conteudo * no
    seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char

2 - Utilizando os 3 comandos de loop while, do-while e for escreva um programa
    para imprimir na tela os conteudos dos vetores abaixo usando ponteiros.

    valores -> 1,10,100,1000,10000,100000,1000000 -> variavel global
    valores -> 1.1,103.34,156987012.456,33.78954e+30 -> variavel local
    string -> isto e' um teste de string dos alunos do 2. ciclo -> variavel
              global
    string -> teste de vetores de string -> variavel local

3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo
    e inicialize-a com algum conteudo. Imprima os conteudos no video usando
    ponteiros.
             nome, end, cidade, estado, cep

4 - Com a estrutura do exercicio acima, defina um vetor de estruturas de 3
    elementos. Receba os dados pelo teclado e imprima-os no video usando
    ponteiros. Utilize um comando de loop. (vetor de estruturas)

5 - Defina um vetor de ponteiros com 7 elementos. Receba via teclado 7 strings
    (use ponteiros) e imprima no video as strings usando ponteiros.

6 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado.
*/

/* 1 - Escreva um programa que receba via teclado um char, int, long, unsigned,
    float, double, unsigned long e unsigned char, declare ponteiros para os
    mesmos e imprima-os no video utilizando o operador de conteudo * no
    seguinte formato:

            10        20        30        40        50        60
    123456789012345678901234567890123456789012345678901234567890
        int                 long                unsigned
                  float               double              char
             unsigned long       unsigned char*/
#ifdef ex21
main() {

    char *pc,c;
    int *pi,i;
    long *pl,l;
    unsigned *pu,u;
    float *pf,f;
    double *pd,d;
    unsigned long *pul,ul;
    unsigned char *puc,uc;

    printf("Char: ");
    c = getchar();

    printf("\nInt: ");
    scanf("%d",&i);

    printf("\nLong: ");
    scanf("%ld",&l);

    printf("\nUnsigned: ");
    scanf("%u",&u);

    printf("\nFloat: ");
    scanf("%f",&f);

    printf("\nDouble: ");
    scanf("%lf",&d);

    printf("\nUnsigned Long: ");
    scanf("%ul",&ul);

    printf("\nUnsigned Char: ");
    scanf("%u",&uc);

    pc = &c;
    pi = &i;
    pl = &l;
    pu = &u;
    pf = &f;
    pd = &d;
    pul = &ul;
    puc = &uc;

    printf("        10        20        30        40        50        60\n");
    printf("123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %d                   %ld                   %u        \n",*pi,*pl,*pu);
    printf("              %.2f               %.2f\n",*pf,*pd);
    printf("         %ul                  %u\n",*pul,*puc);
}
#endif

/* 2 - Utilizando os 3 comandos de loop while, do-while e for escreva um programa
    para imprimir na tela os conteudos dos vetores abaixo usando ponteiros.

    valores -> 1,10,100,1000,10000,100000,1000000 -> variavel global
    valores -> 1.1,103.34,156987012.456,33.78954e+30 -> variavel local
    string -> isto e' um teste de string dos alunos do 2. ciclo -> variavel
              global
    string -> teste de vetores de string -> variavel local*/

#ifdef ex22

int vet1[] = {1,10,100,1000,10000,100000,1000000};
char vet3[] = "isto e' um teste de string dos alunos do 2. ciclo";

main() {
    int i=0;
    float vet2[] = {1.1,103.340,156987012.456,33.78954e+30};
    char vet4[] = "teste de vetores de string";

    //ponteiros
    int *p1;
    float *p2;
    char *p3;
    char *p4;

    printf("\n\nWhile\n");
    while(i <= sizeof(vet3)) {
        p1 = &vet1[i];
        p2 = &vet2[i];
        p3 = &vet3[i];
        p4 = &vet4[i];

        if(i <= sizeof(vet1)/sizeof(int)) {
            printf("vet1[%d]=%d\n",i, *p1);
        }
        if(i <= sizeof(vet2)/sizeof(float)) {
            printf("vet2[%d]=%.2g\n",i, *p2);
        }
        if(i <= sizeof(vet3)/sizeof(char)) {
            printf("vet3[%d]=%c\n",i, *p3);
        }
        if(i <= sizeof(vet4)/sizeof(char)) {
            printf("vet4[%d]=%c\n",i, *p4);
        }
        i++;
    }

    i = 0;
    printf("\n\nDo While\n");
    do {
        p1 = &vet1[i];
        p2 = &vet2[i];
        p3 = &vet3[i];
        p4 = &vet4[i];

        if(i <= sizeof(vet1)/sizeof(int)) {
            printf("vet1[%d]=%d\n",i, *p1);
        }
        if(i <= sizeof(vet2)/sizeof(float)) {
            printf("vet2[%d]=%.2g\n",i, *p2);
        }
        if(i <= sizeof(vet3)/sizeof(char)) {
            printf("vet3[%d]=%c\n",i, *p3);
        }
        if(i <= sizeof(vet4)/sizeof(char)) {
            printf("vet4[%d]=%c\n",i, *p4);
        }
        i++;
    } while(i <= sizeof(vet3));

    printf("\n\nFor\n");
    for(i=0;i<=sizeof(vet3)/sizeof(char);i++) {
        p1 = &vet1[i];
        p2 = &vet2[i];
        p3 = &vet3[i];
        p4 = &vet4[i];

        if(i <= sizeof(vet1)/sizeof(int)) {
            printf("vet1[%d]=%d\n",i, *p1);
        }
        if(i <= sizeof(vet2)/sizeof(float)) {
            printf("vet2[%d]=%.2g\n",i, *p2);
        }
        if(i <= sizeof(vet3)/sizeof(char)) {
            printf("vet3[%d]=%c\n",i, *p3);
        }
        if(i <= sizeof(vet4)/sizeof(char)) {
            printf("vet4[%d]=%c\n",i, *p4);
        }
    }
}
#endif // ex22

/* 3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo
    e inicialize-a com algum conteudo. Imprima os conteudos no video usando
    ponteiros. nome, end, cidade, estado, cep*/

#ifdef ex23

struct dados {
    char nome[20];
    char ende[30];
    char cidade[20];
    char estado[3];
    int cep;
};

struct dados pessoa = {"Leonardo", "Avenida fim do mundo", "Sao Vicente", "SP", 11345555};
struct dados *p = &pessoa;

main() {
    printf("Nome: %s\n",p->nome);
    printf("Endereco: %s\n",p->ende);
    printf("Cidade: %s\n",p->cidade);
    printf("Estado: %s\n",p->estado);
    printf("CEP: %d",p->cep);
}
#endif // ex23

/* 4 - Com a estrutura do exercicio acima, defina um vetor de estruturas de 3
    elementos. Receba os dados pelo teclado e imprima-os no video usando
    ponteiros. Utilize um comando de loop. (vetor de estruturas) */

#ifdef ex24
struct dados {
    char nome[20];
    char ende[40];
    char cidade[20];
    char estado[3];
    int cep;
};

struct dados pessoa[3];
struct dados *p[3];

main() {
    int i;
    for(i=0;i<3;i++) {
        printf("\n\nPessoa %d\n",i+1);

        printf("\nNome: ");
        scanf("%s",&pessoa[i].nome);
        getchar();

        printf("\nEndereco: ");
        scanf("%s",&pessoa[i].ende);
        getchar();

        printf("\nCidade: ");
        scanf("%s",&pessoa[i].cidade);
        getchar();

        printf("\nEstado: ");
        scanf("%s",&pessoa[i].estado);
        getchar();

        printf("\nCEP: ");
        scanf("%d",&pessoa[i].cep);
    }
    p[0] = &pessoa[0];
    p[1] = &pessoa[1];
    p[2] = &pessoa[2];
    for(i=0;i<3;i++) {
        printf("\nPessoa %d:\n",i+1);
        printf("%s\n", p[i]->nome);
        printf("%s\n", p[i]->ende);
        printf("%s\n", p[i]->cidade);
        printf("%s\n", p[i]->estado);
        printf("%s\n", p[i]->cep);
    }
}
#endif // ex24

/* 5 - Defina um vetor de ponteiros com 7 elementos. Receba via teclado 7 strings
    (use ponteiros) e imprima no video as strings usando ponteiros. */
#ifdef ex25
//char aux[7][10];
//char *p[7] = &aux;

main() {
    int i;
    char *p[7][20] = {(char *) malloc (sizeof(char))};

    for(i=0; i<7; i++) {
        printf("\nDigite uma string: ");
        scanf("%s",p[i]);
    }
    printf("\nListando:\n");
    for(i=0; i<7; i++) {
        printf("%s\n",p[i]);
    }
}
#endif // ex25


/*6 - Escreva um programa que receba via teclado numeros inteiros positivos usando
    ponteiros. Quando o numero digitado for negativo o programa deve parar e calcula
    a media dos valores digitados e mostrar o resultado.*/
#ifdef ex26
main() {
    int *p = (int *) malloc(sizeof(int)), i=0;
    float media = 0;

    do {
        printf("\nDigite um numero: ");
        scanf("%d",p);
        if((*p) < 0) { break; }
        i++; media+=(*p);
    } while(1==1);

    printf("\nMedia: %.2f", media/i);
}
#endif // ex26

