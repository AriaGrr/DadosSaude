
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

// Item de menu: Cadastrar em uma LDE

// Operações:
// ▶ Cadastrar novo paciente;
// ▶ Consultar paciente cadastrado;
// ▶ Mostrar lista completa;
// ▶ Atualizar dados de paciente;
// ▶ Remover paciente.

// CONFERIR SE ESTÁ CORRETO

// As funções estão repetitivas, buscar uma forma de otimizar.

// LIMPANDO AS FUNÇÕES

// Funções para manipulação de listas dinâmicas encadeadas

Lista *inicializa_lista()
{
  Lista *lista = malloc(sizeof(Lista));
  lista->inicio = NULL;
  lista->qtde = 0;
  return lista;
}

// Verificar se é Registro *dados mesmo
ELista *inicializa_celula(Registro *dados)
{
  ELista *celula = malloc(sizeof(ELista));
  celula->proximo = NULL;
  celula->dados = dados;
  return celula;
}

void inserir(Lista *lista, Registro *dados)
{
  ELista *nova = inicializa_celula(dados);
  ELista *atual = lista->inicio;
  ELista *anterior = NULL;
  if (lista->qtde == 0)
  {
    lista->inicio = nova;
    lista->qtde++;
  }
  else
  {
    while (atual != NULL && nova->dados >= atual->dados)
    {
      anterior = atual;
      atual = atual->proximo;
    }
    if (anterior == NULL)
    {
      nova->proximo = lista->inicio;
      lista->inicio = nova;
      lista->qtde++;
    }
    else
    {
      if (atual == NULL)
      {
        anterior->proximo = nova;
        lista->qtde++;
      }
      else
      {
        anterior->proximo = nova;
        nova->proximo = atual;
        lista->qtde++;
      }
    }
  }
}

// Mostrar lista de pacientes completa?
void mostrarLista(Lista *lista)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    // printf("%d ", atual->dados);
    // atual = atual->proximo;
    printf("Nome: %s\n", atual->dados->nome);
    printf("Idade: %d\n", atual->dados->idade);
    printf("RG: %s\n", atual->dados->rg);
    printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
    atual = atual->proximo;
  }
  printf("\n");
}

// Melhorar o cadastro de paciente, não deixar o usuário sair sem preencher todos os campos
// Cadastro de paciente
// Registro *cadastrar()
// {
//   Registro *novo = malloc(sizeof(Registro));
//   printf("Nome: ");
//   scanf("%s", novo->nome);
//   printf("Idade: ");
//   scanf("%d", &novo->idade);
//   printf("RG: ");
//   scanf("%s", novo->rg);
//   novo->entrada = malloc(sizeof(Data));
//   printf("Data de entrada: ");
//   scanf("%d/%d/%d", &novo->entrada->dia, &novo->entrada->mes, &novo->entrada->ano);
//   return novo;
// }

int validarNome(char *nome)
{
  if (strlen(nome) > maxNOME)
  {
    return 0;
  }
  return 1;
}

int validarRg(char *rg)
{
  if (strlen(rg) > maxRG)
  {
    return 0;
  }
  return 1;
}

int validarIdade(int idade)
{
  if (idade < 0)
  {
    return 0;
  }
  return 1;
}

int validarData(Data *data)
{
  if (data->dia < 1 || data->dia > 31)
  {
    return 0;
  }
  if (data->mes < 1 || data->mes > 12)
  {
    return 0;
  }
  if (data->ano < 1900 || data->ano > 2024)
  {
    return 0;
  }
  return 1;
}

