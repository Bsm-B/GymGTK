#ifndef EMPLOIMED_H_INCLUDED
#define EMPLOIMED_H_INCLUDED



typedef struct
{
  char JOUR[10];
  char DATE[20];
}jr;


typedef struct
{
    int ID;
    jr  JRMED[7];
}empltmed;

void ajouter_emploimed (empltmed);
void modifier_emploimed (empltmed);
void supprimer_emploimed(int);



#endif
