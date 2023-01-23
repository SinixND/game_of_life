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

// import data
//const masks = require("./data/masks.json");
import {masks} from "./data/masks.js";
//(async () => { 
//    const masks = await import('./data/masks.js');
//    console.log(masks);
//console.log(masks.default.Vile.rarity);
//})() 
//let masks = JSON.parse(masks);
//document.getElementsByClassName(`item-name`)[0].innerHTML += " black";
console.log(masks.Vile.rarity);
//document.getElementsByClassName(`item-name`)[0].innerHTML+=`${masks.Vile.rarity}`;
//try:
//console.log(file['name'].key);
//document.getElementsByClassName(`item-name`).innerHTML+=`${masks[Vile].rarity}`;
//and:
//console.log(file[name][key]);
//document.getElementsByClassName(`item-name`).innerHTML+=`${masks[Vile][rarity]}`;

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
