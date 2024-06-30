package javapblmain;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;

public class JavaMain {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Gaming Console");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(400, 200);
            frame.setLayout(new BorderLayout());

            JLabel welcomeLabel = new JLabel("Welcome to Gaming Console... Choose your game");
            welcomeLabel.setHorizontalAlignment(JLabel.CENTER);
            frame.add(welcomeLabel, BorderLayout.NORTH);

            JPanel buttonPanel = new JPanel();
            buttonPanel.setLayout(new FlowLayout());

            JButton game1Button = new JButton("Dino Game");
            JButton game2Button = new JButton("Snake and Ladder");

            game1Button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    frame.dispose();
                    runJar("Dino Game/GameDino.jar");
                }
            });

            game2Button.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    frame.dispose();
                    runJar("Snake and Ladder/GameSNL.jar");
                }
            });

            buttonPanel.add(game1Button);
            buttonPanel.add(game2Button);

            frame.add(buttonPanel, BorderLayout.CENTER);

            frame.setVisible(true);
        });
    }

    private static void runJar(String jarFilePath) {
        try {
            File jarFile = new File(jarFilePath);
            if (!jarFile.exists()) {
                System.out.println("Jar file not found!");
                return;
            }

            String jarDir = jarFile.getParent();
            ProcessBuilder builder = new ProcessBuilder("java", "-jar", jarFile.getAbsolutePath());
            builder.directory(new File(jarDir)); // Set the working directory
            builder.redirectErrorStream(true);
            builder.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

