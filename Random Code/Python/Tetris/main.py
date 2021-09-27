import pygame
from pygame.locals import *


class Game:
    def __init__(self, width, height, title):
        pygame.init()

        self.width = width
        self.height = height
        self.title = title

        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption(title)

        self.font = pygame.font.SysFont('Arial', 30)


class Grid:
    def __init__(self, rows, cols):
        self.cols = cols
        self.rows = rows

        self.grid = [[0] * cols for _ in range(rows)]

    def render_to_surface(self, width, height):
        surface = pygame.Surface((width, height))
        surface.fill((0, 0, 0))

        rectWidth = width / self.cols - 1
        rectHeight = height / self.rows - 1

        for y in range(self.rows):
            for x in range(self.cols):
                if self.grid[y][x] == 1:
                    color = (200, 200, 200)
                else:
                    color = (255, 255, 255)
                pygame.draw.rect(surface, color, (x * (rectWidth + 1), y * (rectHeight + 1), rectWidth, rectHeight))

        return surface


class Tetris(Game):
    def __init__(self, width, height):
        super().__init__(width, height, 'Tetris')

        self.grid = Grid(22, 10)
        self.grid.grid[3][3] = 1

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

    def draw_text(self, text, x, y, color):
        text = self.font.render(text, True, color)

        centeredX = x - text.get_width() / 2
        centeredY = y - text.get_height() / 2

        self.screen.blit(text, (centeredX, centeredY))

    def draw_score(self):
        self.draw_text(f'Score: {self.score}',
                       self.width/2, 20, (255, 255, 255))

    def draw_grid(self):
        surface = self.grid.render_to_surface(self.width, self.height - 100)
        self.screen.blit(surface, (0, 100))

    def draw(self):
        self.screen.fill((0, 0, 0))

        self.draw_score()
        self.draw_grid()

        pygame.display.flip()

        self.clock.tick(60)




if __name__ == '__main__':
    tetris = Tetris(500, 1000)

    tetris.play()
