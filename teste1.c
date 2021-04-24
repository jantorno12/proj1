#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nam{
	
	char nome[50];
	struct nam *prox;
	
}name;

typedef struct dis{
	int codigo;
	char nome[50] ;
	char professor[50];
	int creditos;
	struct dis *prox;
	name pessoas;
	
}disciplina;

typedef struct al{
	int codigo;
	int cpf;
	char nome[50];
	struct al *prox;
	disciplina materia;
	
}aluno;

typedef struct per{
	float periodo;
	aluno estudante;
	struct per *prox;
}period;

disciplina *materia=NULL;
aluno *estudante=NULL;
period *periodo=NULL;

aluno *buscal(char chave[50], aluno *point, aluno **point2)
{
	aluno *aux;
	aux=point;
	while( aux!=NULL && strcmp(aux->nome,chave)!=0)
	{
		*point2=aux;
		aux=aux->prox;
	}
	return aux;
}

void insereal(aluno **point)
{
	aluno *aux;
	aluno *aux2;
	aux=(aluno*)malloc(sizeof(aluno));
	char name[50];
	int cpf;
	int codigo;
	printf("Escreva o nome do aluno:");
	scanf("%s", name);
	if(buscal(name, *point, &aux2 )!=NULL)
	{
		printf("Esse aluno ja esta registrado\n");
	}
	else
	{
		aux->nome[50]=name[50];
		printf("Escreva o codigo do aluno:");
		scanf("%d", &codigo);
		aux->codigo=codigo;
		printf("Escreva o cpf do aluno:");
		scanf("%d", &cpf);
		aux->cpf=cpf;
		aux->prox=*point;
		*point=aux;
	}
}
void printal(aluno *point)
{
	aluno *aux;
	while(aux!=NULL)
	{
		printf("%s\n", aux->nome);
		aux=aux->prox;
		
	}
}

int main(){
	
	insereal(&estudante);
	insereal(&estudante);
	printal(estudante);
	
	
	return 0;
}
