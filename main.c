#include "funcoes.h"
// system("cls"); Limpa o terminal Windows
// system("clear"); Limpa o terminal Linux (Replit usa Linux)
// Retirando acentos e caracteres especiais

// Alterar main pro projeto atual
void main()
{
    // Inicializações
    // Inicializa a lista
    Lista *lista = inicializa_lista();
    // Inicializa a fila
    Fila *fila = inicializa_fila();
    // Inicializa a árvore
    ABB *abb = inicializa_arvore();
    // Inicializa a pilha
    Pilha *pilha = inicializa_pilha();

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
                // mostrar_ano(abb);
            }
            else if (opcao4 == 2)
            {
                // Registros ordenados por mês
                // mostrar_mes(abb);
            }
            else if (opcao4 == 3)
            {
                // Registros ordenados por dia
                // mostrar_dia(abb);
            }
            else if (opcao4 == 4)
            {
                // Registros ordenados por idade
                // mostrar_idade(abb);
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
            desfazer(pilha, fila, lista);
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
        //     cod = salvarLista(lt, arquivo);
    } while (opcao != 0);

}
