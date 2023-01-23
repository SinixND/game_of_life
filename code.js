//=============
// import data
//=============
import {mask} from "./data/masks.js";
//console.log(mask.Vile.talentName);
//console.log(mask['Vile'].talentName);

//==================
// startup function
//==================
document.addEventListener('DOMContentLoaded', function () {
  //===========================
  // set item background icons
  //===========================
  let icons = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
  for (let i = 0; i < icons.length; i++) {
    let file = `./icons/${icons[i]}.png`;
    let value = `linear-gradient(var(--cbg75), var(--cbg75)), url(${file}) center/contain no-repeat`;
    let element = document.getElementsByClassName(`${icons[i]}`);
    for (let j = 0; j < element.length; j++) {
      element[j].style.background = value;
    }
  };

  // fill lists to choose items

  //alert("Done!");
}, false);


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
