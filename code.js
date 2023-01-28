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
  const tplLGI = document.getElementById('template-list-gear-item');
  const list = document.getElementById('list-gear');
  let objNames = [];
  for (let objName in mask) {      
    if (mask.hasOwnProperty(objName)) {
      objNames.push(objName);
    };
  };
  for (let i=0; i < objNames.length; i++) { 
    let name = `${objNames[i]}`;
    const clonedListGearItem = tplLGI.content.cloneNode(true);

    // onclick
    clonedListGearItem.querySelector('#panelItem').onclick = closePopup;

    // item name
    let gearName = clonedListGearItem.querySelector('.item-name')
    gearName.innerText = `${name}`;

    // item color
    let border = clonedListGearItem.querySelector('.border');
    if (mask[`${name}`].rarity == "Exotic") {
      border.style.borderColor = 'var(--cexotic)';
      gearName.style.color = 'var(--cexotic)';
    }
    else if (mask[`${name}`].rarity == "Named") {
      border.style.borderColor = 'var(--cnamed)';
      gearName.style.color = 'var(--cnamed)';
    }
    else if (mask[`${name}`].rarity == "Set") {
      border.style.borderColor = 'var(--cgearset)';
      gearName.style.color = 'var(--cgearset)';
    };

    // item type
    if (mask[`${name}`].hasOwnProperty('type') && mask[`${name}`].type !== `${name}`) {
      let gearType = clonedListGearItem.querySelector('.item-type');
      gearType.innerText = "(";
      gearType.innerText += mask[`${name}`].type;
      gearType.innerText += ")";
    };

    // item talent
    if (mask[`${name}`].hasOwnProperty('talentName')) {
      let gearTalentName = clonedListGearItem.querySelector('.item-talent-name')
      gearTalentName.classList.add('hLineTop');
      gearTalentName.innerText = mask[`${name}`].talentName;
    };
    if (mask[`${name}`].hasOwnProperty('talentText')) {
      clonedListGearItem.querySelector('.item-talent-text').innerText = mask[`${name}`].talentText;
    };

    list.appendChild(clonedListGearItem);
  }
}, false);

//===========================================================
// POPUP FUNCTIONS
window.showPopup = function showPopup(Class) {
  document.getElementById('popupFrameMain').style.display = "inherit";
  document.body.style.overflow = "hidden";
}

window.closePopup = function closePopup() {
  document.getElementById(`popupFrameMain`).style.display = "none";
  document.body.style.overflow = "";
}
