import Foundation

let n = Int(readLine()!)!
var numbers = readLine()!.split(separator: " ").map { Int(String($0))! }
var symbols = readLine()!.split(separator: " ").map { Int(String($0))! } // + - x /

var max = Int.min
var min = Int.max

func backtracking(_ result: Int, _ index: Int) {
    if index == n {
        if result > max { max = result }
        if result < min { min = result }
        return
    } else {
        for i in 0..<4 {
            if symbols[i] > 0 {
                symbols[i] -= 1
                
                switch i {
                    case 0:
                        backtracking(result + numbers[index], index + 1)
                    case 1:
                        backtracking(result - numbers[index], index + 1)
                    case 2:
                        backtracking(result * numbers[index], index + 1)
                    case 3:
                        backtracking(result / numbers[index], index + 1)
                    default:
                        fatalError("default Error")
                }
                
                symbols[i] += 1
            }
        }
    }
}

func solution() {
    backtracking(numbers[0], 1)
    
    print("\(max)\n\(min)")
}

solution()