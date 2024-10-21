
#include "funcoes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar o buffer do teclado
void clearBuffer()
{
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

// TESTAR

// // Função para criar um objeto cJSON a partir de uma estrutura de dados genérica
// cJSON* estruturaJson(void* data, const char* campo[], const char* tipo[]) {
//   // Função auxiliar para adicionar um campo ao objeto JSON
//     cJSON* obj = cJSON_CreateObject();

//     // Macro para adicionar um campo ao objeto JSON
//     for (int i = 0; campo[i] != NULL; i++) {
//       // Adiciona o campo ao objeto JSON
//         if (strcmp(tipo[i], "int") == 0) {
//             // Adiciona um campo do tipo inteiro
//             ADD_FIELD(obj, campo[i], Number, *((int*)data + i));
//         } else if (strcmp(tipo[i], "char*") == 0) {
//           // Adiciona um campo do tipo string
//             ADD_FIELD(obj, campo[i], String, *((char**)data + i));
//         // Adiciona um campo do tipo Data
//         } else if (strcmp(tipo[i], "Data") == 0) {
//             // Pega o ponteiro para a estrutura Data
//             Data* data_ptr = (Data*)((char*)data + i * sizeof(char*));
//             // Cria um objeto JSON para a estrutura Data
//             cJSON* data_obj = cJSON_CreateObject();
//             // Adiciona os campos da estrutura Data ao objeto JSON
//             ADD_FIELD(data_obj, "dia", Number, data_ptr->dia);
//             ADD_FIELD(data_obj, "mes", Number, data_ptr->mes);
//             ADD_FIELD(data_obj, "ano", Number, data_ptr->ano);
//             // Adiciona o objeto JSON da estrutura Data ao objeto JSON principal
//             cJSON_AddItemToObject(obj, campo[i], data_obj);
//         } else {
//             // Tratar outros tipos de dados aqui
//             printf("Tipo de dado não suportado: %s\n", tipo[i]);
//         }
//     }
//     // Retorna o objeto JSON criado
//     return obj;
// }

// // Função para ler um arquivo JSON e popular uma estrutura
// void jsonEstrutura(const char* arquivo, void* estrutura, const char* campo[], const char* tipo[]) {
//     FILE* fp = fopen(arquivo, "r");
//     if (!fp) {
//         perror("Erro ao abrir o arquivo");
//         return;
//     }

//     fseek(fp, 0, SEEK_END);
//     long fsize = ftell(fp);
//     fseek(fp, 0, SEEK_SET);

//     char* jsonString = (char*)malloc(fsize + 1);
//     fread(jsonString, 1, fsize, fp);
//     fclose(fp);
//     jsonString[fsize] = 0;

//     cJSON* root = cJSON_Parse(jsonString);
//     if (!root) {
//         printf("Erro ao analisar o JSON\n");
//         free(jsonString);
//         return;
//     }

//     // Assumindo que o JSON raiz contém um único objeto representando a estrutura
//     estruturaJson(estrutura, campo, tipo);

//     cJSON_Delete(root);
//     free(jsonString);
// }

// Funções de print dos menus

void printMenu()
{
  printf("Menu\n");
  printf("1 - Cadastrar\n");
  printf("2 - Atendimento\n");
  printf("3 - Pesquisa\n");
  printf("4 - Desfazer\n");
  // Pode retirar essas opções para serem automáticas?
  // Carrega ao iniciar o programa e salva ao sair
  printf("5 - Carregar\n");
  printf("6 - Salvar\n");
  //
  printf("7 - Sobre\n");
  printf("0 - Sair\n");
  printf("Digite a opcao desejada: ");
}

// Cadastrar novo paciente em uma lista dinâmica encadeada, mantendo a ordem de registro (inserção no início);
void menuCadastro()
{
  printf("Operacoes:\n");
  printf("1 - Cadastrar novo paciente\n");
  printf("2 - Consultar paciente cadastrado\n");
  printf("3 - Mostrar lista de pacientes\n");
  printf("4 - Atualizar dados de paciente\n");
  printf("5 - Remover paciente\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
}

// Inserir um paciente, que já possua cadastro, em uma fila para atendimento;
void menuAtendimento()
{
  printf("Operacoes:\n");
  // Enfileirar paciente
  printf("1 - Adicionar paciente a fila de espera\n");
  // Desenfileirar paciente
  printf("2 - Atender paciente\n");
  // Mostrar fila
  printf("3 - Mostrar fila de espera\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
}

// Inserir um paciente, que já possua cadastro, em uma árvore binária de busca;
void menuPesquisa()
{
  printf("Operacoes:\n");
  // Mostrar registros ordenados por ano de registro;
  printf("1 - Registros ordenados por ano\n");
  // Mostrar registros ordenados por mês de registro;
  printf("2 - Registros ordenados por mês\n");
  // Mostrar registros ordenados por dia de registro;
  printf("3 - Registros ordenados por dia\n");
  // Mostrar registros ordenados por idade do paciente.
  printf("4 - Registros ordenados por idade\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
}

void sobre()
{
  printf("Sistema de atendimento hospitalar\n");
  printf("Desenvolvido por:\n");
  printf("Marjorie Luize Martins Costa\n");
  printf("& \n");
  printf("Nuno \n");
  printf("Ciclo: Quarto\n");
  printf("Curso: Ciencia da Computacao\n");
  printf("Disciplina: Estrutura de Dados\n");
  printf("Data: 20/10/2024\n");
}
