#include <gtk/gtk.h>


void
on_radiobuttonPetitDej_repas_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonDej_repas_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonDiner_repas_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonMauvais_repas_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonPassable_repas_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonExcellent_repas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonajouter_repas_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonmodifier_repas_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonafficher_repas_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonrecherche_repas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongotoajouter_repas_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttongo_to_modifier_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonsupprimer_repas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_meilleur_menu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
