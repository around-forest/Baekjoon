let input = readLine()!.split(separator: " ").map{ Int($0)! }
let time = Int(readLine()!)!
let H = input[0]
let M = input[1]

if M + time >= 60 {
    if H + (M + time) / 60 >= 24 {
        print(H + (M + time) / 60 - 24, (M + time) % 60)
    } else {
        print(H + (M + time) / 60, (M + time) % 60)
    }
} else {
    print(H, M + time)
}

