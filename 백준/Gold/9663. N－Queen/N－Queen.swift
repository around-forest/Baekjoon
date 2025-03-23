import Foundation

let n = Int(readLine()!)!
var board = [Int](repeating: 0, count: n)
var visited = [Bool](repeating: false, count: n)
var count = 0

func check(_ depth: Int) -> Bool {
    for i in 0..<depth {
        // 가로세로
        if board[i] == board[depth] {
            return false
        }
        
        // 대각선
        if abs(board[i] - board[depth]) == abs(i - depth) {
            return false
        }
    }
    return true
}

func dfs(_ depth: Int) {
    if depth == n {
        count += 1
        return
    }
    
    for i in 0..<n {
        if visited[i] { continue }
        
        board[depth] = i
        
        if check(depth) {
            visited[i] = true
            dfs(depth + 1)
            visited[i] = false
        }
    }
}

dfs(0)
print(count)
