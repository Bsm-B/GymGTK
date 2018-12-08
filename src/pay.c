#include "pay.h"
#include "users.h"

void ajouter_paiment(pmt pt)
{
  FILE *f;
  f=fopen("paiment.txt","a+");
  fprintf(f,"%d %d %s %s \n",pt.ID,pt.NBMOIS,pt.NOM,pt.DATE);
  fclose(f);
}

void modifier_paiment(pmt temppt)
{
	FILE*f;
	FILE*ftemp;
  pmt pt;
	f=fopen("paiment.txt","r");
	ftemp=fopen("paiment.tmp","w");
	if(f!=NULL)
	{
			while(fscanf(f,"%d %d %s %s \n",&pt.ID,&pt.NBMOIS,pt.NOM,pt.DATE)!=EOF)
			{
    				if(pt.ID != temppt.ID){
  					  fprintf(ftemp,"%d %d %s %s \n",pt.ID,pt.NBMOIS,pt.NOM,pt.DATE);
		        }else{
              fprintf(ftemp,"%d %d %s %s \n",pt.ID,temppt.NBMOIS,pt.NOM,temppt.DATE);
  	        }
			}
			fclose(f);
			fclose(ftemp);
			remove("paiment.txt");
			rename("paiment.tmp","paiment.txt");
	}
}


void supprimer_paiment(int id)
{
	pmt pt;
	FILE*f;
  FILE*ftemp;
  f=fopen("paiment.txt","r");
	ftemp=fopen("paiment.tmp","w");

  while(fscanf(f,"%d %d %s %s \n",&pt.ID,&pt.NBMOIS,pt.NOM,pt.DATE)!=EOF)
  {
    		if(id != pt.ID)
    		{
        fprintf(ftemp,"%d %d %s %s \n",pt.ID,pt.NBMOIS,pt.NOM,pt.DATE);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("paiment.txt");
	rename("paiment.tmp","paiment.txt");
}



void accedernom(int idx,char nom[])
{
usr u;
FILE *f;
strcpy(nom,"Le client n'existe pas");
f=fopen("users.txt","r");
    if(f!=NULL)
      {
        while(fscanf(f,"%s %s %d %d %d \n",u.NOM,u.PRENOM,&u.ID,&u.PASS,&u.ROLE)!=EOF)
  {
    if (u.ID == idx)
    {
      sprintf(nom,"%s %s",u.NOM,u.PRENOM);
    }
  }
fclose(f);
}
}
