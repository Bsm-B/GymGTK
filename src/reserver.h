#ifndef RESERVER_H_INCLUDED
#define RESERVER_H_INCLUDED



typedef struct{
  int ID;
  char NOM_prof[30];
  char DATE[30];
}reserv;


void ajouter_reserve(reserv r);




#endif
