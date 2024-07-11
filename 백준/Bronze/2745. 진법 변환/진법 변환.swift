let input = readLine()!.split(separator: " ").map { String($0) }
let n = Array(input[0]).map { String($0) }.reversed()
let b = Int(input[1])!
var result = 0
var dict = [String: Int]()

for i in 10...35 {
    let numb = 55
    dict[String(UnicodeScalar(numb + i)!)] = i
}

for (index, numb) in n.enumerated() {
    var tmp1 = Int()
    var tmp2 = 1
    
    if Int(numb) == nil {
        tmp1 = dict[numb]!
    } else {
        tmp1 = Int(numb)!
    }
    
    for _ in 0..<index {
        tmp2 *= b
    }
    
    result += (tmp1 * tmp2)
}

print(result)