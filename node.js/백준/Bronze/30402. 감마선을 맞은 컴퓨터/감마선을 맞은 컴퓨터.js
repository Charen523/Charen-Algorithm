let fs = require('fs');
//"C:/Users/sjeon/OneDrive/바탕 화면/Coding/Algorithm/Baekjoon/NODEJS/input.txt"
//'/dev/stdin'
let input = fs.readFileSync('/dev/stdin').toString();

if (input.includes('w'))
    console.log('chunbae');
else if (input.includes('b'))
    console.log('nabi');
else if (input.includes('g'))
    console.log('yeongcheol');