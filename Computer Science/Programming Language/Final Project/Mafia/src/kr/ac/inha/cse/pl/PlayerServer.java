package kr.ac.inha.cse.pl;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;

class PlayerSend extends Thread {
    private Socket sendSocket;

    @Override
    public void run() {
        super.run();
        try {
            BufferedReader sbuf = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter sendWriter = new PrintWriter(sendSocket.getOutputStream());

            String sendString;

            System.out.print("사용할 닉네임 입력 : ");
            PlayerServer.UserID = sbuf.readLine(); // 입력할 때마다 readline실행

            sendWriter.println("IDlinking1234" + PlayerServer.UserID);
            sendWriter.flush();

            while (true) {
                sendString = sbuf.readLine();

                if (sendString.equals("exit")) {
                    break;
                }

                sendWriter.println(sendString);
                sendWriter.flush();
            }

            sendWriter.close();
            sbuf.close();
            sendSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void setSendSocket(Socket sendSocket) {
        this.sendSocket = sendSocket;
    }

}

class PlayerReceive extends Thread {
    private Socket receiveSocket;

    public void setReceiveSocket(Socket receiveSocket) {
        this.receiveSocket = receiveSocket;
    }

    @Override
    public void run() {
        super.run();
        try {
            BufferedReader rbuf = new BufferedReader(new InputStreamReader(receiveSocket.getInputStream()));
            String receiveString;
            String[] split;

            while (true) {
                receiveString = rbuf.readLine();

                split = receiveString.split(" > ");

                if (split.length >= 2 && split[0].equals(PlayerServer.UserID)) {
                    continue;
                }

                System.out.println(receiveString);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

public class PlayerServer {
    public static String UserID;

    public static void main(String[] args) {
        try {
            InetAddress localAddress = InetAddress.getLocalHost();
            Socket cSocket = new Socket(localAddress, 8888);

            PlayerReceive recThread = new PlayerReceive();
            recThread.setReceiveSocket(cSocket);

            PlayerSend sendThread = new PlayerSend();
            sendThread.setSendSocket(cSocket);

            sendThread.start();
            recThread.start();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
