var arr: [Int] = Array(repeating: 0, count: 9)

for i in 0..<9 {
    arr[i] = Int(readLine()!)!
}

print(arr.max()!)
print(arr.firstIndex(of: arr.max()!)! + 1)