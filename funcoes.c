// COMENTAR O CÓDIGO

#include "funcoes.h"

#include <ctype.h> // isalpha
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

// Item de menu: Cadastrar em uma LDE

// Operações:
// ▶ Cadastrar novo paciente;
// ▶ Consultar paciente cadastrado;
// ▶ Mostrar lista completa;
// ▶ Atualizar dados de paciente;
// ▶ Remover paciente.

// CONFERIR SE ESTÁ CORRETO

// As funções estão repetitivas, buscar uma forma de otimizar.

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

// Mostrar lista de pacientes completa
void mostrarLista(Lista *lista)
{
  ELista *atual = lista->inicio;
  if (atual == NULL)
  {
    printf("Lista vazia\n");
    return;
  }
  printf("Lista de pacientes\n");
  while (atual != NULL)
  {
    printf("--------------------\n");
    printf("Nome: %s\n", atual->dados->nome);
    printf("Idade: %d\n", atual->dados->idade);
    printf("RG: %s\n", atual->dados->rg);
    printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
    atual = atual->proximo;
  }
  printf("--------------------\n");
}

int validarNome(char *nome)
{
  // Verifica se o nome contém apenas letras e espaços
  for (int i = 0; nome[i] != '\0'; i++)
  {
    if (!isalpha(nome[i]) && nome[i] != ' ')
    {
      return 0;
    }
  }

  if (strlen(nome) > maxNOME)
  {
    return 0;
  }
  return 1;
}

int validarRg(char *rg, Lista *lista)
{
  int passou = 0;
  if (strlen(rg) > maxRG || strlen(rg) < 7)
  {
    passou = 1;
  }
  if (passou == 0)
  {
    ELista *atual = lista->inicio;
    while (atual != NULL)
    {
      if (strcmp(atual->dados->rg, rg) == 0)
      {
        passou = 1;
      }
      atual = atual->proximo;
    }
  }

  if (passou == 0)
  {
    return 1;
  }

  return 0;
}

