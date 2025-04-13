let arr = readLine()!.split(separator: "-")
var answer = 0

for i in arr[0].split(separator: "+") {
    answer += Int(i)!
}

for i in arr[1...] {
    for j in i.split(separator: "+") {
        answer -= Int(j)!
    }
}

print(answer)