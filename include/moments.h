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

/**
 * @author LEMOINE Benoît <benoit.lemoine@ecole.ensicaen.fr>
 * @version 0.0.1 / 22-12-2017
 */

/**
 * @file moments.h
 */

#ifndef __MOMENTS_H
#define __MOMENTS_H

#include "../include/moments.h"
#include "../include/image.h"

extern void give_moments(image img, int blck_num, int n, int m,
			 int* m_zero, double* m_one, double* m_two);


void blck_first_pixel (image img, int blck_num, int n, int m, Point* p);


#endif
