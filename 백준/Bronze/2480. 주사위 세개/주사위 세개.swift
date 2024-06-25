let input = readLine()!.split(separator: " ").map{ Int($0)! }

if input[0] == input[1] && input[0] == input[2] {
    print(10000 + input[0] * 1000)
} else if input[0] == input[1] || input[0] == input[2] {
    print(1000 + input[0] * 100)
} else if input[1] == input[2] {
    print(1000 + input[1] * 100)
} else {
    print(input.max()! * 100)
}