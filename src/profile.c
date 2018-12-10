#include "profile.h"


void ajouter_profile(prfl p)
{
  FILE *f;
  f=fopen("profile.txt","a+");
  fprintf(f,"%d %s %s %s %s %f %f\n",p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,p.POIDS,p.LONG);
	fclose(f);
}



void modifier_profile(prfl tempe)
{
  FILE*f;
	FILE*ftemp;
  prfl p;
	f=fopen("profile.txt","r");
	ftemp=fopen("profile.tmp","w");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s %s %s %s %f %f\n",&p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,&p.POIDS,&p.LONG) != EOF)
			{
    				if(p.ID != tempe.ID){
              fprintf(ftemp,"%d %s %s %s %s %f %f\n",p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,p.POIDS,p.LONG);
		        }else{
              fprintf(ftemp,"%d %s %s %s %s %f %f\n",p.ID,tempe.NOM,tempe.PRENOM,tempe.EMAIL,tempe.TEL,tempe.POIDS,tempe.LONG);
  	        }
			}
			fclose(f);
			fclose(ftemp);
			remove("profile.txt");
			rename("profile.tmp","profile.txt");
	}
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



prfl search(int idx)
{
	prfl p;
	FILE*f;
	f=fopen("profile.txt","r");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s %s %s %s %f %f\n",&p.ID,p.NOM,p.PRENOM,p.EMAIL,p.TEL,&p.POIDS,&p.LONG) != EOF)
		{
      if (p.ID == idx)
			{
				return p;
			}
		}
    p.ID = 0;
    strcpy(p.NOM,"_");
    strcpy(p.PRENOM,"_");
    strcpy(p.EMAIL,"_");
    strcpy(p.TEL,"_");
    p.POIDS = 0;
    p.LONG = 0;

		return p;
	fclose(f);
	}
}
