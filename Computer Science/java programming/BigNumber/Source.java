import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Scanner;

class BigNumber {
    String data = new String();
    int[] number = new int[1000001];

    BigNumber() {
        this.data = Integer.toString(1);
        number[0] = 1;
    }

    BigNumber(String n) {
        this.data = n;

        for (int i = n.length() - 1; i > -1; i--) {
            number[i] = (n.charAt(n.length() - 1 - i) - '0');
        }
    }

    BigNumber(long n) {
        this.data = Long.toString(n);

        for (int i = this.data.length() - 1; i > -1; i--) {
            number[i] = (this.data.charAt(i) - '0');
        }
    }

    void multiply(BigNumber BN) {
        String ret = new String();
        int[] result = new int[1000001];
        int range = 0;

        for (int i = 0; i < BN.data.length(); i++) {
            for (int j = 0; j < this.data.length(); j++) {
                result[i + j] += (this.number[j] * BN.number[i]);
            }
        }

        range = this.data.length() + BN.data.length() - 2; // 4 + 2 - 2 = 4 자릿수

        for (int i = 0; i <= range; i++) {
            if (i == range) {
                if (result[i] > 9) range++;
            }

            if (result[i] > 9) {
                // carry 발생
                result[i + 1] += result[i] / 10;
                result[i] = (result[i] % 10);
            }
        }

        for (int i = range; i > -1; i--) {
            ret += Integer.toString(result[i]);
        }

        this.number = result;
        this.data = ret;
    }

    void printNumber() {
        System.out.println(this.data);
    }

    public void save() throws IOException {
        Scanner sc = new Scanner(System.in);

        String filePath = "C:\\homework\\answer.txt";
        Path p = new File(filePath).toPath();

        if (Files.notExists(p)) {
            System.out.println("create a file!");
            Files.createFile(p);
        }
        Files.write(p, this.data.getBytes(), StandardOpenOption.APPEND);
    }

}

public class Source extends Thread{
    public static void main(String[] args) {
        BigNumber bn = new BigNumber();

        Scanner sc = new Scanner(System.in);
        System.out.println("Input integer : ");
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            if (i % 100 == 0) {
                System.out.println("---- "+i+" calculation...----");
            }

            BigNumber next = new BigNumber(Integer.toString(i));

            bn.multiply(next);
        }

//        try {
//            bn.save();
//        }catch (IOException e) {}
        bn.printNumber();
    }
}
