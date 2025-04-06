let n = Int(readLine()!)!
let sequence = readLine()!.split(separator: " ").map { Int($0)! }
var increase = [Int](repeating: 1, count: n)

for i in 1..<n {
    for j in 0..<i {
        if sequence[i] > sequence[j] {
            increase[i] = max(increase[i], increase[j] + 1)
        }
    }
}

print(increase.max()!)