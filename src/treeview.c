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
   if(f ==NULL)
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
