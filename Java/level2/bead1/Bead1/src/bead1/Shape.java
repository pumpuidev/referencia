package bead1;


public class Shape {

    private final double x; //final - nem valtozik az ertek
    private final double y;
    protected final double length;

    public Shape(double x, double y, double length) {
        this.x = x;
        this.y = y;
        this.length = length;
    }
    
    public double area(){
        return 0.0;
    }
    
    public double circ(){
        return 0.0;
    }
    
    public double diff(){
        return Math.abs(area() - circ());
    }
}