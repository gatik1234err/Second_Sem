const canvas = document.getElementById("gameCanvas");
const ctx = canvas.getContext("2d");
const scoreElement = document.getElementById("score");
const highScoreElement = document.getElementById("highScore");
const startBtn = document.getElementById("startBtn");
const restartBtn = document.getElementById("restartBtn");

// Game settings
const gridSize = 20;
const tileCount = canvas.width / gridSize;

// Game state
let snake = [];
let food = {};
let direction = { x: 1, y: 0 };
let nextDirection = { x: 1, y: 0 };
let score = 0;
let highScore = localStorage.getItem("snakeHighScore") || 0;
let gameLoop;
let isGameRunning = false;
let gameSpeed = 100;

// Initialize high score display
highScoreElement.textContent = highScore;

function initGame() {
  // Initialize snake in the middle
  snake = [
    { x: 10, y: 10 },
    { x: 9, y: 10 },
    { x: 8, y: 10 },
  ];

  direction = { x: 1, y: 0 };
  nextDirection = { x: 1, y: 0 };
  score = 0;
  scoreElement.textContent = score;

  spawnFood();
}

function spawnFood() {
  do {
    food = {
      x: Math.floor(Math.random() * tileCount),
      y: Math.floor(Math.random() * tileCount),
    };
  } while (
    snake.some((segment) => segment.x === food.x && segment.y === food.y)
  );
}

function update() {
  // Update direction from nextDirection
  direction = { ...nextDirection };

  // Calculate new head position
  const head = {
    x: snake[0].x + direction.x,
    y: snake[0].y + direction.y,
  };

  // Check wall collision
  if (head.x < 0 || head.x >= tileCount || head.y < 0 || head.y >= tileCount) {
    gameOver();
    return;
  }

  // Check self collision
  if (snake.some((segment) => segment.x === head.x && segment.y === head.y)) {
    gameOver();
    return;
  }

  // Add new head
  snake.unshift(head);

  // Check food collision
  if (head.x === food.x && head.y === food.y) {
    score += 10;
    scoreElement.textContent = score;
    spawnFood();

    // Increase speed slightly
    if (gameSpeed > 50) {
      gameSpeed -= 2;
      clearInterval(gameLoop);
      gameLoop = setInterval(gameStep, gameSpeed);
    }
  } else {
    // Remove tail if no food eaten
    snake.pop();
  }
}

