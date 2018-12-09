#ifndef KINE_H_INCLUDED
#define KINE_H_INCLUDED
#include <stdio.h>
typedef struct
{
  char D[30];
}Date;

typedef struct
{
  int ID;
  char NOM[20];
  Date DATE[7];
}kine;

void ajouter_kine (kine);
void modifier_kine (kine);
void supprimer_kine(int);
int verif_kine (int);

#endif
