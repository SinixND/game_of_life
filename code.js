//============================
/* IMPORT DATA {*/

import { db } from "./data/database.js";
let mltpc = db['setboni'];

/*} IMPORT DATA  */
//============================

//============================
/* ARRAYS {*/

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
  "coreBlue",
  "minorBlue",
  "modBlue2",
  "modBlue",
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
  "coreRed",
  "minorRed",
  "modRed2",
  "modRed",
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
  "coreYellow",
  "minorYellow",
  "modYellow2",
  "modYellow",
  "Tip_of_the_Spear",
  "True_Patriot",
  "Umbra_Initiative",
  "Uzina_Getica",
  "Walker_Harris_&_Co",
  "Wyvern_Wear",
  "Yaahl_Gear",
];

/*} ARRAYS  */
//============================

//============================
/* DEBUG {*/

//alert( 'Res: (W)' + screen.width + 'x(H)' + screen.height + '  ratio: ' + window.devicePixelRatio); // LapHD: 1920x1080 Lap: 1280x720; Mob: 432x896

/*} DEBUG  */
//============================

//============================
/* COLORIZE PANELS {*/

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

/*} COLORIZE PANELS  */
//============================

//============================
/* CONSISTANT PIXEL VARIABLE {*/

document.documentElement.style.setProperty('--tpx', `calc(1px * ${window.devicePixelRatio})`);

/*} CONSISTANT PIXEL VARIABLE  */
//============================

//============================
/* SET BACKGROUND ICONS {*/
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

/*} SET BACKGROUND ICONS  */
//============================

//============================
/* CLONE EQUIPMENT SELECTION POPUPS {*/
const tplPopupParent = document.getElementById('popup--frame-main');

