let input = readLine()!.split(separator: " ")
let A = Int(input[0])!
let B = Int(input[1])!
let C = Int(input[2])!

print((A + B) % C)
print(((A % C) + (B % C)) % C)
print((A * B) % C)
print(((A % C) * (B % C)) % C)