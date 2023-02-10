//============================
// TOGGLE DEBUG MODES
/* 
console.log = function() {};
//*/
/* */
alert = function() {};
//*/

//============================
// IMPORT DATA
import { set } from "./data/sets.js";
import { mask } from "./data/masks.js";

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

let gear = [
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
  alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); // LapHD: 1920x1080 Lap: 1280x720; Mob: 432x896

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
    if (element.length) {
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
  // MAKE SELECTION POPUP
  const tplPopupParent = document.getElementById('popup--frame-main');
  const tplPopupBase = document.getElementById('template--popup');
  for (let gearClass of gear) {//does this work?
    let clonedPopupNode = tplPopupBase.content.cloneNode(true);

    let popupGear = clonedPopupNode.getElementById('popup--gear');
    popupGear.id += `--${gearClass}`;

    // POPULATE SELECTION LIST
    const tplListParent = clonedPopupNode.getElementById('list--gear');
    tplListParent.id += `--${gearClass}`;
    const tplListBase = document.getElementById('template--list-gear-item');

    for (let gearName in mask) {
      let clonedListNode = tplListBase.content.cloneNode(true);

      // panel settings
      let panelItem = clonedListNode.getElementById('panel--item')

      // onclick
      panelItem.addEventListener('click', (evt) => { evt.stopPropagation();
 hidePopup() }, false);
      panelItem.addEventListener('click', (evt) => { evt.stopPropagation();
 applySelection(gearClass, gearName) }, false);

      // panel color
      if (mask[`${gearName}`].rarity == "Exotic") {
        panelItem.style.borderColor = 'var(--cExotic)';
        panelItem.style.color = 'var(--cExotic)';
      }
      else if (mask[`${gearName}`].rarity == "Named") {
        panelItem.style.borderColor = 'var(--cNamed)';
        panelItem.style.color = 'var(--cNamed)';
      }
      else if (mask[`${gearName}`].rarity == "GearSet") {
        panelItem.style.borderColor = 'var(--cGearSet)';
        panelItem.style.color = 'var(--cGearSet)';
      };

      // item name
      let itemName = clonedListNode.getElementById('item--name')
      itemName.innerHTML = `${gearName}`;

      // item type
      if (mask[`${gearName}`].hasOwnProperty('type') && mask[`${gearName}`].type !== `${gearName}`) {
        let itemType = clonedListNode.getElementById('item--type');
        itemType.innerHTML = "(";
        itemType.innerHTML += mask[`${gearName}`].type;
        itemType.innerHTML += ")";
      };

      // item set boni
      let itemSetAttributes = clonedListNode.getElementById('item--set-attributes');
      itemSetAttributes.classList.add('h-line--top');
      let setAttribute1 = clonedListNode.getElementById('set-attribute-1');
      let setAttribute2 = clonedListNode.getElementById('set-attribute-2');
      let setAttribute3 = clonedListNode.getElementById('set-attribute-3');
      let setName = mask[`${gearName}`].type;

      if (mask[`${gearName}`].rarity == "Exotic") {
        setAttribute1.innerHTML = mask[`${gearName}`].attribute1Name + ': ';
        setAttribute1.innerHTML += mask[`${gearName}`].attribute1Value;
        setAttribute2.innerHTML = mask[`${gearName}`].attribute2Name + ': ';
        setAttribute2.innerHTML += mask[`${gearName}`].attribute2Value;
        setAttribute3.innerHTML = mask[`${gearName}`].attribute3Name + ': ';
        setAttribute3.innerHTML += mask[`${gearName}`].attribute3Value;
      }
      else if (mask[`${gearName}`].rarity == "GearSet") {
        setAttribute1.innerHTML = set[`${setName}`].attribute1Name + ': ';
        setAttribute1.innerHTML += set[`${setName}`].attribute1Value;
        setAttribute2.innerHTML = set[`${setName}`].attribute2Name + ': ';
        setAttribute2.innerHTML += set[`${setName}`].attribute2Value;
        setAttribute3.innerHTML = set[`${setName}`].gearSetTalentName + '<br><br>';
        setAttribute3.innerHTML += set[`${setName}`].gearSetTalentText;
      }
      else if (mask[`${gearName}`].rarity !== "Improvised") { //aka. is a normal high-end-item
        setAttribute1.innerHTML = set[`${setName}`].attribute1Name + ': ';
        setAttribute1.innerHTML += set[`${setName}`].attribute1Value;
        setAttribute2.innerHTML = set[`${setName}`].attribute2Name + ': ';
        setAttribute2.innerHTML += set[`${setName}`].attribute2Value;
        setAttribute3.innerHTML = set[`${setName}`].attribute3Name + ': ';
        setAttribute3.innerHTML += set[`${setName}`].attribute3Value;
      };

      // item talent
      let itemTalentName = clonedListNode.getElementById('item--talent-name')
      if (mask[`${gearName}`].hasOwnProperty('talentName')) {
        itemTalentName.classList.add('h-line--top');
        itemTalentName.innerHTML = mask[`${gearName}`].talentName;
      };
      if (mask[`${gearName}`].hasOwnProperty('talentText')) {
        clonedListNode.getElementById('item--talent-text').innerHTML = mask[`${gearName}`].talentText;
      };

      tplListParent.appendChild(clonedListNode);
    }
    tplPopupParent.appendChild(clonedPopupNode);
  }
}, false);

//==============================
// EVENT LISTENERS
// close popup when background is clicked
//let eventTarget = document.querySelectorAll(`[id*="${icons[i]}"]`);
let popupFrameMain = document.getElementById("popup--frame-main");
popupFrameMain.addEventListener("click", () => {hidePopup() }, false);

// open selection popup
for (let i = 0; i < gear.length; i++) {
  let panelItem = document.getElementById(`panel--${gear[i]}`);
  panelItem.addEventListener('click', (evt) => { evt.stopPropagation();
 showPopup(gear[i]) }, false);
}

//==============================
// FUNCTIONS
function showPopup(arg) {
  document.getElementById('popup--frame-main').style.display = "flex";
  document.getElementById(`popup--gear--${arg}`).style.display = "flex";
  // reset scroll state to top
  ////document.getElementById(`list--gear--${arg}`).scrollTop = 0;
  document.body.style.overflow = "hidden";
}

function hidePopup() {
  document.getElementById('popup--frame-main').style.display = "none";
  document.body.style.overflow = "";
}

function applySelection(gearClass, gearName) {
  const tplItemSelectedParent = document.getElementById(`panel--${gearClass}`);
  tplItemSelectedParent.innerHTML = "";
  const tplItemSelectedBase = document.getElementById('template--item-selected');
    let clonedItemSelectedNode = tplItemSelectedBase.content.cloneNode(true);

    let itemSelected = clonedItemSelectedNode.getElementById('item-selected');
    itemSelected.id += `--${gearClass}`;
    
    //let panelItem = document.getElementById(`panel--${gearClass}`);
    //panelItem.removeEventListener('click', this, false);

    let itemSelectedName = clonedItemSelectedNode.getElementById('item-selected--name');
      itemSelectedName.innerHTML = mask[`${gearName}`].name;

    /*
    item-selected--name
    item-selected--type
    item-selected--core-attribute
    item-selected--minor-attribute-1
    item-selected--minor-attribute-2
    item-selected--mod
    item-selected--talent-name
    item-selected--talent-text
    */

    tplItemSelectedParent.appendChild(clonedItemSelectedNode);
}
