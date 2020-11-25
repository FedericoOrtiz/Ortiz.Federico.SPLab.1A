#include "Parser.h"
#include "Bicicleta.h"
#include "../inc/LinkedList.h"

int parser_BicicletaFromText(FILE* pFile , LinkedList* lista)
{
    int ok = 0;
    int cant;
    char auxId[128];
    char auxNombre[128];
    char auxTipo[128];
    char auxTiempo[128];
    Bicicleta* auxBicicleta =  NULL;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxTipo, auxTiempo);

        while(!feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxTipo, auxTiempo);
            if(cant == 4)
            {
                auxBicicleta = bicicleta_newParametros(auxId, auxNombre, auxTipo, auxTiempo);

                if(auxBicicleta != NULL)
                {
                    ll_add(lista, auxBicicleta);
                    ok = 1;
                }
            }
            else
            {
                break;
            }
        }

        fclose(pFile);
    }

    return ok;
}