// iterate over equipmentTypes
for (let equipmentTypeName in db['equipment']) {
  let equipmentType = db['equipment'][equipmentTypeName];

  const tplPopupSelectEquipmentTypeBase = document.getElementById(`template--popup--select-${equipmentTypeName}`);

  // iterate over gearTypes
  for (let gearTypeName in equipmentType) {
    let gearType = equipmentType[gearTypeName];

    let clonedPopupSelectEquipmentTypeNode = tplPopupSelectEquipmentTypeBase.content.cloneNode(true);
    let popupSelectEquipmentType = clonedPopupSelectEquipmentTypeNode.getElementById(`popup--select-${equipmentTypeName}-`);
    popupSelectEquipmentType.id += `-${gearTypeName}`;
    let listSelectEquipmentType = clonedPopupSelectEquipmentTypeNode.getElementById(`list--select-${equipmentTypeName}-`);
    listSelectEquipmentType.id += `-${gearTypeName}`;
    tplPopupParent.appendChild(clonedPopupSelectEquipmentTypeNode);

    popupSelectEquipmentType = document.getElementById(`${popupSelectEquipmentType.id}`)
    popupSelectEquipmentType.getElementsByClassName('popup--title')[0].innerHTML = `- Choose ${gearTypeName} -`;

    //============================
    /* CLONE SELECTION LIST ENTRY {*/
    const tplListEntryParent = document.getElementById(`${listSelectEquipmentType.id}`);
    const tplListEntryBase = document.getElementById('template--selection-list-entry');

    // iterate over all items in $gearType
    for (let gearItemName in gearType) {
      console.log(gearItemName)
      let gearItem = gearType[gearItemName];

      // get list entry panel
      let clonedListEntryNode = tplListEntryBase.content.cloneNode(true);
      let panelListEntry = clonedListEntryNode.getElementById('panel--list-entry-');
      panelListEntry.id += `-${gearTypeName}--${gearItemName}`;

      tplListEntryParent.appendChild(clonedListEntryNode);
      panelListEntry = document.getElementById(`${panelListEntry.id}`);

      // list entry panel onclick
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
      else if (gearItem.rarity == "Gearset") {
        panelListEntry.style.borderColor = 'var(--cGearset)';
        panelListEntry.style.color = 'var(--cGearset)';
      }
      else if (gearItem.rarity == "High End") {
        panelListEntry.style.borderColor = 'var(--cHighEnd)';
        panelListEntry.style.color = 'var(--cHighEnd)';
      }

      // list entry name
      let entryName = panelListEntry.getElementsByClassName('entry--name')[0];
      entryName.innerHTML = gearItemName;

      // list entry type
      let entryRarity = panelListEntry.getElementsByClassName('entry--rarity')[0];
      entryRarity.innerHTML = "(";
      entryRarity.innerHTML += gearItem.rarity;
      if (gearItem.rarity == 'Named') {
        entryRarity.innerHTML += " " + gearItem.type;
      }
      entryRarity.innerHTML += ")";

      // list entry set (mltpc) boni
      if (gearItem.rarity !== 'Exotic' && gearItem.rarity !== 'Improvised') {
        let entryMltpcAttributes = panelListEntry.getElementsByClassName('entry--mltpc-attributes')[0];
        entryMltpcAttributes.classList.add('h-line--top');
        entryMltpcAttributes = entryMltpcAttributes.getElementsByClassName('ol')[0];
        let mltpcName = gearItem.type;

        if (gearItem.rarity == "Gearset") {
          for (let attribute in mltpc.Gearset[mltpcName]) {
            if (mltpc.Gearset[mltpcName][attribute].requiredPieces == 4) {
              entryMltpcAttributes.innerHTML += "<li>" + mltpc.Gearset[mltpcName][attribute].name + ': <br><br>' + mltpc.Gearset[mltpcName][attribute].value + "</li>";
            }
            else {
              entryMltpcAttributes.innerHTML += "<li>" + mltpc.Gearset[mltpcName][attribute].name + ': ' + mltpc.Gearset[mltpcName][attribute].value + "</li>";
            }
          }
        }
        else if (gearItem.rarity !== 'Improvised' && (gearItem.rarity == 'High End' || gearItem.rarity == 'Named')) {
          for (let attribute in mltpc.Brandset[mltpcName]) {
            entryMltpcAttributes.innerHTML += "<li>" + mltpc.Brandset[mltpcName][attribute].name + ': ' + mltpc.Brandset[mltpcName][attribute].value + "</li>";
          }
        };
      }

      // list entry talent
      let entryTalentName = panelListEntry.getElementsByClassName('entry--talent-name')[0];
      if (gearItem.hasOwnProperty('talent')) {
        entryTalentName.classList.add('h-line--top');
        entryTalentName.innerHTML = gearItem['talent'].name;
        panelListEntry.getElementsByClassName('entry--talent-text')[0].innerText = gearItem['talent'].value;
      }
    }

    /*} CLONE SELECTION LIST ENTRY  */
    //============================
  }
}

/*} CLONE EQUIPMENT SELECTION POPUPS  */
//============================

//==============================
/* EVENT LISTENERS {*/
// create event listener aborts
let abortControlls = {};

// add listener: close popup on background click
let popupFrameMain = document.getElementById("popup--frame-main");
popupFrameMain.addEventListener('click', (e) => {
  hidePopups();
}, false);

// add removable listener to gearslot-panel: show selection popup
for (let equipmentTypeName in db['equipment']) {
  let equipmentType = db['equipment'][equipmentTypeName];
  for (let gearTypeName in equipmentType) {
    let panelGearType = document.getElementById(`panel--${gearTypeName}`);
    panelGearType.classList.add('cursor-pointer');

    // create event listener abort
    abortControlls[`controller-${gearTypeName}`] = new AbortController();

    panelGearType.addEventListener('click', () => {
      hideOtherDropdowns();
      showPopup(equipmentTypeName, gearTypeName);
    }, { signal: abortControlls[`controller-${gearTypeName}`].signal }, false);
  }
}

/*} EVENT LISTENERS  */
//==============================

