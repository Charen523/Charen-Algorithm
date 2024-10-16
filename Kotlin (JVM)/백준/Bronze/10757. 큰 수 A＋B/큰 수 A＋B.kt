import java.math.BigInteger

fun main() {
    // 입력받기
    val (A, B) = readLine()!!.split(" ")

    // BigInteger로 변환 후 덧셈
    val result = BigInteger(A) + BigInteger(B)

    // 결과 출력
    println(result)
}