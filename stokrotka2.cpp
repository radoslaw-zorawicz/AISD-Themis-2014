#include <iostream>
#include <cstdio>
#include <cmath>
#include <stack>

using namespace std;

int main()
{
    const int SIZE = 1010;
    int t[SIZE][SIZE];
    int d[SIZE][SIZE];

    int m,n; // m - liczba wierszy, n - liczba kolum
    scanf("%d %d",&m,&n);


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            scanf("%d",&t[i][j]);
    }


    for(int i = 0; i < n; i++) {
        d[0][i] = (int)HUGE_VAL;
        d[m+1][i] = (int)HUGE_VAL;
    }

    for(int i = 1; i <= m ; i++) {
        d[i][0] = t[i-1][0]; //kolumna 0 mawartosci z pozycji t[0..m-1][0]
    }

    for(int j = 1; j < n; j++) {
        for(int i = 1; i <= m; i++) {
            d[i][j] = t[i-1][j] + min(min(d[i][j-1],d[i+1][j-1]),d[i-1][j-1]);
        }
    }

    int k = 1;
    int min = d[1][n-1];
    for(int j = 1; j <= m; j++) {
        if(min > d[j][n-1])
            k = j;
    }
    stack<int> s;
    int j = n-1;
    s.push(k-1);
    while(j > 0) {
        if(t[k-1][j] + d[k-1][j-1] == d[k][j])
            s.push(--k - 1);
        else if(t[k-1][j] + d[k][j-1] == d[k][j])
            s.push(k - 1);
        else
            s.push(++k - 1);
            j--;
        }
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        return 0;
}


