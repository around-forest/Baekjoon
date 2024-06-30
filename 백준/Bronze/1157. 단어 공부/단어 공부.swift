let input = Dictionary(readLine()!.uppercased().map{ ($0, 1) }, uniquingKeysWith: +)
let maxCount = input.filter{ $0.value == input.values.max()! }

if maxCount.count > 1 {
    print("?")
} else {
    print(maxCount.keys.first!)
}