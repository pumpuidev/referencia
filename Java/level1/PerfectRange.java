public class PerfectRange {
    public static void main(String[] args){
        if (args.length == 1){    
            int n = Integer.parseInt(args[0]);
            int perfect = 0;
            for (int i=1; i<=n; i++){
            int temp = 0;
                for (int j=1; j<=i/2; j++){        
                    if(i%j == 0){
                        temp += j;    
                    }                
                }
                if (temp == i) {
                    perfect +=1;
                }                    
            }
            if (perfect == 0) {
                System.out.println("Egyetlen tökéletes szám sincs a megadott intervallumban.");
            }
            else {
                System.out.println(perfect + " tökéletes szám van a megadott intervallumban.");
            }
        } else {
            System.err.println("Hibás paraméterezés!");
            System.exit(0);
        }    
    } 
}
