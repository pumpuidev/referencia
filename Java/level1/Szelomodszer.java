package szelomodszer;

import static java.lang.Math.*;

public class Szelomodszer {
    
     static double f(double x) {
        return cos(x)-x;
    }

    public static void main(String[] args) {
        //kezdő intervallum
      double x1=0;
      double x2=1;
      double x3;
      double e=1E-6;
      int n=0;
      do {x3=(f(x1)*x2-f(x2)*x1)/(f(x1)-f(x2));
          n++;
          x1=x2;x2=x3;
      } while (abs(f(x3))>e);
        System.out.println(n+" lépés után x="+x3+" f(x)="+f(x3));
        
    }
    
}
        
    
