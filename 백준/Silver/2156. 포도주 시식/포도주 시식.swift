let n = Int(readLine()!)!
var wine = [Int]()
var drink = Array(repeating: 0, count: 10001)

wine.append(0)

for _ in 1...n {
    wine.append(Int(readLine()!)!)
}

drink[1] = wine[1]

if n >= 2 {
    drink[2] = wine[1] + wine[2]
}

if n >= 3 {
    for i in 3...n {
        drink[i] = max(drink[i - 2] + wine[i], drink[i - 3] + wine[i - 1] + wine[i], drink[i - 1])
    }
}

print(drink[n])