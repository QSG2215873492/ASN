

#include <iostream>

using namespace std;

int main()
{
    int a[19];
    int n;
    cin>>n;
    int i,j;
    for (i=0 ;i<n ; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        int m;
        for(j=0; j<n-1-i ; j++)
        {
            if(a[j]>a[j+1])
            {
                m=a[j+1];
                a[j+1]=a[j];
                a[j]=m;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
