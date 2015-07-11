#include <iostream>
#include <cstdio>
using namespace std;

void partition(int* a, int n, int k) {
    int lt = 0, gt = n-1;
    int v = a[k-1];
    int i = 0;
    while(i <= gt) {
        if(a[i] < v) {
            swap(a[lt++],a[i++]);
        }
        else if(a[i] > v) {
            swap(a[i],a[gt--]);
        }
        else
            i++;
    }
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}


int main()
{
    int n, k;
    scanf("%d",&n);
    scanf("%d",&k);
    int* a = new int[n];
    for(int i = 0; i < n; i++)
        scanf("%d",&a[i]);
    partition(a,n,k);
    delete[] a;
    return 0;
}
