#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 1000001;
int pi[SIZE];

void computePrefixFunction(const char* p,int m) {
    int k = 0;
    pi[0] = 0;
    for(int i = 1; i < m; i++) {
        while (k > 0 && p[k] != p[i])
            k = pi[k-1];
        if (p[k] == p[i])
            k++;
        pi[i] = k;
    }
}


void kmpMatcher(const char* p, const char* t) {
    int m = strlen(p);
    int n = strlen(t);
    if(m>n) return;
    computePrefixFunction(p,m);
    int q = 0;
    for(int i = 0; i < n; i++) {
        while(q > 0 && p[q] != t[i])
            q = pi[q-1];
        if(p[q] == t[i])
            q++;
        if(q == m) {
            printf("%d\n", i-m+1);
            q = pi[q-1];
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        char p[SIZE];
        char t[SIZE];
        int j;
      //  scanf("%d",&j);
        scanf("%s\n", p);
        scanf("%s\n", t);
        kmpMatcher(p,t);

    }
    return 0;
}
