#include "treeview.h"


enum
{
	ID_EVENT,
	NOM_EVENT,
	DATE_EVENT,
  COLUMNS_EVENT
};


void afficher_event(GtkWidget *treeview1)
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
	store=gtk_tree_view_get_model(treeview1);
	if (store==NULL)
	{
    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("id", renderer, "text", ID_EVENT, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

    		renderer = gtk_cell_renderer_text_new ();
    		column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text", NOM_EVENT, NULL);
    		gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

        renderer = gtk_cell_renderer_text_new ();
        column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", DATE_EVENT, NULL);
        gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);
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
    gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1), GTK_TREE_MODEL (store));

    g_object_unref (store);
}
