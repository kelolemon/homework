package chapter_9;

import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        // write your code here
        byte[] n = System.in.readAllBytes();
        String s = new String(n, 0, n.length);
        Writer writer = new FileWriter("out.txt");
        writer.write(s);
        writer.flush();
        writer.close();
    }
}