int validarIdade(int idade)
{
  if (idade < 0 || idade > 120)
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

Registro *cadastrar(Lista *lista)
{
  Registro *novo = malloc(sizeof(Registro));
  char nome[maxNOME];
  int idade;
  char rg[maxRG];
  Data *entrada = malloc(sizeof(Data));
  printf("Cadastro de paciente\n");
  printf("--------------------\n");
  printf("Nome: ");
  clearBuffer();
  fgets(nome, maxNOME, stdin);
  nome[strcspn(nome, "\n")] = '\0';
  while (!validarNome(nome))
  {
    clearBuffer();
    printf("Nome invalido, digite novamente. Exemplo: Joao\n");
    printf("Nome: ");
    fgets(nome, maxNOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
  }
  // SE VOCÊ COLOCAR LETRAS NA IDADE OU DATA O PROGRAMA VAI BUGAR
  strcpy(novo->nome, nome);
  printf("Idade: ");
  scanf("%d", &idade);
  while (!validarIdade(idade))
  {
    printf("Idade invalida, digite novamente. Exemplo: 18\n");
    printf("Idade: ");
    scanf("%d", &idade);
  }
  novo->idade = idade;
  printf("RG: ");
  scanf("%s", rg);
  while (!validarRg(rg, lista))
  {
    printf("RG invalido, digite novamente. Exemplo: 1234567\n");
    printf("RG: ");
    scanf("%s", rg);
  }
  strcpy(novo->rg, rg);
  printf("Data de entrada: ");
  scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
  while (!validarData(entrada))
  {
    printf("Data invalida, digite novamente. Exemplo: 01/01/2024\n");
    printf("Data de entrada: ");
    scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
  }
  novo->entrada = entrada;
  return novo;
}

void cadastrarPaciente(Lista *lista)
{
  Registro *novo = cadastrar(lista);
  int opcao;
  do
  {
    system("cls");
    printf("Dados do novo paciente\n");
    printf("--------------------\n");
    printf("Nome: %s\n", novo->nome);
    printf("Idade: %d\n", novo->idade);
    printf("RG: %s\n", novo->rg);
    printf("Data de entrada: %d/%d/%d\n", novo->entrada->dia, novo->entrada->mes, novo->entrada->ano);
    printf("--------------------\n");
    printf("Deseja\n");
    printf("1 - Confirmar\n");
    printf("2 - Alterar\n");
    printf("0 - Cancelar\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
      inserir(lista, novo);
    }
    else if (opcao == 2)
    {
      printf("Alterar\n");
      printf("1 - Tudo\n");
      printf("2 - Campo\n");
      int opcao2;
      printf("Digite a opcao desejada: ");
      scanf("%d", &opcao2);
      if (opcao2 == 1)
      {
        free(novo->entrada);
        free(novo);
        cadastrarPaciente(lista);
      }
      else if (opcao2 == 2)
      {
        printf("Alterar:\n");
        printf("1 - Nome\n");
        printf("2 - Idade\n");
        printf("3 - RG\n");
        printf("4 - Data de entrada\n");
        printf("Digite a opcao desejada: ");
        int opcao3;
        scanf("%d", &opcao3);
        if (opcao3 == 1)
        {
          char nome[maxNOME];
          printf("Nome: ");
          clearBuffer();
          fgets(nome, maxNOME, stdin);
          nome[strcspn(nome, "\n")] = '\0';
          while (!validarNome(nome))
          {
            clearBuffer();
            printf("Nome invalido, digite novamente. Exemplo: Joao\n");
            printf("Nome: ");
            fgets(nome, maxNOME, stdin);
            nome[strcspn(nome, "\n")] = '\0';
          }
          strcpy(novo->nome, nome);
        }
        else if (opcao3 == 2)
        {
          int idade;
          printf("Idade: ");
          scanf("%d", &idade);
          while (!validarIdade(idade))
          {
            printf("Idade invalida, digite novamente. Exemplo: 18\n");
            printf("Idade: ");
            scanf("%d", &idade);
          }
          novo->idade = idade;
        }
        else if (opcao3 == 3)
        {
          char rg[maxRG];
          printf("RG: ");
          scanf("%s", rg);
          while (!validarRg(rg, lista))
          {
            printf("RG invalido, digite novamente. Exemplo: 1234567\n");
            printf("RG: ");
            scanf("%s", rg);
          }
          strcpy(novo->rg, rg);
        }
        else if (opcao3 == 4)
        {
          Data *entrada = malloc(sizeof(Data));
          printf("Data de entrada: ");
          scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
          while (!validarData(entrada))
          {
            printf("Data invalida, digite novamente. Exemplo: 01/01/2024\n");
            printf("Data de entrada: ");
            scanf("%d/%d/%d", &entrada->dia, &entrada->mes, &entrada->ano);
          }
          novo->entrada = entrada;
        }
        else
        {
          printf("Opcao invalida\n");
        }
      }
    }
    else if (opcao == 0)
    {
      free(novo->entrada);
      free(novo);
    }
    else
    {
      printf("Opcao invalida\n");
    }
  } while (opcao != 1 && opcao != 3);
}

void consultando(ELista *atual)
{
  system("cls");
  printf("Dados do paciente\n");
  printf("--------------------\n");
  printf("Nome: %s\n", atual->dados->nome);
  printf("Idade: %d\n", atual->dados->idade);
  printf("RG: %s\n", atual->dados->rg);
  printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
  printf("--------------------\n");
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
    clearBuffer();
    fgets(nome, maxNOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
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

void atualizando(Lista *lista, ELista *atual)
{
  consultando(atual);
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
    clearBuffer();
    fgets(atual->dados->nome, maxNOME, stdin);
    atual->dados->nome[strcspn(atual->dados->nome, "\n")] = '\0';
    while (!validarNome(atual->dados->nome))
    {
      clearBuffer();
      printf("Nome invalido, digite novamente. Exemplo: Joao\n");
      printf("Nome: ");
      fgets(atual->dados->nome, maxNOME, stdin);
      atual->dados->nome[strcspn(atual->dados->nome, "\n")] = '\0';
    }
  }
  else if (opcao == 2)
  {
    printf("Idade: ");
    scanf("%d", &atual->dados->idade);
    while (!validarIdade(atual->dados->idade))
    {
      printf("Idade invalida, digite novamente. Exemplo: 18\n");
      printf("Idade: ");
      scanf("%d", &atual->dados->idade);
    }
  }
  else if (opcao == 3)
  {
    printf("RG: ");
    scanf("%s", atual->dados->rg);
    while (!validarRg(atual->dados->rg, lista))
    {
      printf("RG invalido, digite novamente. Exemplo: 1234567\n");
      printf("RG: ");
      scanf("%s", atual->dados->rg);
    }
  }
  else if (opcao == 4)
  {
    atual->dados->entrada = malloc(sizeof(Data));
    printf("Data de entrada: ");
    scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
    while (!validarData(atual->dados->entrada))
    {
      printf("Data invalida, digite novamente. Exemplo: 01/01/2024\n");
      printf("Data de entrada: ");
      scanf("%d/%d/%d", &atual->dados->entrada->dia, &atual->dados->entrada->mes, &atual->dados->entrada->ano);
    }
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
    // Substituir scanf por fgets no nome para evitar bugs de nomes com espaço.
    clearBuffer();
    fgets(nome, maxNOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
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
  printf("Paciente removido\n");
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
  printf("Remover por\n");
  printf("1 - Nome\n");
  printf("2 - RG\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    char nome[50];
    printf("Nome: ");
    clearBuffer();
    fgets(nome, maxNOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
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


// Item de menu: Desfazer
// Utilize uma pilha para armazenar as operações realizadas para a montagem da fila de atendimento;

// Operações:
// ▶ Desfaz a última operação realizada para a montagem da fila de
// atendimento;
// ▶ Informe ao usuário a operação a ser desfeita e solicite confirmação.

Celula *cria_celula(int operacao, Registro *dados)
{
  Celula *celula = malloc(sizeof(Celula));
  celula->proximo = NULL;
  celula->dados = dados;
  celula->operacao = operacao;

  return celula;
}

Pilha *inicializa_pilha()
{
    Pilha *stack = malloc(sizeof(Pilha));
    stack->topo = NULL;
    stack->qtd = 0;

    return stack;
}

void push(Pilha *pilha, int valor, Registro *dados)
{
    Celula *nova = cria_celula(valor, dados);

    if (pilha->qtd > 0)
    {
        nova->proximo = pilha->topo;
        // Maneira que fiz antes:
        // nova->anterior = pilha->topo;
        // pilha->topo->proximo = nova;
    }
    pilha->topo = nova;
    pilha->qtd++;
}

int pop(Pilha *pilha)
{
    if (pilha->qtd == 0)
    {
        return -1;
    }
    int valor = pilha->topo->operacao;
    Celula *temp = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(temp);
    pilha->qtd--;
    return valor;
}
// {
//     //   if (pilha->qtd > 0) {
//     //     Celula *temp = pilha->topo;
//     //     pilha->topo = pilha->topo->anterior;
//     //     free(temp);
//     //     pilha->qtd--;
//     //   }
//     if (pilha->qtd == 0)
//     {
//         return -1;
//     }
//     int valor = pilha->topo->operacao;
//     Celula *temp = pilha->topo;
//     pilha->topo = pilha->topo->anterior;
//     if (pilha->qtd > 1)
//     {
//         pilha->topo->proximo = NULL;
//     }
//     free(temp);
//     pilha->qtd--;
//     return valor;
// }

void mostra(Pilha *pilha)
{
    Celula *celula = pilha->topo;
    printf("Operacoes\n");
    while (celula != NULL)
    {
        // printf("%c", celula->operacao);
        printf("--------------------\n");
        printf("%d", celula->operacao);
        celula = celula->anterior;
    }
    printf("--------------------\n");
}

void desfazer(Pilha *pilha, Fila *fila, Lista *lista)
{
    printf("Desfazer\n");
    printf("--------------------\n");
    if (pilha->qtd == 0)
    {
        printf("Nao ha operacoes para desfazer\n");
        return;
    }
    int operacao = pop(pilha);
    if (operacao == 1){
      printf("Desenfileirar\n");
    } else if (operacao == 2){
      printf("Enfileirar\n");
    }
    // printf("%d", operacao);
    printf("--------------------\n");
    printf("Deseja desfazer a operacao?\n");
    printf("--------------------\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("--------------------\n");
    printf("Digite a opcao desejada: ");
    int opcao;
    scanf("%d", &opcao);
    if (opcao == 1)
    {
        if (operacao == 1)
        {
            desenfileirarPaciente(fila, pilha);
        }
        else if (operacao == 2)
        {
            enfileirarRg(fila, pilha, lista, pilha->topo->dados);
        }
        else
        {
            printf("Operacao invalida\n");
        }
    }
    else if (opcao == 2)
    {
        push(pilha, operacao, NULL);
    }
    else
    {
        printf("Opcao invalida\n");
    }
}
// void desfazer(Fila *fila)
// {
//   if (fila->head == NULL)
//   {
//     printf("Fila vazia\n");
//     return;
//   }
//   EFila *atual = fila->head;
//   EFila *anterior = NULL;
//   while (atual->proximo != NULL)
//   {
//     anterior = atual;
//     atual = atual->proximo;
//   }
//   printf("Desfazer\n");
//   printf("Paciente %s", atual->dados->nome);
//   printf(" removido(a) da fila de espera.\n");
//   free(atual);
//   if (anterior == NULL)
//   {
//     fila->head = NULL;
//     fila->tail = NULL;
//   }
//   else
//   {
//     anterior->proximo = NULL;
//     fila->tail = anterior;
//   }
//   fila->qtde--;
// }


// Item de menu: Atendimento em uma fila dinâmica (sem o anterior)
// Inserir um paciente, que já possua cadastro, em uma fila para atendimento;

// Operações:
// ▶ Enfileirar paciente;
// ▶ Desenfileirar paciente;
// ▶ Mostrar fila.

// Cria uma fila vazia
// Ponteiro para fila
Fila *inicializa_fila()
{
  // Fila *fila = (Fila *)malloc(sizeof(Fila));
  Fila *fila = malloc(sizeof(Fila));
  fila->head = NULL;
  fila->tail = NULL;
  fila->qtde = 0;
  // Retorna o ponteiro para a fila
  return fila;
}

// Cria uma celula
EFila *criarCelula(Registro *dados)
{
  EFila *celula = malloc(sizeof(EFila));
  // celula->anterior = NULL;
  celula->proximo = NULL;
  celula->dados = dados;
  return celula;
}

// Conferir se está correto depois
// Enfileirar paciente
void enfileirar(Fila *fila, Registro *dados)
{
  EFila *nova = criarCelula(dados);
  if (fila->head == NULL)
  {
    fila->head = nova;
    fila->tail = nova;
  }
  else
  {
    fila->tail->proximo = nova;
    fila->tail = nova;
  }
  printf("Paciente %s", dados->nome);
  printf(" adicionado(a) a fila de espera.\n");
  fila->qtde++;
}

// Conferir se está correto depois
// Desenfileirar paciente
void desenfileirarPaciente(Fila *fila, Pilha *pilha)
{
  if (fila->head == NULL)
  {
    printf("Fila vazia\n");
    return;
  }
  // Armazena o paciente que será removido
  EFila *removido = fila->head;
  push(pilha, 1, removido->dados);
  fila->head = fila->head->proximo;
  printf("Paciente %s", removido->dados->nome);
  printf(" atendido(a).\n");
  free(removido);
  fila->qtde--;
}
// {
//   if (fila->head == NULL)
//   {
//     printf("Fila vazia\n");
//     return;
//   }
//   // Armazena o paciente que será removido
//   EFila *removido = fila->head;
//   fila->head = fila->head->proximo;
//   printf("Paciente %s", removido->dados->nome);
//   printf(" atendido(a).\n");
//   free(removido);
//   fila->qtde--;
// }

// void enfileirarPaciente(Fila *fila, Lista *lista, Pilha *pilha){
//   printf("Enfileirar paciente\n");
//   printf("1 - Nome\n");
//   printf("2 - RG\n");
//   printf("Digite a opcao desejada: ");
//   int opcao;
//   scanf("%d", &opcao);
//   if (opcao == 1)
//   {
//     char nome[50];
//     printf("Nome: ");
//     clearBuffer();
//     fgets(nome, maxNOME, stdin);
//     nome[strcspn(nome, "\n")] = '\0';
//     ELista *atual = lista->inicio;
//     while (atual != NULL)
//     {
//       if (strcmp(atual->dados->nome, nome) == 0)
//       {
//         // CONFERIR SE ELE JÁ ESTÁ NA FILA
//         for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
//         {
//           if (strcmp(aux->dados->nome, nome) == 0)
//           {
//             printf("Paciente ja esta na fila\n");
//             return;
//           }
//         }
//         enfileirar(fila, atual->dados);
//         push(pilha, 2, atual->dados);
//         return;
//       }
//       atual = atual->proximo;
//     }
//     printf("Paciente nao encontrado\n");
//   }
//   else if (opcao == 2)
//   {
//     char rg[10];
//     printf("RG: ");
//     scanf("%s", rg);
//     ELista *atual = lista->inicio;
//     while (atual != NULL)
//     {
//       if (strcmp(atual->dados->rg, rg) == 0)
//       {
//         // CONFERIR SE ELE JÁ ESTÁ NA FILA
//         for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
//         {
//           if (strcmp(aux->dados->rg, rg) == 0)
//           {
//             printf("Paciente ja esta na fila\n");
//             return;
//           }
//         }
//         enfileirar(fila, atual->dados);
//         push(pilha, 2, atual->dados);
//         return;
//       }
//       atual = atual->proximo;
//     }
//     printf("Paciente nao encontrado\n");
//   }
//   else
//   {
//     printf("Opcao invalida\n");
//   }
// }

void enfileirarNome(Fila *fila, Lista *lista, Pilha *pilha, char *nome)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->nome, nome) == 0)
    {
      // CONFERIR SE ELE JÁ ESTÁ NA FILA
      for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
      {
        if (strcmp(aux->dados->nome, nome) == 0)
        {
          printf("Paciente ja esta na fila\n");
          return;
        }
      }
      enfileirar(fila, atual->dados);
      push(pilha, 2, atual->dados);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

void enfileirarRg(Fila *fila, Lista *lista, Pilha *pilha, char *rg)
{
  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    if (strcmp(atual->dados->rg, rg) == 0)
    {
      // CONFERIR SE ELE JÁ ESTÁ NA FILA
      for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
      {
        if (strcmp(aux->dados->rg, rg) == 0)
        {
          printf("Paciente ja esta na fila\n");
          return;
        }
      }
      enfileirar(fila, atual->dados);
      push(pilha, 2, atual->dados);
      return;
    }
    atual = atual->proximo;
  }
  printf("Paciente nao encontrado\n");
}

void enfileirarPaciente(Fila *fila, Lista *lista, Pilha *pilha)
{
  int opcao;
  printf("Enfileirar paciente\n");
  printf("1 - Nome\n");
  printf("2 - RG\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    char nome[50];
    printf("Nome: ");
    clearBuffer();
    fgets(nome, maxNOME, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    enfileirarNome(fila, lista, pilha, nome);
  }
  else if (opcao == 2)
  {
    char rg[10];
    printf("RG: ");
    scanf("%s", rg);
    enfileirarRg(fila, lista, pilha, rg);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}
// {
//   printf("Enfileirar paciente\n");
//   printf("1 - Nome\n");
//   printf("2 - RG\n");
//   printf("Digite a opcao desejada: ");
//   int opcao;
//   scanf("%d", &opcao);
//   if (opcao == 1)
//   {
//     char nome[50];
//     printf("Nome: ");
//     clearBuffer();
//     fgets(nome, maxNOME, stdin);
//     nome[strcspn(nome, "\n")] = '\0';
//     ELista *atual = lista->inicio;
//     while (atual != NULL)
//     {
//       if (strcmp(atual->dados->nome, nome) == 0)
//       {
//         // CONFERIR SE ELE JÁ ESTÁ NA FILA
//         for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
//         {
//           if (strcmp(aux->dados->nome, nome) == 0)
//           {
//             printf("Paciente ja esta na fila\n");
//             return;
//           }
//         }
//         enfileirar(fila, atual->dados);
//         return;
//       }
//       atual = atual->proximo;
//     }
//     printf("Paciente nao encontrado\n");
//   }
//   else if (opcao == 2)
//   {
//     char rg[10];
//     printf("RG: ");
//     scanf("%s", rg);
//     ELista *atual = lista->inicio;
//     while (atual != NULL)
//     {
//       if (strcmp(atual->dados->rg, rg) == 0)
//       {
//         // CONFERIR SE ELE JÁ ESTÁ NA FILA
//         for (EFila *aux = fila->head; aux != NULL; aux = aux->proximo)
//         {
//           if (strcmp(aux->dados->rg, rg) == 0)
//           {
//             printf("Paciente ja esta na fila\n");
//             return;
//           }
//         }
//         enfileirar(fila, atual->dados);
//         return;
//       }
//       atual = atual->proximo;
//     }
//     printf("Paciente nao encontrado\n");
//   }
//   else
//   {
//     printf("Opcao invalida\n");
//   }
// }

// Mostrar fila
void mostrarFila(Fila *fila)
{
  EFila *atual = fila->head;
  if (atual == NULL)
  {
    printf("Fila vazia\n");
    return;
  }
  printf("Fila de espera\n");
  int i = 0;
  while (atual != NULL)
  {
    printf("--------------------\n");
    i++;
    printf("Posicao: %d\n", i);
    printf("Nome: %s\n", atual->dados->nome);
    printf("RG: %s\n", atual->dados->rg);
    atual = atual->proximo;
  }
  printf("--------------------\n");
}

// Item de menu: Pesquisa em uma árvore binária de busca
// Inserir um paciente, que já possua cadastro, em uma árvore binária de busca;

// Operações:
// ▶ Mostrar registros ordenados por ano de registro;
// ▶ Mostrar registros ordenados por mês de registro;
// ▶ Mostrar registros ordenados por dia de registro;
// ▶ Mostrar registros ordenados por idade do paciente.

EABB *cria_vertice(Registro *dados)
{
  EABB *novo = malloc(sizeof(EABB));
  novo->dir = NULL;
  novo->esq = NULL;
  // novo->pai = NULL;
  novo->dados = dados;

  return novo;
}

ABB *inicializa_arvore()
{
  ABB *arvore = malloc(sizeof(ABB));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  return arvore;
}

// CONCERTAR ITENS DA PESQUISA!!

// Funções para print dos menus

void printMenu()
{
  printf("Menu\n");
  printf("--------------------\n");
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
  printf("--------------------\n");
  printf("Digite a opcao desejada: ");
}

// Cadastrar novo paciente em uma lista dinâmica encadeada, mantendo a ordem de registro (inserção no início);
void menuCadastro()
{
  printf("Menu Cadastro\n");
  printf("--------------------\n");
  printf("1 - Cadastrar novo paciente\n");
  printf("2 - Consultar paciente cadastrado\n");
  printf("3 - Mostrar lista de pacientes\n");
  printf("4 - Atualizar dados de paciente\n");
  printf("5 - Remover paciente\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
  printf("--------------------\n");
  printf("Digite a opcao desejada: ");
}

// Inserir um paciente, que já possua cadastro, em uma fila para atendimento;
void menuAtendimento()
{
  printf("Menu Atendimento\n");
  printf("--------------------\n");
  // Enfileirar paciente
  printf("1 - Adicionar paciente a fila de espera\n");
  // Desenfileirar paciente
  printf("2 - Atender paciente\n");
  // Mostrar fila
  printf("3 - Mostrar fila de espera\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
  printf("--------------------\n");
  printf("Digite a opcao desejada: ");
}

// Inserir um paciente, que já possua cadastro, em uma árvore binária de busca;
void menuPesquisa()
{
  printf("Menu Pesquisa\n");
  printf("--------------------\n");
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
  printf("--------------------\n");
  printf("Digite a opcao desejada: ");
}

void sobre()
{
  printf("Sistema de atendimento hospitalar\n");
  printf("\n--------------------\n");
  printf("\n");
  printf("Desenvolvido por:\n");
  printf("Marjorie Luize Martins Costa\n");
  printf("& \n");
  printf("Nuno Martins Guilhermino da Silva\n\n");
  printf("Ciclo: \nQuarto\n\n");
  printf("Curso: \nCiencia da Computacao\n\n");
  printf("Disciplina: \nEstrutura de Dados\n\n");
  printf("Data: \n20/10/2024\n");
  printf("\n--------------------\n");
}
