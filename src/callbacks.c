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
#include "pay.h"
#include "fichemed.h"
#include "emploimed.h"
#include "kine.h"
#include "coach.h"
#include "treeview.h"
#include "reserver.h"

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
    char nom[40];
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
      GtkWidget *output = lookup_widget(GTK_WIDGET(Dector),"ID");
      gtk_label_set_text(GTK_LABEL(output),user_txt);
      break;

      case 3:
      Coach = create_Coach();
      gtk_widget_destroy(Login);
      gtk_widget_show(Coach);
      GtkWidget *output3 = lookup_widget(GTK_WIDGET(Coach),"ID");
      gtk_label_set_text(GTK_LABEL(output3),user_txt);
      accedernom(atoi(user_txt),nom);
      GtkWidget *output4 = lookup_widget(GTK_WIDGET(Coach),"Nom");
      gtk_label_set_text(GTK_LABEL(output4),nom);

      break;

      case 4:
      kine = create_kine();
      gtk_widget_destroy(Login);
      gtk_widget_show(kine);
      GtkWidget *output1 = lookup_widget(GTK_WIDGET(kine),"ID");
      gtk_label_set_text(GTK_LABEL(output1),user_txt);
      accedernom(atoi(user_txt),nom);
      GtkWidget *output2 = lookup_widget(GTK_WIDGET(kine),"Nom");
      gtk_label_set_text(GTK_LABEL(output2),nom);


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
      GtkWidget *output5 = lookup_widget(GTK_WIDGET(User),"ID");
      gtk_label_set_text(GTK_LABEL(output5),user_txt);
      prfl p;
      char x1[20],x2[20];
      p = search(atoi(user_txt));
      sprintf(x1,"%f",p.POIDS);
      sprintf(x2,"%f",p.LONG);
      GtkWidget *output6 = lookup_widget(GTK_WIDGET(User),"label311");
      gtk_label_set_text(GTK_LABEL(output6),p.NOM);
      GtkWidget *output7 = lookup_widget(GTK_WIDGET(User),"label312");
      gtk_label_set_text(GTK_LABEL(output7),p.PRENOM);
      GtkWidget *output8 = lookup_widget(GTK_WIDGET(User),"label315");
      gtk_label_set_text(GTK_LABEL(output8),p.EMAIL);
      GtkWidget *output9 = lookup_widget(GTK_WIDGET(User),"label316");
      gtk_label_set_text(GTK_LABEL(output9),p.TEL);
      GtkWidget *output11 = lookup_widget(GTK_WIDGET(User),"label319");
      gtk_label_set_text(GTK_LABEL(output11),x1);
      GtkWidget *output12 = lookup_widget(GTK_WIDGET(User),"label320");
      gtk_label_set_text(GTK_LABEL(output12),x2);

      break;

      default:
      gtk_label_set_text(GTK_LABEL(error),"id ou mot passe sont incorrect !!");
      break;
    }
}
/*************************ADMIN CONTROL PANEL************************/


//////////////////////////////////// CRUD USER /////////////////////////////
void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
  ////////////////////////////////ADD USER //////////////////////////////////
  usr u;
  int test;
  char temp[20];
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
  else if (strcmp(temp,"Nutritionniste") == 0 )  u.ROLE = 2;
  else if (strcmp(temp,"Coach") == 0 )    u.ROLE = 3;
  else if (strcmp(temp,"Kine") == 0 )     u.ROLE = 4;
  else if (strcmp(temp,"Financier") == 0 ) u.ROLE = 5;
  else if (strcmp(temp,"Adherent") == 0 )   u.ROLE = 6;

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


