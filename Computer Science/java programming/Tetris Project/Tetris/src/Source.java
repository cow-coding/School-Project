import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.util.Random;

public class Source extends JFrame implements ActionListener, KeyListener {
    static final Color BACKGROUND = Color.WHITE;
    static final Color FIXED = Color.GRAY;
    boolean fixedBoard[][] = new boolean[20][10];
    int rotation;
    int rotClick;
    JButton board[][];
    Color colorList[] = {Color.PINK, Color.CYAN, Color.BLUE, Color.BLACK, Color.RED, Color.ORANGE, Color.MAGENTA, Color.YELLOW};
    Thread realtime;

    int speed = 1000;
    int maxBlock = 6;
    int score = -1;
    int block; // curr block type
    boolean pause = false;
    boolean reset = true; // reset flag
    boolean gameend = false; // gameend flag

    final int blockShape[][][] = {
            {
                    {5, 0}, {5, 1}, {5, 2}, {4, 2},
                    {3, 0}, {4, 0}, {5, 0}, {5, 1},
                    {5, 0}, {4, 0}, {4, 1}, {4, 2},
                    {3, 0}, {3, 1}, {4, 1}, {5, 1}
            }, // J
            {
                    {4, 0}, {4, 1}, {4, 2}, {5, 2},
                    {3, 1}, {4, 1}, {5, 1}, {5, 0},
                    {4, 0}, {5, 0}, {5, 1}, {5, 2},
                    {3, 0}, {4, 0}, {5, 0}, {3, 1}
            }, // L
            {
                    {5, 0}, {5, 1}, {5, 2}, {5, 3},
                    {3, 1}, {4, 1}, {5, 1}, {6, 1},
                    {5, 0}, {5, 1}, {5, 2}, {5, 3},
                    {3, 1}, {4, 1}, {5, 1}, {6, 1}
            }, // I
            {
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1}
            }, // O
            {
                    {6, 1}, {5, 0}, {5, 1}, {4, 0},
                    {6, 0}, {6, 1}, {5, 1}, {5, 2},
                    {6, 1}, {5, 0}, {5, 1}, {4, 0},
                    {6, 0}, {6, 1}, {5, 1}, {5, 2},
            }, // Z
            {
                    {5, 0}, {4, 0}, {4, 1}, {3, 1},
                    {3, 0}, {3, 1}, {4, 1}, {4, 2},
                    {5, 0}, {4, 0}, {4, 1}, {3, 1},
                    {3, 0}, {3, 1}, {4, 1}, {4, 2}
            }  // Z reverse
    };

    int currBlockShape[][][] = {
            {
                    {5, 0}, {5, 1}, {5, 2}, {4, 2},
                    {3, 0}, {4, 0}, {5, 0}, {5, 1},
                    {5, 0}, {4, 0}, {4, 1}, {4, 2},
                    {3, 0}, {3, 1}, {4, 1}, {5, 1}
            }, // J
            {
                    {4, 0}, {4, 1}, {4, 2}, {5, 2},
                    {3, 1}, {4, 1}, {5, 1}, {5, 0},
                    {4, 0}, {5, 0}, {5, 1}, {5, 2},
                    {3, 0}, {4, 0}, {5, 0}, {3, 1}
            }, // L
            {
                    {5, 0}, {5, 1}, {5, 2}, {5, 3},
                    {3, 1}, {4, 1}, {5, 1}, {6, 1},
                    {5, 0}, {5, 1}, {5, 2}, {5, 3},
                    {3, 1}, {4, 1}, {5, 1}, {6, 1}
            }, // I
            {
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1},
                    {5, 0}, {5, 1}, {4, 0}, {4, 1}
            }, // O
            {
                    {6, 1}, {5, 0}, {5, 1}, {4, 0},
                    {6, 0}, {6, 1}, {5, 1}, {5, 2},
                    {6, 1}, {5, 0}, {5, 1}, {4, 0},
                    {6, 0}, {6, 1}, {5, 1}, {5, 2},
            }, // Z
            {
                    {5, 0}, {4, 0}, {4, 1}, {3, 1},
                    {3, 0}, {3, 1}, {4, 1}, {4, 2},
                    {5, 0}, {4, 0}, {4, 1}, {3, 1},
                    {3, 0}, {3, 1}, {4, 1}, {4, 2}
            }  // Z reverse
    };

    Source() {
        Init();
        MakeMenu();

        setSize(500, 1000);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setVisible(true);

        addKeyListener(this);
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);
    }

    boolean columnFull() {
        for (int i = 0; i < 10; i++) {
            if (fixedBoard[0][i]) return true;
        }

        return false;
    }

    void rowDelete() {
        int lastdel = 0;
        int delblock = 0;

        for (int i = 19; i > -1; i--) {
            boolean rowCheck = true;

            for (int j = 0; j < 10; j++) {
                if (!fixedBoard[i][j]) {
                    rowCheck = false;
                    break;
                }
            }

            if (rowCheck) {
                // rowCheck true -> row delete
                for (int j = 0; j < 10; j++) {
                    board[i][j].setBackground(BACKGROUND);
                    fixedBoard[i][j] = false;
                    score++;
                }
                delblock++;
                lastdel = i;
            }
        }

        for (int i = lastdel - 1; i > -1; i--) {
            for (int j = 0; j < 10; j++) {
                fixedBoard[i + delblock][j] = fixedBoard[i][j];
                fixedBoard[i][j] = false;
            }
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (fixedBoard[i][j]) board[i][j].setBackground(FIXED);
            }
        }
    }

    void makeBlock() {
        this.rotation = 0;
        this.rotClick = 0;

        Random rand = new Random();
        block = rand.nextInt(maxBlock);
        int coloridx = rand.nextInt(8);

        for (int i = 0; i < 4; i++) {
            int x = currBlockShape[block][i][0];
            int y = currBlockShape[block][i][1];

            board[y][x].setBackground(colorList[coloridx]);
        }

        reset = false;
    }

    void currBlockInit() {
        for (int i = 0; i < 16; i++) {
            currBlockShape[block][i][0] = blockShape[block][i][0];
            currBlockShape[block][i][1] = blockShape[block][i][1];
        }
    }

    void boardFixed() {
        for (int i = 0; i < 4; i++) {
            int x = currBlockShape[block][i + rotation][0];
            int y = currBlockShape[block][i + rotation][1];

            fixedBoard[y][x] = true;
        }

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (fixedBoard[i][j]) board[i][j].setBackground(FIXED);
            }
        }

        rowDelete();
        reset = true;
        currBlockInit(); // block point reset
    }

    boolean isCollied(int x, int y, int rot) {
        for (int i = 0; i < 4; i++) {
            int currx = currBlockShape[block][i + rot][0];
            int curry = currBlockShape[block][i + rot][1];
            int nx = currx + x;
            int ny = curry + y;

            if (nx > 9 || nx < 0) return true;
            if (ny > 19 || ny < 0) return true;
            if (fixedBoard[ny][nx]) return true;
        }

        return false;
    }

    void filleWhite() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (!fixedBoard[i][j]) board[i][j].setBackground(BACKGROUND);
            }
        }
    }

    void blockDown() {
        if (columnFull()) gameEnd();

        Color curr = null;

        if (!isCollied(0, 1, rotation)) {
            for (int i = 0; i < 4; i++) {
                int currx = currBlockShape[block][i + rotation][0];
                int curry = currBlockShape[block][i + rotation][1];
                curr = board[curry][currx].getBackground();
            }

            for (int i = 0; i < 16; i++)
                currBlockShape[block][i][1]++;

            filleWhite();

            for (int i = 0; i < 4; i++) {
                int x = currBlockShape[block][i + rotation][0];
                int y = currBlockShape[block][i + rotation][1];

                board[y][x].setBackground(curr);
            }
        }else{
            boardFixed();
        }
    }

    void save() throws IOException {
        String path = "C:\\save";
        String fileName = "save.txt";
        File folder = new File(path);

        if (!folder.exists()) {
            try {
                folder.mkdir();
            }catch (Exception e) {
                e.printStackTrace();
            }
        }

        FileOutputStream output = null;

        try {
            output = new FileOutputStream(path+"\\"+fileName);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        String data = new String();
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++){
                if (fixedBoard[i][j]) {
                    data += "1 ";
                }else {
                    data += "0 ";
                }
            }
            data += "\n";
        }

        output.write(data.getBytes());
        output.close();
    }

    void load() {
        FileInputStream input = null;

        File file = new File("C:\\save\\save.txt");

        try {
            input = new FileInputStream(file);
            int i = 0;
            int row = 0;
            int col = 0;

            while ((i = input.read()) != -1) {
                if ((char)i == ' ' || (char)i == '\n') continue;

                if (col > 9) {
                    row++;
                    col = 0;
                }
                if ((char)i == '1') fixedBoard[row][col] = true;
                else if ((char)i == '0') fixedBoard[row][col] = false;

//                System.out.println(row+"행 "+col+"열 : "+(char)i);
                col++;
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    void move(int point) {
        Color curr = null;

        if (!isCollied(point, 0, rotation)) {
            for (int i = 0; i < 4; i++) {
                int currx = currBlockShape[block][i + rotation][0];
                int curry = currBlockShape[block][i + rotation][1];

                curr = board[curry][currx].getBackground();
            }

            for (int i = 0; i < 16; i++)
                currBlockShape[block][i][0] += point;

            filleWhite();

            for (int i = 0; i < 4; i++) {
                int x = currBlockShape[block][i + rotation][0];
                int y = currBlockShape[block][i + rotation][1];

                board[y][x].setBackground(curr);
            }
        }
    }

    void rotate(int direction) {
        int newRotation = rotation + 4 * direction;

        if (newRotation > 12) newRotation = 0;
        if (newRotation < 0 ) newRotation = 12;

        if (!isCollied(0, 0, newRotation)) {
            Color curr = null;
            for (int i = 0; i < 4; i++) {
                int currx = currBlockShape[block][i + rotation][0];
                int curry = currBlockShape[block][i + rotation][1];

                curr = board[curry][currx].getBackground();
            }

            rotation = newRotation;
            filleWhite();

            for (int i = 0; i < 4; i++) {
                int x = currBlockShape[block][i + rotation][0];
                int y = currBlockShape[block][i + rotation][1];

                board[y][x].setBackground(curr);
            }
        }
    }

    void gameStart() {
        gameend = false;
        reset = true;
        realtime = new Thread() {
            @Override
            public void run() {
                int x = 1;
                while (!gameend) {
                    while (pause){}

                    try {
                        Thread.sleep(speed);
//                        System.out.println(x);

                        if (reset) {
                            makeBlock();
                            Thread.sleep(speed);
                        }

                        blockDown();
                    } catch (InterruptedException e) {

                    }
                }
            }
        };

        realtime.start();
    }

    void gameEnd() {
        gameend = true;
        System.out.println("게임 종료!");

        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (!fixedBoard[i][j]) board[i][j].setBackground(BACKGROUND);
            }
        }

        realtime.interrupt();
    }

    void Init() {
        board = new JButton[20][10];

        setLayout(new GridLayout(20, 10));
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                board[i][j] = new JButton();
                add(board[i][j]);
                board[i][j].setBackground(BACKGROUND);
            }
        }
    }

    void MakeMenu() {
        JMenuItem item = null;
        JMenuBar mb = new JMenuBar();
        JMenu m1 = new JMenu("게임");
        JMenu m2 = new JMenu("파일");
        JMenu m3 = new JMenu("종료");

        AddMenu(item, m1, "게임 시작");
        AddMenu(item, m1, "일시정지");

        JMenu subMenu = new JMenu("난이도 선택");
        AddMenu(item, subMenu, "쉬움");
        AddMenu(item, subMenu, "보통");
        AddMenu(item, subMenu, "어려움");
        m1.add(subMenu);

        AddMenu(item, m3, "게임 종료");

        AddMenu(item, m2, "파일 저장");
        AddMenu(item, m2, "파일 불러오기");

        mb.add(m1);
        mb.add(m2);
        mb.add(m3);

        setJMenuBar(mb);
    }

    void AddMenu(JMenuItem item, JMenu m, String MenuName) {
        item = new JMenuItem(MenuName);
        item.addActionListener(this);
        m.add(item);
    }

    public static void main(String[] args) {
        new Source();
    }

    void endPrint() {
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 4 || i == 8) {
                    if (j >= 0 && j <= 2) board[i][j].setBackground(Color.BLACK);
                    if (j == 7 || j == 8) board[i][j].setBackground(Color.BLACK);
                }else if (i == 5) {
                    if (j == 0 || j == 3 || j == 6 || j == 7 || j == 9) board[i][j].setBackground(Color.BLACK);
                }else if (i == 6) {
                    if (j >= 0 && j <= 2) board[i][j].setBackground(Color.BLACK);
                    if (j == 3 || j == 4 || j == 6 || j == 7 || j == 9) board[i][j].setBackground(Color.BLACK);
                }else if (i == 7) {
                    if (j == 0 || j == 3 || j == 5 || j == 6 || j == 7 || j == 9) board[i][j].setBackground(Color.BLACK);
                }
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JMenuItem value = (JMenuItem) e.getSource();

        if (value.getText().equals("게임 시작")) {
            if (score == -1) score = 0;
            pause = false;
            gameStart();
        }else if (value.getText().equals("게임 종료")) {
            gameEnd();

            endPrint();
        }else if (value.getText().equals("파일 저장")) {
            try {
                save();
            } catch (IOException ioException) {
                ioException.printStackTrace();
            }
        }else if (value.getText().equals("파일 불러오기")) {
            load();
            for (int i = 0; i < 20; i++){
                for (int j = 0; j < 10; j++) {
                    if (fixedBoard[i][j]) board[i][j].setBackground(FIXED);
                }
            }
        }else if (value.getText().equals("쉬움")) {
            speed = 1000;
            maxBlock = 4;
        }else if (value.getText().equals("중간")) {
            speed = 600;
            maxBlock = 6;
        }else if (value.getText().equals("어려움")) {
            speed = 300;
            maxBlock = 6;
        }else if (value.getText().equals("일시정지")) {
            pause = true;
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        switch (e.getKeyCode()) {
            case KeyEvent.VK_RIGHT:
                System.out.println("Right");
                move(+1);
                break;

            case KeyEvent.VK_LEFT:
                System.out.println("Left");
                move(-1);
                break;

            case KeyEvent.VK_SPACE:
                blockDown();
                break;

            case KeyEvent.VK_UP:
                System.out.println("Up");
                rotate(1);
                break;

            case KeyEvent.VK_DOWN:
                System.out.println("Down");
                score++;
                rotate(-1);
                break;
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}