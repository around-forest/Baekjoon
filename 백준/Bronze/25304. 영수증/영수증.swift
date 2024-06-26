let totalCost = Int(readLine()!)!
let products = Int(readLine()!)!
var sum = 0

for i in 1...products {
    let input = readLine()!.split(separator: " ").map{ Int($0)! }
    
    sum += (input[0] * input[1])
}

if sum == totalCost {
    print("Yes")
} else {
    print("No")
}