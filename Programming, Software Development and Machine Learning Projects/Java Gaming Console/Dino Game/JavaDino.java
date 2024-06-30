package javapbl1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class JavaDino extends JFrame {

    private final int WIDTH = 800;
    private final int HEIGHT = 400;
    public static final long INITIAL_CACTUS_DELAY = 10000; // Initial delay before spawning the first cactus (milliseconds)
    public static final int MIN_CACTUS_DISTANCE = (int) (DinoPanel.JUMP_TIME * 0.75); // Minimum distance between two cacti (adjusted)

    public JavaDino() {
        setTitle("Java Dino");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        DinoPanel panel = new DinoPanel(INITIAL_CACTUS_DELAY, MIN_CACTUS_DISTANCE);
        add(panel);

        setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(JavaDino::new);
    }
}

class DinoPanel extends JPanel {

    private final int DINO_WIDTH = 100;
    private final int DINO_HEIGHT = 100;
    private final int GROUND_HEIGHT = 20;
    private static final int JUMP_HEIGHT = (int) (400 * 1.5); // Jump height of the dinosaur (adjusted)
    public static final int JUMP_SPEED = (int) (15 * 1.5); // Speed of the jump (adjusted)
    public static final long JUMP_TIME = (long) Math.sqrt(2 * JUMP_HEIGHT / 1.5); // Time taken for one jump (milliseconds)
    private Color skyColor = new Color(135, 206, 235); // Sky Blue color
    private Image dinoImage;
    private Image groundImage;
    private Image cloudImage;
    private Image cactusImage;
    private List<Cloud> clouds;
    List<Cactus> cacti;
    private long startTime;
    private int dinoY;
    private int jumpVelocity;
    private boolean isJumping;
    private long lastCactusSpawnTime;
    private long initialCactusDelay;
    private int minCactusDistance;

