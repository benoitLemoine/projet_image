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

   unsigned char* comp;
   
   int m_zero = 0;
   double m_one[3] = {0,0,0};
   double m_two[3] = {0,0,0};

   image img;
   img = FAIRE_image();

   image_charger(img,"../img/lenna.ppm");

   give_moments(img, 2, 2, 2, &m_zero, m_one, m_two);

   printf("M0: %d  // M1: %d  // M2: %d", m_zero, m_one, m_two);

   image_initialize(img,1,8,8);

   for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {

	 printf("%d%d ", i,j);
	 *comp = i + j;
	 image_write_pixel(img,i, j, comp); 
      }
   }
   
   give_moments(img, 2, 2, 2, &m_zero, m_one, m_two);

   /* printf("M0: %d  // M1: %f  // M2: %f\n", m_zero, m_one[0], m_two[0]); */

   if (m_zero == 16 && m_one[0] == 91 && m_two[0] == 824) {
      printf("Moments on gray level image succeded\n");
      return;
   }

   printf("Moments on gray level image failed\n");
}


int main () {

    testSmallImage();

   return 0;
}
