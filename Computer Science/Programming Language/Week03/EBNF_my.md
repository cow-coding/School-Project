### 다음은 자바 식별자 규칙이다. BNF 표기법을 EBNF 표기법으로 수정하시오.

BNF
\<id> ::= \<initial> | \<initial>\<more>
\<letter> ::= a | ... | z | A | ... | Z
\<digit> ::= 0 | ... | 9
\<initial> ::= \<letter> | _ | $
\<more> ::= \<final> | \<more>\<final>
\<final> ::= \<initial> | \<digit>


---

\< My Answer >

\<id> ::= { \<more> } \<more>
\<letter> ::= a | … | z | A | … | Z
\<digit> ::= 0 | … | 9
\<initial> ::= \<letter> | _ | $
\<more> ::= \<final> { \<final> }
\<final> ::= \<initial> | \<digit>


---

\< Prof Answer >

\<id> ::= \<initial> { \<final> }
\<letter> ::= a | … | z | A | … | Z
\<digit> ::= 0 | … | 9
\<initial> ::= \<letter> | \<digit>
\<final> ::= \<initial> | \<digit>

or

\<id> ::= \<initial> { ( \<initial> | \<digit> )  }
\<letter> ::= a | … | z | A | … | Z
\<digit> ::= 0 | … | 9
\<initial> ::= \<letter> | _ | $

Lexical Analysis 파트의 목적은 프로그램에서 사용된 단어를 구별해 내는 것 입니다.
어휘 분석기에 의해 얻어지는 결과를 토큰(특수/일반)이라고 합니다.
어휘 분석으로 얻어지는 토큰의 한 가지인 identifier는 변수나 함수 등의 이름을 나타내는
토큰 입니다. 영상에서는 자바언어의 식별자 규칙을 BNF 구문 규칙으로 정리하고
선언된 변수가 사용할 수 있는 변수인지 Eclipse IDE에서 확인한 후 r2d2 변수를
<identifier>로 유도해서 적합한 변수인지 판정하는 과정을 설명했습니다.
IDE에서 규칙에 맞지 않는 변수 선언은 빨간 줄이 나오면서 쓸 수 없다고 하는 것은
영상에서 설명한 JAVA BNF 규칙에 맞지 않기 때문입니다.
좀 더 깊이 있는 내용은 후수 과목인 컴파일러에서 학습하게 됩니다.
