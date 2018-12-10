#ifndef TREEVIEW_H_INCLUDED
#define TREEVIEW_H_INCLUDED

#include <config.h>

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "event.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afficher_event(GtkWidget *treeview);
void afficher_user(GtkWidget *treeview);
void afficher_pay(GtkWidget *treeview);
void afficher_coach(GtkWidget *treeview);
void afficher_medecin(GtkWidget *treeview);
void afficher_kine(GtkWidget *treeview);
void afficher_medecin_1(GtkWidget *treeview,int idx);

#endif
