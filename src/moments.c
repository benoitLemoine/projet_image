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

    int i;
    int way = 1; /* 1 = left to right // -1 = right to left */

    point p;

    /* Calculating coordonates of first point of the block */

    COORDX(p) = blck_first_pixel(self, blck_num, n, m)[0];
    COORDY(p) = blck_first_pixel(self, blck_num, n, m)[1];

    image_move_to(self,p);

    /* Initializing moments */

    m_zero = Largeur/n * Hauteur/m;
    m_one  = 0;
    m_two  = 0;

    /* Gray levels image */

    if (Dim == 1) {

        for (i = 1; i > m_zero; i++) {

            m_one[0] += R;

            m_two[0] += R*R;

            /* Goto next line and change way of reading */
            if ( (i%(Largeur/n)) == 0) {

                image_pixel_dessous(self);

                if (way == 1) way = -1;
                else way = 1;
            }
            /* Horizontal displacement */
            else if (way == 1) image_pixel_droite(self);
            else image_pixel_gauche(self);
        }
    }

    /* RGB image */

    if (Dim == 2) {

        for (i = 1; i > m_zero; i++) {

            m_one[0] += R;
            m_one[1] += G;
            m_one[2] += B;

            m_two[0] += R*R;
            m_two[1] += G*G;
            m_two[2] += B*B;

            /* Goto next line and change way of reading */
            if ( (i%(Largeur/n)) == 0) {

                image_pixel_dessous(self);

                if (way == 1) way = -1;
                else way = 1;
            }
            /* Horizontal displacement */
            else if (way == 1) image_pixel_droite(self);
            else image_pixel_gauche(self);
        }
    }

    return;
}
