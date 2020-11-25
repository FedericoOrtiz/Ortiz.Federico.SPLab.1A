#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

typedef struct
{
    int id_bike;
    char nombre[20];
    char tipo[20];
    int tiempo;
}Bicicleta;

Bicicleta* bicicleta_new();
Bicicleta* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempoStr);

int getIdBicicleta(Bicicleta* this, int* id_bike);
int getNombreBicicleta(Bicicleta* this, char* nombre);
int getTipoBicicleta(Bicicleta* this, char* tipo);
int getTiempoBicicleta(Bicicleta* this, int* tiempo);

int setIdBicicleta(Bicicleta* this, int id_bike);
int setNombreBicicleta(Bicicleta* this, char* nombre);
int setTipoBicicleta(Bicicleta* this, char* tipo);
int setTiempoBicicleta(Bicicleta* this, int tiempo);

void printBicicleta(Bicicleta* unaBicicleta);

int bicicletasBmx(void* bicicleta);
int bicicletasPlayera(void* bicicleta);
int bicicletasMtb(void* bicicleta);
int bicicletasPaseo(void* bicicleta);

int getTiempoAleatorio(int a, int b);
void* setTiempoAleatorio(void* bicicleta);

int sortTipoYTiempo(void* a, void* b);

#endif // BICICLETA_H_INCLUDED
