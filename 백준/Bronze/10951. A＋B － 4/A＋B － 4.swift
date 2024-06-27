while let input = readLine() {
    let tmp = input.split(separator: " ").map{ Int($0)! }
    print(tmp[0] + tmp[1])
}