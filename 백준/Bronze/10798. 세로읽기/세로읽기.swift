var words = [[String]](repeating: [String](repeating: "", count: 15), count: 5)
var result = ""

for i in 0..<5 {
    let word = readLine()!.map{ String($0) }
    words[i].replaceSubrange(0..<word.count, with: word)
}

for i in 0..<15 {
    for j in 0..<5 {
        print(words[j][i], terminator: "")
    }
}