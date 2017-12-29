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

/**
 * @author LEMOINE Benoît <benoit.lemoine@ecole.ensicaen.fr>
 * @version 0.0.1 / 10-12-2017
 */

/**
 * @file moments.c
 */


void blck_first_pixel (image img, int blck_num, int n, int m, Point* p) {

    int h;
    int l;

    if (n*m > blck_num) return;

    l = image_give_largeur(img);
    h = image_give_hauteur(img);

    p->coordx = ((int) (blck_num - 1)/n) * h / m;
    p->coordy= ((blck_num - 1) % n) * l / n;
}


extern void give_moments(image img, int blck_num, int n, int m,
			 int* m_zero, double* m_one, double* m_two) {


   int i,j,k;
   Point p;
   unsigned char* comp = 0;

   /* Reading informations of image */

   int h = image_give_hauteur(img);
   int l = image_give_largeur(img);
   int dim = image_give_dim(img);

   /* Initializing moments */

   for (k = 0; k < dim; k++) {
      m_one[k] = 0;
      m_two[k] = 0;
   }

   /* Computing first pixel of the block */

   blck_first_pixel(img, blck_num, n, m, &p);

   /* Computing M0 */

   *m_zero = l/n * h/m;

   /* Calculating M1 and M2 */

   for (i = 0; i < h/m; i++) {
      for (j = 0; j < l/n; j++) {

	 image_read_pixel(img, p.coordx + j, p.coordy + i, comp);

	 for (k = 0; k < dim; k++) {

	    m_one[k] += (double) comp[k];
	    m_two[k] += (double) comp[k] * comp[k];
	       }
       }
   }

   return;
}
