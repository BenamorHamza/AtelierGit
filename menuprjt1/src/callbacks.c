#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "repas.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"

int x;
int y;
void
on_radiobuttonPetitDej_repas_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=0;
}


void
on_radiobuttonDej_repas_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=1;
}


void
on_radiobuttonDiner_repas_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=2;
}


void
on_checkbuttonMauvais_repas_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=0;
}


void
on_checkbuttonPassable_repas_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=1;
}


void
on_checkbuttonExcellent_repas_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=2;
}


void
on_buttonajouter_repas_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
repas r;
	GtkWidget *id,*nom_repas,*dessert,*ingredients,*nbr_pers,*dechets;
	GtkCalendar *calendar1;
	guint day, month, year;
	id=lookup_widget(objet_graphique,"entry_id_repas");
	nom_repas=lookup_widget(objet_graphique,"entry_nom_repas");
	ingredients=lookup_widget(objet_graphique,"entry_ingreds_repas");
	dessert=lookup_widget(objet_graphique,"comboboxdessert_repas");
	dechets=lookup_widget(objet_graphique,"entry_dechets");
	calendar1=lookup_widget(objet_graphique,"calendar1");
	nbr_pers=lookup_widget(objet_graphique,"spinbutton_nbr_pers");
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(r.nom_repas,gtk_entry_get_text(GTK_ENTRY(nom_repas)));
	strcpy(r.ingredients,gtk_entry_get_text(GTK_ENTRY(ingredients)));
	r.dechets=atof(gtk_entry_get_text(GTK_ENTRY(dechets)));
	r.nbr_pers=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbr_pers));
	gtk_calendar_get_date(GTK_CALENDAR(calendar1), &day, &month, &year);
