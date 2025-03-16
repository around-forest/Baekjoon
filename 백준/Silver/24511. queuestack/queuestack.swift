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

queue = queue.reversed()

if m < queue.count {
    for i in 0..<m {
        answer += "\(queue[i]) "
    }
} else {
    for i in queue {
        answer += "\(i) "
    }
    
    for i in 0..<m-queue.count {
        answer += "\(c[i]) "
    }
}

print(answer)