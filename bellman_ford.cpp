#include <vector>
#include <cstdio>
#include <climits>
/* Algorytm Bellmana-Forda nie potrzebuje informacji o sasiadach poszczegolnych wierzcholkow,
   a wiec graf reprezentowany jest jako zbior krawedzi, a nie jako zbior list sasiedztwa */
using namespace std;
const int inf = INT_MAX;

bool bellman_ford(vector<vector<int> >& G, vector<int>& weight, int n, int m) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m; j++) {
            int u = G[j][0];
            int v = G[j][1];
            int d = G[j][2];
            /*! UWAGA !
               CLRS zak³ada ¿e inf + x = inf
               Niech  d[v] = inf, d[u] = inf
               Wtedy warunkek d[v] > d[u] + c nie jest spe³niony,
               bo d[u] + c = inf, czyli nie zachodzi inf > inf.

               Jednak w praktyce inf to przeciez liczba. Niech inf = 100
               Wtedy d[v] = inf = 100, d[u] = inf = 100
               Wtedy  d[u] + c = 100 + c > inf, a wiec warunek zostaje
               spelniony i wykonuje sie cialo if. Aby temu zapobiec trzeba
               sprawdzic czy d[u] != inf */
            if(weight[u] != inf && weight[v] > weight[u] + d) {
                weight[v] = weight[u] + d;
            }
        }
    }
    for(int j = 0; j < (int)G.size(); j++) {
        int u = G[j][0];
        int v = G[j][1];
        int d = G[j][2];
        if(weight[u] != inf && weight[v] > weight[u] + d) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,m,s;
    scanf("%d %d %d",&n,&m,&s);
    vector<vector<int> > G(m);
    vector<int> weight(n,inf);
    weight[s] = 0;
    for(int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        G[i].resize(3);
        G[i][0] = a;
        G[i][1] = b;
        G[i][2] = c;
    }
    if(bellman_ford(G,weight,n,m)) {
        for(int i = 0; i < n; i++) {
            if(weight[i] < inf && i != s)
                printf("%d %d\n",i,weight[i]);
        }
    }
    else
        printf("NIE");
    return 0;
}
