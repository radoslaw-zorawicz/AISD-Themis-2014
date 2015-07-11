#include <iostream>
#include <cstdio>

using namespace std;

bool interleaving(string a, string b, string c) {
    const int m = a.size();
    const int n = b.size();
    const int o = c.size();
    if(m+n != o)
        return false;
    bool t[m+1][n+1];
    t[0][0] = true;  //przeplot pustych slow jest pustym slowem
    for(int i = 1; i < m + 1; i++)  //mozna jakos lepiej; rozwazamy dwa przypadki przeplot a i slowa pustego
        t[i][0] = t[i-1][0] && a[i-1] == c[i-1];
    for(int j = 1; j < n + 1; j++)  // przeplot b i slowa pustego
        t[0][j] = t[0][j-1] && b[j-1] == c[j-1];
    for(int i = 1; i < m + 1; i++)
        for(int j = 1; j < n + 1; j++) {
            if(c[i+j-1] == a[i-1] && c[i+j-1] == b[j-1])
                t[i][j] = t[i-1][j] || t[i][j-1];
            else if(c[i+j-1] == b[j-1] && c[i+j-1] != a[i-1])
                t[i][j] = t[i][j-1];
            else if(c[i+j-1] == a[i-1] && c[i+j-1] != b[j-1])
                t[i][j] = t[i-1][j];
            else        //znak na pozycji i+j-1 w c roznil sie od a[i-1] oraz od a[j-1], c nie jest przeplotem
                t[i][j] = false;
        }
    return t[m][n];
}


int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    bool res = interleaving(a,b,c);
    if(res)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;
    return 0;
}
