#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "../inc/LinkedList.h"

int controller_loadFromText(char* path, LinkedList* lista);
int controller_saveText(LinkedList* this, char* path);
int controller_imprimirListaBicicletas(LinkedList* lista);
int controller_showMenu();

#endif // CONTROLLER_H_INCLUDED
