#include "event.h"


void ajouter_event(event e)
{
	FILE *f;
	f=fopen("event.txt","a+");
	fprintf(f,"%d %s %s \n",e.ID,e.NOM,e.DATE);
	fclose(f);
}

int verif_event(int idx)
{
	event e;
	FILE*f;
	f=fopen("event.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%d %s %s \n",&e.ID,e.NOM,e.DATE)!=EOF)
		{
      if (e.ID == idx)
			{
				return 1;
			}
		}
		return 0;
	fclose(f);
	}
}


void modifier_event(event tempe)
{
	FILE*f;
	FILE*ftemp;
  event e;
	f=fopen("event.txt","r");
	ftemp=fopen("event.tmp","w");
	if(f!=NULL)
	{
			while(fscanf(f,"%d %s %s \n",&e.ID,e.NOM,e.DATE)!=EOF)
			{
    				if(e.ID != tempe.ID){
    					fprintf(ftemp,"%d %s %s \n",e.ID,e.NOM,e.DATE);
		        }else{
    					fprintf(ftemp,"%d %s %s \n",e.ID,tempe.NOM,tempe.DATE);
  	        }
			}
			fclose(f);
			fclose(ftemp);
			remove("event.txt");
			rename("event.tmp","event.txt");
	}
}


void supprimer_event(int id)
{
	event e;
	FILE*f;
  FILE*ftemp;
  f=fopen("event.txt","r");
	ftemp=fopen("event.tmp","w");

  while(fscanf(f,"%d %s %s \n",&e.ID,e.NOM,e.DATE)!=EOF)
  {
    		if(id != e.ID)
    		{
			fprintf(ftemp,"%d %s %s \n",e.ID,e.NOM,e.DATE);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("event.txt");
	rename("event.tmp","event.txt");
}
