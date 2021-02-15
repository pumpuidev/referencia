#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int i,j,csillag;
    cout<<"hany csillag"<<endl; // hany darabrol induljon - int csillag;
    cin>>csillag;
    for(i=csillag;i>=1;i--){     //  i= 'hany darab'
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
