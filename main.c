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
    // Inicializa a pilha
    Pilha *pilha = inicializaPilha();
    // Inicializa as árvores
    // Arvore *arvore = cria_arvore(); EXEMPLO
    ;ABB *arvoreAno = inicializaArvore();
    ABB *arvoreMes = inicializaArvore();
    ABB *arvoreDia = inicializaArvore();
    ABB *arvoreIdade = inicializaArvore();

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
                cadastrarPaciente(lista, arvoreAno, arvoreMes, arvoreDia, arvoreIdade);
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
                mostrarArvore(arvoreAno->raiz);

                // ABB *arvore_ano = inicializaArvore();
                ABB *arvoreAno = inicializaArvore();
                ELista *atual = lista->inicio;

                while (atual != NULL)
                {
                    Registro *novo = atual->dados;
                    inserirAno(arvoreAno, novo);
                    atual = atual->proximo;
                }
                // Registros ordenados por ano
                mostrarArvore(arvoreAno->raiz);

                // ABB *arvore_ano = inicializaArvore();

                // ELista *lugar_atual = lista->inicio;

                // while (lugar_atual != NULL)
                // {
                //     Registro *atual = lugar_atual->dados;
                //     inserirAno(arvore_ano, atual);
                //     lugar_atual = lugar_atual->proximo;
                // }
                // // Registros ordenados por ano
                // mostrar_ano(arvore_ano->raiz);
            }
            else if (opcao4 == 2)
            {
                // Registros ordenados por mês
                printf("Registros ordenados por mes:\n");
                // ordenado(arvoreMes->raiz);
            }
            else if (opcao4 == 3)
            {
                // Registros ordenados por dia
                printf("Registros ordenados por dia:\n");
                // ordenado(arvoreDia->raiz);
            }
            else if (opcao4 == 4)
            {
                // Registros ordenados por idade
                printf("Registros ordenados por idade:\n");
                // ordenado(arvoreIdade->raiz);
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
