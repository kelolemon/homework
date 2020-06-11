package homework_3;

public class circle {
    private double radius = 1;
    private circle(){

    }
    private circle(double r){
        radius = r;
    }
    private double getRadius(){
        return radius;
    }
    private void setRadius(double r){
        radius = r;
    }
    private double getArea(){
        return radius * radius * Math.PI;
    }
    private double getCircumference(){
        return radius * 2 * Math.PI;
    }
    public String toString(){
        return this.getClass() + "[radius = " + this.getRadius() + "]" ;
    }
    public static void main(String[] args) {
        circle c1 = new circle(2.0);
        System.out.println(c1.getRadius());
        System.out.println(c1.getArea());
        System.out.println(c1.getCircumference());
        c1.setRadius(3.0);
        System.out.println(c1.getCircumference());
        c1.setRadius(4.0);
        circle c2 = new circle();
        System.out.println(c1.toString());
    }
}
