#ifndef PROJETTEST_H_INCLUDED
#define PROJETTEST_H_INCLUDED
#include <gtk/gtk.h>


#endif // PROJETTEST_H_INCLUDED
typedef struct 
{
int jour;
int mois;
int annee;
}Datebloc;

typedef struct user
{
    char Nom[100];
    char Prenom[100];
    char  CIN[8];
    char sexe[20];
    char MotDePasse[20];
    Datebloc db;
    char Langues[20];
    char type[20];

} User;


void ajouter(User u);
void afficher(GtkWidget *liste,char fichier[]);
void vider(GtkWidget *liste);
void modifier(User u);
void supprimer(char CIN[8]);
void chercher(char CIN[8]);

