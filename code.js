//============================
// IMPORT DATA
import { set } from "./data/sets.js"; //mltpc because sets noun verb confusion
let mltpc = set;
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

let equipment = [
  //"specialisation",
  //"weapon-1",
  //"weapon-2",
  //"sidearm",
  mask,
  //"backpack",
  //"chest",
  //"gloves",
  //"holster",
  //"kneepads",
  //"skill-1",
  //"skill-2",
];

/*
//masks.js -> equipment.js
export const equipment = {
  "mask": {
    "Vile": {
      rarity: "Exotic",
      type: "Exotic",
      attribute1Name: "Skill Tier",
      attribute1Value: 1,
      attribute2Name: "Status Effects",
      attribute2Value: 10,
      attribute3Name: "Hazard Protection",
      attribute3Value: 10,
      talentName: "Toxic Delivery",
      talentText: "Status effects also apply a damage over time debuff for 10s.\r\n Total damage dealt is equal to 50% of your concussion grenade damage and increased by your status effect attributes.",
    }
  }
}
*/

//============================
// STARTUP FUNCTION
document.addEventListener('DOMContentLoaded', () => {
  //============================
  // DEBUG
  //alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); // LapHD: 1920x1080 Lap: 1280x720; Mob: 432x896

  // COLORIZE PANELS
  let panels = document.getElementsByClassName("panel");
  let ccnt = 0;

  // iterate over all panels
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
  // iterate over icons.png-array
  for (let i = 0; i < icons.length; i++) {
    var img = new Image();
    img.src = `./icons/${icons[i]}.png`;
    let value = `linear-gradient(var(--cbgr75), var(--cbgr75)), url(${img.src}) center/contain no-repeat`;
    let element = document.querySelectorAll(`[id *= "${icons[i]}"]`);
    if (element.length) {
      // iterate over all IDs with an icon name
      for (let j = 0; j < element.length; j++) {
        element[j].style.background = value;
        /*
        let scale = 0.75 * Math.min(element[j].offsetWidth/img.width, element[j].offsetHeight/img.height)
        element[j].style.backgroundSize = `${img.width * scale}px ${img.height * scale}px`;
        //*/
      }
    }
  };

  //============================
  // INITIALIZE EQUIPMENT SELECTION POPUP
  const tplPopupParent = document.getElementById('popup--frame-main');
  const tplPopupBase = document.getElementById('template--popup');

  // iterate over geartypes array
  for (let i = 0; i < equipment.length; i++) {
    let gearTypeObject = equipment[i];
    let clonedPopupNode = tplPopupBase.content.cloneNode(true);

    let popupSelectGear = clonedPopupNode.getElementById('popup--select-gear');
    popupSelectGear.id += `--${gearTypeObject.name}`;
    popupSelectGear.addEventListener('click', (evt) => {
      evt.stopPropagation()
    });

    // FILL SELECTION LIST
    const tplListParent = clonedPopupNode.getElementById('list--select-gear');
    tplListParent.id += `--${gearTypeObject.name}`;
    const tplListBase = document.getElementById('template--list-gear-item');

    // iterate over all items in $gearTypeObject
    for (let gearItemName in gearTypeObject) { if (gearItemName !== "name") {
      let gearItem = gearTypeObject[gearItemName]
      let clonedListNode = tplListBase.content.cloneNode(true);

      // panel settings
      let panelItem = clonedListNode.getElementById('panel--item')

      // onclick
      panelItem.classList.add('cursor-pointer');
      panelItem.addEventListener('click', () => {
        applySelection(gearTypeObject, gearItemName)
      }, false);

      // panel color
      if (gearItem.rarity == "Exotic") {
        panelItem.style.borderColor = 'var(--cExotic)';
        panelItem.style.color = 'var(--cExotic)';
      }
      else if (gearItem.rarity == "Named") {
        panelItem.style.borderColor = 'var(--cNamed)';
        panelItem.style.color = 'var(--cNamed)';
      }
      else if (gearItem.rarity == "GearSet") {
        panelItem.style.borderColor = 'var(--cGearSet)';
        panelItem.style.color = 'var(--cGearSet)';
      };

      // item name
      let itemName = clonedListNode.getElementById('item--name')
      itemName.innerHTML = `${gearItemName}`;

      // item type
      if (gearItem.hasOwnProperty('type') && gearItem.type !== `${gearItemName}`) {
        let itemType = clonedListNode.getElementById('item--type');
        itemType.innerHTML = "(";
        itemType.innerHTML += gearItem.type;
        itemType.innerHTML += ")";
      };

      // item set boni
      let itemMltpcAttributes = clonedListNode.getElementById('item--mltpc-attributes');
      itemMltpcAttributes.classList.add('h-line--top');
      let mltpcAttribute1 = clonedListNode.getElementById('mltpc-attribute-1');
      let mltpcAttribute2 = clonedListNode.getElementById('mltpc-attribute-2');
      let mltpcAttribute3 = clonedListNode.getElementById('mltpc-attribute-3');
      let mltpcName = gearItem.type;

      if (gearItem.rarity == "Exotic") {
        mltpcAttribute1.innerHTML = gearItem.attribute1Name + ': ';
        mltpcAttribute1.innerHTML += gearItem.attribute1Value;
        mltpcAttribute2.innerHTML = gearItem.attribute2Name + ': ';
        mltpcAttribute2.innerHTML += gearItem.attribute2Value;
        mltpcAttribute3.innerHTML = gearItem.attribute3Name + ': ';
        mltpcAttribute3.innerHTML += gearItem.attribute3Value;
      }
      else if (gearItem.rarity == "GearSet") {
        mltpcAttribute1.innerHTML = mltpc[mltpcName].attribute1Name + ': ';
        mltpcAttribute1.innerHTML += mltpc[mltpcName].attribute1Value;
        mltpcAttribute2.innerHTML = mltpc[mltpcName].attribute2Name + ': ';
        mltpcAttribute2.innerHTML += mltpc[mltpcName].attribute2Value;
        mltpcAttribute3.innerHTML = mltpc[mltpcName].gearMltpcTalentName + '<br><br>';
        mltpcAttribute3.innerHTML += mltpc[mltpcName].gearMltpcTalentText;
      }
      else if (gearItem.rarity !== "Improvised") { //aka. is a normal high-end-item
        mltpcAttribute1.innerHTML = mltpc[mltpcName].attribute1Name + ': ';
        mltpcAttribute1.innerHTML += mltpc[mltpcName].attribute1Value;
        mltpcAttribute2.innerHTML = mltpc[mltpcName].attribute2Name + ': ';
        mltpcAttribute2.innerHTML += mltpc[mltpcName].attribute2Value;
        mltpcAttribute3.innerHTML = mltpc[mltpcName].attribute3Name + ': ';
        mltpcAttribute3.innerHTML += mltpc[mltpcName].attribute3Value;
      };

      // item talent
      let itemTalentName = clonedListNode.getElementById('item--talent-name')
      if (gearItem.hasOwnProperty('talentName')) {
        itemTalentName.classList.add('h-line--top');
        itemTalentName.innerHTML = gearItem.talentName;
      };
      if (gearItem.hasOwnProperty('talentText')) {
        clonedListNode.getElementById('item--talent-text').innerHTML = gearItem.talentText;
      };

      tplListParent.appendChild(clonedListNode);
    }}
    tplPopupParent.appendChild(clonedPopupNode);
  }
}, false);

