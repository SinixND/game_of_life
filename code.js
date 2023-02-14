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

// document.addEventListener('DOMContentLoaded', () => {

//============================
// DEBUG
//alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); // LapHD: 1920x1080 Lap: 1280x720; Mob: 432x896

//============================
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

//============================
// CONSISTANT PIXEL VARIABLE
document.documentElement.style.setProperty('--tpx', `calc(1px * ${window.devicePixelRatio})`);

// CONSISTANT PIXEL VARIABLE
//============================

//============================
// SET BACKGROUND ICONS
// iterate over icons-array
for (let i = 0; i < icons.length; i++) {
  var img = new Image();
  img.src = `./icons/${icons[i]}.png`;
  let value = `linear-gradient(var(--cbgr75), var(--cbgr75)), url(${img.src})`;
  let element = document.querySelectorAll(`[id *= "${icons[i]}"]`);
  if (element.length) {
    // iterate over all IDs with an icon name
    for (let j = 0; j < element.length; j++) {
      element[j].style.background = value;
      element[j].style.backgroundOrigin = 'content-box';
      element[j].style.backgroundSize = 'contain';
      element[j].style.backgroundPosition = 'center';
      element[j].style.backgroundRepeat = 'no-repeat';
    }
  }
};

// SET BACKGROUND ICONS
//============================

//============================
// BUILD EQUIPMENT SELECTION POPUPS
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

    //============================
    // FILL SELECTION LIST
    const tplListEntryParent = clonedPopupSelectEquipmentTypeNode.getElementById(`list--select-${equipmentTypeName}`);
    tplListEntryParent.id += `--${gearTypeName}`;
    const tplListEntryBase = document.getElementById('template--selection-list-entry');

    // iterate over all items in $gearType
    for (let gearItemName in gearType) {
      let gearItem = gearType[gearItemName];
      let clonedListEntryNode = tplListEntryBase.content.cloneNode(true);

      // get list entry panel
      let panelListEntry = clonedListEntryNode.getElementById('panel--list-entry')
      panelListEntry.id += `--${gearItemName}`;

      // entry panel onclick
      panelListEntry.classList.add('cursor-pointer');
      panelListEntry.addEventListener('click', () => {
        applySelection(equipmentTypeName, gearTypeName, gearItem, gearItemName)
      }, false);

      // list entry panel color
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
      }
      else if (gearItem.rarity == "HighEnd") {
        panelListEntry.style.borderColor = 'var(--cHighEnd)';
        panelListEntry.style.color = 'var(--cHighEnd)';
      }

      // list entry name
      console.log(`getElementsByClassName: ${clonedListEntryNode.getElementsByClassName('entry--name')}`)
      console.log(`getElementsByClassName()[0]: ${clonedListEntryNode.getElementsByClassName('entry--name')[0]}`)
      let entryName = clonedListEntryNode.getElementById('entry--name')[0];
      entryName.innerHTML = `${gearItemName}`;

      // list entry type
      if (gearItem.hasOwnProperty('type') && gearItem.type !== `${gearItemName}`) {
        let entryType = clonedListEntryNode.getElementsByClassName('entry--type');
        entryType[0].innerHTML = "(";
        entryType[0].innerHTML += gearItem.type;
        entryType[0].innerHTML += ")";
      };

      // list entry set (mltpc) boni
      let entryMltpcAttributes = clonedListEntryNode.getElementsByClassName('entry--mltpc-attributes');
      entryMltpcAttributes[0].classList.add('h-line--top');
      let mltpcAttribute1 = clonedListEntryNode.getElementsByClassName('mltpc-attribute-1');
      let mltpcAttribute2 = clonedListEntryNode.getElementsByClassName('mltpc-attribute-2');
      let mltpcAttribute3 = clonedListEntryNode.getElementsByClassName('mltpc-attribute-3');
      let mltpcName = gearItem.type;

      if (gearItem.rarity == "Exotic") {
        mltpcAttribute1[0].innerHTML = gearItem.attribute1Name + ': ';
        mltpcAttribute1[0].innerHTML += gearItem.attribute1Value;
        mltpcAttribute2[0].innerHTML = gearItem.attribute2Name + ': ';
        mltpcAttribute2[0].innerHTML += gearItem.attribute2Value;
        mltpcAttribute3[0].innerHTML = gearItem.attribute3Name + ': ';
        mltpcAttribute3[0].innerHTML += gearItem.attribute3Value;
      }
      else if (gearItem.rarity == "GearSet") {
        mltpcAttribute1[0].innerHTML = mltpc[mltpcName].attribute1Name + ': ';
        mltpcAttribute1[0].innerHTML += mltpc[mltpcName].attribute1Value;
        mltpcAttribute2[0].innerHTML = mltpc[mltpcName].attribute2Name + ': ';
        mltpcAttribute2[0].innerHTML += mltpc[mltpcName].attribute2Value;
        mltpcAttribute3[0].innerHTML = mltpc[mltpcName].gearMltpcTalentName + '<br><br>';
        mltpcAttribute3[0].innerHTML += mltpc[mltpcName].gearMltpcTalentText;
      }
      else if (gearItem.rarity !== "Improvised") { //aka. is a normal brand-item
        mltpcAttribute1[0].innerHTML = mltpc[mltpcName].attribute1Name + ': ';
        mltpcAttribute1[0].innerHTML += mltpc[mltpcName].attribute1Value;
        mltpcAttribute2[0].innerHTML = mltpc[mltpcName].attribute2Name + ': ';
        mltpcAttribute2[0].innerHTML += mltpc[mltpcName].attribute2Value;
        mltpcAttribute3[0].innerHTML = mltpc[mltpcName].attribute3Name + ': ';
        mltpcAttribute3[0].innerHTML += mltpc[mltpcName].attribute3Value;
      };

      // list entry talent
      let entryTalentName = clonedListEntryNode.getElementsByClassName('entry--talent-name')
      if (gearItem.hasOwnProperty('talentName')) {
        entryTalentName[0].classList.add('h-line--top');
        entryTalentName[0].innerHTML = gearItem.talentName;
      };
      if (gearItem.hasOwnProperty('talentText')) {
        clonedListEntryNode.getElementsByClassName('entry--talent-text')[0].innerHTML = gearItem.talentText;
      };

      tplListEntryParent.appendChild(clonedListEntryNode);
    }

    // FILL SELECTION LIST
    //============================

    tplPopupParent.appendChild(clonedPopupSelectEquipmentTypeNode);
  }
}

