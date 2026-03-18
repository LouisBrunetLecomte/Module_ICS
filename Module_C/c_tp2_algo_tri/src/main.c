#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include "all_sorts.h"

/**
 * @brief Calculates the time difference between two time points.
 * 
 * This function computes the difference in seconds between two `struct timeval` instances,
 * which represent time in seconds and microseconds.
 * 
 * @param start A pointer to the `struct timeval` representing the start time.
 * @param end A pointer to the `struct timeval` representing the end time.
 * @return The time difference in seconds as a float.
 */
float time_diff(struct timeval *start, struct timeval *end) {
  return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec); // Chercher explications
}

/**
 * @brief The main function of the program.
 * 
 * This function initializes two arrays of random floating-point numbers, measures the time taken
 * to sort each array using selection sort and bubble sort, and prints the results.
 * 
 * @return Returns 0 on successful execution.
 */
int main()
{
    struct timeval start;
    struct timeval end;
    int size_of_array = 100000; // Permet de dire au programme la taille du tableau alloué.
    float tab1[size_of_array]; //Tableau vide (taille de size_of_array)
    float tab2[size_of_array];
    float tab3[size_of_array];
    float tab4[size_of_array];

    srand(time(NULL));                  //Initialise le random pour utiliser celle-ci
    for(int i=0;i<size_of_array;i++) {  // Remplir les tableaux avec les nombres aléatoires
        tab1[i] = rand() % 10000;       // RAND = valeur aléatoire -- modulo -- 10000 -> ajouter a la liste [i] une valeur aléatoire.
        tab2[i] = tab1[i];              // Tableau 1 et 2 ont les memes valeurs -> meme nombres d'operations a faire. Pour bien comparer les algos
        tab3[i] = tab1[i];
        tab4[i] = tab1[i];
    }


    //sort_selection

    gettimeofday(&start, NULL); // récupère l'heure à une instant donné, place dans une variable START
    sort_selection(tab1, size_of_array);
    gettimeofday(&end, NULL);   // récupère l'heure à une instant donné, place dans une variable END

    printf("sort_selection: %0.40f sec for %d numbers\n", time_diff(&start, &end), size_of_array); 
    // time_diff(&start, &end) -> donne le temps qui s'est écoulé
    // sort_selection: %0.40f sec for %d numbers\n  -> Affiche le temps écoulé 40 chiffres apres la virgule.


    //sort_bubble

    gettimeofday(&start, NULL);
    sort_bubble(tab2, size_of_array);
    gettimeofday(&end, NULL);

    printf("sort_bubble: %0.40f sec for %d numbers\n", time_diff(&start, &end), size_of_array);


    //sort_insertion

    gettimeofday(&start, NULL);
    sort_insertion(tab3, size_of_array);
    gettimeofday(&end, NULL);

    printf("sort_insertion: %0.40f sec for %d numbers\n", time_diff(&start, &end), size_of_array);


    //sort_tas

    gettimeofday(&start, NULL);
    sort_tas(tab4, size_of_array);
    gettimeofday(&end, NULL);

    printf("sort_tas: %0.40f sec for %d numbers\n", time_diff(&start, &end), size_of_array);


    return 0;
}

// %d signifie entier
// %f signifie float
// %0.40f signifie float avec 40 chiffres apres la virgule
// \n signifie retour a la ligne