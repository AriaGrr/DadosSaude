#include "funcoes.h"


// Alterar main pro projeto atual
int main()
{
    printf("Testando \n");
    Registro registro = {"João da Silva", 30, "123456789", 0};
    registro.entrada = (Data*)malloc(sizeof(Data));
    registro.entrada->dia = 15;
    registro.entrada->mes = 3;
    registro.entrada->ano = 2023;
    printf("Testando 1\n");
    const char *campos_registro[] = {"nome", "idade", "rg", "entrada.dia", "entrada.mes", "entrada.ano", NULL};
    const char *tipos_registro[] = {"char*", "int", "char*", "Data", "Data", "Data", NULL};
    printf("Testando 2\n");
    cJSON *json = estruturaJson(&registro, campos_registro, tipos_registro);
    printf("Testando 3\n");
    char *string_json = cJSON_Print(json);
    printf("Testando 4\n");
    FILE *fp = fopen("dados.json", "w");
    printf("Testando 5\n");
    fwrite(string_json, strlen(string_json), 1, fp);
    printf("Testando 6\n");
    fclose(fp);
    printf("Testando 7\n");
    cJSON_Delete(json);
    free(string_json);
    printf("Testando 8\n");

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
    return 0;
}