#include <iostream>
using namespace std;

class Enemy 
{
private:
    int x;
    int y;
    int health;
    bool isDestroyed;

public:
    // Constructor to initialize Enemy object
    Enemy(int initialX, int initialY, int initialHealth)
        : x(initialX), y(initialY), health(initialHealth), isDestroyed(false) {}

    // Movement functions for the Enemy object
    void moveUp() 
    {
        if (!isDestroyed) 
        {
            y++;
            cout << "Enemy moved up to position: (" << x << ", " << y << ")" << endl;
        }
    }

    void moveDown() 
    {
        if (!isDestroyed) 
        {
            y--;
            cout << "Enemy moved down to position: (" << x << ", " << y << ")" << endl;
        }
    }

    void moveLeft() 
    {
        if (!isDestroyed) 
        {
            x--;
            cout << "Enemy moved left to position: (" << x << ", " << y << ")" << endl;
        }
    }

    void moveRight() 
    {
        if (!isDestroyed) 
        {
            x++;
            cout << "Enemy moved right to position: (" << x << ", " << y << ")" << endl;
        }
    }

    // Function to simulate the enemy taking damage
    void takeDamage(int damageTaken) 
    {
        if (!isDestroyed) 
        {
            health -= damageTaken;
            if (health <= 0) 
            {
                destroy();
            } 
            else 
            {
                cout << "Enemy took " << damageTaken << " damage. Current health: " << health << endl;
            }
        }
    }

    // Function to destroy the enemy
    void destroy() 
    {
        cout << "Enemy has been destroyed!" << endl;
        isDestroyed = true;
        // Additional actions after enemy is destroyed can be added here
    }

    // Getter functions to access private member variables
    int getX() const 
    {
        return x;
    }

    int getY() const 
    {
        return y;
    }

    bool isAlive() const 
    {
        return !isDestroyed;
    }

    int getHealth() const
    {
        return health;
    }
};

int main() 
{
    // Creating an enemy object at position (0, 0) with 50 health
    Enemy enemy(0, 0, 50);

    // Moving the enemy around and displaying positions after each movement
    enemy.moveUp();
    cout << "Current position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << endl;

    enemy.moveRight();
    cout << "Current position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << endl;

    enemy.moveDown();
    cout << "Current position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << endl;

    enemy.moveLeft();
    cout << "Current position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << endl;

    // Inflict damage on the enemy
    enemy.takeDamage(60);

    // Checking if the enemy is still alive
    if (enemy.isAlive()) 
    {
        cout << "Enemy is still alive with " << enemy.getHealth() << " health." << endl;
    } 
    else 
    {
        cout << "Enemy has been destroyed!" << endl;
    }

    // Retrieving the final position of the enemy
    cout << "Final position of the enemy: (" << enemy.getX() << ", " << enemy.getY() << ")" << endl;

    return 0;
}
