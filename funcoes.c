
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

// Estruturas pra ficar mais facil de ver
// Registros de pacientes
// typedef struct
// {
//      int dia;
//      int mes;
//      int ano;
// } Data;

// typedef struct
// {
//      // char nome[50];
//      char nome;
//      int idade;
//      // char rg[10];
//      char rg;
//      Data *entrada;
// } Registro;

// // Item de menu: Cadastrar em uma LDE
// typedef struct ELista
// {
//      Registro *dados;
//      struct ELista *proximo;
// } ELista;

// typedef struct
// {
//      ELista *inicio;
//      int qtde;
// } Lista;

// // Item de menu: Atendimento em uma Fila
// typedef struct EFila
// {
//      Registro *dados;
//      struct EFila *proximo;
// } EFila;

// typedef struct
// {
//      EFila *head;
//      EFila *tail;
//      int qtde;
// } Fila;

// // Item de menu: Pesquisa
// typedef struct EABB
// {
//      Registro *dados;
//      // Filhos esquerdo e direito
//      struct EABB *esq;
//      struct EABB *dir;
// } EABB;

// typedef struct
// {
//      EABB *raiz;
//      int qtde;
// } ABB;

// Se der errado aqui mudo pra um 
// typedef enum
// {
//      ENFILEIRAR,
//      DESENFILEIRAR
// } Operacao;

// // Pilha dinamica usa anterior e próximo
// typedef struct Celula
// {
//     Operacao operacao;
//     struct Celula *proximo;
//     struct Celula *anterior;
// } Celula;

// ou 


// // Pilha dinamica usa anterior e próximo
// typedef struct Celula
// {
//      // 1 para enfileirar, 2 para desinfileirar
//      int operacao;
// //     Operacao operacao;
//     struct Celula *proximo;
//     struct Celula *anterior;
// } Celula;

// // Pilha (Stack) para armazenar as operações de enfileirar e desenfileirar
// typedef struct
// {
//     Celula *topo;
//     int qtd;
// } Pilha;

// typedef struct
// {
//      Lista *lista;
//      Fila *fila;
//      ABB *abb;
//      Pilha *pilha;
// } Dados;

// Funções para inicializar as estruturas de dados com base em arquivos JSON

// Função genérica para serializar uma estrutura
cJSON *estruturaToJson(void *data, const char *campos[], const char *tipos[])
{
  cJSON *obj = cJSON_CreateObject();
  int i = 0;
  while (campos[i] != NULL)
  {
    switch (tipos[i][0])
    {
    case 'i': // int
      cJSON_AddNumberToObject(obj, campos[i], *((int *)data + i));
      break;
    case 'c': // char*
      cJSON_AddStringToObject(obj, campos[i], *((char **)data + i));
      break;
    case 'D': // Data
    {
      Data *data_ptr = (Data *)((char *)data + i * sizeof(char *));
      cJSON *data_obj = cJSON_CreateObject();
      cJSON_AddNumberToObject(data_obj, "dia", data_ptr->dia);
      cJSON_AddNumberToObject(data_obj, "mes", data_ptr->mes);
      cJSON_AddNumberToObject(data_obj, "ano", data_ptr->ano);
      cJSON_AddItemToObject(obj, campos[i], data_obj);
    }
    break;
    case 'L': // ELista*
      cJSON_AddItemToObject(obj, campos[i], estruturaToJson(*((ELista **)data + i), campos, tipos));
      break;
    case 'F': // EFila*
      cJSON_AddItemToObject(obj, campos[i], estruturaToJson(*((EFila **)data + i), campos, tipos));
      break;
    case 'A': // EABB*
      cJSON_AddItemToObject(obj, campos[i], estruturaToJson(*((EABB **)data + i), campos, tipos));
      break;
    // case 'P': // Pilha*
    //   cJSON_AddItemToObject(obj, campos[i], estruturaToJson(*((Pilha **)data + i), campos, tipos));
    //   break;
    // ... outros tipos
    default:
      printf("Tipo de dado não suportado: %s\n", tipos[i]);
    }
    i++;
  }
  return obj;
}

