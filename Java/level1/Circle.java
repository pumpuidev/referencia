class Circle {

    double x, y;
    double radius;

    void enlarge(double factor) {
        radius *= factor;
    }

    double getArea() {
        return Math.PI*radius*radius;
    }

}

