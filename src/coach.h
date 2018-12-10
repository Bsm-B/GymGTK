#ifndef COACH_H_INCLUDED
#define COACH_H_INCLUDED

#include <stdio.h>

typedef struct
{
  int ID;
  char NOM[20];
  char DATE[7][20];

}coach;

void ajouter_coach(coach);
void modifier_coach(coach);
void supprimer_coach (int);
int verif_coach (int);

#endif
