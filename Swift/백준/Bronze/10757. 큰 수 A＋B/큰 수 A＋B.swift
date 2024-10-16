import Foundation

// 두 개의 문자열을 자릿수별로 더하는 함수
func addLargeNumbers(_ A: String, _ B: String) -> String {
    let arrA = Array(A.reversed()) // A를 뒤집어서 배열로 변환
    let arrB = Array(B.reversed()) // B를 뒤집어서 배열로 변환

    var result = ""
    var carry = 0
    let maxLength = max(arrA.count, arrB.count)

    for i in 0..<maxLength {
        let digitA = i < arrA.count ? Int(String(arrA[i]))! : 0
        let digitB = i < arrB.count ? Int(String(arrB[i]))! : 0
        let sum = digitA + digitB + carry
        carry = sum / 10
        result.append(String(sum % 10))
    }

    if carry > 0 {
        result.append(String(carry))
    }

    return String(result.reversed()) // 결과를 뒤집어서 반환
}

// 입력받기
if let input = readLine() {
    let numbers = input.split(separator: " ").map { String($0) }
    let A = numbers[0]
    let B = numbers[1]
    
    // 결과 출력
    print(addLargeNumbers(A, B))
}