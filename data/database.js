export const db = {
  equipment: {
    armor: {
      mask: {
        "Catharsis": {
          rarity: "Exotic",
          core: {
            name: "Armor",
          },
          minor1: {
            name: "Incoming Repairs",
            png: "minorBlue",
            value: 20,
          },
          minor2: {
            name: "Armor Regeneration",
          },
          talent: {
            name: "Vicious Cycle",
            value: "Taking damage builds stacks to a cap of 30. Each stack grants 1% Weapon Damage.\r\n Taking damage at max stacks triggers a purge, removing all stacks and Status Effects and then dropping a healing cloud which restores 5% of Max Armor for 10s to all allies in the cloud."
          }
        },
        "Coyote's Mask": {
          rarity: "Exotic",
          core: {
            name: "Weapon Damage",
          },
          minor1: {
            name: "Critical Hit Chance",
          },
          minor2: {
            name: "Critical Hit Damage",
          },
          talent: {
            name: "Pack Instincts",
            value: "You and all allies gain a bonus based on the distance of the last enemy you hit.\r\n \r\n 0 - 15m: \t+25% critical hit damage\r\n 15 - 25 m: \t+10% critical hit damage and +10% critical hit chance\r\n 25m+: \t+25% critical hit chance"
          }
        },
        "Vile": {
          rarity: "Exotic",
          type: "Exotic",
          core: {
            name: "Skill Tier",
          },
          minor1: {
            name: "Status Effects",
          },
          minor2: {
            name: "Hazard Protection",
          },
          talent: {
            name: "Toxic Delivery",
            value: "Status effects also apply a damage over time debuff for 10s.\r\n Total damage dealt is equal to 50% of your concussion grenade damage and increased by your status effect attributes.",
          },
        },
        "Nightwatcher": {
          rarity: "Named",
          type: "Gila Guard",
          minor1: {
            name: "Scanner Pulse Haste",
            png: "minorYellow",
            value: 100,
          },
        },
        "Chill Out": {
          rarity: "Named",
          type: "Gila Guard",
          mod2: {
          },
        },
        "Punch Drunk": {
          rarity: "Named",
          type: "Douglas & Harding",
          minor: "Headshot Damage",
        },
        "The Hollow Man": {
          rarity: "Named",
          type: "Yaahl Gear",
          minor1: {
            name: "Damage to Health",
          },
        },
        "Aces & Eights": {
          rarity: "Gearset",
          type: "Aces & Eights",
        },
        "Eclipse Protocol": {
          rarity: "Gearset",
          type: "Eclipse Protocol",
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
        },
        "Heartbreaker": {
          rarity: "Gearset",
          type: "Heartbreaker",
        },
        "Hotshot": {
          rarity: "Gearset",
          type: "Hotshot",
        },
        "Hunter's Fury": {
          rarity: "Gearset",
          type: "Hunter's Fury",
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
        },
        "Rigger": {
          rarity: "Gearset",
          type: "Rigger",
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Weapon Damage",
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
        },
        "Umbra Initiative": {
          rarity: "Gearset",
          type: "Umbra Initiative",
        },
        "5.11 Tactical": {
          rarity: "High End",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "High End",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "High End",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "High End",
          type: "Badger Tuff",
        },
        "Belstone Armory": {
          rarity: "High End",
          type: "Belstone Armory",
        },
        "Brazos de Arcabuz": {
          rarity: "High End",
          type: "Brazos de Arcabuz",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "High End",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "High End",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "High End",
          type: "Douglas & Harding",
        },
        "Empress International": {
          rarity: "High End",
          type: "Empress International",
        },
        "Fenris Group AB": {
          rarity: "High End",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "High End",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "High End",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "High End",
          type: "Grupo Sombra S.A.",
        },
        "Habsburg Guard": {
          rarity: "High End",
          type: "Habsburg Guard",
        },
        "Hana-U Corporation": {
          rarity: "High End",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "High End",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "High End",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "High End",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "High End",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "High End",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "High End",
          type: "Sokolov Concern",
        },
        "Uzina Getica": {
          rarity: "High End",
          type: "Uzina Getica",
        },
        "Walker, Harris & Co.": {
          rarity: "High End",
          type: "Walker, Harris & Co.",
        },
        "Wyvern Wear": {
          rarity: "High End",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "High End",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
      backpack: {
        "Acosta's Go-Bag": {
          rarity: "Exotic",
          type: "Exotic",
          core: {
            name: "Skill Tier",
          },
          minor1: {
            name: "Skill Haste",
          },
          minor2: {
            name: "Skill Damage",
          },
          talent: {
            name: "One in Hand...",
            value: "Throwing a grenade refunds it and grants +1 skill tier for 15s.\r\n Grants overcharge if already at skill tier 6. Cooldown: 60s\r\n \r\n Two in the Bag:\r\n \t+1 Armor Kit Capacity\r\n \t+3 Grenade Capacity\r\n \t+25% Ammo Capacity\r\n \t+10% Repair-skills\r\n \t+10% Status Effects"
          },
        },
        "Memento": {
          rarity: "Exotic",
          type: "Exotic",
          core: {
            name: "Weapon Damage",
            png: "coreRed",
            value: 15,
          },
          minor1: {
            name: "Armor",
            png: "coreBlue",
            value: 170001,
          },
          minor2: {
            name: "Skill Tier",
            png: "coreYellow",
            value: 1,
          },
          talent: {
            name: "Kill Confirmed",
            value: "Enemies you kill drop a trophy on death. Collecting trophies provides both a short and long-term buff, the first of which scales with the number of core attributes equipped and lasts 10 seconds.\r\n \r\n 5% weapon damage per red core,\r\n 10% bonus armor per blue core.\r\n 5% skill efficiency per yellow core.\r\n \r\n For every trophy collected, gain an additional +1% weapon damage, +1% skill efficiency, and +0.1% armor regeneration for 300s. Maximum 30 stacks."
          },
        },
        "NinjaBike Messenger Bag": {
          rarity: "Exotic",
          type: "Exotic",
          core: {
            name: "Weapon Damage",
            png: "coreRed",
            value: 15,
          },
          minor1: {
            name: "Armor",
            png: "coreBlue",
            value: 170001,
          },
          minor2: {
            name: "Skill Tier",
            png: "coreYellow",
            value: 1,
          },
          talent: {
            name: "Resourceful",
            value: "Slots in with any equipped Gear Set and/or Brand Set item to fulfill a requirement towards unlocking a Gear Sets bonus. Allows to unlock bonuses from multiple sets simultaneously."
          },
        },
        "Anarchist's Cookbook": {
          rarity: "Named",
          type: "Golan Gear Ltd",
          talent: {
            name: "Perfectly Wicked",
            value: "Applying a status effect increases total weapon damage by 18% for 27s.",
          }
        },
        "Battery Pack": {
          rarity: "Named",
          type: "Empress International",
          talent: {
            name: "Perfectly Calculated",
            value: "Kills from cover reduce skill cooldowns by 15%.",
          }
        },
        "Devil's Due": {
          rarity: "Named",
          type: "Ceska Vyroba s.r.o.",
          talent: {
            name: "Perfect Clutch",
            value: "If you are below 20% armor, critical hits repair 2.5% missing armor. Kills allow you to repair up to 100% armor for 4-10s, based on your number of offensive core attributes.",
          }
        },
        "Force Multiplier": {
          rarity: "Named",
          type: "Hana-U Corporation",
          talent: {
            name: "Perfect Combined Arms",
            value: "Shooting an enemy increases total skill damage by 30% for 3s."
          }
        },
        "Hermano": {
          rarity: "Named",
          type: "Brazos de Arcabuz",
          talent: {
            name: "Perfect Overclock",
            value: "Allies within 15m of your deployed skills, gain +30% reload speed and reduces their active cooldowns by 0.6s each second.",
          }
        },
        "Liquid Engineer": {
          rarity: "Named",
          type: "Belstone Armory",
          talent: {
            name: "Perfect Bloodsucker",
            value: "Killing an enemy adds and refreshes a stack of +12% bonus armor for 10s. Max stack is 10.",
          }
        },
        "Matador": {
          rarity: "Named",
          type: "Walker, Harris & Co.",
          talent: {
            name: "Perfect Adrenaline Rush",
            value: "Whenever you are within 10m of an enemy, gain 23% bonus armor for 5s. Stacks up to 3 times. Cooldown: 5s",
          }
        },
        "Percussive Maintenance": {
          rarity: "Named",
          type: "Alps Summit Armaments",
          talent: {
            name: "Perfect Tech Support",
            value: "Skill kills increase total skill damage by 25% for 27s.",
          }
        },
        "Strategic Alignment": {
          rarity: "Named",
          type: "China Light Industries Corporation",
          talent: {
            name: "Perfect Shock and Awe",
            value: "Applying a status effect to an enemy increases total skill damage and repair by 20% for 27s.",
          }
        },
        "The Courier": {
          rarity: "Named",
          type: "Habsburg Guard",
          talent: {
            name: "Perfect Creeping Death",
            value: "Causing Status Effect on an enemy has a chance to spread that same Status Effect to the nearest enemy within a 10-meter radius. Can only occur once every 10 seconds.",
          }
        },
        "The Gift": {
          rarity: "Named",
          type: "Providence Defense",
          talent: {
            name: "Perfect Vigilance",
            value: "Increases total weapon damage by 25%. Taking damage disables this buff for 3s.",
          }
        },
        "The Setup": {
          rarity: "Named",
          type: "Uzina Getica",
          talent: {
            name: "Perfect Opportunistic",
            value: "Enemies you hit with shotguns and marksman rifles amplifies the damage they take by 15% from all sources for 5s.",
          }
        },
        "Aces and Eights": {
          rarity: "Gearset",
          type: "Aces and Eights",
          talent: {
            name: "Poker Face",
          }
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
          talent: {
            name: "Short Circuit",
          }
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
          talent: {
            name: "Critical Measures",
          }
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
          talent: {
            name: "Emergency Requisition",
          }
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
          talent: {
            name: "Risk Management",
          }
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Armor",
          }
          talent: {
            name: "Multithreaded Execution",
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
          talent: {
            name: "Crossbow Expert",
          }
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
          talent: {
            name: "Patriotic Boost",
          }
        },
        "5.11 Tactical": {
          rarity: "HighEnd",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "HighEnd",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "HighEnd",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "HighEnd",
          type: "Badger Tuff",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "HighEnd",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "HighEnd",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "HighEnd",
          type: "Douglas & Harding",
        },
        "Fenris Group AB": {
          rarity: "HighEnd",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "HighEnd",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "HighEnd",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "HighEnd",
          type: "Grupo Sombra S.A.",
        },
        "Hana-U Corporation": {
          rarity: "HighEnd",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "HighEnd",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "HighEnd",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "HighEnd",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "HighEnd",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "HighEnd",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "HighEnd",
          type: "Sokolov Concern",
        },
        "Wyvern Wear": {
          rarity: "HighEnd",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "HighEnd",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
      chest: {
        "Tardigrade Armor System": {
          rarity: "Exotic",
          type: "Exotic",
          core: {
            name: "Armor",
          },
          minor1: {
            name: "Explosive Resistance",
          },
          minor2: {
            name: "Armor Regeneration",
          },
          talent: {
            name: "Ablative Nano-Plating",
          },
        },
        "Pristine Example": {
          rarity: "Named",
          type: "Airaldi Holdings",
          talent: {
            name: "Perfect Focus",
          }
        },
        "Zero F's": {
          rarity: "Named",
          type: "Badger Tuff",
          talent: {
            name: "Perfectly Unbreakable",
          }
        },
        "Ferocious Calm": {
          rarity: "Named",
          type: "Fenris Group AB",
          talent: {
            name: "Perfect Overwatch",
          }
        },
        "Pointman": {
          rarity: "Named",
          type: "Gila Guard",
          talent: {
            name: "Perfect Vanguard",
          }
        },
        "Hunter-Killer": {
          rarity: "Named",
          type: "Golan Gear Ltd",
          talent: {
            name: "Perfect Intimidate",
          }
        },
        "Door-Kicker's Knock": {
          rarity: "Named",
          type: "Grupo Sombra S.A.",
          talent: {
            name: "Perfect Spark",
          }
        },
        "Vedmedytsya Vest": {
          rarity: "Named",
          type: "Petrov Defense Group",
          talent: {
            name: "Perfect Braced",
          }
        },
        "The Sacrifice": {
          rarity: "Named",
          type: "Providence Defense",
          talent: {
            name: "Perfect Glass Cannon",
          }
        },
        "Aces and Eights": {
          rarity: "Gearset",
          type: "Aces and Eights",
          talent: {
            name: "No Limit",
          }
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
          talent: {
            name: "Positive Reinforcement",
          }
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
          talent: {
            name: "Target Rich Environment",
          }
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
          talent: {
            name: "Parabellum Rounds",
          }
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
          talent: {
            name: "Press the Advantage",
          }
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Weapon Damage",
          }
          talent: {
            name: "Compiler Optimization",
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
          talent: {
            name: "Specialized Destruction",
          }
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
          talent: {
            name: "Waving the Flag",
          }
        },
        "5.11 Tactical": {
          rarity: "HighEnd",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "HighEnd",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "HighEnd",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "HighEnd",
          type: "Badger Tuff",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "HighEnd",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "HighEnd",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "HighEnd",
          type: "Douglas & Harding",
        },
        "Fenris Group AB": {
          rarity: "HighEnd",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "HighEnd",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "HighEnd",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "HighEnd",
          type: "Grupo Sombra S.A.",
        },
        "Hana-U Corporation": {
          rarity: "HighEnd",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "HighEnd",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "HighEnd",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "HighEnd",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "HighEnd",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "HighEnd",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "HighEnd",
          type: "Sokolov Concern",
        },
        "Wyvern Wear": {
          rarity: "HighEnd",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "HighEnd",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
      gloves: {
        "Aces & Eights": {
          rarity: "Gearset",
          type: "Aces & Eights",
        },
        "Eclipse Protocol": {
          rarity: "Gearset",
          type: "Eclipse Protocol",
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
        },
        "Heartbreaker": {
          rarity: "Gearset",
          type: "Heartbreaker",
        },
        "Hotshot": {
          rarity: "Gearset",
          type: "Hotshot",
        },
        "Hunter's Fury": {
          rarity: "Gearset",
          type: "Hunter's Fury",
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
        },
        "Rigger": {
          rarity: "Gearset",
          type: "Rigger",
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Weapon Damage",
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
        },
        "Umbra Initiative": {
          rarity: "Gearset",
          type: "Umbra Initiative",
        },
        "5.11 Tactical": {
          rarity: "High End",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "High End",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "High End",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "High End",
          type: "Badger Tuff",
        },
        "Belstone Armory": {
          rarity: "High End",
          type: "Belstone Armory",
        },
        "Brazos de Arcabuz": {
          rarity: "High End",
          type: "Brazos de Arcabuz",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "High End",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "High End",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "High End",
          type: "Douglas & Harding",
        },
        "Empress International": {
          rarity: "High End",
          type: "Empress International",
        },
        "Fenris Group AB": {
          rarity: "High End",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "High End",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "High End",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "High End",
          type: "Grupo Sombra S.A.",
        },
        "Habsburg Guard": {
          rarity: "High End",
          type: "Habsburg Guard",
        },
        "Hana-U Corporation": {
          rarity: "High End",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "High End",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "High End",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "High End",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "High End",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "High End",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "High End",
          type: "Sokolov Concern",
        },
        "Uzina Getica": {
          rarity: "High End",
          type: "Uzina Getica",
        },
        "Walker, Harris & Co.": {
          rarity: "High End",
          type: "Walker, Harris & Co.",
        },
        "Wyvern Wear": {
          rarity: "High End",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "High End",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
      holster: {
        "Aces & Eights": {
          rarity: "Gearset",
          type: "Aces & Eights",
        },
        "Eclipse Protocol": {
          rarity: "Gearset",
          type: "Eclipse Protocol",
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
        },
        "Heartbreaker": {
          rarity: "Gearset",
          type: "Heartbreaker",
        },
        "Hotshot": {
          rarity: "Gearset",
          type: "Hotshot",
        },
        "Hunter's Fury": {
          rarity: "Gearset",
          type: "Hunter's Fury",
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
        },
        "Rigger": {
          rarity: "Gearset",
          type: "Rigger",
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Armor",
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
        },
        "Umbra Initiative": {
          rarity: "Gearset",
          type: "Umbra Initiative",
        },
        "5.11 Tactical": {
          rarity: "High End",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "High End",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "High End",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "High End",
          type: "Badger Tuff",
        },
        "Belstone Armory": {
          rarity: "High End",
          type: "Belstone Armory",
        },
        "Brazos de Arcabuz": {
          rarity: "High End",
          type: "Brazos de Arcabuz",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "High End",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "High End",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "High End",
          type: "Douglas & Harding",
        },
        "Empress International": {
          rarity: "High End",
          type: "Empress International",
        },
        "Fenris Group AB": {
          rarity: "High End",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "High End",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "High End",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "High End",
          type: "Grupo Sombra S.A.",
        },
        "Habsburg Guard": {
          rarity: "High End",
          type: "Habsburg Guard",
        },
        "Hana-U Corporation": {
          rarity: "High End",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "High End",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "High End",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "High End",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "High End",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "High End",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "High End",
          type: "Sokolov Concern",
        },
        "Uzina Getica": {
          rarity: "High End",
          type: "Uzina Getica",
        },
        "Walker, Harris & Co.": {
          rarity: "High End",
          type: "Walker, Harris & Co.",
        },
        "Wyvern Wear": {
          rarity: "High End",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "High End",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
      kneepads: {
        "Aces & Eights": {
          rarity: "Gearset",
          type: "Aces & Eights",
        },
        "Eclipse Protocol": {
          rarity: "Gearset",
          type: "Eclipse Protocol",
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
        },
        "Heartbreaker": {
          rarity: "Gearset",
          type: "Heartbreaker",
        },
        "Hotshot": {
          rarity: "Gearset",
          type: "Hotshot",
        },
        "Hunter's Fury": {
          rarity: "Gearset",
          type: "Hunter's Fury",
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
        },
        "Rigger": {
          rarity: "Gearset",
          type: "Rigger",
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Armor"
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
        },
        "Umbra Initiative": {
          rarity: "Gearset",
          type: "Umbra Initiative",
        },
        "5.11 Tactical": {
          rarity: "High End",
          type: "5.11 Tactical",
        },
        "Airaldi Holdings": {
          rarity: "High End",
          type: "Airaldi Holdings",
        },
        "Alps Summit Armaments": {
          rarity: "High End",
          type: "Alps Summit Armaments",
        },
        "Badger Tuff": {
          rarity: "High End",
          type: "Badger Tuff",
        },
        "Belstone Armory": {
          rarity: "High End",
          type: "Belstone Armory",
        },
        "Brazos de Arcabuz": {
          rarity: "High End",
          type: "Brazos de Arcabuz",
        },
        "Ceska Vyroba s.r.o.": {
          rarity: "High End",
          type: "Ceska Vyroba s.r.o.",
        },
        "China Light Industries Corporation": {
          rarity: "High End",
          type: "China Light Industries Corporation",
        },
        "Douglas & Harding": {
          rarity: "High End",
          type: "Douglas & Harding",
        },
        "Empress International": {
          rarity: "High End",
          type: "Empress International",
        },
        "Fenris Group AB": {
          rarity: "High End",
          type: "Fenris Group AB",
        },
        "Gila Guard": {
          rarity: "High End",
          type: "Gila Guard",
        },
        "Golan Gear Ltd": {
          rarity: "High End",
          type: "Golan Gear Ltd",
        },
        "Grupo Sombra S.A.": {
          rarity: "High End",
          type: "Grupo Sombra S.A.",
        },
        "Habsburg Guard": {
          rarity: "High End",
          type: "Habsburg Guard",
        },
        "Hana-U Corporation": {
          rarity: "High End",
          type: "Hana-U Corporation",
        },
        "Murakami Industries": {
          rarity: "High End",
          type: "Murakami Industries",
        },
        "Overlord Armaments": {
          rarity: "High End",
          type: "Overlord Armaments",
        },
        "Petrov Defense Group": {
          rarity: "High End",
          type: "Petrov Defense Group",
        },
        "Providence Defense": {
          rarity: "High End",
          type: "Providence Defense",
        },
        "Richter & Kaiser GmbH": {
          rarity: "High End",
          type: "Richter & Kaiser GmbH",
        },
        "Sokolov Concern": {
          rarity: "High End",
          type: "Sokolov Concern",
        },
        "Uzina Getica": {
          rarity: "High End",
          type: "Uzina Getica",
        },
        "Walker, Harris & Co.": {
          rarity: "High End",
          type: "Walker, Harris & Co.",
        },
        "Wyvern Wear": {
          rarity: "High End",
          type: "Wyvern Wear",
        },
        "Yaahl Gear": {
          rarity: "High End",
          type: "Yaahl Gear",
        },
        "Improvised (Crafted)": {
          rarity: "High End",
          type: "Improvised",
        },
      },
    },
  },
  attribute: {
    armor: {
      core: {
        "Weapon Damage": {
          png: "coreRed",
          value: 15,
        },
        "Armor": {
          png: "coreBlue",
          value: 170001,
        },
        "Skill Tier": {
          png: "coreYellow",
          value: 1,
        },
      },
      minor: {
        "Critical Hit Chance": {
          png: "minorRed",
          value: 6,
        },
        "Critical Hit Damage": {
          png: "minorRed",
          value: 12,
        },
        "Headshot Damage": {
          png: "minorRed",
          value: 10,
        },
        "Weapon Handling": {
          png: "minorRed",
          value: 8,
        },
        "Armor Regeneration": {
          png: "minorBlue",
          value: 4925,
        },
        "Explosive Resistance": {
          png: "minorBlue",
          value: 10,
        },
        "Hazard Protection": {
          png: "minorBlue",
          value: 10,
        },
        "Health": {
          png: "minorBlue",
          value: 18935,
        },
        "Repair Skills": {
          png: "minorYellow",
          value: 20,
        },
        "Skill Damage": {
          png: "minorYellow",
          value: 10,
        },
        "Skill Haste": {
          png: "minorYellow",
          value: 12,
        },
        "Status Effects": {
          png: "minorYellow",
          value: 10,
        },
      },
    },
  },
  mod: {
    "Critical Hit Chance": {
      png: "modRed",
      value: 6,
    },
    "Critical Hit Damage": {
      png: "modRed",
      value: 12,
    },
    "Headshot Damage": {
      png: "modRed",
      value: 10,
    },
    "Armor on kill": {
      png: "modBlue",
      value: 18935,
    },
    "Bleed Resistance": {
      png: "modBlue",
      value: 10,
    },
    'Blind/Deaf Resistance': {
      png: "modBlue",
      value: 10,
    },
    "Burn Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Disorient Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Disrupt Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Ensnare Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Incomming Repairs": {
      png: "modBlue",
      value: 20,
    },
    "Pulse Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Protection from Elites": {
      png: "modBlue",
      value: 13,
    },
    "Shock Resistance": {
      png: "modBlue",
      value: 10,
    },
    "Repair Skills": {
      png: "modYellow",
      value: 20,
    },
    "Skill Duration": {
      png: "modYellow",
      value: 10,
    },
    "Skill Haste": {
      png: "modYellow",
      value: 12,
    },
  },
  talent: {
    weapon: {
    },
    backpack: {
      "Bloodsucker": "Killing an enemy adds and refreshes a stack of +10% bonus armor for 10 seconds. Max stack is 10.",
      "Calculated": "Kills from cover reduce skill cooldowns by 10%.",
      "Clutch": "If you are below 15% armor, critical hits repair 3% missing armor. Kills allow you to repair up to 100% armor for 4-10 seconds.",
      "Combined Arms": "Shooting an enemy increases total skill damage by 25% for 3 seconds.",
      "Companion": "While you are within 5 meters of an ally or skill, total weapon damage is increased by 15%.",
      "Composure": "While in cover, increases total weapon damage by 15%.",
      "Concussion": "Headshots increase weapon damage by 10% for 1.5s. 5s for marksman rifles. Headshot kills increase weapon damage by 15% for 10s.",
      "Creeping Death": "When you apply a status effect, it is also applied to all enemies within 5 meters of your target. Cooldown is 20 seconds.",
      "Energize": "Using an armor kit grants +1 skill tier for 15 seconds. If already at skill tier 6, grants overcharge.",
      "Galvanize": "Applying a Blind, Ensnare, Confuse, or Shock to an enemy grants 40% bonus armor to you and all allies within 20M of the enemy for 10 seconds.",
      "Leadership": "Cover to covers grant 12% bonus armor to you & all allies for 10s. Doubled if ending within 10M of an enemy. Cooldown is 10 seconds.",
      "Opportunistic": "Enemies you hit with shotguns and marksman rifles amplifies the damage they take by 10% from all sources for 5 seconds.",
      "Overclock": "You and allies within 7 meters of your deployed skills, gain 25% reload speed and reduces active cooldowns by 0.2s each second.",
      "Protector": "When your shield is damaged, you gain 5% and all other allies gain 15% of your armor as bonus armor for 3 seconds. Cooldown is 3 seconds.",
      "Safeguard": "While at full armor, increases total skill repair by 100%.",
      "Shock and Awe": "Applying a status effect to an enemy increases total skill damage and repair by 20% for 20 seconds",
      "Tech Support": "Skill kills increase total skill damage by 25% for 20 seconds.",
      "Unstoppable Force": "Killing an enemy increases total weapon damage by 5% for 15 seconds. Stacks up to 5 times.",
      "Versatile": "Amplifies total weapon damage for 10 seconds when swapping between your primary and secondary weapons if they are different.",
      "Vigilance": "Increases total weapon damage by 25%. Taking damage disables this buff for 4 seconds.",
      "Wicked": "Applying a status effect increases total weapon damage by 18% for 20 seconds.",
    },
    chest: {
    },
  },
  setboni: {
    Gearset: {
      "Aces & Eights": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Marksman Rifle Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Headshot Damage",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Dead Man's Hand",
          requiredPieces: 4,
          value: "Flip a card when landing shots with a Marksman Rifle.<br> After 5 cards are flipped, the damage of your next shot is amplified by 30%. More shots are enhanced, the better the hand revealed.<br> <br> Four of a Kind: 4 shots.<br> Full House: 3 shots.<br> Aces and Eights: 2 shots.<br> <br> Flip an additional card on headshots."
        },
      },
      "Eclipse Protocol": {
        core: {
          name: "Skill Tier",
        },
        pcs2: {
          name: "Status Effects",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Skill Haste",
          requiredPieces: 3,
          value: 15,
        },
        pcs32: {
          name: "Hazard Protection",
          requiredPieces: 3,
          value: 30,
        }
        pcs4: {
          name: "Indirect Transmission",
          requiredPieces: 4,
          value: "Your Status Effects"
        },
      },
      "Foundry Bullwark": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Future Initiative": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Hard Wired": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Heartbreaker": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Hotshot": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Hunter's Fury": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Negotiator's Dilemma": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Ongoing Directive": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Rigger": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Striker's Battlegear": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "System Corruption": {
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Tip of the Spear": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "True Patriot": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
      "Umbra Initiative": {
        core: {
          name: "",
        },
        pcs2: {
          name: "",
          requiredPieces: 2,
          value: ,
        },
        pcs3: {
          name: "",
          requiredPieces: 3,
          value: ,
        },
        pcs4: {
          name: "",
          requiredPieces: 4,
          value: ""
        },
      },
    },
    Brandset: {
      "Gila Guard": {
        pcs1: {
          name: "Total Armor",
          requiredPieces: 1,
          value: 5,
        },
        pcs2: {
          name: "Health",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Armor Regeneration",
          requiredPieces: 3,
          value: 1,
        },
      },
      "5.11 Tactical": {
        pcs1: {
          name: "Health",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Incoming Repairs",
          requiredPieces: 2,
          value: 20,
        },
        pcs3: {
          name: "Hazard Protection",
          requiredPieces: 3,
          value: 10,
        },
      },
    },
  },
  /*
  weapons: {

  },
  */
}