function draw() {
  // Clear canvas
  ctx.fillStyle = "#f0f0f0";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  // Draw grid (optional, for visual effect)
  ctx.strokeStyle = "#e0e0e0";
  ctx.lineWidth = 0.5;
  for (let i = 0; i <= tileCount; i++) {
    ctx.beginPath();
    ctx.moveTo(i * gridSize, 0);
    ctx.lineTo(i * gridSize, canvas.height);
    ctx.stroke();

    ctx.beginPath();
    ctx.moveTo(0, i * gridSize);
    ctx.lineTo(canvas.width, i * gridSize);
    ctx.stroke();
  }

  // Draw food
  ctx.fillStyle = "#ff6b6b";
  ctx.shadowColor = "#ff6b6b";
  ctx.shadowBlur = 10;
  ctx.beginPath();
  ctx.arc(
    food.x * gridSize + gridSize / 2,
    food.y * gridSize + gridSize / 2,
    gridSize / 2 - 2,
    0,
    Math.PI * 2,
  );
  ctx.fill();
  ctx.shadowBlur = 0;

  // Draw snake
  snake.forEach((segment, index) => {
    // Gradient color for snake
    const greenValue = 200 - (index / snake.length) * 100;
    ctx.fillStyle = `rgb(50, ${greenValue}, 80)`;

    if (index === 0) {
      // Draw head slightly larger
      ctx.fillRect(
        segment.x * gridSize + 1,
        segment.y * gridSize + 1,
        gridSize - 2,
        gridSize - 2,
      );

      // Draw eyes
      ctx.fillStyle = "white";
      const eyeSize = 3;
      const eyeOffset = 5;

      if (direction.x === 1) {
        ctx.fillRect(
          segment.x * gridSize + gridSize - eyeOffset - eyeSize,
          segment.y * gridSize + eyeOffset,
          eyeSize,
          eyeSize,
        );
        ctx.fillRect(
          segment.x * gridSize + gridSize - eyeOffset - eyeSize,
          segment.y * gridSize + gridSize - eyeOffset - eyeSize,
          eyeSize,
          eyeSize,
        );
      } else if (direction.x === -1) {
        ctx.fillRect(
          segment.x * gridSize + eyeOffset,
          segment.y * gridSize + eyeOffset,
          eyeSize,
          eyeSize,
        );
        ctx.fillRect(
          segment.x * gridSize + eyeOffset,
          segment.y * gridSize + gridSize - eyeOffset - eyeSize,
          eyeSize,
          eyeSize,
        );
      } else if (direction.y === -1) {
        ctx.fillRect(
          segment.x * gridSize + eyeOffset,
          segment.y * gridSize + eyeOffset,
          eyeSize,
          eyeSize,
        );
        ctx.fillRect(
          segment.x * gridSize + gridSize - eyeOffset - eyeSize,
          segment.y * gridSize + eyeOffset,
          eyeSize,
          eyeSize,
        );
      } else {
        ctx.fillRect(
          segment.x * gridSize + eyeOffset,
          segment.y * gridSize + gridSize - eyeOffset - eyeSize,
          eyeSize,
          eyeSize,
        );
        ctx.fillRect(
          segment.x * gridSize + gridSize - eyeOffset - eyeSize,
          segment.y * gridSize + gridSize - eyeOffset - eyeSize,
          eyeSize,
          eyeSize,
        );
      }
    } else {
      ctx.fillRect(
        segment.x * gridSize + 1,
        segment.y * gridSize + 1,
        gridSize - 2,
        gridSize - 2,
      );
    }
  });
}

function gameStep() {
  update();
  draw();
}

function gameOver() {
  isGameRunning = false;
  clearInterval(gameLoop);

  // Update high score
  if (score > highScore) {
    highScore = score;
    localStorage.setItem("snakeHighScore", highScore);
    highScoreElement.textContent = highScore;
  }

  // Show restart button
  restartBtn.style.display = "inline-block";
  startBtn.style.display = "none";

  // Draw game over text
  ctx.fillStyle = "rgba(0, 0, 0, 0.7)";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  ctx.fillStyle = "white";
  ctx.font = "bold 40px Segoe UI";
  ctx.textAlign = "center";
  ctx.fillText("Game Over!", canvas.width / 2, canvas.height / 2 - 20);

  ctx.font = "20px Segoe UI";
  ctx.fillText(`Score: ${score}`, canvas.width / 2, canvas.height / 2 + 20);
}

function startGame() {
  if (isGameRunning) return;

  initGame();
  isGameRunning = true;
  gameSpeed = 100;
  gameLoop = setInterval(gameStep, gameSpeed);

  startBtn.style.display = "none";
  restartBtn.style.display = "inline-block";

  // Draw initial state
  draw();
}

function restartGame() {
  restartBtn.style.display = "none";
  startGame();
}

// Keyboard controls
document.addEventListener("keydown", (e) => {
  if (!isGameRunning) return;

  switch (e.key) {
    case "ArrowUp":
      if (direction.y !== 1) {
        nextDirection = { x: 0, y: -1 };
      }
      e.preventDefault();
      break;
    case "ArrowDown":
      if (direction.y !== -1) {
        nextDirection = { x: 0, y: 1 };
      }
      e.preventDefault();
      break;
    case "ArrowLeft":
      if (direction.x !== 1) {
        nextDirection = { x: -1, y: 0 };
      }
      e.preventDefault();
      break;
    case "ArrowRight":
      if (direction.x !== -1) {
        nextDirection = { x: 1, y: 0 };
      }
      e.preventDefault();
      break;
  }
});

// Button event listeners
startBtn.addEventListener("click", startGame);
restartBtn.addEventListener("click", restartGame);

// Initial draw
initGame();
draw();
