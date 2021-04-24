#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nam{
	
	char *nome;
	struct nam *prox;
	
}name;

typedef struct dis{
	int codigo;
	char *nome ;
	char *professor;
	int creditos;
	struct dis *prox;
	name pessoas;
	
}disciplina;

typedef struct al{
	int codigo;
	int cpf;
	char *nome;
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

aluno *buscal(char *chave, aluno *point, aluno **point2)
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
	aluno *ajuda;
	aluno *aux2;
	ajuda=(aluno*)malloc(sizeof(aluno));
	char resp[50];
	int cpf;
	int codigo;
	printf("Escreva o nome do aluno:");
	fflush(stdin);
	scanf("%[^\n]s", resp);
	fflush(stdin);
	//if(buscal(resp, *point, &aux2 )!= NULL)
	//{
		
	//	printf("Esse aluno ja esta registrado\n");
	//}
	//else
	//{
		ajuda->nome=resp;
		
		printf("Escreva o codigo do aluno:");
		scanf("%d", &codigo);
		ajuda->codigo=codigo;
		printf("Escreva o cpf do aluno:");
		scanf("%d", &cpf);
		ajuda->cpf=cpf;
		ajuda->prox=*point;
		*point=ajuda;
	//}
}
void printal(aluno *point)
{
	aluno *aux;
	aux=point;
	while(aux!=NULL)
	{
		printf("%s\n", aux->nome);
		aux=aux->prox;
	}
}

int main(){
	
	insereal(&estudante);
	printal(estudante);
	insereal(&estudante);
	insereal(&estudante);
	printal(estudante);
	
	
	return 0;
}
