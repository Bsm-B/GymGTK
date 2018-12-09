#include "fichemed.h"



void ajouter_med(med m)
{
  FILE *f;
  f=fopen("fichemed.txt","a+");
  fprintf(f,"%d %s %s %s %s %s %f %f \n",m.ID,m.NOM,m.PRENOM,m.EMAIL,
  m.TEL,m.MALADE,m.POIDS,m.LONG);
  fclose(f);
}

int verif_med(int idx)
{
	med m;
	FILE*f;
	f=fopen("fichemed.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %s %s %s %s %s %f %f \n",&m.ID,m.NOM,m.PRENOM,m.EMAIL,
    m.TEL,m.MALADE,&m.POIDS,&m.LONG)!=EOF)
		{
      if (m.ID == idx)
			{
				return 1;
			}
		}
		return 0;
	fclose(f);
	}
}


void modifier_med(med tempm)
{
	FILE*f;
	FILE*ftemp;
  med m;
	f=fopen("fichemed.txt","r");
	ftemp=fopen("fichemed.tmp","w");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s %s %s %s %s %f %f \n",&m.ID,m.NOM,m.PRENOM,m.EMAIL,
    m.TEL,m.MALADE,&m.POIDS,&m.LONG)!=EOF)
			{
    				if(m.ID != tempm.ID){
              fprintf(ftemp,"%d %s %s %s %s %s %f %f \n",m.ID,m.NOM,m.PRENOM,m.EMAIL,
              m.TEL,m.MALADE,m.POIDS,m.LONG);
		        }else{
              fprintf(ftemp,"%d %s %s %s %s %s %f %f \n",m.ID,tempm.NOM,tempm.PRENOM,tempm.EMAIL,
              tempm.TEL,tempm.MALADE,tempm.POIDS,tempm.LONG);
  	        }
			}
			fclose(f);
			fclose(ftemp);
			remove("fichemed.txt");
			rename("fichemed.tmp","fichemed.txt");
	}
}



void supprimer_med(int id)
{
	med m;
	FILE*f;
  FILE*ftemp;
  f=fopen("fichemed.txt","r");
	ftemp=fopen("fichemed.tmp","w");

  while(fscanf(f,"%d %s %s %s %s %s %f %f \n",&m.ID,m.NOM,m.PRENOM,m.EMAIL,
  m.TEL,m.MALADE,&m.POIDS,&m.LONG)!=EOF)
    {
    		if(id != m.ID)
    		{
          fprintf(ftemp,"%d %s %s %s %s %s %f %f \n",m.ID,m.NOM,m.PRENOM,m.EMAIL,
          m.TEL,m.MALADE,m.POIDS,m.LONG);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("fichemed.txt");
	rename("fichemed.tmp","fichemed.txt");
}
