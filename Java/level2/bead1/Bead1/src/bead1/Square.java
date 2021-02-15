package bead1;

public class Square extends Shape {   //kiegészít

    public Square(double x, double y, double length) {
        super(x, y, length);
    }
  
    @Override
    public double area() {
        return length * length;
     }

    @Override
    public double circ() {
        return length * 4;
    }
    
    @Override
    public String toString() {
        return "Square - " + " Side length: " + length + " Circ: " + circ() + " Area: " + area() + " Diff: " + diff();
    }
}