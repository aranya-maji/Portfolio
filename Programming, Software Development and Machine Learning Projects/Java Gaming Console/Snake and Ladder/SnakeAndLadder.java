package javapbl2;

import java.util.*;
import java.awt.event.*;
import javax.swing.*;

class JavaSNL implements ActionListener
{
	
	//onStartComponents
	JDialog enterNameDialog;
	JLabel enterNameLabel;
	JLabel namePlayerFirst,namePlayerSecond;
	JTextField firstPlayerName, secondPlayerName;
	JLabel imgFirstPlayerLabel, imgSecondPlayerLabel;
	JButton startGame;
		
	
	//startGameComponents
	JFrame mainFrame;
	JLabel b[];
	JLabel winLabel,winImage;
	JLabel turnLabel;
	JLabel firstPlayer,secondPlayer;
	
	//DefiningImageTiles
	String imgPath[];	
	ImageIcon imgIcon[];
	JButton diceButton;
	
	int x1=220,x2=760,x3=220,x4=760,x5=220,x6=760,x7=220,x8=760,x9=220,x10=760;
	int y=550;
	int w=60;
	int h=60;
	
	
	int randomNumber()
	{
		Random r = new Random();
		int min = 1;
		int max = 7;
		int randomNum = r.nextInt(max-min)+min;
		
		return randomNum;
	}
	
	
	JavaSNL()
	{
		onStart();
	}
	
	void onStart()
	{
		//DialogBox
		enterNameDialog = new JDialog(mainFrame,"Snake & Ladder : Players",true);
		enterNameDialog.setSize(500,500);
		enterNameDialog.setLayout(null);
		
		
		//EnterNameLabel
		enterNameLabel = new JLabel("Enter Player Name");
		enterNameLabel.setFont(new java.awt.Font("Times New Roman", 2, 40));
		enterNameLabel.setBounds(80,50,450,50);
		enterNameDialog.add(enterNameLabel);
		
		//FirstPlayerName
		namePlayerFirst =new JLabel("First:");
		namePlayerFirst.setFont(new java.awt.Font("Times New Roman", 2, 18));
		namePlayerFirst.setBounds(50,150,70,18);
		enterNameDialog.add(namePlayerFirst);
		
		firstPlayerName = new JTextField(null);
		firstPlayerName.setBounds(160,145,150,30);
		firstPlayerName.setText("");
		enterNameDialog.add(firstPlayerName);
		
		//SecondPlayerName
		namePlayerSecond =new JLabel("Second:");
		namePlayerSecond.setFont(new java.awt.Font("Times New Roman", 2, 18));
		namePlayerSecond.setBounds(50,250,70,18);
		enterNameDialog.add(namePlayerSecond);
		
		secondPlayerName = new JTextField(null);
		secondPlayerName.setBounds(160,245,150,30);
		secondPlayerName.setText("");
		enterNameDialog.add(secondPlayerName);
		
		//ImageFirstPlayerLabel
		imgFirstPlayerLabel = new JLabel();
		imgFirstPlayerLabel.setBounds(360,125,70,70);
		imgFirstPlayerLabel.setBorder(null);
		imgFirstPlayerLabel.setIcon(new ImageIcon("player_images/p1.png"));
		enterNameDialog.add(imgFirstPlayerLabel);
		
		//ImageSecondPlayerLabel
		imgSecondPlayerLabel = new JLabel();
		imgSecondPlayerLabel.setBounds(360,225,70,70);
		imgSecondPlayerLabel.setBorder(null);
		imgSecondPlayerLabel.setIcon(new ImageIcon("player_images/p2.png"));
		enterNameDialog.add(imgSecondPlayerLabel);
		
		//StartGameButton
		startGame = new JButton("Start Game");
		startGame.setBounds(185,320,100,30);
		enterNameDialog.add(startGame);
		
		startGame.addActionListener(this);
		enterNameDialog.setVisible(true);
	}
	
