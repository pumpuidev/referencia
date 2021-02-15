
package faktorialis;
import java.util.Scanner;
import static java.lang.Math.*;


public class Faktorialis {

    
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Írj be egy számot");
        System.out.print("x=");
        int x=input.nextInt(), fakt=1;
        while (x>1) {
            fakt=x*fakt;
            x--;
        }
        System.out.println("faktoriális="+ fakt);
        
    }
    
}
