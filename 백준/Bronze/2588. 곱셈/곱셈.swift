let a = Int(readLine()!)!
let b = Int(readLine()!)!

let ans3 = a * (b % 10)
let ans4 = a * ((b / 10) % 10)
let ans5 = a * (b / 100)
let ans6 = ans3 + (ans4 * 10) + (ans5 * 100)

print(ans3)
print(ans4)
print(ans5)
print(ans6)