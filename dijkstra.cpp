#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <algorithm>
#define gr_iter vector<pair<int,int>>::iterator
#define heap_iter  std::set<int,cmp>::iterator
using namespace std;
const int inf = 1000001;

struct cmp
{   const vector<int>& weight;
    cmp(vector<int>& w) : weight(w) {}
    bool operator() (const int &a, const int &b)
    {
        if (weight[a] < weight[b]) return true;
        if (weight[a] > weight[b]) return false;
        return a < b;
    }

};

void dijkstra(vector<vector<pair<int,int> > >& G, vector<int>& weight, int s) {
    std::set<int,cmp>heap((cmp(weight)));
    heap.clear();
    weight[s] = 0;
    heap.insert(s);
    while(!heap.empty()) {
        int u = *(heap.begin());
        heap.erase(u);
        for(int i = 0; i < (int)G[u].size(); i++) {  //relaksujemy kazda krawedz wychodzaca z wierzchola u
            int v = G[u][i].first;
            int w = G[u][i].second;
            if(weight[u] != inf && weight[v] > weight[u] + w) {
                heap.erase(v);     //aby uaktualnic wartosc w kopcu musimy usunac dany wierzcholek
                weight[v] = weight[u] + w;      // albo zastosowac strukture z operacja decrease key
                heap.insert(v);
            }
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int s = 0; //wierzcholek startowy
    vector<vector<pair<int,int> > > G(n);
    vector<int> weight(n,inf);
    for(int i = 0; i < m; i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        G[a-1].push_back(pair<int,int>(b-1,c));
        G[b-1].push_back(pair<int,int>(a-1,c));
    }
    dijkstra(G,weight,s);
    for(int i = 1; i < n; i++)
        printf("%d ",weight[i]);
    return 0;
}
