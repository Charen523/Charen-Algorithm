let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
//let input = fs.readFileSync("C:/Users/sjeon/OneDrive/바탕 화면/Coding/Algorithm/Baekjoon/NODEJS/input.txt").toString().split('\n');

let seenStrings = new Set();
let duplicates = new Set();

for (let i = 1; i < input.length; i++) {
    if (seenStrings.has(input[i]))
        duplicates.add(input[i]);
    else
        seenStrings.add(input[i]);
}

console.log(duplicates.size);