package homework_6;

interface GeometricObject {
    double GetPerimeter();
    double GetArea();
}

class circle implements GeometricObject {
    private double radius = 1.0;

    public circle(double r){
        radius = r;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    public double getRadius() {
        return radius;
    }

    @Override
    public double GetPerimeter() {
        return radius * 2 * Math.PI;
    }

    @Override
    public double GetArea() {
        return radius * radius * Math.PI;
    }

}

interface Resizable extends GeometricObject{
    void resize(int percent);
}

class ResizableCircle extends circle implements Resizable {
    public ResizableCircle(double r){
        super(r);
    }

    @Override
    public void resize(int percent) {
        super.setRadius(percent / 100.0 * getRadius());
    }
}

public class Main {

    public static void main(String[] args) {
        GeometricObject s1 = new circle(2.0);
        System.out.printf("The circle's perimeter is %f and the circle's area is %f\n", s1.GetPerimeter(), s1.GetArea());
        Resizable s2 = new ResizableCircle(3.0);
        System.out.printf("The circle's perimeter is %f and the circle's area is %f\n", s2.GetPerimeter(), s2.GetArea());
        s2.resize(10);
        System.out.printf("The circle's perimeter is %f and the circle's area is %f\n", s2.GetPerimeter(), s2.GetArea());
    }
}
