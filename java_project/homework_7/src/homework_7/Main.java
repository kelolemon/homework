package homework_7;

import java.io.IOException;
import java.rmi.server.ExportException;

class NonAlphabeticException extends Exception {
    NonAlphabeticException(String s) {
        super(s);
    }
}


public class Main {
    private static boolean checkAlphabet(char x){
        return (x >= 'a' && x <='z') || (x >= 'A' && x <= 'Z');
    }

    private static void ReadChar(int number) throws NonAlphabeticException, IOException {
        char input = (char) System.in.read();
        if (!checkAlphabet(input)) {
            System.out.printf("You have entered %d characters\n", number);
            throw new NonAlphabeticException("Non Alphabetic character");
        }
    }

    public static void main(String[] args) throws IOException, NonAlphabeticException {
	// write your code here
        int number = 0;
        for (; true; ) {
            ReadChar(number);
            number++;
        }
    }
}
