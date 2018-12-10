#include "coach.h"


void ajouter_coach(coach c)
{
  FILE *f;
  f=fopen("coach.txt","a+");
  fprintf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
  c.ID,c.NOM,
  c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],c.DATE[4],c.DATE[5],c.DATE[6]);
  fclose(f);
}



void modifier_coach(coach tempc)
{
	FILE*f;
	FILE *ftemp;
  coach c;
	f=fopen("coach.txt","r");
	ftemp = fopen("coach.tmp","w");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
    &c.ID,c.NOM,
    c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],
    c.DATE[4],c.DATE[5],c.DATE[6])!=EOF)
			{
    				if(c.ID != tempc.ID){
              fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
              c.ID,c.NOM,
              c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],c.DATE[4],c.DATE[5],c.DATE[6]);
		        }else{
              fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
              c.ID,tempc.NOM,
              tempc.DATE[0],tempc.DATE[1],tempc.DATE[2],tempc.DATE[3],tempc.DATE[4],tempc.DATE[5],tempc.DATE[6]);
			        }
      }
			fclose(f);
			fclose(ftemp);
			remove("coach.txt");
			rename("coach.tmp","coach.txt");
	}
}


int verif_coach(int idx)
{
	coach c;
	FILE*f;
	f=fopen("coach.txt","r");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
    &c.ID,c.NOM,
    c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],
    c.DATE[4],c.DATE[5],c.DATE[6])!=EOF)
		{
      if (c.ID == idx)
			{
				return 1;
			}
		}
		return 0;
	fclose(f);
}
}


void supprimer_coach(int id)
{

  coach c;
	FILE*f;
  FILE*ftemp;
  f=fopen("coach.txt","r");
	ftemp=fopen("coach.tmp","w");

  while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
  &c.ID,c.NOM,
  c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],
  c.DATE[4],c.DATE[5],c.DATE[6])!=EOF)
  {
    		if(id != c.ID)
    		{
          fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
          c.ID,c.NOM,
          c.DATE[0],c.DATE[1],c.DATE[2],c.DATE[3],
          c.DATE[4],c.DATE[5],c.DATE[6]);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("coach.txt");
	rename("coach.tmp","coach.txt");
}
