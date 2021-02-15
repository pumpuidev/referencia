package numint;

import static java.lang.Math.*;

public class Numint {
            static double a=6378137, e=0.08182;
                
        static double M(double fi) {
            return a*(1-e*e)/pow(1-e*e*sin(fi)*sin(fi),1.5);
        }

    public static void main(String[] args) {
        double RAD=PI/180;
        double fi1=20*RAD, fi2=80*RAD;
        int n=30;
        double h=(fi2-fi1)/n;
        double sum=0;
        for(int i=1;i<n;i++)
            sum+=M(fi1+h*i);
        double s=h/2*(M(fi1)+M(fi2)+2*sum);
        System.out.println("Az ívhossz "+s+" méter.");
        }
        
    }
    

