let input = readLine()!.split(separator: " ").map{ Int($0)! }
var H = input[0]
var M = input[1]

if M - 45 < 0 {
    M = 60 - 45 + M
    H -= 1
    if H < 0 {
        H += 24
        print(H, M)
    } else {
        print(H, M)
    }
} else {
    M -= 45
    print(H, M)
}