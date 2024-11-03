#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/cJSON.h"

// Aqui devemos colocar os structs, tanto do arquivo a ser salvo quanto das estruturas que serão manipuladas

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
     char nome[50];
     // char nome;
     int idade;
     char rg[10];
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
     // 1 para enfileirar, 2 para desinfileirar
     int operacao;
     //     Operacao operacao;
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
typedef struct
{
     Lista *lista;
     Fila *fila;
     ABB *abb;
     Pilha *pilha;
} Dados;

// Aqui devemos colocar as funções que serão utilizadas do arquivo funcoes.c

void clearBuffer();

// Prints de menu

void printMenu();
void menuCadastro();
void menuAtendimento();
void menuPesquisa();
void sobre();

// Funções do menu de cadastro

// Inicializar lista
Lista *inicializa_lista();

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

#endif //FUNCOES_H