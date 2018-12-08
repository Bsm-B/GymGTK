#include "users.h"


usr verifierlogin(int log,int pass)
{
  usr tempuser;
  tempuser.ROLE = 0;
  FILE*f;
  f=fopen("users.txt","r");
  while((fscanf(f,"%s %s %d %d %d \n",tempuser.NOM,tempuser.PRENOM,&tempuser.ID,&tempuser.PASS,&tempuser.ROLE)!=EOF))
  {
    if ( tempuser.ID ==  log &&  tempuser.PASS == pass)    return tempuser;
  }
  tempuser.ROLE = 0; return tempuser;
	fclose(f);
}

void ajouter_user(usr u)
{
	FILE *f1;
  FILE *f2;
	f1=fopen("users.txt","a+");
	fprintf(f1,"%s %s %d %d %d \n",u.NOM,u.PRENOM,u.ID,u.PASS,u.ROLE);
	fclose(f1);
  f2=fopen("profile.txt","a+");
  fprintf(f2,"%s %s %d \n",u.NOM,u.PRENOM,u.ID);
	fclose(f2);
}

int verif_user(int idx)
{
	usr u;
	FILE*f;
	f=fopen("users.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %d %d %d \n",u.NOM,u.PRENOM,&u.ID,&u.PASS,&u.ROLE)!=EOF)
		{
      if (u.ID == idx)
			{
				return 1;
			}

		}
		return 0;
	fclose(f);
	}
}



void modifier_user(usr tempu)
{
	FILE*f;
	FILE*ftemp;
  usr u;
	f=fopen("users.txt","r");
	ftemp=fopen("users.tmp","w");
	if(f!=NULL)
	{
			while(fscanf(f,"%s %s %d %d %d \n",u.NOM,u.PRENOM,&u.ID,&u.PASS,&u.ROLE)!=EOF)
			{
    				if(u.ID != tempu.ID){
    				fprintf(ftemp,"%s %s %d %d %d \n",u.NOM,u.PRENOM,u.ID,u.PASS,u.ROLE);
				   }else{
    				fprintf(ftemp,"%s %s %d %d %d \n",tempu.NOM,tempu.PRENOM,u.ID,tempu.PASS,tempu.ROLE);
    	}
			}
			fclose(f);
			fclose(ftemp);
			remove("users.txt");
			rename("users.tmp","users.txt");
	}

}


void supprimer_user(int id)
{
	usr u;
	FILE*f;
  FILE*ftemp;
	f=fopen("users.txt","a+");
	ftemp=fopen("users.tmp","w");

  while(fscanf(f,"%s %s %d %d %d \n",u.NOM,u.PRENOM,&u.ID,&u.PASS,&u.ROLE)!=EOF)
  {
    		if(id != u.ID)
    		{
			fprintf(ftemp,"%s %s %d %d %d \n",u.NOM,u.PRENOM,u.ID,u.PASS,u.ROLE);
    		}
	}
	fclose(f);
	fclose(ftemp);
	remove("users.txt");
	rename("users.tmp","users.txt");
}
