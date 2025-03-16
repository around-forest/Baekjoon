let n = Int(readLine()!)!
let a = readLine()!.split(separator: " ").map{ Int(String($0))! }
let b = readLine()!.split(separator: " ").map{ Int(String($0))! }
var m = Int(readLine()!)!
let c = readLine()!.split(separator: " ").map{ Int(String($0))! }
var queue = [Int]()
var ans = ""

for i in 0..<a.count {
    if a[i] == 0 {  // 큐 일때만 추가 (스택은 의미가 없음)
        queue.append(b[i])
    }
}

// m이 queue에 있는 개수보다 많거나 같을 때 -> queue에 있는 것들 + 삽입된 원소들 추가
if m >= queue.count {
    for i in queue.reversed() {
        ans += "\(i) "
    }
    for i in 0..<m - queue.count {
        ans += "\(c[i]) "
    }
} else {    // m이 더 queue에 있는 개수보다 더 적을 때 -> queue에 있는 것들만 해도 충분
    for i in stride(from: queue.count - 1, to: queue.count - m - 1, by: -1) {
        ans += "\(queue[i]) "
    }
}
print(ans)