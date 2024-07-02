import Foundation

let croatian = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
var input = readLine()!

for alphabet in croatian {
    input = input.replacingOccurrences(of: alphabet, with: " ")
}

print(input.count)