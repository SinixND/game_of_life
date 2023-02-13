//============================
// IMPORT DATA
import { attributes } from "./data/attributes.js";
import { sets } from "./data/sets.js"; //mltpc because sets noun verb confusion
let mltpc = sets;
import { equipment } from "./data/equipment.js";

// ARRAYS
let colors = [
  '--car',
  '--cag',
  '--cab',
  '--cay',
  '--cac',
  '--cam',
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
    panels[i].style.borderColor = `var(${colors[ccnt]})`;
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
  // INITIALIZE EQUIPMENT SELECTION POPUPS
  const tplPopupParent = document.getElementById('popup--frame-main');

  // iterate over equipmentTypes
  for (let equipmentTypeName in equipment) {
    let equipmentType = equipment[equipmentTypeName];

    const tplPopupSelectEquipmentTypeBase = document.getElementById(`template--popup--select-${equipmentTypeName}`);
    // iterate over gearTypes
    for (let gearTypeName in equipmentType) {
      let gearType = equipmentType[gearTypeName];

      let clonedPopupSelectEquipmentTypeNode = tplPopupSelectEquipmentTypeBase.content.cloneNode(true);

      let popupSelectEquipmentType = clonedPopupSelectEquipmentTypeNode.getElementById(`popup--select-${equipmentTypeName}`);
      popupSelectEquipmentType.id += `--${gearTypeName}`;
      popupSelectEquipmentType.addEventListener('click', (evt) => {
        evt.stopPropagation()
      });

      // FILL SELECTION LIST
      const tplListEntryParent = clonedPopupSelectEquipmentTypeNode.getElementById(`list--select-${equipmentTypeName}`);
      tplListEntryParent.id += `--${gearTypeName}`;
      const tplListEntryBase = document.getElementById('template--selection-list-entry');

      // iterate over all items in $gearType
      for (let gearItemName in gearType) {
        let gearItem = gearType[gearItemName];
        let clonedListEntryNode = tplListEntryBase.content.cloneNode(true);

        // panel settings
        let panelListEntry = clonedListEntryNode.getElementById('panel--list-entry')

        // onclick
        panelListEntry.classList.add('cursor-pointer');
        panelListEntry.addEventListener('click', () => {
          applySelection(equipmentTypeName, gearTypeName, gearItem, gearItemName)
        }, false);

        // panel color
        if (gearItem.rarity == "Exotic") {
          panelListEntry.style.borderColor = 'var(--cExotic)';
          panelListEntry.style.color = 'var(--cExotic)';
        }
        else if (gearItem.rarity == "Named") {
          panelListEntry.style.borderColor = 'var(--cNamed)';
          panelListEntry.style.color = 'var(--cNamed)';
        }
        else if (gearItem.rarity == "GearSet") {
          panelListEntry.style.borderColor = 'var(--cGearSet)';
          panelListEntry.style.color = 'var(--cGearSet)';
        };

        // entry name
        let entryName = clonedListEntryNode.getElementById('entry--name')
        entryName.innerHTML = `${gearItemName}`;

        // entry type
        if (gearItem.hasOwnProperty('type') && gearItem.type !== `${gearItemName}`) {
          let entryType = clonedListEntryNode.getElementById('entry--type');
          entryType.innerHTML = "(";
          entryType.innerHTML += gearItem.type;
          entryType.innerHTML += ")";
        };

        // entry set (mltpc) boni
        let entryMltpcAttributes = clonedListEntryNode.getElementById('entry--mltpc-attributes');
        entryMltpcAttributes.classList.add('h-line--top');
        let mltpcAttribute1 = clonedListEntryNode.getElementById('mltpc-attribute-1');
        let mltpcAttribute2 = clonedListEntryNode.getElementById('mltpc-attribute-2');
        let mltpcAttribute3 = clonedListEntryNode.getElementById('mltpc-attribute-3');
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
        else if (gearItem.rarity !== "Improvised") { //aka. is a normal brand-item
          mltpcAttribute1.innerHTML = mltpc[mltpcName].attribute1Name + ': ';
          mltpcAttribute1.innerHTML += mltpc[mltpcName].attribute1Value;
          mltpcAttribute2.innerHTML = mltpc[mltpcName].attribute2Name + ': ';
          mltpcAttribute2.innerHTML += mltpc[mltpcName].attribute2Value;
          mltpcAttribute3.innerHTML = mltpc[mltpcName].attribute3Name + ': ';
          mltpcAttribute3.innerHTML += mltpc[mltpcName].attribute3Value;
        };

        // entry talent
        let entryTalentName = clonedListEntryNode.getElementById('entry--talent-name')
        if (gearItem.hasOwnProperty('talentName')) {
          entryTalentName.classList.add('h-line--top');
          entryTalentName.innerHTML = gearItem.talentName;
        };
        if (gearItem.hasOwnProperty('talentText')) {
          clonedListEntryNode.getElementById('entry--talent-text').innerHTML = gearItem.talentText;
        };

        tplListEntryParent.appendChild(clonedListEntryNode);
      }
      tplPopupParent.appendChild(clonedPopupSelectEquipmentTypeNode);
    }
  }
}, false);

