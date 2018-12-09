#include "profile.h"


void ajouter_profile(prfl p)
{
  FILE *f;
  f=fopen("profile.txt","a+");
  fprintf(f,"%d %s %s %s %s %f %f\n",p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,p.POIDS,p.LONG);
	fclose(f);
}

void supprimer_profile(int id)
{
	prfl p;
	FILE*f;
  FILE*ftemp;
	f=fopen("profile.txt","a+");
	ftemp=fopen("profile.tmp","w");

  while(fscanf(f,"%d %s %s %s %s %f %f\n",&p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,&p.POIDS,&p.LONG) != EOF)
  {
    		if(id != p.ID)
    		{
          fprintf(ftemp,"%d %s %s %s %s %f %f\n",p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,p.POIDS,p.LONG);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("profile.txt");
	rename("profile.tmp","profile.txt");
}
