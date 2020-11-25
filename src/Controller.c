#include "C:\Users\Feder\Desktop\2do Parcial\Ortiz.Federico.SPLab.1A\src\Controller.h"
#include "Parser.h"
#include "Bicicleta.h"
#include "../inc/LinkedList.h"
#include "Gets.h"
#include <stdio.h>

int controller_loadFromText(char* path, LinkedList* lista)
{
    int ok = 0;
    FILE* pFile = NULL;

    if(path != NULL && lista != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            if(parser_BicicletaFromText(pFile, lista))
            {
                ok = 1;
            }
        }

        fclose(pFile);
    }

    return ok;
}

int controller_saveText(LinkedList* this, char* path)
{
    int ok = 0;
    int len;

    Bicicleta* auxBicicleta;
    int auxId;
    char auxNombre[20];
    char auxTipo[20];
    int auxTiempo;

    FILE* pFile = fopen(path, "w");

    if(pFile != NULL && this != NULL)
    {
        fprintf(pFile,"id_bike,nombre,tipo,tiempo\n");
        len = ll_len(this);

        for(int i=0; i<len; i++)
        {
            auxBicicleta = (Bicicleta*) ll_get(this, i);

            if(auxBicicleta != NULL)
            {
                getIdBicicleta(auxBicicleta, &auxId);
                getNombreBicicleta(auxBicicleta, auxNombre);
                getTipoBicicleta(auxBicicleta, auxTipo);
                getTiempoBicicleta(auxBicicleta, &auxTiempo);

                fprintf(pFile,"%d,%s,%s,%d\n",auxId,auxNombre,auxTipo,auxTiempo);
                ok = 1;
            }
        }

    }

    fclose(pFile);

    return ok;
}

int controller_imprimirListaBicicletas(LinkedList* lista)
{
    int len;
    int ok = 0;
    Bicicleta* auxBicicleta;

    if(lista != NULL)
    {
        len = ll_len(lista);
        printf(" ID       NOMBRE       TIPO   TIEMPO\n");

        for(int i=0; i<len; i++)
        {
            auxBicicleta = ll_get(lista, i);
            printBicicleta(auxBicicleta);
        }
        ok = 1;
    }

    return ok;
}

int controller_showMenu()
{
    printf("1. Cargar archivo.\n");
    printf("2. Imprimir Lista.\n");
    printf("3. Asignar Tiempos.\n");
    printf("4. Filtrar por Tipo.\n");
    printf("5. Mostrar Posiciones.\n");
    printf("6. Guardar Posiciones.\n");
    printf("7. Salir.\n\n");

    return getInt(1, 7, "Ingrese una opcion: ");
}
