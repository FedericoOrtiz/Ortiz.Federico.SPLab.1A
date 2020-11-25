/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Bicicleta.h"
#include "C:\Users\Feder\Desktop\2do Parcial\Ortiz.Federico.SPLab.1A\src\Controller.h"
#include "Gets.h"
#include <time.h>



int main()
{
    srand(time(NULL));
    char path[20];
    char path2[20];
    char exit = 'n';
    int loadFromText = 0;
    int auxTipo;
    int flag = 0;

    LinkedList* listaBicicletas = ll_newLinkedList();
    LinkedList* listaFiltrada;
    LinkedList* listaConTiempos;

    do
    {
        switch(controller_showMenu())
        {
            case 1:
                if(!loadFromText)
                {
                    getString(path, 1, 20, "Ingrese nombre del archivo (sin .csv): ");
                    strcat(path, ".csv");
                    if(controller_loadFromText(path, listaBicicletas))
                    {
                        printf("Datos cargados con exito\n\n");
                        loadFromText = 1;
                    }
                    else
                    {
                        printf("Error al cargar el archivo\n\n");
                    }
                }
                else
                {
                    printf("El archivo ya ha sido cargado\n");
                }
                break;
            case 2:
                if(loadFromText)
                {
                    controller_imprimirListaBicicletas(listaBicicletas);
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }

                break;
            case 3:
                if(loadFromText)
                {
                    listaConTiempos = ll_map(listaBicicletas, setTiempoAleatorio);
                    flag = 1;
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }
                break;
            case 4:
                if(loadFromText)
                {
                    printf("\n1. BMX\n");
                    printf("2. PLAYERA\n");
                    printf("3. MTB\n");
                    printf("4. PASEO\n");
                    auxTipo = getInt(1, 4, "Ingrese tipo de bicicleta (1-4): ");
                    printf("\n\n");

                    switch(auxTipo)
                    {
                        case 1:
                            listaFiltrada = ll_filter(listaConTiempos, bicicletasBmx);
                            controller_imprimirListaBicicletas(listaFiltrada);
                            break;
                        case 2:
                            listaFiltrada = ll_filter(listaConTiempos, bicicletasPlayera);
                            controller_imprimirListaBicicletas(listaFiltrada);
                            break;
                        case 3:
                            listaFiltrada = ll_filter(listaConTiempos, bicicletasMtb);
                            controller_imprimirListaBicicletas(listaFiltrada);
                            break;
                        case 4:
                            listaFiltrada = ll_filter(listaConTiempos, bicicletasPaseo);
                            controller_imprimirListaBicicletas(listaFiltrada);
                            break;
                    }
                }
                else
                {
                    printf("Primero debe cargar el archivo\n");
                }
                break;
            case 5:
                if(loadFromText && flag)
                {
                    ll_sort(listaConTiempos, sortTipoYTiempo, 1);
                    controller_imprimirListaBicicletas(listaConTiempos);
                    flag = 2;
                }
                else
                {
                    printf("Primero debe cargar el archivo y setear los tiempos\n");
                }
                break;
            case 6:
                if(flag == 2)
                {
                    getString(path2, 1, 20, "Ingrese nombre del archivo (sin .csv): ");
                    strcat(path, ".csv");

                    if(controller_saveText(listaConTiempos, path2))
                    {
                        printf("Archivo guardado\n");
                    }
                    else
                    {
                        printf("Error al guardar el archivo\n");
                    }
                }
                else
                {
                    printf("Primero debe ordenar la lista\n");
                }
                break;
            case 7:
                exit = getChar("Confirma salida? (s/n) ");
                break;
        }

        printf("\n");
        system("pause");
        system("cls");

    }while(exit != 's');


    return 0;
}


































