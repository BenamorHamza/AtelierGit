#include <gtk/gtk.h>


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_calcul_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
