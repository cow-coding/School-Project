package kr.ac.inha.cse.pl;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;


class GameManager extends Thread {
    public CyclicBarrier barrier;
    private String role;
    private Socket mSocket;
    private String mID;
    private boolean isVote;
    public boolean isDie;
    public int voteCount;

    public void setVoteCount(int c) {
        voteCount = c;
    }

    public int getVoteCount() { return voteCount; }

    public GameManager() {}

    public GameManager(CyclicBarrier barrier, String role) {
        this.barrier = barrier;
        this.role = role;
        isVote = false;
        isDie = false;
        voteCount = 0;
    }

    public void setDie(boolean d) {
        isDie = d;
    }

    public void setVote(boolean v) {
        isVote = v;
    }

    public String getmID() {
        return mID;
    }

    public void socketClose() throws IOException {
        mSocket.close();
    }

    public void barrierWait() throws BrokenBarrierException, InterruptedException {
        this.barrier.await();
    }

    public String getRole() {
        return role;
    }

    public Socket getmSocket() {
        return mSocket;
    }

    // 채팅 전송 관련 run method
    @Override
    public void run() {
        super.run();

        try {
            BufferedReader rbuf = new BufferedReader(new InputStreamReader(mSocket.getInputStream()));
            PrintWriter out = new PrintWriter(mSocket.getOutputStream(), true);
            String text;

            while (true) {

                // 플레이어 입장 관련
                text = rbuf.readLine();

                if (isDie) {
                    out.println("당신은 죽어서 말을 할 수 없습니다!!!!");

                    continue;
                }

                if (text == null) {
                    System.out.println(mID + "이(가) 나갔습니다.");

                    if (role.equals("Mafia")) {
                        GameServer.mafiaNum--;
                    }else {
                        GameServer.citizenNum--;
                    }

                    for (int i = 0; i < GameServer.mOutputList.size(); i++) {
                        GameServer.mOutputList.get(i).println(mID + "이(가) 나갔습니다.");
                        GameServer.mOutputList.get(i).flush();
                    }
                    break;
                }

                String[] split = text.split("linking1234");

                if (split.length == 2 && split[0].equals("ID")) {
                    mID = split[1];
                    System.out.println(mID + "이(가) 입장했습니다.");

                    for (int i = 0; i < GameServer.mOutputList.size(); i++) {
                        GameServer.mOutputList.get(i).println(mID + "이(가) 입장했습니다.");
                        GameServer.mOutputList.get(i).flush();
                    }

                    out.println("당신은 " + role + "입니다");
                    continue;
                }

                split = text.split("vote "); // vote command !voteID

                if (split.length == 2 && split[0].equals("!") && !isVote) {
                    isVote = true;
                    GameServer.setVote(split[1]);

                    for (int i = 0; i < GameServer.mOutputList.size(); i++) {
                        GameServer.mOutputList.get(i).println(mID + "이(가) 투표를 완료했습니다.");
                        GameServer.mOutputList.get(i).flush();
                        GameServer.mOutputList.get(i).println("사회자 > 현재 투표 상황 : " + GameServer.getVotePeople() + " / " + GameServer.getTotalNum());
                    }

                    continue;
                }

                split = text.split("mafia ");

                if (split.length == 2 && split[0].equals("!") && role.equals("Mafia")) {
                    GameServer.mafiaVote = true;
                    GameServer.mafiaKill(split[1]);
                }

                for (int i = 0; i < GameServer.mOutputList.size(); i++) {
                    GameServer.mOutputList.get(i).println(mID + " > " + text);

                    GameServer.mOutputList.get(i).flush();
                }
            }

            GameServer.mOutputList.remove(new PrintWriter(mSocket.getOutputStream()));
            mSocket.close();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (BrokenBarrierException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void setM_socket(Socket mSocket) {
        this.mSocket = mSocket;
    }
}

public class GameServer {
    public static ArrayList<PrintWriter> mOutputList;
    public static ArrayList<GameManager> playerList;
    public static boolean[] isDie;
//    public static HashMap<String, Integer> vote;
    public static int votePeople = 0;
    public static int mafiaNum;
    public static int citizenNum;
    public static int totalNum;
    public static boolean morning;
    public static boolean mafiaVote;
    public static String killID;

    public static int getTotalNum() { return totalNum; }

    public static void mafiaKill(String id) throws BrokenBarrierException, InterruptedException {
        System.out.println("mafia kill code on");

        mafiaVote = true;
        killID = id;
    }

    public static void gameCount() throws InterruptedException {
        for (int i = 0; i < mOutputList.size(); i++) {
            mOutputList.get(i).println("사회자 > 잠시후 게임이 시작됩니다.");
        }

        Thread.sleep(1000);

        for (int i = 3; i > -1; i--) {
            for (int j = 0; j < mOutputList.size(); j++)
                mOutputList.get(j).println(i);
            Thread.sleep(1000);
        }

        for (int i = 0; i < mOutputList.size(); i++) {
            mOutputList.get(i).println("사회자 > Game Start!");
        }
    }

    public static void Morning() {
        // Init part
        mafiaVote = false;
        votePeople = 0;

        for (int i = 0; i < playerList.size(); i++){
            playerList.get(i).setVoteCount(0);
            playerList.get(i).setVote(false);
        }

        for (int i = 0; i < mOutputList.size(); i++) {
            mOutputList.get(i).println("\n사회자 > 아침이 밝았습니다! 대화를 하고 투표를 통해 추방할 한 명을 골라주세요.");
            mOutputList.get(i).println("사회자 > 투표방법 : !vote 닉네임");
        }
    }

    public static boolean allVote() {
        return votePeople == citizenNum + mafiaNum;
    }

    public static void setVote(String id) {
        int val = 0;

        for (int i = 0; i < playerList.size(); i++) {
            if (playerList.get(i).getmID().equals(id)) {
                playerList.get(i).setVoteCount(playerList.get(i).getVoteCount() + 1);

                break;
            }
        }

        votePeople++;
    }

    public static int getVotePeople() { return votePeople; }

    public static void allPrint(String input) {
        for (int i = 0; i < mOutputList.size(); i++) {
            mOutputList.get(i).println(input);
        }
    }

    public static boolean isEnd() {
        if (mafiaNum == 0) return true;
        if (mafiaNum == citizenNum) return true;

        return false;
    }

    public static void setTotalNum(int t) {
        totalNum = t;
    }

    public static boolean isMorning() {
        return morning;
    }

    public static void main(String[] args) {
        mOutputList = new ArrayList<PrintWriter>();
        playerList = new ArrayList<GameManager>();

        morning = true;
        int playerNum = 0;
        totalNum = 0;
        Scanner sc = new Scanner(System.in);
        mafiaNum = 0;
        citizenNum = 0;
        killID = "";

        try {
            ServerSocket sSocket = new ServerSocket(8888);

            System.out.println("서버가 생성되었습니다!");
            System.out.print("플레이어 수를 입력해주세요 : ");
            playerNum = sc.nextInt();
            isDie = new boolean[playerNum];

            CyclicBarrier barrier = new CyclicBarrier(playerNum - 1, () -> System.out.println("Game Over!"));

            while (totalNum < playerNum) {
                Random rand = new Random();
                int m = rand.nextInt(4);

                Socket cSocket = sSocket.accept();
                GameManager pManager = null;

                if (m == 0 && mafiaNum == 0) {
                     pManager = new GameManager(barrier, "Mafia");
                     mafiaNum++;
                }else {
                    if (mafiaNum == 0 && totalNum == playerNum - 1) {
                        pManager = new GameManager(barrier, "Mafia");
                        mafiaNum++;
                    }
                    else pManager = new GameManager(barrier, "Citizen");
                    citizenNum++;
                }

                pManager.setM_socket(cSocket);


                playerList.add(pManager);
                mOutputList.add(new PrintWriter(cSocket.getOutputStream(), true));
                pManager.start();
                totalNum++;
            }

            Thread.sleep(2000);
            gameCount();

            boolean print = false;

            while (!isEnd()) {
                while (isMorning()) {
                    if (!print){
                        Morning();
                        print = true;
                    }

                    System.out.println("루프 돌아가는중");

                    if (votePeople == totalNum) {
                        System.out.println("루프 멈춤");
                        // 모두 투표완료
                        morning = false;

                        allPrint("사회자 > 모두 투표를 완료했습니다!");
                        allPrint("사회자 > 투표 결과를 공개합니다!\n");

                        Thread.sleep(3000);

                        int max = -1;
                        String whoDie = "";

                        for (int i = 0; i < playerList.size(); i++) {
                            if (playerList.get(i).getVoteCount() > max) {
                                max = playerList.get(i).getVoteCount();
                                whoDie = playerList.get(i).getmID();
                            }else if (playerList.get(i).getVoteCount() == max) {
                                whoDie = "no";
                            }
                        }

                        if (whoDie.equals("no")) {
                            allPrint("사회자 > 동률이 나왔으므로 아무도 추방당하지 않았습니다.");
                        }else {
                            allPrint("사회자 > 이번 라운드 탈락자는 " + whoDie + "입니다.");

                            for (int i = 0;i < playerList.size(); i++) {
                                if (playerList.get(i).getmID().equals(whoDie)) {
                                    if (playerList.get(i).getRole().equals("Mafia")) {
                                        allPrint("사회자 > "+whoDie+"는 Mafia였습니다.");
                                        mafiaNum--;
                                    }else {
                                        allPrint("사회자 > "+whoDie+"는 Citizen이였습니다.");
                                        citizenNum--;
                                    }
                                    playerList.get(i).setDie(true);
                                    isDie[i] = true;
                                    totalNum--;
                                }
                            }
                        }

                        System.out.println("아침 종료 코드");

                        morning = false;
                        print = false;
                        break;
                    }
                }

                if (isEnd()) {
                    System.out.println("종료");
                    break;
                }

                allPrint("\n사회자 > 밤이 되었습니다.\n");

                Thread.sleep(3000);

                for (int i = 0; i < playerList.size(); i++) {
                    if (playerList.get(i).getRole().equals("Mafia")) {
                        mOutputList.get(i).println("사회자 > 제거할 사람을 골라주세요.");
                        mOutputList.get(i).println("사회자 > 투표방법 : !mafia 닉네임");
                    }
                }

                while (!isMorning()) {
                    System.out.println("밤 진행 중");

                    if (mafiaVote) {
                        System.out.println("마피아 투표완료");

                        for (int i = 0; i < playerList.size(); i++) {
                            if (playerList.get(i).getmID().equals(killID)) {
                                //playerList.get(i).barrier.await();

                                if (playerList.get(i).getRole().equals("Mafia")) {
                                    mafiaNum--;
                                }else {
                                    citizenNum--;
                                }

                                playerList.get(i).setDie(true);
                                isDie[i] = true;
                                break;
                            }
                        }

                        allPrint("사회자 > Mafia가 "+ killID + "를 죽였습니다!");
                        totalNum--;
                        morning = true;
                        break;
                    }
                }
            }



            if (isEnd()) {
                if (mafiaNum == 0) {
                    allPrint("사회자 > Citizen이 승리했습니다!");
                }else {
                    allPrint("사회자 > Mafia가 승리했습니다!");
                }
            }

            for (int i = 0; i < playerList.size(); i++) {
                playerList.get(i).setDie(false);
            }

            allPrint("사회자 > exit를 입력해 게임을 나가주세요");

//            if (endPeople == playerNum) {
//                for (int i = 0; i < playerList.size(); i++) {
//                    mOutputList.remove(new PrintWriter(playerList.get(i).getmSocket().getOutputStream()));
//                    playerList.get(i).socketClose();
//                }
//            }

        } catch (IOException | InterruptedException e) {
            e.printStackTrace();
        }
//        } catch (BrokenBarrierException e) {
//            e.printStackTrace();
//        }
    }
}
