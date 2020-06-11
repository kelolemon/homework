package homework_10;

import javax.sound.midi.Receiver;
import java.io.*;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

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
                    if ("quit".equals(result)) {
                        System.out.println("Client[port:" + client.getLocalPort() +
                                "] you have left the chatting room");
                        break;
                    } else {
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

    public void load() throws Exception {
        writer = new OutputStreamWriter(this.getOutputStream());
        new Thread(new receive_message()).start();
        while ( true ) {
            in = new BufferedReader(new InputStreamReader(System.in));
            String msg = in.readLine();
            writer.write(msg);
            writer.write("\n");
            writer.flush();
        }
    }
}

public class client {
    public static void main(String[] args) {
        try {
            client_chatting_room client = new client_chatting_room();
            client.load();
        } catch (Exception ignored) {

        }
    }
}
