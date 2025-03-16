var total = Int(readLine()!)!
var count = 0

if total % 5 == 0 {
    count += (total / 5)
} else {
    repeat { 
        total -= 3
        count += 1
        
        if total <= 0 {
            break
        }
    } while total % 5 != 0
    
    if total % 5 == 0 {
        count += total / 5
    } else {
        count = -1
    }
}

print(count)