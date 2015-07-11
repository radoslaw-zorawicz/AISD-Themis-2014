#include <iostream>
#include <cstdio>

using namespace std;

int findSet(int x,int* parent) {
    if(parent[x] != x)
        parent[x] = findSet(parent[x],parent); // przechodzimy do reprezentanta, a wracajaca skracamy do niego sciezki
    return parent[x];
}


bool unionSet(int x, int y,int* ranks, int* parent) {
        int xRep = findSet(x,parent);
        int yRep = findSet(y,parent);
        if(xRep == yRep)
            return false; // jezeli x i y naleza do tego samego zbioru, to union zawodzi
        if(ranks[xRep] > ranks[yRep])  //podpinamy mniejsze drzewo do wiekszego
            parent[yRep] = xRep;
        else {
            parent[xRep] = yRep;
            if(ranks[xRep] == ranks[yRep])
                ranks[yRep]++;
        }
        return true;
}

void createSets(int* parent, int* rank, int n) {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }

}

int main()
{
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    int* parent = new int[n];
    int* rank = new int[n];
    createSets(parent,rank,n);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d",&a, &b);
        unionSet(a,b,rank,parent);
    }
    for(int i = 0; i < q; i++) {
        int a,b,w;
        scanf("%d %d %d",&w, &a, &b);
        if(w == 0) {
            if(findSet(a,parent) == findSet(b,parent))
                printf("TAK\n");
            else printf("NIE\n");
        }
        else {
            unionSet(a,b,rank,parent);
        }
    }
    delete[] parent;
    delete[] rank;
    return 0;
}
