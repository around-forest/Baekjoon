import Foundation

var sudoku = [[Int]]()
var blank = [[Int]]()

func dfs(_ depth: Int) {
    if depth == blank.count {
        for line in sudoku {
            print(line.map { String($0) }.joined(separator: " "))
        }
        exit(0)
    }
    
    for i in 1...9 {
        if checkLine(i, blank[depth][0], blank[depth][1]) && checkSquare(i, blank[depth][0], blank[depth][1]) {
            sudoku[blank[depth][0]][blank[depth][1]] = i
            dfs(depth + 1)
            sudoku[blank[depth][0]][blank[depth][1]] = 0
        }
    }
}

func checkSquare(_ n: Int, _ i: Int, _ j: Int) -> Bool {
    for k in 0..<3 {
        for l in 0..<3 {
            if sudoku[i / 3 * 3 + k][j / 3 * 3 + l] == n {
                return false
            }
        }
    }
    return true
}

func checkLine(_ n: Int, _ i: Int, _ j: Int) -> Bool {
    for k in 0..<9 {
        if sudoku[i][k] == n || sudoku[k][j] == n {
            return false
        }
    }
    return true
}

func checkBlank() {
    for i in 0..<9 {
        for j in 0..<9 {
            if sudoku[i][j] == 0 {
                blank.append([i, j])
            }
        }
    }
}

func solution() {    
    for _ in 0..<9 {
        sudoku.append(readLine()!.split(separator: " ").map { Int($0)! })
    }
    
    checkBlank()
    dfs(0)
}

solution()