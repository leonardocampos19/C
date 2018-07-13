#define ex14
#include "stdio.h"

/*****************************************************************************

			ESTRUTURA DE DADOS

******************************************************************************

1. Definicao

Estrutura e' uma variavel composta, formada por uma ou mais variaveis,
possilvelmente de tipos diferentes, colocadas juntas sob um unico nome.

Quando se declara uma estrutura de dados criamos um tipo de variavel composta
onde os membros sao definidos pelo usuario. Assim, podemos dizer que estamos
criando um "novo tipo de variavel".Isso porque o usuario tem total flexibilidade
para declarar qualquer tipo de variavel como "membro" da estrutura juntando-o
para uma finalidade especifica.

2. Declaracao de estruturas

O formato geral para a declaracao de um estrutura e':

struct <nome_estrutura>
	{	-> chave de abertura da estrutura

	membros;

	};	-> chave de fechamento da estrutura

Na declaracao da estrutura de dados temos a palavra reservada "struct" mais o
"nome da estrutura" que define o "novo tipo da variavel" criada pelo usuario. Na
declaracao dos "membros" da estrutura define-se as variaveis, que podem ser do
tipo char, int , float, long, vetor, estrutura, etc.., que irao compor este
"novo tipo de variavel".

Quando a estrutura de dados e' declarada, ainda nao foi criada a variavel
propriamente dita (reservado espaco em memoria). Para entender isso vamos fazer
uma analogia com a declaracao das variaveis simples que conhecemos.

Declarando uma variavel simples:
          <tipo> <nome_variavel>;

Declarando uma variavel composta do tipo estrutura de dados:
          struct <nome da estrutura> <nome da variavel>;
                  (tipo)

Exemplo usando a analogia:

- variavel simples
	   int notas;  -> variavel do tipo "int" de nome "notas"
          (tipo)

- variavel do tipo estrutura de dados

struct tipos      -> "novo tipo de variavel" definida pelo usuario
	{
	int a;
	float b;
	long c;
	};

     struct tipos numeros; -> variavel do tipo "struct tipos" de nome "numeros"
        (tipo)

3. Referencia aos membros de uma estrutura

Para referenciar um "membro" da estrutura de dados usamos o operador ponto(.)
no seguinte formato:
	<nome_variavel>.<membro>;

Exemplo:
	numeros.a
	numeros.b
	numeros.c

4. Inicializacao de estruturas de dados

Assim como nos vetores, uma estrutura de dados so' pode ser inicializada se
declarada como uma variavel global ou static local.

Porem se a inicializacao for elemento por elemento, a declaracao da variavel
pode ser local.

Exemplos:*/

#ifdef ex1
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};

/* declaracao da variavel como global. Por isso pode ser inicializada */
struct data calendario = {7,9,1822,250};

main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

