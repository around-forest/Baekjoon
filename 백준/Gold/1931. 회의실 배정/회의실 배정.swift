let n = Int(readLine()!)!
var arr = [(Int, Int)]()
var endTime = 0
var count = 0

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    arr.append((input[0], input[1]))
}

arr.sort { $0.1 == $1.1 ? $0.0 < $1.0 : $0.1 < $1.1 }

for time in arr {
    if time.0 >= endTime {
        endTime = time.1
        count += 1
    }
}

print(count)