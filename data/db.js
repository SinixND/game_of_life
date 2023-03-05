export const db = {
  'equipment': {
    'armor': {
      'mask': {
        'Vile': {
          rarity: "Exotic",
          type: "Exotic",
          'core': {
            name: "Skill Tier",
          },
          'minor 1': {
            name: "Status Effects",
          },
          'minor 2': {
            name: "Hazard Protection",
          },
          talent: {
            name: "Toxic Delivery",
            value: "Status effects also apply a damage over time debuff for 10s.\r\n Total damage dealt is equal to 50% of your concussion grenade damage and increased by your status effect attributes.",
          },
        },
        'Nightwatcher': {
          rarity: "Named",
          type: "Gila Guard",
          'minor': {
            name: "Scanner Pulse Haste",
            value: 100,
          },
        },
        'Aces & Eights': {
          rarity: "GearSet",
          type: "Aces & Eights",
        },
        '5.11 Tactical': {
          rarity: "HighEnd",
          type: "5.11 Tactical",
        },
      },
    },
  },
  'attributes': {
    armor: {
      'core': {
        'Weapon Damage': {
          png: "coreRed",
          value: 15,
        },
        'Armor': {
          png: "coreBlue",
          value: 170001,
        },
        'Skill Tier': {
          png: "coreYellow",
          value: 1,
        },
      },
      'minor': {
        "HighEnd": {
          'Critical Hit Chance': {
            png: "minorRed",
            value: 6,
          },
          'Critical Hit Damage': {
            png: "minorRed",
            value: 12,
          },
          'Headshot Damage': {
            png: "minorRed",
            value: 10,
          },
          'Weapon Handling': {
            png: "minorRed",
            value: 8,
          },
          'Armor Regeneration': {
            png: "minorBlue",
            value: 4925,
          },
          'Explosive Resistance': {
            png: "minorBlue",
            value: 10,
          },
          'Hazard Protection': {
            png: "minorBlue",
            value: 10,
          },
          'Health': {
            png: "minorBlue",
            value: 18935,
          },
          'Repair Skills': {
            png: "minorYellow",
            value: 20,
          },
          'Skill Damage': {
            png: "minorYellow",
            value: 10,
          },
          'Skill Haste': {
            png: "minorYellow",
            value: 12,
          },
          'Status Effects': {
            png: "minorYellow",
            value: 10,
          },
        },
        "Named": {
          'Scanner Pulse Haste': {
            png: "minorYellow",
            value: 100,
          }
        }
      },
      mod: {
        'Critical Hit Chance': {
          png: "modRed",
          value: 6,
        },
        'Critical Hit Damage': {
          png: "modRed",
          value: 12,
        },
        'Headshot Damage': {
          png: "modRed",
          value: 10,
        },
        'Armor on kill': {
          png: "modBlue",
          value: 18935,
        },
        'Bleed Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Blind/Deaf Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Burn Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Disorient Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Disrupt Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Ensnare Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Incomming Repairs': {
          png: "modBlue",
          value: 20,
        },
        'Pulse Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Protection from Elites': {
          png: "modBlue",
          value: 13,
        },
        'Shock Resistance': {
          png: "modBlue",
          value: 10,
        },
        'Repair Skills': {
          png: "modYellow",
          value: 20,
        },
        'Skill Duration': {
          png: "modYellow",
          value: 10,
        },
        'Skill Haste': {
          png: "modYellow",
          value: 12,
        },
      },
      talent: {
        'weapon': {
        },
        'backpack': {
        },
        'chest': {
        },
      },
    },
    sets: {
      GearSet: {
        "Marksman Rifle Damage": 15,
      },
      BrandSet: {

      },
    },

  },
  'setboni': {
    GearSet: {
      "Aces & Eights": {
        attribute1: {
          name: "Marksman Rifle Damage",
          requiredPieces: 2,
          value: 15,
        },
        attribute2: {
          name: "Headshot Damage",
          requiredPieces: 3,
          value: 30,
        },
        attribute3: {
          name: "Dead Man's Hand",
          requiredPieces: 4,
          value: "Flip a card when landing shots with a Marksman Rifle.<br> After 5 cards are flipped, the damage of your next shot is amplified by 30%. More shots are enhanced, the better the hand revealed.<br> <br> Four of a Kind: 4 shots.<br> Full House: 3 shots.<br> Aces and Eights: 2 shots.<br> <br> Flip an additional card on headshots."
        },
      },
    },
    BrandSet: {
      "Gila Guard": {
        attribute1: {
          name: "Total Armor",
          requiredPieces: 1,
          value: 5,
        },
        attribute2: {
          name: "Health",
          requiredPieces: 2,
          value: 10,
        },
        attribute3: {
          name: "Armor Regeneration",
          requiredPieces: 3,
          value: 1,
        },
      },
      "5.11 Tactical": {
        attribute1: {
          name: "Health",
          requiredPieces: 1,
          value: 10,
        },
        attribute2: {
          name: "Incoming Repairs",
          requiredPieces: 2,
          value: 20,
        },
        attribute3: {
          name: "Hazard Protection",
          requiredPieces: 3,
          value: 10,
        },
      },
    },
  },
  /*
  'weapons': {

  },
  'talents': {

  },
  'mods': {

  },
  */
}