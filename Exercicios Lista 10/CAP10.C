#define ex14
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
/******************************************************************************

			MANIPULACAO DE ARQUIVOS

*******************************************************************************

1 - Introducao

Na Linguagem C, um arquivo e' um conceito logico onde todas as entradas ou
saidas da maquina sao associadas a um arquivo. Assim um arquivo em disco
tambem pode usar este conceito logico pois e' uma entrada e saida da maquina.
Para trocar dados com um arquivo especifico realiza-se uma operacao de
abertura do arquivo. Uma vez que o arquivo esteja aberto, informacoes podem ser
intercambiadas entre o arquivo e o seu programa.

Nem todos os arquivos tem as mesmas capacidades. Por exemplo, um  arquivo em
disco pode-se ler e escrever dados enquanto a entrada de dados pelo teclado so'
pode ler dados.Isso ilustra um ponto importante sobre o sistema de entrada/saida
(E/S) de dados da linguagem C: todos os dados sao os mesmos, mas nem todos os
arquivos os sao.

A abertura de um arquivo inicializa um ponteiro de arquivo apontando para o
comeco dele. A medida que cada caracter e' lido ou escrito no arquivo, o
ponteiro de arquivo e' incrementado, assegurando assim a progressao deste
atraves do arquivo.

O acesso a um arquivo e' interrompido por meio de uma operação de fechamento.
Nos arquivos abertos como saida, o fechamento faz com que o conteudo, se houver,
na memoria intermediaria(buffer) seja descarregado para o dispositivo externo.
Esse processo e' geralmente referenciado como uma limpeza/descarga de dados
e garante que nenhuma informacao sera' acidentalmente esquecida na area
intermediaria(buffer) do disco. Todos os arquivos sao fechados automaticamente
quando o programa termina normalmente.

Resumindo, os procedimentos para se acessar um arquivo sao:
- abertura do arquivo
- leitura ou escrita de dados
- fechamento do arquivo

2 - Ponteiro de arquivo

A linha comum que une o sistema de E/S de disco aos programas escritos em C e' o
ponteiro de arquivo. Este é um ponteiro para uma area na memoria(buffer) onde
estao contidos varios dados sobre o arquivo, tais como o nome do arquivo, estado
e posicao corrente, etc. A memoria(buffer) apontado pelo ponteiro de arquivo e'
a area intermediaria entre o arquivo no disco e o programa.

Um ponteiro de arquivo e' uma variavel ponteiro do tipo "FILE" que esta definida
no arquivo de cabecalho(header) "stdio.h". Para ler ou escrever dados em um
arquivo de disco, o programa deve declarar uma (ou mais de uma se formos
trabalhar com mais de um arquivo simultaneamente) variavel ponteiro de arquivo.

Para declarar uma variavel ponteiro de arquivo, usa-se o seguinte formato:

    FILE *p1;  -> "p1" é uma variavel ponteiro de arquivo do tipo "FILE"

3 - fopen()

A funcao fopen() abre um arquivo associando-o a uma estrutura do tipo "FILE" que
e' atualizada com as informacoes necessarias e retorna um ponteiro  de arquivo
ou simplesmente ponteiro para a localizacao desta estrutura. Deve-se entao fazer
a atribuicao deste valor retornado a um ponteiro previamente declarado pois
este sera' usado em substituicao ao nome do arquivo.

O formato geral e':
	fopen(nome_arquivo,modo);

  - nome_arq --> e' uma serie de caracteres contendo o nome externo do arquivo
  - modo ------> informa o tipo de uso que tera' o arquivo, podendo ser :

"r" --> Abre o arquivo apenas para leitura. Se ele ja' estava aberto, entao
o ponteiro e' posicionado no primeiro caracter do arquivo. Caso o arquivo nao
exista entao e' retornado uma condicao de erro representada pela constante
"NULL". A constante "NULL" e' definido no arquivo "stdio.h" e tem o valor -1.

"w" --> Abre o arquivo apenas para escrita. Se o arquivo ja' existia no disco,
entao todos os dados serao perdidos e se nao existia entao sera' criado.

"a" --> Abre o arquivo para acrescentar dados. Caso o arquivo nao exista sera'
criado.

"x" --> Abre o arquivo para escrita. O arquivo nao pode existir previamente.

4 - getc() e putc()

Estas funcoes de leitura e escrita para apenas um caracter por vez no arquivo.
Sao similares as funcoes getchar() e putchar().

O formato geral e':
	getc(ponteiro);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo

O formato geral e':
	putc(caracter,ponteiro);
   - caracter --> caracter a ser escrito no arquivo
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo

5 - fclose()

Esta funcao fecha o arquivo aberto com a funcao fopen() liberando as areas de
memoria e blocos de controle criados para gerenciamento deste arquivo.

O formato geral e':
	fclose(ponteiro);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

6 - exit()

Esta funcao fecha todos arquivos que estejam abertos, encerra  a execucao do
programa e retorna ao sistema operacional.

O formato geral e':
	exit(0);

Exemplo:*/

