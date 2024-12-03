import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.Random;
public class SnakeGame extends JFrame implements ActionListener, KeyListener {
    private int[] snakeX = new int[750];  // Tọa độ X của rắn
    private int[] snakeY = new int[750];  // Tọa độ Y của rắn
    private int lengthOfSnake = 2;  // Chiều dài ban đầu của rắn

    private boolean left = false;
    private boolean right = true;
    private boolean up = false;
    private boolean down = false;

    private Timer timer;
    private int delay = 100;  // Tốc độ di chuyển của rắn

    private Random random = new Random();
    private int foodX, foodY;

    public SnakeGame() {
        this.setTitle("Snake Game");
        this.setSize(900, 700);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.addKeyListener(this);
        this.setLocationRelativeTo(null);

        // Vị trí ngẫu nhiên của thức ăn
        foodX = random.nextInt(34) * 25;
        foodY = random.nextInt(23) * 25;

        timer = new Timer(delay, this);
        timer.start();
    }

    @Override
    public void paint(Graphics g) {
        g.setColor(Color.BLACK);
        g.fillRect(0, 0, 900, 700);

        // Vẽ thức ăn
        g.setColor(Color.RED);
        g.fillRect(foodX, foodY, 25, 25);

        // Vẽ rắn
        for (int i = 0; i < lengthOfSnake; i++) {
            if (i == 0) {
                g.setColor(Color.GREEN);  // Đầu rắn
            } else {
                g.setColor(Color.PINK);  // Thân rắn
            }
            g.fillRect(snakeX[i], snakeY[i], 25, 25);
        }

        g.dispose();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        // Di chuyển rắn
        for (int i = lengthOfSnake - 1; i > 0; i--) {
            snakeX[i] = snakeX[i - 1];
            snakeY[i] = snakeY[i - 1];
        }

        if (right) {
            snakeX[0] += 25;
        } else if (left) {
            snakeX[0] -= 25;
        } else if (up) {
            snakeY[0] -= 25;
        } else if (down) {
            snakeY[0] += 25;
        }

        // Kiểm tra va chạm với thức ăn
        if (snakeX[0] == foodX && snakeY[0] == foodY) {
            lengthOfSnake++;
            foodX = random.nextInt(34) * 25;
            foodY = random.nextInt(23) * 25;
        }

        // Kiểm tra va chạm tường
        if (snakeX[0] < 0 || snakeX[0] >= 900 || snakeY[0] < 0 || snakeY[0] >= 700) {
            timer.stop();
            JOptionPane.showMessageDialog(this, "Game Over!");
        }

        repaint();
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_RIGHT && !left) {
            right = true;
            left = false;
            up = false;
            down = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_LEFT && !right) {
            right = false;
            left = true;
            up = false;
            down = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_UP && !down) {
            right = false;
            left = false;
            up = true;
            down = false;
        }
        if (e.getKeyCode() == KeyEvent.VK_DOWN && !up) {
            right = false;
            left = false;
            up = false;
            down = true;
        }
    }

    @Override
    public void keyTyped(KeyEvent e) {}

    @Override
    public void keyReleased(KeyEvent e) {}

    public static void main(String[] args) {
        new SnakeGame().setVisible(true);
    }
}
