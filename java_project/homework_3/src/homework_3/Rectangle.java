package homework_3;

public class Rectangle {
    float length = 1.0f;
    float width = 1.0f;
    private Rectangle(){

    }
    private Rectangle(float l, float w){
        length = l;
        width = w;
    }
    private float getLength(){
        return length;
    }
    private void setLength(float l){
        length = l;
    }
    private float getWidth(){
        return width;
    }
    private void setWidth(float w){
        width = w;
    }
    private double getArea(){
        return length * width;
    }
    private double getPerimeter(){
        return length + width + length + width;
    }
    public String toString(){
        return this.getClass() + "[length = " + this.getLength() + ", width = " + this.getWidth() + "]";
    }
    public static void main(String[] args) {
        Rectangle r1 = new Rectangle(1, 2);
        System.out.println(r1.getArea());
        System.out.println(r1.getPerimeter());
        r1.setLength(2);
        r1.setWidth(4);
        System.out.println(r1.toString());
    }
}
