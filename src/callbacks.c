#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "user.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int x;
int y[3]={0,0,0};
int t;
void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_ajout;
GtkWidget *treeview1;

fenetre_ajout=lookup_widget(objet_graphique,"fenetre_ajout");



gtk_widget_destroy(fenetre_ajout);
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();


gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");


afficher(treeview1,"User.txt");
}


void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cininput;
char CIN[8];
cininput=lookup_widget(objet_graphique,"cin");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(cininput)));
supprimer(CIN);
}


void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
User u;
GtkWidget *CINmod,*Nommod,*Prenommod,*Comboboxentry1mod,*jourmod,*moismod,*anneemod,*Pwmod;

CINmod=lookup_widget(objet_graphique,"cin");
Nommod=lookup_widget(objet_graphique,"nom");
Prenommod=lookup_widget(objet_graphique,"prenom");
Pwmod=lookup_widget(objet_graphique,"pw");
Comboboxentry1mod=lookup_widget(objet_graphique,"comboboxentry1");
jourmod=lookup_widget(objet_graphique,"jour");
moismod=lookup_widget(objet_graphique,"mois");
anneemod=lookup_widget(objet_graphique,"annee");
strcpy(u.CIN,gtk_entry_get_text(GTK_ENTRY(CINmod)));
strcpy(u.Nom,gtk_entry_get_text(GTK_ENTRY(Nommod)));
strcpy(u.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenommod)));
strcpy(u.MotDePasse,gtk_entry_get_text(GTK_ENTRY(Pwmod)));
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxentry1mod)));

u.db.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourmod));
u.db.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moismod));
u.db.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anneemod));
GtkWidget *output;
char text1[100]="genre";
char text2[100]="";
char text3[100]="";
if(x==0)
strcpy(u.sexe,"Monsieur");
else
if(x==1)
strcpy(u.sexe,"Madame");

if(y[0]==1)
strcpy(u.Langues,"arabe");
if(y[1]==1)
strcpy(u.Langues,"francais");
if(y[2]==1)
strcpy(u.Langues,"anglais");


modifier(u);
}


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
User u;
FILE *f=NULL;
GtkWidget *CIN,*Nom,*Prenom,*Comboboxentry1,*jour,*mois,*annee,*Pw;
GtkWidget *fenetre_ajout;

CIN=lookup_widget(objet_graphique,"cin");
Nom=lookup_widget(objet_graphique,"nom");
Prenom=lookup_widget(objet_graphique,"prenom");
Pw=lookup_widget(objet_graphique,"pw");
Comboboxentry1=lookup_widget(objet_graphique,"comboboxentry1");
jour=lookup_widget(objet_graphique,"jour");
mois=lookup_widget(objet_graphique,"mois");
annee=lookup_widget(objet_graphique,"annee");
strcpy(u.CIN,gtk_entry_get_text(GTK_ENTRY(CIN)));
strcpy(u.Nom,gtk_entry_get_text(GTK_ENTRY(Nom)));
strcpy(u.Prenom,gtk_entry_get_text(GTK_ENTRY(Prenom)));
strcpy(u.MotDePasse,gtk_entry_get_text(GTK_ENTRY(Pw)));
strcpy(u.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxentry1)));

u.db.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
u.db.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
u.db.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
GtkWidget *output;
char text1[100]="genre";
char text2[100]="";
char text3[100]="";
if(x==0)
strcpy(u.sexe,"Monsieur");
else
if(x==1)
strcpy(u.sexe,"Madame");

if(y[0]==1)
strcpy(u.Langues,"arabe");
if(y[1]==1)
strcpy(u.Langues,"francais");
if(y[2]==1)
strcpy(u.Langues,"anglais");


ajouter(u);
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
    gchar *Nom;
    gchar *Prenom;
    gchar *CIN;
    gchar *MotDePasse;
    User u;
   
    GtkTreeModel *model=gtk_tree_view_get_model(treeview);
   
    if (gtk_tree_model_get_iter(model,&iter,path))
    {
          gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&Nom,1,&Prenom,2,&CIN,3,&MotDePasse,-1);
          
          strcpy(u.Nom,Nom);
          strcpy(u.Prenom,Prenom);
          strcpy(u.CIN,CIN);
          strcpy(u.MotDePasse,MotDePasse);
           supprimer(CIN);
           afficher(treeview,"User.txt");
    }
}

void
on_chercher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
User u;
char text[55]="";
char CIN[8];
GtkWidget *cininput;
GtkWidget *output;
cininput=lookup_widget(objet_graphique,"cin");
strcpy(CIN,gtk_entry_get_text(GTK_ENTRY(cininput)));
chercher(CIN);
sprintf(text,"le user chercher est %s %s %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,u.db.jour,u.db.mois,u.db.annee,u.Langues,u.type);
output=lookup_widget(objet_graphique,"text");
gtk_label_set_text(GTK_LABEL(output),text);


}

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;

w1=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

gtk_widget_hide(w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");

vider(treeview1);
afficher(treeview1,"User.txt");
}


void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=0;}
}


void
on_femelle_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_arabe_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{y[0]=1;}
}


void
on_francais_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{y[1]=1;}
}


void
on_anglais_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{y[2]=1;}
}



