#ifndef PROFILE_H_INCLUDED
#define PROFILE_H_INCLUDED

#include <stdio.h>

struct Profile
{
    int ID;
    char NOM[20];
    char PRENOM[20];
    char EMAIL[30];
    char TEL[8];
    float POIDS;
    float LONG;
};
typedef struct Profile prfl;

void ajouter_profile(prfl);
void modifier_profile(prfl);
void supprimer_profile(int);


#endif //PROFILE_H_INCLUDED