void
on_Search_clicked                      (GtkWidget       *button,
                                        gpointer         user_data)
{
  prfl p;
  char x1[20],x2[20];
  GtkWidget *searchid = lookup_widget(GTK_WIDGET(button),"entry145");
  int id =  atoi(gtk_entry_get_text(GTK_ENTRY(searchid)));
  p = search(id);
  sprintf(x1,"%f",p.POIDS);
  sprintf(x2,"%f",p.LONG);
  GtkWidget *output6 = lookup_widget(GTK_WIDGET(button),"nom");
  gtk_label_set_text(GTK_LABEL(output6),p.NOM);
  GtkWidget *output7 = lookup_widget(GTK_WIDGET(button),"prenom");
  gtk_label_set_text(GTK_LABEL(output7),p.PRENOM);
  GtkWidget *output8 = lookup_widget(GTK_WIDGET(button),"Email");
  gtk_label_set_text(GTK_LABEL(output8),p.EMAIL);
  GtkWidget *output9 = lookup_widget(GTK_WIDGET(button),"Tel");
  gtk_label_set_text(GTK_LABEL(output9),p.TEL);
  GtkWidget *output11 = lookup_widget(GTK_WIDGET(button),"Poids");
  gtk_label_set_text(GTK_LABEL(output11),x1);
  GtkWidget *output12 = lookup_widget(GTK_WIDGET(button),"Long");
  gtk_label_set_text(GTK_LABEL(output12),x2);
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
/*************************PAYMENT CONTROL PANEL************************/

void
on_entry90_changed                     (GtkWidget     *editable,
                                      gpointer         user_data)
{
  //////////////////////////// ADD PAY ///////////////////////////////
  char nom[40];
  int ID;
  GtkWidget *input1 = lookup_widget(editable,"entry90");
  GtkWidget *output1 = lookup_widget(editable,"entry92");
  ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  accedernom(ID,nom);
  gtk_entry_set_text(GTK_ENTRY(output1),nom);
}


void
on_button29_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  pmt pt;
  int j,m,a;
  char nom[40];
  GtkWidget *output1 = lookup_widget(button,"msgp");
  GtkWidget *input1 = lookup_widget(button,"entry90");
  pt.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget * nbrmois = lookup_widget(button,"spinbutton8");
  pt.NBMOIS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nbrmois));
  GtkWidget * jour = lookup_widget(button, "spinbutton9");
  j = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
  GtkWidget * mois = lookup_widget(button, "spinbutton10");
  m = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
  GtkWidget * annee = lookup_widget(button, "spinbutton11");
  a = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
  sprintf(pt.DATE,"%d/%d/%d",j,m,a);
  GtkWidget *inputnom = lookup_widget(button,"entry92");
  strcpy(pt.NOM,gtk_entry_get_text(GTK_ENTRY(inputnom)));
  if(strcmp(pt.NOM,"Le client n'existe pas") == 0 || verif_paiment(pt.ID) == 1){
    gtk_label_set_text(GTK_LABEL(output1),"Error");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Paiement Ajouté");
      ajouter_paiment(pt);
  }


}
///////////////////////// UPDATE PAY ///////////////////////////
void
on_entry91_changed                     (GtkWidget     *editable,
                                        gpointer         user_data)
{
  char nom[40];
  int ID;
  GtkWidget *input1 = lookup_widget(editable,"entry91");
  GtkWidget *output1 = lookup_widget(editable,"entry93");
  ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  accedernom(ID,nom);
  gtk_entry_set_text(GTK_ENTRY(output1),nom);
}


void
on_button28_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  pmt pt;
  int j,m,a;
  char nom[40];
  GtkWidget *output1 = lookup_widget(button,"msgp");
  GtkWidget *input1 = lookup_widget(button,"entry91");
  pt.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget * nbrmois = lookup_widget(button,"spinbutton12");
  pt.NBMOIS = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (nbrmois));
  GtkWidget * jour = lookup_widget(button, "spinbutton13");
  j = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (jour));
  GtkWidget * mois = lookup_widget(button, "spinbutton14");
  m = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (mois));
  GtkWidget * annee = lookup_widget(button, "spinbutton15");
  a = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (annee));
  sprintf(pt.DATE,"%d/%d/%d",j,m,a);
  GtkWidget *inputnom = lookup_widget(button,"entry93");
  strcpy(pt.NOM,gtk_entry_get_text(GTK_ENTRY(inputnom)));
  if(strcmp(pt.NOM,"Le client n'existe pas") == 0 ||verif_paiment(pt.ID) == 0 ){
    gtk_label_set_text(GTK_LABEL(output1),"Error");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Paiement Modifié");
      modifier_paiment(pt);
  }

}

