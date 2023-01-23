// set content background icons per class/itemtype
document.addEventListener('DOMContentLoaded', function () {
    let items = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
    for (let i = 0; i < items.length; i++) {
        let file = `./icons/${items[i]}.png`;
        let value = `linear-gradient(var(--cbg75), var(--cbg75)), url(${file}) center/contain no-repeat`;
        let element = document.getElementsByClassName(`${items[i]}`);
        for (let j = 0; j < element.length; j++) {
            element[j].style.background = value;
        }
    };
}, false);

//============
// import data
//============

import {mask} from "./data/masks.js";

//=============================
// Test if objects are working:
//=============================

//document.getElementsByClassName(`item-name`)[0].innerText += " black";
//console.log(file['name'].key);
console.log("Test command 1: mask.Vile.rarity");
console.log(mask.Vile.rarity);
document.getElementsByClassName(`item-name`)[0].innerText += ` ${mask.Vile.rarity}`;
//try:
console.log("Test command 2: mask['Vile'].rarity");
console.log(mask['Vile'].rarity);
document.getElementsByClassName(`item-name`).innerText += `${mask['Vile'].rarity}`;
//and:
console.log("Test command 3: mask[Vile]['rarity']");
console.log(mask."5.11 Tactical".rarity);
document.getElementsByClassName(`item-name`).innerText += `${mask."5.11 Tactical".rarity}`;



// show selection popup
function showPopup(Class) {
    document.getElementById(`popupGear`).style.display = "flex";
}

// hide selection popup
function closePopup() {
    //populateList(Class);
    document.getElementById(`popupGear`).style.display = "none";
}

/*
let vdiv = document.createElement('div');
vdiv.id = 'ID';
vdiv.className = 'flex';
document.getElementsById('list-mask')[0].appendChild(vdiv);

function useTemplate() {
      var myTemplate = document.getElementById('myTemplate');
          normalContent = document.getElementById('normalContent');
          clonedTemplate = myTemplate.content.cloneNode(true);
          clonedTemplate.id = 'ID';
          normalContent.appendChild(clonedTemplate);
          }
*/