#ifdef ex2
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};
main()
{
/* declaracao da variavel como estatica local. Por isso pode ser inicializada */
static struct data calendario = {15,11,1889,319};

printf("\nProclamacao da republica: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

#ifdef ex3
/* declaracao do tipo de variavel */
struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
	};
main()
{
/* declaracao da variavel como local porem sem inicializacao */
struct data calendario;

calendario.dia=26;       /*inicializacao elemento por elemento */
calendario.mes=1;
calendario.ano=1839;
calendario.dia_ano=26;

printf("\nFundacao de Santos: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

/*
5. Estruturas dentro de estruturas

Uma estrutura dentro de outra estrutura nada mais e' que uma variavel composta
dentro de outra variavel composta. Lembrando que os "membros" de uma estrutura
de dados pode ser de qualquer tipo, entao pode-se declarar como "membro" de uma
estrutura de dados outra estrutura de dados.

Para acessar os "membros" de uma estrutura de dados dentro de outra estrutura
de dados usa-se o operador ponto(.) partindo-se da variavel mais externa para
a variavel mais interna no seguinte formato:

	<nome_variavel>.<nome_variavel>.<membro>;
     estrutura externa   estrutura interna

Para se inicializar uma estrutura de dados dentro de outra estrutura de dados
tambem valem os conceitos vistos anteriormente.

Exemplo:*/

#ifdef ex4
/* declaracao do tipo de variavel */
struct relogio{
	int hora;    /* membros */
	int minutos;
	int segundo;
	};

struct data {
	int dia;    /* membros */
	int mes;
	int ano;
	int dia_ano;
struct relogio tempo;	/* declara uma variavel do tipo estrutura de nome
			   "tempo" dentro de outra variavel tipo estrutura */
	};
/* declaracao da variavel como global. Portanto pode ser inicializada */
struct data calendario = {7,9,1822,250,
	/* inicializando a variavel "tempo" dentro da variavel "calendario" */
                                       {20,50,10}};

/*outra forma de inicializar a variavel "tempo" dentro da variavel "calendario"
     struct data calendario = {7,9,1822,250,20,50,10};
*/

main()
{
printf("\nA data e': ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d ",calendario.dia_ano);

printf("e a hora e': ");
printf("%d:%d:%d",calendario.tempo.hora,calendario.tempo.minutos,
                  calendario.tempo.segundo);
}
#endif

#ifdef ex5
/* declaracao do tipo de variavel */
struct relogio{
	int hora;    /* membros */
	int minutos;
	int segundo;
	};

struct data {
	int dia;    /* membros */
	int mes;
	int ano;
struct relogio tempo;	/* declara uma variavel do tipo estrutura de nome
			   "tempo" dentro de outra variavel tipo estrutura */
	};

struct data calendario;

main()
{
/* entrada de dados */

printf("entre com data e hora do seu aniversario\n");
scanf("%d",&calendario.dia);
scanf("%d",&calendario.mes);
scanf("%d",&calendario.ano);

scanf("%d",&calendario.tempo.hora);
scanf("%d",&calendario.tempo.minutos);
scanf("%d",&calendario.tempo.segundo);

printf("\nA data e': ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);

printf("e a hora e': ");
printf("%d:%d:%d",calendario.tempo.hora,calendario.tempo.minutos,
                  calendario.tempo.segundo);
}
#endif

/*
6. Vetores como variavel dentro de uma estruturas de dados

Uma estrutura pode ser composta por variaveis simples(int, float, long, ...) e
variaveis compostas(vetores, estruturas). Neste caso, pode-se declarar um vetor
como "membro" de uma estrutura. O formato para declarar um vetor como "membro"
de uma estrutura e' o mesmo visto anteriormente.

Exemplo:*/
#ifdef ex6

struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[9]; /* declara um vetor do tipo "char" de nome "nome_mes"
			    com 9 elementos dentro de uma estrutura. */
	};

struct data calendario = {15,11,1889,319,"novembro"}; /* variavel global */

main()
{
printf("\nProclamacao da republica: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d, ",calendario.ano);
printf("%d - ",calendario.dia_ano);
printf("%s\n",calendario.nome_mes);/*imprime o "membro" "nome_mes" como string*/

printf("\nimprimindo o nome do mes letra a letra: %c%c%c%c%c%c%c%c",
calendario.nome_mes[0],
calendario.nome_mes[1],
calendario.nome_mes[2],
calendario.nome_mes[3],
calendario.nome_mes[4],
calendario.nome_mes[5],
calendario.nome_mes[6],
calendario.nome_mes[7]);
}
#endif

/*
7. Vetor de estruturas de dados

Como ja' estudamos, um vetor se caracteriza por ter todos os seus elementos do
mesmo tipo e acessar estes elementos por um indice. Com estrutura de dados nao
e' diferente.

Fazendo analogia com um vetor como ja' conhecemos ele e' composto por variaveis
simples do tipo int, float long,... Na declaracao de um vetor onde cada elemento
e' uma estrutura de dados nada muda, pois todos os elementos continuam sendo do
mesmo tipo. O detalhe esta' no tipo da variavel que neste caso e' definida pelo
usuario atraves da declaracao de uma estrutura de dados.

Para declarar um vetor de estruturas de dados, deve-se primeiro definir a
estrutura com seus "membros", "novo tipo de variavel", e depois declarar um
vetor deste tipo.

Aqui tambem para referenciar "membros" em um vetor de estrutura usa-se o "nome
da variavel" mais o "indice" do elemento do vetor e o operador ponto(.) para
acessar o "membro" da estrutura de dados no seguinte formato:

	<nome_variavel> [<n. do elemento>].<membro>;

Para se inicializar um vetor de estruturas tambem valem os conceitos de vistos
anteriormente.

Exemplo: */

#ifdef ex7
struct data {
	int dia;
	int mes;
	int ano;
	int dia_ano;
	char nome_mes[10];
	};

/* declara um vetor de estrutura do tipo "struct data" de nome "calendario" com
3 elementos sendo cada um uma estrutura*/

struct data calendario[3] = {7,9,1822,250,"setembro",
                                      15,11,1889,319,"novembro",
                                                 26,1,1839,26,"janeiro"};
main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario[0].dia);
printf("%d/",calendario[0].mes);
printf("%d, ",calendario[0].ano);
printf("%d - ",calendario[0].dia_ano);
printf("%s\n",calendario[0].nome_mes);

printf("\nProclamacao da republica: ");
printf("%d/",calendario[1].dia);
printf("%d/",calendario[1].mes);
printf("%d, ",calendario[1].ano);
printf("%d - ",calendario[1].dia_ano);
printf("%s\n",calendario[1].nome_mes);

printf("\nFundacao de Santos: ");
printf("%d/",calendario[2].dia);
printf("%d/",calendario[2].mes);
printf("%d, ",calendario[2].ano);
printf("%d - ",calendario[2].dia_ano);
printf("%s\n",calendario[2].nome_mes);
}
#endif

#ifdef ex8
struct data {
	int dia;
	int mes;
	int ano;
	char nome_mes[10];
	};
main()
{
/* declara um vetor de estrutura do tipo "struct data" de nome "calendario" com
3 elementos sendo cada um uma estrutura*/
struct data calendario[3];


printf("\nEntre com a data da Proclamacao da Independencia: \n");
scanf("%d",&calendario[0].dia);
scanf("%d",&calendario[0].mes);
scanf("%d",&calendario[0].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[0].nome_mes);
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario[0].dia);
printf("%d/",calendario[0].mes);
printf("%d, ",calendario[0].ano);
printf("%s\n",calendario[0].nome_mes);

printf("\nEntre com a data da Proclamacao da Republica: \n");
scanf("%d",&calendario[1].dia);
scanf("%d",&calendario[1].mes);
scanf("%d",&calendario[1].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[1].nome_mes);
printf("\nProclamacao da republica: ");
printf("%d/",calendario[1].dia);
printf("%d/",calendario[1].mes);
printf("%d, ",calendario[1].ano);
printf("%s\n",calendario[1].nome_mes);

printf("\nEntre com a data da Fundacao de Santos: \n");
scanf("%d",&calendario[2].dia);
scanf("%d",&calendario[2].mes);
scanf("%d",&calendario[2].ano);
printf("digite o mes por extenso: ");
scanf("%s",&calendario[2].nome_mes);
printf("\nFundacao de Santos: ");
printf("%d/",calendario[2].dia);
printf("%d/",calendario[2].mes);
printf("%d, ",calendario[2].ano);
printf("%s\n",calendario[2].nome_mes);
}
#endif

