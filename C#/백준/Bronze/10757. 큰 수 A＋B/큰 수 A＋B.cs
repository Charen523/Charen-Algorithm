using System;
using System.Numerics;

class Program
{
    static void Main()
    {
        // A와 B를 한 줄에 입력받기
        string[] input = Console.ReadLine().Split();

        // 입력받은 A와 B를 BigInteger로 변환
        BigInteger A = BigInteger.Parse(input[0]);
        BigInteger B = BigInteger.Parse(input[1]);

        // 결과 출력
        Console.WriteLine(A + B);
    }
}
