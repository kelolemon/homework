package chapter_11;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;

class GUI {
    public GUI() {
        JFrame frame = new JFrame("text");
        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(1, 2));
        JButton exit = new JButton("exit");
        JButton save = new JButton("save");
        panel.add(exit);
        panel.add(save);
        frame.add(panel);
        JTextArea textArea = new JTextArea(25,40);
        frame.add(textArea);

        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });

        save.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                try {
                    Writer writer = new FileWriter("save.txt");
                    writer.write(textArea.getText().trim());
                    writer.flush();
                    writer.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                JOptionPane.showMessageDialog(null, "The file have saved at save.txt");
            }
        });
        frame.setSize(500, 500);
        frame.setLayout(new FlowLayout());
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
public class Main {

    public static void main(String[] args) {
	// write your code here
        GUI text = new GUI();
    }
}
