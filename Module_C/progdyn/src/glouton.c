#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valeur;
    int volume;
} Objet;


/**
* Algorithme glouton
* @param array The array of elements
* @param size Size of array
* @param max_volume volume max of sac
* @return array of best choice
*/
void glouton(Objet *array[], int size, int max_volume) {
    // Calculate value/volume ratios
    double rapport[size];
    for (int i = 0; i < size; i++) {
        rapport[i] = (double)array[i]->valeur / array[i]->volume;
    }

    // Réorganiser les objets dans l'ordre du rapport valeur/volume (tri par sélection)
    Objet *tempO;
    int max, imax, tempR;
    for(int i = 0; i < size; i++) {
        max = rapport[i];
        imax = i;
        for(int j = i + 1; j < size; j++) { // `j` commence à `i + 1` pour éviter la répétition
            if (rapport[j] > max) { // On échange si le rapport est plus grand
                max = rapport[j];
                imax = j;
            }
        }
        // changement de place des objets
        tempO = array[imax];
        array[imax] = array[i];
        array[i] = tempO;

        // changement de place des rapports
        tempR = rapport[imax];
        rapport[imax] = rapport[i];
        rapport[i] = tempR;
    }

    int volume_total = 0;
    int valeur_totale = 0;
    int i = 0;

    // Add elements to the bag until max_volume is reached
    while (i < size) {
        if (volume_total + array[i]->volume <= max_volume) {
            volume_total += array[i]->volume; 
            valeur_totale += array[i]->valeur;
            i++;
        } else {
            i++;
        }
    }

    printf("Poids total: %d/%d\n", volume_total, max_volume);
    printf("Valeur totale: %d\n", valeur_totale);
}
