/*
    //==============
    //
    // Traditional anonymous function
(function (a) {
  return a + 100;
});

// 1. Remove the word "function" and place arrow between the argument and opening body bracket
(a) => {
  return a + 100;
};

// 2. Remove the body braces and word "return" — the return is implied.
(a) => a + 100;

// 3. Remove the parameter parentheses
a => a + 100;

//==============
//==============

// Traditional Function
function bob(a) {
  return a + 100;
}

// Arrow Function
const bob2 = (a) => a + 100;

//==============
*/
/*
function f_return(arg) {
    //do something like displaying
};

let myPromise = new Promise(function(myResolve, myReject) {

    // "Producing Code" (May take some time)

    myResolve(console.log("promise: resolve")); // when successful
    myReject(console.log("promise: reject"));  // when error
});

// "Consuming Code" (Must wait for a fulfilled Promise)
myPromise.then(
    function(value) {console.log(value)},
    function(error) {console.log(error)}
);

//=============
*/
/*
const csvParser = async (filename) => {
    return new Promise((resolve, reject) => {
        let arr = [];
        const fs = require("fs");
        const readline = require("readline");

        const rfs = fs.createReadStream(`./csv/${filename}`);
        const reader = readline.createInterface({ input: rfs });

        reader.on("line", row => {
            // split row string in array and push
            arr.push(row.split(","));
            console.log("1: pushed: " + row.split(","));
        });

        reader.on("close", () => {
            console.log("2: onClose: ");
            console.log(arr);
            if (arr.length != 0) {
                resolve(arr);
            } else {
                reject("Failed: array empty!");
            }
        });

    });
};

//usage
let parsedCSV = csvParser('data.csv').then( function(prv) {
    console.log("return promise return value: "+prv);
    return prv;
});
console.log("final csv array: "+parsedCSV);
*/
function csvParser(filename) {// incl. *.filetyp
    return new Promise((resolve, reject) => {
        // initialize
        let arr = [];
        const fs = require("fs");
        const readline = require("readline");

        const rfs = fs.createReadStream(`./csv/${filename}`);
        const reader = readline.createInterface({ input: rfs });

        reader.on("line", row => {
            arr.push(row.split(","));
        });

        reader.on("close", () => {
            console.log("reader.onClose: ");
            console.log(arr);
            resolve(arr);
        });

    }).then();
};

let parsedCSV = csvParser('data.csv');
console.log("finalarr: ");
console.log(parsedCSV);

