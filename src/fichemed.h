#ifndef FICHEMED_H_INCLUDED
#define FICHEMED_H_INCLUDED

#include <stdio.h>

struct Med
{
    int ID;
    char NOM[20];
    char PRENOM[20];
    char EMAIL[40];
    char TEL[12];
    char MALADE[20];
    float POIDS,LONG;
};
typedef struct Med med;


void ajouter_med(med);
int verif_med(int);
void modifier_med(med);
void supprimer_med(int id);


#endif
