#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "users.h"

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
//////////////////////////////////////ADMIN CONTROL PANEL///////////////////////
void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  usr u;
  int test;
  char temp[10];
  GtkWidget *output1 = lookup_widget(button,"msgerror");
  gtk_label_set_text(GTK_LABEL(output1),"Output");
  GtkWidget *input1 = lookup_widget(button,"entry84");
  u.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry4");
  strcpy(u.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry85");
  strcpy(u.PRENOM,gtk_entry_get_text(GTK_ENTRY(input2)));
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
    gtk_label_set_text(GTK_LABEL(output1),"Votre Utilisatuer ajouté");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error: ID exicte !");
  }
  //gtk_label_set_text(GTK_LABEL(output1),"");


}
