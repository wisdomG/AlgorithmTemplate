#include <iostream>
#include "binary_search.h"
using namespace std;

int main() {
    int a[] = {1, 1, 1, 2, 2, 2, 2, 2, 4, 4, 5, 5, 5, 6, 6, 6};
    int n = sizeof(a)/sizeof(int);
    for( int i = 0 ; i <= 8 ; i ++ ){

        int floorIndex = floor(a, n, i);
        cout<<"the floor index of "<<i<<" is "<<floorIndex<<".";
        if( floorIndex >= 0 && floorIndex < n )
            cout<<"The value is "<<a[floorIndex]<<".";
        cout<<endl;

        int ceilIndex = ceil(a, sizeof(a)/sizeof(int), i);
        cout<<"the ceil index of "<<i<<" is "<<ceilIndex<<".";
        if( ceilIndex >= 0 && ceilIndex < n )
            cout<<"The value is "<<a[ceilIndex]<<".";
        cout<<endl;

        cout<<endl;
    }
    return 0;
}
