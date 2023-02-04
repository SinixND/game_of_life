//============================
// IMPORT DATA
import {set} from "./data/sets.js";
import {mask} from "./data/masks.js";

//============================
// STARTUP FUNCTION
document.addEventListener('DOMContentLoaded', function () {
  //============================
  // DEBUG
  //console.log(mask.Vile.talentName);
  //alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); /* Lap: 1280x720; Mob: 432x896 */

  // COLORIZE PANELS
  let panels = document.getElementsByClassName("panel");
  let colors = ['car', 'cag', 'cab', 'cay', 'cat', 'cav'];
  let ccnt = 0;

  for (let i = 0; i < panels.length; i++) {
    panels[i].style.borderColor = `var(--${colors[ccnt]})`;
    ccnt++;
    if (ccnt >= colors.length) {
      ccnt = 0;
    }
  }

  // ADD ROOT VARIABLE
  document.documentElement.style.setProperty('--tpx', `calc(1px * ${window.devicePixelRatio})`);

  //============================
  // SET BACKGROUND ICONS
  let icons = ["main-weapon", "sidearm", "mask", "backpack", "chest", "gloves", "holster", "kneepads"];
  for (let i = 0; i < icons.length; i++) {
    var img = new Image();
    img.src = `./icons/${icons[i]}.png`;
    let value = `linear-gradient(var(--cbgr75), var(--cbgr75)), url(${img.src}) center no-repeat`;
    //let element = document.getElementsByClassName(`js_${icons[i]}`);
    let element = document.querySelectorAll(`[id*="${icons[i]}"]`);
    for (let j = 0; j < element.length; j++) {
      element[j].style.background = value;
      let scale = 0.75 * Math.min(element[j].offsetWidth/img.width, element[j].offsetHeight/img.height)
      element[j].style.backgroundSize = `${img.width * scale}px ${img.height * scale}px`;
    }
  };

  //============================
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
    gearName.innerHTML = `${name}`;

    // item type
    if (mask[`${name}`].hasOwnProperty('type') && mask[`${name}`].type !== `${name}`) {
      let gearType = clonedListGearItem.querySelector('.item-type');
      gearType.innerHTML = "(";
      gearType.innerHTML += mask[`${name}`].type;
      gearType.innerHTML += ")";
    };

    // item set boni
    let statsSet = clonedListGearItem.querySelector('.stats-set');
    statsSet.classList.add('hLineTop');
    let setAttribute1 = clonedListGearItem.querySelector('.set-attribute1');
    let setAttribute2 = clonedListGearItem.querySelector('.set-attribute2');
    let setAttribute3 = clonedListGearItem.querySelector('.set-attribute3');
    if (mask[`${name}`].rarity == "Exotic") {
      setAttribute1.innerHTML = mask[`${name}`].attribute1Name + ': ';
      setAttribute1.innerHTML += mask[`${name}`].attribute1Value;
      setAttribute2.innerHTML = mask[`${name}`].attribute2Name + ': ';
      setAttribute2.innerHTML += mask[`${name}`].attribute2Value;
      setAttribute3.innerHTML = mask[`${name}`].attribute3Name + ': ';
      setAttribute3.innerHTML += mask[`${name}`].attribute3Value;
    }
    else if (mask[`${name}`].rarity == "GearSet") {
      let setName = mask[`${name}`].type;
      setAttribute1.innerHTML = set[`${setName}`].attribute1Name + ': ';
      setAttribute1.innerHTML += set[`${setName}`].attribute1Value;
      setAttribute2.innerHTML = set[`${setName}`].attribute2Name + ': ';
      setAttribute2.innerHTML += set[`${setName}`].attribute2Value;
      setAttribute3.innerHTML = set[`${setName}`].gearSetTalentName + '<br><br>';
      setAttribute3.innerHTML += set[`${setName}`].gearSetTalentText;
    }
    else if (mask[`${name}`].rarity !== "Improvised") {
      let setName = mask[`${name}`].type;
      console.log(setName);
      setAttribute1.innerHTML = set[`${setName}`].attribute1Name + ': ';
      setAttribute1.innerHTML += set[`${setName}`].attribute1Value;
      setAttribute2.innerHTML = set[`${setName}`].attribute2Name + ': ';
      setAttribute2.innerHTML += set[`${setName}`].attribute2Value;
      setAttribute3.innerHTML = set[`${setName}`].attribute3Name + ': ';
      setAttribute3.innerHTML += set[`${setName}`].attribute3Value;
    };

    // item talent
    let gearTalentName = clonedListGearItem.querySelector('.item-talent-name')
    if (mask[`${name}`].hasOwnProperty('talentName')) {
      gearTalentName.classList.add('hLineTop');
      gearTalentName.innerHTML = mask[`${name}`].talentName;
    };
    if (mask[`${name}`].hasOwnProperty('talentText')) {
      clonedListGearItem.querySelector('.item-talent-text').innerHTML = mask[`${name}`].talentText;
    };

    // item color
    let panelBorder = clonedListGearItem.querySelector('.panelBorder');
    if (mask[`${name}`].rarity == "Exotic") {
      panelBorder.style.borderColor = 'var(--cExotic)';
      panelBorder.style.color = 'var(--cExotic)';
    }
    else if (mask[`${name}`].rarity == "Named") {
      panelBorder.style.borderColor = 'var(--cNamed)';
      panelBorder.style.color = 'var(--cNamed)';
    }
    else if (mask[`${name}`].rarity == "GearSet") {
      panelBorder.style.borderColor = 'var(--cGearSet)';
      panelBorder.style.color = 'var(--cGearSet)';
    };

    list.appendChild(clonedListGearItem);
  }
}, false);

//==============================
// POPUP FUNCTIONS
window.showPopup = function showPopup(Class) {
  document.getElementById('popupFrameMain').style.display = "flex";
  //document.body.style.overflow = "hidden";
}

window.closePopup = function closePopup() {
  document.getElementById(`popupFrameMain`).style.display = "none";
  //document.body.style.overflow = "";
}
