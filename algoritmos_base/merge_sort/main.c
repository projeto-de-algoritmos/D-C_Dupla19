#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(a, b) (a < b)
#define exch(a, b) (Item temp = b; b = a; a = temp;)

void merge(Item *v, int l, int r1, int r2) {
  Item *v2 = (Item *) malloc(sizeof(Item) * (r2 - l + 1));
  int k = 0;
  int i = l, j = r1+1;

  while (i <= r1 && j <= r2) {
    if (less(v[i], v[j]))
      v2[k++] = v[i++];
    else
      v2[k++] = v[j++];
  }

  while(i <= r1)
    v2[k++] = v[i++];
  
  while(j <= r2)
    v2[k++] = v[j++];

  k = 0;
  
  for (i = l; i <= r2; i++)
    v[i] = v2[k++];

  free(v2);
}

void mergeSort(Item *v, int l, int r)
{
  if (l >= r)
    return;
  
  int middle = (r+l)/2;
  
  mergeSort(v, l, middle);
  mergeSort(v, middle+1, r);
  merge(v, l, middle, r);
}

int main(void) { 
  Item v[10] = {32, -1, 424, -44, 234, 45, 23, 84, 
  10, 8};

  mergeSort(v, 0, 9);

  for (int i = 0; i < 10; i++)
    printf("%d%c", v[i], " \n"[i+1==10]);
  
  return 0; 
}