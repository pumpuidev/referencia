package morse;

import java.util.Scanner;

public class Morse {

    public static void main(String[] args) {
        Scanner input=new Scanner(System.in,"iso-8859-2");
        System.out.println("Írj be valamit!");
        String s=input.nextLine();
        s=s.toUpperCase();
        String[] jelek={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
                "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--",
                "-..-","-.--","--..","-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
        String betuk="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        for(int i=0;i<s.length();i++) {
            int sorszam=betuk.indexOf(s.charAt(i));
            if (sorszam>=0)
                System.out.print(jelek[sorszam]+" ");
            else
                System.out.print("   ");
        }
    }
    
}
