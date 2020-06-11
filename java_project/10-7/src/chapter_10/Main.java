package chapter_10;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class GUI {
    public GUI() {
        JFrame frame = new JFrame("10-7");
        JButton set_red = new JButton("set red");
        set_red.setBackground(Color.black);
        set_red.setForeground(Color.black);
        JButton set_blue = new JButton("set blue");
        set_blue.setBackground(Color.black);
        set_blue.setForeground(Color.black);
        JButton set_green = new JButton("set green");
        set_green.setBackground(Color.black);
        set_green.setForeground(Color.black);
        frame.setLayout(new FlowLayout());
        frame.add(set_blue);
        frame.add(set_green);
        frame.add(set_red);
        JButton exit = new JButton("exit");
        frame.add(exit);
        frame.setSize(500,500);
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                System.exit(0);
            }
        });

        set_blue.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                set_blue.setBackground(Color.blue);
                set_green.setBackground(Color.blue);
                set_red.setBackground(Color.blue);
                set_blue.setForeground(Color.blue);
                set_red.setForeground(Color.blue);
                set_green.setForeground(Color.blue);
            }
        });

        set_green.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                set_blue.setBackground(Color.green);
                set_green.setBackground(Color.green);
                set_red.setBackground(Color.green);
                set_blue.setForeground(Color.green);
                set_red.setForeground(Color.green);
                set_green.setForeground(Color.green);
            }
        });

        set_red.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                set_blue.setBackground(Color.red);
                set_green.setBackground(Color.red);
                set_red.setBackground(Color.red);
                set_blue.setForeground(Color.red);
                set_red.setForeground(Color.red);
                set_green.setForeground(Color.red);
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}

public class Main {

    public static void main(String[] args) {
	// write your code a
        GUI col = new GUI();
    }
}
