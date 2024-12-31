const canvas = document.getElementById("fireworksCanvas");
const ctx = canvas.getContext("2d");

canvas.width = window.innerWidth;
canvas.height = window.innerHeight;

const isMobile = /iPhone|iPad|iPod|Android/i.test(navigator.userAgent);
if (isMobile) {
    canvas.style.width = '100%';
    canvas.style.height = '100vh';
}

// Khởi tạo mảng chứa các âm thanh
const launchSounds = [
  document.getElementById('launch1'),
  document.getElementById('launch2'),
  document.getElementById('launch3'),
  document.getElementById('launch4'),
  document.getElementById('launch5')
];

// Hàm lấy âm thanh ngẫu nhiên
function getRandomSound() {
  return launchSounds[Math.floor(Math.random() * launchSounds.length)];
}

// Hàm phát âm thanh
function playSound(audio) {
  const sound = audio.cloneNode();
  sound.volume = 0.3;
  sound.play();
}

// Phát âm thanh ban đầu khi trang web tải xong
function playInitialFireworks() {
  setTimeout(() => playSound(getRandomSound()), 0);
  setTimeout(() => playSound(getRandomSound()), 200);
  setTimeout(() => playSound(getRandomSound()), 400);
}

// Sự kiện click chuột sẽ phát âm thanh
document.addEventListener('click', () => {
  playSound(getRandomSound());
});

function resizeCanvas() {
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
}

window.addEventListener("resize", resizeCanvas, false);

class Firework {
  constructor() {
    this.x = Math.random() * canvas.width;
    this.y = canvas.height;
    this.sx = Math.random() * 3 - 1.5;
    this.sy = Math.random() * -3 - 3;
    this.size = Math.random() * 2 + 1;
    this.shouldExplode = false;
    this.particleCount = isMobile ? 30 : 50;

    const colorVal = Math.round(0xffffff * Math.random());
    const r = colorVal >> 16;
    const g = (colorVal >> 8) & 255;
    const b = colorVal & 255;
    this.r = r;
    this.g = g;
    this.b = b;
  }

  update() {
    if (
        this.sy >= -2 ||
        this.y <= 100 ||
        this.x <= 0 ||
        this.x >= canvas.width
    ) {
      this.shouldExplode = true;
    } else {
      this.sy += 0.01;
    }
    this.x += this.sx;
    this.y += this.sy;
  }

  draw() {
    ctx.fillStyle = `rgb(${this.r},${this.g},${this.b})`;
    ctx.beginPath();
    ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
    ctx.fill();
  }
}

class Particle {
  constructor(x, y, r, g, b) {
    this.x = x;
    this.y = y;
    this.sx = Math.random() * 3 - 1.5;
    this.sy = Math.random() * 3 - 1.5;
    this.size = Math.random() * 2 + 1;
    this.life = 100;
    this.r = r;
    this.g = g;
    this.b = b;
  }

  update() {
    this.x += this.sx;
    this.y += this.sy;
    this.life -= 1;
  }

  draw() {
    ctx.fillStyle = `rgba(${this.r}, ${this.g}, ${this.b}, ${this.life / 100})`;
    ctx.beginPath();
    ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
    ctx.fill();
  }
}

const fireworks = [new Firework()];
const particles = [];

function animate() {
  ctx.fillStyle = "rgba(0, 0, 0, 0.2)";
  ctx.fillRect(0, 0, canvas.width, canvas.height);

  if (Math.random() < (isMobile ? 0.03 : 0.05)) {
    fireworks.push(new Firework());
  }

  for (let i = fireworks.length - 1; i >= 0; i--) {
    fireworks[i].update();
    fireworks[i].draw();

    if (fireworks[i].shouldExplode) {
      for (let j = 0; j < 50; j++) {
        particles.push(
            new Particle(
                fireworks[i].x,
                fireworks[i].y,
                fireworks[i].r,
                fireworks[i].g,
                fireworks[i].b
            )
        );
      }
      fireworks.splice(i, 1);
    }
  }

  for (let i = particles.length - 1; i >= 0; i--) {
    particles[i].update();
    particles[i].draw();

    if (particles[i].life <= 0) {
      particles.splice(i, 1);
    }
  }
  requestAnimationFrame(animate);
}

animate();

class TextDisplay {
  constructor() {
    this.lines = [
      "Chúc em năm mớiiiii 2025 zui zẻ mạnh khỏe và nuôn xinh đẹp,",
      "trưởng thành hơn, yêu a hơn và cute hơn nữa.",
      "Cảm ơn đã bên cạnh anh 3 năm pháo hoa nổ nhaaa!!!"
    ];
    this.colors = [
      '#fff5b3', // light yellow-white
      '#b3e0ff', // light blue-white
      '#ffb3b3'  // light red-white
    ];
    this.container = document.getElementById('textContainer');
    
    if (isMobile) {
      this.container.style.fontSize = '0.9em';
      this.container.style.padding = '10px';
      this.container.style.width = '90%';
      this.container.style.left = '50%';
      this.container.style.transform = 'translateX(-50%)';
      this.container.style.textAlign = 'center';
      this.container.style.bottom = '30%';
    }
  }

  display() {
    this.lines.forEach((line, lineIndex) => {
      const lineDiv = document.createElement('div');
      lineDiv.className = 'text-line';

      [...line].forEach((char, charIndex) => {
        const span = document.createElement('span');
        span.textContent = char;
        span.className = 'text';
        span.style.color = this.colors[lineIndex];
        span.style.animationDelay = `${charIndex * 0.1}s`;
        lineDiv.appendChild(span);
      });

      this.container.appendChild(lineDiv);
    });
  }
}

const textDisplay = new TextDisplay();
textDisplay.display();

function showRandomWish() {
  const wishText = document.getElementById('wishText');
  const randomWish = wishes[Math.floor(Math.random() * wishes.length)];
  wishText.textContent = randomWish;
  wishText.style.display = 'block';

  // Fireworks
  for (let i = 0; i < 5; i++) {
    setTimeout(() => {
      fireworks.push(new Firework());
      playSound(getRandomSound());
    }, i * 200);
  }

  // Hide the wish text after 3 seconds
  setTimeout(() => {
    wishText.style.display = 'none';
  }, 3000);
}

// Show the first wish after 2 seconds when the page loads
setTimeout(() => {
  showRandomWish();
  setInterval(showRandomWish, 5000);
}, 2000);

// Click to hide the wish text
document.getElementById('wishText').addEventListener('click', function() {
  this.style.display = 'none';
});
