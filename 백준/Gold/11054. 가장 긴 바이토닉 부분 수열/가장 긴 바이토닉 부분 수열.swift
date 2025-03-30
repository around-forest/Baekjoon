let n = Int(readLine()!)!
let sequence = readLine()!.split(separator: " ").map { Int($0)! }
let reversedSequence = Array(sequence.reversed())

var increase = [Int](repeating: 1, count: n)
var decrease = [Int](repeating: 1, count: n)

var answer = 1

func solution() {
    for i in 1..<n {
        for j in 0..<i {
            if sequence[i] > sequence[j] {
                increase[i] = max(increase[i], increase[j] + 1)
            }
            if reversedSequence[i] > reversedSequence[j] {
                decrease[i] = max(decrease[i], decrease[j] + 1)
            }
        }
    }
    
    for i in 0..<n {
        answer = max(answer, increase[i] + decrease.reversed()[i] - 1)
    }
    
    print(answer)
}

solution()