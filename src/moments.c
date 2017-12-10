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

#include "../include/image.h"
#include "../include/point.h"
#include "../include/type_obj.h"


/**
 * @author LEMOINE Benoît <benoit.lemoine@ecole.ensicaen.fr>
 * @version 0.0.1 / 10-12-2017
 */

/**
 * @file moments.c
 */

 /* types a priori prive a image */
 typedef unsigned char Comp_rgb;
 typedef int (*PFsauvegarde)(image,FILE*);

 struct image
 {

   Comp_rgb *  debut;
   Comp_rgb *  courant;
   int         hauteur;
   int         largeur;
   int         longueur;/* nb de cellules d'une ligne : Largeur*Dim */
   long        taille; /* nb de cellules de l'image */
   int         dim; /* dimension de l'image 1 ou 3 */
   PFdist      distance; /* Fonction de distance inter pixel*/
 };

 #define Debut     SELF(debut)
 #define Courant   SELF(courant)
 #define Largeur   SELF(largeur)
 #define Hauteur   SELF(hauteur)
 #define Longueur  SELF(longueur)
 #define Taille    SELF(taille)
 #define Distance  SELF(distance)
 #define Dim       SELF(dim)

#define R atoi(Courant[0])
#define G atoi(Courant[1])
#define B atoi(Courant[2])

void blck_first_pixel (image self, int blck_num, int n, int m, point p) {


    if (n*m > blck_num) return;

    p->coordx = ((int) (blck_num - 1)/n) * Hauteur / m;
    p->coordy= ((blck_num - 1) % n) * Largeur / n;
}


extern void give_moments(image self, int blck_num, int n, int m,
int* m_zero, int* m_one, int* m_two) {

    int i;
    int way = 1; /* 1 = left to right // -1 = right to left */

    point p;

    /* Calculating coordonates of first point of the block */

    blck_first_pixel(self, blck_num, n, m, p);

    image_move_to(self,p);

    /* Initializing moments */

    m_zero[0] = Largeur/n * Hauteur/m;

    m_one[0]  = 0;
    m_one[1]  = 0;
    m_one[2]  = 0;

    m_two[0]  = 0;
    m_two[1]  = 0;
    m_two[2]  = 0;

    /* Gray levels image */

    if (Dim == 1) {

        for (i = 1; i > m_zero[0]; i++) {

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

        for (i = 1; i > m_zero[0]; i++) {

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