    public DinoPanel(long initialCactusDelay, int minCactusDistance) {
        this.initialCactusDelay = initialCactusDelay;
        this.minCactusDistance = minCactusDistance;

        // Load the dinosaur image from the "data" folder
        ImageIcon dinoIcon = new ImageIcon("data/dinosaur.png");
        dinoImage = dinoIcon.getImage();

        // Load the ground image from the "data" folder
        ImageIcon groundIcon = new ImageIcon("data/ground.png");
        groundImage = groundIcon.getImage();

        // Load the cloud image from the "data" folder and resize it
        ImageIcon cloudIcon = new ImageIcon("data/cloud.png");
        cloudImage = cloudIcon.getImage().getScaledInstance(80, 50, Image.SCALE_DEFAULT); // Larger size

        // Load the cactus image from the "data" folder and resize it
        ImageIcon cactusIcon = new ImageIcon("data/cactus.png");
        cactusImage = cactusIcon.getImage().getScaledInstance(60, 120, Image.SCALE_DEFAULT); // Adjust size as needed

        // Initialize clouds and cacti lists
        clouds = new ArrayList<>();
        cacti = new ArrayList<>();

        // Add some initial clouds
        clouds.add(new Cloud(100, 50));
        clouds.add(new Cloud(400, 100));
        clouds.add(new Cloud(600, 30));

        // Set the panel size
        setPreferredSize(new Dimension(800, 400));

        // Start tracking the game start time
        startTime = System.currentTimeMillis();

        // Initialize dinosaur position and jump state
        dinoY = getHeight() - GROUND_HEIGHT - DINO_HEIGHT;
        jumpVelocity = 0;
        isJumping = false;

        // Set up key listener for jumping
        setFocusable(true);
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_SPACE && !isJumping) {
                    isJumping = true;
                    jumpVelocity = JUMP_SPEED;
                }
            }
        });

        // Automatically jump the dino once at the start
        isJumping = true;
        jumpVelocity = JUMP_SPEED;

        // Start a thread to animate clouds and cacti
        new Thread(() -> {
            while (true) {
                if (isJumping) {
                    dinoY -= jumpVelocity;
                    jumpVelocity--;
                    if (dinoY >= getHeight() - GROUND_HEIGHT - DINO_HEIGHT) {
                        dinoY = getHeight() - GROUND_HEIGHT - DINO_HEIGHT;
                        isJumping = false;
                    }
                }

                for (Cloud cloud : clouds) {
                    cloud.move();
                }

                // Create a copy of the cacti list to avoid ConcurrentModificationException
                List<Cactus> cactiCopy = new ArrayList<>(cacti);
                for (Cactus cactus : cactiCopy) {
                    cactus.move();
                    // Check for collision with dinosaur
                    if (cactus.getX() <= 100 + DINO_WIDTH && cactus.getX() + 60 >= 100 &&
                            cactus.getY() + 120 >= dinoY && cactus.getY() <= dinoY + DINO_HEIGHT) {
                        // Collision detected, show game over dialog
                        long elapsedTimeMillis = System.currentTimeMillis() - startTime;
                        double elapsedTimeSec = elapsedTimeMillis / 1000.0; // Convert milliseconds to seconds
                        JOptionPane.showMessageDialog(null, "Game Over... Your Score is " + elapsedTimeSec + " seconds", "Game Over", JOptionPane.ERROR_MESSAGE);
                        System.exit(0);
                    }
                }
                spawnCactusIfNeeded();
                repaint();
                try {
                    Thread.sleep(40); // Adjust the speed of clouds and cacti
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        // Fill background with sky blue color
        g.setColor(skyColor);
        g.fillRect(0, 0, getWidth(), getHeight());
        // Draw clouds
        for (Cloud cloud : clouds) {
            g.drawImage(cloudImage, cloud.getX(), cloud.getY(), this);
        }
        // Draw cacti
        for (Cactus cactus : cacti) {
            g.drawImage(cactusImage, cactus.getX(), cactus.getY(), this);
        }
        // Draw the ground image
        g.drawImage(groundImage, 0, getHeight() - GROUND_HEIGHT, getWidth(), GROUND_HEIGHT, this);
        // Draw the dinosaur image
        g.drawImage(dinoImage, 100, dinoY, DINO_WIDTH, DINO_HEIGHT, this);
    }

    private void spawnCactusIfNeeded() {
        long currentTime = System.currentTimeMillis();
        if (currentTime - lastCactusSpawnTime > initialCactusDelay &&
                (cacti.isEmpty() || currentTime - cacti.get(cacti.size() - 1).getSpawnTime() > minCactusDistance)) {
            // Randomly spawn cactus on the right side of the screen
            int cactusY = getHeight() - GROUND_HEIGHT - 120; // Y position of cactus (on the ground)
            int cactusSpeed = -8; // Faster speed of the cactus (moving left)
            cacti.add(new Cactus(800, cactusY, cactusSpeed, this, currentTime));
            lastCactusSpawnTime = currentTime;
        }
    }
}

class Cloud {
    private int x;
    private int y;
    private int speed;

    public Cloud(int x, int y) {
        this.x = x;
        this.y = y;
        this.speed = -2; // Initial speed of the cloud (moving left)
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void move() {
        x += speed;
        // If the cloud goes off the screen, wrap it around
        if (x < -100) {
            x = 800;
            y = (int) (Math.random() * 150) + 20; // Randomize y position within the sky area
        }
    }
}

class Cactus {
    private int x;
    private int y;
    private int speed;
    private DinoPanel panel;
    private long spawnTime;

    public Cactus(int x, int y, int speed, DinoPanel panel, long spawnTime) {
        this.x = x;
        this.y = y;
        this.speed = speed; // Initial speed of the cactus
        this.panel = panel;
        this.spawnTime = spawnTime;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public long getSpawnTime() {
        return spawnTime;
    }

    public void move() {
        x += speed;
        // If the cactus goes off the screen, remove it from the list
        if (x < -50) {
            Iterator<Cactus> iterator = panel.cacti.iterator();
            while (iterator.hasNext()) {
                Cactus cactus = iterator.next();
                if (cactus == this) {
                    iterator.remove();
                    break;
                }
            }
        }
    }
}
