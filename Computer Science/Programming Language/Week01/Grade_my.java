package kr.ac.inha.cse.pl;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
// 과제
// if문 X, else문 X, 출력구문 1개만, : 사용금지, break 사용금지, 캐스팅 X
// 위 조건을 최대한 만족시키면서 아래 코드와 같은 결과를 내는 코드를 Stream, 람다식등을 써서 작성하시오.

public class Grade {
	public static void main(String[] args) {
		Scanner scv = new Scanner(System.in);
		System.out.println("점수 입력 : ");
		int score = scv.nextInt();

		Map<String, Integer> grade = new HashMap<>();
		grade.put("A", 10);
		grade.put("A", 9);
		grade.put("B", 8);
		grade.put("C", 7);
		grade.put("D", 6);
		grade.put("F", 5);

// Modern jdk8 support
// < My Answer >
// Stream, Lambda
		grade.entrySet().stream()
				.filter(el -> (score / 10) <= el.getValue())
				.sorted(Map.Entry.comparingByValue())
				.findFirst().stream().forEach(el -> System.out.println(el.getKey()));

	}
}
