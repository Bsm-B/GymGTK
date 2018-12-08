#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <stdio.h>

struct Event
{
    int ID;
    char NOM[20];
    char DATE[20];

};
typedef struct Event event;

void ajouter_event(event);
int verif_event(int);
void modifier_event(event);
void supprimer_event(int id);


#endif //EVENT_H_INCLUDED
