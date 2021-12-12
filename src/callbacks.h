#include <gtk/gtk.h>


void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_femelle_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_arabe_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_francais_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_anglais_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