Registro *cadastrar()
{
  Registro *novo = malloc(sizeof(Registro));
  char nome[maxNOME];
  int idade;
  char rg[maxRG];
  Data *entrada = malloc(sizeof(Data));
  printf("Nome: ");
  scanf("%s", nome);
  while (!validarNome(nome))
  {
    printf("Nome invalido, digite novamente: ");
    scanf("%s", nome);
  }
  strcpy(novo->nome, nome);
  printf("Idade: ");
  scanf("%d", &idade);
  while (!validarIdade(idade))
  {
    printf("Idade invalida, digite novamente: ");
    scanf("%d", &idade);
  }
  novo->idade = idade;
  printf("RG: ");
  scanf("%s", rg);
  while (!validarRg(rg))
  {
    printf("RG invalido, digite novamente: ");
    scanf("%s", rg);
  }
  strcpy(novo->rg, rg);
  printf("Data de entrada: ");
  scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
  while (!validarData(entrada))
  {
    printf("Data invalida, digite novamente: ");
    scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
  }
  novo->entrada = entrada;
  return novo;
}


// Chamada de funções de cadastro
void cadastrarPaciente(Lista *lista)
{
  Registro *novo = cadastrar();
  inserir(lista, novo);
}

// // Consultar paciente cadastrado por nome
// void consultarNome(Lista *lista, char *nome)
// {
//   ELista *atual = lista->inicio;
//   while (atual != NULL)
//   {
//     if (strcmp(atual->dados->nome, nome) == 0)
//     {
//       printf("Nome: %s\n", atual->dados->nome);
//       printf("Idade: %d\n", atual->dados->idade);
//       printf("RG: %s\n", atual->dados->rg);
//       printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
//       return;
//     }
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

// // Consultar paciente cadastrado por RG
// void consultarRg(Lista *lista, char *rg)
// {
//   ELista *atual = lista->inicio;
//   while (atual != NULL)
//   {
//     if (strcmp(atual->dados->rg, rg) == 0)
//     {
//       printf("Nome: %s\n", atual->dados->nome);
//       printf("Idade: %d\n", atual->dados->idade);
//       printf("RG: %s\n", atual->dados->rg);
//       printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
//       return;
//     }
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

      // printf("Nome: %s\n", atual->dados->nome);
      // printf("Idade: %d\n", atual->dados->idade);
      // printf("RG: %s\n", atual->dados->rg);
      // printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);

