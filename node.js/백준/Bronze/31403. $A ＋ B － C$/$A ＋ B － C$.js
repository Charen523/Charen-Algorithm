let fs = require('fs');
let input = fs.readFileSync('/dev/stdin').toString().split('\n');
//let input = fs.readFileSync("C:/Users/sjeon/OneDrive/바탕 화면/Coding/Algorithm/Baekjoon/NODEJS/input.txt").toString().split('\n');

let a = Number(input[0]);
let b = Number(input[1]);
let c = Number(input[2]);

console.log(a + b - c);
console.log(input[0] + input[1] - input[2]);