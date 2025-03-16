let n = Int(readLine()!)!
var s: [Int] = []

for _ in 0..<n {
    let a = readLine()!.split(separator: " ").map { Int($0)! }
    guard let c = a.first else { break }
    
    switch c {
        case 1:
            s.append(a[1])
        case 2:
            print(s.popLast() ?? -1)
        case 3:
            print(s.count)
        case 4:
            print(s.isEmpty ? 1: 0)
        case 5:
            print(s.last ?? -1)
        default:
            continue
    }
}