	void startGame()
	{
		mainFrame = new JFrame("Snake & Ladder : By Aranya & Gargi");
		
		//DefiningImageLabels
		b = new JLabel[101];
		for(int i = 0; i < b.length; i++)
		{
			b[i] = new JLabel();
		}
		
		//CreatingImageTiles
		imgPath = new String[100];
		for(int i=0;i<imgPath.length;i++)
		{
			imgPath[i] = "images/img_"+(i+1)+".jpeg";
		}
		
		//DefiningImageIcons
		imgIcon = new ImageIcon[100];
		for(int i = 0; i<imgIcon.length;i++)
		{
			imgIcon[i] = new ImageIcon(imgPath[i]);
			b[i].setIcon(imgIcon[i]);
		}
		
		//WinnerLabel
		winLabel = new JLabel();
		winLabel.setBounds(100,10,60,60);
		winLabel.setIcon(new ImageIcon("player_images/winner.jpeg"));
		mainFrame.add(winLabel);
		
		
		
		//Defining_Layout
		for(int i=0;i<b.length;i++)
		{
			if(i<10)
			{
				b[i].setBounds(x1,y,w,h);
				x1+=w;
			}
			else if(i<20)
			{
				y=490;
				b[i].setBounds(x2,y,w,h);
				x2-=w;
			}
			else if(i<30)
			{
				y=430;
				b[i].setBounds(x3,y,w,h);
				x3+=w;
			}
			else if(i<40)
			{
				y=370;
				b[i].setBounds(x4,y,w,h);
				x4-=w;
			}
			else if(i<50)
			{
				y=310;
				b[i].setBounds(x5,y,w,h);
				x5+=w;
			}
			else if(i<60)
			{
				y=250;
				b[i].setBounds(x6,y,w,h);
				x6-=w;
			}
			else if(i<70)
			{
				y=190;
				b[i].setBounds(x7,y,w,h);
				x7+=w;
			}
			else if(i<80)
			{
				y=130;
				b[i].setBounds(x8,y,w,h);
				x8-=w;
			}
			else if(i<90)
			{
				y=70;
				b[i].setBounds(x9,y,w,h);
				x9+=w;
			}
			else if(i<100)
			{
				y=10;
				b[i].setBounds(x10,y,w,h);
				x10-=w;
			}
			else if( i == 100)
			{
				b[100].setBounds(160,10,60,60);
			}
		}
		
		//Pasting_Components_on_Frame
		for(int i=0;i<b.length;i++)
		{
			mainFrame.add(b[i]);
		}
		
		//
		firstPlayer = new JLabel(new ImageIcon("player_images/p1.png"));
		firstPlayer.setBounds(150,550,60,60);
		
		secondPlayer = new JLabel(new ImageIcon("player_images/p2.png"));
		secondPlayer.setBounds(150,480,60,60);
		
		mainFrame.add(firstPlayer);
		mainFrame.add(secondPlayer);
		
		turnLabel = new JLabel();
		turnLabel.setFont(new java.awt.Font("Times New Roman", 1, 15));
		turnLabel.setBounds(875,70,150,50);
		turnLabel.setText(firstPlayerName.getText()+"'s Turn");
		mainFrame.add(turnLabel);
		
		
		diceButton = new JButton();
		diceButton.setBounds(900,130,60,60);
		diceButton.setIcon(new ImageIcon("dice_images/dice.png"));
		diceButton.addActionListener(this);
		mainFrame.add(diceButton);
		
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		mainFrame.setLayout(null);
		mainFrame.setSize(1040,700);
		mainFrame.setVisible(true);
	}
	
	//InitializingFlagValueAndSomeCheckPoints
	
		int firstPlayerFirstTurn = 1;
		int secondPlayerFirstTurn = 1;
		int flag = 0;
		
	//Player's_Position
	
	int firstPlayerPosition;
	int secondPlayerPosition;
	
	//SixCount
	int firstSixCount;
	int secondSixCount;
	
