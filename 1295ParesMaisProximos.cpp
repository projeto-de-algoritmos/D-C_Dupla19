// Problema: https://www.beecrowd.com.br/judge/pt/problems/view/1295
// Linguagem: C++17

#include <bits/stdc++.h>
using namespace std;
#define MAX 9999.99

typedef struct Ponto{
        double x;
        double y;
}Ponto;

Ponto pontos[10009];

double min(double p1, double p2){
    if(p1<p2){
        return p1;
    }

    return p2;
}

double distancia(Ponto &p1, Ponto&p2){
    double dist = sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
    return dist;
}

double ParMaisProximo(long long int p1, long long int p2){
    double esq, dir, dist, mediana;
    long long int i, meio, k;

    if (p1 == p2){
        return MAX + 1.0;
    }else if(p2-p1 == 1){
        return distancia(pontos[p2],pontos[p1]);
    }else{
        esq = ParMaisProximo(p1,(p1+p2)/2);
        dir = ParMaisProximo((p1+p2)/2+1,p2);
        dist = min(esq,dir);
        meio = (p1+p2)/2;
        mediana = pontos[meio].x;

        do{
            k = ((p1+p2)/2)+1;
            while((mediana - pontos[k].x < dist) && (k <= p2)){
                esq = distancia(pontos[k],pontos[meio]);
                dist = min(dist,esq);
                k++;
            }

            meio--;

        }while(mediana - pontos[meio].x < dist && meio >= p1);
        
        return dist;
        
    }
}

int compara(const void *p1, const void *p2){
    Ponto *a = (Ponto *)p1;
    Ponto *b = (Ponto *)p2;

    if((a->x) > (b->x)){
        return 1;
    }else if((a->x) < (b->x)){
        return -1;
    }else{
        if((a->y) > (b->y)){
            return 1;
        }else{
            return -1;
        }
    }

    return -1;
}


int main(){
    long i, N=1;
    double dist;
    while(N!=0){
        cin >> N;
        if(N==0){
            break;
        }

        for(i=0; i<N;i++){
            cin >> pontos[i].x >> pontos[i].y;
        }

        qsort(pontos,N,sizeof(pontos[0]),compara);
        dist = ParMaisProximo(0,N-1);

        if(dist>MAX){
            cout << "INFINITY" << endl;
        }else{
            printf("%.4lf\n", dist);
        }

    }

    return 0;
}