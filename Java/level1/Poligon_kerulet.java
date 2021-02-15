package poligon_kerulet;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import static java.lang.Math.*;
import java.util.Scanner;


public class Poligon_kerulet {
    static double tav(double x1,double y1,double x2,double y2) {
        return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    }
    static double irany(double x1,double y1,double x2,double y2) {
        return atan2(x2-x1,y2-y1);
    }
    
    public static void main(String[] args) {
        try {
            Scanner filein=new Scanner(new FileInputStream("poligon.txt"));
            int n=filein.nextInt();
            System.out.println("Csúcsok száma: "+n);
            double[] x=new double[n];
            double[] y=new double[n];
            for(int i=0;i<n;i++) {
                x[i]=filein.nextDouble();
                y[i]=filein.nextDouble();
            }
            double k=0;
            for(int i=0;i<n;i++)
                k=k+sqrt(pow(x[(i+1)%n]-x[i],2)+pow(y[(i+1)%n]-y[i],2));
            System.out.println("A kerület: "+k);  
            double t=0;
            for(int i=1;i<n-1;i++)
                t=t+tav(x[0],y[0],x[i],y[i])*tav(x[0],y[0],x[i+1],y[i+1])*sin(irany(x[0],y[0],x[i+1],y[i+1])-irany(x[0],y[0],x[i],y[i]))/2;
            t=abs(t);
            System.out.println("A terület: "+t);
        } catch (FileNotFoundException ex) {
            System.out.println("Nincs is olyan fájl. "+ex);
        }
    }
    
}
