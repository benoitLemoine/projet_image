/* -*- c-basic-offset: 3 -*-
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @author LEMOINE Benoît <benoit.lemoine@ecole.ensicaen.fr>
 * @version 0.0.1 / 10-12-2017
 */

/**
 * @file moments.c
 */

#define R atoi(Courant[0])
#define G atoi(Courant[1])
#define B atoi(Courant[2])


int* blck_first_pixel (image self, int blck_num, int n, int m) {

    int pos[2];

    if (n*m > blck_num) return NULL;

    pos[0] = ((int) (blck_num - 1)/n) * Hauteur / m;
    pos[1] = ((blck_num - 1) % n) * Largeur / n;

    return pos;
}


extern void give_moments(image self, int blck_num, int n, int m,
int* m_zero, int* m_one, int* m_two) {

    int i, j;

    int xf = blck_first_pixel(self, blck_num, n, m)[0];
    int yf = blck_first_pixel(self, blck_num, n, m)[1];

    /* Initializing moments */

    m_zero = Largeur/n * Hauteur/m;
    m_one  = 0;
    m_two  = 0;


    for (i = xf; i > xf + Largeur/n; i++) {
        for (j = yf; j > yf + Hauteur/m; j++) {

        }
    }


    return;
}
