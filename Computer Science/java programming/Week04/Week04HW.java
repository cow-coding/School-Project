import java.util.Scanner;

import javax.swing.JOptionPane;


class Calculator {
	private int num1;
	private int num2;
	private int result;
	private char oper;

	public Calculator() {
		this.num1 = 0;
		this.num2 = 0;
		this.result = 0;
		this.oper = '\0';
	}

	public void setNum1(String n1) {
		this.num1 = Integer.parseInt(n1);
	}

	public void setNum2(String n2) {
		this.num2 = Integer.parseInt(n2);
	}

	public void setOper(char o) {
		this.oper = o;
	}

	public void cal() {
		switch (oper) {
		case '+': result = num1 + num2; break;

		case '-': result = num1 - num2; break;

		case '/': result = num1 / num2; break;

		case '*': result = num1 * num2; break;

		case '%': result = num1 % num2; break;

		}
		num1 = result;
	}

	public int getResult() {
		return result;
	}

	public int getNum1() {
		return num1;
	}

	public int getNum2() {
		return num2;
	}
}


public class Week04HW {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Calculator c = new Calculator();
		String num = "";
		boolean start = true;
		boolean op = false;
		boolean eq = false;
		char oper = '\0';

		while (true) {
			String input = "";

			if (eq) {
				// result print
				input = JOptionPane.showInputDialog("result : " + c.getNum1());
				c.setNum2("0");
				eq = false;
				op = false;
			}else {
				if (op) {
					// op input and num not input
					input = JOptionPane.showInputDialog("Number2 : " + c.getNum2());
				}else {
					input = JOptionPane.showInputDialog("Number1 : " + c.getNum1());
				}
			}

			if (input.equals("exit")) break; // terminate condition

			if (input.charAt(0) - '0' >= 0 && input.charAt(0) - '0' < 10) {
				// input is number
				if (start == true) {
					// num1 setting
					num += input.charAt(0) - '0';
					c.setNum1(num);
				}else {
					num += input.charAt(0) - '0';
					c.setNum2(num);
				}
			}else {
				// input is operator

				if (input.charAt(0) == '=') {
					// calculating operation input
					c.cal();
					op = false;
					eq = true;
				}else {
					num = "";
					start = false;
					c.setOper(input.charAt(0));
					op = true;
				}
			}


		}
	}

}
