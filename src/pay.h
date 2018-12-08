#ifndef PAY_H_INCLUDED
#define PAY_H_INCLUDED
#include <stdio.h>
#include <string.h>
struct Paiment
{
    int ID;
    int NBMOIS;
    char NOM[40];
    char DATE[20];
};
typedef struct Paiment pmt;

void ajouter_paiment(pmt);
void modifier_paiment(pmt);
void supprimer_paiment(int);
void accedernom(int,char[]);



#endif //PAIEMENT_H_INCLUDED
