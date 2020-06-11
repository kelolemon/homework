package chapter_7;

import java.util.Scanner;

class Point {
    int text = 0;
    Point get_class() {
        return null;
    }
}
public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        int c = 0;
        try {
            c = a / b;
        } catch (ArithmeticException e) {
            e.printStackTrace();
        }

        int[] arr = new int[10];
        try {
            System.out.println(arr[c]);
        } catch (IndexOutOfBoundsException e) {
            e.printStackTrace();
        }

        Point ExTest = new Point();
        ExTest = ExTest.get_class();
        try {
            System.out.println(ExTest.text);
        } catch (NullPointerException e) {
            e.printStackTrace();
        }
    }
}
