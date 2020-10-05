package kr.ac.inha.cse.pl;

public class SyntaxSemantics {
	public static void main(String[] args) {
		// week02
		// assignment #2
		// 45번, 46번 라인의 경우 에러가 발생하지 않고, 47~ 50번 라인의 경우 에러가 발생한다.
		// 아래 다섯가지 케이스만을 참고하여 hexadecimal을 정의(EBNF)하시오.

    // < My Answer >
		// <hexletter> ::= "A" | "B" | "C" | "D" | "E" | "F" | "a" | "b" | "c" | "d" | "e" | "f"
		// <hexadecimal> ::= 0x {<digit> | <hexletter> | '_'}
		int a = 0xFCFFFF_FF;
		int b = 0X13FF_FfbF;
		//int c = 0xfFFFFFFF_;
		//int d = 0xFFFKFFFF;
		//int e = 0x_FFFBaFF;
		int f = 0x07FBaF6F;
	}
}

// 구문 도표
// 사각형 (non terminal), 원 (terminal), 화살표 (기호 연결)