//==============================
// EVENT LISTENERS
let popupFrameMain = document.getElementById("popup--frame-main");
popupFrameMain.addEventListener('click', () => {
  hidePopup()
}, false);

// open selection popup
for (let i = 0; i < equipment.length; i++) {
  let gearTypeObject = equipment[i];
  let panelItem = document.getElementById(`panel--${gearTypeObject.name}`);
  panelItem.classList.add('cursor-pointer');
  panelItem.addEventListener('click', (evt) => {
    showPopup(gearTypeObject)
  }, false);
}

//==============================
// FUNCTIONS
function showPopup(gearTypeObject) {
  document.getElementById('popup--frame-main').style.display = "flex";
  document.getElementById(`popup--select-gear--${gearTypeObject.name}`).style.display = "flex";
  // reset scroll state to top
  document.getElementById(`list--select-gear--${gearTypeObject.name}`).scrollTop = 0;
  document.body.style.overflow = "hidden";
}

function hidePopup() {
  document.getElementById('popup--frame-main').style.display = "none";
  document.body.style.overflow = "";
}

function applySelection(gearTypeObject, gearItemName) {
  hidePopup();
  //============================
  // FILL GEAR SLOT
    const tplGearslotParent = document.getElementById(`panel--${gearTypeObject.name}`);
    tplGearslotParent.innerHTML = "";
    const tplGearslotBase = document.getElementById('template--gearslot');
    let clonedGearslotNode = tplGearslotBase.content.cloneNode(true);

    //let Gearslot = clonedGearslotNode.getElementById('gearslot');
    //Gearslot.id += `--${gearTypeObject}`;

    //let GearslotName = clonedGearslotNode.getElementById('gearslot--name');
      //GearslotName.innerHTML = `Choose ${gearTypeObject}`;
      ////add new showPopup Listener

    /*
    gearslot--name
    gearslot--type
    gearslot--core-attribute
    gearslot--minor-attribute-1
    gearslot--minor-attribute-2
    gearslot--mod
    gearslot--talent-name
    gearslot--talent-text
    */

    tplGearslotParent.appendChild(clonedGearslotNode);
}

//let eventTarget = document.querySelectorAll(`[id*="${icons[i]}"]`);
//for (let i = 0; i < array.length; i++) {
