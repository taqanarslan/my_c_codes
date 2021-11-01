#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

//Tahtayi YAZDIRMA FONKSIYONU
void printBoard(char [11][11]);
//Eski Tahtayi Tutmak icin Fonk
void copyBoard(char Board[11][11],char oldBoard[11][11]);

int main()
{	
	//YOL HARITASI
	int BRoad[35][3]={{0,4,1},{1,4,2},{2,4,3},{3,4,4},{4,3,4},{5,2,4},{6,1,4},{7,1,5},{8,1,6},{9,2,6},{10,3,6},{11,4,6},{12,4,7},{13,4,8},{14,4,9},{15,5,9},{16,6,9},{17,6,8},{18,6,7},{19,6,6},{20,7,6},{21,8,6},{22,9,6},{23,9,5},{24,9,4},{25,8,4},{26,7,4},{27,6,4},{28,6,3},{29,6,2},{30,6,1},{31,5,1},{32,5,2},{33,5,3},{34,5,4}};
	int RRoad[35][3]={{0,1,6},{1,2,6},{2,3,6},{3,4,6},{4,4,7},{5,4,8},{6,4,9},{7,5,9},{8,6,9},{9,6,8},{10,6,7},{11,6,6},{12,7,6},{13,8,6},{14,9,6},{15,9,5},{16,9,4},{17,8,4},{18,7,4},{19,6,4},{20,6,3},{21,6,2},{22,6,1},{23,5,1},{24,4,1},{25,4,2},{26,4,3},{27,4,4},{28,3,4},{29,2,4},{30,1,4},{31,1,5},{32,2,5},{33,3,5},{34,4,5}};
	int YRoad[35][3]={{0,6,9},{1,6,8},{2,6,7},{3,6,6},{4,7,6},{5,8,6},{6,9,6},{7,9,5},{8,9,4},{9,8,4},{10,7,4},{11,6,4},{12,6,3},{13,6,2},{14,6,1},{15,5,1},{16,4,1},{17,4,2},{18,4,3},{19,4,4},{20,3,4},{21,2,4},{22,1,4},{23,1,5},{24,1,6},{25,2,6},{26,3,6},{27,4,6},{28,4,7},{29,4,8},{30,4,9},{31,5,9},{32,5,8},{33,5,7},{34,5,6}};
	int GRoad[35][3]={{0,9,4},{1,8,4},{2,7,4},{3,6,4},{4,6,3},{5,6,2},{6,6,1},{7,5,1},{8,4,1},{9,4,2},{10,4,3},{11,4,4},{12,3,4},{13,2,4},{14,1,4},{15,1,5},{16,1,6},{17,2,6},{18,3,6},{19,4,6},{20,4,7},{21,4,8},{22,4,9},{23,5,9},{24,6,9},{25,6,8},{26,6,7},{27,6,6},{28,7,6},{29,8,6},{30,9,6},{31,9,5},{32,8,5},{33,7,5},{34,6,5}};
	
	int amount,i,j,k,dice,starter,startstop=1,winner=0,x,y,x2,y2,cont,dec;
	char Blue[10],Red[10],Yellow[10],Green[10],Board[11][11],trash,temp,oldBoard[11][11];
	
	//Giriþ Menüsü
	while(startstop!=0)
	{
		printf("Enter 0 To Start The Game\nEnter 1 To See The Rules\nEnter 2 To Quit\n");
		scanf("%d",&startstop);
		scanf("%c",&trash);
		system("cls");
		if(startstop==2)
		{
			return 0;
		}
		if(startstop==1)
		{
			printf("Rules Are:\n");
			printf("1. Each player has 4 pieces.\n");
			printf("2. There might be 2, 3, or 4 players (Red (R) ,Yellow (Y), Green (G) and Blue (B))\n");
			printf("3. At each round the respective player rolls the single dice (1-6).\n");
			printf("4. Each piece is allowed to leave from the nest, if the dice shows “6”.\n");
			printf("5. At each cell, only one single piece could exist.\n");
			printf("6. Each player is allowed to place any number of his/her pieces into the raceway.\n");
			printf("7. If the player rolls six, he/she could either place a piece into the board from the nest(home) or play any piece on the board.\n");
			printf("8. A piece could move forward even if there is a piece of any opponent on its way\n");
			printf("9. If a piece stops at the same place of another piece of the same player, the player is not allowed to move it. He/she should wait for his/her next turn.\n");
			printf("10.Nobody could hurt a piece if it reaches at the final destination.\n");
			printf("11. If any piece could reach to the location of another players’ piece, the piece should return to its nest.\n");
			printf("12. The player whose all 4 pieces reach at final destination becomes the WINNER.\n");
			printf("13. To move a pawn of yours Enter The X and Y of it in X(Space)Y format\n");
			printf("14. Blue starts from [4][1] and goes rightwards,Red starts from [1][6] and goes downwards,Yellow starts from [6][9] and goes leftwards,Green starts from [9][4] and goes upwards\n");
			printf("Press enter to go back to menu:");
			scanf("%c",&trash);
		}
		system("cls");
	}
	
	
	//OYUNCU SAYISI VE BASLAYAN KISIYI RASTGELE SECME
	srand(time(NULL));
	printf("Enter the amount of how many players will play (2-3-4) ");
	scanf("%d",&amount);
	if(amount>=2)
	{
	printf("Enter the name of Blue: ");
	scanf("%s",Blue);
	printf("Enter the name of Red: ");
	scanf("%s",Red);
	}
	if(amount>2)
	{
		printf("Enter the name of Yellow: ");
		scanf("%s",Yellow);
	}
	if(amount>3)
	{
		printf("Enter the name of Green: ");
		scanf("%s",Green);
	}
	printf("To pick the starter randomly press enter");
	scanf("%c",&trash);
	scanf("%c",&trash);
	printf("Starter is randomly picking: ");
	
	starter=rand()%amount;
	
	if(starter==0)
	{
		printf("%s(Blue) starts\n",Blue);
	}
	else if(starter==1)
	{
		printf("%s(Red) Starts\n",Red);
	}
	else if(starter==2)
	{
		printf("%s(Yellow) Starts\n",Yellow);
	}
	else if(starter==3)
	{
		printf("%s(Green) Starts\n",Green);
	}
	printf("To start the game press enter");
	scanf("%c",&trash);
	printf("\n");
	
	
	//TAHTANIN YERLESTIRILMESI
	for(i=1;i<10;i++)
	{
		for(j=1;j<10;j++)
		{
			Board[i][j]=' ';
		}
	}
	for(i=0;i<10;i++)
	{
		Board[i][0]='0'+i;
		Board[0][i]='0'+i;
	}
	for(i=1;i<3;i++)
	{
		for(j=1;j<3;j++)
		{
			Board[i][j]='B';
		}
		for(j=8;j<10;j++)
		{
			Board[i][j]='R';
		}
	}
	for(i=8;i<10;i++)
	{
		if(amount>3)
		{
			for(j=1;j<3;j++)
			{
				Board[i][j]='G';
			}
		}
		if(amount>2)
		{
			for(j=8;j<10;j++)
			{
				Board[i][j]='Y';
			}
		}
	}

	for(i=1;i<4;i++)
	{
		Board[i][3]='X';
		Board[3][i]='X';
		Board[i][7]='X';
		Board[7][i]='X';
	}
	for(i=7;i<10;i++)
	{
		Board[i][3]='X';
		Board[3][i]='X';
		Board[i][7]='X';
		Board[7][i]='X';
	}
	for(i=2;i<5;i++)
	{
		Board[i][5]='D';
		Board[5][i]='D';
	}
	for(i=6;i<9;i++)
	{
		Board[i][5]='D';
		Board[5][i]='D';
	}
	for(i=0;i<11;i++)
	{
		Board[i][10]='X';
		Board[10][i]='X';
	}
	system("cls");	
	printBoard(Board);
	
	while(winner==0)
	{
		//Mavi
		if(starter%amount==0 && winner==0)
		{
			system("color 1");
			copyBoard(Board,oldBoard);
			printf("%s(Blue)'S Turn\n",Blue);
			printf("To roll the dice press Enter");
			scanf("%c",&trash);
			dice=rand()%6+1;
			printf("You Rolled %d\n",dice);
			//Dýþarýda kendi piyonu yok
			if(Board[1][1]=='B')
			{
				//Zar<6
				if(dice<6)
				{
					printf("You don't have a pawn outside and you can't leave home with this dice so (YOUR TURN WILL BE SKIPPED)\n");
				}
				//Zar=6
				else
				{
					printf("You can leave one of your pawns please press enter to leave");
					scanf("%c",&trash);
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[4][1]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Sarý Varsa
					else if(Board[4][1]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Yesil Varsa
					else if(Board[4][1]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					Board[4][1]='B';
					Board[1][1]=' ';
				}
			}
			//Dýþarýda Kendi Piyonu Var Zar<6 Ya Da Ýçeride Kendi Piyonu Yok Zar=6
			else if((Board[1][1]!='B' && dice<6) || (Board[2][2]==' ' && dice==6))
			{
				printf("Please choose the pawn you want to move with");
				scanf("%d %d",&x,&y);
				scanf("%c",&trash);
				cont=0;
				i=-1;
				while(i<34 && cont==0)
					{
						i++;
						if(BRoad[i][1]==x && BRoad[i][2]==y && Board[x][y]=='B')
						{
							cont=1;
							printf("The pawn you want to move is found\n");
						}
					}
				if(cont==0)
				{
					printf("(%d,%d) is not on the Blue path or there is no Blue pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
				}
				else if(BRoad[i][0]+dice>=35)
				{
					printf("You can't make this move(YOUR TURN WILL BE SKIPPED)\n");
				}
				else if(BRoad[i][0]+dice<35)
				{
					
					printf("To move your pawn please press enter");
					scanf("%c",&trash);
					x2=BRoad[i+dice][1];
					y2=BRoad[i+dice][2];
					if(Board[x2][y2]=='B')
					{
						printf("There is a Blue pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
					}
					if(Board[x2][y2]!='B')
					{
						//Yiyecek Piyon Var Mý?
						//Kýrmýzý Varsa
						if(Board[x2][y2]=='R')
						{
							if(Board[2][9]==' ')
							{	
								Board[2][9]=='R';
							}
							else if(Board[2][8]==' ')
							{
								Board[2][8]='R';
							}
							else if(Board[1][9]==' ')
							{
								Board[1][9]='R';
							}
							else
							{
								Board[1][8]='R';
							}
						}
						//Sarý Varsa
						else if(Board[x2][y2]=='Y')
						{
							if(Board[9][9]==' ')
							{
								Board[9][9]='Y';
							}
							else if(Board[9][8]==' ')
							{
								Board[9][8]='Y';
							}
							else if(Board[8][9]==' ')
							{
								Board[8][9]='Y';
							}
							else
							{
								Board[8][8]='Y';
							}
						}
						//Yesil Varsa
						else if(Board[x2][y2]=='G')
						{
							if(Board[9][2]==' ')
							{
								Board[9][2]='G';
							}
							else if(Board[9][1]==' ')
							{
								Board[9][1]='G';
							}
							else if(Board[8][2]==' ')
							{
								Board[8][2]='G';
							}
							else
							{
								Board[8][1]='G';
							}
						}
						Board[x2][y2]='B';
						Board[x][y]=' ';
					}
				}
			}
			//Dýþarýda Ve Ýçeride Kendi Piyonu Var Zar=6
			else if(Board[2][2]=='B' && dice==6)
			{
				//Dýþarý Mý Çýkacak Piyon Mu Oynayacak
				printf("To move a pawn enter (1) To leave home with a pawn enter (0): ");
				scanf("%d",&dec);
				scanf("%c",&trash);
				//Dýþarý Çýkma
				if(dec==0 && Board[4][1]!='B')
				{
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[4][1]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Sarý Varsa
					else if(Board[4][1]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Yesil Varsa
					else if(Board[4][1]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					//Cikacak Piyonun Belirlenmesi
					if(Board[1][2]=='B')
					{
						Board[1][2]=' ';
					}
					else if(Board[2][1]=='B')
					{
						Board[2][1]=' ';
					}
					else
					{
						Board[2][2]=' ';
					}
					Board[4][1]='B';
				}
				//Dýþarý Çýkamama
				else if(dec==0 && Board[4][1]=='B')
				{
					printf("You can't leave your home because there is a Blue pawn at the start of your path(YOUR TURN WILL BE SKIPPED)\n");
				}
				//Piyon Oynama
				else if(dec==1)
				{
					printf("Please choose the pawn you want to move with");
					scanf("%d %d",&x,&y);
					scanf("%c",&trash);
					cont=0;
					i=-1;
					while(i<34 && cont==0)
						{
							i++;
							if(BRoad[i][1]==x && BRoad[i][2]==y && Board[x][y]=='B')
							{
								cont=1;
								printf("The pawn you want to move is found\n");
							}
						}
					if(cont==0)
					{
						printf("(%d,%d) is not on the Blue path or there is no Blue pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
					}
					else if(BRoad[i][0]+dice>=35)
					{
						printf("You can't make this move(YOUR TURN WILL BE SKIPPED)");
					}
					else if(BRoad[i][0]+dice<35)
					{
						
						printf("To move your pawn please press enter");
						scanf("%c",&trash);
						x2=BRoad[i+dice][1];
						y2=BRoad[i+dice][2];
						if(Board[x2][y2]=='B')
						{
							printf("There is a Blue pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
						}
						if(Board[x2][y2]!='B')
						{
							//Yiyecek Piyon Var Mý?
							//Kýrmýzý Varsa
							if(Board[x2][y2]=='R')
							{
								if(Board[2][9]==' ')
								{	
									Board[2][9]=='R';
								}
								else if(Board[2][8]==' ')
								{
									Board[2][8]='R';
								}
								else if(Board[1][9]==' ')
								{
									Board[1][9]='R';
								}
								else
								{
									Board[1][8]='R';
								}
							}
							//Sarý Varsa
							else if(Board[x2][y2]=='Y')
							{
								if(Board[9][9]==' ')
								{
									Board[9][9]='Y';
								}
								else if(Board[9][8]==' ')
								{
									Board[9][8]='Y';
								}
								else if(Board[8][9]==' ')
								{
									Board[8][9]='Y';
								}
								else
								{
									Board[8][8]='Y';
								}
							}
							//Yesil Varsa
							else if(Board[x2][y2]=='G')
							{
								if(Board[9][2]==' ')
								{
									Board[9][2]='G';
								}
								else if(Board[9][1]==' ')
								{
									Board[9][1]='G';
								}
								else if(Board[8][2]==' ')
								{
									Board[8][2]='G';
								}
								else
								{
									Board[8][1]='G';
								}
							}
							Board[x2][y2]='B';
							Board[x][y]=' ';
						}
					}
				}
			}
			//Destination Bozulursa Düzeltme
			if(Board[5][2]==' ')
			{
				Board[5][2]='D';
			}
			if(Board[5][3]==' ')
			{
				Board[5][3]='D';
			}
			if(Board[5][4]==' ')
			{
				Board[5][4]='D';
			}
			//KAZANMA KONTROLU
									
									
			if(Board[5][1]=='B' && Board[5][2]=='B' && Board[5][3]=='B' && Board[5][4]=='B')
			{
				winner=1;
			}
			//Sonraki Oyuncuya Gecme Eklemeleri
			if(winner==0)
			{
			printf("To skip to the next player please press enter");
			scanf("%c",&trash);
			system("cls");
			printf("Dice was= %d\n",dice);
			printf("Board before your move:\n");
			printBoard(oldBoard);
			printf("\n");
			printf("Board after your move:\n");
			printBoard(Board);
			starter++;
			}
		}
		//Kýrmýzý
		if(starter%amount==1 && winner==0)
		{
			system("color 4");
			copyBoard(Board,oldBoard);
			printf("%s(Red)'S Turn\n",Red);
			printf("To roll the dice press Enter");
			scanf("%c",&trash);
			dice=rand()%6+1;
			printf("You Rolled %d\n",dice);
			//Dýþarýda kendi piyonu yok
			if(Board[1][8]=='R')
			{
				//Zar<6
				if(dice<6)
				{
					printf("You don't have a pawn outside and you can't leave home with this dice(YOUR TURN WILL BE SKIPPED)\n");
				}
				//Zar=6
				else
				{
					printf("You can leave one of your pawns please press enter to leave");
					scanf("%c",&trash);
					//Yiyecek Piyon Var Mý?
					//Mavi Varsa
					if(Board[1][6]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][1]=='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					//Sarý Varsa
					else if(Board[1][6]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Yesil Varsa
					else if(Board[1][6]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					Board[1][6]='R';
					Board[1][8]=' ';
				}
			}
			//Dýþarýda Kendi Piyonu Var Zar<6 Ya Da Ýçeride Kendi Piyonu Yok Zar=6
			else if((Board[1][8]!='R' && dice<6) || (Board[2][9]==' ' && dice==6))
			{
				printf("Please choose the pawn you want to move with");
				scanf("%d %d",&x,&y);
				scanf("%c",&trash);
				cont=0;
				i=-1;
				while(i<34 && cont==0)
					{
						i++;
						if(RRoad[i][1]==x && RRoad[i][2]==y && Board[x][y]=='R')
						{
							cont=1;
							printf("The pawn you want to move is found\n");
						}
					}
				if(cont==0)
				{
					printf("(%d,%d) is not on the Red path or there is no Red pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
				}
				else if(RRoad[i][0]+dice>=35)
				{
					printf("You can't make this move(YOUR TURN WILL BE SKIPPED)\n");
				}
				else if(RRoad[i][0]+dice<35)
				{
					
					printf("To move your pawn please press enter");
					scanf("%c",&trash);
					x2=RRoad[i+dice][1];
					y2=RRoad[i+dice][2];
					if(Board[x2][y2]=='R')
					{
						printf("There is a Red pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
					}
					if(Board[x2][y2]!='R')
					{
						//Yiyecek Piyon Var Mý?
						//Mavi Varsa
						if(Board[x2][y2]=='B')
						{
							if(Board[2][2]==' ')
							{	
								Board[2][2]=='B';
							}
							else if(Board[2][1]==' ')
							{
								Board[2][1]='B';
							}
							else if(Board[1][2]==' ')
							{
								Board[1][2]='B';
							}
							else
							{
								Board[1][1]='B';
							}
						}
						//Sarý Varsa
						else if(Board[x2][y2]=='Y')
						{
							if(Board[9][9]==' ')
							{
								Board[9][9]='Y';
							}
							else if(Board[9][8]==' ')
							{
								Board[9][8]='Y';
							}
							else if(Board[8][9]==' ')
							{
								Board[8][9]='Y';
							}
							else
							{
								Board[8][8]='Y';
							}
						}
						//Yesil Varsa
						else if(Board[x2][y2]=='G')
						{
							if(Board[9][2]==' ')
							{
								Board[9][2]='G';
							}
							else if(Board[9][1]==' ')
							{
								Board[9][1]='G';
							}
							else if(Board[8][2]==' ')
							{
								Board[8][2]='G';
							}
							else
							{
								Board[8][1]='G';
							}
						}
						Board[x2][y2]='R';
						Board[x][y]=' ';
					}
				}
			}
			//Dýþarýda Ve Ýçeride Kendi Piyonu Var Zar=6
			else if(Board[2][9]=='R' && dice==6)
			{
				//Dýþarý Mý Çýkacak Piyon Mu Oynayacak
				printf("To move a pawn enter (1) To leave home with a pawn enter (0): ");
				scanf("%d",&dec);
				scanf("%c",&trash);
				//Dýþarý Çýkma
				if(dec==0 && Board[1][6]!='R')
				{
					//Yiyecek Piyon Var Mý?
					//Mavi Varsa
					if(Board[1][6]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][2]=='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					//Sarý Varsa
					else if(Board[1][6]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Yesil Varsa
					else if(Board[1][6]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					//Cikacak Piyonun Belirlenmesi
					if(Board[1][9]=='R')
					{
						Board[1][9]=' ';
					}
					else if(Board[2][8]=='R')
					{
						Board[2][8]=' ';
					}
					else
					{
						Board[2][9]=' ';
					}
					Board[1][6]='R';
				}
				//Dýþarý Çýkamama
				else if(dec==0 && Board[1][6]=='R')
				{
					printf("You can't leave your home because there is a Red pawn at the start of your path(YOUR TURN WILL BE SKIPPED)\n");
				}
				//Piyon Oynama
				else if(dec==1)
				{
					printf("Please choose the pawn you want to move with");
					scanf("%d %d",&x,&y);
					scanf("%c",&trash);
					cont=0;
					i=-1;
					while(i<34 && cont==0)
						{
							i++;
							if(RRoad[i][1]==x && RRoad[i][2]==y && Board[x][y]=='R')
							{
								cont=1;
								printf("The pawn you want to move is found\n");
							}
						}
					if(cont==0)
					{
						printf("(%d,%d) is not on the Red path or there is no Red pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
					}
					else if(RRoad[i][0]+dice>=35)
					{
						printf("You can't make this move(YOUR TURN WILL BE SKIPPED)");
					}
					else if(RRoad[i][0]+dice<35)
					{
						printf("To move your pawn please press enter");
						scanf("%c",&trash);
						x2=RRoad[i+dice][1];
						y2=RRoad[i+dice][2];
						if(Board[x2][y2]=='R')
						{
							printf("There is a Red pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
						}
						if(Board[x2][y2]!='R')
						{
							//Yiyecek Piyon Var Mý?
							//Mavi Varsa
							if(Board[x2][y2]=='B')
							{
								if(Board[2][2]==' ')
								{	
									Board[2][2]=='B';
								}
								else if(Board[2][1]==' ')
								{
									Board[2][1]='B';
								}
								else if(Board[1][2]==' ')
								{
									Board[1][2]='B';
								}
								else
								{
									Board[1][1]='B';
								}
							}
							//Sarý Varsa
							else if(Board[x2][y2]=='Y')
							{
								if(Board[9][9]==' ')
								{
									Board[9][9]='Y';
								}
								else if(Board[9][8]==' ')
								{
									Board[9][8]='Y';
								}
								else if(Board[8][9]==' ')
								{
									Board[8][9]='Y';
								}
								else
								{
									Board[8][8]='Y';
								}
							}
							//Yesil Varsa
							else if(Board[x2][y2]=='G')
							{
								if(Board[9][2]==' ')
								{
									Board[9][2]='G';
								}
								else if(Board[9][1]==' ')
								{
									Board[9][1]='G';
								}
								else if(Board[8][2]==' ')
								{
									Board[8][2]='G';
								}
								else
								{
									Board[8][1]='G';
								}
							}
							Board[x2][y2]='R';
							Board[x][y]=' ';
						}
					}
				}
			}
			//Destination Bozulursa Düzeltme
			if(Board[2][5]==' ')
			{
				Board[2][5]='D';
			}
			if(Board[3][5]==' ')
			{
				Board[3][5]='D';
			}
			if(Board[4][5]==' ')
			{
				Board[4][5]='D';
			}
			//KAZANMA KONTROLU
			if(Board[1][5]=='R' && Board[2][5]=='R' && Board[3][5]=='R' && Board[4][5]=='R')
			{
				winner=2;
			}
			//Sonraki Oyuncuya Gecme Eklemeleri
			if(winner==0)
			{
			printf("To skip to the next player please press enter");
			scanf("%c",&trash);
			system("cls");
			printf("Dice was= %d\n",dice);
			printf("Board before your move:\n");
			printBoard(oldBoard);
			printf("\n");
			printf("Board after your move:\n");
			printBoard(Board);
			starter++;
			}
		}
		//Sarý
		if(starter%amount==2 && winner==0)
		{
			system("color E");
			copyBoard(Board,oldBoard);
			printf("%s(Yellows)'S Turn\n",Yellow);
			printf("To roll the dice press Enter");
			scanf("%c",&trash);
			dice=rand()%6+1;
			printf("You Rolled %d\n",dice);
			//Dýþarýda kendi piyonu yok
			if(Board[8][8]=='Y')
			{
				//Zar<6
				if(dice<6)
				{
					printf("You don't have a pawn outside and you can't leave home with this dice so (YOUR TURN WILL BE SKIPPED)\n");
				}
				//Zar=6
				else
				{
					printf("You can leave one of your pawns please press enter to leave");
					scanf("%c",&trash);
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[6][9]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Mavi Varsa
					else if(Board[6][9]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][2]='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					//Yesil Varsa
					else if(Board[6][9]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					Board[6][9]='Y';
					Board[8][8]=' ';
				}
			}
			//Dýþarýda Kendi Piyonu Var Zar<6 Ya Da Ýçeride Kendi Piyonu Yok Zar=6
			else if((Board[8][8]!='Y' && dice<6) || (Board[9][9]==' ' && dice==6))
			{
				printf("Please choose the pawn you want to move with");
				scanf("%d %d",&x,&y);
				scanf("%c",&trash);
				cont=0;
				i=-1;
				while(i<34 && cont==0)
					{
						i++;
						if(YRoad[i][1]==x && YRoad[i][2]==y && Board[x][y]=='Y')
						{
							cont=1;
							printf("The pawn you want to move is found\n");
						}
					}
				if(cont==0)
				{
					printf("(%d,%d) is not on the Yellow path or there is no Yellow pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
				}
				else if(YRoad[i][0]+dice>=35)
				{
					printf("You can't make this move(YOUR TURN WILL BE SKIPPED)\n");
				}
				else if(YRoad[i][0]+dice<35)
				{
					
					printf("To move your pawn please press enter");
					scanf("%c",&trash);
					x2=YRoad[i+dice][1];
					y2=YRoad[i+dice][2];
					if(Board[x2][y2]=='Y')
					{
						printf("There is a Yellow pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
					}
					if(Board[x2][y2]!='Y')
					{
						//Yiyecek Piyon Var Mý?
						//Kýrmýzý Varsa
						if(Board[x2][y2]=='R')
						{
							if(Board[2][9]==' ')
							{	
								Board[2][9]=='R';
							}
							else if(Board[2][8]==' ')
							{
								Board[2][8]='R';
							}
							else if(Board[1][9]==' ')
							{
								Board[1][9]='R';
							}
							else
							{
								Board[1][8]='R';
							}
						}
						//Mavi Varsa
						else if(Board[x2][y2]=='B')
						{
							if(Board[2][2]==' ')
							{
								Board[2][2]='B';
							}
							else if(Board[2][1]==' ')
							{
								Board[2][1]='B';
							}
							else if(Board[1][2]==' ')
							{
								Board[1][2]='B';
							}
							else
							{
								Board[1][1]='B';
							}
						}
						//Yesil Varsa
						else if(Board[x2][y2]=='G')
						{
							if(Board[9][2]==' ')
							{
								Board[9][2]='G';
							}
							else if(Board[9][1]==' ')
							{
								Board[9][1]='G';
							}
							else if(Board[8][2]==' ')
							{
								Board[8][2]='G';
							}
							else
							{
								Board[8][1]='G';
							}
						}
						Board[x2][y2]='Y';
						Board[x][y]=' ';
					}
				}
			}
			//Dýþarýda Ve Ýçeride Kendi Piyonu Var Zar=6
			else if(Board[9][9]=='Y' && dice==6)
			{
				//Dýþarý Mý Çýkacak Piyon Mu Oynayacak
				printf("To move a pawn enter (1) To leave home with a pawn enter (0): ");
				scanf("%d",&dec);
				scanf("%c",&trash);
				//Dýþarý Çýkma
				if(dec==0 && Board[6][9]!='Y')
				{
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[6][9]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Mavi Varsa
					else if(Board[6][9]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][2]='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					//Yesil Varsa
					else if(Board[6][9]=='G')
					{
						if(Board[9][2]==' ')
						{
							Board[9][2]='G';
						}
						else if(Board[9][1]==' ')
						{
							Board[9][1]='G';
						}
						else if(Board[8][2]==' ')
						{
							Board[8][2]='G';
						}
						else
						{
							Board[8][1]='G';
						}
					}
					//Cikacak Piyonun Belirlenmesi
					if(Board[8][9]=='Y')
					{
						Board[8][9]=' ';
					}
					else if(Board[9][8]=='Y')
					{
						Board[9][8]=' ';
					}
					else
					{
						Board[9][9]=' ';
					}
					Board[6][9]='Y';
				}

				//Dýþarý Çýkamama
				else if(dec==0 && Board[6][9]=='Y')
				{
					printf("You can't leave your home because there is a Yello pawn at the start of your path(YOUR TURN WILL BE SKIPPED)\n");
				}
				//Piyon Oynama
				else if(dec==1)
				{
					printf("Please choose the pawn you want to move with");
					scanf("%d %d",&x,&y);
					scanf("%c",&trash);
					cont=0;
					i=-1;
					while(i<34 && cont==0)
						{
							i++;
							if(YRoad[i][1]==x && YRoad[i][2]==y && Board[x][y]=='Y')
							{
								cont=1;
								printf("The pawn you want to move is found\n");
							}
						}
					if(cont==0)
					{
						printf("(%d,%d) is not on the Yellow path or there is no Yellow pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
					}
					else if(YRoad[i][0]+dice>=35)
					{
						printf("You can't make this move(YOUR TURN WILL BE SKIPPED)");
					}
					else if(YRoad[i][0]+dice<35)
					{
						
						printf("To move your pawn please press enter");
						scanf("%c",&trash);
						x2=YRoad[i+dice][1];
						y2=YRoad[i+dice][2];
						if(Board[x2][y2]=='Y')
						{
							printf("There is a Yellow pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
						}
						if(Board[x2][y2]!='Y')
						{
							//Yiyecek Piyon Var Mý?
							//Kýrmýzý Varsa
							if(Board[x2][y2]=='R')
							{
								if(Board[2][9]==' ')
								{	
									Board[2][9]=='R';
								}
								else if(Board[2][8]==' ')
								{
									Board[2][8]='R';
								}
								else if(Board[1][9]==' ')
								{
									Board[1][9]='R';
								}
								else
								{
									Board[1][8]='R';
								}
							}
							//Mavi Varsa
							else if(Board[x2][y2]=='B')
							{
								if(Board[2][2]==' ')
								{
									Board[2][2]='B';
								}
								else if(Board[2][1]==' ')
								{
									Board[2][1]='B';
								}
								else if(Board[1][2]==' ')
								{
									Board[1][2]='B';
								}
								else
								{
									Board[1][1]='B';
								}
							}
							//Yesil Varsa
							else if(Board[x2][y2]=='G')
							{
								if(Board[9][2]==' ')
								{
									Board[9][2]='G';
								}
								else if(Board[9][1]==' ')
								{
									Board[9][1]='G';
								}
								else if(Board[8][2]==' ')
								{
									Board[8][2]='G';
								}
								else
								{
									Board[8][1]='G';
								}
							}
							Board[x2][y2]='Y';
							Board[x][y]=' ';
						}
					}
				}
			}
			//Destination Bozulursa Düzeltme
			if(Board[5][6]==' ')
			{
				Board[5][6]='D';
			}
			if(Board[5][7]==' ')
			{
				Board[5][7]='D';
			}
			if(Board[5][8]==' ')
			{
				Board[5][8]='D';
			}
			//KAZANMA KONTROLU
			if(Board[5][6]=='Y' && Board[5][7]=='Y' && Board[5][8]=='Y' && Board[5][9]=='Y')
			{
				winner=3;
			}
			//Sonraki Oyuncuya Gecme Eklemeleri
			if(winner==0)
			{
			printf("To skip to the next player please press enter");
			scanf("%c",&trash);
			system("cls");
			printf("Dice was= %d\n",dice);
			printf("Board before your move:\n");
			printBoard(oldBoard);
			printf("\n");
			printf("Board after your move:\n");
			printBoard(Board);
			starter++;
			}
		}
		//Yeþil
		if(starter%amount==3 && winner==0)
		{
			system("color 2");
			copyBoard(Board,oldBoard);
			printf("%s(Green)'S Turn\n",Green);
			printf("To roll the dice press Enter");
			scanf("%c",&trash);
			dice=rand()%6+1;
			printf("You Rolled %d\n",dice);
			//Dýþarýda kendi piyonu yok
			if(Board[8][1]=='G')
			{
				//Zar<6
				if(dice<6)
				{
					printf("You don't have a pawn outside and you can't leave home with this dice so (YOUR TURN WILL BE SKIPPED)\n");
				}
				//Zar=6
				else
				{
					printf("You can leave one of your pawns please press enter to leave");
					scanf("%c",&trash);
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[9][4]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Sarý Varsa
					else if(Board[9][4]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Mavi Varsa
					else if(Board[9][4]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][2]='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					Board[9][4]='G';
					Board[8][1]=' ';
				}
			}
			//Dýþarýda Kendi Piyonu Var Zar<6 Ya Da Ýçeride Kendi Piyonu Yok Zar=6
			else if((Board[8][1]!='G' && dice<6) || (Board[9][2]==' ' && dice==6))
			{
				printf("Please choose the pawn you want to move with");
				scanf("%d %d",&x,&y);
				scanf("%c",&trash);
				cont=0;
				i=-1;
				while(i<34 && cont==0)
					{
						i++;
						if(GRoad[i][1]==x && GRoad[i][2]==y && Board[x][y]=='G')
						{
							cont=1;
							printf("The pawn you want to move is found\n");
						}
					}
				if(cont==0)
				{
					printf("(%d,%d) is not on the Green path or there is no Green pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
				}
				else if(GRoad[i][0]+dice>=35)
				{
					printf("You can't make this move(YOUR TURN WILL BE SKIPPED)\n");
				}
				else if(GRoad[i][0]+dice<35)
				{
					
					printf("To move your pawn please press enter");
					scanf("%c",&trash);
					x2=GRoad[i+dice][1];
					y2=GRoad[i+dice][2];
					if(Board[x2][y2]=='G')
					{
						printf("There is a Green pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
					}
					if(Board[x2][y2]!='G')
					{
						//Yiyecek Piyon Var Mý?
						//Kýrmýzý Varsa
						if(Board[x2][y2]=='R')
						{
							if(Board[2][9]==' ')
							{	
								Board[2][9]=='R';
							}
							else if(Board[2][8]==' ')
							{
								Board[2][8]='R';
							}
							else if(Board[1][9]==' ')
							{
								Board[1][9]='R';
							}
							else
							{
								Board[1][8]='R';
							}
						}
						//Sarý Varsa
						else if(Board[x2][y2]=='Y')
						{
							if(Board[9][9]==' ')
							{
								Board[9][9]='Y';
							}
							else if(Board[9][8]==' ')
							{
								Board[9][8]='Y';
							}
							else if(Board[8][9]==' ')
							{
								Board[8][9]='Y';
							}
							else
							{
								Board[8][8]='Y';
							}
						}
						//Mavi Varsa
						else if(Board[x2][y2]=='B')
						{
							if(Board[2][2]==' ')
							{
								Board[2][2]='B';
							}
							else if(Board[2][1]==' ')
							{
								Board[2][1]='B';
							}
							else if(Board[1][2]==' ')
							{
								Board[1][2]='B';
							}
							else
							{
								Board[1][1]='B';
							}
						}
						Board[x2][y2]='G';
						Board[x][y]=' ';
					}
				}
			}
			//Dýþarýda Ve Ýçeride Kendi Piyonu Var Zar=6
			else if(Board[9][2]=='G' && dice==6)
			{
				//Dýþarý Mý Çýkacak Piyon Mu Oynayacak
				printf("To move a pawn enter (1) To leave home with a pawn enter (0): ");
				scanf("%d",&dec);
				scanf("%c",&trash);
				//Dýþarý Çýkma
				if(dec==0 && Board[8][1]!='B')
				{
					//Yiyecek Piyon Var Mý?
					//Kýrmýzý Varsa
					if(Board[9][4]=='R')
					{
						if(Board[2][9]==' ')
						{
							Board[2][9]=='R';
						}
						else if(Board[2][8]==' ')
						{
							Board[2][8]='R';
						}
						else if(Board[1][9]==' ')
						{
							Board[1][9]='R';
						}
						else
						{
							Board[1][8]='R';
						}
					}
					//Sarý Varsa
					else if(Board[9][4]=='Y')
					{
						if(Board[9][9]==' ')
						{
							Board[9][9]='Y';
						}
						else if(Board[9][8]==' ')
						{
							Board[9][8]='Y';
						}
						else if(Board[8][9]==' ')
						{
							Board[8][9]='Y';
						}
						else
						{
							Board[8][8]='Y';
						}
					}
					//Mavi Varsa
					else if(Board[9][4]=='B')
					{
						if(Board[2][2]==' ')
						{
							Board[2][2]='B';
						}
						else if(Board[2][1]==' ')
						{
							Board[2][1]='B';
						}
						else if(Board[1][2]==' ')
						{
							Board[1][2]='B';
						}
						else
						{
							Board[1][1]='B';
						}
					}
					//Cikacak Piyonun Belirlenmesi
					if(Board[8][2]=='G')
					{
						Board[8][2]=' ';
					}
					else if(Board[9][1]=='G')
					{
						Board[9][1]=' ';
					}
					else
					{
						Board[9][2]=' ';
					}
					Board[9][4]='G';
				}
				//Dýþarý Çýkamama
				else if(dec==0 && Board[9][4]=='G')
				{
					printf("You can't leave your home because there is a Green pawn at the start of your path(YOUR TURN WILL BE SKIPPED)\n");
				}
				//Piyon Oynama
				else if(dec==1)
				{
					printf("Please choose the pawn you want to move with");
					scanf("%d %d",&x,&y);
					scanf("%c",&trash);
					cont=0;
					i=-1;
					while(i<34 && cont==0)
						{
							i++;
							if(GRoad[i][1]==x && GRoad[i][2]==y && Board[x][y]=='G')
							{
								cont=1;
								printf("The pawn you want to move is found\n");
							}
						}
					if(cont==0)
					{
						printf("(%d,%d) is not on the Green path or there is no Green pawn there (YOUR TURN WILL BE SKIPPED).\n",x,y);
					}
					else if(GRoad[i][0]+dice>=35)
					{
						printf("You can't make this move(YOUR TURN WILL BE SKIPPED)");
					}
					else if(GRoad[i][0]+dice<35)
					{
						
						printf("To move your pawn please press enter");
						scanf("%c",&trash);
						x2=GRoad[i+dice][1];
						y2=GRoad[i+dice][2];
						if(Board[x2][y2]=='G')
						{
							printf("There is a Green pawn at the place you want to move(YOUR TURN WILL BE SKIPPED)\n");
						}
						if(Board[x2][y2]!='G')
						{
							//Yiyecek Piyon Var Mý?
							//Kýrmýzý Varsa
							if(Board[x2][y2]=='R')
							{
								if(Board[2][9]==' ')
								{	
									Board[2][9]=='R';
								}
								else if(Board[2][8]==' ')
								{
									Board[2][8]='R';
								}
								else if(Board[1][9]==' ')
								{
									Board[1][9]='R';
								}
								else
								{
									Board[1][8]='R';
								}
							}
							//Sarý Varsa
							else if(Board[x2][y2]=='Y')
							{
								if(Board[9][9]==' ')
								{
									Board[9][9]='Y';
								}
								else if(Board[9][8]==' ')
								{
									Board[9][8]='Y';
								}
								else if(Board[8][9]==' ')
								{
									Board[8][9]='Y';
								}
								else
								{
									Board[8][8]='Y';
								}
							}
							//Mavi Varsa
							else if(Board[x2][y2]=='B')
							{
								if(Board[2][2]==' ')
								{
									Board[2][2]='B';
								}
								else if(Board[2][1]==' ')
								{
									Board[2][1]='B';
								}
								else if(Board[1][2]==' ')
								{
									Board[1][2]='B';
								}
								else
								{
									Board[1][1]='B';
								}
							}
							Board[x2][y2]='G';
							Board[x][y]=' ';
						}
					}
				}
			}
			//Destination Bozulursa Düzeltme
			if(Board[6][5]==' ')
			{
				Board[6][5]='D';
			}
			if(Board[7][5]==' ')
			{
				Board[7][5]='D';
			}
			if(Board[8][5]==' ')
			{
				Board[8][5]='D';
			}
			//KAZANMA KONTROLÜ
			if(Board[6][5]=='G' && Board[7][5]=='G' && Board[8][5]=='G' && Board[9][5]=='G')
			{
				winner=4;
			}
			//Sonraki Oyuncuya Gecme Eklemeleri
			if(winner==0)
			{
			printf("To skip to the next player please press enter");
			scanf("%c",&trash);
			system("cls");
			printf("Dice was= %d\n",dice);
			printf("Board before your move:\n");
			printBoard(oldBoard);
			printf("\n");
			printf("Board after your move:\n");
			printBoard(Board);
			starter++;
			}
		}
	}
	system("cls");
	printf("Final board is:\n");
	printBoard(Board);
	if(winner==1)
	{
		printf("Blue(%s) Won",Blue);
	}
	if(winner==2)
	{
		printf("Red(%s) Won",Red);
	}
	if(winner==3)
	{
		printf("Yellow(%s) Won",Yellow);
	}
	if(winner==4)
	{
		printf("Green(%s) Won",Green);
	}
	return 0;
}

//Tahta Kopyalama FONK
void copyBoard(char Board[11][11],char oldBoard[11][11])
{
	int i,j;
	for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			oldBoard[i][j]=Board[i][j];
		}
	}
}

//Tahta Yazdirma FONK
void printBoard(char Board[11][11])
{

int i, j;

for(i=0;i<11;i++)
	{
		for(j=0;j<11;j++)
		{
			printf("%2c",Board[i][j]);
		}
		printf("\n");
	}
}
