import Foundation

let n = Int(readLine()!)!

func hanoi(n: Int, start: String, to: String, via: String) {
    if n == 1 {
        print(start, to)
        return
    }
    
    hanoi(n: n - 1, start: start, to: via, via: to)
    hanoi(n: 1, start: start, to: to, via: via)
    hanoi(n: n - 1, start: via, to: to, via: start)
}

print(pow(2, n) - 1)
hanoi(n: n, start: "1", to: "3", via: "2")