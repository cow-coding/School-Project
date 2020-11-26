package kr.ac.inha.cse.pl;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.function.Supplier;
import java.util.stream.Stream;

public class HW12 implements Runnable{
    private static Socket clientSocket;

    public HW12(Socket clientSocket) {
        this.clientSocket = clientSocket;
    }

    public static void main(String[] args) {
        System.out.println("에코 서버 시작~"); // 메아리

        // port는 2byte가능 0~65535
        try(ServerSocket sSocket = new ServerSocket(10000/*포트번호*/)){ // ServerSocket 객체
            while (true) {// 계속 접속하는 client를 받아야하므로 무한 루프
                System.out.println("연결 대기 중......");
                clientSocket = sSocket.accept(); // 해당 접속 클라이언튼 정보
                HW12 tes = new HW12(clientSocket);
                new Thread(tes).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("쓰레드 에코 서버 종료");
    }

    @Override
    public void run() {
        System.out.println("클라이언트 연결됨! : " + Thread.currentThread() + " 연결됨!");
        try(
                BufferedReader br = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)
        ){
            Supplier<String> socketInput = () -> { // Supplier는 인수가 없음
                try {
                    return br.readLine(); // readLine은 입출력 예외를 반드시 해야함
                } catch (IOException e) {
                    e.printStackTrace();
                    return null; // try가 정상실행이 되지 않은 경우에 반환값 (문법만 맞춰줌)
                }
            };

            Stream<String> stream = Stream.generate(socketInput); // 반드시 supplier
            stream.map(s -> {
                        System.out.println("[ "+Thread.currentThread().getName()+" ] 클라이언트 요청: " + s);
                        out.println(s);
                        return s;
                    }).allMatch( s -> s != null);

            /*String inputLine;
            while((inputLine = br.readLine()) != null) { // 클라이언트가 보낸 메시지를 한줄 받아옴
                System.out.println("[ "+Thread.currentThread().getName()+" ] 클라이언트 요청: " + inputLine);
                out.println(inputLine); // 클라이언트에게 전송 (메아리)
                // out은 서버에 접속한 클라이언트의 주소를 담고 있음
            }*/
            System.out.println("클라이언트 종료됨! : " + Thread.currentThread() + " 종료됨!");
        }catch(IOException ex) {
            ex.printStackTrace();
        }
    }
}
