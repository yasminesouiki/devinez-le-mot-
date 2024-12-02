#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MOTS 5
#define MAX_TENTATIVES 10

void afficherBienvenue() {
    printf("=== Jeu de Deviner le Mot (Lettre par Lettre) ===\n");
    printf("L'ordinateur a choisi un mot dans sa liste.\n");
    printf("Vous devez deviner les lettres une par une.\n");
    printf("Vous avez %d tentatives au total. Bonne chance !\n\n", MAX_TENTATIVES);
}

void afficherEtatMot(char *motCache, int longueurMot) {
    printf("Mot à deviner : ");
    for (int i = 0; i < longueurMot; i++) {
        printf("%c ", motCache[i]);
    }
    printf("\n");
}

int main() {
    
    const char *mots[MAX_MOTS] = {"ordinateur","transport", "programmation","animation", "developpement", "algorithmique",
    "compilation","pays","password","artificial-intelligence","work"};

    srand(time(NULL));

    // Choisir un mot aléatoire
    const char *motSecret = mots[rand() % MAX_MOTS];
    int longueurMot = strlen(motSecret);

   
    char motCache[longueurMot + 1];
    for (int i = 0; i < longueurMot; i++) {
        motCache[i] = '_';
    }
    motCache[longueurMot] = '\0';

    int tentativesRestantes = MAX_TENTATIVES;
    int lettresTrouvees = 0;

    afficherBienvenue();

    while (tentativesRestantes > 0 && lettresTrouvees < longueurMot) {
        afficherEtatMot(motCache, longueurMot);
        printf("Tentatives restantes : %d\n", tentativesRestantes);

       
        char lettre;
        printf("Entrez une lettre : ");
        scanf(" %c", &lettre);

     
        int lettreTrouvee = 0;
        for (int i = 0; i < longueurMot; i++) {
            if (motSecret[i] == lettre && motCache[i] == '_') {
                motCache[i] = lettre;
                lettresTrouvees++;
                lettreTrouvee = 1;
            }
        }

        if (lettreTrouvee) {
            printf("Bonne lettre !\n");
        } else {
            printf("Lettre incorrecte.\n");
            tentativesRestantes--;
        }

        printf("\n");
    }

    // Résultat final
    if (lettresTrouvees == longueurMot) {
        printf("Félicitations ! Vous avez deviné le mot : %s\n", motSecret);
    } else {
        printf("Dommage, vous avez épuisé vos tentatives. Le mot était : %s\n", motSecret);
    }

    printf("Merci d'avoir joué !\n");
    return 0;
}