/*
8. Typedef
A Linguagem C permite definir explicitamente "novos nomes" para os tipos de
dados existentes usando-se a palavra reservada "typedef". Nao se cria um novo
tipo de variavel mas, ao contrario, define-se um "novo nome" para um tipo que
existem. O "typedef" tambem auxilia na documentacao do programa permitindo
definir nomes que descrevam melhor os tipos de dados padroes ou definidos pelo
usuario (estruturas).

O formato geral e':
   typedef <tipo de dado> <novo nome do tipo de dado>;

Exemplo:
   typedef int inteiro;
   typedef float flutuante;

Exemplo:  */

#ifdef ex9
struct data{
	int dia;
	int mes;
	int ano;
	int dia_ano;
	};

typedef struct data data;    /* a estrutura dados de nome "struct data" passa a
       		                ser chamada por um "novo nome que e' "data".*/

data calendario = {7,9,1822,250};

main()
{
printf("\nProclamacao da Independencia: ");
printf("%d/",calendario.dia);
printf("%d/",calendario.mes);
printf("%d ",calendario.ano);
printf("%d\n",calendario.dia_ano);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************

1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo e
    inicialize-a com algum conteudo. Imprima estes conteudos no video.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,

2 - Com a estrutura de dados do exercicio anterior, entre pelo teclado o
    conteudo de cada um dos membros e imprima-os no video no seguinte
    fomato.
            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long

3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo
    e inicialize-a com algum conteudo. Imprima estes conteudos no video.
             nome, end, cidade, estado, cep

4 - Crie outra estrutura de dados com os membros abaixo. Acrescente esta nova
    estrutura a estrutura de dados do exercicio anterior (estrutura dentro de
    outra estrutura) como mais um membro e receba via teclado todos os dados.
    Declare a variavel como local e imprima estes conteudos no video.
             tel, cpf, rg

5 - Com a estrutura do exercicio 3 acima defina um vetor de estruturas de 3
    elementos. Receba os dados pelo teclado e imprima-os no video. (vetor de
    estruturas)
*/
/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo e
    inicialize-a com algum conteudo. Imprima estes conteudos no video.
             char, int, long, float, double
             unsigned char, unsigned int, unsigned long,*/
#ifdef ex10
struct nsei {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

struct nsei naosei = {'a',10,100,14.5,14.1,44,212,155151};

int main() {
    printf("Char: %c\nInt: %d\nLong: %ld\nFloat: %.2f\nDouble: %.2f\nUnsigned char: %u\nUnsigned Int: %u\nUnsigned Long: %u",naosei.c,naosei.i,naosei.l,naosei.f,naosei.d,naosei.uc,naosei.ui,naosei.ul);
}
#endif // ex10
/*2 - Com a estrutura de dados do exercicio anterior, entre pelo teclado o
    conteudo de cada um dos membros e imprima-os no video no seguinte
    fomato.
            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long*/
#ifdef ex11
struct nsei {
    char c;
    int i;
    long l;
    float f;
    double d;
    unsigned char uc;
    unsigned int ui;
    unsigned long ul;
};

struct nsei naosei;

int main() {

    printf("Digite um valor para CHAR: ");
    scanf("%c",&naosei.c);
    printf("\nDigite um valor para INT: ");
    scanf("%d",&naosei.i);
    printf("\nDigite um valor para LONG: ");
    scanf("%ld",&naosei.l);
    printf("\nDigite um valor para FLOAT: ");
    scanf("%f",&naosei.f);
    printf("\nDigite um valor para DOUBLE: ");
    scanf("%lf",&naosei.d);
    printf("\nDigite um valor para UNSIGNED CHAR: ");
    scanf("%u",&naosei.uc);
    printf("\nDigite um valor para UNSIGNED INT: ");
    scanf("%u",&naosei.ui);
    printf("\nDigite um valor para UNSIGNED LONG: ");
    scanf("%ul",&naosei.ul);
    printf("\n        10        20        30        40        50        60        70");
    printf("\n1234567890123456789012345678901234567890123456789012345678901234567890");
    printf("\n    %c         %d         %ld                   %.2f                %.2f",naosei.c,naosei.i,naosei.l,naosei.f,naosei.d);
    printf("\n          %u                   %u                   %u",naosei.uc,naosei.ui,naosei.ul);
}
#endif // ex11
/*3 - Escreva um programa que tem uma estrutura da dados com os membros abaixo
    e inicialize-a com algum conteudo. Imprima estes conteudos no video.
             nome, end, cidade, estado, cep*/
#ifdef ex12
struct nsei {
    char nome[10];
    char endereco[20];
    char cidade[10];
    char estado[3];
    char cep[12];
};

struct nsei cadastro = {"Leo","Av.Nsei","SaoVic","SP","xxxxxxxxx"};

int main() {
    printf("Nome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n",cadastro.nome,cadastro.endereco,cadastro.cidade,cadastro.estado,cadastro.cep);
}

#endif // ex12

/*4 - Crie outra estrutura de dados com os membros abaixo. Acrescente esta nova
    estrutura a estrutura de dados do exercicio anterior (estrutura dentro de
    outra estrutura) como mais um membro e receba via teclado todos os dados.
    Declare a variavel como local e imprima estes conteudos no video.tel, cpf, rg*/
#ifdef ex13
struct id {
    char tel[10];
    char cpf[13];
    char rg[10];
};

struct pessoa {
    char nome[10];
    char endereco[20];
    char cidade[10];
    char estado[3];
    char cep[12];
    struct id id;
};

int main() {
    static struct pessoa cadastro = {"Leo","Av.Nsei","SaoVic","SP","xxxxxxxxx","1010100","54000000","4444444"};
    printf("Nome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\nTelefone: %s\nCPF: %s\nRG: %s\n",cadastro.nome,cadastro.endereco,cadastro.cidade,cadastro.estado,cadastro.cep,cadastro.tel,cadastro.cpf,cadastro.rg);
}
#endif // ex13
/* 5 - Com a estrutura do exercicio 3 acima defina um vetor de estruturas de 3
    elementos. Receba os dados pelo teclado e imprima-os no video. (vetor de
    estruturas) */
#ifdef ex14
struct id {
    char tel[10];
    char cpf[13];
    char rg[10];
};
struct dados {
    char nome[10];
    char endereco[20];
    char cidade[10];
    char estado[3];
    char cep[12];
    struct id id;
};
struct dados pessoas[3];
int main() {
    int i;
    for(i=0;i<3;i++) {
        printf("\n\nPessoa %d\n\n",i+1);
        printf("\nDigite seu nome: ");
        scanf("%s",&pessoas[i].nome);

        printf("\nDigite seu endereco: ");
        scanf("%s",&pessoas[i].endereco);

        printf("\nDigite o nome de sua cidade: ");
        scanf("%s",&pessoas[i].cidade);

        printf("\nDigite a sigla de seu estado: ");
        scanf("%s",&pessoas[i].estado);

        printf("\nDigite seu CEP: ");
        scanf("%s",&pessoas[i].cep);

        printf("\nDigite seu telefone: ");
        scanf("%s",&pessoas[i].id.tel);

        printf("\nDigite seu CPF: ");
        scanf("%s",&pessoas[i].id.cpf);

        printf("\nDigite seu RG: ");
        scanf("%s",&pessoas[i].id.rg);
    }
    printf("\nPessoas cadastradas: \n");
    for(i=0;i<3;i++) {
        printf("\nPessoa %d\n",i+1);
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCEP: %s\nTelefone: %s\nCPF: %s\nRG: %s\n\n",
        pessoas[i].nome,pessoas[i].endereco,pessoas[i].cidade,pessoas[i].estado,pessoas[i].cep,pessoas[i].id.tel,
        pessoas[i].id.cpf,pessoas[i].id.rg);
    }
}
#endif // ex14
