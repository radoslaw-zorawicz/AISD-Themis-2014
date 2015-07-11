#include <iostream>

using namespace std;



int** allocate(int n, int m) {
    int** t = new int*[n];
    for(int i = 0; i < n; i++)
        t[i] = new int[m];
    return t;
}

void dealloc(int**t, int n) {
    for(int i = 0; i < n; i++)
        delete[] t[i];
    delete[] t;
}


int lcs2(string a, string b) {
    //int lcs[a.size()+1][b.size()+1];
    int** lcs = allocate(a.size()+1,b.size()+1);

    for(unsigned int i = 1; i <= a.size(); i++)
        lcs[i][0] = 0;
    for(unsigned int j = 0; j <= b.size(); j++)
        lcs[0][j] = 0;
    for(unsigned int i = 1; i <= a.size(); i++) {
        for(unsigned int j = 1; j <= b.size(); j++) {
            if(a[i-1] == b[j-1])
                lcs[i][j] = lcs[i-1][j-1] + 1;
            else
                lcs[i][j] = max(lcs[i][j-1],lcs[i-1][j]);
        }
    }

    int i = a.size(), j = b.size();
    string sub = "";
    while(lcs[i][j] > 0) {
        if(a[i-1] == b[j-1]) {
            sub = a[i-1] + sub;
            i--; j--;
        }
        else if(lcs[i][j] == lcs[i-1][j])
            i--;
        else j--;
    }
    cout << sub << endl;
    dealloc(lcs,a.size()+1);
    return lcs[a.size()][b.size()];
}


int main()
{
    string a,b;
    cin >> a >> b;
    cout << lcs2(a,b) << endl;
    return 0;
}