//==============================
/* FUNCTIONS {*/
function hideOtherDropdowns(target) {
  let allDropdowns = document.getElementsByClassName('dropdown--options');
  for (let dropdown of allDropdowns) {
    if (dropdown !== target && !(dropdown.classList.contains('hide'))) {
      dropdown.classList.add('hide');
      dropdown.parentElement.previousElementSibling.getElementsByClassName('symbol-toggle')[0].innerHTML = "&#9660"; //hidden
    }
  }
}
function showPopup(equipmentTypeName, gearTypeName) {
  document.getElementById('popup--frame-main').classList.remove("hide");
  document.getElementById(`popup--select-${equipmentTypeName}--${gearTypeName}`).classList.remove("hide");
  // reset scroll state to top
  document.getElementById(`list--select-${equipmentTypeName}--${gearTypeName}`).scrollTop = 0;
  document.body.style.overflow = "hidden"; //prevent backgroundscrolling
}

function hidePopups() {
  document.getElementById('popup--frame-main').classList.add("hide");
  for (let element of document.getElementsByClassName('popup')) {
    element.classList.add("hide");
  }
  document.body.style.overflow = "";
}

function applySelection(equipmentTypeName, gearTypeName, gearItem, gearItemName) {
  let panelGearType = document.getElementById(`panel--${gearTypeName}`);

  // remove previous showPopup listener, bc slot content has to be clickable
  panelGearType.classList.remove('cursor-pointer');
  abortControlls[`controller-${gearTypeName}`].abort();

  hidePopups();

  //============================
  /* CLONE GEAR SLOT {*/
  const tplGearslotParent = document.getElementById(`panel--${gearTypeName}`);
  tplGearslotParent.innerHTML = "";
  const tplGearslotBase = document.getElementById('template--gearslot');
  let clonedGearslotNode = tplGearslotBase.content.cloneNode(true);

  let gearslot = clonedGearslotNode.getElementById('gearslot-');
  gearslot.id += `-${gearTypeName}`;

  tplGearslotParent.appendChild(clonedGearslotNode);
  gearslot = document.getElementById(`${gearslot.id}`);

  // gearslot-name
  let gearslotName = gearslot.getElementsByClassName('gearslot--name')[0];
  gearslotName.childNodes[0].nodeValue = gearItemName;

  // add new showPopup listener to gearslot
  gearslotName.classList.add('cursor-pointer');
  gearslotName.addEventListener('click', () => {
    hideOtherDropdowns();
    showPopup(equipmentTypeName, gearTypeName);
  }, false);

  // gearslot color
  if (gearItem.rarity == "Exotic") {
    tplGearslotParent.style.borderColor = 'var(--cExotic)';
    gearslotName.style.color = 'var(--cExotic)';
    gearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cExotic))';
  }
  else if (gearItem.rarity == "Gearset") {
    tplGearslotParent.style.borderColor = 'var(--cGearset)';
    gearslotName.style.color = 'var(--cGearset)';
    gearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cGearset))';
  }
  else if (gearItem.rarity == "Named") {
    tplGearslotParent.style.borderColor = 'var(--cNamed)';
    gearslotName.style.color = 'var(--cNamed)';
    gearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cNamed))';
  }
  else if (gearItem.rarity == "High End") {
    tplGearslotParent.style.borderColor = 'var(--cHighEnd)';
    gearslotName.style.color = 'var(--cHighEnd)';
    gearslotName.style.background = 'linear-gradient(28deg, var(--c0), var(--cNamed))';
  };

  //============================
  /* GEARSLOT ATTRIBUTES {*/
  let attributeTypeNames = []
  attributeTypeNames.push('core');

  // first minor attribute
  attributeTypeNames.push('minor');

  // 2nd minor if not gearset
  if (gearItem.rarity !== 'Gearset') {
    attributeTypeNames.push('minor');
  }

  // mod when mask, backpack, chest or improvised
  if (gearTypeName == 'mask' || gearTypeName == 'backpack' || gearTypeName == 'chest' || gearItem.type == 'Improvised') {
    attributeTypeNames.push('mod');
  }

  // talent when exotic, backpack or chest
  if (gearItem.rarity == 'Exotic' || gearTypeName == 'backpack' || gearItemName == 'chest' || equipmentTypeName == 'weapon') {
    attributeTypeNames.push('talent');
  }

  let attributeTypeName;
  for (let i in attributeTypeNames) {
    attributeTypeName = attributeTypeNames[i]
    if (attributeTypeName == 'minor') {
      attributeTypeName += i;
    }

    //============================
    /* CLONE DROPDOWN SELECTOR {*/
    const tplDropdownSelectorParent = gearslot;
    const tplDropdownSelectorBase = document.getElementById('template--dropdown');
    let clonedDropdownSelectorNode = tplDropdownSelectorBase.content.cloneNode(true);
    let dropdownSelector = clonedDropdownSelectorNode.getElementById('dropdown--selector-');
    dropdownSelector.id += `-${gearTypeName}--${attributeTypeName}`;
    let dropdownOptions = clonedDropdownSelectorNode.getElementById('dropdown--options-');
    dropdownOptions.id += `-${gearTypeName}--${attributeTypeName}`;
    tplDropdownSelectorParent.appendChild(clonedDropdownSelectorNode);
    dropdownSelector = document.getElementById(`${dropdownSelector.id}`);
    dropdownOptions = dropdownOptions.getElementsByClassName('dropdown--options')[0];

    dropdownSelector.classList.add('h-line--bottom');

    let dropdownSelectorType = dropdownSelector.getElementsByClassName('dropdown--selector--type')[0];
    let dropdownSelectorText = dropdownSelector.getElementsByClassName('dropdown--selector--text')[0];
    let dropdownSelectorValue = dropdownSelector.getElementsByClassName('dropdown--selector--value')[0];
    let dropdownSelectorSymbol = dropdownSelector.getElementsByClassName('symbol-toggle')[0];

    // dropdown selector default
    dropdownSelectorText.innerHTML = "Select ";
    switch (attributeTypeName) {
      case 'core1':
      case 'minor1':
        dropdownSelectorText.innerHTML += `first ${attributeTypeNames[i]} attribute`;
        break;

      case 'core2':
      case 'minor2':
        dropdownSelectorText.innerHTML += `second ${attributeTypeNames[i]} attribute`;
        break;

      case 'core':
      case 'minor':
        dropdownSelectorText.innerHTML += `${attributeTypeNames[i]} attribute`;
        break;

      default:
        dropdownSelectorText.innerHTML += `${attributeTypeNames[i]}`;
        break;
    }

    // handle item specific attribute
    if (gearItem.hasOwnProperty(attributeTypeName)) {
      dropdownSelectorText.innerHTML = "";
      let selectorSource;
      let pngName;
      let img;
      let gearslotTalentText = gearslot.getElementsByClassName('gearslot--talent-text')[0];
      switch (attributeTypeNames[i]) {
        case 'core':
          selectorSource = db['attribute'][equipmentTypeName][attributeTypeNames[i]];

          // add attribute icon (and name)
          pngName = selectorSource[gearItem[attributeTypeName].name].png;
          img = new Image();
          img.src = `./icons/${pngName}.png`;
          dropdownSelectorText.appendChild(img);
          dropdownSelectorText.innerHTML += " " + gearItem[attributeTypeName].name;
          dropdownSelectorValue.innerHTML = selectorSource[gearItem[attributeTypeName].name].value;

          break;

        case 'minor':
          if (gearItem.rarity == 'Named') {
            dropdownSelectorText.classList.add('named');
          }
          if (gearItem[attributeTypeName].hasOwnProperty('value')) {
            pngName = gearItem[attributeTypeName].png;
            img = new Image();
            img.src = `./icons/${pngName}.png`;
            dropdownSelectorText.appendChild(img);
            dropdownSelectorText.innerHTML += " " + gearItem[attributeTypeName].name;
            dropdownSelectorValue.innerHTML = gearItem[attributeTypeName].value;
          }
          else {
            selectorSource = db['attribute'][equipmentTypeName][attributeTypeNames[i]];

            console.log(attributeTypeName)
            pngName = selectorSource[gearItem[attributeTypeName].name].png;
            img = new Image();
            img.src = `./icons/${pngName}.png`;
            dropdownSelectorText.appendChild(img);
            dropdownSelectorText.innerHTML += " " + gearItem[attributeTypeName].name;
            dropdownSelectorValue.innerHTML = selectorSource[gearItem[attributeTypeName].name].value;
          }

          break;

        case 'talent':
          selectorSource = db['talent'];
          if (gearItem.rarity == 'Exotic') {
            dropdownSelectorText.classList.add('exotic');
          }
          else if (gearItem.rarity == 'Named') {
            dropdownSelectorText.classList.add('named');
          }
          else if (gearItem.rarity == 'Gearset') {
            dropdownSelectorText.classList.add('gearset');
          }

          dropdownSelectorType.innerHTML = "Talent: ";
          dropdownSelectorText.innerHTML = gearItem[attributeTypeName].name;
          gearslotTalentText.innerHTML = gearItem[attributeTypeName].value;
          gearslot.appendChild(gearslot.getElementsByClassName('gearslot--talent-text')[0]);

          break;
      }
    }
    // dropdown selector onclick
    if (attributeTypeNames[i] == 'mod' || !(gearItem.rarity == 'Exotic' || (gearItem.hasOwnProperty(attributeTypeName) && attributeTypeNames[i] !== 'core'))) {
      dropdownSelector.classList.add('cursor-pointer');
      dropdownSelectorSymbol.innerHTML = "&#9660";
      dropdownSelector.addEventListener('click', () => {
        hideOtherDropdowns(dropdownOptions);
        dropdownOptions.classList.toggle('hide');
        if (dropdownOptions.classList.contains('hide')) {
          dropdownSelectorSymbol.innerHTML = "&#9660"; //hidden
        }
        else {
          dropdownSelectorSymbol.innerHTML = "&#9661"; //shown
          dropdownOptions.scrollTop = 0;
        }
      })
    }
    /*} CLONE DROPDOWN SELECTOR  */
    //============================

    //============================
    /* CLONE DROPDOWN OPTIONS {*/
    let dbAttributeList;
    let attributeSource;
    switch (attributeTypeNames[i]) {
      case 'core':
      case 'minor':
        attributeSource = db['attribute'][equipmentTypeName][attributeTypeNames[i]];
        dbAttributeList = Object.keys(attributeSource);

        break;

      case 'mod':
      case 'talent':
        attributeSource = db[attributeTypeNames[i]];
        dbAttributeList = Object.keys(attributeSource);

        break;
    }

    const tplDropdownOptionParent = dropdownOptions;
    const tplDropdownOptionBase = document.getElementById('template--dropdown--option');

    // iterate over attributes

    for (let attributeName of dbAttributeList) {
      let clonedDropdownOptionNode = tplDropdownOptionBase.content.cloneNode(true);
      let dropdownOption = clonedDropdownOptionNode.getElementById('dropdown--option-');
      dropdownOption.id += `-${gearTypeName}--${attributeTypeName}--${attributeName}`;
      tplDropdownOptionParent.appendChild(clonedDropdownOptionNode);
      dropdownOption = document.getElementById(`${dropdownOption.id}`);

      let dropdownOptionName = dropdownOption.getElementsByClassName('dropdown--option--name')[0];

      let pngName = attributeSource[attributeName].png;

      let img = new Image();
      img.src = `./icons/${pngName}.png`;
      dropdownOptionName.appendChild(img);
      dropdownOptionName.innerHTML += " " + attributeName;

      let dropdownOptionValue = dropdownOption.getElementsByClassName('dropdown--option--value')[0];
      let optionValue = attributeSource[attributeName].value;
      dropdownOptionValue.innerHTML = optionValue;

      // dropdown option onclick
      dropdownOption.addEventListener('click', () => {
        dropdownSelectorText.innerHTML = dropdownOptionName.innerHTML;
        dropdownSelectorValue.innerHTML = dropdownOptionValue.innerHTML;
        dropdownSelectorSymbol.innerHTML = "&#9660";
        dropdownOptions.classList.add('hide');
      })

    }
    /*} CLONE DROPDOWN OPTIONS  */
    //============================
  }
  /*} GEARSLOT ATTRIBUTES  */
  //============================

  /*} CLONE GEAR SLOT  */
  //============================
}
/*} FUNCTIONS  */
//==============================

//let eventTarget = document.querySelectorAll(`[id*="${icons[i]}"]`);
