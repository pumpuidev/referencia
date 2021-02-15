
package masodfoku_egyenlet;
import static java.lang.Math.sqrt;
import java.util.Scanner;

public class Masodfoku_egyenlet {

    
    public static void main(String[] args) {
        System.out.println("a*x*x+b*x+c=0 alakú másodfokú egyenlet megoldása.");
        Scanner input=new Scanner(System.in);
        //adatok bekérése
        System.out.print("a=");
        double a=input.nextDouble();
        System.out.print("b=");
        double b=input.nextDouble();
        System.out.print("c=");
        double c=input.nextDouble();
        
        if(a==0) {
                //sima elsőfokú egyenlet
                double x=-c/b;
                System.out.println("x="+x);
        }
        else {
            double d=b*b-4*a*c;
            if (d<0) {
                System.out.println("nincs valós gyök.");
            }
            else if (d==0) {
                double x=-b/(2*a);
                System.out.println("x="+x);
            }
            else {
                double x1=(-b+sqrt(d))/(2*a);
                double x2=(-b-sqrt(d))/(2*a);
                System.out.println("x1="+x1+" x2="+x2);
            }
        }
    }
    
}
