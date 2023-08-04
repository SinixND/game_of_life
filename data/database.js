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
            value: "Taking damage builds stacks to a cap of 30. Each stack grants 1% Weapon Damage. <br> <br> Taking damage at max stacks triggers a purge, removing all stacks and Status Effects and then dropping a healing cloud which restores 5% of Max Armor for 10s to all allies in the cloud."
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
            value: "You and all allies gain a bonus based on the distance of the last enemy you hit. <br> <br> 0 - 15m: +25% critical hit damage <br> 15 - 25 m: +10% critical hit damage and +10% critical hit chance <br> 25m+: +25% critical hit chance"
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
            value: "Status effects also apply a damage over time debuff for 10s. <br> <br> Total damage dealt is equal to 50% of your concussion grenade damage and increased by your status effect attributes.",
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
            value: "Throwing a grenade refunds it and grants +1 skill tier for 15s. <br> <br> Grants overcharge if already at skill tier 6. Cooldown: 60s. <br> <br> Two in the Bag: <br> <br> +1 Armor Kit Capacity <br> +3 Grenade Capacity <br> +25% Ammo Capacity <br> +10% Repair-skills <br> +10% Status Effects"
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
            value: "Enemies you kill drop a trophy on death. Collecting trophies provides both a short and long-term buff, the first of which scales with the number of core attributes equipped and lasts 10 seconds. <br> <br> 5% weapon damage per red core, <br> 10% bonus armor per blue core. <br> 5% skill efficiency per yellow core. <br> <br> For every trophy collected, gain an additional +1% weapon damage, +1% skill efficiency, and +0.1% armor regeneration for 300s. Maximum 30 stacks."
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
        "Aces & Eights": {
          rarity: "Gearset",
          type: "Aces & Eights",
          talent: {
            name: "Poker Face",
            value: "Flip an additional Dead Man's Hand card on 1 shot.",
          }
        },
        "Eclipse Protocol": {
          rarity: "Gearset",
          type: "Eclipse Protocol",
          talent: {
            name: "Symptom Aggravator",
            value: "Amplifies all damage you deal to status effected targets by 30%.",
          }
        },
        "Foundry Bullwark": {
          rarity: "Gearset",
          type: "Foundry Bullwark",
          talent: {
            name: "Process Refinery",
            value: "Increases Makeshift Repairs speed from 15s to 10s.",
          }
        },
        "Future Initiative": {
          rarity: "Gearset",
          type: "Future Initiative",
          talent: {
            name: "Strategic Combat Support",
            value: "Increases Ground Control proximity repair from 60% to 120%.",
          }
        },
        "Hard Wired": {
          rarity: "Gearset",
          type: "Hard Wired",
          talent: {
            name: "Short Circuit",
            value: "Decreases Feedback Loop cooldown from 20s to 10s."
          }
        },
        "Heartbreaker": {
          rarity: "Gearset",
          type: "Heartbreaker",
          talent: {
            name: "Cold",
            value: "Increases total bonus armor gained per stack of Hearstopper from 1% to 2%."
          }
        },
        "Hotshot": {
          rarity: "Gearset",
          type: "Hotshot",
          talent: {
            name: "Blessed",
            value: "Agents can miss a headshot before resetting the cycle."
          }
        },
        "Hunter's Fury": {
          rarity: "Gearset",
          type: "Hunter's Fury",
          talent: {
            name: "Overwhelming Force",
            value: "Increases the radius of disorient on Apex Predator kills from 5m to 10m."
          }
        },
        "Negotiator's Dilemma": {
          rarity: "Gearset",
          type: "Negotiator's Dilemma",
          talent: {
            name: "Critical Measures",
            value: "Increases Hostile Negotiations damage to additional marked enemies from 60% to 100%."
          }
        },
        "Ongoing Directive": {
          rarity: "Gearset",
          type: "Ongoing Directive",
          talent: {
            name: "Emergency Requisition",
            value: "Increases the duration of your bleed status effects by 50% and all bleed damage done by 100%."
          }
        },
        "Rigger": {
          rarity: "Gearset",
          type: "Rigger",
          talent: {
            name: "Complete Uptime",
            value: "Cancelling your skills will reset their cooldown."
          }
        },
        "Striker's Battlegear": {
          rarity: "Gearset",
          type: "Striker's Battlegear",
          talent: {
            name: "Risk Management",
            value: "Increases total weapon damage gained per stack of Striker's Gamble from 0.65% to 1%"
          }
        },
        "System Corruption": {
          rarity: "Gearset",
          type: "System Corruption",
          core: {
            name: "Armor",
          },
          talent: {
            name: "Multithreaded Execution",
            value: "Increases Hackstep Protocol bonus armor from 50% to 100%."
          }
        },
        "Tip of the Spear": {
          rarity: "Gearset",
          type: "Tip of the Spear",
          talent: {
            name: "xxx",
            value: "xxx"
          }
        },
        "True Patriot": {
          rarity: "Gearset",
          type: "True Patriot",
          talent: {
            name: "Patriotic Boost",
            value: "Increases Red, White and Blue debuff strength. <br> Red: 8% to 12%. <br> White: 2% to 3%. <br> Blue: 8% to 12%."
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
          },
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
          value: "Flip a card when landing shots with a Marksman Rifle. <br> <br> After 5 cards are flipped, the damage of your next shot is amplified by 30%. <br> More shots are enhanced, the better the hand revealed. <br> <br> Four of a Kind: 4 shots <br> <br> Full House: 3 shots <br> <br> Aces and Eights: 2 shots <br> <br> Flip an additional card on headshots."
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
        },
        pcs4: {
          name: "Indirect Transmission",
          requiredPieces: 4,
          value: "Your status effects now spread on kill to all enemies within 10m and refresh 50% of the duration."
        },
      },
      "Foundry Bullwark": {
        core: {
          name: "Armor",
        },
        pcs2: {
          name: "Total Armor",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Armor Regeneration",
          requiredPieces: 3,
          value: 1,
        },
        pcs4: {
          name: "Makeshift Repairs",
          requiredPieces: 4,
          value: "Whenever you or your shield take damage, 20% of that amount is repaired to both over 15s."
        },
      },
      "Future Initiative": {
        core: {
          name: "Skill Tier",
        },
        pcs2: {
          name: "Repair Skills",
          requiredPieces: 2,
          value: 30,
        },
        pcs3: {
          name: "Skill Duration",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Ground Control",
          requiredPieces: 4,
          value: "Increases you and your allies' total weapon and skill damage by 15% when at full armor. <br> <br> When you repair an ally, you and all allies within 5m of you are also repaired for 60% of that amount."
        },
      },
      "Hard Wired": {
        core: {
          name: "Skill Tier",
        },
        pcs2: {
          name: "Skill Haste",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Skill Damage",
          requiredPieces: 3,
          value: 15,
        },
        pcs32: {
          name: "Repair Skills",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Feedback Loop",
          requiredPieces: 4,
          value: "Whenever you use or cancel a skill, your other skill's cooldown is automatically reduced by 30s while increasing total skill damage and repair by 10% for 20s. <br> <br> Feedback Loop can occur once every 20s."
        },
      },
      "Heartbreaker": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Assault Rifle Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs22: {
          name: "LMG Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Weapon Handling",
          requiredPieces: 3,
          value: 15,
        },
        pcs4: {
          name: "Heartstopper",
          requiredPieces: 4,
          value: "Headshots apply pulse for 5s. <br> <br> Weapon hits on pulsed enemies add a stack of +1% bonus armor and +1% damage to pulsed enemies, up to a max of 50 stacks. <br> <br> 2 stacks are lost each second."
        },
      },
      "Hotshot": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Marksman Rifle Damage",
          requiredPieces: 2,
          value: 30,
        },
        pcs22: {
          name: "Stability",
          requiredPieces: 2,
          value: 30,
        },
        pcs3: {
          name: "Headshot Damage",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Headache",
          requiredPieces: 4,
          value: "First Headshot with a Marksman Rifle will increase next headshot by 20%. <br> <br> Second consecutive headshot with a Marksman Rifle will give +10% armor (if at full armor it will give bonus armor max +50% of current armor value). <br> <br> Third consecutive headshot will refill magazine. <br> <br> From the fourth headshot forward, agents will get all 3 bonuses for each consecutive headshot kill. <br> <br> Missing a headshot will reset the cycle."
        },
      },
      "Hunter's Fury": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "SMG Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs22: {
          name: "Shotgun Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs32: {
          name: "Armor on Kill",
          requiredPieces: 3,
          value: 20,
        },
        pcs3: {
          name: "Health on Kill",
          requiredPieces: 3,
          value: 100,
        },
        pcs4: {
          name: "Apex Predator",
          requiredPieces: 4,
          value: "Enemies within 15m receive a debuff, amplifying your weapon damage against them by 20%. <br> <br> Killing a debuffed enemy with your weapon disorients other enemies within 5m, and amplifies weapon damage by 5% for 10s, stacking up to 5 times."
        },
      },
      "Negotiator's Dilemma": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Critical Hit Chance",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Critical Hit Damage",
          requiredPieces: 3,
          value: 20,
        },
        pcs4: {
          name: "Hostile Negotiations",
          requiredPieces: 4,
          value: "Critical hits mark enemies for 20s, up to 3 marks total. <br> <br> When you critically hit a marked enemy, all other marked enemies take 60% of the damage dealt. <br> <br> Whenever a marked enemy dies, gain +2% critical hit damage, stacking up to 20 times, until combat ends."
        },
      },
      "Ongoing Directive": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Status Effect",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Reload Speed",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Rules of Engagement",
          requiredPieces: 4,
          value: "Killing a marked enemy grants a full clip of Hollow-Point Ammo for your active weapon, and half a clip of the agent's active weapon to the rest of the party. <br> <br> Hollow-Point Ammo amplifies weapon damage by 20% and applies bleed on hit."
        },
      },
      "Rigger": {
        core: {
          name: "Skill Tier",
        },
        pcs2: {
          name: "Skill Haste",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Skill Duration",
          requiredPieces: 3,
          value: 15,
        },
        pcs4: {
          name: "Tend and Befriend",
          requiredPieces: 4,
          value: "Interacting with your deployed skills grants the skill 25% skill damage for 10s. <br> This buff cannot be refreshed. <br> <br> Interactions include: <br> - Using / Deploying the Skill <br> - Changing the skill's target <br> - Healing the skill"
        },
      },
      "Striker's Battlegear": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Weapon Handling",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Rate of Fire",
          requiredPieces: 3,
          value: 15,
        },
        pcs4: {
          name: "Striker's Gamble",
          requiredPieces: 4,
          value: "Weapon hits increase total weapon damage by 0.65%, stacking up to 100 times. <br> <br> 2 stacks are lost each second."
        },
      },
      "System Corruption": {
        pcs2: {
          name: "Armor on Kill",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Pulse Resistance",
          requiredPieces: 3,
          value: 40,
        },
        pcs32: {
          name: "Disrupt Resistance",
          requiredPieces: 3,
          value: 40,
        },
        pcs4: {
          name: "Hackstep Protocol",
          requiredPieces: 4,
          value: "Replaces armor kits with an instant, infinite-use ability on a 20s cooldown, that repairs 20% armor, grants 50% bonus armor and hides your nameplate for 5s. <br> <br> Increases total weapon damage by 1% per 5% bonus armor gained, up to 20%."
        },
      },
      "Tip of the Spear": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Signature Weapon Damage",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Weapon Damage",
          requiredPieces: 3,
          value: 10,
        },
        pcs4: {
          name: "Aggressive Recon",
          requiredPieces: 4,
          value: "Specialization weapon kills increase total weapon damage by 20% for 60s. <br> <br> Automatically generate specialization ammo every 60s."
        },
      },
      "True Patriot": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Ammo Capacity",
          requiredPieces: 2,
          value: 30,
        },
        pcs3: {
          name: "Magazine Size",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "Red, White and Blue",
          requiredPieces: 4,
          value: "Every 2s, enemies you shoot receive a stacking debuff of Red, White and Blue. <br> <br> Red: <br> Amplifies the enemy's damage taken by 8%. <br> <br> White: <br> Shooting the enemy repairs you and your allies' armor by 2% once every second. <br> <br> Blue: <br> Decreases the enemy's damage dealt by 8%. <br> <br> Full Flag: <br> Enemies that die while under the effect of all 3 debuffs create a 5m explosion, dealing damage equal to their total health and armor. <br> <br> (Explosion damage reduced on Named enemy deaths.)"
        },
      },
      "Umbra Initiative": {
        core: {
          name: "Weapon Damage",
        },
        pcs2: {
          name: "Critical Hit Chance",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Reload Speed",
          requiredPieces: 3,
          value: 30,
        },
        pcs4: {
          name: "From The Shadows / Into The Light",
          requiredPieces: 4,
          value: "From The Shadows: <br> <br> While in cover, gain 10 stacks per seconds up to 50. <br> Each stack gives 1% Critical Hit Damage increase and 0.3% RPM. <br> Buff only applies while out of cover. <br> While out of cover, you will lose 2 stacks per seconds at normal speed and 1 stack per second if sprinting. <br> <br> Into The Light: <br> <br> While out of cover and in combat, gain 10 stacks per seconds up to 50. <br> Each stack gives 0.8% Armor Regen when consumed. <br> Stacks are consumed at 10 stacks per second while in cover."
        },
      },
    },
    Brandset: {
      "5.11 Tactical": {
        core: {
          name: "Armor",
        },
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
      "Airaldi Holdings": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Marksman Rifle Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Headshot Damage",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Damage to Armor",
          requiredPieces: 3,
          value: 5,
        },
      },
      "Alps Summit Armaments": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Repair Skills",
          requiredPieces: 1,
          value: 15,
        },
        pcs2: {
          name: "Skill Duration",
          requiredPieces: 2,
          value: 20,
        },
        pcs3: {
          name: "Cooldown Reduction",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Badger Tuff": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Shotgun Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Armor",
          requiredPieces: 2,
          value: 5,
        },
        pcs3: {
          name: "Armor on Kill",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Belstone Armory": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Armor Regeneration",
          requiredPieces: 1,
          value: 1,
        },
        pcs2: {
          name: "Armor on Kill",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Incoming Repairs",
          requiredPieces: 3,
          value: 20,
        },
      },
      "Brazos de Arcabuz": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Skill Haste",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Skill Tier",
          requiredPieces: 2,
          value: 1,
        },
        pcs3: {
          name: "Magazine Size",
          requiredPieces: 3,
          value: 20,
        },
      },
      "Ceska Vyroba s.r.o.": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Critical Hit Chance",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Hazard Protection",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Health",
          requiredPieces: 3,
          value: 10,
        },
      },
      "China Light Industries Corporation": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Explosive Damage",
          requiredPieces: 1,
          value: 15,
        },
        pcs2: {
          name: "Cooldown Reduction",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Status Effects",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Douglas & Harding": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Pistol Damage",
          requiredPieces: 1,
          value: 20,
        },
        pcs2: {
          name: "Stability",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Accuracy",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Empress International": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Skill Health",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Skill Damage",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Skill Efficiency",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Fenris Group AB": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Assault Rifle Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Reload Speed",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Stability",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Gila Guard": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Armor",
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
      "Golan Gear Ltd": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Status Effects",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Armor Regeneration",
          requiredPieces: 2,
          value: 1,
        },
        pcs3: {
          name: "Armor",
          requiredPieces: 3,
          value: 5,
        },
      },
      "Grupo Sombra S.A.": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Critical Hit Damage",
          requiredPieces: 1,
          value: 15,
        },
        pcs2: {
          name: "Explosive Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Headshot Damage",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Habsburg Guard": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Headshot Damage 15",
          requiredPieces: 1,
          value: 15,
        },
        pcs2: {
          name: "Marksman Rifle Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Status Effects",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Hana-U Corporation": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Cooldown Reduction",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Skill Damage",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Weapon Damage",
          requiredPieces: 3,
          value: 5,
        },
      },
      "Murakami Industries": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Skill Duration",
          requiredPieces: 1,
          value: 20,
        },
        pcs2: {
          name: "Repair Skills",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Skill Damage",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Overlord Armaments": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Rifle Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Accuracy",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Weapon Handling",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Petrov Defense Group": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "LMG Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Weapon Handling",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Ammo Capacity",
          requiredPieces: 3,
          value: 20,
        },
      },
      "Providence Defense": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Headshot Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Critical Hit Chance",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Critical Hit Damage",
          requiredPieces: 3,
          value: 15,
        },
      },
      "Richter & Kaiser GmbH": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Incoming Repairs",
          requiredPieces: 1,
          value: 15,
        },
        pcs2: {
          name: "Explosive Resistance",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Skill Repair",
          requiredPieces: 3,
          value: 15,
        },
      },
      "Sokolov Concern": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "SMG Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Critical Hit Damage",
          requiredPieces: 2,
          value: 15,
        },
        pcs3: {
          name: "Critical Hit Chance",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Uzina Getica": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Armor",
          requiredPieces: 1,
          value: 5,
        },
        pcs2: {
          name: "Armor on Kill",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Hazard Protection",
          requiredPieces: 3,
          value: 10,
        },
      },
      "Walker, Harris & Co.": {
        core: {
          name: "Weapon Damage",
        },
        pcs1: {
          name: "Weapon Damage",
          requiredPieces: 1,
          value: 5,
        },
        pcs2: {
          name: "Damage to Armor",
          requiredPieces: 2,
          value: 5,
        },
        pcs3: {
          name: "Damage to Health",
          requiredPieces: 3,
          value: 5,
        },
      },
      "Wyvern Wear": {
        core: {
          name: "Skill Tier",
        },
        pcs1: {
          name: "Skill Damage",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Status Effects",
          requiredPieces: 2,
          value: 10,
        },
        pcs3: {
          name: "Skill Duration",
          requiredPieces: 3,
          value: 20,
        },
      },
      "Yaahl Gear": {
        core: {
          name: "Armor",
        },
        pcs1: {
          name: "Hazard Protection",
          requiredPieces: 1,
          value: 10,
        },
        pcs2: {
          name: "Weapon Damage",
          requiredPieces: 2,
          value: 5,
        },
        pcs3: {
          name: "Pulse Resistance",
          requiredPieces: 3,
          value: 40,
        },
      },
    },
    /*
    weapons: {

    },
    */
  }
}