/*
-------------------------------------------------
    SIMPLE TURN-BASED COMBAT SYSTEM V2 (EXTENDED)
    Author: Dawid Chrobak
    Language: C++
    Description:
        A more advanced version of a turn-based combat system.
        The player fights an enemy using:
        - Normal attacks (with a chance for critical hits)
        - DMG buff (temporary damage increase)
        - Defense buff (temporary damage reduction)
        - Heal (restores player HP)
        - Dodge (avoids next enemy attack)

        The program demonstrates:
        - Random number generation (rand, srand)
        - switch-case logic
        - Loops and conditionals
        - Cooldown mechanics
        - Basic combat gameplay logic
-------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {

    srand(time(0)); // Initialize random seed

    // Initialize player and enemy HP as float
    float enemyHP = 100.0f, playerHP = 100.0f;

    // Cooldown variables and buff tracking
    int dmgBuffUsedRound = -1;
    int dmgBuffCooldown = 0;
    int healCooldown = 0;
    int dodgeCooldown = 0;
    int defenseBuffUsedRound = -1;
    int defenseBuffCooldown = 0;

    // Loop for up to 20 rounds
    for (int round = 1; round <= 20; round++) {

        // Randomize attacks and critical hit chance
        int critChance = rand() % 100 + 1;
        int playerAttack = rand() % 6 + 9;
        int enemyAttack = rand() % 5 + 6;

        cout << "\n\n--- Round #" << round << " ---\n\n";

        cout << "1. Attack		4. DMG buff [15% CD 5]\n";
        cout << "2. Heal [20HP CD 6]	5. Defense buff [15% CD 4]\n";
        cout << "3. Dodge [CD 3]		6. Skip round\n";
        cout << "CHOOSE ACTION" << endl;

        int action;
        cin >> action;

        switch (action) {
        case 1:
            // Apply defense buff if active
            if (round == defenseBuffUsedRound + 1) {
                enemyAttack = enemyAttack / 1.15;
                cout << "Enemy attack reduced! Enemy deals [" << enemyAttack << " DMG]" << endl;
            }

            // Check for attack cases:
            if (critChance < 20 && round == dmgBuffUsedRound + 1 && playerAttack > 9) {
                // Critical hit + buff active
                playerAttack *= 1.65f;
                cout << "CRITICAL HIT WITH BUFF! [" << playerAttack << " DMG]" << endl;
            }
            else if (round == dmgBuffUsedRound + 1) {
                // Only buff active
                playerAttack *= 1.15f;
                cout << "ATTACK WITH BUFF [15%]! [" << playerAttack << " DMG]" << endl;
            }
            else if (critChance < 20) {
                // Only critical hit
                playerAttack *= 1.5f;
                cout << "CRITICAL HIT! [" << playerAttack << " DMG]" << endl;
            }
            else {
                // Normal attack
                cout << "Normal attack [" << playerAttack << " DMG]" << endl;
            }

            // Apply damage after attack
            enemyHP -= playerAttack;
            playerHP -= enemyAttack;
            break;

        case 2:
            // Heal action
            if (round == defenseBuffUsedRound + 1) {
                enemyAttack = enemyAttack / 1.15;
                cout << "Enemy attack reduced! Enemy deals [" << enemyAttack << " DMG]" << endl;
            }

            if (healCooldown > 0) {
                cout << "Heal on cooldown [" << healCooldown << "]" << endl;
            }
            else {
                cout << "Heal used! [HP + 20]" << endl;
                playerHP += 20;
                healCooldown = 6;
            }
            playerHP -= enemyAttack;
            break;

        case 3:
            // Dodge action
            if (round == defenseBuffUsedRound + 1) {
                enemyAttack = enemyAttack / 1.15;
                cout << "Enemy attack reduced! Enemy deals [" << enemyAttack << " DMG]" << endl;
            }

            if (dodgeCooldown > 0) {
                cout << "Dodge on cooldown [" << dodgeCooldown << "]" << endl;
                playerHP -= enemyAttack;
            }
            else {
                cout << "Dodge used! Enemy attack avoided." << endl;
                dodgeCooldown = 3;
            }
            break;

        case 4:
            // Damage buff activation
            if (round == defenseBuffUsedRound + 1) {
                enemyAttack = enemyAttack / 1.15;
                cout << "Enemy attack reduced! Enemy deals [" << enemyAttack << " DMG]" << endl;
            }

            if (dmgBuffCooldown > 0) {
                cout << "[DMG buff on cooldown: " << dmgBuffCooldown << "]" << endl;
            }
            else {
                cout << "[DMG buff used]" << endl;
                dmgBuffUsedRound = round;
                dmgBuffCooldown = 5;
            }
            playerHP -= enemyAttack;
            break;

        case 5:
            // Defense buff activation
            if (defenseBuffCooldown > 0) {
                cout << "Defense buff on cooldown [" << defenseBuffCooldown << "]" << endl;
            }
            else {
                cout << "[Defense buff used]" << endl;
                defenseBuffUsedRound = round;
                defenseBuffCooldown = 4;
            }
            playerHP -= enemyAttack;
            break;

        case 6:
            // Skip round
            cout << "Round skipped!" << endl;
            playerHP -= enemyAttack;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }

        // Ensure HP does not go below 0
        enemyHP = max(0.0f, enemyHP);
        playerHP = max(0.0f, playerHP);

        cout << "Player HP [" << playerHP << "]" << endl;
        cout << "Enemy HP [" << enemyHP << "]" << endl;

        // Check victory conditions after each round
        if (enemyHP == 0 && playerHP == 0) {
            cout << "[[ --- DRAW! --- ]]" << endl;
            cout << "[[ --- DRAW! --- ]]" << endl;
            cout << "[[ --- DRAW! --- ]]" << endl;
            break;
        }
        else if (enemyHP <= 0) {
            cout << "[[ --- VICTORY! --- ]]" << endl;
            cout << "[[ --- VICTORY! --- ]]" << endl;
            cout << "[[ --- VICTORY! --- ]]" << endl;
            break;
        }
        else if (playerHP <= 0) {
            cout << "[[ --- DEFEAT! --- ]]" << endl;
            cout << "[[ --- DEFEAT! --- ]]" << endl;
            cout << "[[ --- DEFEAT! --- ]]" << endl;
            break;
        }

        // Cooldown decrement for buffs and skills
        if (dmgBuffCooldown > 0) { dmgBuffCooldown--; }
        if (healCooldown > 0) { healCooldown--; }
        if (dodgeCooldown > 0) { dodgeCooldown--; }
        if (defenseBuffCooldown > 0) { defenseBuffCooldown--; }
    }

    return 0;
}
