package bead1;

public class Hexagon extends Shape {

    public Hexagon(double x, double y, double length) {
        super(x, y, length);
    }

    @Override
    public double area() {
        return length * length * (3 * Math.sqrt(3) / 2);
    }

    @Override
    public double circ() {
        return length * 6;
    }

    @Override
    public String toString() {
        return "Hexagon - " + " Side length: " + length + " Circ: " + circ() + " Area: " + area() + " Diff: " + diff();
    }
}