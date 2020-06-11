package homework_11;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CopyOnWriteArrayList;


class server_chatting_room extends ServerSocket {
    private static List<String> userList = new CopyOnWriteArrayList<String>();
    private static List<Task> threadList = new ArrayList<Task>();
    private static BlockingQueue<String> msgQueue = new ArrayBlockingQueue<String>(20);

    class Task implements Runnable {
        private Socket socket;
        private BufferedReader buff;
        private Writer writer;
        private String userName;

        public Task(Socket socket) {
            this.socket = socket;
            this.userName = String.valueOf(socket.getPort());
            try {
                this.buff = new BufferedReader(new InputStreamReader(
                        socket.getInputStream(), StandardCharsets.UTF_8));
                this.writer = new OutputStreamWriter(socket.getOutputStream(),
                        StandardCharsets.UTF_8);
            } catch (Exception e) {
                e.printStackTrace();
            }
            userList.add(this.userName);
            threadList.add(this);
            pushMsg("[" + this.userName + "enter the chatting room]");
            System.out.println("Form Client[port:" + socket.getPort() + "] "
                    + this.userName + "enter the chatting room");
        }

        @Override
        public void run() {
            try {
                while (true) {
                    String msg = buff.readLine();

                    if ("view_user".equals(msg)) {
                        sendMsg(onlineUsers());
                    } else if ("--quit".equals(msg)) {
                        sendMsg("--quit");
                        break;
                    } else {
                        pushMsg(String.format("%1$s says：%2$s", userName, msg));
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            } finally {
                try {
                    writer.close();
                    buff.close();
                    socket.close();
                } catch (Exception e) {

                }
                userList.remove(userName);
                threadList.remove(this);
                pushMsg("[" + userName + "left]");
                System.out.println("Form Client[port:" + socket.getPort() + "] "
                        + userName + "left");
            }
        }

        private void pushMsg(String msg) {
            try {
                msgQueue.put(msg);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        private void sendMsg(String msg) {
            try {
                writer.write(msg);
                writer.write("\015\012");
                writer.flush();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

        private String onlineUsers() {
            StringBuilder sbf = new StringBuilder();
            sbf.append("======== online list(").append(userList.size())
                    .append(") ========\015\012");
            for (String s : userList) {
                sbf.append("[").append(s).append("]\015\012");
            }
            sbf.append("===============================");
            return sbf.toString();
        }
    }

    public server_chatting_room(int server_port) throws IOException {
        super(server_port);
    }

    class push_message implements Runnable {

        @Override
        public void run() {
            while (true) {
                String msg = null;
                try {
                    msg = msgQueue.take();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (msg != null) {
                    for (Task thread : threadList) {
                        thread.sendMsg(msg);
                    }
                }
            }
        }
    }

    public void load() throws IOException {
        new Thread(new push_message()).start();
        while ( true ) {
            Socket socket = this.accept();
            new Thread(new Task(socket)).start();
        }
    }

}

public class server {

    public static void main(String[] args) {
	    try {
	        server_chatting_room sever = new server_chatting_room(23333);
	        sever.load();
        } catch (Exception e) {
	        e.printStackTrace();
        }
    }

}
