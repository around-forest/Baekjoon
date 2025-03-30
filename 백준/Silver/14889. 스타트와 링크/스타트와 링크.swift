import Foundation

let n = Int(readLine()!)!
var stats = [[Int]]()
var isVisited = Array(repeating: false, count: n)

var minAns = Int.max

func dfs(_ count: Int, _ index: Int) {
    if count == n / 2 { 
        var start = 0
        var link = 0
        
        for i in 0..<n {
            for j in 0..<n {
                if isVisited[i] && isVisited[j] { start += stats[i][j] }
                if !isVisited[i] && !isVisited[j] { link += stats[i][j] }
            }
        }
        
        minAns = min(abs(start - link), minAns)
        return
    }
    
    for i in index..<n {
        isVisited[i] = true
        dfs(count + 1, i + 1)
        isVisited[i] = false
    }
}

func solution() {
    for _ in 0..<n {
        let input = readLine()!.split(separator: " ").map { Int($0)! }
        stats.append(input)
    }
    
    dfs(0, 0)
    
    print(minAns)
}

solution()