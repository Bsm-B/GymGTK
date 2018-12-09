#include "kine.h"



void ajouter_kine (kine k)
{
  FILE *f;
  f=fopen("kine.txt","a+");
  fprintf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
  k.ID,k.NOM,
  k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,k.DATE[4].D,k.DATE[5].D,k.DATE[6].D);
  fclose(f);
}


void modifier_kine(kine tempk)
{
	FILE*f;
	FILE *ftemp;
  kine k;
	f=fopen("kine.txt","r");
	ftemp = fopen("kine.tmp","w");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
    &k.ID,k.NOM,
    k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,
    k.DATE[4].D,k.DATE[5].D,k.DATE[6].D)!=EOF)
			{
    				if(k.ID != tempk.ID){
              fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
              k.ID,k.NOM,
              k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,k.DATE[4].D,k.DATE[5].D,k.DATE[6].D);
		        }else{
              fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
              k.ID,tempk.NOM,
              tempk.DATE[0].D,tempk.DATE[1].D,tempk.DATE[2].D,tempk.DATE[3].D,tempk.DATE[4].D,tempk.DATE[5].D,tempk.DATE[6].D);
			        }
      }
			fclose(f);
			fclose(ftemp);
			remove("kine.txt");
			rename("kine.tmp","kine.txt");
	}
}



void supprimer_kine(int id)
{

  kine k;
	FILE*f;
  FILE*ftemp;
  f=fopen("kine.txt","r");
	ftemp=fopen("kine.tmp","w");

  while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
  &k.ID,k.NOM,
  k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,
  k.DATE[4].D,k.DATE[5].D,k.DATE[6].D)!=EOF)
  {
    		if(id != k.ID)
    		{
          fprintf(ftemp,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
          k.ID,k.NOM,
          k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,
          k.DATE[4].D,k.DATE[5].D,k.DATE[6].D);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("kine.txt");
	rename("kine.tmp","kine.txt");
}


int verif_kine(int idx)
{
	kine k;
	FILE*f;
	f=fopen("kine.txt","r");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
    &k.ID,k.NOM,
    k.DATE[0].D,k.DATE[1].D,k.DATE[2].D,k.DATE[3].D,
    k.DATE[4].D,k.DATE[5].D,k.DATE[6].D)!=EOF)
		{
      if (k.ID == idx)
			{
				return 1;
			}
		}
		return 0;
	fclose(f);
}
}
