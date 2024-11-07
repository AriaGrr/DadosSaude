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

// Cria uma fila vazia
// Ponteiro para fila
Fila *inicializaFila()
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

Registro *salvarPessoa(char *nome, int idade, char *rg, Data *data) {
  Registro *pessoa = malloc(sizeof(Registro));
  strcpy(pessoa->nome, nome);
  pessoa->idade = idade;
  strcpy(pessoa->rg, rg);
  pessoa->entrada = data;
  return pessoa;
}

Data *criaData(int dia, int mes, int ano) {
  Data *data = malloc(sizeof(Data));
  data->dia = dia;
  data->mes = mes;
  data->ano = ano;
  return data;
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

Lista *inicializaLista()
{
  Lista *lista = malloc(sizeof(Lista));
  lista->inicio = NULL;
  lista->qtde = 0;
  return lista;
}

// Verificar se é Registro *dados mesmo
ELista *inicializaCelula(Registro *dados)
{
  ELista *celula = malloc(sizeof(ELista));
  celula->proximo = NULL;
  celula->dados = dados;
  return celula;
}

void inserir(Lista *lista, Registro *dados)
{
  ELista *nova = inicializaCelula(dados);
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
    printf("----------------------------------------\n");
    printf("Nome: %s\n", atual->dados->nome);
    printf("Idade: %d\n", atual->dados->idade);
    printf("RG: %s\n", atual->dados->rg);
    printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
    atual = atual->proximo;
  }
  printf("----------------------------------------\n");
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
  printf("----------------------------------------\n");
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
  // return novo;
}