//==============================
// EVENT LISTENERS
// create event listener aborts
let abortControlls = {};

// listener: close popup on background click
let popupFrameMain = document.getElementById("popup--frame-main");
popupFrameMain.addEventListener('click', () => {
  hidePopup();
}, false);

// listener: show selection popup
for (let equipmentTypeName in equipment) {
  let equipmentType = equipment[equipmentTypeName];
  for (let gearTypeName in equipmentType) {
    let panelGearType = document.getElementById(`panel--${gearTypeName}`);
    panelGearType.classList.add('cursor-pointer');
    
    // create event listener aborts
    abortControlls[`controller-${gearTypeName}`] = new AbortController();

    panelGearType.addEventListener('click', () => {
      showPopup(equipmentTypeName, gearTypeName);
    }, {signal: abortControlls[`controller-${gearTypeName}`].signal}, false);
  }
}

//==============================
// FUNCTIONS
function showPopup(equipmentTypeName, gearTypeName) {
  //document.getElementById('popup--frame-main').style.display = "flex";
  document.getElementById('popup--frame-main').classList.remove("hide");
  //document.getElementById(`popup--select-armor--${equipmentTypeName}`).style.display = "flex";
  document.getElementById(`popup--select-${equipmentTypeName}--${gearTypeName}`).classList.remove("hide");
  // reset scroll state to top
  document.getElementById(`list--select-${equipmentTypeName}--${gearTypeName}`).scrollTop = 0;
  document.body.style.overflow = "hidden";
}

function hidePopup() {
  document.getElementById('popup--frame-main').classList.add("hide");
  document.body.style.overflow = "";
}

function applySelection(equipmentTypeName, gearTypeName, gearItem, gearItemName) {
  let panelGearType = document.getElementById(`panel--${gearTypeName}`);

  // remove previous showPopup listener, bc slot content has to be clickable
  panelGearType.classList.remove('cursor-pointer');
  abortControlls[`controller-${gearTypeName}`].abort();

  hidePopup();

  //============================
  // FILL GEAR SLOT
  const tplGearslotParent = document.getElementById(`panel--${gearTypeName}`);
  tplGearslotParent.innerHTML = "";
  const tplGearslotBase = document.getElementById('template--gearslot');
  let clonedGearslotNode = tplGearslotBase.content.cloneNode(true);

  let Gearslot = clonedGearslotNode.getElementById('gearslot');
  Gearslot.id += `--${gearTypeName}`;

  let GearslotName = clonedGearslotNode.getElementById('gearslot--name');
  GearslotName.innerHTML = `${gearItemName}`;

  // panel settings
  // add new showPopup listener
  GearslotName.classList.add('cursor-pointer');
  GearslotName.addEventListener('click', () => {
    showPopup(equipmentTypeName, gearTypeName);
  }, false);

  // panel and container color
  if (gearItem.rarity == "Exotic") {
    tplGearslotParent.style.borderColor = 'var(--cExotic)';
    tplGearslotParent.style.color = 'var(--cExotic)';
    GearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cExotic))';
  } 
  else if (gearItem.rarity == "GearSet") {
    tplGearslotParent.style.borderColor = 'var(--cGearSet)';
    tplGearslotParent.style.color = 'var(--cGearSet)';
    GearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cGearSet))';
  } 
  else {
    tplGearslotParent.style.borderColor = 'var(--cNamed)';
    tplGearslotParent.style.color = 'var(--cNamed)';
    GearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cNamed))';
  };

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
