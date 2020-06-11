package chapter_8;

class test {
    static int a;
    static int b;
    public test(){
        a = 10;
        b = 20;
    }

    public void setA(int i, int j) {
        a = i;
        b = j;
    }

    public void display(){
        System.out.println(a + b);
    }
}
public class Main {
    //static int ans;
    public static void main(String[] args) {
	// write your code here
        test t1 = new test();
        test t2 = new test();
        t1.display();
        t2.setA(100, 200);
        t1.display();
    }
}