// BUILD EQUIPMENT SELECTION POPUPS
//============================

//==============================
// EVENT LISTENERS
// create event listener aborts
let abortControlls = {};

// add listener: close popup on background click
let popupFrameMain = document.getElementById("popup--frame-main");
popupFrameMain.addEventListener('click', () => {
  hidePopup();
}, false);

// add removable listener to gearslot-panel: show selection popup
for (let equipmentTypeName in equipment) {
  let equipmentType = equipment[equipmentTypeName];
  for (let gearTypeName in equipmentType) {
    let panelGearType = document.getElementById(`panel--${gearTypeName}`);
    panelGearType.classList.add('cursor-pointer');

    // create event listener abort
    abortControlls[`controller-${gearTypeName}`] = new AbortController();

    panelGearType.addEventListener('click', () => {
      showPopup(equipmentTypeName, gearTypeName);
    }, { signal: abortControlls[`controller-${gearTypeName}`].signal }, false);
  }
}

// EVENT LISTENERS
//==============================

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

  let GearslotName = clonedGearslotNode.getElementsByClassName('gearslot--name');
  GearslotName[0].innerHTML = `${gearItemName}`;

  // add new showPopup listener to "Name" div
  GearslotName[0].classList.add('cursor-pointer');
  GearslotName[0].addEventListener('click', () => {
    showPopup(equipmentTypeName, gearTypeName);
  }, false);

  // gearslot color
  if (gearItem.rarity == "Exotic") {
    tplGearslotParent.style.borderColor = 'var(--cExotic)';
    tplGearslotParent.style.color = 'var(--cExotic)';
    GearslotName[0].style.background = 'linear-gradient(28deg, var(--c0), var(--cExotic))';
  }
  else if (gearItem.rarity == "GearSet") {
    tplGearslotParent.style.borderColor = 'var(--cGearSet)';
    tplGearslotParent.style.color = 'var(--cGearSet)';
    GearslotName[0].style.background = 'linear-gradient(28deg, var(--c0), var(--cGearSet))';
  }
  else if (gearItem.rarity == "Named") {
    tplGearslotParent.style.borderColor = 'var(--cNamed)';
    tplGearslotParent.style.color = 'var(--cNamed)';
    GearslotName[0].style.background = 'linear-gradient(28deg, var(--c0), var(--cNamed))';
  }
  else if (gearItem.rarity == "HighEnd") {
    tplGearslotParent.style.borderColor = 'var(--cHighEnd)';
    tplGearslotParent.style.color = 'var(--cHighEnd)';
    GearslotName[0].style.background = 'linear-gradient(28deg, var(--c0), var(--cNamed))';
  };

  /*
  document.getElementById('dropdown-selector').addEventListener('click', () => {
    document.getElementById('dropdown-options').classList.toggle('hide');
  })

  gearslot--name
  gearslot--core-attribute
  gearslot--minor-attribute-1
  gearslot--minor-attribute-2
  gearslot--mod
  gearslot--talent-name
  gearslot--talent-text
  */

  tplGearslotParent.appendChild(clonedGearslotNode);

  // FILL GEAR SLOT
  //============================
}

  // FUNCTIONS
  //==============================

  //let eventTarget = document.querySelectorAll(`[id*="${icons[i]}"]`);

// }, false);
