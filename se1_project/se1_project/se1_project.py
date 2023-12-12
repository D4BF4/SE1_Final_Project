import pygame
import sys, os
import math

pygame.init()

display = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
bullet_speed = 25

player_movement = [pygame.image.load("playerback.png"),
                pygame.image.load("playerfront.png"),
                pygame.image.load("playerright.png"),
                pygame.image.load("playerleft.png"),
                pygame.image.load("playernortheast.png"),
                pygame.image.load("playersoutheast.png"),
                pygame.image.load("playersouthwest.png"),
                pygame.image.load("playernorthwest.png")]

zombie_movement = [pygame.image.load("zombieback.png"),
                   pygame.image.load("zombiefront.png"),
                   pygame.image.load("zombieleft.png"),
                   pygame.image.load("zombieright.png")]

class Player:
    def __init__(self, x, y, width, height):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        #self.animation_count = 0
        
        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False

    def main(self, display):
        '''if self.animation_count + 1 >= 32:
            self.animation_count = 0

        self.animation_count += 1 '''

        if self.moving_right and self.moving_up:
            display.blit(player_movement[4], (self.x, self.y))
        elif self.moving_right and self.moving_down:
            display.blit(player_movement[5], (self.x, self.y))
        elif self.moving_left and self.moving_down:
            display.blit(player_movement[6], (self.x, self.y))
        elif self.moving_left and self.moving_up:
            display.blit(player_movement[7], (self.x, self.y))
        elif self.moving_right:
            display.blit(player_movement[2], (self.x, self.y))
        elif self.moving_left:
            display.blit(player_movement[3], (self.x, self.y))
        elif self.moving_up:
            display.blit(player_movement[0], (self.x, self.y))
        elif self.moving_down:
            display.blit(player_movement[1], (self.x, self.y))
        else:
            display.blit(player_movement[1], (self.x, self.y))

        self.moving_right = False
        self.moving_left = False
        self.moving_up = False
        self.moving_down = False
        #pygame.draw.rect(display, (0, 255, 0), (self.x, self.y, self.width, self.height))


class Zombie:
    def __init__(self, x, y):
        self.x = x
        self.y = y


class PlayerBullet:
    def __init__(self, x, y, mouse_x, mouse_y):
        self.x = x
        self.y = y
        self.mouse_x = mouse_x
        self.mouse_y = mouse_y

        self.speed = bullet_speed
        self.angle = math.atan2(y - mouse_y, x - mouse_x)
        self.x_velocity = math.cos(self.angle) * self.speed 
        self.y_velocity = math.sin(self.angle) * self.speed 

    def main(self, display):
        self.x -= int(self.x_velocity)
        self.y -= int(self.y_velocity)

        pygame.draw.circle(display, (0, 0, 0), (self.x, self.y), 5)

player = Player(400, 300, 32, 32)

display_scroll = [0, 0]

player_bullets = []

while True:
    display.fill((255, 0, 0))

    mouse_x, mouse_y = pygame.mouse.get_pos()

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                # Read out and print the sprite's position
                print("Player Sprite Position:", display_scroll[0], display_scroll[1])

        if event.type == pygame.MOUSEBUTTONDOWN:
            if event.button == 1:
                player_bullets.append(PlayerBullet(player.x, player.y, mouse_x, mouse_y))

    pygame.draw.rect(display, (255, 255, 255), (100 - display_scroll[0], 100 - display_scroll[1], 16, 16))

    keys = pygame.key.get_pressed()

    if keys[pygame.K_a] or keys[pygame.K_LEFT]:
        display_scroll[0] -= 5

        player.moving_left = True

        for bullet in player_bullets:
            bullet.x += 5

    if keys[pygame.K_d] or keys[pygame.K_RIGHT]:
        display_scroll[0] += 5

        player.moving_right = True

        for bullet in player_bullets:
            bullet.x -= 5

    if keys[pygame.K_w] or keys[pygame.K_UP]:
        display_scroll[1] -= 5

        player.moving_up = True

        for bullet in player_bullets:
            bullet.y += 5

    if keys[pygame.K_s] or keys[pygame.K_DOWN]:
        display_scroll[1] += 5

        player.moving_down = True

        for bullet in player_bullets:
            bullet.x -= 5


    player.main(display)

    for bullet in player_bullets:
        bullet.main(display)

    clock.tick(60)
    pygame.display.update()