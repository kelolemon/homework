package homework_9;

import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
	// write your code here
        int number = 0;
        Reader reader = new FileReader("/Users/dengmengda/kelo/java_project/homework_9/src/homework_9/test.in");
        int data = reader.read();
        while (data != -1) {
            while (data != 32 && data != -1) {
                data = reader.read();
            }
            number ++;
            data = reader.read();
        }
        reader.close();
        Writer writer = new FileWriter("/Users/dengmengda/kelo/java_project/homework_9/src/homework_9/test.out");
        String StringData = "" + number;
        writer.write(StringData);
        writer.close();
        System.out.println("Done");
    }
}
