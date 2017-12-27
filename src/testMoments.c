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
#include "../include/moments.h"
#include "../include/image.h"

/**
 * @author LEMOINE Benoît <benoit.lemoine@ecole.ensicaen.fr>
 * @version 0.0.1 / 22-12-2017
 */

/**
 * @file testMoments.c
 */


void testSmallImage() {

   int i,j;
   int m_zero = 0;
   double m_one[3] = {0,0,0};
   double m_two[3] = {0,0,0};

   image img;
   img = FAIRE_image();
   image_charger(img,"../img/lenna.ppm");

   give_moments(img, 2, 2, 2, &m_zero, m_one, m_two);

   printf("M0: %d  // M1: %d  // M2: %d", m_zero, m_one, m_two);
}


int main () {

    testSmallImage();

   return 0;
}
