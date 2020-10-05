package kr.ac.inha.cse.pl;

import java.math.BigInteger;
import java.util.Scanner;
import java.util.stream.IntStream;
import java.util.stream.Stream;
// week02
// assignment #1
// 프로그램의 실행결과를 참고하여 큰 숫자 입력에 대한 올바른 처리가 되도록 자바 코드를 수정하시오.
/* 실행결과 (100입력)
Number :
100
Factorial Number : 0
*/

public class Paradigm {

	public static void main(String[] args) {
		Scanner scv = new Scanner(System.in);
		System.out.println("Number : ");
		int j = scv.nextInt();

		// functional (Old School)
		//System.out.println("Factorial Number : " + factorial(j));

		// functional (Modern Style)

		//  System.out.println("Factorial Number : " + IntStream.rangeClosed(2, j)
    //  .reduce(1, (a, b) -> {return a * b;}));

		//  System.out.println("Factorial Number : " + IntStream.range(2, j+1)
    //  .reduce(1, (a, b) -> a * b));

    // < My Answer >
		System.out.println("Factorial number : " + Stream.iterate(BigInteger.ONE, i -> i.add(BigInteger.ONE))
				.limit(j).reduce(BigInteger.ONE, (a,b)->a.multiply(b)));
	}
}
