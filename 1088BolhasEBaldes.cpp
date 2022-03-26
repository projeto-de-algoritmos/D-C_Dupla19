// Problema: https://www.beecrowd.com.br/judge/pt/problems/view/1088
// Linguagem: C++17

#include <bits/stdc++.h>
using namespace std;

int v[100000];

int merge (int v[], int l, int r1, int r2){
    int i,j,k = 0, trocas = 0;
    int v2[r2-l];
    i = l, j = r1;

    while(i<r1 && j<r2){
        if(v[i] <= v[j]){
            v2[k++] = v[i++];
        }else{
            v2[k++] = v[j++];
            trocas += r1-i;
        }
    }

    while(i<r1){
        v2[k++] = v[i++];
    }

    while(j<r2){
        v2[k++] = v[j++];
    }

    for(i=l; i<r2; i++){
        v[i] = v2[i-l];
    }

    return trocas;
}

int mergeSort (int v[], int l, int r2){
    int r1, cL = 0, cR = 0, meio = 0;
    
    if(l<(r2-1)){
        r1 = (l+r2)/2;
        cL = mergeSort(v,l,r1);
        cR = mergeSort(v,r1,r2);
        meio = merge(v,l,r1,r2);
    }
    return cL + cR + meio;
}

int main(){
    int i, n;

    while(1){
        cin >> n;
        if (n==0){
            break;
        }
        for(i = 0 ; i < n; i++){
            cin >> v[i];
        }
        int total = mergeSort(v, 0, n);

        if(total%2 == 0){
            cout << "Carlos" << endl;
        }else{
            cout << "Marcelo" << endl;
        }
    }

    return 0;
}