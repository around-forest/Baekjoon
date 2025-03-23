let n = Int(readLine()!)!

func star(n: Int, pattern: [String]) {
    if n == 1 {
        pattern.forEach { print($0) }
        return
    }
    
    let firstLine = pattern.map { $0 + $0 + $0 }
    let secondLine = pattern.map { $0 + Array(repeating: " ", count: pattern.count) + $0 }
    star(n: n / 3, pattern: firstLine + secondLine + firstLine)
}

star(n: n, pattern: ["*"])