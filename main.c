#include "funcoes.h"
// system("cls"); Limpa o terminal Windows
// system("clear"); Limpa o terminal Linux (Replit usa Linux)
// Retirando acentos e caracteres especiais

// Alterar main pro projeto atual
int main()
{
    int cod;
    char arquivo[] = "pacientes";

    // Inicializações
    // Inicializa a lista
    Lista *lista = inicializaLista();
    // Inicializa a fila
    Fila *fila = inicializaFila();
    // Inicializa a pilha
    Pilha *pilha = inicializaPilha();
    // Inicializa as árvores
    // Arvore *arvore = cria_arvore(); EXEMPLO
    // ABB *arvoreAno = inicializaArvore();
    // ABB *arvoreMes = inicializaArvore();
    // ABB *arvoreDia = inicializaArvore();
    // ABB *arvoreIdade = inicializaArvore();

    cod = carregarLista(lista, arquivo);
    if (cod == 1)
    {
        lista->qtde = 0;
    }

    int opcao;
    do
    {
        system("cls");
        printMenu();
        scanf("%d", &opcao);
        // printf("%d\n", opcao);
        if (opcao == 0)
        {
            printf("Saindo...\n");
        }
        else if (opcao == 1)
        {
            // Menu de cadastro
            system("cls");
            menuCadastro();
            int opcao2;
            scanf("%d", &opcao2);
            system("cls");
            if (opcao2 == 1)
            {
                // Cadastrar novo paciente
                // cadastrarPaciente(lista, arvoreAno, arvoreMes, arvoreDia, arvoreIdade);
                cadastrarPaciente(lista);
            }
            else if (opcao2 == 2)
            {
                // Consultar paciente cadastrado
                consultarPaciente(lista);
            }
            else if (opcao2 == 3)
            {
                // Mostrar lista completa
                mostrarLista(lista);
            }
            else if (opcao2 == 4)
            {
                // Atualizar dados de paciente
                atualizarPaciente(lista);
            }
            else if (opcao2 == 5)
            {
                // Remover paciente
                removerPaciente(lista);
            }
            else if (opcao2 == 0)
            {
                // Voltar ao menu
                // Só deixar vázio
            }
            else
            {
                printf("Opcao nao existe!\n");
            }
            printf("Pressione Enter para voltar ao menu...");
            // Pausar o terminal
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 2)
        {
            system("cls");
            menuAtendimento();
            int opcao3;
            scanf("%d", &opcao3);
            system("cls");

            if (opcao3 == 1)
            {
                // Adicionar paciente à fila de espera
                enfileirarPaciente(fila, lista, pilha);
            }
            else if (opcao3 == 2)
            {
                // Atender paciente
                desenfileirarPaciente(fila, pilha);
            }
            else if (opcao3 == 3)
            {
                // Mostrar fila de espera
                mostrarFila(fila);
            }
            else if (opcao3 == 0)
            {
                // Voltar ao menu
            }
            else
            {
                printf("Opcao nao existe!\n");
            }
            printf("Pressione Enter para voltar ao menu...");
            // Pausar o terminal
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 3)
        {
            system("cls");
            menuPesquisa();
            int opcao4;
            scanf("%d", &opcao4);
            system("cls");

            if (opcao4 == 1)
            {
                // Registros ordenados por ano
                printf("Registros ordenados por ano:\n");
                ABB *arvoreAno = inicializaArvore();

                ELista *atual = lista->inicio;

                while (atual != NULL)
                {
                    Registro *novo = atual->dados;
                    inserirAno(arvoreAno, novo);
                    atual = atual->proximo;
                }
                // // Registros ordenados por ano
                mostrarArvore(arvoreAno->raiz);
                printf("----------------------------------------\n");
            }
            else if (opcao4 == 2)
            {
                // Registros ordenados por mês
                printf("Registros ordenados por mes:\n");
                ABB *arvoreMes = inicializaArvore();
                ELista *atual = lista->inicio;

                while (atual != NULL)
                {
                    Registro *novo = atual->dados;
                    inserirAno(arvoreMes, novo);
                    atual = atual->proximo;
                }
                mostrarArvore(arvoreMes->raiz);
                printf("----------------------------------------\n");
            }
            else if (opcao4 == 3)
            {
                // Registros ordenados por dia
                printf("Registros ordenados por dia:\n");
                ABB *arvoreDia = inicializaArvore();
                ELista *atual = lista->inicio;

                while (atual != NULL)
                {
                    Registro *novo = atual->dados;
                    inserirAno(arvoreDia, novo);
                    atual = atual->proximo;
                }
                mostrarArvore(arvoreDia->raiz);
                printf("----------------------------------------\n");
            }
            else if (opcao4 == 4)
            {
                // Registros ordenados por idade
                printf("Registros ordenados por idade:\n");
                ABB *arvoreIdade = inicializaArvore();
                ELista *atual = lista->inicio;

                while (atual != NULL)
                {
                    Registro *novo = atual->dados;
                    inserirAno(arvoreIdade, novo);
                    atual = atual->proximo;
                }
                mostrarArvore(arvoreIdade->raiz);
                printf("----------------------------------------\n");
            }
            else if (opcao4 == 0)
            {
                // Voltar ao menu
            }
            else
            {
                printf("Opcao nao existe!\n");
            }
            printf("Pressione Enter para voltar ao menu...");
            // Pausar o terminal
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 4)
        {
            // Desfazer
            system("cls");
            desfazer(pilha, fila);
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 5)
        {
            // Carregar
            system("cls");
            // Limpar a lista antes de carregar
            liberarLista(lista);
            cod = carregarLista(lista, arquivo);
            if (cod == 1)
            {
                lista->qtde = 0;
                printf("Nao foi possivel carregar os pacientes!\n");
            } else {
                printf("Pacientes carregados com sucesso!\n");
            }
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 6)
        {
            // Salvar
            system("cls");
            cod = salvarLista(lista, arquivo);
            if (cod == 0)
            {
                printf("Pacientes salvos com sucesso!\n");
            }
            else
            {
                printf("Erro ao salvar pacientes!\n");
            }
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else if (opcao == 7)
        {
            // Sobre
            system("cls");
            sobre();
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("cls");
        }
        else
        {
            printf("Opcao nao existe!\n");
        }
        cod = salvarLista(lista, arquivo);
    } while (opcao != 0);
    if (cod != 0)
    {
        printf("Erro ao salvar pacientes!\n");
    }
    return 0;
}
