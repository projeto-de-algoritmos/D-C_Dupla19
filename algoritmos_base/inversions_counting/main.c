#include <stdio.h>
#include <stdlib.h>
#define greater(a, b) (a > b)
typedef int Item;

typedef struct inv {
  Item value;
  int inversions;
} inv;

void mergeAndCount(inv *L, int *invs, int l, int r1, int r2)
{
  inv *L2 = (inv *) malloc(sizeof(inv)*(r2-l+1));
  int i = l, j = r1+1, k = 0, items = r1-l+1;

  while(i <= r1 && j <= r2)
  {
    if (greater(L[i].value, L[j].value)){
      L2[k].value = L[j++].value;
      L2[k].inversions = items;
      *invs += items;
      k++;
    } else {
      L2[k++].value = L[i++].value;
      items--;
    }
  }

  while(i <= r1)
    L2[k++].value = L[i++].value;
  
  while(j <= r2)
    L2[k++].value = L[j++].value;

  k = 0;
  
  for (i = l; i <= r2; i++)
  {
    L[i].value = L2[k].value;
    L[i].inversions = L2[k].inversions;
    k++;
  }
  free(L2);
}

//Temos o total de inversões geral, implementar
// para conseguir contar as inversões em cada
// uma das duas metades da primeira divisão e não
// somente o total ao fim

void sortAndCount(inv *L, int *invs, int l, int r)
{
  if (l >= r) return;
  
  int middle = (r+l)/2;

  sortAndCount(L, invs, l, middle);
  sortAndCount(L, invs, middle+1, r);
  mergeAndCount(L, invs, l, middle, r);
}

void printList(inv *L, int l, int r)
{
  for (int j = l; j <= r; j++){
    printf("%d%c", L[j].value, " \n"[j==r]);
  }
}

int main(void) {
  int qtt = 0, num = 0, k = 0, invs = 0;

  scanf("%d", &qtt);

  inv *L = (inv *) malloc(sizeof(inv)*qtt);

  while(qtt--){
    scanf("%d", &num);
    L[k].value = num;
    L[k].inversions = 0;
    k++;
  }

  printList(L, 0, 11);
  
  sortAndCount(L, &invs, 0, 11);
  printList(L, 0, 11);

  printf("Total = %d\n", invs);
  
  return 0;
}