let n = Int(readLine()!)!
var arr: [Int] = Array(repeating: 0, count: n)

let input = readLine()!.split(separator: " ").map{ Int($0)! }

for i in 0..<n {
    arr[i] = input[i]
}

print(arr.min()!, arr.max()!)