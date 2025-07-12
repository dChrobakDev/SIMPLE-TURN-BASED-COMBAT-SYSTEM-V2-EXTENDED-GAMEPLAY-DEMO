# 🎯 SIMPLE TURN-BASED COMBAT SYSTEM V2 | EXTENDED GAMEPLAY DEMO

A more advanced **turn-based combat simulator** written in C++.  
This project expands the original demo with buffs, cooldowns, and additional logic.

---

## 📋 Description

The player can:
- Perform normal attacks (with a 20% chance for critical hits)
- Use a DMG buff (+15% attack bonus for next round, 5-round cooldown)
- Use a Defense buff (-15% enemy attack reduction next round, 4-round cooldown)
- Heal (+20 HP, 6-round cooldown)
- Dodge (avoid all incoming damage, 3-round cooldown)
- Skip rounds to observe enemy attacks.

The system features:
- Cooldown mechanics
- Conditional logic for buffs and crits
- Combat resolution and clear win/loss conditions

---

## 🧩 Features demonstrated:

✅ Turn-based combat logic  
✅ Player and enemy HP tracking  
✅ Critical hits and buff interactions  
✅ Cooldown management  
✅ Use of `max()` to prevent negative HP values  
✅ `switch-case` control flow for action handling  
✅ Random number generation (`rand()`, `srand()`)

---

## 🔧 How to run

1️⃣ Compile with a C++ compiler that supports C++11 or later (e.g., `g++` or Visual Studio).  
2️⃣ Run the executable and follow console prompts.

---

## 👤 Author

**Dawid Chrobak**  
Aspiring Game Developer  
[LinkedIn](https://www.linkedin.com/in/dawid-chrobak-9511a0373/) | [GitHub](https://github.com/dChrobakDev)

---

## 📝 Example output

```text
--- Round #1 ---

1. Attack		     4. DMG buff [15% CD 5]
2. Heal [20HP CD 6]	5. Defense buff [15% CD 4]
3. Dodge [CD 3]		  6. Skip round
CHOOSE ACTION
1
Normal attack [10 DMG]
Player HP [90]
Enemy HP [90]

...

[[ --- VICTORY! --- ]]
