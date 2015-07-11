#include <iostream>
#include <cstdio>

using namespace std;

int lower(int* a, int n, int x) {
    int low = 0;
    int hi = n-1;
    while(low != hi) {
        int mid = (hi+low)/2;
        if(a[mid] < x)
            low = mid + 1;
        else
            hi = mid;
    }
    if(a[low] >= x)
        return low;
    return low + 1;
}


int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++) {
        int x;
        scanf("%d",&x);
        printf("%d\n",n-lower(a,n,x));
  }
    return 0;
}
