#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

#include <stdio.h>

struct User
{
    char NOM[20];
    char PRENOM[20];
    int ID;
    int PASS;
    int ROLE;
};
typedef struct User usr;

usr verifierlogin(int log,int pass);
void ajouter_user(usr);
int verif_user(int);
void modifier_user(usr tempu);
void supprimer_user(int id);



#endif //USERS_H_INCLUDED
