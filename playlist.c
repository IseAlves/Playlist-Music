#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define Nome_Artista 20
#define Nome_Banda 20
#define Nome_Musica 20
typedef struct 
{
char NomeA[Nome_Artista];
char NomeB[Nome_Banda];
char NomeM[Nome_Musica];
unsigned char min, seg;
}Titulo_Musica;
typedef struct Lista
{
Titulo_Musica musica;
struct Lista *prox;
}Lista_Musicas;
void menu();
void cadastrar_musica();
void listar_musica();
int main(void) 
{
Lista_Musicas *Play = NULL,*Fim = NULL;
Play = malloc(sizeof(Lista_Musicas)); 
menu(); 
printf("\n\n Digite o nome da banda: "); 
fgets(Play->musica.NomeB,Nome_Banda,stdin);
printf("\n Digite o nome do cantor: ");
fgets(Play->musica.NomeA,Nome_Artista,stdin);
printf("\n Digite o nome da musica: ");
fgets(Play->musica.NomeM,Nome_Musica,stdin);
printf("\n Digite quantos minutos tem a musica: ");
scanf("%hhu%*c",&Play->musica.min);
printf("\n Digite quantos segundos tem a musica: ");
scanf("%hhu%*c",&Play->musica.seg);
Fim = Play; 
Fim->prox = malloc(sizeof(Lista_Musicas)); 
Fim = Fim->prox;
printf("\n\n Digite o nome da banda: ");
fgets(Fim->musica.NomeB,Nome_Banda,stdin);
printf("\n Digite o nome do cantor: ");
fgets(Fim->musica.NomeA,Nome_Artista,stdin);
printf("\n Digite o nome da musica: ");
fgets(Fim->musica.NomeM,Nome_Musica,stdin);
printf("\n Digite quantos minutos tem a musica: ");
scanf("%hhu%*c",&Fim->musica.min);
printf("\n Digite quantos segundos tem a musica: ");
scanf("%hhu%*c",&Fim->musica.seg);
Fim->prox = NULL;
Fim = Play;
while(Fim != NULL) 
{
Lista_Musicas *temp;
temp = Fim->prox;
printf("\n Banda: %s",Fim->musica.NomeB);
printf("\n Cantor %s",Fim->musica.NomeA);
printf("\n Musica %s",Fim->musica.NomeM);
printf("\n Tempo da musica: %hhu:%hhu \n\n",Fim->musica.min,Fim->musica.seg);
free(Fim); 
Fim = temp; 
}
getchar();
return(0);
}
void menu()
{
int op;
printf("\n 1 - Cadastrar Musicas");
printf("\n 2 - Listar Musicas");
printf("\n 0 - Finalizar Programa \n\n");
scanf("%d",&op);
switch (op)
{
case 0: 
printf("\n Programa Finalizado! \n\n");
system("pause");
exit(1);
break;
case 1:
cadastrar_musica();
break;
case 2:
listar_musica();
break;
if((op<0)||(op>2))
{
printf("\n Opcao invalida! \n\n");
menu();
}
else
{
menu();
}
}
}
