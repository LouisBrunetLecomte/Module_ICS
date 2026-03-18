#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Définition de la taille de la matrice (côte) et de sa longueur (surface totale)
#define MAT_COTE 10
#define MAT_LENGTH MAT_COTE*MAT_COTE
#define NB_POINTS 23 // définit le nombre de points noirs dans la matrice

/**
 * @brief Alloue de la mémoire pour une nouvelle matrice et la remplit avec des valeurs aléatoires.
 * 
 * @return int* Un pointeur vers la matrice nouvellement créée.
 */
int* newMatrice() {
    srand(time(NULL)); // Initialise le générateur de nombres aléatoires
    // Alloue mémoire pour la matrice (MAT_LENGTH + 1 pour la sécurité)
    int* mat = malloc(sizeof(int)*MAT_LENGTH + 1);
    // Remplit la matrice avec des 0 et 1, où 1 apparaît avec une probabilité de 1 sur 4
    for (int i = 0; i < MAT_LENGTH; i++) {
        mat[i] = 0;
    }
    int count = 0;
    int randomIndex;
    while (count < NB_POINTS) {
        randomIndex = rand() % MAT_LENGTH + rand() % MAT_COTE;
        if(mat[randomIndex] != 1) { // si ce n'est pas déjà à 1, on a rajouté un point noir.
            mat[randomIndex] = 1;
            count++; // on ajoute 1 au nombre total de 1 actuellement dans la matrice.
        }
    }
    return mat; // Retourne le pointeur vers la matrice
}

/**
 * @brief Affiche la matrice sous forme graphique dans la console.
 * 
 * @param mat Un pointeur vers la matrice à afficher.
 */
void showMatrice(int* mat) {
    printf("\nMatrice %d x %d : \n", MAT_COTE, MAT_COTE); // Affiche la taille de la matrice
    for (int i = 0; i < MAT_LENGTH; i++) {
        // Crée une nouvelle ligne pour chaque nouvelle ligne de la matrice
        if (i % MAT_COTE == 0) {
            printf("|\n"); // Affiche une bordure de ligne
        }
        // Affiche un astérisque pour 1 ou un espace pour 0
        if (mat[i] == 1) {
            printf("*");
        } else {
            printf(" ");
        }
    }
    printf("|\n"); // Affiche la bordure inférieure de la matrice
}

/**
 * @brief Calcule le minimum parmi trois entiers.
 * 
 * @param a Premier entier.
 * @param b Deuxième entier.
 * @param c Troisième entier.
 * @return int Le minimum des trois entiers.
 */
int min(int a, int b, int c) {
    // Compare les entiers pour déterminer le plus petit
    if (a <= b && a <= c) {
        return a; // a est le minimum
    } else if (b <= a && b <= c) {
        return b; // b est le minimum
    } else {
        return c; // c est le minimum
    }
}

/**
 * @brief Calcule la taille du plus grand carré de 0 dans une matrice.
 * 
 * @param m Un pointeur vers la matrice.
 * @param x Index de la ligne dans la matrice.
 * @param y Index de la colonne dans la matrice.
 * @return int La taille du plus grand carré de 0, ou 0 si la position est invalide.
 */
int PGCB(int* m, int x, int y) {
    // Calcule l'index dans le tableau à partir des coordonnées x et y
    int indexInArray = x * MAT_COTE + y; 
    if (x < 0 || y < 0) {
        return 0; // Retourne 0 si les indices sont en dehors des limites
    }
    if (m[indexInArray] == 1) {
        return 0; // Retourne 0 si la case est occupée
    } else if (m[indexInArray] == 0) {
        // Appelle récursivement PGCB pour vérifier les coins inférieur gauche, supérieur et gauche
        return 1 + min(PGCB(m, x - 1, y - 1), PGCB(m, x, y - 1), PGCB(m, x - 1, y));
    }
    return 1; // Cas par défaut (ne devrait jamais être atteint)
}

/**
 * @brief Trouve la plus grande taille de carré possible dans la matrice.
 * 
 * @param m Un pointeur vers la matrice à analyser.
 * @return int* Un tableau contenant la taille du carré et ses coordonnées.
 */
int* findBiggestCarre(int* m) {
    int best = 0; // Meilleure taille trouvée
    int xbest, ybest; // Coordonnées pour le meilleur carré
    int test; // Utilisé pour stocker les résultats de PGCB
    int x, y; // Coordonnées courantes dans la matrice
    for (int i = 0; i < MAT_LENGTH; i++) {
        // Conversion de l'index linear en coordonnées x (ligne) et y (colonne)
        x = i / MAT_COTE; // Coordonnée de ligne
        y = i % MAT_COTE; // Coordonnée de colonne
        // Appelle PGCB pour la position actuelle
        test = PGCB(m, x, y);
        // Si la taille trouvée est meilleure, met à jour les meilleures valeurs
        if (test > best) {
            best = test;    
            xbest = x; // Met à jour la meilleure coordonnée x
            ybest = y; // Met à jour la meilleure coordonnée y
        }
    }
    // Alloue un tableau pour stocker la taille du carré et ses coordonnées
    int* res = malloc(sizeof(int) * 4);
    res[0] = best; // Taille du carré
    res[1] = xbest; // Coordonnée x
    res[2] = ybest; // Coordonnée y
    return res; // Retourne le tableau de résultats
}

/**
 * @brief Affiche la matrice et met en surbrillance le plus grand carré trouvé.
 * 
 * @param mat Un pointeur vers la matrice à afficher.
 */
void showMatriceWithCarre(int* mat) {
    // Trouve le plus grand carré dans la matrice
    int* res = findBiggestCarre(mat);
    int x, y; // Coordonnées pour l'affichage
    printf("\nMatrice %d x %d : \n", MAT_COTE, MAT_COTE); // Affiche la taille de la matrice
    for (int i = 0; i < MAT_LENGTH; i++) {
        // Conversion de l'index linear en coordonnées x et y
        x = i / MAT_COTE; // Coordonnée de ligne
        y = i % MAT_COTE; // Coordonnée de colonne
        if (i % MAT_COTE == 0) {
            printf("|\n"); // Affiche une bordure de ligne
        }
        // Vérifie si la position actuelle est dans le carré le plus grand
        if (
            x >= res[1] - res[0] + 1 && 
            y >= res[2] - res[0] + 1 && 
            x <= res[1] && 
            y <= res[2]
        ) {
            printf("#"); // Affiche # pour les éléments du carré trouvé
        } else {
            // Affiche un astérisque pour 1 ou un espace pour 0
            if (mat[i] == 1) { 
                printf("*"); 
            } else { 
                printf(" "); 
            }
        }
    }
    printf("|\n"); // Affiche la bordure inférieure de la matrice
}
