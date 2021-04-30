#include <stdlib.h>
#include <stdio.h>
#include <string.h>

FILE *p;


typedef struct nameal{
	
	char nome[50];
	float periodo;
	struct nameal *prox;
	
}nomeal;

typedef struct namedis{
	
	char nome[50];
	float periodo;
	struct namedis *prox;
	
}nomedis;

typedef struct dis{
	int codigo;
	char nome[50] ;
	char professor[50];
	int creditos;
	struct dis *prox;
	nomeal *pessoa;
	
}disciplina;

typedef struct al{
	int codigo;
	int cpf;
	char nome[50];
	struct al *prox;
	nomedis *materia;
	
}aluno;

typedef struct per{
	float periodo;
	aluno *estudante;
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

disciplina *buscadis(char *chave, disciplina *point, disciplina **point2)
{
	disciplina *aux;
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
		ajuda->materia=NULL;//faço o ponteiro de disciplinas apontar pra NULL, pra quando inserir uma disciplina pra esse aluno, o ponteiro de proximo ficar apontando pro null, e encadear a lista
		ajuda->prox=*point;
		*point=ajuda;
	}
}

void inseredis(disciplina **point)
{
	disciplina *ajuda;
	disciplina *aux2;
	ajuda=(disciplina*)malloc(sizeof(disciplina));
	char resp[50];
	int creditos;
	int codigo;
	fflush(stdin);
	printf("Escreva o nome da disciplina:");
	scanf("%[^\n]s", ajuda->nome);
	fflush(stdin);
	if(buscadis(ajuda->nome, *point, &aux2 )!= NULL)
	{
		
		printf("Essa disciplina ja esta registrada\n");
	}
	else
	{
		printf("Escreva o nome do professor:");
		scanf("%[^\n]s", ajuda->professor);
		printf("Escreva o codigo da disciplina:");
		scanf("%d", &codigo);
		ajuda->codigo=codigo;
		printf("Escreva a quantidade de creditos da disciplina:");
		scanf("%d", &creditos);
		ajuda->creditos=creditos;
		ajuda->pessoa=NULL;//faço o ponteiro de alunos apontar pra NULL, pra quando inserir uma disciplina pra esse aluno, o ponteiro de proximo ficar apontando pro null, e encadear a lista
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

void removedis(disciplina **point)
{
	disciplina *aux;
	disciplina *pai;
	char resp[50];
	fflush(stdin);
	printf("Escreva o nome da disciplina que se deseja remover:");
	scanf("%[^\n]s", resp);
	aux = buscadis(resp, *point, &pai);
	if(aux==NULL)
	{
		printf("Essa disciplina nao esta registrado\n");
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
void disciplina_aluno(aluno *pont, disciplina *pont2)
{
    char alun[50];
    char materia[50];
    float per;
    aluno *ponteiro;
    aluno *aux;
    nomedis *novadis;
    nomeal *novoal;
    disciplina *ponteiro2;
    disciplina *aux2;
    int cont;
    printf("Nome do aluno para adicionar materias:");
    scanf("%s", alun);
    aux = buscal(alun, pont, &ponteiro);
    if(aux == NULL){
        printf("Aluno nao encontrado.\n");
    }
    else
	{
		fflush(stdin);
        printf("Entre com a disciplina: ");
        scanf("%[^\n]s", materia);
        aux2 = buscadis(materia,pont2,&ponteiro2);
        if(aux2==NULL)
        {
        	printf("Materia nao encontrada, por favor registre a materia\n");
		}
        else
        {
        	printf("Periodo: ");
    		scanf("%f", &per);
        	novadis = (nomedis*)malloc(sizeof(nomedis));
        	strcpy(novadis->nome, materia);
        	novadis->periodo=per;
        	novadis->prox=aux->materia;
        	aux->materia=novadis;
        	novoal = (nomeal*)malloc(sizeof(nomeal));
        	strcpy(novoal->nome, aux->nome);
        	novoal->periodo=per;
        	novoal->prox=aux2->pessoa;
        	aux2->pessoa=novoal;
		}
    }
}

void print_dis_al(aluno *pont){
    aluno *aux;
    aluno *ponteiro;
    nomedis *ajuda;
    char aluno[50];
    float per;
    fflush(stdin);
    printf("Digite o nome do aluno que se quer ver as disciplinas: ");
    scanf("%[^\n]s", aluno);
    aux = buscal(aluno,pont, &ponteiro);
     if(aux==NULL)
    {
        printf("Aluno nao encontrada, por favor registre o aluno\n");
	}
    else
    {
    	printf("Periodo: ");
    	scanf("%f", &per);
    	printf("As disciplinas sao:\n");
    	ajuda=aux->materia;
    	while(ajuda!=NULL)
		{
			if(ajuda->periodo==per)
			{
				printf("%s\n", ajuda->nome);
			}
			ajuda = ajuda->prox;
    	    
    	}
    }
}

void print_al_dis(disciplina *pont){
    disciplina *aux;
    disciplina *ponteiro;
    nomeal *ajuda;
    char materia[50];
    float per;
    fflush(stdin);
    printf("Digite o nome da disciplina que se quer ver os alunos: ");
    scanf("%[^\n]s", materia);
    aux = buscadis(materia,pont, &ponteiro);
    if(aux==NULL)
    {
        printf("Materia nao encontrada, por favor registre a materia\n");
	}
    else
    {
    	printf("Periodo: ");
    	scanf("%f", &per);
    	printf("Os alunos sao:\n");
    	ajuda=aux->pessoa;
    	while(ajuda!=NULL)
		{
			if(ajuda->periodo==per)
			{
				printf("%s\n", ajuda->nome);
			}
			ajuda = ajuda->prox;  
    	}
   	}
}

void escreve_dis(disciplina *pont)
{
	disciplina *aux;
	aux=pont;
	while(aux!=NULL)
	{
		fprintf(p, "%s", aux->nome);
		fprintf(p, "%s", "/");
		fprintf(p, "%d", aux->codigo);
		fprintf(p, "%s", "/");
		fprintf(p, "%s", aux->professor);
		fprintf(p, "%s", "/");
		fprintf(p, "%d", aux->creditos);
		fprintf(p, "%s", "\n");
		aux=aux->prox;
	}
	fprintf(p, "%s", "*\n");
}

void escreve_al(aluno *pont)
{
	aluno *aux;
	nomedis *aux2;
	aux=pont;
	while(aux!=NULL)
	{
		fprintf(p, "%s", aux->nome);
		fprintf(p, "%s", "/");
		fprintf(p, "%d", aux->codigo);
		fprintf(p, "%s", "/");
		fprintf(p, "%d", aux->cpf);
		fprintf(p, "%s", "\n");
		aux2=aux->materia;
		while(aux2!=NULL)
		{
			fprintf(p, "%s", aux2->nome);
			fprintf(p, "%s", "/");
			fprintf(p, "%.1f", aux2->periodo);
			fprintf(p, "%s", "\n");
			aux2=aux2->prox;
		}
		aux=aux->prox;
		fprintf(p, "%s", "^\n");
	}
	fprintf(p, "%s", "*\n");
}


void le_disciplina(disciplina **materia)
{
	char ch;
	char dis[50];
	char prof[50];
	int creditos;
	int codigo;
	int i;
	int k=0;
	int j=1;
	int pausa=0;
	disciplina *aux;
	i=0;
	do
    {
    	ch=fgetc(p);
    	while(ch!='\n')
    	{
    		
			if(ch=='*')
    		{
    			pausa=1;
				break;
			}
    		if(ch!='/' && j==1)
    		{
    			dis[i]=ch;
    			i=i+1;
			}
			if(ch=='/' && j==1)
    		{
    			dis[i]='\0';
    			fscanf(p, "%d", &codigo);
    			j=j+1;
    			i=0;
    			ch=fgetc(p);
    			ch=fgetc(p);
			}
			if(ch!='/' && j==2)
    		{
    			prof[i]=ch;
    			i=i+1;
    			//printf("poi");
			}
			if(ch=='/' && j==2)
    		{
    			prof[i]='\0';
    			fscanf(p, "%d", &creditos);
    			j=j+1;
			}
			if(j==3)
			{
				aux=(disciplina*)malloc(sizeof(disciplina));
				aux->codigo=codigo;
				aux->creditos=creditos;
				strcpy(aux->professor, prof);
				strcpy(aux->nome, dis);
				aux->prox = *materia;
				*materia= aux;
			}
			ch=fgetc(p);
		}
		j=1;
		i=0;
	}
	while(ch!=EOF&&pausa==0);
}


int main(){
	
	p=fopen("cadastro.txt", "r");
	le_disciplina(&materia);
	fclose(p);
	p=fopen("cadastro.txt", "w");
	int cont;
	printf("Aqui voce encontra um sistema de matriculas\n");
	printf("Insira 0 se voce deseja sair\n");
	printf("Insira 1 se voce deseja adicionar um aluno\n");
	printf("Insira 2 se voce deseja remover um aluno\n");
	printf("Insira 3 se voce deseja adicionar uma disciplina\n");
	printf("Insira 4 se voce deseja remover uma disciplina\n");
	printf("Insira 5 se voce deseja inserir uma disciplina a um aluno\n");
	printf("Insira 6 se voce deseja ver todos os alunos de uma disciplina\n");
	printf("Insira 7 se voce deseja ver todos as disciplinas de um aluno\n");
	do
	{
		printf("\nInsira qual opcao do menu deseja executar: ");
		scanf("%d", &cont);
		if(cont==1)
		{
			insereal(&estudante);
		}
		if(cont==2)
		{
			removeal(&estudante);
		}
		if(cont==3)
		{
			inseredis(&materia);
		}
		if(cont==4)
		{
			removedis(&materia);
		}
		if(cont==5)
		{
			disciplina_aluno(estudante,materia);
		}
		if(cont==6)
		{
			print_al_dis(materia);
		}
		if(cont==7)
		{
			print_dis_al(estudante);
		}
	}
	while(cont!=0);
	escreve_dis(materia);
	escreve_al(estudante);

	
	return 0;
}
