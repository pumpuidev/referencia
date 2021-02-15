package bead1;

import java.util.Scanner;
import java.io.File;
import java.io.IOException; 
import java.util.Vector;

public class Bead1 {

    Vector<Shape> shapes = new Vector<>();

    public static void main(String args[]) throws IOException {
        Bead1 bead = new Bead1();
        bead.read();
        System.out.println(bead.minDiff());
    }
    
    void read() throws IOException {
        try(Scanner sc = new Scanner(new File("test1.txt"))) {
            int i = Math.abs(sc.nextInt());
            System.out.println(i);
           // sc.nextLine();
           
            for(; i > 0; --i) {
                int type = Math.abs(sc.nextInt());
                double x = Math.abs(sc.nextDouble());
                double y = Math.abs(sc.nextDouble());
                double length = Math.abs(sc.nextDouble());
              //  sc.nextLine();
                switch(type) {
                    case 0: shapes.add(new Circle(x, y, length)); break;
                    case 3: shapes.add(new Triangle(x, y, length)); break;
                    case 4: shapes.add(new Square(x, y, length)); break;
                    case 6: shapes.add(new Hexagon(x, y, length)); break;
                }
            }
        }
        catch(IOException e) {}
    }
    
    String minDiff() {
        if(shapes.isEmpty()) return "\nThere are no shapes!";
        Shape result = shapes.get(0);
        System.out.println(result);
        
        for(int i = 1; i < shapes.size(); ++i) {
            System.out.println(shapes.get(i));
            if(shapes.get(i).diff() < result.diff()) {
                result = shapes.get(i);
            }
        }
        return "\nResult:\n" + result;
    }

}