void
on_entry94_changed                     (GtkWidget     *editable,
                                        gpointer         user_data)
{
  char nom[40];
  int ID;
  GtkWidget *input1 = lookup_widget(editable,"entry94");
  GtkWidget *output1 = lookup_widget(editable,"entry95");
  ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  accedernom(ID,nom);
  gtk_entry_set_text(GTK_ENTRY(output1),nom);
}


void
on_button30_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  pmt pt;
  int ID;
  GtkWidget *output1 = lookup_widget(button,"msgp");
  GtkWidget *input1 = lookup_widget(button,"entry94");
  ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  if (verif_paiment(ID) == 1 ){
      supprimer_paiment(ID);
      gtk_label_set_text(GTK_LABEL(output1),"Paiement supprimé");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");

  }
}

/*************************DECTOR CONTROL PANEL************************/
void
on_button18_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

   /**************** ADD ****************/
  med m;
  int test1,test2;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"entry96");
  m.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry18");
  strcpy(m.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry19");
  strcpy(m.PRENOM,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry20");
  strcpy(m.EMAIL,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry22");
  strcpy(m.TEL,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *comboinput1 = lookup_widget(button, "comboboxentry15");
  strcpy(m.MALADE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboinput1)));
  GtkWidget *input6 = lookup_widget(button,"entry21");
  m.POIDS = atof(gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry23");
  m.LONG = atof(gtk_entry_get_text(GTK_ENTRY(input7)));
  test1  = verif_user(m.ID);
  test2 = verif_med(m.ID);
  if (test1 == 1 && test2 == 0){
    ajouter_med(m);
    gtk_label_set_text(GTK_LABEL(output1),"ficher Ajouté");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
  }


}


void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
   /******************** update ******************/
  med m;
  int test;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"entry97");
  m.ID = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry24");
  strcpy(m.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry25");
  strcpy(m.PRENOM,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry26");
  strcpy(m.EMAIL,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry28");
  strcpy(m.TEL,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *comboinput1 = lookup_widget(button, "comboboxentry36");
  strcpy(m.MALADE,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboinput1)));
  GtkWidget *input6 = lookup_widget(button,"entry27");
  m.POIDS = atof(gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry29");
  m.LONG = atof(gtk_entry_get_text(GTK_ENTRY(input7)));
  test = verif_med(m.ID);
  if (test == 1){
    modifier_med(m);
    gtk_label_set_text(GTK_LABEL(output1),"ficher modifié");

  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");

  }
}


void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{

   ///////////////***********************Delect ******/
  int test,id;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"entry30");
  id = atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
  test = verif_med(id);
  if (test == 1){
    supprimer_med(id);
    gtk_label_set_text(GTK_LABEL(output1),"ficher supprime");
  }else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
  }
}

void
on_button31_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
empltmed em;
GtkWidget *output1 = lookup_widget(button,"msg");
GtkWidget *input1 = lookup_widget(button,"ID");
em.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
strcpy(em.JRMED[0].JOUR,"Lundi");
strcpy(em.JRMED[1].JOUR,"Mardi");
strcpy(em.JRMED[2].JOUR,"Mercredi");
strcpy(em.JRMED[3].JOUR,"Jeudi");
strcpy(em.JRMED[4].JOUR,"Vendredi");
strcpy(em.JRMED[5].JOUR,"Samedi");
strcpy(em.JRMED[6].JOUR,"Dimanche");
GtkWidget *input2 = lookup_widget(button,"entry61");
strcpy(em.JRMED[0].DATE,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3 = lookup_widget(button,"entry62");
strcpy(em.JRMED[1].DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
GtkWidget *input4 = lookup_widget(button,"entry65");
strcpy(em.JRMED[2].DATE,gtk_entry_get_text(GTK_ENTRY(input4)));
GtkWidget *input5 = lookup_widget(button,"entry67");
strcpy(em.JRMED[3].DATE,gtk_entry_get_text(GTK_ENTRY(input5)));
GtkWidget *input6 = lookup_widget(button,"entry63");
strcpy(em.JRMED[4].DATE,gtk_entry_get_text(GTK_ENTRY(input6)));
GtkWidget *input7 = lookup_widget(button,"entry64");
strcpy(em.JRMED[5].DATE,gtk_entry_get_text(GTK_ENTRY(input7)));
GtkWidget *input8 = lookup_widget(button,"entry66");
strcpy(em.JRMED[6].DATE,gtk_entry_get_text(GTK_ENTRY(input8)));
if (verif_evmploimed(em.ID) == 0){
    ajouter_emploimed(em);
    gtk_label_set_text(GTK_LABEL(output1),"Emploit Ajouté");
}else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
}

}

void
on_button39_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  empltmed em;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  em.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  strcpy(em.JRMED[0].JOUR,"Lundi");
  strcpy(em.JRMED[1].JOUR,"Mardi");
  strcpy(em.JRMED[2].JOUR,"Mercredi");
  strcpy(em.JRMED[3].JOUR,"Jeudi");
  strcpy(em.JRMED[4].JOUR,"Vendredi");
  strcpy(em.JRMED[5].JOUR,"Samedi");
  strcpy(em.JRMED[6].JOUR,"Dimanche");
  GtkWidget *input2 = lookup_widget(button,"entry98");
  strcpy(em.JRMED[0].DATE,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry99");
  strcpy(em.JRMED[1].DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry102");
  strcpy(em.JRMED[2].DATE,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry104");
  strcpy(em.JRMED[3].DATE,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry100");
  strcpy(em.JRMED[4].DATE,gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry101");
  strcpy(em.JRMED[5].DATE,gtk_entry_get_text(GTK_ENTRY(input7)));
  GtkWidget *input8 = lookup_widget(button,"entry103");
  strcpy(em.JRMED[6].DATE,gtk_entry_get_text(GTK_ENTRY(input8)));
  if (verif_evmploimed(em.ID) == 1){
      modifier_emploimed(em);
      gtk_label_set_text(GTK_LABEL(output1),"Emploit Modifié");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Error");
  }

}

void
on_button33_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  int id;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  id = atoi(gtk_label_get_text(GTK_LABEL(input1)));

if (verif_evmploimed(id) == 1 ){
    supprimer_emploimed(id);
    gtk_label_set_text(GTK_LABEL(output1),"Emploit Suprrimer");
}else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
}

}

void
on_button40_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  kine k;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  k.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input9 = lookup_widget(button,"Nom");
  strcpy(k.NOM,gtk_label_get_text(GTK_LABEL(input9)));
  GtkWidget *input2 = lookup_widget(button,"entry105");
  strcpy(k.DATE[0].D,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry106");
  strcpy(k.DATE[1].D,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry109");
  strcpy(k.DATE[2].D,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry111");
  strcpy(k.DATE[3].D,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry107");
  strcpy(k.DATE[4].D,gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry108");
  strcpy(k.DATE[5].D,gtk_entry_get_text(GTK_ENTRY(input7)));
  GtkWidget *input8 = lookup_widget(button,"entry110");
  strcpy(k.DATE[6].D,gtk_entry_get_text(GTK_ENTRY(input8)));

  if (verif_kine(k.ID) == 0){
      ajouter_kine(k);
      gtk_label_set_text(GTK_LABEL(output1),"Emploit Ajouté");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Error");
  }
}


void
on_button41_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  kine k;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  k.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input9 = lookup_widget(button,"Nom");
  strcpy(k.NOM,gtk_label_get_text(GTK_LABEL(input9)));
  GtkWidget *input2 = lookup_widget(button,"entry112");
  strcpy(k.DATE[0].D,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry113");
  strcpy(k.DATE[1].D,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry116");
  strcpy(k.DATE[2].D,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry118");
  strcpy(k.DATE[3].D,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry114");
  strcpy(k.DATE[4].D,gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry115");
  strcpy(k.DATE[5].D,gtk_entry_get_text(GTK_ENTRY(input7)));
  GtkWidget *input8 = lookup_widget(button,"entry117");
  strcpy(k.DATE[6].D,gtk_entry_get_text(GTK_ENTRY(input8)));

  if (verif_kine(k.ID) == 1){
      modifier_kine(k);
      gtk_label_set_text(GTK_LABEL(output1),"Emploit Modifié");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Error");
  }
}

void
on_button38_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  int id;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  id = atoi(gtk_label_get_text(GTK_LABEL(input1)));

if (verif_kine(id) == 1 ){
    supprimer_kine(id);
    gtk_label_set_text(GTK_LABEL(output1),"Emploit Suprrimer");
}else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
}
}

void
on_button42_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  coach c;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  c.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input9 = lookup_widget(button,"Nom");
  strcpy(c.NOM,gtk_label_get_text(GTK_LABEL(input9)));
  GtkWidget *input2 = lookup_widget(button,"entry125");
  strcpy(c.DATE[0],gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry126");
  strcpy(c.DATE[1],gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry129");
  strcpy(c.DATE[2],gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry131");
  strcpy(c.DATE[3],gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry127");
  strcpy(c.DATE[4],gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry128");
  strcpy(c.DATE[5],gtk_entry_get_text(GTK_ENTRY(input7)));
  GtkWidget *input8 = lookup_widget(button,"entry130");
  strcpy(c.DATE[6],gtk_entry_get_text(GTK_ENTRY(input8)));

  if (verif_coach(c.ID) == 0){
      ajouter_coach(c);
      gtk_label_set_text(GTK_LABEL(output1),"Emploit Ajouté");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Error");
  }
}


void
on_button43_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  coach c;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  c.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));


  GtkWidget *input9 = lookup_widget(button,"Nom");
  strcpy(c.NOM,gtk_label_get_text(GTK_LABEL(input9)));
  GtkWidget *input2 = lookup_widget(button,"entry132");
  strcpy(c.DATE[0],gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry133");
  strcpy(c.DATE[1],gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry136");
  strcpy(c.DATE[2],gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry138");
  strcpy(c.DATE[3],gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry134");
  strcpy(c.DATE[4],gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry135");
  strcpy(c.DATE[5],gtk_entry_get_text(GTK_ENTRY(input7)));
  GtkWidget *input8 = lookup_widget(button,"entry137");
  strcpy(c.DATE[6],gtk_entry_get_text(GTK_ENTRY(input8)));


  if (verif_coach(c.ID) == 1){
      modifier_coach(c);
      gtk_label_set_text(GTK_LABEL(output1),"Emploit modifié");
  }else{
      gtk_label_set_text(GTK_LABEL(output1),"Error");
  }
}


void
on_button44_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  int id;
  GtkWidget *output1 = lookup_widget(button,"msg");
  GtkWidget *input1 = lookup_widget(button,"ID");
  id = atoi(gtk_label_get_text(GTK_LABEL(input1)));

if (verif_coach(id) == 1 ){
    supprimer_coach(id);
    gtk_label_set_text(GTK_LABEL(output1),"Emploit Suprrimé");
}else{
    gtk_label_set_text(GTK_LABEL(output1),"Error");
}

}
 //////////////////////// UPDATE PROFILE /////////////////////
void
on_button27_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  prfl p;
  GtkWidget *input1 = lookup_widget(button,"ID");
  p.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry47");
  strcpy(p.NOM,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry48");
  strcpy(p.PRENOM,gtk_entry_get_text(GTK_ENTRY(input3)));
  GtkWidget *input4 = lookup_widget(button,"entry49");
  strcpy(p.EMAIL,gtk_entry_get_text(GTK_ENTRY(input4)));
  GtkWidget *input5 = lookup_widget(button,"entry51");
  strcpy(p.TEL,gtk_entry_get_text(GTK_ENTRY(input5)));
  GtkWidget *input6 = lookup_widget(button,"entry50");
  p.POIDS = atof(gtk_entry_get_text(GTK_ENTRY(input6)));
  GtkWidget *input7 = lookup_widget(button,"entry52");
  p.LONG = atof(gtk_entry_get_text(GTK_ENTRY(input7)));
  modifier_profile(p);
  /////////////////////////////////////
  prfl p2;
  char x1[20],x2[20];
  p2 = search(p.ID);
  sprintf(x1,"%f",p2.POIDS);
  sprintf(x2,"%f",p2.LONG);
  GtkWidget *output6 = lookup_widget(GTK_WIDGET(button),"label311");
  gtk_label_set_text(GTK_LABEL(output6),p2.NOM);
  GtkWidget *output7 = lookup_widget(GTK_WIDGET(button),"label312");
  gtk_label_set_text(GTK_LABEL(output7),p2.PRENOM);
  GtkWidget *output8 = lookup_widget(GTK_WIDGET(button),"label315");
  gtk_label_set_text(GTK_LABEL(output8),p2.EMAIL);
  GtkWidget *output9 = lookup_widget(GTK_WIDGET(button),"label316");
  gtk_label_set_text(GTK_LABEL(output9),p2.TEL);
  GtkWidget *output11 = lookup_widget(GTK_WIDGET(button),"label319");
  gtk_label_set_text(GTK_LABEL(output11),x1);
  GtkWidget *output12 = lookup_widget(GTK_WIDGET(button),"label320");
  gtk_label_set_text(GTK_LABEL(output12),x2);
}
//////////////////////////// AFFICHER /////////////////////////////////////
void
on_button45_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *aff1 = lookup_widget(GTK_WIDGET(button),"treeview4");
  afficher_event(aff1);
}

void
on_button46_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview5");
  afficher_user(aff);
}

void
on_button47_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview16");
  afficher_pay(aff);
}

void
on_button48_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 = lookup_widget(button,"ID");
  int id = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview7");
  afficher_medecin_1(aff,id);
}

void
on_button49_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 = lookup_widget(button,"ID");
  int id = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview14");
  afficher_medecin_1(aff,id);

  GtkWidget *aff2 = lookup_widget(GTK_WIDGET(button),"treeview9");
  afficher_medecin(aff2);

}

void
on_button52_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 = lookup_widget(button,"ID");
  int id = atoi(gtk_label_get_text(GTK_LABEL(input1)));
GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview11");
afficher_medecin_1(aff,id);
}


void
on_button50_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview10");
  afficher_event(aff);
}


void
on_button53_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *aff1 = lookup_widget(GTK_WIDGET(button),"treeview17");
  afficher_coach(aff1);
  GtkWidget *aff2 = lookup_widget(GTK_WIDGET(button),"treeview18");
  afficher_medecin(aff2);
  GtkWidget *aff3 = lookup_widget(GTK_WIDGET(button),"treeview19");
  afficher_kine(aff3);
}

void
on_button54_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *input1 = lookup_widget(button,"ID");
  int id = atoi(gtk_label_get_text(GTK_LABEL(input1)));
 GtkWidget *aff = lookup_widget(GTK_WIDGET(button),"treeview15");
  afficher_kine_1(aff,id);
}

void
on_button24_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
reserv r;
GtkWidget *input1 = lookup_widget(button,"ID");
r.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
GtkWidget *input2 = lookup_widget(button,"entry139");
strcpy(r.NOM_prof,gtk_entry_get_text(GTK_ENTRY(input2)));
GtkWidget *input3 = lookup_widget(button,"entry140");
strcpy(r.DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
ajouter_reserve(r);

}


void
on_button25_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  reserv r;
  GtkWidget *input1 = lookup_widget(button,"ID");
  r.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry141");
  strcpy(r.NOM_prof,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry142");
  strcpy(r.DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
  ajouter_reserve(r);
}


void
on_button26_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
  reserv r;
  GtkWidget *input1 = lookup_widget(button,"ID");
  r.ID = atoi(gtk_label_get_text(GTK_LABEL(input1)));
  GtkWidget *input2 = lookup_widget(button,"entry143");
  strcpy(r.NOM_prof,gtk_entry_get_text(GTK_ENTRY(input2)));
  GtkWidget *input3 = lookup_widget(button,"entry144");
  strcpy(r.DATE,gtk_entry_get_text(GTK_ENTRY(input3)));
  ajouter_reserve(r);
}
