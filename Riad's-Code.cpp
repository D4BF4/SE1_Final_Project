#include <iostream>

class Player {
private:
    int xPos;
    int yPos;
    int health;

public:
    // Constructor
    Player(int startX, int startY, int initialHealth) : xPos(startX), yPos(startY), health(initialHealth) {}

    // Getter for player position
    std::pair<int, int> providePosition() const {
        return std::make_pair(xPos, yPos);
    }

    // Method to handle player movement
    void moveDirection(int xDelta, int yDelta) {
        // Add logic to check boundaries or obstacles before moving
        xPos += xDelta;
        yPos += yDelta;

        // Add logic for updating the game state based on the new position
        // For example, check for collisions with enemies, pickups, etc.
    }

    // Method for shooting
    void shoot() {
        // Add logic for shooting, such as creating projectiles or affecting enemies
    }

    // Method to handle player taking damage
    void takeDamage(int damageAmount) {
        health -= damageAmount;

        // Add logic for checking if the player is defeated
        if (health <= 0) {
            // Player is defeated, handle accordingly (e.g., end the game)
        }
    }

    // Additional methods or features can be added based on your game requirements
};

int main() {
    // Example usage of the Player class
    Player player(0, 0, 100);  // Starting position (0, 0) with 100 health
    player.moveDirection(1, 1);  // Move the player
    player.shoot();  // Player shoots
    player.takeDamage(20);  // Player takes damage

    // Display player position
    std::pair<int, int> playerPosition = player.providePosition();
    std::cout << "Player Position: (" << playerPosition.first << ", " << playerPosition.second << ")\n";

    return 0;
}

