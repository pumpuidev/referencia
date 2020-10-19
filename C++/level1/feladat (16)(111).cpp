#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int h[n][5];
    for(int i=0; i<n; i++)
        {for(int j=0; j<5; j++)
             {
                 cin >>h[i][j];

             }

        }

    //a feladat

    for(int i=0; i<n; i++)
        {int S=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]<=k && h[i][j]>0)
                {
                   S=S+1+(k-h[i][j])*2;
                }

            }cout << S <<" ";

        }cout << endl;

    //b feladat
for(int j=0; j<5; j++)
      {int db=0;
          for(int i=0; i<n; i++)
          {
            if(h[i][j]>0)
                {
                db++;
                }

          }cout << db <<" ";

      }cout << endl;
    //c feladat
     int db2=0;
     for(int i=0; i<n; i++)
        {int db=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]<=k && h[i][j]>0)
                {
                   db++;
                }

            }if(db==5)
                {db2++;}

        }cout << db2 <<" ";


     for(int i=0; i<n; i++)
        {int db=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]<=k && h[i][j]>0)
                {
                   db++;
                }

            }if(db==5)
                {cout << i+1 <<" ";}

        }cout << endl;

   //d feladat
    db2=0;
     for(int i=0; i<n; i++)
        {int db=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]==1)
                {
                   db++;
                }

            }if(db>0)
                {db2++;}

        }cout << db2 <<" ";


     for(int i=0; i<n; i++)
        {int db=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]==1)
                {
                   db++;
                }

            }if(db>0)
                {cout << i+1 <<" ";}

        }cout << endl;

      //e feladat
      int lepteto=0;
      int helyezesek[n];
      for(int i=0; i<n; i++)
        {int S=0;
            for(int j=0; j<5; j++)
            {
                if(h[i][j]<=k && h[i][j]>0)
                {
                   S=S+1+(k-h[i][j])*2;
                }

            }lepteto++;
            helyezesek[lepteto-1]=S;

        }
     int i;
     int j;

       int db=0;
       int szamlalo[n];
       for(int l=0; l<n; l++)
          { db++;
            szamlalo[db-1]=l+1;
          }


       /*for(int i=0; i<db; i++)
          {
           cout << szamlalo[i] <<" ";
          }*/

       /*int plusz=k;*/
       for(i=0; i<lepteto-1; i++)
        {for(j=i+1; j<lepteto; j++)
             {if(helyezesek[i] < helyezesek[j])
                {
                 int csere = helyezesek[i];
                 helyezesek [i] = helyezesek [j];
                 helyezesek [j]=csere;

                 csere = szamlalo[i];
                 szamlalo[i]=szamlalo[j];
                 szamlalo[j]=csere;

                }
                if(helyezesek[i]==helyezesek[j] && szamlalo[i]>szamlalo[j])
                    {int csere = szamlalo[j];
                     szamlalo[j]= szamlalo[i];
                     szamlalo[i]=csere;

                    }

             }

        }
        if(helyezesek[i]==helyezesek[i+1] && szamlalo[i+1]>k)
                    {
                      k++;
                    }
        /*cout << k << endl;*/
      /*for(int i=0; i<lepteto; i++)
         {
          cout <<helyezesek[i]<<" ";

         }
         cout << endl;*/


/*for(int i=0; i<k; i++)
         {if(helyezesek[i]=helyezesek[i]+1 && szamlalo[i]>szamlalo[i+1])
              {int csere=szamlalo[i+1];
               szamlalo[i+1]=szamlalo[i];
               szamlalo[i]=csere;


              }


         }
  cout << endl;*/

    /*cout << k <<" ";*/
    /*int plusz = k;
    cout << plusz << endl;*/


    cout << k <<" ";
    for(int i=0; i<k; i++){
         {
          cout <<szamlalo[i]<<" ";

         }
    }cout << endl;

    return 0;
}
