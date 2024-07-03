let n = Int(readLine()!)!
var cnt: Int = 0

for _ in 0..<n {
    let input = readLine()!
    var arr: [Character] = []
    
    for i in input {
        if arr.isEmpty {
            arr.append(i)
        } else if arr.last! == i {
            continue
        } else {
            arr.append(i)
        }
    }
    
    if arr.count == Set(arr).count {
        cnt += 1
    }
}

print(cnt)