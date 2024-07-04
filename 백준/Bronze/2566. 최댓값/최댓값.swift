var tmp: [[Int]] = []

for _ in 0..<9 {
    let input = readLine()!.split(separator: " ").map{ Int($0)! }
    tmp.append(input)
}

let maxValue = tmp.flatMap{ $0 }.max()!

print(maxValue)
for i in 0..<9 {
    if tmp[i].max() == maxValue {
        print(i + 1, tmp[i].firstIndex(of: maxValue)! + 1)
        break
    }
}