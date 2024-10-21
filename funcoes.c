
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


// Função para criar um objeto cJSON a partir de uma estrutura de dados genérica
cJSON* estruturaJson(void* data, const char* campo[], const char* tipo[]) {
  // Função auxiliar para adicionar um campo ao objeto JSON
    cJSON* obj = cJSON_CreateObject();

    // Macro para adicionar um campo ao objeto JSON
    for (int i = 0; campo[i] != NULL; i++) {
      // Adiciona o campo ao objeto JSON
        if (strcmp(tipo[i], "int") == 0) {
            // Adiciona um campo do tipo inteiro
            ADD_FIELD(obj, campo[i], Number, *((int*)data + i));
        } else if (strcmp(tipo[i], "char*") == 0) {
          // Adiciona um campo do tipo string
            ADD_FIELD(obj, campo[i], String, *((char**)data + i));
        // Adiciona um campo do tipo Data
        } else if (strcmp(tipo[i], "Data") == 0) {
            // Pega o ponteiro para a estrutura Data
            Data* data_ptr = (Data*)((char*)data + i * sizeof(char*));
            // Cria um objeto JSON para a estrutura Data
            cJSON* data_obj = cJSON_CreateObject();
            // Adiciona os campos da estrutura Data ao objeto JSON
            ADD_FIELD(data_obj, "dia", Number, data_ptr->dia);
            ADD_FIELD(data_obj, "mes", Number, data_ptr->mes);
            ADD_FIELD(data_obj, "ano", Number, data_ptr->ano);
            // Adiciona o objeto JSON da estrutura Data ao objeto JSON principal
            cJSON_AddItemToObject(obj, campo[i], data_obj);
        } else {
            // Tratar outros tipos de dados aqui
            printf("Tipo de dado não suportado: %s\n", tipo[i]);
        }
    }
    // Retorna o objeto JSON criado
    return obj;
}

// Função para ler um arquivo JSON e popular uma estrutura
void jsonEstrutura(const char* arquivo, void* estrutura, const char* campo[], const char* tipo[]) {
    FILE* fp = fopen(arquivo, "r");
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fseek(fp, 0, SEEK_END);
    long fsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* jsonString = (char*)malloc(fsize + 1);
    fread(jsonString, 1, fsize, fp);
    fclose(fp);
    jsonString[fsize] = 0;

    cJSON* root = cJSON_Parse(jsonString);
    if (!root) {
        printf("Erro ao analisar o JSON\n");
        free(jsonString);
        return;
    }

    // Assumindo que o JSON raiz contém um único objeto representando a estrutura
    estruturaJson(estrutura, campo, tipo);

    cJSON_Delete(root);
    free(jsonString);
}
