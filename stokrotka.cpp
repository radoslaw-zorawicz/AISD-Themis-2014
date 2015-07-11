#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
//m- # wierszy, n- # kolumn

int main()
{
    const int s = 1010;
    int c;
    int t[s][s];
    int d[s][s];
    scanf("%d",&c);
    for(int i = 0; i < c; i++) {
        int m,n; // m - liczba wierszy, n - liczba kolum
        scanf("%d %d",&m,&n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                scanf("%d",&t[i][j]);
        }

        for(int i = 0; i < m ; i++) {
            d[i][0] = t[i][0]; //kolumna 0 ma wartosci z pozycji t[0..m-1][0]
        }

        for(int j = 1; j < n; j++) {
            for(int i = 0; i < m; i++) {
                int min = d[i][j-1];
                if(i < m - 1 && d[i+1][j-1] < min)
                    min = d[i+1][j-1];
                if(i-1 >= 0 && d[i-1][j-1] < min)
                    min = d[i-1][j-1];
                d[i][j] = t[i][j] + min;
            }
        }
        int min = d[0][n-1];
        for(int j = 1; j < m; j++) {
            if(min > d[j][n-1])
                min = d[j][n-1];
        }
        cout << min << endl;
    }
    return 0;
}
