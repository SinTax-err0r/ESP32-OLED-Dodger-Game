#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define UP_BUTTON 27
#define DOWN_BUTTON 33

int playerY = 30;
int obstacleX = 128;
int obstacleY = random(0, 60);
int obstacleSpeed = 3;
bool gameOver = false;
int score = 0;

void resetGame() {
  playerY = 30;
  obstacleX = 128;
  obstacleY = random(0, 60);
  score = 0;
  gameOver = false;
}

void setup() {
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(DOWN_BUTTON, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15, 28);
  display.println("Dodger Starting...");
  display.display();
  delay(1000);
}

void loop() {
  if (!gameOver) {
    // Move player
    if (digitalRead(UP_BUTTON) == LOW && playerY > 0)
      playerY -= 2;
    if (digitalRead(DOWN_BUTTON) == LOW && playerY < SCREEN_HEIGHT - 8)
      playerY += 2;

    // Move obstacle
    obstacleX -= obstacleSpeed;
    if (obstacleX < 0) {
      obstacleX = 128;
      obstacleY = random(0, SCREEN_HEIGHT - 8);
      score++;
      if (obstacleSpeed < 6) obstacleSpeed++; // Gradually harder
    }

    // Collision detection
    if (obstacleX < 12 && obstacleX + 6 > 5 &&
        playerY < obstacleY + 8 && playerY + 8 > obstacleY) {
      gameOver = true;
    }

    // Draw everything
    display.clearDisplay();
    display.fillRect(5, playerY, 6, 6, SSD1306_WHITE); // Player
    display.fillRect(obstacleX, obstacleY, 6, 6, SSD1306_WHITE); // Obstacle
    display.setCursor(0, 0);
    display.print("Score: ");
    display.print(score);
    display.display();
    delay(30);
  } else {
    // Game Over screen
    display.clearDisplay();
    display.setCursor(25, 20);
    display.setTextSize(1);
    display.println("Game Over!");
    display.setCursor(15, 35);
    display.print("Score: ");
    display.println(score);
    display.setCursor(5, 50);
    display.println("Press UP to restart");
    display.display();

    if (digitalRead(UP_BUTTON) == LOW) {
      delay(300);
      resetGame();
    }
  }
}
