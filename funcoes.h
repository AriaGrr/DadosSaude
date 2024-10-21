// Pra que isso serve mesmo?
#ifndef UNTITLED2_BIBLI_H
#define UNTITLED2_BIBLI_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"

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

// Aqui devemos colocar as funções que serão utilizadas do arquivo funcoes.c

void clearBuffer();

// void imprimirRegistro(Registro *r);

cJSON* estruturaJson(void* data, const char* campo[], const char* tipo[]);
void jsonEstrutura(const char* arquivo, void* estrutura, const char* campo[], const char* tipo[]);


#endif //UNTITLED2_BIBLI_H