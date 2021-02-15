
package prim;

import java.util.Scanner;


public class Prim {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int p;
        do {
            System.out.println("Írj be egy számot");
            p=input.nextInt();
            if (p==0)
                break;
            boolean prim=true;
            for(int i=2;i*i<=p;i++)
                if(p%i==0) {
                    //találtunk egy osztót
                    prim=false;
                    break;
                }
            if (prim)
                System.out.println("Ez egy prímszám.");
            else
                System.out.println("Nem prím.");
        } while (p!=0);
    }
    
}
