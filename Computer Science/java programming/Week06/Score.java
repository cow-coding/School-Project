package kr.ac.java.inha;

import java.lang.annotation.ElementType;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Score {

    public static void main(String[] args) {
        Map<String, Character> student = new HashMap<String, Character>();
        Scanner sc = new Scanner(System.in);
        int student_num = 1;

        while (true) {
            System.out.print("학생"+student_num+"의 이름을 입력하세요? : ");
            String name = sc.next();

            if (name.equals("exit")) break;

            System.out.print("점수"+student_num+"을 입력하세요 : ");
            int score = sc.nextInt();
            char grade;

            if (score >= 90) grade = 'A';
            else if (score >= 80) grade = 'B';
            else if (score >= 70) grade = 'C';
            else if (score >= 60) grade = 'D';
            else grade = 'F';

            student.put(name, grade);
            student_num++;
        }

        int idx = 1;
        for (Map.Entry<String, Character> ent : student.entrySet()) {
            System.out.println(idx + "번째 학생 " + ent.getKey() + "의 등급은 " + ent.getValue() + "입니다.");
            idx++;
        }
    }
}
