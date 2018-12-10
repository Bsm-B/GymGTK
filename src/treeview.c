#include "treeview.h"

//////////////////******************************************//////////////////
enum
{
	ID_EVENT,
	NOM_EVENT,
	DATE_EVENT,
  COLUMNS_EVENT
};


void afficher_event(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  int id;
  char nom[20];
  char date[20];

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_EVENT, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_EVENT, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", DATE_EVENT, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
   }
   store=gtk_list_store_new (COLUMNS_EVENT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
   f = fopen("event.txt", "r");
   if(f ==NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
  		while(fscanf(f,"%d %s %s",&id,nom,date)!=EOF)
  		{
  			gtk_list_store_append (store, &iter);
  			gtk_list_store_set (store, &iter,ID_EVENT,id,NOM_EVENT,nom,DATE_EVENT,date,-1);
  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}
//////////////////******************************************//////////////////
enum
{
	NOM_USER,
	PRENOM_USER,
  ID_USER,
  PASS_USER,
  ROLE_USER,
  COLUMNS_USER
};


void afficher_user(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  char nom[20];
  char prenom[20];
  int id;
  int pass_u;
  int role_u;

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_USER, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", PRENOM_USER, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_USER, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("pass", renderer, "text", PASS_USER, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("role", renderer, "text", ROLE_USER, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
   }
   store=gtk_list_store_new (COLUMNS_USER, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT);
   f = fopen("users.txt", "r");
   if(f == NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
  		while(fscanf(f,"%s %s %d %d %d",nom,prenom,&id,&pass_u,&role_u)!=EOF)
  		{
  			gtk_list_store_append (store, &iter);
gtk_list_store_set (store, &iter,NOM_USER,nom,PRENOM_USER,prenom,ID_USER,id,pass_u,ROLE_USER,role_u,-1);

  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}
////////////////////*******************************************///////////////////////////////////////////

enum
{
  ID_PAY,
  NBMOIS_PAY,
  NOM_PAY,
  DATE_PAY,
  COLUMNS_PAY
};


void afficher_pay(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  int id;
  int nbms;
  char nom[20];
  char date[20];

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_PAY, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("nombre mois", renderer, "text", NBMOIS_PAY, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_PAY, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", DATE_PAY, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
   }
   store=gtk_list_store_new (COLUMNS_PAY, G_TYPE_INT, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);
   f = fopen("paiment.txt", "r");
   if(f == NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
  		while(fscanf(f,"%d %d %s %s",&id,&nbms,nom,date)!=EOF)
  		{
  			gtk_list_store_append (store, &iter);
  			gtk_list_store_set (store, &iter,ID_PAY,id,NBMOIS_PAY,nbms,NOM_PAY,nom,DATE_PAY,date,-1);
  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);

}


/*****************************************************************************************/


enum
{
	ID_COACH,
	NOM_COACH,
	DATE_COATCH1,
	DATE_COATCH2,
	DATE_COATCH3,
	DATE_COATCH4,
	DATE_COATCH5,
	DATE_COATCH6,
	DATE_COATCH7,
  COLUMNS_COACH
};


void afficher_coach(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  int id;
  char nom[20];
  char date1[20];
	char date2[20];
	char date3[20];
	char date4[20];
	char date5[20];
	char date6[20];
	char date7[20];

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_COACH, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_COACH, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Lundi", renderer, "text", DATE_COATCH1, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Mardi", renderer, "text", DATE_COATCH2, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Mercredi", renderer, "text", DATE_COATCH3, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Jeudi", renderer, "text", DATE_COATCH4, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Vendredi", renderer, "text", DATE_COATCH5, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Samedi", renderer, "text", DATE_COATCH6, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Dimanche", renderer, "text", DATE_COATCH7, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
   }
   store=gtk_list_store_new (COLUMNS_COACH, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
   f = fopen("coach.txt", "r");
   if(f ==NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
			while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
	    &id,nom,
	    date1,date2,date3,date4,
	    date5,date6,date7)!=EOF)
  		{

					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter,ID_COACH,id,NOM_COACH,nom,DATE_COATCH1,date1,DATE_COATCH2,date2,
						DATE_COATCH3,date3,DATE_COATCH4,date4,DATE_COATCH5,date5,DATE_COATCH6,date6,DATE_COATCH7,date7,-1);

  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}
/////********************************* MED ****************************///
enum
{
	ID_MED,
	NOM_MED,
	PRENOM_MED,
	EMAIL_MED,
	TEL_MED,
	MALADE_MED,
	POIDS_MED,
	LONG_MED,
  COLUMNS_MED
};


void afficher_medecin(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  int id;
  char nom[20];
  char prenom[20];
	char email[20];
	char tel[20];
	char malade[20];
	float poids;
	float long_med;

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_MED, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_MED, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
				column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", PRENOM_MED, NULL);
				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("email", renderer, "text", EMAIL_MED, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
				column = gtk_tree_view_column_new_with_attributes("tel", renderer, "text", TEL_MED, NULL);
				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


				renderer = gtk_cell_renderer_text_new ();
				column = gtk_tree_view_column_new_with_attributes("malade", renderer, "text", MALADE_MED, NULL);
				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text", POIDS_MED, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("long", renderer, "text", LONG_MED, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


	 }
   store=gtk_list_store_new (COLUMNS_MED, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING ,
	 G_TYPE_FLOAT,G_TYPE_FLOAT);
   f = fopen("fichemed.txt", "r");
   if(f ==NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
			while(fscanf(f,"%d %s %s %s %s %s %f %f \n",&id,nom,prenom,email,
			tel,malade,&poids,&long_med)!=EOF)
  		{
  			gtk_list_store_append (store, &iter);
  			gtk_list_store_set (store, &iter,ID_MED,id,NOM_MED,nom,PRENOM_MED,prenom,EMAIL_MED,email,
					TEL_MED,tel,MALADE_MED,malade,POIDS_MED,poids,LONG_MED,long_med,-1);
  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}
////////////////////***************************************///////////////////////////////

enum
{
	ID_KINE,
	NOM_KINE,
	DATE_KINE1,
	DATE_KINE2,
	DATE_KINE3,
	DATE_KINE4,
	DATE_KINE5,
	DATE_KINE6,
	DATE_KINE7,
  COLUMNS_KINE
};


void afficher_kine(GtkWidget *treeview)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter    iter;
  GtkListStore *store;

  int id;
  char nom[20];
  char date1[20];
	char date2[20];
	char date3[20];
	char date4[20];
	char date5[20];
	char date6[20];
	char date7[20];

	FILE *f;

	store=NULL;

	//creat the colomns if they dont alredy exist
	store=gtk_tree_view_get_model(treeview);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_KINE, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_KINE, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Lundi", renderer, "text", DATE_KINE1, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Mardi", renderer, "text", DATE_KINE2, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Mercredi", renderer, "text",DATE_KINE3, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Jeudi", renderer, "text", DATE_KINE4, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Vendredi", renderer, "text", DATE_KINE5, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Samedi", renderer, "text", DATE_KINE6, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


				renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("Dimanche", renderer, "text", DATE_KINE7, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
   }
   store=gtk_list_store_new (COLUMNS_KINE, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
   f = fopen("kine.txt", "r");
   if(f ==NULL)
 	 {
 		printf("erreur d'ouverture ");
 		return;
 	  }
    else
  	{
			while(fscanf(f,"%d %s Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
	    &id,nom,
	    date1,date2,date3,date4,
	    date5,date6,date7)!=EOF)
  		{

					gtk_list_store_append (store, &iter);
					gtk_list_store_set (store, &iter,ID_KINE,id,NOM_KINE,nom,DATE_KINE1,date1,DATE_KINE2,date2,
						DATE_KINE3,date3,DATE_KINE4,date4,DATE_KINE5,date5,DATE_KINE6,date6,DATE_KINE7,date7,-1);


  		}
      fclose(f);
    }
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

    g_object_unref (store);
}

 ///////////////*******************************************///////



 void afficher_medecin_1(GtkWidget *treeview,int idx)
 {
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter    iter;
   GtkListStore *store;

   int id;
   char nom[20];
   char prenom[20];
 	char email[20];
 	char tel[20];
 	char malade[20];
 	float poids;
 	float long_med;

 	FILE *f;

 	store=NULL;

 	//creat the colomns if they dont alredy exist
 	store=gtk_tree_view_get_model(treeview);
 	if (store==NULL)
 	{
     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_MED, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_MED, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
 				column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text", PRENOM_MED, NULL);
 				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


         renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("email", renderer, "text", EMAIL_MED, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
 				column = gtk_tree_view_column_new_with_attributes("tel", renderer, "text", TEL_MED, NULL);
 				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


 				renderer = gtk_cell_renderer_text_new ();
 				column = gtk_tree_view_column_new_with_attributes("malade", renderer, "text", MALADE_MED, NULL);
 				gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("poids", renderer, "text", POIDS_MED, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("long", renderer, "text", LONG_MED, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


 	 }
    store=gtk_list_store_new (COLUMNS_MED, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING ,
 	 G_TYPE_FLOAT,G_TYPE_FLOAT);
    f = fopen("fichemed.txt", "r");
    if(f ==NULL)
  	 {
  		printf("erreur d'ouverture ");
  		return;
  	  }
     else
   	{
 			while(fscanf(f,"%d %s %s %s %s %s %f %f \n",&id,nom,prenom,email,
 			tel,malade,&poids,&long_med)!=EOF)
   		{
				if(id == idx)
				{
   			gtk_list_store_append (store, &iter);
   			gtk_list_store_set (store, &iter,ID_MED,id,NOM_MED,nom,PRENOM_MED,prenom,EMAIL_MED,email,
 					TEL_MED,tel,MALADE_MED,malade,POIDS_MED,poids,LONG_MED,long_med,-1);
				}
   		}
       fclose(f);
     }
     gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

     g_object_unref (store);
 }
 //////////////////******************************************************////
 void afficher_kine_1(GtkWidget *treeview,int idx)
 {
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter    iter;
   GtkListStore *store;

   int id;
   char nom[20];
   char date1[20];
 	char date2[20];
 	char date3[20];
 	char date4[20];
 	char date5[20];
 	char date6[20];
 	char date7[20];

 	FILE *f;

 	store=NULL;

 	//creat the colomns if they dont alredy exist
 	store=gtk_tree_view_get_model(treeview);
 	if (store==NULL)
 	{
     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_KINE, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_KINE, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

         renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Lundi", renderer, "text", DATE_KINE1, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Mardi", renderer, "text", DATE_KINE2, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Mercredi", renderer, "text",DATE_KINE3, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Jeudi", renderer, "text", DATE_KINE4, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Vendredi", renderer, "text", DATE_KINE5, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Samedi", renderer, "text", DATE_KINE6, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Dimanche", renderer, "text", DATE_KINE7, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
    }
    store=gtk_list_store_new (COLUMNS_KINE, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f = fopen("kine.txt", "r");
    if(f ==NULL)
  	 {
  		printf("erreur d'ouverture ");
  		return;
  	  }
     else
   	{
 			while(fscanf(f,"%d %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
 	    &id,nom,
 	    date1,date2,date3,date4,
 	    date5,date6,date7)!=EOF)
   		{
					if (id == idx){
 					gtk_list_store_append (store, &iter);
 					gtk_list_store_set (store, &iter,ID_KINE,id,NOM_KINE,nom,DATE_KINE1,date1,DATE_KINE2,date2,
 						DATE_KINE3,date3,DATE_KINE4,date4,DATE_KINE5,date5,DATE_KINE6,date6,DATE_KINE7,date7,-1);

						}
   		}
       fclose(f);
     }
     gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));

     g_object_unref (store);
 }





 void afficher_coach_1(GtkWidget *treeview,int idx)
 {
   GtkCellRenderer *renderer;
   GtkTreeViewColumn *column;
   GtkTreeIter    iter;
   GtkListStore *store;

   int id;
   char nom[20];
   char date1[20];
 	char date2[20];
 	char date3[20];
 	char date4[20];
 	char date5[20];
 	char date6[20];
 	char date7[20];
	char date10[20];
 char date20[20];
 char date30[20];
 char date40[20];
 char date50[20];
 char date60[20];
 char date70[20];

 	FILE *f;

 	store=NULL;

 	//creat the colomns if they dont alredy exist
 	store=gtk_tree_view_get_model(treeview);
 	if (store==NULL)
 	{
     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_COACH, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

     		renderer = gtk_cell_renderer_text_new ();
     		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_COACH, NULL);
     		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

         renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Lundi", renderer, "text", DATE_COATCH1, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Mardi", renderer, "text", DATE_COATCH2, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Mercredi", renderer, "text", DATE_COATCH3, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Jeudi", renderer, "text", DATE_COATCH4, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Vendredi", renderer, "text", DATE_COATCH5, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);

 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Samedi", renderer, "text", DATE_COATCH6, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);


 				renderer = gtk_cell_renderer_text_new ();
         column = gtk_tree_view_column_new_with_attributes("Dimanche", renderer, "text", DATE_COATCH7, NULL);
         gtk_tree_view_append_column (GTK_TREE_VIEW (treeview), column);
    }
    store=gtk_list_store_new (COLUMNS_COACH, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    f = fopen("coach.txt", "r");
    if(f ==NULL)
  	 {
  		printf("erreur d'ouverture ");
  		return;
  	  }
     else
   	{
 			while(fscanf(f,"%d Lundi %s Mardi %s Mercredi %s Jeudi %s Vendredi %s Samedi %s Dimanche %s \n",
 	    &id,nom,
 	    date1,date2,date3,date4,
 	    date5,date6,date7)!=EOF)
   		{
					if (id == idx ) {
 					gtk_list_store_append (store, &iter);
 					gtk_list_store_set (store, &iter,ID_COACH,id,NOM_COACH,nom,DATE_COATCH1,date1,DATE_COATCH2,date2,
 						DATE_COATCH3,date3,DATE_COATCH4,date4,DATE_COATCH5,date5,DATE_COATCH6,date6,DATE_COATCH7,date7,-1);

   		}
       fclose(f);
     }
     gtk_tree_view_set_model (GTK_TREE_VIEW (treeview), GTK_TREE_MODEL (store));
     g_object_unref (store);
 }
}
