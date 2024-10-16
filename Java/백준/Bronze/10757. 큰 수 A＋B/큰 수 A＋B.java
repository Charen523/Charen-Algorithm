import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // A와 B 입력받기
        String A = sc.next();
        String B = sc.next();

        // BigInteger로 변환하여 덧셈
        BigInteger numA = new BigInteger(A);
        BigInteger numB = new BigInteger(B);
        BigInteger result = numA.add(numB);

        // 결과 출력
        System.out.println(result);

        sc.close();
    }
}