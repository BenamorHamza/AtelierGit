#ifdef HAVE_CONFIG_H
#include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Etudiant.h"
#include <gtk/gtk.h>
enum { ECIN,
       ENOM,
       EPRENOM,
       ECLASSE,
       ENOMBRE,
       COLUMNS,
     };

void ajouter(Etudiant e)
{
   FILE *f=NULL;
    f=fopen("Etudiant.txt","a");
if(f!=NULL)
{
    fprintf(f,"%s %s %s %s %d \n",e.CIN,e.Nom,e.Prenom,e.classe,e.nombre);
    fclose(f);
}
}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter ;
GtkListStore *store;

    char Nom[100];
    char Prenom[100];
    char CIN[8];
   
    char classe[7];
    int  nombre;

Etudiant e;
store=NULL;
FILE *f=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
 {


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",ECLASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nombre",renderer,"text",ENOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



 }

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);

f=fopen("Etudiant.txt","r");
if(f==NULL)
  {
  return;
  }
else
  {
   while(fscanf(f,"%s %s %s %s %d \n",e.CIN,e.Nom,e.Prenom,e.classe,&e.nombre)!=EOF)
    {
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ECIN,e.CIN,ENOM,e.Nom,EPRENOM,e.Prenom,ECLASSE,e.classe,ENOMBRE,e.nombre,-1);                                                  
    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
  }
}



void vider(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter ;
GtkListStore *store;

    char Nom[100];
    char Prenom[100];
    char CIN[8];
    char classe[7];
    int  nombre;

Etudiant e;
store=NULL;
FILE *f=NULL;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
 {


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",ECIN,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("classe",renderer,"text",ECLASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("nombre",renderer,"text",ENOMBRE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



 }
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store)); 
}


int calcul(Etudiant e)
{
int nb=0;
FILE *f=NULL;
f=fopen("Etudiant.txt","r");
while(fscanf(f,"%s %s %s %s %d \n",e.CIN,e.Nom,e.Prenom,e.classe,&e.nombre)!=EOF)
{
 nb=nb+e.nombre;
}
fclose(f);
return(nb);
}















