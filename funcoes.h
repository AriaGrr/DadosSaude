#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/cJSON.h"

// Aqui devemos colocar os structs, tanto do arquivo a ser salvo quanto das estruturas que serão manipuladas

#define maxNOME 50
#define maxRG 10

// Estruturas do slide

// Registros de pacientes
typedef struct
{
     int dia;
     int mes;
     int ano;
} Data;

typedef struct
{
     char nome[maxNOME];
     // char nome;
     int idade;
     char rg[maxRG];
     // char rg;
     Data *entrada;
} Registro;

// Item de menu: Cadastrar em uma LDE
typedef struct ELista
{
     Registro *dados;
     // Por qual motivo eu coloquei struct ELista *proximo e não ELista *proximo?
     struct ELista *proximo;
} ELista;

typedef struct
{
     ELista *inicio;
     int qtde;
} Lista;

// Item de menu: Atendimento em uma Fila
typedef struct EFila
{
     Registro *dados;
     struct EFila *proximo;
} EFila;

typedef struct
{
     EFila *head;
     EFila *tail;
     int qtde;
} Fila;

// Item de menu: Pesquisa
typedef struct EABB
{
     Registro *dados;
     // Filhos esquerdo e direito
     struct EABB *esq, *dir;
     // Não tem pai pois ele é usado para operações de exclusão, que não são necessárias nesse projeto.
} EABB;

typedef struct
{
     EABB *raiz;
     int qtde;
} ABB;

// A partir daqui são estruturas com fonte: vozes da minha cabeça

// Pilha dinamica usa anterior e próximo
typedef struct Celula
{
     // 1 para desinfileirar, 2 para enfileirar
     int operacao;
     // Deve também ser possível armazenar um registro
     Registro *dados;
     struct Celula *proximo;
     struct Celula *anterior;
} Celula;

// Pilha (Stack) para armazenar as operações de enfileirar e desenfileirar
typedef struct
{
     Celula *topo;
     int qtd;
} Pilha;

// Estrutura contêiner para armazenar as estruturas de dados do programa no JSON
// typedef struct
// {
//      Lista *lista;
//      Fila *fila;
//      //ABB *abb;
//      Pilha *pilha;
// } Dados;

// Aqui devemos colocar as funções que serão utilizadas do arquivo funcoes.c
// DEVO CHAMAR TODAS QUE NÃO ESTÃO NO MAIN?

// Limpa o buffer do teclado
void clearBuffer();

// Prints de menu
void printMenu();
void menuCadastro();
void menuAtendimento();
void menuPesquisa();
void sobre();

// Inicializadores
Lista *inicializaLista();
Fila *inicializaFila();
ABB *inicializaArvore();
Pilha *inicializaPilha();

// Funções do menu de cadastro

// Cadastrar paciente
void cadastrarPaciente(Lista *lista);
// Consultar paciente
void consultarPaciente(Lista *lista);
// Mostrar lista completa
void mostrarLista(Lista *lista);
// Atualizar dados de paciente
void atualizarPaciente(Lista *lista);
// Remover paciente
void removerPaciente(Lista *lista);

// Funções do menu de atendimento

// Enfileirar paciente
void enfileirarPaciente(Fila *fila, Lista *lista, Pilha *pilha);
// Desenfileirar paciente
void desenfileirarPaciente(Fila *fila, Pilha *pilha);
// Mostrar fila completa
void mostrarFila(Fila *fila);

// Funções do menu de desfazer

// Desfazer operação
void desfazer(Pilha *pilha, Fila *fila, Lista *lista);

// Funções do menu de pesquisa

// Funções de mostrar ordenado 

// Ano

// Mês

// Dia

// Idade


#endif //FUNCOES_H