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
 * @version 0.0.1 / 15-12-2017
 */

/**
 * @file rag_fusion.c
 */


extern double RAG_give_closest_region(RAG rag, int* b1, int* b2) {

  int i,k;
  int n;

  int ffirst = 1;

  cellule cel;
  
  int M0, M0b;
  double* M1, M1b;

  int dim = image_give_dim(rag.im);

  double err;
  double errMin;
  
  for (i = 1; i < rag.nb_blocks; i++) {
    if (rag.father[i] == i) {

      /* Saving moments of first block */
      
      M0 = rag.m[i].M0;
      M1 = rag.m[i].M1;

      /* Saving address of current neighbor */
      
      cel = rag.neighbors[i];

      while (cel != NULL) {

	n = cel.block;
	if (father[n] == n) {

	  /* Saving moments of neighbor */
	  
	  M0b = rag.m[n].M0;
	  M1b = rag.m[n].M1;

	  /* Computing error */
	  
	  err = error(M0, M0b, M1, M1b, dim);

	  /* Saving this error as the minimum one if first occurence or if lesser */
	  
	  if (errMin > err || ffirst == 1) {
	    errMin = err;
	    ffirst = 0;

	    b1 = i;
	    b2 = n;
	  }
	}
	cel = cel.next;
      }
    }
  }

  return errMin;
}


double error (int M0, int M0b, double* M1, double* M1b, int dim) {

  double err = 0;
  int k;
  
  err = (M0 * M0b)/(M0 + M0b);

  for (k = 0; k < dim; k++) {

    err *= ((M1[k]/M0) - (M1b[k]/M0b)) * ((M1[k]/M0) - (M1b[k]/M0b));
  }

  return err;
}



void RAG_merge_region(RAG* rag, int b1, int b2) {

  assert(b1 < b2);

  /* Update father */

  rag->father[b1] = b2;

  /* Update moments */

  RAG_merge_moments(rag, b1, b2);


  /* Update neighbor */

}


void RAG_merge_moments(RAG* rag, int b1, int b2) {

  int dim = image_give_dim(rag.im); 
  int k;

  rag->moment[b2].M0 += rag->moment[b1].M0;

  for (k = 0; k < dim; k++) {

    rag->moment[b2].M1[k] += rag->moment[b1].M1[k];
    rag->moment[b2].M2[k] += rag->moment[b1].M2[k];
  }
}


void RAG_merge_neighbors(RAG* rag, int b1, int b2) {

  cellule cel1, cel2;
  int n;
  
  cel2 = rag->neighbors[b2];

  /* Go to the last neighbor of b2 */
  
  while (cel2 != NULL) {

    /* Saves number of last block in the list of neighbors  */
    
    n = cel2.block;
    cel2 = cel2.next;
  }

  /* Go to first neighbor of b1 */
  
  cel1 = rag->neighbors[b1];

  while (cel1 != NULL) {

    /* Doesn't put b2 as a neighbor of b2 */

    if (cel1.block != b2) {

      rag->neighbors[n].block = cel1.block;
      rag->neighbors[n].next = cel1.next;
    }
  }
} 
