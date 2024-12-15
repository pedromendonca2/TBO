#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#define CUTOFF 10

typedef int Item;

#define key(A)          (A)
#define less(A, B)      (key(A) < key(B))
#define exch(A, B)      { Item t = A; A = B; B = t; }
#define compexch(A, B)  if (less(B, A)) exch(A, B)

#endif
