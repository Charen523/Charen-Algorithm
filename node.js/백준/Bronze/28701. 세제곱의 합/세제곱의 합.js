let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
//let input = fs.readFileSync("C:/Users/sjeon/OneDrive/바탕 화면/Coding/Algorithm/Baekjoon/NODEJS/input.txt").toString().split('\n');

let n = parseInt(input[0], 10);

let output1 = 0;
for (let i = 1; i <= n; i++) {
    output1 += i;
}
let output2 = output1 * output1;

let output3 = 0;
for (let i = 1; i <= n; i++) {
    output3 += i * i * i;
}

console.log(output1);
console.log(output2);
console.log(output3);