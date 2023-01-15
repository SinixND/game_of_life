//import Import from './data/weapons.json';
const weapons = require("./data/weapons.json");
//const data = JSON.parse(Const);
console.log("\nLevel 1: ");
console.log(weapons);

console.log("\nLevel 2: ");
console.log(weapons.MMR);

console.log("\nLevel 3: ");
weapons.MMR._1886.damage = 20;
console.log(weapons.MMR._1886.damage);
