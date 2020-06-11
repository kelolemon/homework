package homework_6;

interface movable {
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void show_location();
}

class movablePoint implements movable {
    int x, y, xSpeed, ySpeed;
    public movablePoint(int xi, int yi, int xs, int ys){
        x = xi;
        y = yi;
        xSpeed = xs;
        ySpeed = ys;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    @Override
    public void moveUp() {
        y = y + ySpeed;
    }

    @Override
    public void moveDown() {
        y = y - ySpeed;
    }

    @Override
    public void moveLeft() {
        x = x - xSpeed;
    }

    @Override
    public void moveRight() {
        x = x + xSpeed;
    }

    @Override
    public void show_location(){
        System.out.printf("now the point locates in (%d, %d)\n", x, y);
    }
}

class movableCircle extends movablePoint implements movable {
    int radius;
    public movableCircle(int xi, int yi, int xs, int ys, int r) {
        super(xi, yi, xs, ys);
        radius = r;
    }

    @Override
    public String toString() {
        return super.toString();
    }

    public int getRadius(){
        return radius;
    }

    public void setRadius(int r){
        radius = r;
    }

    @Override
    public void show_location(){
        System.out.printf("now the circle's radius is %d and the central point locates in (%d, %d)\n", radius, super.x, super.y);
    }
}

public class Main {

    public static void main(String[] args) {
	movable s1 = new movablePoint(1, 2, 1, 1);
	s1.show_location();
    s1.moveDown();
    s1.show_location();
    s1.moveLeft();
    s1.show_location();
    System.out.println("=====");
    movable s2 = new movableCircle(1, 3, 2, 2, 1);
    s2.show_location();
    s2.moveRight();
    s2.show_location();
    s2.moveUp();
    s2.show_location();
    }
}
