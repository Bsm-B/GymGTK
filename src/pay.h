#ifndef PAY_H_INCLUDED
#define PAY_H_INCLUDED
#include <stdio.h>
#include <string.h>

struct Paiment
{
    int ID;
    int NBMOIS;
    char NOM[50];
    char DATE[30];
};
typedef struct Paiment pmt;

void ajouter_paiment(pmt);
void modifier_paiment(pmt);
void supprimer_paiment(int);
void accedernom(int,char[]);
int verif_paiment(int);


#endif //PAIEMENT_H_INCLUDED
