let fs = require('fs');
//"C:/Users/sjeon/OneDrive/바탕 화면/Coding/Algorithm/Baekjoon/NODEJS/input.txt"
//'/dev/stdin'
let input = fs.readFileSync('/dev/stdin').toString();

let a = input / 100 * 78;
let b = input - (input / 100 * 20) / 100 * 22;

console.log(`${a} ${b}`);