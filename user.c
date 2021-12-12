#ifdef HAVE_CONFIG_H
#include <config.h>
#endif


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include <gtk/gtk.h>
enum { ECIN,
       ENOM,
       EPRENOM,
       EMOTDEPASSE,
       ESEXE,
       EJOUR,
       EMOIS,
       EANNEE,
       ELANGUES,
       ETYPE,
       COLUMNS,
     };


void ajouter(User u)
{
   FILE *f=NULL;
    f=fopen("User.txt","a");
if(f!=NULL)
{
    fprintf(f,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,u.db.jour,u.db.mois,u.db.annee,u.Langues,u.type);
    fclose(f);
}
}
void afficher(GtkWidget *liste,char ficher[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter ;
GtkListStore *store;

    char Nom[100];
    char Prenom[100];
    char CIN[8];
    char MotDePasse[20];
    char sexe[20];
    Datebloc db;
    char Langues[20];
    char type[20];

User u;
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
column=gtk_tree_view_column_new_with_attributes("MotDePasse",renderer,"text",EMOTDEPASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Langues",renderer,"text",ELANGUES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);





 }

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("User.txt","r");
if(f==NULL)
  {
  return;
  }
else
  {
   while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,&u.db.jour,&u.db.mois,&u.db.annee,u.Langues,u.type)!=EOF)
    {
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ECIN,u.CIN,ENOM,u.Nom,EPRENOM,u.Prenom,EMOTDEPASSE,u.MotDePasse,ESEXE,u.sexe,EJOUR,u.db.jour,EMOIS,u.db.mois,EANNEE,u.db.annee,ELANGUES,u.Langues,ETYPE,u.type,-1);                                                  
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
User u;
    char Nom[100];
    char Prenom[100];
    char CIN[8];
    char MotDePasse[20];
    char sexe[20];
    Datebloc db;
    char Langues[20];
    char type[20];

store=NULL;
FILE *f;
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
column=gtk_tree_view_column_new_with_attributes("MotDePasse",renderer,"text",EMOTDEPASSE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



column=gtk_tree_view_column_new_with_attributes("Langues",renderer,"text",ELANGUES,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",ETYPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

 }
store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store)); 
}

void modifier(User u)
{
FILE *f1,*f2;
    User b;
    f1=fopen("User.txt","r");
    f2=fopen("temp.txt","a+");
    
if (f1!=NULL && f2!=NULL)
{
while(fscanf(f1,"%s %s %s %s %s %d %d %d %s %s \n",b.CIN,b.Nom,b.Prenom,b.MotDePasse,b.sexe,&b.db.jour,&b.db.mois,&b.db.annee,b.Langues,b.type)!=EOF)
{  if(strcmp(b.CIN,u.CIN)!=0)
      fprintf(f2,"%s %s %s %s %s %d %d %d %s %s \n",b.CIN,b.Nom,b.Prenom,b.MotDePasse,b.sexe,b.db.jour,b.db.mois,b.db.annee,b.Langues,b.type);
    else
     fprintf(f2,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,u.db.jour,u.db.mois,u.db.annee,u.Langues,u.type);
}
  
}
fclose(f1);
fclose(f2);
remove("User.txt");
rename("temp.txt","User.txt");
}

void supprimer(char CIN[])
{

    User u;
    FILE *f1=NULL;
    FILE *f2=NULL;
    f1 =fopen("User.txt","r");
    f2=fopen("temp.txt","a");
    while (fscanf(f1,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,&u.db.jour,&u.db.mois,&u.db.annee,u.Langues,u.type)!=EOF)
    {
        if(strcmp(CIN,u.CIN)!=0)
            fprintf(f2,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,u.db.jour,u.db.mois,u.db.annee,u.Langues,u.type);
    }
    fclose(f1);
    fclose(f2);
    remove("User.txt");
    rename("temp.txt","User.txt");

}

void chercher(char CIN[8])
{   
    FILE *f=NULL;
    FILE *g=NULL;
    User u;
    f=fopen("User.txt","r");
    g=fopen("chercher.txt","a+");
    while (fscanf(f,"%s %s %s %s %s %d %d %d %s %s \n",u.CIN,u.Nom,u.Prenom,u.MotDePasse,u.sexe,&u.db.jour,&u.db.mois,&u.db.annee,u.Langues,u.type)!=EOF)
    {
        if (strcmp(CIN,u.CIN)==0)
        {
            fprintf(g,"------Information Sur le User :--------    \n \n");
            fprintf(g,"Cin :%s \n",u.CIN);
            fprintf(g,"Nom :%s \n",u.Nom);
            fprintf(g,"Prenom :%s \n",u.Prenom);
            fprintf(g,"mot de passe :%s \n",u.MotDePasse);
            fprintf(g,"sexe :%s \n",u.sexe);
            fprintf(g,"jour :%d \n",u.db.jour);
            fprintf(g,"mois :%d \n",u.db.mois);
            fprintf(g,"annee :%d \n",u.db.annee);
            fprintf(g,"Cin :%s \n",u.Langues);
            fprintf(g,"Nom :%s \n",u.type);
        }
    }
    
    fclose(f);
    fclose(g);

}
















