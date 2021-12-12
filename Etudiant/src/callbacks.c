#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "Etudiant.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
Etudiant e;
FILE *f=NULL;
GtkWidget *input1,*input2,*input3,*Comboboxclasse,*nombre;
GtkWidget *fenetre_ajouter;

fenetre_ajouter=lookup_widget(objet_graphique,"fenetre_ajouter");

input1=lookup_widget(objet_graphique,"cin");
input2=lookup_widget(objet_graphique,"nom");
input3=lookup_widget(objet_graphique,"prenom");
Comboboxclasse=lookup_widget(objet_graphique,"comboboxclasse");
nombre=lookup_widget(objet_graphique,"nombre");

strcpy(e.CIN,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.Nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.Prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(e.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxclasse)));
e.nombre=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre));


ajouter(e);

}


void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
GtkWidget *fenetre_ajouter;
GtkWidget *treeview1;

fenetre_ajouter=lookup_widget(objet_graphique,"fenetre_ajouter");



gtk_widget_destroy(fenetre_ajouter);
fenetre_afficher=lookup_widget(objet_graphique,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();


gtk_widget_show(fenetre_afficher);


treeview1=lookup_widget(fenetre_afficher,"treeview1");


afficher(treeview1);
}


void
on_calcul_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *output;
Etudiant e;
char text[50]="";
int n;
n=calcul(e);
sprintf(text,"le nombre totale des etudiant en esprit est %d",n);
output=lookup_widget(objet_graphique,"text");
gtk_label_set_text(GTK_LABEL(output),text);
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
    gchar *classe;
    gint *nombre;
    Etudiant e;
   
    GtkTreeModel *model=gtk_tree_view_get_model(treeview);
   
    if (gtk_tree_model_get_iter(model,&iter,path))
    {
          gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&CIN,1,&Nom,2,&Prenom,3,&classe,4,&nombre,-1);
          
          strcpy(e.Nom,Nom);
          strcpy(e.Prenom,Prenom);
          strcpy(e.CIN,CIN);
          strcpy(e.classe,classe);
          e.nombre=nombre;
          afficher(treeview);
    }
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
afficher(treeview1);
}

