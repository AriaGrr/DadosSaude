#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/cJSON.h"

// Para adicionar um campo ao JSON, basta adicionar uma linha no formato ADD_FIELD(obj, name, type, value)
// #define ADD_FIELD(obj, name, type, value) \
//     cJSON_Add##type##ToObject(obj, name, value)

// #define GET_FIELD(obj, name, type) \
//     cJSON_GetObjectItem(obj, name)->value##type

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
} EABB;

typedef struct
{
     EABB *raiz;
     int qtde;
} ABB;

// A partir daqui são estruturas com fonte: vozes da minha cabeça

// Pilha para armazenar operações (enfileirar e desenfileirar), para desfazer
typedef enum
{
     ENFILEIRAR,
     DESENFILEIRAR
} Operacao;

typedef struct Celula
{
    Operacao operacao;
    struct Celula *proximo;
//     struct Celula *anterior;
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

void cadastrarPaciente(Lista *lista);
void consultarPaciente(Lista *lista);

// void imprimirRegistro(Registro *r);

// cJSON* estruturaJson(void* data, const char* campo[], const char* tipo[]);
// void jsonEstrutura(const char* arquivo, void* estrutura, const char* campo[], const char* tipo[]);

#endif //FUNCOES_H