// Pra que isso serve mesmo?
#ifndef UNTITLED2_BIBLI_H
#define UNTITLED2_BIBLI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "cjson\cJSON.h"
#include "cJSON.h"

// #include <cjson/cJSON.h>
// #include "lib\cJSON\cJSON.c"
// #include "cJSON.h"
// #include "cJSON.c"

// #include "funcoes.c"

// Para
#define ADD_FIELD(obj, name, type, value) \
    cJSON_Add##type##ToObject(obj, #name, value)

// Aqui devemos colocar os structs, tanto do arquivo a ser salvo quanto das estruturas que serão manipuladas

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
    int idade;
    char rg[10];
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
     struct EABB *esq;
     struct EABB *dir;
} EABB;

typedef struct
{
     EABB *raiz;
     int qtde;
} ABB;


// typedef struct
// {
//     int prioridade;
//     int estado;
//     int categoria;
//     char descricao[300];
// } Tarefa;

// typedef struct
// {
//     Tarefa tarefas[100];
//     int qtd;
// } ListaDeTarefas;

// Aqui devemos colocar as funções que serão utilizadas do arquivo funcoes.c

void clearBuffer();

// void imprimirRegistro(Registro *r);

cJSON* estruturaJson(void* data, const char* campo[], const char* tipo[]);
void jsonEstrutura(const char* arquivo, void* estrutura, const char* campo[], const char* tipo[]);


// char *estado(int e);
// char *categoria(int c);

// //Funções principais
// int criarTarefa(ListaDeTarefas *lt);
// int deletarTarefa(ListaDeTarefas *lt);
// int alterarTarefa(ListaDeTarefas *lt);

// // Funções para exportar
// int exportarTarefas(ListaDeTarefas lt, char exportado[]); // Adicional, não feito.
// int exportarPrioridade(ListaDeTarefas lt, char exportado[]);
// int exportarCategoria(ListaDeTarefas lt, char exportado[]);
// int exportarPCTarefa(ListaDeTarefas lt, char exportado[]);

// //Funções de listagem
// int listarTarefas(ListaDeTarefas lt);
// int listarPrioridade(ListaDeTarefas lt);
// int listarCategoria(ListaDeTarefas lt);
// int listarPCTarefa(ListaDeTarefas lt);
// int listarEstado(ListaDeTarefas lt);

// void menuExportar();
// void menuListagem();
// void printMenu();
// // fwrite
// int salvarLista(ListaDeTarefas lt, char nome[]);
// // fread
// int carregarLista(ListaDeTarefas *lt, char nome[]);
#endif //UNTITLED2_BIBLI_H