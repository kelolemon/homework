package homework_2;

public class Main {

    public static void main(String[] args) {
        System.out.println("  |    1   2   3   4   5   6   7   8   9  10  11  12");
        System.out.println("--+-------------------------------------------------");
        for (int i = 1;i <= 12;i = i + 1){
            System.out.printf("%2d|", i);
            System.out.print(" ");
            for (int j = 1; j <= 12;j = j  + 1){
                if (j < i) {
                    System.out.print("    ");
                } else {
                    System.out.printf("%4d", i * j);
                }
            }
            System.out.println("");
        }
    }
}
