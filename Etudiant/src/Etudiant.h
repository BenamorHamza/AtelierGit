#ifndef PROJETTEST_H_INCLUDED
#define PROJETTEST_H_INCLUDED
#include <gtk/gtk.h>


#endif // PROJETTEST_H_INCLUDED





typedef struct etudiant
{
    char Nom[100];
    char Prenom[100];
    char CIN[8];
    char classe[7];
    int  nombre;

} Etudiant;

void ajouter(Etudiant e);
void afficher(GtkWidget *liste);
void vider(GtkWidget *liste);
int calcul(Etudiant e);
