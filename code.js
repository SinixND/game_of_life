//===========================================================
// IMPORT DATA
import {mask} from "./data/masks.js";
//console.log(mask.Vile.talentName);
//console.log(mask['Vile'].talentName);
//console.log(mask[0].talentName);

//===========================================================
// STARTUP FUNCTION
document.addEventListener('DOMContentLoaded', function () {
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
  clonedTpl.getElementByClassName('item-name').innerText = `${mask[0]}`;
  clonedTpl.getElementByClassName('item-type').innerText = `(${mask[0].type})`;
  clonedTpl.getElementByClassName('item-talent-name').innerText = `(${mask[0].talentName})`;
  clonedTpl.getElementByClassName('item-talent-text').innerText = `(${mask[0].talentText})`;
  
  list.appendChild(clonedTpl);
  
  
  //alert("Done!");
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
