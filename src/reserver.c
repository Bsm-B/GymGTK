#include "reserver.h"

#include <stdio.h>


void ajouter_reserve(reserv r)
{
  FILE *f;
	f=fopen("reserver.txt","a+");
	fprintf(f,"%d %s %s \n",r.ID,r.NOM_prof,r.DATE);
	fclose(f);
}
