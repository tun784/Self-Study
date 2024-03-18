// Hello world

/* Hello
        World */

var message = 'Hello World';
function sayHello(){
    console.log(message);
}
sayHello();

var a = 5, b = 10;
console.log(a + b);
console.log(a - b);
console.log(a * b);
console.log(a / b);
console.log((a / b).toFixed(2)); // Fix: Use toFixed() method to limit decimal places to 2

var year = new Date().getFullYear();
var nextYear = year + 1;
var isLeapYear = false;
isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
if (isLeapYear) {
    console.log(year + ' is a leap year');
}
else {
    console.log(year + ' is not a leap year');
}

isLeapYear = nextYear % 4 == 0 && (nextYear % 100 != 0 || nextYear % 400 == 0);
if (isLeapYear)
    console.log(nextYear + ' is a leap year');
else
    console.log(nextYear + ' is not a leap year');

var age = 18;
if (age >= 18)
    console.log('You are an adult');
else
    console.log('You are a child');

var i = 0;
let output = '';
for (i = 0; i < 5 ; i++) {
    output += i + '-';
}
console.log(output);

i = 0;
output = '';
while (i < 10) {
    output += i + '_';
    i++;
}
console.log(output);

i = 0;
output = '';
do {
    output += i + ' ';
    i++;
}
while (i < 15);
console.log(output);

console.log(0.1 + 0.2);
const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

readline.question("What's your name: ", (userName) => {
    console.log("Hello " + userName);
    readline.close();
});