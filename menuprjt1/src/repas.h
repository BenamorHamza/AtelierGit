#include <gtk/gtk.h>
typedef struct{
	int jour;
	int mois;
	int annee;
}date;
typedef struct{
	char id[20];
        char nom_repas[20];
	char dessert[20];
	char ingredients[50];
	date d;
	char type[20];
        int nbr_pers;
        float dechets;
	int avis;
        
	
}repas;
void ajouter_repas(repas r, char *file);
void afficher_repas(GtkWidget *liste, char *file);
void recherche_repas(char id[20], char *file);
void modifier_repas(repas r, char *file);
void supprimer_repas(char id[20], char *file);
char* meilleur_menu(char *file);
int year_week(const struct tm *tmptr, int *year, int *week);
