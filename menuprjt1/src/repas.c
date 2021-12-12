#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "repas.h"
#include "callbacks.h"
#include <gtk/gtk.h>
enum{
	
        
	RDATE,
        RID,
	RNOM_REPAS,
	RTYPE,
	RINGREDIENTS,
	RDESSERT,
	RNBR_PERS,
        RAVIS,
        RDECHETS,
	COLUMNS
};
void ajouter_repas(repas r, char *file){
	FILE *f;
	f=fopen(file,"a+");
	if(f!=NULL){
		fprintf(f,"%d %d %d %s %s %s %s %s %d %d %.2f\n",r.d.jour,r.d.mois,r.d.annee,r.id,r.nom_repas,     r.type,r.ingredients,r.dessert,r.nbr_pers,r.avis,r.dechets);
	}
	else
		return;
	fclose(f);
}


void recherche_repas(char id[20], char *file){
	repas r1;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("recherche.txt","a+");
	if(f!=NULL && g!=NULL){
		while(fscanf(f,"%d %d %d %s %s %s %s %s %d %d %f\n",&r1.d.jour,&r1.d.mois,&r1.d.annee,r1.id,r1.nom_repas,     r1.type,r1.ingredients,r1.dessert,&r1.nbr_pers,&r1.avis,&r1.dechets)!=EOF)
		{
			if(strcmp(id,r1.id)==0)
				fprintf(g,"%d %d %d %s %s %s %s %s %d %d %.2f\n",r1.d.jour,r1.d.mois,r1.d.annee,r1.id,r1.nom_repas,r1.type,r1.ingredients,r1.dessert,r1.nbr_pers,r1.avis,r1.dechets);
				
		}
	}
	fclose(f);
	fclose(g);

}

void afficher_repas(GtkWidget *liste, char *file)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	repas r;
	store=NULL;
	gchar date_menu[50], dechets[10], type[20];
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Date",renderer,"text",RDATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",RID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom_repas",renderer,"text",RNOM_REPAS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",RTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Ingredients",renderer,"text",RINGREDIENTS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",RDESSERT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nbr_pers",renderer,"text",RNBR_PERS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Avis",renderer,"text",RAVIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Dechets",renderer,"text",RDECHETS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		 
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_FLOAT);
	f=fopen(file,"r");
	if(f==NULL){return;}
	else
	{
		 while(fscanf(f,"%d %d %d %s %s %s %s %s %d %d %f\n",&r.d.jour,&r.d.mois,&r.d.annee,r.id,r.nom_repas,     r.type,r.ingredients,r.dessert,&r.nbr_pers,&r.avis,&r.dechets)!=EOF)
		 {
sprintf(dechets,"%.2f",r.dechets);
sprintf(date_menu,"%d/%d/%d",r.d.jour,r.d.mois,r.d.annee);

			gtk_list_store_append(store,&iter);
		  	gtk_list_store_set(store,&iter,RDATE,date_menu,RID,r.id,RNOM_REPAS,r.nom_repas,RTYPE,r.type,RINGREDIENTS,r.ingredients,RDESSERT,r.dessert,RNBR_PERS,r.nbr_pers,RAVIS,r.avis,RDECHETS,r.dechets,-1);
		 }
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}
}


