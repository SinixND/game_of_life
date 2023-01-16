//import Import from './data/weapons.json';
const weapons = require("./data/weapons.json");
//const data = JSON.parse(Const);
console.log("\nLevel 1: ");
console.log(weapons);

console.log("\nLevel 2: ");
console.log(weapons.mmr);

console.log("\nLevel 3: ");
console.log(weapons.mmr._1886.damage);


function showPopupSpecialisation() {
    document.getElementById("popupSpecialisation").style.display = "block";
}

function closePopupSpecialisation() {
  document.getElementById("popupSpecialisation").style.display = "none";
} 
