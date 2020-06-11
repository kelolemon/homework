package homework_11;

import javax.sound.midi.Receiver;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

class GUI {
    JFrame frame = new JFrame("chatting room");
    JPanel panel = new JPanel(new GridLayout(20, 1));
    client_chatting_room client;

    public GUI() throws Exception {
        panel.setSize(35,40);
        this.client = new client_chatting_room();
        this.client.load();
        frame.add(panel);
        JTextField text = new JTextField(35);
        frame.add(text);
        JButton exit = new JButton("exit");
        JButton confirmed = new JButton("confirmed");
        frame.add(confirmed);
        frame.add(exit);
        frame.setLayout(new FlowLayout());
        exit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                try {
                    client.send_message("--quit");
                } catch (Exception e) {
                    e.printStackTrace();
                }
                System.exit(1);
            }
        });

        confirmed.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                String msg = text.getText().trim();
                try {
                    client.send_message(msg);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
        frame.setLocationRelativeTo(null);
        frame.setSize(500, 500);
        frame.setVisible(true);
    }

    public void display(String msg){
        frame.setVisible(false);
        panel.add(new JLabel(msg));
        frame.setVisible(true);
    }

    class client_chatting_room extends Socket {
        private Socket client;
        private Writer writer;
        private BufferedReader in;
        public client_chatting_room() throws IOException {
            super("127.0.0.1", 23333);
            this.client = this;
            System.out.println("Client[port:" + client.getLocalPort() + "]: you have entered the chatting room");
        }

        class receive_message implements Runnable {
            private BufferedReader buff;
            @Override
            public void run() {
                try {
                    this.buff = new BufferedReader(new InputStreamReader(client.getInputStream(), StandardCharsets.UTF_8));
                    while (true) {
                        String result = buff.readLine();
                        if ("--quit".equals(result)) {
                            display("Client[port:" + client.getLocalPort() +
                                    "] you have left the chatting room");
                            System.out.println("Client[port:" + client.getLocalPort() +
                                    "] you have left the chatting room");
                            break;
                        } else {
                            display(result);
                            System.out.println(result);
                        }
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                } finally {
                    try {
                        buff.close();
                        writer.close();
                        client.close();
                        in.close();
                    } catch (Exception ignored) {

                    }
                }
            }
        }

        public void send_message(String msg) throws Exception  {
            writer = new OutputStreamWriter(this.getOutputStream());
            writer.write(msg);
            writer.write("\n");
            writer.flush();
        }

        public void load() throws Exception {
            new Thread(new receive_message()).start();
        }
    }
}


public class client {
    public static void main(String[] args) throws Exception {
        GUI chat = new GUI();
    }
}