void modifier_repas(repas r, char *file){
	repas r1;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL)
	{
		while(fscanf(f,"%d %d %d %s %s %s %s %s %d %d %f\n",&r1.d.jour,&r1.d.mois,&r1.d.annee,r1.id,r1.nom_repas,     r1.type,r1.ingredients,r1.dessert,&r1.nbr_pers,&r1.avis,&r1.dechets)!=EOF)
		{
			if(strcmp(r1.id,r.id)!=0)
				fprintf(g,"%d %d %d %s %s %s %s %s %d %d %.2f\n",r1.d.jour,r1.d.mois,r1.d.annee,r1.id,r1.nom_repas,r1.type,r1.ingredients,r1.dessert,r1.nbr_pers,r1.avis,r1.dechets);
			else
				fprintf(g,"%d %d %d %s %s %s %s %s %d %d %.2f\n",r.d.jour,r.d.mois,r.d.annee,r.id,r.nom_repas,     r.type,r.ingredients,r.dessert,r.nbr_pers,r.avis,r.dechets);		
		}

	
	}

	fclose(f);
	fclose(g);
	remove(file);
	rename("tmp.txt",file);
}
void supprimer_repas(char id[20], char *file){
	repas r;
	FILE *f,*g;
	f=fopen(file,"r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL)
	{
		while(fscanf(f,"%d %d %d %s %s %s %s %s %d %d %f\n",&r.d.jour,&r.d.mois,&r.d.annee,r.id,r.nom_repas,     r.type,r.ingredients,r.dessert,&r.nbr_pers,&r.avis,&r.dechets)!=EOF)
		{
			if(strcmp(id,r.id)!=0)
				fprintf(g,"%d %d %d %s %s %s %s %s %d %d %.2f\n",r.d.jour,r.d.mois,r.d.annee,r.id,r.nom_repas,     r.type,r.ingredients,r.dessert,r.nbr_pers,r.avis,r.dechets);
		}

	
	}
	fclose(f);
	fclose(g);
	remove(file);
	rename("tmp.txt",file);
}

char* meilleur_menu(char *file){
int err, err1, y=0, y1=0, w=0, w1=0;
struct tm tm = { 0 };
repas r1;
char* ch = (char*) malloc(1000);
time_t t;
time(&t);
err = year_week(localtime(&t),&y,&w);
char gl[50], gll[50];
float gd, gdd, min=99999999.00;
FILE *f, *g;
f=fopen(file,"a+");
g=fopen("dump.txt","w+");
if(g!=NULL){
if(f!=NULL)
{	while(fscanf(f,"%d %d %d %s %s %s %s %s %d %d %f\n",&r1.d.jour,&r1.d.mois,&r1.d.annee,r1.id,r1.nom_repas,     r1.type,r1.ingredients,r1.dessert,&r1.nbr_pers,&r1.avis,&r1.dechets)!=EOF){
	tm.tm_year = r1.d.annee - 1900;
	tm.tm_mon = r1.d.mois - 1;
	tm.tm_mday = r1.d.jour;
	tm.tm_isdst = -1;
	err1 = year_week(&tm,&y1,&w1);
	if(w==w1){
        fprintf(g,"%s %.2f\n",r1.nom_repas,r1.dechets);
	}
}
fclose(f);
}
fclose(g);
}
g=fopen("dump.txt","r");
if(g!=NULL){
	while(fscanf(g,"%s %f\n",gl,&gd)!=EOF){
    if(gd<min)
        min=gd;
}
fclose(g);
}
g=fopen("dump.txt","r");
if(g!=NULL){
	while(fscanf(g,"%s %f\n",gll,&gdd)!=EOF){
    if(gdd==min)
        break;
}
fclose(g);
}
sprintf(ch,"Meilleur menu de la semaine : %s",gll);
remove("dump.txt");
return ch;
}

int year_week(const struct tm *tmptr, int *year, int *week) {
  // work with local copy
  struct tm tm = *tmptr;
  // fully populate the yday and wday fields.
  if (mktime(&tm) == -1) {
    return 1;
  }

  // Find day-of-the-week: 0 to 6.
  // Week starts on Monday per ISO 8601
  // 0 <= DayOfTheWeek <= 6, Monday, Tuesday ... Sunday
  int DayOfTheWeek = (tm.tm_wday + (7 - 1)) % 7;

  // Offset the month day to the Monday of the week.
  tm.tm_mday -= DayOfTheWeek;
  // Offset the month day to the mid-week (Thursday) of the week, 3 days later.
  tm.tm_mday += 3;
  // Re-evaluate tm_year and tm_yday  (local time)
  if (mktime(&tm) == -1) {
    return 1;
  }

  *year = tm.tm_year + 1900;
  // Convert yday to week of the year, stating with 1.
  *week = tm.tm_yday / 7 + 1;
  return 0;
}








