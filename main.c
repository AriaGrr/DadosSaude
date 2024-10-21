#include "funcoes.h"
// system("cls"); Limpa o terminal Windows
// system("clear"); Limpa o terminal Linux (Replit usa Linux)
// Retirando acentos e caracteres especiais

// Alterar main pro projeto atual
void main()
{
    //   int cod;
    // Ia ser usado para salvar os arquivos em txt, mas irei tentar fazer em json
    //   char arquivo[] = "arquivo,";
    //   char exportado[] = "-";
    //   ArquivosPacientes lt;

    //   cod = carregarLista(&lt, arquivo);
    //   if (cod == 1)
    //   {
    //     lt.qtd = 0;
    //   }
    int opcao;
    do
    {
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
            }
            else if (opcao2 == 2)
            {
                // Consultar paciente cadastrado
            }
            else if (opcao2 == 3)
            {
                // Mostrar lista completa
            }
            else if (opcao2 == 4)
            {
                // Atualizar dados de paciente
            }
            else if (opcao2 == 5)
            {
                // Remover paciente
            }
            else if (opcao2 == 0)
            {
                // Voltar ao menu
                // Só de deixar o comentário já volta ao menu
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
            }
            else if (opcao3 == 2)
            {
                // Atender paciente
            }
            else if (opcao3 == 3)
            {
                // Mostrar fila de espera
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
            }
            else if (opcao4 == 2)
            {
                // Registros ordenados por mês
            }
            else if (opcao4 == 3)
            {
                // Registros ordenados por dia
            }
            else if (opcao4 == 4)
            {
                // Registros ordenados por idade
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
        }
        else if (opcao == 5)
        {
            // Carregar
            system("cls");
        }
        else if (opcao == 6)
        {
            // Salvar
            system("cls");
        }
        else if (opcao == 7)
        {
            // Sobre
            system("cls");
            sobre();
            // Pausar o terminal
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

    //   if (cod != 0)
    //   {
    //     printf("Erro ao salvar arquivo!\n");
    //   }

    // TESTE DE JSON

    //     printf("Testando \n");
    //     Registro registro = {"João da Silva", 30, "123456789", 0};
    //     registro.entrada = (Data*)malloc(sizeof(Data));
    //     registro.entrada->dia = 15;
    //     registro.entrada->mes = 3;
    //     registro.entrada->ano = 2023;
    //     printf("Testando 1\n");
    //     const char *campos_registro[] = {"nome", "idade", "rg", "entrada.dia", "entrada.mes", "entrada.ano", NULL};
    //     const char *tipos_registro[] = {"char*", "int", "char*", "Data", "Data", "Data", NULL};
    //     printf("Testando 2\n");
    //     cJSON *json = estruturaJson(&registro, campos_registro, tipos_registro);
    //     printf("Testando 3\n");
    //     char *string_json = cJSON_Print(json);
    //     printf("Testando 4\n");
    //     FILE *fp = fopen("dados.json", "w");
    //     printf("Testando 5\n");
    //     fwrite(string_json, strlen(string_json), 1, fp);
    //     printf("Testando 6\n");
    //     fclose(fp);
    //     printf("Testando 7\n");
    //     cJSON_Delete(json);
    //     free(string_json);
    //     printf("Testando 8\n");

    // Registro nova_registro;
    // jsonEstrutura("dados.json", &nova_registro, campos_registro, tipos_registro);
    // printf("Testando\n");
    // for (int i = 0; campos_registro[i] != NULL; i++)
    // {
    //     printf("%s: ", campos_registro[i]);
    //     if (tipos_registro[i][0] == 'c')
    //     {
    //         printf("%s\n", *((char **)&nova_registro + i));
    //     }
    //     else if (tipos_registro[i][0] == 'i')
    //     {
    //         printf("%d\n", *((int *)&nova_registro + i));
    //     }
    //     else if (tipos_registro[i][0] == 'D')
    //     {
    //         Data *data = (Data *)((char *)&nova_registro + i);
    //         printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
    //     }
    // }
    // printf("Testando\n");
}
