
let n = Int(readLine()!)!
let p = readLine()!.split(separator: " ").map { Int($0)! }.sorted(by: <)
var time = 0
var answer = 0

for i in p {
    time += i
    answer += time
}

print(answer)