	//winnerStatusFirst
	int winnerStatusFirst;
	int winnerStatusSecond;
	
	
	public void actionPerformed(ActionEvent e)
	{		
		if(e.getSource() == startGame)
		{
			firstPlayerName.getText();
			secondPlayerName.getText();
			if((firstPlayerName.getText().equals("")) && (secondPlayerName.getText().equals("")))
			{
				JOptionPane.showMessageDialog(enterNameDialog, "Please Enter Name of Both Players!!!");
			}
			else
			{
				startGame();
				enterNameDialog.dispose();
			}
		}
		
		if( e.getSource() == diceButton )
		{
			int num = randomNumber();
			
			if(flag == 0) //FIRST_PLAYER
			{
				if(firstPlayerFirstTurn == 1)
				{
					if(num == 6)
					{
						firstSixCount = 1;
						
						firstPlayerPosition = 0;
						firstPlayer.setIcon(null);
						b[0].setIcon(new ImageIcon("player_images/p1.png"));
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_6.png"));						
						firstPlayerFirstTurn = 0;
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else
					{
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
				}
				else if(firstPlayerFirstTurn == 0)
				{
					b[0].setIcon(new ImageIcon("images/img_1.jpeg"));
					if(num == 1)
					{
						int setPosition = firstPlayerPosition + num;
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( firstPlayerPosition == 99 )
							{
								b[99].setIcon(imgIcon[99]);
								b[100].setIcon(new ImageIcon("player_images/p1.png"));
								JOptionPane.showMessageDialog(mainFrame, firstPlayerName.getText()+" Wins!!!");
								winnerStatusFirst = 1;
								firstPlayerPosition = 100;
							}
							else
							{
								flag = 1;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = firstPlayerPosition + num;
						}
						else
						{
							flag = 1;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_1.png"));
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else if(num == 2)
					{
						
						int setPosition = firstPlayerPosition + num;						
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( firstPlayerPosition == 98 )
							{
								b[98].setIcon(imgIcon[98]);
								b[100].setIcon(new ImageIcon("player_images/p1.png"));
								JOptionPane.showMessageDialog(mainFrame, firstPlayerName.getText()+" Wins!!!");
								winnerStatusFirst = 1;
								firstPlayerPosition = 100;
							}
							else
							{
								flag = 1;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = firstPlayerPosition + num;
						}
						else
						{
							flag = 1;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_2.png"));
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else if(num == 3)
					{
						
						int setPosition = firstPlayerPosition + num;					
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 78;
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = firstPlayerPosition + num;
						}
						else
						{
							flag = 1;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_3.png"));
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else if(num == 4)
					{
						
						int setPosition = firstPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( firstPlayerPosition == 96 )
							{
								b[96].setIcon(imgIcon[96]);
								b[100].setIcon(new ImageIcon("player_images/p1.png"));
								JOptionPane.showMessageDialog(mainFrame, firstPlayerName.getText()+" Wins!!!");
								winnerStatusFirst = 1;
								firstPlayerPosition = 100;
							}
							else
							{
								flag = 1;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = firstPlayerPosition + num;
						}
						else
						{
							flag = 1;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_4.png"));
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else if(num == 5)
					{
						
						int setPosition = firstPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( firstPlayerPosition == 95 )
							{
								b[95].setIcon(imgIcon[95]);
								b[100].setIcon(new ImageIcon("player_images/p1.png"));
								JOptionPane.showMessageDialog(mainFrame, firstPlayerName.getText()+" Wins!!!");
								winnerStatusFirst = 1;
								firstPlayerPosition = 100;
							}
							else
							{
								flag = 1;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
							firstPlayerPosition = firstPlayerPosition + num;
						}
						else
						{
							flag = 1;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_5.png"));
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else if(num == 6)
					{
						firstSixCount = +1;
						if(firstSixCount<3)
						{
							
							int setPosition = firstPlayerPosition + num;
							
							if(setPosition == 3)
							{
								b[13].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 13;
							}
							else if( setPosition == 8)
							{
								b[30].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 30;
							}
							else if( setPosition == 16)
							{
								b[6].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 6;
							}
							else if( setPosition == 20)
							{
								b[41].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 41;
							}
							else if( setPosition == 27)
							{
								b[83].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 83;
							}
							else if( setPosition == 50)
							{
								b[66].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 66;
							}
							else if( setPosition == 53)
							{
								b[33].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 33;
							}
							else if( setPosition == 61)
							{
								b[18].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 18;
							}
							else if( setPosition == 63)
							{
								b[59].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 59;
							}
							else if( setPosition == 71)
							{
								b[90].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 90;
							}
							else if( setPosition == 79)
							{
								b[98].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 98;
							}
							else if( setPosition == 86)
							{
								b[35].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 35;
							}
							else if( setPosition == 92)
							{
								b[72].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 72;
							}
							else if( setPosition == 94)
							{
								b[74].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 74;
							}
							else if( setPosition == 97)
							{
								b[78].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = 78;
							}
							else if(setPosition<100)
							{
								b[setPosition].setIcon(new ImageIcon("player_images/p1.png"));
								firstPlayerPosition = firstPlayerPosition + num;
							}
							else
							{
								flag = 1;
							}
							
							diceButton.setIcon(new ImageIcon("dice_images/dice_6.png"));
							flag = 0;
							turnLabel.setText(firstPlayerName.getText()+"'s Turn");
						}
						else if(firstSixCount == 3)
						{
							flag =1;
						}						
					}
				}
				firstSixCount = 0;
			}
			
			else if(flag == 1) //SECOND_PLAYER
			{
				if(secondPlayerFirstTurn == 1)
				{
					if(num == 6)
					{
						secondSixCount = 1;
						
						secondPlayerPosition = 0;
						secondPlayer.setIcon(null);
						b[0].setIcon(new ImageIcon("player_images/p2.png"));
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_6.png"));
						secondPlayerFirstTurn = 0;
						flag = 1;
						turnLabel.setText(secondPlayerName.getText()+"'s Turn");
					}
					else
					{
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
				}
				else if(secondPlayerFirstTurn == 0)
				{
					b[0].setIcon(new ImageIcon("images/img_1.jpeg"));
					if(num == 1)
					{
						int setPosition = secondPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( secondPlayerPosition == 99 )
							{
								b[99].setIcon(imgIcon[99]);
								b[100].setIcon(new ImageIcon("player_images/p2.png"));
								JOptionPane.showMessageDialog(mainFrame, secondPlayerName.getText()+" Wins!!!");
								winnerStatusSecond = 1;
								secondPlayerPosition = 100;
							}
							else
							{
								flag = 0;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = secondPlayerPosition + num;
						}
						else
						{
							flag = 0;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_1.png"));
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else if(num == 2)
					{
						int setPosition = secondPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( secondPlayerPosition == 98 )
							{
								b[98].setIcon(imgIcon[98]);
								b[100].setIcon(new ImageIcon("player_images/p2.png"));
								JOptionPane.showMessageDialog(mainFrame, secondPlayerName.getText()+" Wins!!!");
								winnerStatusSecond = 1;
								secondPlayerPosition = 100;
							}
							else
							{
								flag = 0;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = secondPlayerPosition + num;
						}
						else
						{
							flag = 0;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_2.png"));
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else if(num == 3)
					{
						int setPosition = secondPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 78;
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = secondPlayerPosition + num;
						}
						else
						{
							flag = 0;
						}					
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_3.png"));
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else if(num == 4)
					{
						int setPosition = secondPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( secondPlayerPosition == 96 )
							{
								b[96].setIcon(imgIcon[96]);
								b[100].setIcon(new ImageIcon("player_images/p2.png"));
								JOptionPane.showMessageDialog(mainFrame, secondPlayerName.getText()+" Wins!!!");
								winnerStatusSecond = 1;
								secondPlayerPosition = 100;
							}
							else
							{
								flag = 0;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = secondPlayerPosition + num;
						}
						else
						{
							flag = 0;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_4.png"));
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else if(num == 5)
					{
						int setPosition = secondPlayerPosition + num;
						
						if(setPosition == 3)
						{
							b[13].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 13;
						}
						else if( setPosition == 8)
						{
							b[30].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 30;
						}
						else if( setPosition == 16)
						{
							b[6].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 6;
						}
						else if( setPosition == 20)
						{
							b[41].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 41;
						}
						else if( setPosition == 27)
						{
							b[83].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 83;
						}
						else if( setPosition == 50)
						{
							b[66].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 66;
						}
						else if( setPosition == 53)
						{
							b[33].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 33;
						}
						else if( setPosition == 61)
						{
							b[18].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 18;
						}
						else if( setPosition == 63)
						{
							b[59].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 59;
						}
						else if( setPosition == 71)
						{
							b[90].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 90;
						}
						else if( setPosition == 79)
						{
							b[98].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 98;
						}
						else if( setPosition == 86)
						{
							b[35].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 35;
						}
						else if( setPosition == 92)
						{
							b[72].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 72;
						}
						else if( setPosition == 94)
						{
							b[74].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 74;
						}
						else if( setPosition == 97)
						{
							b[78].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = 78;
						}
						else if( setPosition == 100 )
						{
							if( secondPlayerPosition == 95 )
							{
								b[95].setIcon(imgIcon[95]);
								b[100].setIcon(new ImageIcon("player_images/p2.png"));
								JOptionPane.showMessageDialog(mainFrame, secondPlayerName.getText()+" Wins!!!");
								winnerStatusSecond = 1;
								secondPlayerPosition = 100;
							}
							else
							{
								flag = 0;
							}
						}
						else if(setPosition<100)
						{
							b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
							secondPlayerPosition = secondPlayerPosition + num;
						}
						else
						{
							flag = 0;
						}
						
						diceButton.setIcon(new ImageIcon("dice_images/dice_5.png"));
						flag = 0;
						turnLabel.setText(firstPlayerName.getText()+"'s Turn");
					}
					else if(num == 6)
					{
						secondSixCount = +1;
						if(secondSixCount<3)
						{
							int setPosition = secondPlayerPosition + num;
							
							if(setPosition == 3)
							{
								b[13].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 13;
							}
							else if( setPosition == 8)
							{
								b[30].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 30;
							}
							else if( setPosition == 16)
							{
								b[6].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 6;
							}
							else if( setPosition == 20)
							{
								b[41].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 41;
							}
							else if( setPosition == 27)
							{
								b[83].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 83;
							}
							else if( setPosition == 50)
							{
								b[66].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 66;
							}
							else if( setPosition == 53)
							{
								b[33].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 33;
							}
							else if( setPosition == 61)
							{
								b[18].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 18;
							}
							else if( setPosition == 63)
							{
								b[59].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 59;
							}
							else if( setPosition == 71)
							{
								b[90].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 90;
							}
							else if( setPosition == 79)
							{
								b[98].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 98;
							}
							else if( setPosition == 86)
							{
								b[35].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 35;
							}
							else if( setPosition == 92)
							{
								b[72].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 72;
							}
							else if( setPosition == 94)
							{
								b[74].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 74;
							}
							else if( setPosition == 97)
							{
								b[78].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = 78;
							}
							else if(setPosition<100)
							{
								b[setPosition].setIcon(new ImageIcon("player_images/p2.png"));
								secondPlayerPosition = secondPlayerPosition + num;
							}
							else
							{
								flag = 0;
							}
							
							diceButton.setIcon(new ImageIcon("dice_images/dice_6.png"));
							flag = 1;
							turnLabel.setText(secondPlayerName.getText()+"'s Turn");
						}
						else if(secondSixCount == 3)
						{
							flag = 0;
						}
					}
				}
				secondSixCount = 0;
			}
			
			//DefiningImageIcons
			for(int i = 0; i<imgIcon.length;i++)
			{
				if( i == firstPlayerPosition  || i == secondPlayerPosition)
				{
				
				}
				else
				{
					b[i].setIcon(imgIcon[i]);
				}
			}
		}
		
		if( winnerStatusFirst == 1 )
		{
			winnerFrame();
		}
		else if( winnerStatusSecond == 1)
		{
			winnerFrame();
		}
		
	}
	
	//WinnerFrameComponents
	JFrame winFrame;
	JLabel winBanner;
	ImageIcon winImg;
	
	
	void winnerFrame()
	{
		diceButton.setEnabled(false);
		for(int i = 0; i<imgIcon.length;i++)
		{
			b[i].setIcon(imgIcon[i]);
		}
	}
	
	
	public static void main(String... ar)
	{
		new JavaSNL();
	}
}