#include <iostream>

using namespace std;

int main()
{
int n=0;
cin >> n;
int eredmeny[n];
int perc[n];
int sec[n];
for (int i=0;i<n;i++)
    {
        cin >> eredmeny[i];
        cin >> perc[i];
        cin >> sec[i];
    }
 int db=0;
for (int i = 0;i < n ; i++)
    {
      if (perc[i+1] > perc[i])
        {
            db++;
        }
       else if (perc[i+1] == perc[i])
       {
           if (perc[i+1]>perc[i])
            {
                db++;
            }
       }
    }
cout << db<<endl;
//masodik
int min = 0;
for (int i = 1; i < n; i++)
    {
        if (perc[i]*60+sec[i] < perc[min]*60+sec[min])
            {
                min = i;
            }
    }
cout << eredmeny[min]<<endl;


//harmadik
int elso=0;
for (int i = 1;i<n;i++)
    {
        if (eredmeny[i]<eredmeny[elso])
            {
                elso=i;
            }
    }
int elsohely=eredmeny[elso];
 int s=0;
 for (int i=0;i<n;i++)
 {
     if(eredmeny[i]==elsohely)
     {
         s=s+1;
     }


 }
cout << elsohely << " " << s << endl;
//negyedik

int napsz=0;
int hossz=0;
int maxnapsz=0;
int maxhossz=0;
bool allapot=0;

for (int i=0;i<n;i++)
{
	if (eredmeny[i]<4)
	{
		if(allapot==0)
		{
			allapot=1;
			napsz=i;
			hossz=1;
		}
		else
		{
			hossz++;
		}

	}
	else
	{
		if(allapot==1)
		{
			allapot=0;
			if(hossz>maxhossz)
			{
				maxhossz=hossz;
				maxnapsz=napsz;
			}
		}
	}
}

cout <<maxnapsz+1 <<" "<<maxnapsz+maxhossz;
}

