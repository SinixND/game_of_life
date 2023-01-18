// set content background icons per class/itemtype
/*
document.addEventListener('DOMContentLoaded', function () {
    let items = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
    for (let i = 0; i < items.size; i++) {
        document.getElementsByClassName(`.content.${items[i]}`).style.background = linear-gradient(var(--cbg75), var(--cbg75)), url(`icons/${items[i]}.png`) center/contain no-repeat;
    };
}, false);
*/

// import Import from './data/weapons.json';
const weapons = require("./data/weapons.json");
console.log(weapons.mmr._1886.damage);

// show specialisation selection popup
function showPopupSpecialisation() {
    document.getElementById("popupSpecialisation").style.display = "block";
}

// hide specialisation selection popup
function closePopupSpecialisation() {
  document.getElementById("popupSpecialisation").style.display = "none";
} 
