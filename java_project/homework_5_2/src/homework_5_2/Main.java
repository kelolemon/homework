package homework_5_2;

abstract class shape{
    private String color;
    private boolean filled;
    shape(){

    }
    shape(String c, boolean f){
        color = c;
        filled = f;
    }
    private String getColor(){
        return color;
    }
    private void setColor(String c){
        color = c;
    }
    private boolean isFilled(){
        return filled;
    }
    private void setFilled(boolean f){
        filled = f;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}

class circle extends shape{
    private double radius;
    circle(String c, boolean f, double r){
        super(c, f);
        radius = r;
    }
    public circle(){

    }
    public circle(double r){
        radius = r;
    }
    double getRadius(){
        return radius;
    }
    void setRadius(double r){
        radius = r;
    }
    double getArea(){
        return Math.PI * radius * radius;
    }
    double getPerimeter(){
        return 2 * Math.PI * radius;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}

class rectangle extends shape{
    private double width;
    private double length;
    rectangle(String c, boolean f, double w, double l){
        super(c, f);
        width = w;
        length = l;
    }
    public rectangle(){

    }
    rectangle(double w, double l){
        width = w;
        length = l;
    }
    double getWidth(){
        return width;
    }
    double getLength(){
        return length;
    }
    void setWidth(double w){
        width = w;
    }
    void setLength(double l){
        length = l;
    }
    double getArea(){
        return length * width;
    }
    double getPerimeter(){
        return width + length + width + length;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}

class square extends rectangle{
    public square(String c, boolean f, double s){
        super(c, f, s, s);
    }
    public square(double s){
        super(s, s);
    }
    double getSide(){
        return super.getLength();
    }
    void setSide(double s){
        super.setLength(s);
        super.setWidth(s);
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
public class Main {

    public static void main(String[] args) {
	square s1 = new square("red", true, 2.3);
	System.out.printf("the square's side is %f\n", s1.getSide());
	System.out.printf("the square's area is %f\n", s1.getArea());
	System.out.printf("the square's perimeter is %f\n", s1.getPerimeter());
	circle c1 = new circle("blue", true, 2.1);
	System.out.printf("the circle's r is %f\n", c1.getRadius());
	System.out.printf("the circle's area is %f\n", c1.getArea());
	System.out.printf("the circle's perimeter is %f\n", c1.getPerimeter());
    }
}
