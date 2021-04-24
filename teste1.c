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
	char *professor;
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

aluno *buscal(char *chave, aluno *point, aluno **point2)
{
	aluno *aux;
	aux=point;
	while(aux!=NULL && strcmp(aux->nome,chave)!=0)
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
	fflush(stdin);
	printf("Escreva o nome do aluno:");
	scanf("%[^\n]s", ajuda->nome);
	fflush(stdin);
	if(buscal(ajuda->nome, *point, &aux2 )!= NULL)
	{
		
		printf("Esse aluno ja esta registrado\n");
	}
	else
	{
		printf("Escreva o codigo do aluno:");
		scanf("%d", &codigo);
		ajuda->codigo=codigo;
		printf("Escreva o cpf do aluno:");
		scanf("%d", &cpf);
		ajuda->cpf=cpf;
		ajuda->prox=*point;
		*point=ajuda;
	}
}

void removeal(aluno **point)
{
	aluno *aux;
	aluno *pai;
	char resp[50];
	fflush(stdin);
	printf("Escreva o nome do aluno que se deseja remover:");
	scanf("%[^\n]s", resp);
	aux = buscal(resp, *point, &pai);
	if(aux==NULL)
	{
		printf("Esse aluno nao esta registrado\n");
	}
	else
	{
		if(aux==*point)
		{
			*point=aux->prox; //ponteiro aponta pro proximo
		}
		else
		{
			pai->prox=aux->prox;
		}
	}
}
void printal(aluno *point)
{
	aluno *aux;
	aux=point;
	while(aux!=NULL)
	{
		printf("%s\n",  aux->nome);
		aux=aux->prox;
	}
}
 void insere_discplina(aluno *pont){
    char alun[50];
    aluno *ponteiro;
    aluno *aux;
    printf("Nome do aluno para adicionar matérias:\n");
    scanf("%s", alun);
    aux = buscal(alun, pont, &ponteiro);
    if(aux == NULL){
        printf("Aluno não encontrado.\n");
    }
    else{
        printf("Entre com a disciplina:\n");
        scanf("%s", aux->materia.nome);
        strcpy(aux->materia.pessoas.nome, aux->nome);
    }
 }

 void print_dis(aluno *pont){
    aluno *aux;
    aux = pont;
    //while(aux!=NULL){
        //printf("%s", aux->materia.nome);
        //aux = aux->prox;
    //}
 }


int main(){
	
	insereal(&estudante);
    insere_discplina(estudante);
    print_dis(estudante);
	//printal(estudante);
	//insereal(&estudante);
	//insereal(&estudante);
	//printal(estudante);
	//removeal(&estudante);
	//insereal(&estudante);
	//printal(estudante);
	
	return 0;
}