
package fordito;

import java.util.Scanner;

public class Fordito {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in,"iso-8859-2");
        System.out.println("Írj be valamit!");
        String s=input.nextLine();
        for(int i=s.length()-1;i>=0;i--)
        System.out.print(s.charAt(i));
    }
    
}
