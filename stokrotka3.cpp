#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;
//m- # wierszy, n- # kolumn

int main()
{
    const int s = 1010;
    int c;
    int t[s][s];
    int d[s][s];
    /* dPrevCol[i] - najmniejszy koszt dojscia do i- tego pola danej kolumny przechodzac z poprzedniej, tj. uwzgledniajac
    pola i+1,i,i-1 z poprzedniej */
    int dPrevCol[s];
    int up[s+2], down[s+2];
    scanf("%d",&c);
    for(int i = 0; i < c; i++) {
        int m,n; // m - liczba wierszy, n - liczba kolum
        scanf("%d %d",&m,&n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                scanf("%d",&t[i][j]);
        }

        for(int i = 0; i < m ; i++) {
            d[i][0] = t[i][0]; //kolumna 0 mawartosci z pozycji t[0..m-1][0]
        }

        for(int j = 1; j < n; j++) {

            for(int i = 0; i < m; i++) {
                int minVal = d[i][j-1];
                if(i < m - 1 && d[i+1][j-1] < minVal)
                    minVal = d[i+1][j-1];
                if(i-1 >= 0 && d[i-1][j-1] < minVal)
                    minVal = d[i-1][j-1];
                dPrevCol[i] = minVal;
            }

            up[0] = t[0][j] + dPrevCol[0]; //przy przechodzeniu w gore, do najnizszego pola mozna dostac sie tylko z poprzedniej kolumny
            for(int i = 1; i < n; i++)
                up[i] = t[i-1][j] + min(up[i-1],dPrevCol[i-1]);

            down[n-1] = t[n-1][j] + dPrevCol[n-1]; //przy przechodzeniu w dol, do najwyzszego pola mozna dostacsie tylko z poprzedniej kolumny
            for(int i = n - 2; i >= 0; i--)
                down[i] = t[i+1][j] + min(down[i+1],dPrevCol[i+1]);

            for(int i = 0; i < n; i++)
                d[i][j] = t[i][j] + min(dPrevCol[i],min(down[i],up[i]));
        }
        int minVal = d[0][n-1];
        for(int j = 1; j < m; j++) {
            if(minVal > d[j][n-1])
                minVal = d[j][n-1];
        }
        cout << minVal << endl;
    }
    return 0;
}
