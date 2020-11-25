#include "Bicicleta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Gets.h"


Bicicleta* bicicleta_new()
{
    Bicicleta* nuevaBicicleta;
    nuevaBicicleta = (Bicicleta*) calloc(sizeof(Bicicleta), 1);

    return nuevaBicicleta;
}

Bicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr)
{
    Bicicleta* nuevaBicicleta = NULL;
    nuevaBicicleta = bicicleta_new();

    if(nuevaBicicleta != NULL &&
       idStr != NULL &&
       nombreStr != NULL &&
       tipoStr != NULL &&
       tiempoStr != NULL)
    {
        setIdBicicleta(nuevaBicicleta, atoi(idStr));
        setNombreBicicleta(nuevaBicicleta, nombreStr);
        setTipoBicicleta(nuevaBicicleta, tipoStr);
        setTiempoBicicleta(nuevaBicicleta, atoi(tiempoStr));
    }

    return nuevaBicicleta;
}

int getIdBicicleta(Bicicleta* this, int* id_bike)
{
    int ok = 0;

    if(this != NULL && id_bike != NULL)
    {
        *id_bike = this->id_bike;
        ok = 1;
    }

    return ok;
}
int getNombreBicicleta(Bicicleta* this, char* nombre)
{
    int ok = 0;

    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        ok = 1;
    }

    return ok;
}

int getTipoBicicleta(Bicicleta* this, char* tipo)
{
    int ok = 0;

    if(this != NULL && tipo != NULL)
    {
        strcpy(tipo, this->tipo);
        ok = 1;
    }

    return ok;
}

int getTiempoBicicleta(Bicicleta* this, int* tiempo)
{
    int ok = 0;

    if(this != NULL && tiempo != NULL)
    {
        *tiempo = this->tiempo;
        ok = 1;
    }

    return ok;
}


int setIdBicicleta(Bicicleta* this, int id_bike)
{
    int ok = 0;
    if(this != NULL && id_bike>0)
    {
        this->id_bike = id_bike;
        ok = 1;
    }

    return ok;
}

int setNombreBicicleta(Bicicleta* this, char* nombre)
{
    int ok = 0;
    if(this != NULL && strlen(nombre)>=3)
    {
        strcpy(this->nombre, nombre);
        ok = 1;
    }

    return ok;
}
int setTipoBicicleta(Bicicleta* this, char* tipo)
{
    int ok = 0;
    if(this != NULL && strlen(tipo)>2)
    {
        strcpy(this->tipo, tipo);
        ok = 1;
    }

    return ok;
}
int setTiempoBicicleta(Bicicleta* this, int tiempo)
{
    int ok = 0;
    if(this != NULL && tiempo>-1)
    {
        this->tiempo = tiempo;
        ok = 1;
    }

    return ok;
}

void printBicicleta(Bicicleta* unaBicicleta)
{
    Bicicleta auxBicicleta;

    if(unaBicicleta != NULL)
    {
        auxBicicleta = *unaBicicleta;
        printf("%3d %12s %10s %8d\n", auxBicicleta.id_bike, auxBicicleta.nombre, auxBicicleta.tipo, auxBicicleta.tiempo);
    }
}

int bicicletasBmx(void* bicicleta)
{
    int ok = 0;
    char tipo[20];

    if(bicicleta != NULL)
    {
        bicicleta = (Bicicleta*) bicicleta;

        getTipoBicicleta(bicicleta, tipo);

        if(strcmp(tipo, "BMX") == 0)
        {
            ok = 1;
        }
    }

    return ok;
}

int bicicletasPlayera(void* bicicleta)
{
    int ok = 0;
    char tipo[20];

    if(bicicleta != NULL)
    {
        bicicleta = (Bicicleta*) bicicleta;

        getTipoBicicleta(bicicleta, tipo);

        if(strcmp(tipo, "PLAYERA") == 0)
        {
            ok = 1;
        }
    }

    return ok;
}

int bicicletasMtb(void* bicicleta)
{
    int ok = 0;
    char tipo[20];

    if(bicicleta != NULL)
    {
        bicicleta = (Bicicleta*) bicicleta;

        getTipoBicicleta(bicicleta, tipo);

        if(strcmp(tipo, "MTB") == 0)
        {
            ok = 1;
        }
    }

    return ok;
}

int bicicletasPaseo(void* bicicleta)
{
    int ok = 0;
    char tipo[20];

    if(bicicleta != NULL)
    {
        bicicleta = (Bicicleta*) bicicleta;

        getTipoBicicleta(bicicleta, tipo);

        if(strcmp(tipo, "PASEO") == 0)
        {
            ok = 1;
        }
    }

    return ok;
}

int getTiempoAleatorio(int a, int b)
{
    return rand()%(a)+(b);
}

void* setTiempoAleatorio(void* bicicleta)
{
    Bicicleta* auxBicicleta;
    void* pElement;
    int tiempo;

    if(bicicleta != NULL)
    {
        auxBicicleta = (Bicicleta*) bicicleta;
        tiempo = getTiempoAleatorio(71, 50);

        if(setTiempoBicicleta(auxBicicleta, tiempo))
        {
            pElement = NULL;
        }else
        {
            pElement = (void*) auxBicicleta;
        }
    }

    return pElement;
}

int sortTipoYTiempo(void* a, void* b)
{
    int sort = 0;
    Bicicleta* bici1;
    Bicicleta* bici2;

    char auxTipo1[20];
    char auxTipo2[20];
    int auxTiempo1;
    int auxTiempo2;

    if(a != NULL && b != NULL)
    {
        bici1 = (Bicicleta*) a;
        bici2 = (Bicicleta*) b;

        getTipoBicicleta(bici1, auxTipo1);
        getTipoBicicleta(bici2, auxTipo2);
        getTiempoBicicleta(bici1, &auxTiempo1);
        getTiempoBicicleta(bici2, &auxTiempo2);

        if(strcmp(auxTipo1, auxTipo2) > 0)
        {
            sort = 1;
        }
        else if(strcmp(auxTipo1, auxTipo2) == 0 && auxTiempo1 > auxTiempo2)
        {
            sort = 1;
        }
    }

    return sort;
}
