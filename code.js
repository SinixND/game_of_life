// set content background icons per class/itemtype
document.addEventListener('DOMContentLoaded', function () {
    let items = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
    for (let i = 0; i < items.length; i++) {
        let file = `./icons/${items[i]}.png`;
        let value = `linear-gradient(var(--cbg75), var(--cbg75)), url(${file}) center/contain no-repeat`;
        let element = document.getElementsByClassName(`content ${items[i]}`);
        for (let j = 0; j < element.length; j++) {
            element[j].style.background = value;
        }
    };
}, false);

// import Import from './data/weapons.json';
//const weapons = require("./data/weapons.json");
//console.log(weapons.mmr._1886.damage);

// show specialisation selection popup
function showPopupSpecialisation() {
    document.getElementById("popupSpecialisation").style.display = "block";
}

// hide specialisation selection popup
function closePopupSpecialisation() {
    document.getElementById("popupSpecialisation").style.display = "none";
} 
