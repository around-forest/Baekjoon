var queue = [Int]()
var answer = ""

let n = Int(readLine()!)!
let a = readLine()!.split(separator: " ").map { Int($0)! }
let b = readLine()!.split(separator: " ").map { Int($0)! }
let m = Int(readLine()!)!
let c = readLine()!.split(separator: " ").map { Int($0)! }

for (i, v) in a.enumerated() {
    if v == 0 {
        queue.append(b[i])
    }
}

if m < queue.count {
    for i in stride(from: queue.count - 1, to: queue.count - m - 1, by: -1) {
        answer += "\(queue[i]) "
    }
} else {
    for i in queue.reversed() {
        answer += "\(i) "
    }
    
    for i in 0..<m-queue.count {
        answer += "\(c[i]) "
    }
}

print(answer)