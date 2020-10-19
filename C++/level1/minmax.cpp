#include <iostream>
#include <fstream>

using namespace std;

const int maxn=100;
struct pont{
    int x,y;
};

void beolvasas(char fnev[20],int&n,pont pontok[]){
    ifstream input(fnev,ios::in);
    input>>n;
    for(int i=0;i<n;++i){
        input>>pontok[i].x>>pontok[i].y;
    }
    input.close();
}

int minx(const int n,pont pontok[]){
    int min=0;
    for(int i=1;i<n;++i){
        if(pontok[i].x<pontok[min].x){
            min=i;
        }
    }
    return pontok[min].x;
}

int miny(const int n,pont pontok[]){
    int min=0;
    for(int i=1;i<n;++i){
        if(pontok[i].y<pontok[min].y){
            min=i;
        }
    }
    return pontok[min].y;
}

int maxx(const int n,pont pontok[]){
    int max=0;
    for(int i=1;i<n;++i){
        if(pontok[i].x>pontok[max].x){
            max=i;
        }
    }
    return pontok[max].x;
}

int maxy(const int n,pont pontok[]){
    int max=0;
    for(int i=1;i<n;++i){
        if(pontok[i].y>pontok[max].y){
            max=i;
        }
    }
    return pontok[max].y;
}

void meghataroz(const int n, pont pontok[],pont&ba,pont&jf){
    ba.x=minx(n,pontok);
    ba.y=miny(n,pontok);
    jf.x=maxx(n,pontok);
    jf.y=maxy(n,pontok);
}

void kiiras(const pont ba,const pont jf){
    cout<<"ba-x: "<<ba.x<<" ba-y: "<<ba.y<<endl;
    cout<<"jf-x: "<<jf.x<<" jf-y: "<<jf.y<<endl;
}

int main()
{
    int n;
    pont pontok[maxn];
    pont ba,jf;
    char fnev[20];
    cout<<"Adja meg a fajl nevet: ";
    cin>>fnev;
    beolvasas(fnev,n,pontok);
    meghataroz(n,pontok,ba,jf);
    kiiras(ba,jf);
    return 0;
}
