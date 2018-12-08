#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "users.h"
#include "event.h"
#include "profile.h"

void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *user  = lookup_widget(button,"user");
    GtkWidget *pwd   = lookup_widget(button,"pwd");
    GtkWidget *error = lookup_widget(button,"msg");
    GtkWidget *Login = lookup_widget(button,"Login");
    GtkWidget *Admin;
    GtkWidget *Paiment;
    GtkWidget *kine;
    GtkWidget *Coach;
    GtkWidget *Dector;
    GtkWidget *User;
    char user_txt[30];
    char pass_txt[30];
    usr u;
    strcpy(user_txt,gtk_entry_get_text(GTK_ENTRY(user)));
    strcpy(pass_txt,gtk_entry_get_text(GTK_ENTRY(pwd)));
    ///////////////////////////////////////////////////
    u = verifierlogin(atoi(user_txt),atoi(pass_txt));
    switch (u.ROLE) {
      case 1:
      Admin = create_Admin();
      gtk_widget_destroy(Login);
      gtk_widget_show(Admin);
      break;

      case 2:
      Dector = create_Dector();
      gtk_widget_destroy(Login);
      gtk_widget_show(Dector);
      break;

      case 3:
      Coach = create_Coach();
      gtk_widget_destroy(Login);
      gtk_widget_show(Coach);
      break;

      case 4:
      kine = create_kine();
      gtk_widget_destroy(Login);
      gtk_widget_show(kine);
      break;

      case 5:
      Paiment = create_Paiment();
      gtk_widget_destroy(Login);
      gtk_widget_show(Paiment);
      break;

      case 6:
      User = create_User();
      gtk_widget_destroy(Login);
      gtk_widget_show(User);
      break;

      default:
      gtk_label_set_text(GTK_LABEL(error),"id ou mot passe sont incorrect");
      break;
    }
}
/////////////////////////////////ADMIN CONTROL PANEL///////////////////////


//////////////////////////////////// CRUD USER /////////////////////////////
void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  ////////////////////////////////ADD USER //////////////////////////////////
  usr u;
  int test;
  char temp[10];
  GtkWidget *output1 = lookup_widget(button,"msgerror");
  GtkWidget *input1 = lookup_widget(button,"entry84");
  u.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry4");
  strcpy(u.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry85");
  strcpy(u.PRENOM,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry5");
  u.PASS = atoi(gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *comboinput1 = lookup_widget(button, "comboboxentry1");
  strcpy(temp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboinput1)));
  if (strcmp(temp,"Admin") == 0 ) u.ROLE = 1;
  else if (strcmp(temp,"Docteur") == 0 )  u.ROLE = 2;
  else if (strcmp(temp,"Coach") == 0 )    u.ROLE = 3;
  else if (strcmp(temp,"Kine") == 0 )     u.ROLE = 4;
  else if (strcmp(temp,"Contable") == 0 ) u.ROLE = 5;
  else if (strcmp(temp,"Client") == 0 )   u.ROLE = 6;
  else u.ROLE = -1; // Error
  test = verif_user(u.ID);
  if (test == 0 &&  u.ROLE != -1 ){
  ajouter_user(u);
  gtk_label_set_text(GTK_LABEL(output1)," Utilisatuer ajouté");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error: ID exist !");
  }


}

void
on_button3_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  ////////////////////////////////UPDATE USER //////////////////////////////////

  usr u;
  int test;
  char temp[10];
  GtkWidget *output1 = lookup_widget(button,"msgerror");
  GtkWidget *input1 = lookup_widget(button,"entry86");
  u.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry6");
  strcpy(u.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry87");
  strcpy(u.PRENOM,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry7");
  u.PASS = atoi(gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *comboinput1 = lookup_widget(button, "comboboxentry2");
  strcpy(temp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboinput1)));
  if (strcmp(temp,"Admin") == 0 ) u.ROLE = 1;
  else if (strcmp(temp,"Docteur") == 0 )  u.ROLE = 2;
  else if (strcmp(temp,"Coach") == 0 )    u.ROLE = 3;
  else if (strcmp(temp,"Kine") == 0 )     u.ROLE = 4;
  else if (strcmp(temp,"Contable") == 0 ) u.ROLE = 5;
  else if (strcmp(temp,"Client") == 0 )   u.ROLE = 6;
  else u.ROLE = -1; // Error
  test = verif_user(u.ID);
  if (test == 1 &&  u.ROLE != -1 ){
    modifier_user(u);
    gtk_label_set_text(GTK_LABEL(output1)," Utilisatuer modifié");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error: ID non exist !");
  }

}

void
on_button4_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  ////////////////////////////////DELET USER //////////////////////////////////

    int ID;
    int test;
    GtkWidget *input1 = lookup_widget(button,"entry8");
    ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
    GtkWidget *output1 = lookup_widget(button,"msgerror");
    test = verif_user(ID);
    if (test == 1 )
    {
      supprimer_user(ID);
      gtk_label_set_text(GTK_LABEL(output1)," Utilisatuer Supprimé");
    }else {
      gtk_label_set_text(GTK_LABEL(output1),"Error: ID non exist !");
    }
}
/////////////////////////CRUD EVENT ////////////////////////////////////
void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  //////////////////////////// ADD EVENT ////////////////////////////
  event e;
  int test;
  GtkWidget *output1 = lookup_widget(button,"msgerror");
  GtkWidget *input1 = lookup_widget(button,"entry88");
  e.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry9");
  strcpy(e.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry10");
  strcpy(e.DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
  test = verif_event(e.ID);
  if (test == 0 ){
    ajouter_event(e);
    gtk_label_set_text(GTK_LABEL(output1)," Evenement ajouté");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error: ID Evenement exist!");
  }
}


void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  ///////////////////////// UPDATE EVENT ///////////////////////
  event e;
  int test;
  GtkWidget *output1 = lookup_widget(button,"msgerror");
  GtkWidget *input1 = lookup_widget(button,"entry89");
  e.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry11");
  strcpy(e.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry12");
  strcpy(e.DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
  test = verif_event(e.ID);
  if (test == 1 ){
    modifier_event(e);
    gtk_label_set_text(GTK_LABEL(output1)," Evenement modifié");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error: ID Evenement non exist!");
  }

}


void
on_button7_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
    ///////////////////////// DELET EVENT ///////////////////////
      int ID;
      int test;
      GtkWidget *input1 = lookup_widget(button,"entry13");
      ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
      GtkWidget *output1 = lookup_widget(button,"msgerror");
      test = verif_event(ID);
      if (test == 1 )
      {
        supprimer_event(ID);
        gtk_label_set_text(GTK_LABEL(output1),"Evenement Supprimé");
      }else {
        gtk_label_set_text(GTK_LABEL(output1),"Error: ID Evenement non exist !");
      }
}
