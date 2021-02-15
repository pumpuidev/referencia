package bead1;

public class Circle extends Shape {

    public Circle(double x, double y, double length) {
        super(x, y, length);
    }
  
    @Override
    public double area() {
        return length * length * Math.PI;
    }

    @Override
    public double circ() {
        return length * Math.PI * 2;
    }

    @Override
    public String toString() {
        return "Circle - " + " Radius: " + length + " Circ: " + circ() + " Area: " + area() + " Diff: " + diff();
    }
}