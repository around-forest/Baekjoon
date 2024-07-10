let n = Int(readLine()!)!
var plate = [[Bool]](repeating: [Bool](repeating: false, count: 100), count: 100)
var count = 0

for _ in 0..<n {
    let input = readLine()!.split(separator: " ").map{ Int($0)! }
    
    for i in input[1]..<input[1] + 10 {
        for j in input[0]..<input[0] + 10 {
            if !plate[i][j] {
                plate[i][j] = true
                count += 1
            }
        }
    }
}

print(count)