// void cadastrarPaciente(Lista *lista, ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia, ABB *arvoreIdade)
void cadastrarPaciente(Lista *lista)
{
  Registro *novo = cadastrar(lista);
  int opcao;
  do
  {
    system("cls");
    printf("Dados do novo paciente\n");
    printf("----------------------------------------\n");
    printf("Nome: %s\n", novo->nome);
    printf("Idade: %d\n", novo->idade);
    printf("RG: %s\n", novo->rg);
    printf("Data de entrada: %d/%d/%d\n", novo->entrada->dia, novo->entrada->mes, novo->entrada->ano);
    printf("----------------------------------------\n");
    printf("Deseja\n");
    printf("1 - Confirmar\n");
    printf("2 - Alterar\n");
    printf("0 - Cancelar\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    if (opcao == 1)
    {
      inserir(lista, novo);
      //inserirArvore(arvoreAno, arvoreMes, arvoreDia, arvoreIdade, novo);
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
        // cadastrarPaciente(lista, arvoreAno, arvoreMes, arvoreDia, arvoreIdade);
        cadastrarPaciente(lista);
        // inserirArvore(arvoreAno, arvoreMes, arvoreDia, arvoreIdade, novo);
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
  printf("----------------------------------------\n");
  printf("Nome: %s\n", atual->dados->nome);
  printf("Idade: %d\n", atual->dados->idade);
  printf("RG: %s\n", atual->dados->rg);
  printf("Data de entrada: %d/%d/%d\n", atual->dados->entrada->dia, atual->dados->entrada->mes, atual->dados->entrada->ano);
  printf("----------------------------------------\n");
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
  celula->anterior = NULL;
  celula->proximo = NULL;
  celula->dados = dados;
  celula->operacao = operacao;

  return celula;
}

Pilha *inicializaPilha()
{
  Pilha *stack = malloc(sizeof(Pilha));
  stack->topo = NULL;
  stack->qtd = 0;

  return stack;
}

void push(Pilha *pilha, int valor, Registro *dados)
{
  Celula *nova = cria_celula(valor, dados);

  if (pilha->qtd == 0)
  {
    // Pilha está vazia, nenhum elemento anterior
    nova->anterior = NULL;
  }
  else
  {
    nova->anterior = pilha->topo;
    pilha->topo->proximo = nova;
  }

  pilha->topo = nova;
  pilha->qtd++;
}

void pop(Pilha *pilha, int *operacao, char *rg, Registro *dados)
{
  // if (pilha->qtd == 0)
  // {
  //   *operacao = 0;
  //   return;
  // }

  *operacao = pilha->topo->operacao;
  strcpy(rg, pilha->topo->dados->rg);
  *dados = *pilha->topo->dados;

  Celula *temp = pilha->topo;
  pilha->topo = pilha->topo->anterior;
  // Atualizar o ponteiro anterior do novo topo (se for duplamente encadeada)
  if (pilha->topo != NULL)
  {
    pilha->topo->proximo = NULL;
  }
  pilha->qtd--;
  free(temp);
}

// Não está sendo usado no código, mas pode ser útil para debugar (se é que está correto)
void mostra(Pilha *pilha)
{
  Celula *celula = pilha->topo;
  int qtd = pilha->qtd;
  printf("Operacoes: %d\n", qtd);
  // printf("----------------------------------------\n");
  while (celula != NULL)
  {
    // printf("%d -> ", celula->operacao);
    printf("%d -> ", qtd);
    qtd--;
    if (celula->operacao == 1)
    {
      printf("Desenfileirar %s\n", celula->dados->nome);
    }
    else if (celula->operacao == 2)
    {
      printf("Enfileirar %s\n", celula->dados->nome);
    }
    celula = celula->anterior;
  }
  printf("----------------------------------------\n");
}

// Erro intermitente: As vezes a variável operacao é alterada para 0 mesmo que a pilha não esteja vazia, o que faz com que o programa não funcione. Motivo desconhecido.
void desfazer(Pilha *pilha, Fila *fila)
{
  printf("Desfazer\n");
  printf("----------------------------------------\n");
  if (pilha->qtd <= 0)
  {
    printf("Nao ha operacoes para desfazer\n");
    printf("----------------------------------------\n");
    return;
  }
  printf("Deseja ver todas as operacoes?\n");
  printf("1 - Sim\n");
  printf("2 - Nao\n");
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
  int op;
  scanf("%d", &op);
  if (op == 1)
  {
    system("cls");
    printf("Desfazer\n");
    printf("----------------------------------------\n");
    mostra(pilha);
  }
  else if (op == 2)
  {
    system("cls");
    printf("Desfazer\n");
    printf("----------------------------------------\n");
  }
  else
  {
    printf("Opcao invalida\n");
    return;
  }

  int operacao;
  Registro *dados = malloc(sizeof(Registro));
  char rg[maxRG];
  // O & é necessário para passar o endereço da variável
  pop(pilha, &operacao, rg, dados);

  if (operacao == 1)
  {
    printf("Desenfileirar %s\n", dados->nome);
  }
  else if (operacao == 2)
  {
    printf("Enfileirar %s\n", dados->nome);
  }
  else
  {
    printf("Erro no carregamento\n");
    return;
  }
  printf("|_ Deseja desfazer a operacao?\n");
  printf("\n1 - Sim\n");
  printf("2 - Nao\n");
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
  int opcao;
  scanf("%d", &opcao);
  if (opcao == 1)
  {
    if (operacao == 1)
    {
      // Se a operação for desenfileirar, coloque o paciente de volta na fila na primeira posição (que é a que ele estava antes de ser desenfileirado)

      // Cria uma nova célula para o paciente
      EFila *nova = criarCelula(dados);
      // Se a fila estiver vazia
      if (fila->head == NULL)
      {
        fila->head = nova;
        fila->tail = nova;
      }
      else
      {
        // Se a fila não estiver vazia, coloque o paciente na primeira posição
        nova->proximo = fila->head;
        fila->head = nova;
      }
      printf("Paciente %s", dados->nome);
      printf(" retornou a fila de espera.\n");
      fila->qtde++;
    }
    else if (operacao == 2)
    {
      // CORRETO?
      // Se a operação for enfileirar, retire o ultimo paciente da fila (desenfileirar retira o primeiro paciente)
      EFila *atual = fila->head;
      EFila *anterior = NULL;
      while (atual != NULL)
      {
        if (strcmp(atual->dados->rg, rg) == 0)
        {
          if (anterior == NULL)
          {
            fila->head = atual->proximo;
            free(atual);
            fila->qtde--;
          }
          else
          {
            anterior->proximo = atual->proximo;
            free(atual);
            fila->qtde--;
          }
          printf("Paciente %s", dados->nome);
          printf(" removido(a) da fila de espera.\n");
          return;
        }
        anterior = atual;
        atual = atual->proximo;
      }
      printf("Paciente nao encontrado\n");
    }
    else
    {
      printf("Operacao invalida\n");
    }
  }
  else if (opcao == 2)
  {
    push(pilha, operacao, dados);
  }
  else
  {
    printf("Opcao invalida\n");
  }
}

// Item de menu: Atendimento em uma fila dinâmica (sem o anterior)
// Inserir um paciente, que já possua cadastro, em uma fila para atendimento
// Operações:
// ▶ Enfileirar paciente;
// ▶ Desenfileirar paciente;
// ▶ Mostrar fila.

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
    printf("----------------------------------------\n");
    i++;
    printf("Posicao: %d\n", i);
    printf("Nome: %s\n", atual->dados->nome);
    printf("RG: %s\n", atual->dados->rg);
    atual = atual->proximo;
  }
  printf("----------------------------------------\n");
}

// Item de menu: Pesquisa em uma árvore binária de busca
// Inserir um paciente, que já possua cadastro, em uma árvore binária de busca
// Operações:
// ▶ Mostrar registros ordenados por ano de registro;
// ▶ Mostrar registros ordenados por mês de registro;
// ▶ Mostrar registros ordenados por dia de registro;
// ▶ Mostrar registros ordenados por idade do paciente.

EABB *criaVertice(Registro *dados)
{
  EABB *novo = malloc(sizeof(EABB));
  novo->dir = NULL;
  novo->esq = NULL;
  novo->dados = dados;

  return novo;
}

ABB *inicializaArvore()
{
  ABB *arvore = malloc(sizeof(ABB));
  arvore->raiz = NULL;
  arvore->qtde = 0;

  return arvore;
}

void *inserirAno(ABB *arvore, Registro *dados)
{
  EABB *novo = criaVertice(dados);
  if (arvore->raiz == NULL)
  {
    arvore->raiz = novo;
  }
  else if (arvore->raiz != NULL)
  {
    EABB *anterior = NULL;
    EABB *atual = arvore->raiz;
    while (atual != NULL)
    {
      anterior = atual;
      if (novo->dados->entrada->ano > atual->dados->entrada->ano)
      {
        atual = atual->dir;
      }
      else
      {
        atual = atual->esq;
      }
      if (atual == NULL)
      {
        if (novo->dados->entrada->ano < anterior->dados->entrada->ano)
        {
          anterior->esq = novo;
        }
        else
        {
          anterior->dir = novo;
        }
        arvore->qtde++;
        // return novo;
      }
    }
  }
}

void *inserirMes(ABB *arvore, Registro *dados)
{
  EABB *novo = criaVertice(dados);
  if (arvore->raiz == NULL)
  {
    arvore->raiz = novo;
  }
  else if (arvore->raiz != NULL)
  {
    EABB *anterior = NULL;
    EABB *atual = arvore->raiz;
    while (atual != NULL)
    {
      anterior = atual;
      if (novo->dados->entrada->mes > atual->dados->entrada->mes)
      {
        atual = atual->dir;
      }
      else
      {
        atual = atual->esq;
      }
      if (atual == NULL)
      {
        if (novo->dados->entrada->mes < anterior->dados->entrada->mes)
        {
          anterior->esq = novo;
        }
        else
        {
          anterior->dir = novo;
        }
        arvore->qtde++;
        // return novo;
      }
    }
  }
}

void *inserirDia(ABB *arvore, Registro *dados)
{
    EABB *novo = criaVertice(dados);
    if (arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else if (arvore->raiz != NULL)
    {
        EABB *anterior = NULL;
        EABB *atual = arvore->raiz;
        while (atual != NULL)
        {
            anterior = atual;
            if (novo->dados->entrada->dia > atual->dados->entrada->dia)
            {
                atual = atual->dir;
            }
            else
            { 
                atual = atual->esq;
            }
            if (atual == NULL)
            {
                if (novo->dados->entrada->dia < anterior->dados->entrada->dia)
                {
                    anterior->esq = novo;
                }
                else
                {
                    anterior->dir = novo;
                }
                arvore->qtde++;
                // return novo;
            }
        }
    }
}

void *inserirIdade(ABB *arvore, Registro *dados)
{
    EABB *novo = criaVertice(dados);
    if (arvore->raiz == NULL)
    {
        arvore->raiz = novo;
    }
    else if (arvore->raiz != NULL)
    {
        EABB *anterior = NULL;
        EABB *atual = arvore->raiz;
        while (atual != NULL)
        {
            anterior = atual;
            if (novo->dados->idade > atual->dados->idade)
            {
                atual = atual->dir;
            }
            else
            { 
                atual = atual->esq;
            }
            if (atual == NULL)
            {
                if (novo->dados->idade < anterior->dados->idade)
                {
                    anterior->esq = novo;
                }
                else
                {
                    anterior->dir = novo;
                }
                arvore->qtde++;
                // return novo;
            }
        }
    }
}

void mostrarArvore(EABB *raiz)
{
  if (raiz != NULL)
  {
    mostrarArvore(raiz->esq);
    printf("----------------------------------------\n");
    printf("Nome: %s\n", raiz->dados->nome);
    printf("Idade: %d\n", raiz->dados->idade);
    printf("RG: %s\n", raiz->dados->rg);
    printf("Data de entrada: %d/%d/%d\n", raiz->dados->entrada->dia, raiz->dados->entrada->mes, raiz->dados->entrada->ano);
    mostrarArvore(raiz->dir);
  }
}

// void *inserirArvore(ABB *arvoreAno, ABB *arvoreMes, ABB *arvoreDia, ABB *arvoreIdade, Registro *dados)
// {
//   inserirAno(arvoreAno, dados);
//   inserirMes(arvoreMes, dados);
//   inserirDia(arvoreDia, dados);
//   inserirIdade(arvoreIdade, dados);
// }

// O que vou precisar: função de inserir, função pesquisar por um paciente, função de ordenar por ano, mês, dia e idade.
// Funções básicas como criar nó, inserir, buscar e percorrer (mostrar, inordem, preordem, posordem)

// CONCERTAR ITENS DA PESQUISA!!

// Salva a lista em um arquivo
// fwrite
int salvarLista(Lista *lista, char nome[])
{
  FILE *arquivo;
  arquivo = fopen(nome, "wb");

  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  ELista *atual = lista->inicio;
  while (atual != NULL)
  {
    fwrite(atual->dados, sizeof(Registro), 1, arquivo);
    fwrite(atual->dados->entrada, sizeof(Data), 1, arquivo);
    atual = atual->proximo;
  }

  fclose(arquivo);
  return 0;
}

// Carrega a lista de um arquivo
// fread
// int carregarLista(Lista *lista, char nome[])
// {
//   FILE *arquivo;
//   arquivo = fopen(nome, "rb");

//   if (arquivo == NULL)
//   {
//     printf("Erro ao abrir o arquivo.\n");
//     return 1;
//   }

//   Registro *registro = malloc(sizeof(Registro));
//   Data *data = malloc(sizeof(Data));
//   while (fread(registro, sizeof(Registro), 1, arquivo) == 1)
//   {
//     fread(data, sizeof(Data), 1, arquivo);
//     Registro *pessoa = salvarPessoa(registro->nome, registro->idade, registro->rg, data);
//     if (pessoa != NULL)
//     {
//       ELista *novo = inicializaCelula(pessoa);
//       if (lista->inicio == NULL)
//       {
//         lista->inicio = novo;
//       }
//       else
//       {
//         ELista *atual = lista->inicio;
//         ELista *anterior = NULL;
//         while (atual != NULL)
//         {
//           anterior = atual;
//           atual = atual->proximo;
//         }
//         anterior->proximo = novo;
//       }
//       lista->qtde++;
//     }
//   }

//   fclose(arquivo);
//   return 0;
// }

int carregarLista(Lista *lista, char *nomeArquivo){
  FILE *arquivo = fopen(nomeArquivo, "rb");
  if (arquivo == NULL) {
    printf("Falha ao abrir o arquivo");
    return 1;
  }
  Registro registro;
  Data data;
  while (fread(&registro, sizeof(Registro), 1, arquivo) == 1) { 
      fread(&data, sizeof(Data), 1, arquivo); 
      Data *novaData = criaData(data.dia, data.mes, data.ano);
      Registro *pessoa = salvarPessoa(registro.nome, registro.idade, registro.rg, novaData);
      if (pessoa != NULL) {
         ELista *novo = inicializaCelula(pessoa);
         //Adicionar no final da lista
         if (lista->inicio == NULL) {
           lista->inicio = novo;
         }else{
           ELista *atual = lista->inicio;
            ELista *anterior = NULL;
            while (atual != NULL) {
              anterior = atual;
              atual = atual->proximo;
            }
            anterior->proximo = novo;
         }
        lista->qtde++;
        //Adicionar na arvore
        // registroOrdenadoAno(arvoreAno, pessoa);
        // registroOrdenadoMes(arvoreMes, pessoa);
        // registroOrdenadoDia(arvoreDia, pessoa);
        // registroOrdenadoIdade(arvoreIdade, pessoa);
      }
  }
  fclose(arquivo);
  return 0;
  // printf("Dados carregados com sucesso!\n");
  // printf("\n");
}

// Funções para print dos menus:
void printMenu()
{
  printf("Menu\n");
  printf("----------------------------------------\n");
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
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
}

// Cadastrar novo paciente em uma lista dinâmica encadeada, mantendo a ordem de registro (inserção no início);
void menuCadastro()
{
  printf("Menu Cadastro\n");
  printf("----------------------------------------\n");
  printf("1 - Cadastrar novo paciente\n");
  printf("2 - Consultar paciente cadastrado\n");
  printf("3 - Mostrar lista de pacientes\n");
  printf("4 - Atualizar dados de paciente\n");
  printf("5 - Remover paciente\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
}

// Inserir um paciente, que já possua cadastro, em uma fila para atendimento
void menuAtendimento()
{
  printf("Menu Atendimento\n");
  printf("----------------------------------------\n");
  // Enfileirar paciente
  printf("1 - Adicionar paciente a fila de espera\n");
  // Desenfileirar paciente
  printf("2 - Atender paciente\n");
  // Mostrar fila
  printf("3 - Mostrar fila de espera\n");
  // Voltar ao menu
  printf("0 - Voltar ao menu\n");
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
}

// Inserir um paciente, que já possua cadastro, em uma árvore binária de busca;
void menuPesquisa()
{
  printf("Menu Pesquisa\n");
  printf("----------------------------------------\n");
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
  printf("----------------------------------------\n");
  printf("Digite a opcao desejada: ");
}

void sobre()
{
  printf("Sistema de atendimento hospitalar\n");
  printf("\n----------------------------------------\n");
  printf("\n");
  printf("Desenvolvido por:\n");
  printf("Marjorie Luize Martins Costa\n");
  printf("& \n");
  printf("Nuno Martins Guilhermino da Silva\n\n");
  printf("Ciclo: \nQuarto\n\n");
  printf("Curso: \nCiencia da Computacao\n\n");
  printf("Disciplina: \nEstrutura de Dados\n\n");
  printf("Data: \n20/10/2024\n");
  printf("\n----------------------------------------\n");
}