r.d.jour=year;
r.d.mois=month+1;
r.d.annee=day;
	if(strcmp("pomme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"pomme");

	else if(strcmp("banane",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"banane");

        else if(strcmp("clémentine",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"clémentine");
        
        else if(strcmp("poire",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"poire");

        else if(strcmp("pêche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"pêche");
        
        else if(strcmp("raisin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"raisin");

        else if(strcmp("orange",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"orange");
        
        else if(strcmp("yaourt",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"yaourt");

        else if(strcmp("tarte",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"tarte");


        else
		strcpy(r.type,"gâteau");
if(x==0)
  strcpy(r.type,"Petit_Dejeuner");
else if(x==1)
  strcpy(r.type,"Dejeuner");
else if(x==2)
  strcpy(r.type,"Diner");


r.avis=y;
	ajouter_repas(r,"menu.txt");
}


void
on_buttonmodifier_repas_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
repas r;
	GtkWidget *id,*nom_repas,*dessert,*ingredients,*nbr_pers,*dechets;
	GtkCalendar *calendar1;
	guint day, month, year;
	id=lookup_widget(objet_graphique,"entry_id_repas");
	nom_repas=lookup_widget(objet_graphique,"entry_nom_repas");
	ingredients=lookup_widget(objet_graphique,"entry_ingreds_repas");
	dessert=lookup_widget(objet_graphique,"comboboxdessert_repas");
	dechets=lookup_widget(objet_graphique,"entry_dechets");
	calendar1=lookup_widget(objet_graphique,"calendar1");
	nbr_pers=lookup_widget(objet_graphique,"spinbutton_nbr_pers");
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(r.nom_repas,gtk_entry_get_text(GTK_ENTRY(nom_repas)));
	strcpy(r.ingredients,gtk_entry_get_text(GTK_ENTRY(ingredients)));
	r.dechets=atof(gtk_entry_get_text(GTK_ENTRY(dechets)));
	r.nbr_pers=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nbr_pers));
	gtk_calendar_get_date(GTK_CALENDAR(calendar1), &day, &month, &year);
r.d.jour=year;
r.d.mois=month+1;
r.d.annee=day;
	if(strcmp("pomme",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"pomme");

	else if(strcmp("banane",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"banane");

        else if(strcmp("clémentine",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"clémentine");
        
        else if(strcmp("poire",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"poire");

        else if(strcmp("pêche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"pêche");
        
        else if(strcmp("raisin",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"raisin");

        else if(strcmp("orange",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"orange");
        
        else if(strcmp("yaourt",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"yaourt");

        else if(strcmp("tarte",gtk_combo_box_get_active_text(GTK_COMBO_BOX(dessert)))==0)
		strcpy(r.dessert,"tarte");


        else
		strcpy(r.type,"gâteau");
if(x==0)
  strcpy(r.type,"Petit_Dejeuner");
else if(x==1)
  strcpy(r.type,"Dejeuner");
else if(x==2)
  strcpy(r.type,"Diner");


r.avis=y;	
	modifier_repas(r,"menu.txt");
}


void
on_buttonafficher_repas_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_repas,*ajout_modif_affich_repas,*treeview_repas;
	gestion_repas=lookup_widget(objet_graphique,"gestion_repas");
	ajout_modif_affich_repas=lookup_widget(objet_graphique,"ajout_modif_affich_repas");
	gtk_widget_destroy(ajout_modif_affich_repas);
	gestion_repas=create_gestion_repas();
	gtk_widget_show(gestion_repas);
	treeview_repas=lookup_widget(gestion_repas,"treeview_repas");
	afficher_repas(treeview_repas,"menu.txt");
}


void
on_buttonrecherche_repas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*treeview_repas;
	char id1[20];
	id=lookup_widget(objet_graphique,"entryrecherche_repas");
	treeview_repas=lookup_widget(objet_graphique,"treeview_repas");
	strcpy(id1,gtk_entry_get_text(GTK_ENTRY(id)));
	if(strcmp(id1,"")!=0)
	{
		recherche_repas(id1,"menu.txt");
		afficher_repas(treeview_repas,"recherche.txt");
		remove("recherche.txt");
	}
	else
		afficher_repas(treeview_repas,"menu.txt");
}


void
on_buttongotoajouter_repas_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *gestion_repas,*ajout_modif_affich_repas,*treeview_repas;
	gestion_repas=lookup_widget(objet_graphique,"gestion_repas");
	ajout_modif_affich_repas=lookup_widget(objet_graphique,"ajout_modif_affich_repas");
	gtk_widget_destroy(gestion_repas);
	ajout_modif_affich_repas=create_ajout_modif_affich_repas();
	gtk_widget_show(ajout_modif_affich_repas);
}


void
on_buttongo_to_modifier_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout_modif_affich_repas,*gestion_repas;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	char ch[20];
        gchar *id;
	gchar *nom_repas;
	gchar *ingredients;
	gint nbr_pers;
	gfloat dechets;
	gchar *type;
	gchar *dessert;
	gchar *date;
	gint avis;
	gestion_repas=lookup_widget(objet_graphique,"gestion_repas");
        treeview=lookup_widget(gestion_repas,"treeview_repas");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&date,1,&id,2,&nom_repas,3,&type,4,&ingredients,5,&dessert,6,&nbr_pers,7,&avis,8,&dechets,-1);
		gtk_widget_destroy(gestion_repas);
		ajout_modif_affich_repas=lookup_widget(objet_graphique,"ajout_modif_affich_repas");
		ajout_modif_affich_repas=create_ajout_modif_affich_repas();
		gtk_widget_show(ajout_modif_affich_repas);
	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(ajout_modif_affich_repas,"entry_id_repas")),id);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(ajout_modif_affich_repas,"entry_nom_repas")),nom_repas);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(ajout_modif_affich_repas,"entry_ingreds_repas")),ingredients);
sprintf(ch,"%.2f",dechets);	gtk_entry_set_text(GTK_ENTRY(lookup_widget(ajout_modif_affich_repas,"entry_dechets")),ch);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(ajout_modif_affich_repas,"spinbutton_nbr_pers")),nbr_pers);
		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(ajout_modif_affich_repas,"comboboxdessert_repas")),dessert);
		
              }
}


void
on_buttonsupprimer_repas_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajout_modif_affich_repas,*gestion_repas;
	GtkTreeModel  *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget *treeview;
	
	
        gchar *id;
	
	gestion_repas=lookup_widget(objet_graphique,"gestion_repas");
        treeview=lookup_widget(gestion_repas,"treeview_repas");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,1,&id,-1);
		supprimer_repas(id,"menu.txt");
		afficher_repas(treeview,"menu.txt");
		
	}
}


void
on_meilleur_menu_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *b, *pInfo;
char str[1000], ch[1000]="";
strcpy(ch,meilleur_menu("menu.txt"));
b=lookup_widget(objet_graphique,"meilleur_menu");
sprintf(str,"%s",ch);
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