#ifdef ex1
/*o programa cria e escreve caracteres no arquivo "teste1"*/
main()
{

//FILE *fopen(); /*a funcao fopen() retorna um ponteiro do tipo "FILE". Por isso,
//                 tem que fazer esta declaracao */
FILE *p;   /*declara o ponteiro "p" do tipo "FILE"*/
char ch;
char i;

printf("exemplo1 \n\n");
printf("abre o arquivo no modo escrita w \n");
if((p = fopen("teste1.txt","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);  /*encerra o programa e volta ao sistema operacional*/
	}

printf("escreve 4 caracteres no arquivo teste1\n");
putc('a',p);
putc(66,p);

ch = 'e';
putc(ch,p);

i=70;
putc(i,p);

fclose(p);
}
#endif

#ifdef ex2
/* o programa le os caracteres escritos no arquivo "teste1" pelo exemplo 1*/
main()
{
//FILE *fopen();
FILE *p;
char ch;

printf("exemplo2 \n\n\n");
printf("abre o arquivo no modo leitura r \n");
if((p = fopen("teste1.txt","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le os char escrito no arquivo pelo exemplo 1 e imprime na tela\n\n");
ch = getc(p);
putchar(ch);
putchar(getc(p));
putchar(getc(p));
putchar(getc(p));

fclose(p);
}
#endif

/*

7 - fscanf() e fprintf()

As funcoes fprintf() e fscanf() sao a leitura e a escrita formatada de dados
em arquivos, que seguem exatamente as mesmas caracteristicas das similares
printf() e scanf() acrescentando o ponteiro do arquivo.

O formato geral e':
	fprintf(ponteiro,serie_de_controle,argumentos);
	fscanf(ponteiro,serie_de_controle,argumentos);
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.
   - serie de controle --> usa-se os mesmos codigos de formatacao do printf().
   - argumentos --> como no printf() coloca-se as variaveis para os codigos de
  		    formatacao.
Exemplo:*/

#ifdef ex3
/*o programa cria e escreve dados formatados no arquivo teste2*/
main()
{
//FILE *fopen();
FILE *p;
int i = 100;
float f = 20.34;
unsigned u = 65000;
long l = 2000000000;
char c = 'x';
static char s[] = "dadosformatados";

if((p = fopen("teste2","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve dados formatados no arquivo teste2\n");
fprintf(p,"%d ",i);
fprintf(p,"%f ",f);
fprintf(p,"%u ",u);
fprintf(p,"%ld ",l);
fprintf(p,"%c ",c);
fprintf(p,"%s ",s);

fclose(p);
}
#endif

#ifdef ex4
/* programa que le dados formatados do arquivo teste2 e imprime na tela*/
main()
{
//FILE *fopen();
FILE *p;
int i;
float f;
unsigned u;
long l;
char c;
static char s[20];

if((p = fopen("teste2","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le os dados escritos pelo exemplo anterior\n");
fscanf(p,"%d ",&i);
fscanf(p,"%f ",&f);
fscanf(p,"%u ",&u);
fscanf(p,"%ld ",&l);
fscanf(p,"%c ",&c);
fscanf(p,"%s ",s);

printf("imprime na tela os dados formatados lidos do arquivo teste2\n\n");
printf("inteiro : %d\n",i);
printf("float   : %f\n",f);
printf("unsigned: %u\n",u);
printf("long    : %ld\n",l);
printf("char    : %c\n",c);
printf("string  : %s\n",s);

fclose(p);
}
#endif
/*

8 - fgets() e fputs()

As funcoes fgets() e fputs() le e escreve uma serie de caracteres no arquivo .
Elas sao similares as funcoes gets() e puts().

O formato geral e':
	fgets(string,tamanho,ponteiro);
   - string ----> e' a variavel que recebera'os caracteres lidos.
   - tamanho ---> e' o numero de caracteres a serem lidos
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

O formato geral e':
	fputs(string,ponteiro);
   - string ----> e' a variavel a ser escrita no arquivo.
   - ponteiro --> e' o ponteiro para a posicao corrente do arquivo.

Exemplos:*/

#ifdef ex5
main()
{
//FILE *fopen();
FILE *p;
static char s[] = "teste com variavel";
char a[40];
char b[100];

if((p = fopen("teste3","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve as strings no arquivo teste3\n");
fputs("isto e' um pequeno teste com uma string",p);
fputs(s,p);

fclose(p);
getchar();

if((p = fopen("teste3","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le as strings do arquivo teste3\n\n");
fgets(a,40,p);
fgets(b,100,p);

printf("escreve as strings lidas na tela\n\n");
puts(a);
puts(b);

fclose(p);
}
#endif

/*
9 - fread() e fwrite()

As funcoes fread() e fwrite() sao utilizadas para ler e escrever dados compostos
no arquivo.

O formato geral e':
	fread(b,c,n,p);
	fwrite(b,c,n,p);
   b -> e' o ponteiro para a variavel que recebera ou contem os dados.
   c -> e' o n. de bytes que serao lidos ou escritos.
   n -> e' o n. de itens que serao lidos ou escritos.
   p -> e' o ponteiro para a posicao corrente do arquivo.

Exemplo:*/

#ifdef ex6
char ch[5] = {'a','b','c','d','\0'};
typedef struct dados
	{
	int i;
	float f;
	double d;
	} dados;
dados numeros = {1000,5000,10000};

main()
{
char st[5];
dados num;

//FILE *fopen();
FILE *p;

if((p = fopen("teste4","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve as variaveis no arquivo teste4\n");
fwrite(ch,5,1,p);
fwrite(&numeros,sizeof(numeros),1,p);

fclose(p);
getchar();

if((p = fopen("teste4","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("le as variaveis do arquivo teste4\n\n");
fread(st,5,1,p);
fread(&num,sizeof(num),1,p);

printf("escreve as variaveis lidas na tela\n\n");
printf("vetor: %s\n\n",st);
printf("estrutura: %d\n",num.i);
printf("estrutura: %f\n",num.f);
printf("estrutura: %g\n",num.d);

fclose(p);
}
#endif

/*
10 - fseek()

A funcao fseek() e' utilizada para posicionar o ponteiro do arquivo em
qualquer ponto para executar as operacoes de leitura ou escrita.

O formato e':
	fseek(p,d,o);
   p -> e' o ponteiro para a posicao corrente do arquivo.
   d -> e' o numero de bytes que serao deslocados que pode ser positivo ou
	negativo.
   o -> e' a origem para o deslocamento que sera' somado ou subtraido
        e pode assumir 3 valores que sao:
   	   0 -> comeco do arquivo.
	   1 -> posicao atual do arquivo.
	   2 -> fim do arquivo.
Exemplo: */
#ifdef ex7
struct dados
	{
	int i;
	float f;
	double d;

	char a;
	char b;
	char c;
	};
struct dados varios = {1000,20000,300000,'a','i','r'};

main()
{
//FILE *fopen();
FILE *p;
long y;		/* deslocamento */
long k = 0;	/* n. do registro */
int x;

if((p = fopen("teste5","w"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}
printf("escreve 5 registros no arquivo teste5\n");
getchar();
for(x=0;x < 5;x++)
	{
	printf("escreve o registro %d: \n",x+1);
	printf("int    i: %d\n",varios.i);
	printf("float  f: %f\n",varios.f);
	printf("double d: %g\n",varios.d);
	printf("char a: %c\n",varios.a);
	printf("char b: %c\n",varios.b);
	printf("char c: %c\n",varios.c);
	getchar();

	fwrite(&varios,sizeof(varios),1,p);
	varios.i = varios.i + 10;
	varios.f = varios.f + 100;
	varios.d = varios.d + 1000;
	varios.a = varios.a + 1;
	varios.b = varios.b + 1;
	varios.c = varios.c + 1;
	}
fclose(p);

if((p = fopen("teste5","r"))==NULL)
	{
	printf("erro na abertura do arquivo \n");
	exit(0);
	}

printf("calcula o n. de bytes a partir do inicio do arquivo ate' o inicio\n");
printf(" do 3. registro. o 3. registro tem indice 2\n\n");
k = 2;
y = k * sizeof(varios);

printf("posiciona o ponteiro p no inicio 3. registro do arquivo teste5\n\n");
fseek(p,y,0);

printf("le o 3. registro do arquivo teste5\n\n");
fread(&varios,sizeof(varios),1,p);

printf("escreve o 3. registro na tela\n\n");
printf("int    i: %d\n",varios.i);
printf("float  f: %f\n",varios.f);
printf("double d: %g\n",varios.d);
printf("char a: %c\n",varios.a);
printf("char b: %c\n",varios.b);
printf("char c: %c\n",varios.c);

fclose(p);
}
#endif

/*****************************************************************************

			EXERCICIOS

*****************************************************************************

1 - Crie uma funcao para escrever num arquivo os dados do exercicio 3 de
    estruturas. (utilize as funcao putc).

2 - Escreva uma funcao para ler do arquivo os dados gravados do exercicio
    anterior. (utilize as funcao getc).

3 - Reescreva as funcoes de gravacao e leitura no arquivo dos exercicios
    anteriores utilizando as funcoes fwrite e fread.

4 - A partir do exercico 7 do capitulo de funcoes, acrescente as funcoes de
    gravacao e leitura dos dados em um arquivo. Inclua-as como opcoes no menu.

5 - Reescreva o programa do exercicio anterior fazendo a leitura e escrita de
    dados no arquivo ao entrar e sair do programa. Retire estas opcoes do menu.

6 - Reescreva o programa do execicio anterior fazendo a leitura e escrita de
    dados no arquivo apenas quando for necessario.

7 - Reescreva o programa do exercicio anterior retirando o vetor de estruturas
    deixando apenas uma estrutura simples. Escreva e leia os registros direto
    no arquivo utilizando usando apenas esta estrutura. (utilize a funcao fseek).
*/

/*1 - Crie uma funcao para escrever num arquivo os dados do exercicio 3 de
    estruturas. (utilize as funcao putc).*/
#ifdef ex8

struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void escrever(dados *cadastro);

main() {
    struct dados cadastro = {"Leonardo","Av. Central","SaoVicente","SP","11348000"};
    escrever(&cadastro);
}

void escrever(dados *cadastro) {
    FILE *p;
    char ch;
    int i=0;

    if((p = fopen("ex1","w"))==NULL) {
        puts("Erro ao abrir o arquivo\n");
        exit(0);
    }
    do {
        ch = cadastro->nome[i];
        putc(ch,p);
        i++;
        printf("%c ", ch);
    } while(ch != '\0');
    i=0;
    do {
        ch = cadastro->end[i];
        putc(ch,p);
        i++;
        printf("%c ", ch);
    } while(ch != '\0');
    i=0;
    do {
        ch = cadastro->cidade[i];
        putc(ch,p);
        i++;
        printf("%c ", ch);
    } while(ch != '\0');
    i=0;
    do {
        ch = cadastro->estado[i];
        putc(ch,p);
        i++;
        printf("%c ", ch);
    } while(ch != '\0');
    i=0;
    do {
        ch = cadastro->cep[i];
        putc(ch,p);
        i++;
        printf("%c ", ch);
    } while(ch != '\0');
    fclose(p);
}

#endif // ex8

/*2 - Escreva uma funcao para ler do arquivo os dados gravados do exercicio
    anterior. (utilize as funcao getc).*/
#ifdef ex9
void ler();
main() {
    ler();
}

void ler () {
    FILE *p;
    int i=0;
    char ch;

    if((p = fopen("ex1","r"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    }

    do {
        ch = getc(p);
        putchar(ch);
    } while(ch != '\0');

    do {
        ch = getc(p);
        putchar(ch);
    } while(ch != '\0');

    do {
        ch = getc(p);
        putchar(ch);
    } while(ch != '\0');

    do {
        ch = getc(p);
        putchar(ch);
    } while(ch != '\0');

    do {
        ch = getc(p);
        putchar(ch);
    } while(ch != '\0');

    fclose(p);
}
#endif // ex9

/*3 - Reescreva as funcoes de gravacao e leitura no arquivo dos exercicios
    anteriores utilizando as funcoes fwrite e fread. */
#ifdef ex10
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void escrever(struct dados *cadastro);
void ler(struct dados *cadastro);

main() {
    struct dados cadastro = {"Leonardo","Av. Central","SaoVicente","SP","11348000"};
    escrever(&cadastro);
    ler(&cadastro);
}

void escrever(struct dados *cadastro) {
    FILE *p;
    if ((p = fopen("ex1","w"))==NULL) {
        puts("Falha ao tentar abrir o arquivo.");
        exit(0);
    }
    fwrite(cadastro->nome, strlen(cadastro->nome)+1,1,p);
    fwrite(cadastro->end, strlen(cadastro->end)+1,1,p);
    fwrite(cadastro->cidade, strlen(cadastro->cidade)+1,1,p);
    fwrite(cadastro->estado, strlen(cadastro->estado)+1,1,p);
    fwrite(cadastro->cep, strlen(cadastro->cep)+1,1,p);
    fclose(p);
}

void ler(struct dados *cadastro) {
    dados aux;
    FILE *p;
    if ((p = fopen("ex1","r"))==NULL) {
        puts("Falha ao tentar abrir o arquivo.");
        exit(0);
    }

    fread(cadastro,sizeof(cadastro),1,p);
    printf("%s ",cadastro->nome);

    fread(cadastro,sizeof(cadastro),1,p);
    printf("%s ",cadastro->end);

    fread(cadastro,sizeof(cadastro),1,p);
    printf("%s ",cadastro->cidade);

    fread(cadastro,sizeof(cadastro),1,p);
    printf("%s ",cadastro->estado);

    fread(cadastro,sizeof(cadastro),1,p);
    printf("%s",cadastro->cep);

    fclose(p);
}

#endif // ex10

/*4 - A partir do exercico 7 do capitulo de funcoes, acrescente as funcoes de
    gravacao e leitura dos dados em um arquivo. Inclua-as como opcoes no menu. */
#ifdef ex11
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *ppessoas);
void exibicao(struct dados *ppessoas);
void procurar(struct dados *ppessoas);
void alterar(struct dados *ppessoas);
void excluir(struct dados *ppessoas);
void gravarArquivo(struct dados *ppessoas);
void lerArquivo();
int checarNome(char *nome, dados *ppessoas);

main() {
    int i, op; //             nome, end, cidade, estado, cep
    struct dados pessoas[3] = {"Leonardo","Avenida Central","Sao Vicente","sp","11348000",
                               "Amanda","Rua Bartolomeu","Sao Vicente","sp","11399000",
                               "Cristina","Avenida Goias","Sao Paulo","sp","11247000"};
    do {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n4 - Alterar\n5 - Excluir\n6 - Gravar arquivo\n7 - Ler arquivo\n8 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: recepcao(&pessoas[0]);
            break;
            case 2: exibicao(&pessoas[0]);
            break;
            case 3: procurar(&pessoas[0]);
            break;
            case 4: alterar(&pessoas[0]);
            break;
            case 5: excluir(&pessoas[0]);
            break;
            case 6: gravarArquivo(&pessoas[0]);
            break;
            case 7: lerArquivo();
            break;
            case 8: printf("\nEncerrando...\n");
            break;
        }
    } while(op != 8);
}

void recepcao(struct dados *ppessoas) {
    int i;
    for(i=0; i<3; i++) {
        puts("Digite seu nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
}

void exibicao(struct dados *ppessoas) {
    int i;
    for(i=0;i<3;i++) {
        printf("\n");
        printf("Nome: %s\n",(ppessoas+i)->nome);
        printf("Endereco: %s\n",(ppessoas+i)->end);
        printf("Cidade: %s\n",(ppessoas+i)->cidade);
        printf("Estado: %s\n",(ppessoas+i)->estado);
        printf("Cep: %s\n",(ppessoas+i)->cep);
    }
}

void procurar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0){
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n", (ppessoas+i)->nome,(ppessoas+i)->end,(ppessoas+i)->cidade,(ppessoas+i)->estado,(ppessoas+i)->cep);
    }
}

void alterar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        puts("Digite seu novo nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu novo endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua nova cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu novo estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu novo cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
}

void excluir(struct dados *ppessoas) {
    int i, j;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        strcpy((ppessoas+i)->nome,"");
        strcpy((ppessoas+i)->end,"");
        strcpy((ppessoas+i)->cidade,"");
        strcpy((ppessoas+i)->estado,"");
        strcpy((ppessoas+i)->cep,"");
        printf("\n\"Excluido\"\n");
    }
}

void gravarArquivo(struct dados *ppessoas) {
    FILE *p;
    int i;

    if((p = fopen("ex4","w"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0; i<3; i++) {
            fwrite((ppessoas+i)->nome,sizeof((ppessoas+i)->nome),1,p);
            fwrite((ppessoas+i)->end,sizeof((ppessoas+i)->end),1,p);
            fwrite((ppessoas+i)->cidade,sizeof((ppessoas+i)->cidade),1,p);
            fwrite((ppessoas+i)->estado,sizeof((ppessoas+i)->estado),1,p);
            fwrite((ppessoas+i)->cep,sizeof((ppessoas+i)->cep),1,p);
        }
        printf("\nArquivo gravado com sucesso!\n");
    }
    fclose(p);
}

void lerArquivo() {
    FILE *p;
    dados cpessoas[3];
    int i;
    if((p = fopen("ex4","r"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0;i<3;i++) {
            fread(cpessoas[i].nome,sizeof(cpessoas[i].nome),1,p);
            fread(cpessoas[i].end,sizeof(cpessoas[i].end),1,p);
            fread(cpessoas[i].cidade,sizeof(cpessoas[i].cidade),1,p);
            fread(cpessoas[i].estado,sizeof(cpessoas[i].estado),1,p);
            fread(cpessoas[i].cep,sizeof(cpessoas[i].cep),1,p);
        }
        for(i=0;i<3;i++) {
            printf("\nNome: %s\n",cpessoas[i].nome);
            printf("Endereco: %s\n",cpessoas[i].end);
            printf("Cidade: %s\n",cpessoas[i].cidade);
            printf("Estado: %s\n",cpessoas[i].estado);
            printf("Cep: %s\n\n",cpessoas[i].cep);
        }
    }
    fclose(p);
}

int checarNome(char *nome, struct dados *ppessoas) {
    int i,j,c = 0;
    for(i=0; i<3; i++) {
        if(strlen(nome)==strlen((ppessoas+i)->nome)) {
            for(j=0; j<strlen(nome); j++) {
                if(nome[j]==(ppessoas+i)->nome[j]) {
                    c++;
                }
            }
            if(c == strlen((ppessoas+i)->nome)) {
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
#endif // ex11

/*5 - Reescreva o programa do exercicio anterior fazendo a leitura e escrita de
    dados no arquivo ao entrar e sair do programa. Retire estas opcoes do menu.*/
#ifdef ex12
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *ppessoas);
void exibicao(struct dados *ppessoas);
void procurar(struct dados *ppessoas);
void alterar(struct dados *ppessoas);
void excluir(struct dados *ppessoas);
void gravarArquivo(struct dados *ppessoas);
void lerArquivo();
int checarNome(char *nome, dados *ppessoas);

main() {
    int i, op; //             nome, end, cidade, estado, cep
    struct dados pessoas[3] = {"Leonardo","Avenida Central","Sao Vicente","sp","11348000",
                               "Amanda","Rua Bartolomeu","Sao Vicente","sp","11399000",
                               "Cristina","Avenida Goias","Sao Paulo","sp","11247000"};
    gravarArquivo(&pessoas[0]);
    lerArquivo();
    do {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n4 - Alterar\n5 - Excluir\n8 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: recepcao(&pessoas[0]);
            break;
            case 2: exibicao(&pessoas[0]);
            break;
            case 3: procurar(&pessoas[0]);
            break;
            case 4: alterar(&pessoas[0]);
            break;
            case 5: excluir(&pessoas[0]);
            break;
            case 8: gravarArquivo(&pessoas[0]);
                    lerArquivo();
                    printf("\nEncerrando...\n");
            break;
        }
    } while(op != 8);
}

void recepcao(struct dados *ppessoas) {
    int i;
    for(i=0; i<3; i++) {
        puts("Digite seu nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
}

void exibicao(struct dados *ppessoas) {
    int i;
    for(i=0;i<3;i++) {
        printf("\n");
        printf("Nome: %s\n",(ppessoas+i)->nome);
        printf("Endereco: %s\n",(ppessoas+i)->end);
        printf("Cidade: %s\n",(ppessoas+i)->cidade);
        printf("Estado: %s\n",(ppessoas+i)->estado);
        printf("Cep: %s\n",(ppessoas+i)->cep);
    }
}

void procurar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0){
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n", (ppessoas+i)->nome,(ppessoas+i)->end,(ppessoas+i)->cidade,(ppessoas+i)->estado,(ppessoas+i)->cep);
    }
}

void alterar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        puts("Digite seu novo nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu novo endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua nova cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu novo estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu novo cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
}

void excluir(struct dados *ppessoas) {
    int i, j;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        strcpy((ppessoas+i)->nome,"");
        strcpy((ppessoas+i)->end,"");
        strcpy((ppessoas+i)->cidade,"");
        strcpy((ppessoas+i)->estado,"");
        strcpy((ppessoas+i)->cep,"");
        printf("\n\"Excluido\"\n");
    }
}

void gravarArquivo(struct dados *ppessoas) {
    FILE *p;
    int i;

    if((p = fopen("ex4","w"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0; i<3; i++) {
            fwrite((ppessoas+i)->nome,sizeof((ppessoas+i)->nome),1,p);
            fwrite((ppessoas+i)->end,sizeof((ppessoas+i)->end),1,p);
            fwrite((ppessoas+i)->cidade,sizeof((ppessoas+i)->cidade),1,p);
            fwrite((ppessoas+i)->estado,sizeof((ppessoas+i)->estado),1,p);
            fwrite((ppessoas+i)->cep,sizeof((ppessoas+i)->cep),1,p);
        }
    }
    fclose(p);
}

void lerArquivo() {
    FILE *p;
    dados cpessoas[3];
    int i;
    if((p = fopen("ex4","r"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0;i<3;i++) {
            fread(cpessoas[i].nome,sizeof(cpessoas[i].nome),1,p);
            fread(cpessoas[i].end,sizeof(cpessoas[i].end),1,p);
            fread(cpessoas[i].cidade,sizeof(cpessoas[i].cidade),1,p);
            fread(cpessoas[i].estado,sizeof(cpessoas[i].estado),1,p);
            fread(cpessoas[i].cep,sizeof(cpessoas[i].cep),1,p);
        }
        for(i=0;i<3;i++) {
            printf("\nNome: %s\n",cpessoas[i].nome);
            printf("Endereco: %s\n",cpessoas[i].end);
            printf("Cidade: %s\n",cpessoas[i].cidade);
            printf("Estado: %s\n",cpessoas[i].estado);
            printf("Cep: %s\n\n",cpessoas[i].cep);
        }
    }
    fclose(p);
}

int checarNome(char *nome, struct dados *ppessoas) {
    int i,j,c = 0;
    for(i=0; i<3; i++) {
        if(strlen(nome)==strlen((ppessoas+i)->nome)) {
            for(j=0; j<strlen(nome); j++) {
                if(nome[j]==(ppessoas+i)->nome[j]) {
                    c++;
                }
            }
            if(c == strlen((ppessoas+i)->nome)) {
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
#endif // ex12

/*6 - Reescreva o programa do execicio anterior fazendo a leitura e escrita de
    dados no arquivo apenas quando for necessario. */
#ifdef ex13
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *ppessoas);
void exibicao(struct dados *ppessoas);
void procurar(struct dados *ppessoas);
void alterar(struct dados *ppessoas);
void excluir(struct dados *ppessoas);
void gravarArquivo(struct dados *ppessoas);
void lerArquivo(struct dados *ppessoas);
int checarNome(char *nome, dados *ppessoas);

main() {
    int i, op;
    struct dados pessoas[3];
    lerArquivo(&pessoas[0]);
    do {
        printf("\nEscolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n4 - Alterar\n5 - Excluir\n8 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: recepcao(&pessoas[0]);
            break;
            case 2: exibicao(&pessoas[0]);
            break;
            case 3: procurar(&pessoas[0]);
            break;
            case 4: alterar(&pessoas[0]);
            break;
            case 5: excluir(&pessoas[0]);
            break;
            case 8: lerArquivo(&pessoas[0]);
                    printf("\nEncerrando...\n");
            break;
        }
    } while(op != 8);
}

void recepcao(struct dados *ppessoas) {
    int i;
    for(i=0; i<3; i++) {
        puts("Digite seu nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
    gravarArquivo(ppessoas);
}

void exibicao(struct dados *ppessoas) {
    int i;
    for(i=0;i<3;i++) {
        if((ppessoas)->nome[0] != '*') {
            printf("\n");
            printf("Nome: %s\n",(ppessoas+i)->nome);
            printf("Endereco: %s\n",(ppessoas+i)->end);
            printf("Cidade: %s\n",(ppessoas+i)->cidade);
            printf("Estado: %s\n",(ppessoas+i)->estado);
            printf("Cep: %s\n",(ppessoas+i)->cep);
        }
    }
}

void procurar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0){
        printf("\nNome: %s\nEndereco: %s\nCidade: %s\nEstado: %s\nCep: %s\n", (ppessoas+i)->nome,(ppessoas+i)->end,(ppessoas+i)->cidade,(ppessoas+i)->estado,(ppessoas+i)->cep);
    }
}

void alterar(struct dados *ppessoas) {
    int i;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        puts("Digite seu novo nome: ");
        gets((ppessoas+i)->nome);
        puts("Digite seu novo endereco: ");
        gets((ppessoas+i)->end);
        puts("Digite sua nova cidade: ");
        gets((ppessoas+i)->cidade);
        puts("Digite seu novo estado: ");
        gets((ppessoas+i)->estado);
        puts("Digite seu novo cep: ");
        gets((ppessoas+i)->cep);
        printf("\n");
    }
    gravarArquivo(ppessoas);
}

void excluir(struct dados *ppessoas) {
    int i, j;
    char nome[40];
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(nome, ppessoas);
    if(i >= 0) {
        (ppessoas+i)->nome[0] = '*';
    }
    gravarArquivo(ppessoas);
}

void gravarArquivo(struct dados *ppessoas) {
    FILE *p;
    int i;

    if((p = fopen("banco","w"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0; i<3; i++) {
            fwrite((ppessoas+i)->nome,sizeof((ppessoas+i)->nome),1,p);
            fwrite((ppessoas+i)->end,sizeof((ppessoas+i)->end),1,p);
            fwrite((ppessoas+i)->cidade,sizeof((ppessoas+i)->cidade),1,p);
            fwrite((ppessoas+i)->estado,sizeof((ppessoas+i)->estado),1,p);
            fwrite((ppessoas+i)->cep,sizeof((ppessoas+i)->cep),1,p);
        }
    }
    fclose(p);
}

void lerArquivo(struct dados *ppessoas) {
    FILE *p;
    dados cpessoas[3];
    int i;
    if((p = fopen("banco","r"))==NULL) {
        puts("Erro ao abrir o arquivo.");
        exit(0);
    } else {
        for(i=0;i<3;i++) {
            fread((ppessoas+i)->nome,sizeof((ppessoas+i)->nome),1,p);
            fread((ppessoas+i)->end,sizeof((ppessoas+i)->end),1,p);
            fread((ppessoas+i)->cidade,sizeof((ppessoas+i)->cidade),1,p);
            fread((ppessoas+i)->estado,sizeof((ppessoas+i)->estado),1,p);
            fread((ppessoas+i)->cep,sizeof((ppessoas+i)->cep),1,p);
        }
        for(i=0;i<3;i++) {
            printf("\nNome: %s\n",(ppessoas+i)->nome);
            printf("Endereco: %s\n",(ppessoas+i)->end);
            printf("Cidade: %s\n",(ppessoas+i)->cidade);
            printf("Estado: %s\n",(ppessoas+i)->estado);
            printf("Cep: %s\n\n",(ppessoas+i)->cep);
        }
    }
    fclose(p);
}

int checarNome(char *nome, struct dados *ppessoas) {
    int i,j,c = 0;
    for(i=0; i<3; i++) {
        if(strlen(nome)==strlen((ppessoas+i)->nome)) {
            for(j=0; j<strlen(nome); j++) {
                if(nome[j]==(ppessoas+i)->nome[j]) {
                    c++;
                }
            }
            if(c == strlen((ppessoas+i)->nome)) {
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
#endif // ex13

/*7 - Reescreva o programa do exercicio anterior retirando o vetor de estruturas
    deixando apenas uma estrutura simples. Escreva e leia os registros direto
    no arquivo utilizando usando apenas esta estrutura. (utilize a funcao fseek). */
#ifdef ex14
struct dados {
    char nome[40];
    char end[40];
    char cidade[40];
    char estado[3];
    char cep[9];
};

void recepcao(struct dados *ppessoas, int *contador);
void gravarArquivo(struct dados *ppessoas, int *contador);
void lerArquivo(struct dados *ppessoas, int *contador);
int checarNome(char *nome, struct dados *ppessoas, int *contador);
void exibicao(struct dados *ppessoas, int *contador);
void procurar(struct dados *ppessoas, int *contador);
void alterar(struct dados *ppessoas);
void excluir(struct dados *ppessoas, int *contador);
void contaRegistro(int *contador);
int tamTexto(char *texto);
int saoIguais(char *nome1, char *nome2);

main() {
    int contador = 0, op;
    struct dados pessoas;
    lerArquivo(&pessoas,&contador);
    do {
        printf("Escolha uma opcao:\n1 - Inserir dados\n2 - Exibir dados \n3 - Procurar\n*4 - Alterar\n*5 - Excluir\n8 - Sair.\n-->");
        scanf("%d",&op);
        getchar();
        switch(op) {
            case 1: system("cls");
                recepcao(&pessoas,&contador);
            break;
            case 2: system("cls");
                exibicao(&pessoas, &contador);
            break;
            case 3: system("cls");
                procurar(&pessoas, &contador);
            break;
            case 4: system("cls");
                alterar(&pessoas);
            break;
            case 5: system("cls");
                excluir(&pessoas,&contador);
            break;
            case 8: system("cls");
                lerArquivo(&pessoas,&contador);
                printf("Encerrando...\n");
            break;
        }
    } while(op != 8);
}

void recepcao(struct dados *ppessoas, int *contador) {
    puts("Digite seu nome: ");
    gets(ppessoas->nome);
    puts("Digite seu endereco: ");
    gets(ppessoas->end);
    puts("Digite sua cidade: ");
    gets(ppessoas->cidade);
    puts("Digite seu estado: ");
    gets(ppessoas->estado);
    puts("Digite seu cep: ");
    gets(ppessoas->cep);
    system("cls");
    gravarArquivo(ppessoas,contador);
}

void exibicao(struct dados *ppessoas, int *contador) {
    FILE *p;
    char ch;
    int i = 0;
    contaRegistro(contador);
    if ((p = fopen("banco","r")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        puts("Usuarios cadastrados: \n");
        while(i < *contador) {
            fread(ppessoas, sizeof(*ppessoas),1,p);
            if(ppessoas->nome[0] != '*') {
                printf("Nome: %s\n",ppessoas->nome);
                printf("Endereco: %s\n",ppessoas->end);
                printf("Cidade: %s\n",ppessoas->cidade);
                printf("Estado: %s\n",ppessoas->estado);
                printf("CEP: %s\n",ppessoas->cep);
                puts("\n");
            }
            fseek(p,0,1);
            i++;
        }
    }
    system("pause");
    system("cls");
}

void procurar(struct dados *ppessoas, int *contador) {
    char nome[40];
    int i;
    puts("Digite o nome: ");
    gets(nome);
    i = checarNome(&nome[0],ppessoas,contador);
    if(i > 0) {
        printf("Nome: %s",ppessoas->nome);
        printf("\nEndereco: %s",ppessoas->end);
        printf("\nCidade: %s",ppessoas->cidade);
        printf("\nEstado: %s",ppessoas->estado);
        printf("\nCep: %s\n\n",ppessoas->cep);
        system("pause");
        system("cls");
    }
}

void alterar(struct dados *ppessoas) {

}

void excluir(struct dados *ppessoas, int *contador) {
    FILE *p;
    int i = 0;
    char nome[40], ch = '*';
    //Pega o nome a ser deletado
    puts("Digite o nome: ");
    gets(nome);
    //Checa se o nome existe e grava na estrutura o nome
    int cont = checarNome(&nome[0],ppessoas,contador);
    if((p = fopen("banco","r")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        while(i < *contador) {
            i++;
            fread(ppessoas,sizeof(*ppessoas),1,p);
            printf("\n%s\n",ppessoas->nome);
            printf("\nFtell: %d\n",ftell(p));
        }
    }
    fclose(p);

    if((p = fopen("banco","r+")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        i = 0;
        while(i < *contador) {
            i++;
            system("pause");
            printf("\nFtell: %d\n",ftell(p));
            fread(ppessoas,sizeof(*ppessoas),1,p);
            printf("\nFtell: %d\n",ftell(p));
            fwrite(&ch,sizeof(*ppessoas->nome),1,p);
            printf("\nFtell: %d\n",ftell(p));
        }
    }
}

void gravarArquivo(struct dados *ppessoas, int *contador) {
    FILE *p;
    FILE *q;
    printf("\n%d\n",*contador);
    //Grava no arquivo
    if((p = fopen("banco","a")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        fwrite(ppessoas,sizeof(*ppessoas),1,p);
    }
    fclose(p);

    //Incrementa o numero de registros
    if((q = fopen("contador","w")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        if(*contador == 0) {
            *contador = 1;
            fprintf(q,"%d",*contador);
        } else {
            fscanf(q,"%d",contador);
            printf("\n%d\n",*contador);
            *contador = *contador + 1;
            fprintf(q,"%d",*contador);
            }
        }
    fclose(q);
    puts("Usuario cadastrado com sucesso!");
    system("pause");
    system("cls");
}

void lerArquivo(struct dados *ppessoas, int *contador) {
    FILE *p;
    char ch;
    int i = 0;
    contaRegistro(contador);
    if ((p = fopen("banco","r")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        while(i < *contador) {
            fread(ppessoas, sizeof(*ppessoas),1,p);
            fseek(p,0,1);
            i++;
        }
    }
}

int checarNome(char *nome, struct dados *ppessoas, int *contador) {
    FILE *p;
    int i = 1,j,c = 0;

    if((p = fopen("banco","r")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        while(i <= *contador) {
            fread(ppessoas, sizeof(*ppessoas),1,p);
            if(tamTexto(nome)==tamTexto(ppessoas->nome)) {
                for(j=0; j<tamTexto(nome); j++) {
                    if(nome[j]==ppessoas->nome[j]) {
                        c++;
                    }
                }
                if(c == tamTexto(ppessoas->nome)) {
                    //system("cls");
                    puts("Nome encontrado!\n");
                    fclose(p);
                    return i;
                } else {
                    c = 0;
                }
            }
            i++;
            fseek(p,0,1);
        }
        return -1;
        system("cls");
        puts("Nome nao encontrado!\n");
        system("pause");
        system("cls");
        fclose(p);

    }
}

void contaRegistro(int *contador) {
    //Pega o numero atual de registros
    FILE *q;
    if((q = fopen("contador","r")) == NULL) {
        puts("Falha ao abrir o arquivo");
        exit(0);
    } else {
        fscanf(q,"%d",contador);
    }
    fclose(q);
}

int tamTexto(char *texto) {
    int i=0;
    char ch;
    do {
        ch = texto[i];
        i++;
    } while(ch != '\0');
    return i-1;
}

int saoIguais(char *nome1, char *nome2) {
    int c = 0, i;
    if(tamTexto(nome1)==tamTexto(nome2)) {
        for(i = 0; i < tamTexto(nome2); i++) {
            if(nome1[i]==nome2[i]) {
                c++;
            }
        }
        if(c == tamTexto(nome2)) {
            return 1;
        }
    }
    return -1;
}
#endif // ex14
