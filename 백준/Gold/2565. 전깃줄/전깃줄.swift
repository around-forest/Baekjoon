let n = Int(readLine()!)!
var array = [(Int, Int)]()
var increase = Array(repeating: 1, count: n)

func solution() {
    for _ in 0..<n {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        array.append((input[0], input[1]))
    }
    
    array = array.sorted { $0.0 < $1.0 }
    
    for i in 1..<n {
        for j in 0..<i {
            if array[i].1 > array[j].1 {
                increase[i] = max(increase[i], increase[j] + 1)
            }
        }
    }
    
    print(n - increase.max()!)
}

solution()