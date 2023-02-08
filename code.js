//============================
// IMPORT DATA
import {set} from "./data/sets.js";
import {mask} from "./data/masks.js";

// ARRAYS
let colors = [
  'car', 
  'cag', 
  'cab', 
  'cay', 
  'cat', 
  'cav',
];

let icons = [
  "5.11_Tactical",
  "Aces_&_Eights",
  "Airaldi_Holdings",
  "Alps_Summit_Armaments",
  "backpack",
  "Badger_Tuff",
  "Belstone_Armory",
  "Brazos_de_Arcabuz",
  "Ceska_Vyroba_s.r.o.",
  "chest",
  "China_Light_Industries_Corporation",
  "defense1",
  "defense2",
  "defense3_1",
  "defense3_2",
  "Douglas_&_Harding",
  "Eclipse_Protocol",
  "Empress_International",
  "Exotic",
  "Fenris_Group_AB",
  "Foundry_Bulwark",
  "Future_Initiative",
  "Gila_Guard",
  "gloves",
  "Golan_Gear_Ltd",
  "Grupo_Sombra_S.A.",
  "Hana-U_Corporation,",
  "Hard_Wired",
  "Heartbreaker",
  "holster",
  "Hunters_Fury",
  "Improvised",
  "kneepads",
  "main-weapon",
  "mask",
  "Murakami_Industries",
  "named",
  "Negotiators_Dilemma",
  "offense1",
  "offense2",
  "offense3_1",
  "offense3_2",
  "Ongoing_Directive",
  "Overlord_Armaments",
  "Petrov_Defense_Group",
  "Providence_Defense",
  "Richter_&_Kaiser_GmbH",
  "Rigger",
  "shd_big",
  "sidearm",
  "Sokolov_Concern",
  "Strikers_Battlegear",
  "System_Corruption",
  "tech1",
  "tech2",
  "tech3_1",
  "tech3_2",
  "Tip_of_the_Spear",
  "True_Patriot",
  "Umbra_Initiative",
  "Uzina_Getica",
  "Walker_Harris_&_Co",
  "Wyvern_Wear",
  "Yaahl_Gear",
];

let items = [
  //"specialisation", 
  //"weapon-1", 
  //"weapon-2", 
  //"sidearm", 
  "mask", 
  //"backpack", 
  //"chest", 
  //"gloves", 
  //"holster", 
  //"kneepads", 
  //"skill-1", 
  //"skill-2",
];

//============================
// STARTUP FUNCTION
document.addEventListener('DOMContentLoaded', () => {
  //============================
  // DEBUG
  //alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); /* Lap: 1280x720; Mob: 432x896 */

  // COLORIZE PANELS
  let panels = document.getElementsByClassName("panel");
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
  for (let i = 0; i < icons.length; i++) {
    var img = new Image();
    img.src = `./icons/${icons[i]}.png`;
    let value = `linear-gradient(var(--cbgr75), var(--cbgr75)), url(${img.src}) center/contain no-repeat`;
    let element = document.querySelectorAll(`[id *= "${icons[i]}"]`);
    if (element.length !== 0) {
      for (let j = 0; j < element.length; j++) {
        element[j].style.background = value;
        /*
        let scale = 0.75 * Math.min(element[j].offsetWidth/img.width, element[j].offsetHeight/img.height)
        element[j].style.backgroundSize = `${img.width * scale}px ${img.height * scale}px`;
        */
      }
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
    clonedListGearItem.querySelector('#panel-item').onclick = closePopup;

    // item name
    let gearName = clonedListGearItem.querySelector('#item-name')
    gearName.innerHTML = `${name}`;

    // item type
    if (mask[`${name}`].hasOwnProperty('type') && mask[`${name}`].type !== `${name}`) {
      let gearType = clonedListGearItem.querySelector('#item-type');
      gearType.innerHTML = "(";
      gearType.innerHTML += mask[`${name}`].type;
      gearType.innerHTML += ")";
    };

    // item set boni
    let statsSet = clonedListGearItem.querySelector('#item-set-attributes');
    statsSet.classList.add('hLineTop');
    let setAttribute1 = clonedListGearItem.querySelector('#set-attribute-1');
    let setAttribute2 = clonedListGearItem.querySelector('#set-attribute-2');
    let setAttribute3 = clonedListGearItem.querySelector('#set-attribute-3');
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
      setAttribute1.innerHTML = set[`${setName}`].attribute1Name + ': ';
      setAttribute1.innerHTML += set[`${setName}`].attribute1Value;
      setAttribute2.innerHTML = set[`${setName}`].attribute2Name + ': ';
      setAttribute2.innerHTML += set[`${setName}`].attribute2Value;
      setAttribute3.innerHTML = set[`${setName}`].attribute3Name + ': ';
      setAttribute3.innerHTML += set[`${setName}`].attribute3Value;
    };

    // item talent
    let gearTalentName = clonedListGearItem.querySelector('#item-talent-name')
    if (mask[`${name}`].hasOwnProperty('talentName')) {
      gearTalentName.classList.add('hLineTop');
      gearTalentName.innerHTML = mask[`${name}`].talentName;
    };
    if (mask[`${name}`].hasOwnProperty('talentText')) {
      clonedListGearItem.querySelector('#item-talent-text').innerHTML = mask[`${name}`].talentText;
    };

    // item color
    let panelBorder = clonedListGearItem.querySelector('#panelBorder');
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
// EVENT LISTENERS
//let eventTarget = document.querySelectorAll(`[id*="${icons[i]}"]`);
let popupFrameMain = document.getElementById("popup-frame-main");
popupFrameMain.addEventListener("click", closePopup, false);

for (let i = 0; i < items.length; i++) {
  let panelItem = document.getElementById(`panel-${items[i]}`);
  panelItem.addEventListener('click', () => {showPopup(items[i])}, false);
}

//==============================
// FUNCTIONS
function showPopup(arg) {
  document.getElementById('popup-frame-main').style.display = "flex";
  document.getElementById(`popup-${arg}`).style.display = "flex";
  document.body.style.overflow = "hidden";
}

function closePopup() {
  document.getElementById(`popup-frame-main`).style.display = "none";
  document.body.style.overflow = "";
}
