/*
    Author: Maicon Mares
    Date: 19/03/2022
    Software Engineering undergraduate student
*/


#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#define less(a, b) (a < b)
#define exch(a, b) (Item temp = b; b = a; a = temp;)
typedef int Item;

void merge(Item *v, int l, int r1, int r2);
void mergeSort(Item *v, int l, int r);

#endif