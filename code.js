//===========================================================
// IMPORT DATA
import {mask} from "./data/masks.js";

//===========================================================
// STARTUP FUNCTION
document.addEventListener('DOMContentLoaded', function () {
  //=========================================================
  // DEBUG
  //console.log(mask.Vile.talentName);
  //console.log(mask['Vile'].talentName);
  //alert("hi");

  //=========================================================
  // SET BACKGROUND ICONS
  let icons = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
  for (let i = 0; i < icons.length; i++) {
    let file = `./icons/${icons[i]}.png`;
    let value = `linear-gradient(var(--cbg75), var(--cbg75)), url(${file}) center/contain no-repeat`;
    let element = document.getElementsByClassName(`${icons[i]}`);
    for (let j = 0; j < element.length; j++) {
      element[j].style.background = value;
    }
  };
  
  //=========================================================
  // FILL LISTS
  const template = document.getElementById('template-list-gear-item');
  const list = document.getElementById('list-gear');
  const clonedTpl = template.content.cloneNode(true);
  let objNames = [];
  for (let objName in mask) {      
    if (mask.hasOwnProperty(objName)) objNames.push(objName);
  }
  //Then you can iterate on your properties by index: yourobject[keys[i]] :
    clonedTpl.querySelector('.item-name').innerText = "";
  for (let i=0; i < objNames.length; i++) { 
    console.log(objNames[i], mask[objNames[i]]);
    clonedTpl.querySelector('.item-name').innerText += `${objNames[i]}`;

  list.appendChild(clonedTpl);
  }
  /*
  clonedTpl.getElementByClassName('item-name').innerText = `${mask[0]}`;
  clonedTpl.getElementByClassName('item-type').innerText = `(${mask[0].type})`;
  clonedTpl.getElementByClassName('item-talent-name').innerText = `(${mask[0].talentName})`;
  clonedTpl.getElementByClassName('item-talent-text').innerText = `(${mask[0].talentText})`;

  list.appendChild(clonedTpl);
  */
}, false);

//===========================================================
// POPUP FUNCTIONS
function showPopup(Class) {
  document.getElementById(`popupGear`).style.display = "flex";
}

function closePopup() {
  document.getElementById(`popupGear`).style.display = "none";
}

/*
let vdiv = document.createElement('div');
vdiv.id = 'ID';
vdiv.className = 'flex';
document.getElementsById('list-mask').appendChild(vdiv);

function useTemplate() {
      var myTemplate = document.getElementById('myTemplate');
          normalContent = document.getElementById('normalContent');
          clonedTemplate = myTemplate.content.cloneNode(true);
          clonedTemplate.id = 'ID';
          normalContent.appendChild(clonedTemplate);
          }
          */
