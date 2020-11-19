package kr.ac.inha.java;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NotePad extends JFrame implements ActionListener{
    void addMenu(JMenuItem item , JMenu m, String MenuName) {
        item = new JMenuItem(MenuName);
        item.addActionListener(this);
        m.add(item);
    }

    NotePad() {
        setTitle("메모장");

        showCenter();
        makeMenu();

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setVisible(true);
    }

    void makeMenu() {
        JMenuItem item = null;
        JMenuBar mb = new JMenuBar();
        JMenu m1 = new JMenu("파일");
        JMenu m2 = new JMenu("편집");
        JMenu m3 = new JMenu("서식");
        JMenu m4 = new JMenu("보기");
        JMenu m5 = new JMenu("도움말");

        addMenu(item, m1, "새로 만들기");
        addMenu(item, m1, "새 창");
        addMenu(item, m1, "열기");
        addMenu(item, m1, "저장");
        addMenu(item, m1, "다른 이름으로 저장");
        addMenu(item, m1, "페이지 설정");
        addMenu(item, m1, "인쇄");
        addMenu(item, m1, "끝내기");

        addMenu(item, m2, "실행취소");
        addMenu(item, m2, "잘라내기");
        addMenu(item, m2, "복사");
        addMenu(item, m2, "붙여넣기");
        addMenu(item, m2, "삭제");
        addMenu(item, m2, "Bing으로 검색");
        addMenu(item, m2, "찾기");
        addMenu(item, m2, "다음 찾기");
        addMenu(item, m2, "이전 찾기");
        addMenu(item, m2, "바꾸기");
        addMenu(item, m2, "이동");
        addMenu(item, m2, "모두 선택");
        addMenu(item, m2, "시간/날짜");

        addMenu(item, m3, "자동 줄 바꿈");
        addMenu(item, m3, "글꼴");

        addMenu(item, m4, "확대하기/축소하기");
        addMenu(item, m4, "상태표시줄");

        addMenu(item, m5, "도움말 보내기");
        addMenu(item, m5, "피드백 보내기");
        addMenu(item, m5, "메모장 정보");

        mb.add(m1);
        mb.add(m2);
        mb.add(m3);
        mb.add(m4);
        mb.add(m5);
        setJMenuBar(mb);
    }
    void showCenter() {
        JPanel panel = new JPanel();
        JTextArea area = new JTextArea(40,34);

        panel.add(area);

        add(panel, BorderLayout.CENTER);
    }

    public static void main(String[] args) {
        new NotePad();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JMenuItem mi = (JMenuItem) (e.getSource());

        System.out.println(mi.getText()+" 메뉴를 선택했습니다.");
    }
}
