// glouton.h
#ifndef GLOUTON_H

typedef struct {
    int valeur;
    int volume;
} Objet;

void glouton(Objet *array[], int size, int max_volume);

#endif // GLOUTON_H
