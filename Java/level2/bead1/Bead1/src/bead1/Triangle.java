package bead1;

public class Triangle extends Shape {
  
    public Triangle(double x, double y, double length) {
        super(x, y, length); //ososztalynak meghivja a konstruktorat
    }

    @Override
    public double area() {
        return length * length * (Math.sqrt(3) / 4);
    }

    @Override
    public double circ() {
        return length * 3;
    }

    @Override
    public String toString() {
        return "Triangle - " + " Side length: " + length + " Circ: " + circ() + " Area: " + area() + " Diff: " + diff();
    }
}