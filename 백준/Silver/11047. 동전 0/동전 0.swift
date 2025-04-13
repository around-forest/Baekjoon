let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0]
var k = input[1]
var arr = [Int]()
var count = 0

for _ in 0..<n {
    arr.append(Int(readLine()!)!)
}

for i in (0..<n).reversed() {
    if arr[i] <= k {
        count += (k / arr[i])
        k %= arr[i]
    }
    
    if k == 0 {
        break
    }
}

print(count)