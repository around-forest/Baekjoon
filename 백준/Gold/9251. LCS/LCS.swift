let a = readLine()!.map { String($0) }
let b = readLine()!.map { String($0) }
var arr = Array(repeating: Array(repeating: 0, count: b.count + 1), count: a.count + 1)

for i in 1...a.count { 
    for j in 1...b.count {
        if a[i - 1] == b[j - 1] {
            arr[i][j] = arr[i - 1][j - 1] + 1
        } else {
            arr[i][j] = max(arr[i - 1][j], arr[i][j - 1])
        }
    }
}

print(arr[a.count][b.count])