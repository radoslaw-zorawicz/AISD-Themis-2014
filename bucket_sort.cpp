#include <iostream>
#include <cstdio>
#include <list>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    const int SIZE = 128;
    scanf("%d",&n);
    vector<int> bucket(SIZE,0);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d",&a);
        bucket[a]++;
    }
    for(int i = 0; i < SIZE; i++) {
        while(bucket[i]-- > 0)
            printf("%d ",i);
    }
    return 0;
}
