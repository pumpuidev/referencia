
package primtenyezo;
import java.util.Scanner;
import static java.lang.Math.*;


public class Primtenyezo {

    
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        System.out.println("Írj be egy számot");
        System.out.print("p=");
        int p=input.nextInt();
        
        int o=2;
                while (p>1)
                    if(p%o==0){
                        System.out.println(o);
                        p=p/o;
                    }
                    else {
                        o++;
                    }
        
    }
    
}