// Função genérica para desserializar uma estrutura
void jsonParaEstrutura(const cJSON *obj, void *estrutura, const char *campos[], const char *tipos[])
{
  int i = 0;
  while (campos[i] != NULL)
  {
    cJSON *item = cJSON_GetObjectItem(obj, campos[i]);
    if (item)
    {
      switch (tipos[i][0])
      {
      case 'i': // int
        *((int *)estrutura + i) = item->valueint;
        break;
      case 'c': // char*
        *((char **)estrutura + i) = strdup(item->valuestring);
        break;
      case 'D': // Data
      {
        Data *data_ptr = (Data *)((char *)estrutura + i * sizeof(char *));
        cJSON *dia = cJSON_GetObjectItem(item, "dia");
        cJSON *mes = cJSON_GetObjectItem(item, "mes");
        cJSON *ano = cJSON_GetObjectItem(item, "ano");
        data_ptr->dia = dia->valueint;
        data_ptr->mes = mes->valueint;
        data_ptr->ano = ano->valueint;
      }
      break;
      case 'L': // ELista*
      {
        ELista **lista = (ELista **)((char *)estrutura + i * sizeof(char *));
        *lista = (ELista *)malloc(sizeof(ELista));
        jsonParaEstrutura(item, (*lista)->dados, campos, tipos);
        (*lista)->proximo = NULL;
      }
      break;
      case 'F': // EFila*
      {
        EFila **fila = (EFila **)((char *)estrutura + i * sizeof(char *));
        *fila = (EFila *)malloc(sizeof(EFila));
        jsonParaEstrutura(item, (*fila)->dados, campos, tipos);
        (*fila)->proximo = NULL;
      }
      break;
      case 'A': // EABB*
      {
        EABB **abb = (EABB **)((char *)estrutura + i * sizeof(char *));
        *abb = (EABB *)malloc(sizeof(EABB));
        jsonParaEstrutura(item, (*abb)->dados, campos, tipos);
        (*abb)->esq = NULL;
        (*abb)->dir = NULL;
      }
      break;
      case 'P': // Pilha*
      {
        // ARRUMAR A PILHA EM TUDO
        // typedef struct Celula
        // {
        //   Operacao operacao;
        //   struct Celula *proximo;
        //   struct Celula *anterior;
        // } Celula;

        // // Pilha (Stack) para armazenar as operações de enfileirar e desenfileirar
        // typedef struct
        // {
        //   Celula *topo;
        //   int qtd;
        // } Pilha;


        // Pilha **pilha = (Pilha **)((char *)estrutura + i * sizeof(char *));
        // *pilha = (Pilha *)malloc(sizeof(Pilha));
        // (*pilha)->topo = NULL;
        // (*pilha)->qtd = 0;
        // cJSON *celula = item;
        // while (celula)
        // {
        //   Celula *nova = (Celula *)malloc(sizeof(Celula));
        //   nova->operacao = celula->valueint;
        //   nova->proximo = (*pilha)->topo;
        //   (*pilha)->topo = nova;
        //   (*pilha)->qtd++;
        //   celula = celula->next;
        // }
      }
      break;
        // ... outros tipos
      }
    }
    else
    {
      printf("Campo '%s' não encontrado no JSON\n", campos[i]);
    }
    i++;
  }
}

// Função para serializar toda a estrutura de dados
cJSON *serializarTudo(Dados *dados)
{
  cJSON *root = cJSON_CreateObject();

  // Definir os campos e tipos de cada estrutura
  const char *camposLista[] = {"inicio", "qtde", NULL};
  const char *tiposLista[] = {"ELista*", "int", NULL};
  const char *camposFila[] = {"head", "tail", "qtde", NULL};
  const char *tiposFila[] = {"EFila*", "EFila*", "int", NULL};
  const char *camposABB[] = {"raiz", "qtde", NULL};
  const char *tiposABB[] = {"EABB*", "int", NULL};
  // const char *camposPilha[] = {"operacao", "proximo", NULL};
  // const char *tiposPilha[] = {"Operacao", "Pilha*", NULL};

  // ... e assim por diante para as outras possiveis estruturas

  cJSON_AddItemToObject(root, "lista", estruturaToJson(dados->lista, camposLista, tiposLista));
  cJSON_AddItemToObject(root, "fila", estruturaToJson(dados->fila, camposFila, tiposFila));
  cJSON_AddItemToObject(root, "abb", estruturaToJson(dados->abb, camposABB, tiposABB));
  // cJSON_AddItemToObject(root, "pilha", estruturaToJson(dados->pilha, camposPilha, tiposPilha));
  // ...

  return root;
}

// Função para desserializar toda a estrutura de dados
void desserializarTudo(const char *arquivo, Dados *dados)
{
  // ... (lógica similar à função serializarTudo, mas no sentido inverso)
  FILE *fp = fopen(arquivo, "r");
  if (!fp)
  {
    perror("Erro ao abrir o arquivo");
    return;
  }

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  char *jsonString = (char *)malloc(fsize + 1);
  fread(jsonString, 1, fsize, fp);
  fclose(fp);
  jsonString[fsize] = 0;

  cJSON *root = cJSON_Parse(jsonString);
  if (!root)
  {
    printf("Erro ao analisar o JSON\n");
    free(jsonString);
    return;
  }

  // Definir os campos e tipos de cada estrutura
  const char *camposLista[] = {"inicio", "qtde", NULL};
  const char *tiposLista[] = {"ELista*", "int", NULL};
  const char *camposFila[] = {"head", "tail", "qtde", NULL};
  const char *tiposFila[] = {"EFila*", "EFila*", "int", NULL};
  const char *camposABB[] = {"raiz", "qtde", NULL};
  const char *tiposABB[] = {"EABB*", "int", NULL};
  // const char *camposPilha[] = {"operacao", "proximo", NULL};
  // const char *tiposPilha[] = {"Operacao", "Pilha*", NULL};
  // ... e assim por diante para as outras possiveis estruturas

  jsonParaEstrutura(root, dados->lista, camposLista, tiposLista);
  jsonParaEstrutura(root, dados->fila, camposFila, tiposFila);
  jsonParaEstrutura(root, dados->abb, camposABB, tiposABB);
  // jsonParaEstrutura(root, dados->pilha, camposPilha, tiposPilha);
  // ...

  cJSON_Delete(root);
  free(jsonString);
}

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
  printf("2 - Registros ordenados por mes\n");
  // Mostrar registros ordenados por dia de registro;
  printf("3 - Registros ordenados por dia\n");
  // Mostrar registros ordenados por idade do paciente.
  printf("4 - Registros ordenados por idade\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
}

void sobre()
{
  printf("Sistema de atendimento hospitalar\n\n");
  printf("Desenvolvido por:\n");
  printf("Marjorie Luize Martins Costa\n");
  printf("& \n");
  printf("Nuno Martins Guilhermino da Silva\n\n");
  printf("Ciclo: \nQuarto\n\n");
  printf("Curso: \nCiencia da Computacao\n\n");
  printf("Disciplina: \nEstrutura de Dados\n\n");
  printf("Data: \n20/10/2024\n");
}
