:-use_module(library(clpfd)).

valuation([], N, N).

valuation([Bit|Bits], Result1, N) :-
  Bit in 0..1,
  Result2 #= 2 * Result1 + Bit,
  valuation(Bits, Result2, N).

valuation(Bin, N) :-
  valuation(Bin, 0, N).

/*
Q. 다음 코드를 설명하고 실행결과를 기술
< My Answer >
2진코드 저장 배열과 결과값 N을 입력하면 해당 자연수 N이 이진코드 표현과 같으면 True, 다르면 False를 반화해준다.

< Prof Answer >
구문 규칙에 적용된 요소들을 정수에 대응시키는 valuation semantic function이다.
사진 참고
*/
