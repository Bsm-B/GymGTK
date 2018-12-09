#include "emploimed.h"

void ajouter_emploimed (empltmed em)
{
  FILE *f;
  f=fopen("emploimed.txt","a+");
  fprintf(f,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",em.ID,
  em.JRMED[0].JOUR,em.JRMED[0].DATE,
  em.JRMED[1].JOUR,em.JRMED[1].DATE,
  em.JRMED[2].JOUR,em.JRMED[2].DATE,
  em.JRMED[3].JOUR,em.JRMED[3].DATE,
  em.JRMED[4].JOUR,em.JRMED[4].DATE,
  em.JRMED[5].JOUR,em.JRMED[5].DATE,
  em.JRMED[6].JOUR,em.JRMED[6].DATE);
  fclose(f);
}


void modifier_emploimed (empltmed tmpem)
{
	FILE*f;
	FILE*ftemp;
  empltmed em;
	f=fopen("emploimed.txt","r");
	ftemp=fopen("emploimed.tmp","w");
	if(f!=NULL)
	{
			while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",&em.ID,
      em.JRMED[0].JOUR,em.JRMED[0].DATE,
      em.JRMED[1].JOUR,em.JRMED[1].DATE,
      em.JRMED[2].JOUR,em.JRMED[2].DATE,
      em.JRMED[3].JOUR,em.JRMED[3].DATE,
      em.JRMED[4].JOUR,em.JRMED[4].DATE,
      em.JRMED[5].JOUR,em.JRMED[5].DATE,
      em.JRMED[6].JOUR,em.JRMED[6].DATE)!=EOF)
			{
    				if(em.ID != tmpem.ID){
    					fprintf(ftemp,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",em.ID,
              em.JRMED[0].JOUR,em.JRMED[0].DATE,
              em.JRMED[1].JOUR,em.JRMED[1].DATE,
              em.JRMED[2].JOUR,em.JRMED[2].DATE,
              em.JRMED[3].JOUR,em.JRMED[3].DATE,
              em.JRMED[4].JOUR,em.JRMED[4].DATE,
              em.JRMED[5].JOUR,em.JRMED[5].DATE,
              em.JRMED[6].JOUR,em.JRMED[6].DATE);
		        }else{
              fprintf(ftemp,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",em.ID,
              tmpem.JRMED[0].JOUR,tmpem.JRMED[0].DATE,
              tmpem.JRMED[1].JOUR,tmpem.JRMED[1].DATE,
              tmpem.JRMED[2].JOUR,tmpem.JRMED[2].DATE,
              tmpem.JRMED[3].JOUR,tmpem.JRMED[3].DATE,
              tmpem.JRMED[4].JOUR,tmpem.JRMED[4].DATE,
              tmpem.JRMED[5].JOUR,tmpem.JRMED[5].DATE,
              tmpem.JRMED[6].JOUR,tmpem.JRMED[6].DATE);
  	        }
			}
			fclose(f);
			fclose(ftemp);
			remove("emploimed.txt");
			rename("emploimed.tmp","emploimed.txt");
	}
}
void supprimer_emploimed(int id)
{
  empltmed em;
	FILE*f;
  FILE*ftemp;
  f=fopen("emploimed.txt","r");
	ftemp=fopen("emploimed.tmp","w");

  while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",&em.ID,
  em.JRMED[0].JOUR,em.JRMED[0].DATE,
  em.JRMED[1].JOUR,em.JRMED[1].DATE,
  em.JRMED[2].JOUR,em.JRMED[2].DATE,
  em.JRMED[3].JOUR,em.JRMED[3].DATE,
  em.JRMED[4].JOUR,em.JRMED[4].DATE,
  em.JRMED[5].JOUR,em.JRMED[5].DATE,
  em.JRMED[6].JOUR,em.JRMED[6].DATE)!=EOF)
  {
    		if(id != em.ID)
    		{
          fprintf(ftemp,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",em.ID,
          em.JRMED[0].JOUR,em.JRMED[0].DATE,
          em.JRMED[1].JOUR,em.JRMED[1].DATE,
          em.JRMED[2].JOUR,em.JRMED[2].DATE,
          em.JRMED[3].JOUR,em.JRMED[3].DATE,
          em.JRMED[4].JOUR,em.JRMED[4].DATE,
          em.JRMED[5].JOUR,em.JRMED[5].DATE,
          em.JRMED[6].JOUR,em.JRMED[6].DATE);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("emploimed.txt");
	rename("emploimed.tmp","emploimed.txt");
}

int verif_evmploimed(int idx)
{
	empltmed em;
	FILE*f;
	f=fopen("emploimed.txt","r");
	if(f!=NULL)
	{
    while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",&em.ID,
    em.JRMED[0].JOUR,em.JRMED[0].DATE,
    em.JRMED[1].JOUR,em.JRMED[1].DATE,
    em.JRMED[2].JOUR,em.JRMED[2].DATE,
    em.JRMED[3].JOUR,em.JRMED[3].DATE,
    em.JRMED[4].JOUR,em.JRMED[4].DATE,
    em.JRMED[5].JOUR,em.JRMED[5].DATE,
    em.JRMED[6].JOUR,em.JRMED[6].DATE)!=EOF)
		{
      if (em.ID == idx)
			{
				return 1;
			}
		}
		return 0;
	fclose(f);
	}
}