void consultando(ELista *atual)
{
  printf("Nome: %s\n", atual->dados->nome);
  printf("Idade: %d\n", atual->dados->idade);
  printf("RG: %s\n", atual->dados->rg);
  printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
}
// Consultar paciente cadastrado por nome
void consultarNome(Lista *lista, char *nome)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->nome, nome) == 0)
    {
      consultando(atual);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

// Consultar paciente cadastrado por RG
void consultarRg(Lista *lista, char *rg)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->rg, rg) == 0)
    {
      consultando(atual);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

// Consultar paciente cadastrado por nome ou rg
void consultarPaciente(Lista *lista)
{
  int opcao;
  printf("Consultar por:\n");
  printf("1 - Nome\n");
  printf("2 - RG\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    char nome[50];
    printf("Nome: ");
    scanf("%s", nome);
    consultarNome(lista, nome);
  }
  else if (opcao == 2)
  {
    char rg[10];
    printf("RG: ");
    scanf("%s", rg);
    consultarRg(lista, rg);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}

// // Atualizar dados de paciente (por nome ou rg), printar dados do usuario e escolher o que deseja atualizar três funções.
// void atualizarNome(Lista *lista, char *nome){
//   ELista *atual = lista->inicio;
//   while(atual != NULL){
//     if(strcmp(atual->dados->nome, nome) == 0){
//       printf("Nome: %s\n", atual->dados->nome);
//       printf("Idade: %d\n", atual->dados->idade);
//       printf("RG: %s\n", atual->dados->rg);
//       printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
//       int opcao;
//       printf("Atualizar:\n");
//       printf("1 - Nome\n");
//       printf("2 - Idade\n");
//       printf("3 - RG\n");
//       printf("4 - Data de entrada\n");
//       printf("Digite a opcao desejada: ");
//       scanf("%d", &opcao);
//       if(opcao == 1){
//         printf("Nome: ");
//         scanf("%s", atual->dados->nome);
//       }else if(opcao == 2){
//         printf("Idade: ");
//         scanf("%d", &atual->dados->idade);
//       }else if(opcao == 3){
//         printf("RG: ");
//         scanf("%s", atual->dados->rg);
//       }else if(opcao == 4){
//         atual->dados->entrada = malloc(sizeof(Data));
//         printf("Data de entrada: ");
//         scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
//       }else{
//         printf("Opcao invalida\n");
//       }
//       return;
//     }
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

// void atualizarRg(Lista *lista, char *rg){
//   ELista *atual = lista->inicio;
//   while(atual != NULL){
//     if(strcmp(atual->dados->rg, rg) == 0){
//       printf("Nome: %s\n", atual->dados->nome);
//       printf("Idade: %d\n", atual->dados->idade);
//       printf("RG: %s\n", atual->dados->rg);
//       printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
//       int opcao;
//       printf("Atualizar:\n");
//       printf("1 - Nome\n");
//       printf("2 - Idade\n");
//       printf("3 - RG\n");
//       printf("4 - Data de entrada\n");
//       printf("Digite a opcao desejada: ");
//       scanf("%d", &opcao);
//       if(opcao == 1){
//         printf("Nome: ");
//         scanf("%s", atual->dados->nome);
//       }else if(opcao == 2){
//         printf("Idade: ");
//         scanf("%d", &atual->dados->idade);
//       }else if(opcao == 3){
//         printf("RG: ");
//         scanf("%s", atual->dados->rg);
//       }else if(opcao == 4){
//         atual->dados->entrada = malloc(sizeof(Data));
//         printf("Data de entrada: ");
//         scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
//       }else{
//         printf("Opcao invalida\n");
//       }
//       return;
//     }
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

// printf("Nome: %s\n", atual->dados->nome);
// printf("Idade: %d\n", atual->dados->idade);
// printf("RG: %s\n", atual->dados->rg);
// printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
// int opcao;
// printf("Atualizar:\n");
// printf("1 - Nome\n");
// printf("2 - Idade\n");
// printf("3 - RG\n");
// printf("4 - Data de entrada\n");
// printf("Digite a opcao desejada: ");
// scanf("%d", &opcao);
// if(opcao == 1){
//   printf("Nome: ");
//   scanf("%s", atual->dados->nome);
// }else if(opcao == 2){
//   printf("Idade: ");
//   scanf("%d", &atual->dados->idade);
// }else if(opcao == 3){
//   printf("RG: ");
//   scanf("%s", atual->dados->rg);
// }else if(opcao == 4){
//   atual->dados->entrada = malloc(sizeof(Data));
//   printf("Data de entrada: ");
//   scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
// }else{
//   printf("Opcao invalida\n");
// }
void atualizando(Lista *lista, ELista *atual)
{
  // int opcao;
  // printf("Atualizar:\n");
  // printf("1 - Nome\n");
  // printf("2 - Idade\n");
  // printf("3 - RG\n");
  // printf("4 - Data de entrada\n");
  // printf("Digite a opcao desejada: ");
  // scanf("%d", &opcao);
  // if(opcao == 1){
  //   printf("Nome: ");
  //   scanf("%s", atual->dados->nome);
  // }else if(opcao == 2){
  //   printf("Idade: ");
  //   scanf("%d", &atual->dados->idade);
  // }else if(opcao == 3){
  //   printf("RG: ");
  //   scanf("%s", atual->dados->rg);
  // }else if(opcao == 4){
  //   atual->dados->entrada = malloc(sizeof(Data));
  //   printf("Data de entrada: ");
  //   scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
  // }else{
  //   printf("Opcao invalida\n");
  // }
  printf("Nome: %s\n", atual->dados->nome);
  printf("Idade: %d\n", atual->dados->idade);
  printf("RG: %s\n", atual->dados->rg);
  printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
  int opcao;
  printf("Atualizar:\n");
  printf("1 - Nome\n");
  printf("2 - Idade\n");
  printf("3 - RG\n");
  printf("4 - Data de entrada\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    printf("Nome: ");
    scanf("%s", atual->dados->nome);
  }
  else if (opcao == 2)
  {
    printf("Idade: ");
    scanf("%d", &atual->dados->idade);
  }
  else if (opcao == 3)
  {
    printf("RG: ");
    scanf("%s", atual->dados->rg);
  }
  else if (opcao == 4)
  {
    atual->dados->entrada = malloc(sizeof(Data));
    printf("Data de entrada: ");
    scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}

// Atualizar dados de paciente (por nome ou rg), printar dados do usuario e escolher o que deseja atualizar três funções.
void atualizarNome(Lista *lista, char *nome)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->nome, nome) == 0)
    {
      atualizando(lista, atual);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

void atualizarRg(Lista *lista, char *rg)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->rg, rg) == 0)
    {
      atualizando(lista, atual);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

void atualizarPaciente(Lista *lista)
{
  int opcao;
  printf("Atualizar por:\n");
  printf("1 - Nome\n");
  printf("2 - RG\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    char nome[50];
    printf("Nome: ");
    scanf("%s", nome);
    atualizarNome(lista, nome);
  }
  else if (opcao == 2)
  {
    char rg[10];
    printf("RG: ");
    scanf("%s", rg);
    atualizarRg(lista, rg);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}

// // Remover paciente por nome ou rg
// void removerNome(Lista *lista, char *nome){
//   ELista *atual = lista->inicio;
//   ELista *anterior = NULL;
//   while(atual != NULL){
//     if(strcmp(atual->dados->nome, nome) == 0){
//         if(anterior == NULL){
//         lista->inicio = atual->proximo;
//         free(atual);
//         lista->qtde--;
//         return;
//       }else{
//         anterior->proximo = atual->proximo;
//         free(atual);
//         lista->qtde--;
//         return;
//       }
//     }
//     anterior = atual;
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

// Remover paciente por rg
// void removerRg(Lista *lista, char *rg){
//   ELista *atual = lista->inicio;
//   ELista *anterior = NULL;
//   while(atual != NULL){
//     if(strcmp(atual->dados->rg, rg) == 0){
//       if(anterior == NULL){
//         lista->inicio = atual->proximo;
//         free(atual);
//         lista->qtde--;
//         return;
//       }else{
//         anterior->proximo = atual->proximo;
//         free(atual);
//         lista->qtde--;
//         return;
//       }
//     }
//     anterior = atual;
//     atual = atual->proximo;
//   }
//   printf("Paciente nao encontrado\n");
// }

// if(anterior == NULL){
//   lista->inicio = atual->proximo;
//   free(atual);
//   lista->qtde--;
//   return;
// }else{
//   anterior->proximo = atual->proximo;
//   free(atual);
//   lista->qtde--;
//   return;
// }

void removendo(Lista *lista, ELista *atual, ELista *anterior)
{
  if (anterior == NULL)
  {
    lista->inicio = atual->proximo;
    free(atual);
    lista->qtde--;
  }
  else
  {
    anterior->proximo = atual->proximo;
    free(atual);
    lista->qtde--;
  }
}

// Remover paciente por nome ou rg
void removerNome(Lista *lista, char *nome)
{
  ELista *atual = lista->inicio;
  ELista *anterior = NULL;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->nome, nome) == 0)
    {
      removendo(lista, atual, anterior);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

void removerRg(Lista *lista, char *rg)
{
  ELista *atual = lista->inicio;
  ELista *anterior = NULL;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->rg, rg) == 0)
    {
      removendo(lista, atual, anterior);
      return;
    }
    anterior = atual;
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

// Remover paciente por nome ou rg
void removerPaciente(Lista *lista)
{
  int opcao;
  printf("Remover por:\n");
  printf("1 - Nome\n");
  printf("2 - RG\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    char nome[50];
    printf("Nome: ");
    scanf("%s", nome);
    removerNome(lista, nome);
  }
  else if (opcao == 2)
  {
    char rg[10];
    printf("RG: ");
    scanf("%s", rg);
    removerRg(lista, rg);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}
