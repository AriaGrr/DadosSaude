#include "funcoes.h"
// system("cls"); Limpa o terminal Windows
// system("clear"); Limpa o terminal Linux (Replit usa Linux)
// Retirando acentos e caracteres especiais

// Alterar main pro projeto atual
void main()
{
    // Inicializações
    // Inicializa a lista
    Lista *lista = inicializaLista();
    // Inicializa a fila
    Fila *fila = inicializaFila();
    // Inicializa a árvore
    ABB *abb = inicializaArvore();
    // Inicializa a pilha
    Pilha *pilha = inicializaPilha();

    int opcao;
    do
    {
        system("clear");
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
            system("clear");
            menuCadastro();
            int opcao2;
            scanf("%d", &opcao2);
            system("clear");
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
            system("clear");
        }
        else if (opcao == 2)
        {
            system("clear");
            menuAtendimento();
            int opcao3;
            scanf("%d", &opcao3);
            system("clear");

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
            system("clear");
        }
        else if (opcao == 3)
        {
            system("clear");
            menuPesquisa();
            int opcao4;
            scanf("%d", &opcao4);
            system("clear");

            if (opcao4 == 1)
            {
               ABB *arvore_ano = inicializaArvore();
                
                ELista *lugar_atual = lista->inicio;
                
                while(lugar_atual != NULL){
                    Registro *atual = lugar_atual->dados;
                    inserirAno(arvore_ano,atual);
                    lugar_atual = lugar_atual->proximo;
                    
                }
                // Registros ordenados por ano
                 mostrar_ano(arvore_ano->raiz);
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
            system("clear");
        }
        else if (opcao == 4)
        {
            // Desfazer
            system("clear");
            desfazer(pilha, fila, lista);
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("clear");
        }
        else if (opcao == 5)
        {
            // Carregar
            system("clear");

            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("clear");
        }
        else if (opcao == 6)
        {
            // Salvar
            system("clear");

            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("clear");
        }
        else if (opcao == 7)
        {
            // Sobre
            system("clear");
            sobre();
            // Pausar o terminal
            printf("Pressione Enter para voltar ao menu...");
            clearBuffer();
            clearBuffer();
            system("clear");
        }
        else
        {
            printf("Opcao nao existe!\n");
        }
        //     cod = salvarLista(lt, arquivo);
    } while (opcao != 0);

}
