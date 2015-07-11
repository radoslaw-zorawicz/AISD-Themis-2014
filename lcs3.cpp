#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


int lcs3(char* a, char* b, char* c) {
    //int lcs[a.size()+1][b.size()+1];
    int m = strlen(a) + 1;
    int n = strlen(b) + 1;
    int o = strlen(c) + 1;
    int lcs[m][n][o];

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < o; k++){
                if(i == 0 || j == 0 || k == 0)
                    lcs[i][j][k] = 0;
                else if(a[i-1] == b[j-1] && a[i-1] == c[k-1])
                    lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
                else
                    lcs[i][j][k] = max(max(lcs[i][j-1][k],lcs[i-1][j][k]),lcs[i][j][k-1]);
            }
         }
    }
    return lcs[m-1][n-1][o-1];
}


int main()
{
    int t;
    scanf("%d",&t);
    const short MAX_SIZE = 101;
    char a[MAX_SIZE], b[MAX_SIZE], c[MAX_SIZE];
    for(int i = 0; i < t; i++) {
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
        printf("%d\n",lcs3(a,b,c));
    }
    return 0;
}

