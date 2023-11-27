#include <iostream>

class Enemy {
private:
    int x;
    int y;
    int health;
    bool isDestroyed;

public:
    Enemy(int initialX, int initialY, int initialHealth) : x(initialX), y(initialY), health(initialHealth), isDestroyed(false) {}

    void moveUp() {
        if (!isDestroyed) {
            y++;
            std::cout << "Enemy moved up to position: (" << x << ", " << y << ")" << std::endl;
        }
    }

    void moveDown() {
        if (!isDestroyed) {
            y--;
            std::cout << "Enemy moved down to position: (" << x << ", " << y << ")" << std::endl;
        }
    }

    void moveLeft() {
        if (!isDestroyed) {
            x--;
            std::cout << "Enemy moved left to position: (" << x << ", " << y << ")" << std::endl;
        }
    }

    void moveRight() {
        if (!isDestroyed) {
            x++;
            std::cout << "Enemy moved right to position: (" << x << ", " << y << ")" << std::endl;
        }
    }

    void takeDamage(int damageTaken) {
        if (!isDestroyed) {
            health -= damageTaken;
            if (health <= 0) {
                destroy();
            } else {
                std::cout << "Enemy took " << damageTaken << " damage. Current health: " << health << std::endl;
            }
        }
    }

    void destroy() {
        std::cout << "Enemy has been destroyed!" << std::endl;
        isDestroyed = true;
        // Additional actions after enemy is destroyed
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    bool isAlive() const {
        return !isDestroyed;
    }

    int getHealth() const {
        return health;
    }
};

int main() {
    // Creating an enemy object at position (0, 0) with 50 health
    Enemy enemy(0, 0, 50);

    // Moving the enemy around
    enemy.moveUp();
    enemy.moveRight();
    enemy.moveDown();
    enemy.moveLeft();

    // Enemy takes damage and is destroyed
    enemy.takeDamage(60);

    // Retrieving the final position of the enemy
    std::cout << "Final position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << std::endl;

    return 0;
}
