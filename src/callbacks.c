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
    GtkWidget *Login = lookup_widget(button,"Login");;
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
      case 0:
      gtk_label_set_text(GTK_LABEL(error),"id ou mot passe sont incorrect");
      break;

      case 1:
      Admin = create_Admin();
      gtk_widget_destroy(Login);
      gtk_widget_show(Admin);
      break;
    }

}
