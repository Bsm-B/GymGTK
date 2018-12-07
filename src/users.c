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

}
