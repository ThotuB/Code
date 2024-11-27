import pygame
from pygame.locals import *
import random
from enum import Enum

def draw_text_to_scene(text, x, y, color, screen, font):
    text = font.render(text, True, color)

    centeredX = x - text.get_width() / 2
    centeredY = y - text.get_height() / 2

    screen.blit(text, (centeredX, centeredY))

class Game:
    def __init__(self, width, height, title):
        pygame.init()

        self.width = width
        self.height = height
        self.title = title

        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption(title)

        self.font = pygame.font.SysFont('Arial', 30)

class Cell:
    states = {
        0: 'CLOSED',
        1: 'OPEN',
        2: 'FLAGGED'
    }

    types = {
        -1: 'MINE',
        0: 'EMPTY',
        1: 'ONE',
        2: 'TWO',
        3: 'THREE',
        4: 'FOUR',
        5: 'FIVE',
        6: 'SIX',
        7: 'SEVEN',
        8: 'EIGHT'
    }

    def __init__(self):
        self.state = 1
        self.type = 0

    def set_mine(self):
        self.type = -1

    def is_mine(self):
        return self.type == -1

    def get_color_and_text(self):
        if self.state == 0:
            return (255, 255, 255), None
        elif self.state == 1:
            if self.type == -1:
                return (255, 0, 0), None
            else:
                return (255, 255, 255), str(self.type)

    def __iadd__(self, nr):
        self.type += nr
        if self.type > 8:
            self.type = 8
        return self

    def __str__(self):
        return str(self.type)

class Grid:
    def __init__(self, rows, cols, mines):
        self.cols = cols
        self.rows = rows

        self.grid = [[Cell() for _ in range(cols)] for _ in range(rows)]

        self.place_mines(mines)

    def update_neighbors(self, x, y):
        for i in range(x - 1, x + 2):
            for j in range(y - 1, y + 2):
                if i >= 0 and i < self.cols and j >= 0 and j < self.rows:
                    if not self.grid[j][i].is_mine():
                        self.grid[j][i] += 1
                        

    def place_mines(self, mines):
        while mines > 0:
            x = random.randint(0, self.cols - 1)
            y = random.randint(0, self.rows - 1)

            if self.grid[y][x].type != -1:
                self.grid[y][x].type = -1
                self.update_neighbors(x, y)

                mines -= 1

    def render_to_surface(self, width, height, font):
        surface = pygame.Surface((width, height))
        surface.fill((0, 0, 0))

        rectWidth = width / self.cols - 1
        rectHeight = height / self.rows - 1

        for y in range(self.rows):
            for x in range(self.cols):
                color, text = self.grid[y][x].get_color_and_text()

                pygame.draw.rect(surface, color, (x * (rectWidth + 1), y * (rectHeight + 1), rectWidth, rectHeight))
                if text:
                    draw_text_to_scene(text, x * (rectWidth + 1) + rectWidth / 2, y * (rectHeight + 1) + rectHeight / 2, (0, 0, 0), surface, font)

        return surface

    def __str__(self):
        result = ''
        for y in range(self.rows):
            for x in range(self.cols):
                result += str(self.grid[y][x])
            result += '\n'
        return result


class Minesweeper(Game):
    def __init__(self, rows, cols, mines):
        super().__init__(1200, 1200, 'Minesweeper')

        self.grid = Grid(rows, cols, mines)

    def play(self):
        self.clock = pygame.time.Clock()
        self.running = True
        self.score = 0

        while self.running:
            self.handle_events()
            self.draw()

        pygame.quit()

    def handle_keydown_events(self, key):
        if key == K_ESCAPE:
            self.running = False
        elif key == K_LEFT:
            print('left')
        elif key == K_RIGHT:
            print('right')
        elif key == K_UP:
            print('up')
        elif key == K_DOWN:
            print('down')
        elif key == K_SPACE:
            print('space')

    def handle_events(self):
        for event in pygame.event.get():
            if event.type == QUIT:
                self.running = False
            elif event.type == KEYDOWN:
                self.handle_keydown_events(event.key)  

    def draw_score(self):
        draw_text_to_scene(f'Score: {self.score}', self.width/2, 20, (255, 255, 255), self.screen, self.font)

    def draw_grid(self):
        surface = self.grid.render_to_surface(self.width, self.height - 100, self.font)
        self.screen.blit(surface, (0, 100))

    def draw(self):
        self.screen.fill((0, 0, 0))

        self.draw_score()
        self.draw_grid()

        pygame.display.flip()

        self.clock.tick(60)




if __name__ == '__main__':
    game = Minesweeper(10, 10, 10)

    game.play()
