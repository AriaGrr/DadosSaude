#include "funcoes.h"
// #include "cJSON.h"
// #include "lib\cJSON\cJSON.h"
// #include "funcoes.c"

// Alterar main pro projeto atual
int main()
{

    Registro registro = {"João da Silva", 30, "123456789", 0};
    registro.entrada = (Data*)malloc(sizeof(Data));
    registro.entrada->dia = 15;
    registro.entrada->mes = 3;
    registro.entrada->ano = 2023;

    const char *campos_registro[] = {"nome", "idade", "rg", "entrada.dia", "entrada.mes", "entrada.ano", NULL};
    const char *tipos_registro[] = {"char*", "int", "char*", "Data", "Data", "Data", NULL};

    cJSON *json = estruturaJson(&registro, campos_registro, tipos_registro);
    char *string_json = cJSON_Print(json);
    FILE *fp = fopen("dados.json", "w");
    fwrite(string_json, strlen(string_json), 1, fp);
    fclose(fp);
    cJSON_Delete(json);
    free(string_json);

    Registro nova_registro;
    jsonEstrutura("dados.json", &nova_registro, campos_registro, tipos_registro);

    for (int i = 0; campos_registro[i] != NULL; i++)
    {
        printf("%s: ", campos_registro[i]);
        if (tipos_registro[i][0] == 'c')
        {
            printf("%s\n", *((char **)&nova_registro + i));
        }
        else if (tipos_registro[i][0] == 'i')
        {
            printf("%d\n", *((int *)&nova_registro + i));
        }
        else if (tipos_registro[i][0] == 'D')
        {
            Data *data = (Data *)((char *)&nova_registro + i);
            printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
        }
    }
    return 0;

//     // Criar uma instância da estrutura Registro
//     Registro registro = {"João da Silva", 30, "123456789", {15, 3, 2023}};

//     // Criar um array de campos e tipos para a estrutura Registro
//     const char* campos_registro[] = {"nome", "idade", "rg", "entrada.dia", "entrada.mes", "entrada.ano", NULL};
//     const char* tipos_registro[] = {"char*", "int", "char*", "Data", "Data", "Data", NULL};

//     // Converter a estrutura Registro para JSON e salvar em um arquivo
//     cJSON* json = estruturaJson(&registro, campos_registro, tipos_registro);
//     char* string_json = cJSON_Print(json);
//     FILE* fp = fopen("dados.json", "w");
//     fwrite(string_json, strlen(string_json), 1, fp);
//     fclose(fp);
//     cJSON_Delete(json);
//     free(string_json);

//     // Ler o arquivo JSON e popular uma nova estrutura
//     Registro nova_registro;
//     jsonEstrutura("dados.json", &nova_registro, campos_registro, tipos_registro);

//     for (int i = 0; campos_registro[i] != NULL; i++)
//     {
//         printf("%s: ", campos_registro[i]);
//         if (tipos_registro[i][0] == 'c')
//         {
//             printf("%s\n", *((char**) &nova_registro + i));
//         }
//         else if (tipos_registro[i][0] == 'i')
//         {
//             printf("%d\n", *((int*) &nova_registro + i));
//         }
//         else if (tipos_registro[i][0] == 'D')
//         {
//             Data* data = (Data*) ((char*) &nova_registro + i);
//             printf("%d/%d/%d\n", data->dia, data->mes, data->ano);
//         }
//     }
    // // Imprimir os dados da nova estrutura para verificar
    // printf("Nome: %s\n", nova_registro.nome);
    // printf("Idade: %d\n", nova_registro.idade);
    // printf("RG: %s\n", nova_registro.rg);
    // printf("Data de entrada: %d/%d/%d\n", nova_registro.entrada.dia, nova_registro.entrada.mes, nova_registro.entrada.ano);
    // // ... imprimir outros campos ...

//   int cod;
  // Ia ser usado para salvar os arquivos em txt, mas irei tentar fazer em json
//   char arquivo[] = "arquivos";
//   char exportado[] = "-";
//   ArquivosPacientes lt;

//   cod = carregarLista(&lt, arquivo);
//   if (cod == 1)
//   {
//     lt.qtd = 0;
//   }
//   int opcao;
//   do
//   {
//     printMenu();
//     scanf("%d", &opcao);
//     printf("%d\n", opcao);
//     if (opcao == 0)
//     {
//       printf("Saindo...\n");
//     }
//     else if (opcao == 1)
//     {
//       criarTarefa(&lt);
//       // Limpar o terminal
//       system("clear");
//     }
//     else if (opcao == 2)
//     {
//       deletarTarefa(&lt);
//       system("clear");
//     }
//     else if (opcao == 3)
//     {

//       system("clear");

//       menuListagem();
//       int opcao2;
//       scanf("%d", &opcao2);
//       system("clear");
//       if (opcao2 == 1)
//       {
//         listarTarefas(lt);
//       }
//       else if (opcao2 == 2)
//       {
//         listarPrioridade(lt);
//       }
//       else if (opcao2 == 3)
//       {
//         listarCategoria(lt);
//       }
//       else if (opcao2 == 4)
//       {
//         listarEstado(lt);
//       }
//       else if (opcao2 == 5)
//       {
//         listarPCTarefa(lt);
//       }
//       else
//       {
//         printf("Opção não existe!\n");
//       }
//       printf("Pressione Enter para voltar ao menu...");
//       // Pausar o terminal
//       clearBuffer();
//       clearBuffer();
//       system("clear");
//     }
//     else if (opcao == 4)
//     {
//       system("clear");
//       menuExportar();
//       int opcao3;
//       scanf("%d", &opcao3);
//       system("clear");

//       if (opcao3 == 1)
//       {
//         exportarTarefas(lt, exportado);
//       }
//       else if (opcao3 == 2)
//       {
//         exportarPrioridade(lt, exportado);
//       }
//       else if (opcao3 == 3)
//       {
//         exportarCategoria(lt, exportado);
//       }
//       else if (opcao3 == 4)
//       {
//         exportarPCTarefa(lt, exportado);
//       }
//       else
//       {
//         printf("Opção não existe!\n");
//       }
//     }
//     else if (opcao == 5)
//     {
//       system("clear");
//       alterarTarefa(&lt);
//     }
//     else
//     {
//       printf("Opção não existe!\n");
//     }
//     cod = salvarLista(lt, arquivo);
//   } while (opcao != 0);

//   if (cod != 0)
//   {
//     printf("Erro ao salvar arquivo!\n");
//   }
//   return 0;
}