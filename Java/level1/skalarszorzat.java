
package pkg2_vektor_skalarszorzata;

import java.util.Scanner;


public class Main {

    
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        //adatok beolvasása
        System.out.print("vektorok hossza:");
        int n=input.nextInt();
        double[] a=new double[n];
        double[] b=new double[n];
        for(int i=0;i<n;i++) {
            System.out.print("a"+i+"=");
            a[i]=input.nextDouble();
        }
        for(int i=0;i<n;i++) {
            System.out.print("b"+i+"=");
            b[i]=input.nextDouble();
        }
        //számolunk
        double s=0;
        for(int i=0;i<n;i++)
            s+=a[i]*b[i];
        //kiírjuk a végeredményt
        System.out.println("a skalárszorzat: "+s);
    }
        
    
}
