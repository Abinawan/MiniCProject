#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
int game2_rps(char,char);
int savescore_of_gtn(int);
int displayscore_of_gtn();
int savescore_of_rps(int);
int viewscoreRPS();
int mainmenu();
int intro();
int exiting();
int gtn();
int rule_gtn();
int game_gtn();
int hangman();
int rulesHangman();
int playHangman();
int endOfHangman();
int welcome_rps();
int rule_rps();
int game_rps();
struct user_rps{
    char username1[10];
    int score1;
}*pUser_rps;
struct user_gtn{
    char username[10];
    int score;
}*pUser_gtn;
int a, cha1 = 177, arrowOpt = 175, chaSpace = 32;
int optionA, optionB, optionC, optionD;
// MAIN FUNCTION
int main(){
	intro();
	mainmenu();
}
int intro(){
	for(a = 1; a<=41 ; a++) printf("%c", cha1);
	printf("\n\n,--.   ,--.,--.,--.  ,--.,--.     ,-----. \n");
	printf("|   `.'   ||  ||  ,'.|  ||  |    '  .--./ \n");
	printf("|  |'.'|  ||  ||  |' '  ||  |    |  |     \n");
	printf("|  |   |  ||  ||  | `   ||  |.--.'  '--'\\ \n");
	printf("`--'   `--'`--'`--'  `--'`--''--' `-----' \n\n");
	for(a = 1; a<=41 ; a++) printf("%c", cha1);
	printf("\nMini Project using C language! [Group A]\n");
	sleep(5);
}
int mainmenu(){
    system("cls");
    int displayOpt, selectedOpt = 1, userChoice;
    do {           
        for(a = 1; a<=14 ; a++) printf("%c", cha1);
        printf(" MAIN MENU ");
        for(a = 1; a<=14 ; a++) printf("%c", cha1);
        printf("\n\n");
        if(selectedOpt == 1){
            optionA = arrowOpt;
            optionB = optionC = optionD = chaSpace;
        } else if(selectedOpt == 2){
            optionB = arrowOpt;
            optionA = optionC = optionD = chaSpace;
        } else if(selectedOpt == 3){
            optionC = arrowOpt;
            optionB = optionA = optionD = chaSpace;
        } else if(selectedOpt == 4){
            optionD = arrowOpt;
            optionB = optionC = optionA = chaSpace;
        }
        printf(" \t%c 1. Guess The Number\n", optionA);
        printf(" \t%c 2. Rock, Paper, Scissor\n", optionB);
        printf(" \t%c 3. Hangman: Word Game\n", optionC);
        printf(" \t%c 4. Exit Application\n\n", optionD);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        time_t rawtime;
        struct tm * timeinfo;
        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        printf ( "\nTime and date: %s", asctime (timeinfo) );
        printf("Use Arrow Keys & Enter to choose option!");
        userChoice = getch();
        if(userChoice==72 && selectedOpt>1) {
            selectedOpt--; //u
        } else if(userChoice==80 && selectedOpt<4) {
            selectedOpt++; //d
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOpt){
        case 1:
            gtn();
            break;
        case 2:
            welcome_rps();
            break;
        case 3:
            hangman();
            break;
        case 4:
        	exiting();
            break;
        default: 
            system("exit");
            break;
    }
    return 0;
}
int exiting(){
	system("cls");
    int ex1, ex2, selectedOptionEXIT = 1, userChoice;
    do {
        for(a = 1; a<=11 ; a++) printf("%c", cha1);
        printf(" EXIT APPLICATION ");
        for(a = 1; a<=10 ; a++) printf("%c", cha1);
        printf("\n\n");
        if(selectedOptionEXIT == 1){
            ex1 = arrowOpt;
            ex2 = chaSpace;
        } else if(selectedOptionEXIT == 2){
            ex2 = arrowOpt;
            ex1 = chaSpace;
        } 
        printf(" \t\t%c 1. YES\n", ex1);
        printf(" \t\t%c 2. NO\n\n", ex2);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        printf("\n");
    	userChoice = getch();
        if(userChoice==72 && selectedOptionEXIT>1) {
            selectedOptionEXIT--; //u
        } else if(userChoice==80 && selectedOptionEXIT<2) {
            selectedOptionEXIT++; //d
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOptionEXIT){
        case 2:
            mainmenu();
            break;
        default:
        	system("cls");
        	for(a = 1; a<=44 ; a++) printf("%c", cha1);
        printf("\n\n");
        
        	printf("\tThank you for using MINI.C.\n\tDEVELOPERS: \n\t\tAaryab Panta\n\t\tAbinawan Bhattarai\n\t\tBinisha Maharjan\n\t\tNikesh Baral\n\n");
        	for(a = 1; a<=44 ; a++) printf("%c", cha1);
        	system("exit");
		}
    return 0;
}
int gtn(){
	system("cls");
    int d_1, d_2, d_3, d_4, selectedOptionGTN = 1, userChoice;
    do {
        for(a = 1; a<=11 ; a++) printf("%c", cha1);
        printf(" GUESS THE NUMBER ");
        for(a = 1; a<=10 ; a++) printf("%c", cha1);
        printf("\n\n");
        if(selectedOptionGTN == 1){
            d_1 = arrowOpt;
            d_2 = d_3 = d_4 = chaSpace;
        } else if(selectedOptionGTN == 2){
            d_2 = arrowOpt;
            d_1 = d_3 = d_4 = chaSpace;
        } else if(selectedOptionGTN == 3){
            d_3 = arrowOpt;
            d_2 = d_1 = d_4 = chaSpace;
        } else if(selectedOptionGTN == 4){
            d_4 = arrowOpt;
            d_2 = d_3 = d_1 = chaSpace;
        }
        printf(" \t%c 1. Rules of Game\n", d_1);
        printf(" \t%c 2. Play the game\n", d_2);
        printf(" \t%c 3. View highscores\n", d_3);
        printf(" \t%c 4. Go to main menu\n\n", d_4);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        printf("\n");
    	userChoice = getch();
        if(userChoice==72 && selectedOptionGTN>1) {
            selectedOptionGTN--; //u
        } else if(userChoice==80 && selectedOptionGTN<4) {
            selectedOptionGTN++; //d
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOptionGTN){
        case 1:
            rule_gtn();
            break;
        case 2:
            game_gtn();
            break;
        case 3:
            displayscore_of_gtn();
            break;
        case 4:
            mainmenu();
        }
    return 0;
}  
int rule_gtn(){
    int cha1 = 177, optionA, d2, d3, d4, selectedOpt = 1, userChoice;
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf(" RULES SECTION ");
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf("\n\n");
    printf("Here are some basic rules of Guess the number:\n\n");
    printf("1. Guess the number by typing it in keyboard,\n");
    printf("2. Total of 5 lives which decreases upon \n   every incorrect guess,\n");
    printf("3. Point system according to lives remaining,\n");
    printf("4. The point is based on following format:\n");
    int i;
    for(i=1; i<=33; i++) printf("-");
    printf("\n|\tLives\t|\tScore\t|\n");
    for(i=1; i<=33; i++) printf("-");    printf("\n");
    for(i=5; i>=1; i--)    printf("|\t%d\t|\t%d\t|\n", i, (i*2-1));
    for(i=1; i<=33; i++) printf("-");
   	printf("\n");
    for(a = 1; a<=46 ; a++) printf("%c", cha1);
    printf("\nPress any key to continue....");
    getch();
    system("cls");
    gtn();
}
int game_gtn(){
    system("cls");
    int num,guessed_num,lives,score;
    char ch;
    lives=5;
    srand(time(0));
    num = rand()%100 + 1;
    printf("Computer: I have selected a random number from 1-100. Guess it if you can!\n");
    do{
    	printf("\nYour guess:");
        scanf("%d",&guessed_num);
        if(num == guessed_num){
            printf("Computer: That was the exact number I had thought of!:\nLives : %d\n",lives);
            switch (lives){
            case 1:
                printf("Score = 1");
                savescore_of_gtn(1);
                break;
            case 2:
                printf("Score = 3");
                savescore_of_gtn(3);
                break;
            case 3:
                printf("Score = 5");
                savescore_of_gtn(5);
                break;
            case 4:
                printf("Score = 7");
                savescore_of_gtn(7);
                break;
            case 5:
                printf("Score = 9");
                savescore_of_gtn(9);
                break;
            default:
                break;
            }
            break;
        }
        if(lives>1){
        if(guessed_num > num ){
            if((guessed_num - num) < 10){
                printf("WRONG! But you are very close. It is lesser than you guessed!");
            } else {
                printf("WRONG! It is way more lesser than you guessed!");
            }
        }else if(guessed_num < num ){
            if((num - guessed_num) < 10){
                printf("WRONG! But you are very close. It is greater than you guessed!");
            } else {
                printf("WRONG! It is way more greater than you guessed!");
            }
        } else {
                printf("Computer: You couldn't guess the correct number.");
        }
        }
        lives--;
        printf("\n\tYou have %d tries remaining!",lives);
        if (lives==1){
            printf("\n\tThis is your final try! Good Luck!");
        }
    } while (lives!=0);
    if(lives==0){
        printf("\nComputer: Unlucky, you ran out of attempts to guess the number. I was thinking of %d ",num);
        printf(" You can beat me next time.");
        getch();
    } else {
        printf("\nComputer: This time you got me but next time you won't be guessing it.");
        getch();
    }
    int displayOpt, selectedOpt = 1, userChoice;
	system("cls");
	do {           
         for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf(" WHAT DO YOU WANT TO DO? ");
        for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf("\n\n");
        
        printf("\n");
        if(selectedOpt == 1){
            optionA = arrowOpt;
            optionB = optionC = chaSpace;
        } else if(selectedOpt == 2){
            optionB = arrowOpt;
            optionA = optionC = chaSpace;
        } else if(selectedOpt == 3){
            optionC = arrowOpt;
            optionA = optionB = chaSpace;
        }  
        printf(" \t%c 1. Play Again?\n", optionA);
        printf(" \t%c 2. View Highscore\n", optionB);
        printf(" \t%c 3. Go Back to Menu\n\n", optionC);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        userChoice = getch();
        if(userChoice==72 && selectedOpt>1) {
            selectedOpt--; //u
        } else if(userChoice==80 && selectedOpt<3) {
            selectedOpt++; //d
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOpt){
        case 1:
            game_gtn();
            break;
        case 2:
            displayscore_of_gtn();
            break;
        case 3:
        	gtn();
        	break;
        }
        return 0;
}
int displayscore_of_gtn(){
	system("cls");
    FILE *fp;
    pUser_gtn=(struct user_gtn *)malloc(sizeof(struct user_gtn));
    if ( ( fp=fopen("score_info_of_gtn.dat", "r+")) == NULL) {
        if ( ( fp=fopen("score_info_of_gtn.dat", "w+")) == NULL) {
             printf ("Could not open file\n");
            exit ( 1);
        }
    }
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf(" LEADERBOARD ");
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf("\n\n");
    printf("\n\tNAME\t\t|\tSCORE\n\t------------------------------");        
    while ( fread (pUser_gtn, sizeof(struct user_gtn), 1, fp) == 1)
    {
    	printf("\n\t%s\t\t|\t%d",pUser_gtn->username,pUser_gtn->score);
	}
	free ( pUser_gtn);
    fclose(fp);
    printf("\n\n");
    for(a = 1; a<=46 ; a++) printf("%c", cha1);
    getch();
   	gtn();
   	return 0;
}
int savescore_of_gtn(int point){
    FILE *fp;
    FILE *fp_temp;
    char uName[10];
    jump:
    printf("\nEnter  A Username: ");
    scanf("%9s",uName);
    if(strlen(uName)>7)
    {
    	printf("!!!Username can't exceed more than 7 character");
    	goto jump;
	}
    pUser_gtn=(struct user_gtn *)malloc(sizeof(struct user_gtn));
    fp=fopen("score_info_of_gtn.dat", "a+");
    fp_temp=fopen("temp.dat","w+");
    while ( fread (pUser_gtn, sizeof(struct user_gtn), 1, fp) == 1)
    {
    	if(strcmp(pUser_gtn->username,strupr(uName))==0)
    	{
    		printf("\nUser name already taken.The score will be added there");
			point =  pUser_gtn->score + point;
			continue;
		}
		else 
		{
			fwrite (pUser_gtn, sizeof(struct user_gtn), 1, fp_temp);
		}
		
	}
    strcpy(pUser_gtn->username,strupr(uName));
    pUser_gtn->score = point;
    fwrite (pUser_gtn, sizeof(struct user_gtn), 1, fp_temp);
    free ( pUser_gtn);//free allocated memory
    fclose(fp);
    fclose(fp_temp);
    remove("score_info_of_gtn.dat");
    rename("temp.dat","score_info_of_gtn.dat");
    return 0;     
}
int viewscoreRPS()
{
	FILE *fp;
    pUser_rps=(struct user_rps *)malloc(sizeof(struct user_rps));
    if ( ( fp=fopen("score_info_of_rps.dat", "r+")) == NULL) {
                if ( ( fp=fopen("score_info_of_rps.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
	for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf(" LEADERBOARD ");
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf("\n\n");
    printf("\n\tNAME\t\t|\tSCORE\n\t------------------------------");   
    while ( fread (pUser_rps, sizeof(struct user_rps), 1, fp) == 1)
    {
    	printf("\n\t%s\t\t|\t%d",pUser_rps->username1,pUser_rps->score1);
	}
	free ( pUser_rps);//free allocated memory
    fclose(fp);
    printf("\n\n");
    for(a = 1; a<=46 ; a++) printf("%c", cha1);
    getch();
    welcome_rps();
}
int savescore_of_rps(int point){
	FILE *fp;
    FILE *fp_temp;
    char uName[10];
    jump1:
    printf("\nEnter  A Username: ");
    scanf("%9s",uName);
    if(strlen(uName)>7){
    	printf("!!!Username can't exceed more than 7 character");
    	goto jump1;
	}
    pUser_rps=(struct user_rps *)malloc(sizeof(struct user_rps));
    fp=fopen("score_info_of_rps.dat", "a+");
    fp_temp=fopen("temp.dat","w+");
    while ( fread (pUser_rps, sizeof(struct user_rps), 1, fp) == 1){
    	if(strcmp(pUser_rps->username1,strupr(uName))==0){
    		printf("\nUser name already taken.The score will be added there");
            getch();
			point =  pUser_rps->score1 + point;
			continue;
		} else {
			fwrite (pUser_rps, sizeof(struct user_rps), 1, fp_temp);
		}
	}
    strcpy(pUser_rps->username1,strupr(uName));
    pUser_rps->score1 = point;
    fwrite (pUser_rps, sizeof(struct user_rps), 1, fp_temp);
    free ( pUser_rps);//free allocated memory
    fclose(fp);
    fclose(fp_temp);
    remove("score_info_of_rps.dat");
    rename("temp.dat","score_info_of_rps.dat");
}
int welcome_rps(){
    system("cls");
    int selectedOptRPS = 1, userChoiceRPS;
    do {           
        for(a = 1; a<=8 ; a++) printf("%c", cha1);
        printf(" ROCK, PAPER, SCISSOR ");
        for(a = 1; a<=8 ; a++) printf("%c", cha1);
        printf("\n\n");
        if(selectedOptRPS == 1){
            optionA = arrowOpt;
            optionB = optionC = optionD = chaSpace;
        } else if(selectedOptRPS == 2){
            optionB = arrowOpt;
            optionA = optionC = optionD = chaSpace;
        } else if(selectedOptRPS == 3){
            optionC = arrowOpt;
            optionB = optionA = optionD = chaSpace;
        } else if(selectedOptRPS == 4){
        	optionD = arrowOpt;
        	optionA = optionB = optionC = chaSpace;
		}
        printf(" \t%c 1. Rules of the game\n", optionA);
        printf(" \t%c 2. Play the game\n", optionB);
        printf(" \t%c 3. View highscore\n", optionC);
        printf(" \t%c 4. Back to menu\n\n", optionD);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        printf("\n");  
        userChoiceRPS = getch();
        if(userChoiceRPS==72 && selectedOptRPS>1) {
                selectedOptRPS--; //u
        } else if(userChoiceRPS==80 && selectedOptRPS<4) {
                selectedOptRPS++; //d
        }
        system("cls");
    } while (userChoiceRPS != 13);
    switch(selectedOptRPS){
        case 1:
                rule_rps();
                break;
        case 2:
                game_rps();
                break;
        case 3: 
                viewscoreRPS();
                break;
        default:
                mainmenu();
    }
    return 0;
}
 
int rule_rps(){
    int cha1 = 177, optionA, d2, d3, d4, selectedOpt = 1, userChoice;
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf(" RULES SECTION ");
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf("\n\n");
    printf("Here are some basic rules of Rock, Paper and Scissor:\n\n");
    printf("1. Choose your option by typing it in keyboard,\n");
    printf("2. The game is of Best of 3,[first to 3 points wins],\n");
    printf("3. The game will continue untill a winner is decided!,\n");
    printf("4. 5point will be added if you win and if you loose 2 point will be deducted,\n");
    printf("4. The game is based on following system:\n\t");
    int i;
    for(i=1; i<=22; i++) printf("-");    printf("\n");
    printf("\t| Rock WINS Scissor  |\n");
    printf("\t| Paper WINS Rock    |\n");
    printf("\t| Scissor WINS Paper |\n\t");
    for(i=1; i<=22; i++) printf("-");
   	printf("\n");
    for(a = 1; a<=46 ; a++) printf("%c", cha1);
    printf("\nPress any key to continue....");
    getch();
    system("cls");
    welcome_rps();
}
int game_rps(){
    system("cls");
    int num,a=0,condition,pou=0,poc=0,round=0,cases=0;
    char ch2,you,comp;
    while (poc < 3 || pou < 3){
        if(round>0){
            system("cls");
        }
        for(a = 1; a<=18 ; a++) printf("%c", cha1);
        printf(" ROUND %d ",++round);
        for(a = 1; a<=18 ; a++) printf("%c", cha1);
        printf("\n\n");
        printf("\nComputer: ROCK, PAPER OR SCISSOR???\n[Pick up r for rock, s for scissor and p for paper]");
        printf("\n-->");
        scanf("%s",&you);
        cases = you=='r' || you=='p' || you=='s';
        while(cases==0){
            printf("Please enter a valid choice!!!\n-->");
            scanf("%s",&you);
            cases = you=='r' || you=='p' || you=='s';
        }
        srand(time(0));
        num = rand()%100 + 1;
        if(num<33){
            comp = 'r';
        } else if (num>33 && num<66){
            comp = 'p';
        } else {
            comp = 's';
        }
        condition = game2_rps(comp,you);
        if (condition == 1){
        	printf("\t,--.   ,--.,--.,--.  ,--. \n");
			printf("\t|  |   |  ||  ||  ,'.|  | \n");
			printf("\t|  |.'.|  ||  ||  |' '  | \n");
			printf("\t|   ,'.   ||  ||  | `   | \n");
			printf("\t'--'   '--'`--'`--'  `--' \n");
            if(comp=='r'){
				printf("\n   _______       	           _______\n");
                printf("---'   ____)   		    ____(____    '---\n");
                printf("      (_____)  		   (______\n");
                printf("      (_____)   	   (______\n");
                printf("      (____)    	    (_______\n");
                printf("---.__(___)     	     (__________.---\n");
            } else if(comp=='p') {
				printf("\n    _______                   _______\n");
                printf("---'    ____)____        ____(____   '---\n");
                printf("           ______)      (______\n");
                printf("          _______)     (__________\n");
                printf("         _______)           (____) \n");
                printf("---.__________)               (___)__.---\n");
            } else {
				printf("\n    _______                 _______    \n");
                printf("---'   ____)____           (____   '---\n");
                printf("          ______)         (_____)\n");
                printf("       __________)        (_____)\n");
                printf("      (____)               (____)\n");
                printf("---.__(___)                 (___)__.---\n");
            }
            pou++;
        } else if (condition == -1){
			printf("\t,--.    ,-----.  ,---. ,--------. \n"); 
			printf("\t|  |   '  .-.  ''   .-''--.  .--' \n"); 
			printf("\t|  |   |  | |  |`.  `-.   |  |    \n"); 
			printf("\t|  '--.'  '-'  '.-'    |  |  |    \n"); 
			printf("\t`-----' `-----' `-----'   `--'    \n"); 
            if(comp=='r'){
                printf("\n   _______       	            _______\n");
                printf("---'   ____)   		     ____(____   '---\n");
                printf("      (_____)  		    (______\n");
                printf("      (_____)   	   (__________\n");
                printf("      (____)    	       (____)\n");
                printf("---.__(___)     	         (____)_.---\n");
            }else if(comp=='p'){
                printf("\n    _______                _______    \n");
                printf("---'    ____)____         (____   '---\n");
                printf("           ______)       (_____)\n");
                printf("          _______)       (_____) \n");
                printf("         _______)         (____) \n");
                printf("---.__________)            (___)__.---\n");
            }else{
                printf("\n    _______                  _______\n");
                printf("---'   ____)____        ____(____    '---\n");
                printf("          ______)      (______\n");
                printf("       __________)     (______\n");
                printf("      (____)            (_______\n");
                printf("---.__(___)              (__________.---\n");
        	}
            poc++;
        } else {
			printf("    ,------.  ,------.   ,---.  ,--.   ,--.\n"); 
			printf("    |  .-.  \\ |  .--. ' /  O  \\ |  |   |  |\n"); 
			printf("    |  |  \\  :|  '--'.'|  .-.  ||  |.'.|  |\n");  
			printf("    |  '--'  /|  |\\  \\ |  | |  ||   ,'.   |\n");  
			printf("    `-------' `--' '--'`--' `--''--'   '--'\n");  
            if(comp=='r'){
                printf("\n   _______       	         _______\n");
                printf("---'   ____)   		      (____   '---\n");
                printf("      (_____)  		     (_____)\n");
                printf("      (_____)   	     (_____)\n");
                printf("      (____)    	      (____)\n");
                printf("---.__(___)     	       (___)_.---\n");
            }else if(comp=='p'){
                printf("\n    _______                   _______\n");
                printf("---'    ____)____        ____(____   '---\n");
                printf("           ______)      (______\n");
                printf("          _______)      (_______\n");
                printf("         _______)         (_______\n");
                printf("---.__________)            (__________.---\n");
            }else{
                printf("\n    _______                   _______\n");
                printf("---'   ____)____            ____(____   '---\n");
                printf("          ______)          (_______\n");
                printf("       __________)        (___________\n");
                printf("      (____)                   (____)\n");
                printf("---.__(___)                      (___)__.---\n");
        	}
 		}
        printf("\n\nComputer:%d\t\t\tYour:%d",poc,pou);
        if(poc==3 || pou ==3){
            printf("\nWinner has been decided press any key to continue ");
            getch();
            break;
        }
        printf("\n\nPress any key to go to next round....");
        getch();
    }
    system("cls");
    if (pou == 3){
        printf("\nYou won you got +5 points");
        savescore_of_rps(5);
    } else if (poc == 3){
        printf("\nYou lost you lost 2 points");
        savescore_of_rps(-2);
    }
    int displayOpt, selectedOpt = 1, userChoice;
	system("cls");
	do {           
         for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf(" WHAT DO YOU WANT TO DO? ");
        for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf("\n\n");
        printf("\n");
        if(selectedOpt == 1){
            optionA = arrowOpt;
            optionB = optionC = chaSpace;
        } else if(selectedOpt == 2){
            optionB = arrowOpt;
            optionA = optionC = chaSpace;
        } else if(selectedOpt == 3){
            optionC = arrowOpt;
            optionA = optionB = chaSpace;
        }  
        printf(" \t%c 1. Play Again?\n", optionA);
        printf(" \t%c 2. View Highscore\n", optionB);
        printf(" \t%c 3. Go Back to Menu\n\n", optionC);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        userChoice = getch();
        if(userChoice==72 && selectedOpt>1) {
            selectedOpt--; //u
        } else if(userChoice==80 && selectedOpt<3) {
            selectedOpt++; //d
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOpt){
        case 1:
            game_rps();
        case 2:
            viewscoreRPS();
        case 3:
        	welcome_rps();
        }
   return 0;
}
int game2_rps(char comp, char you){
    if (you == comp){
        return 0;
    }
    if (you == 'r' && comp == 'p'){
        return -1;
    } else if (you == 'p' && comp == 'r'){
        return 1;
    }
    if (you == 'p' && comp == 's'){
        return -1;
    } else if (you == 's' && comp == 'p'){
        return 1;
    }
    if (you == 's' && comp == 'r'){
        return -1;
    } else if (you == 'r' && comp == 's'){
        return 1;
    }
}
int hangman() {
    system("cls");
    int selectedOptRPS = 1, userChoiceRPS;
    do {          
        for(a = 1; a<=8 ; a++) printf("%c", cha1);
        printf(" HANGMAN: WORD GAME ");
        for(a = 1; a<=8 ; a++) printf("%c", cha1);
        printf("\n\n");
        if(selectedOptRPS == 1){
            optionA = arrowOpt;
            optionB = optionC = chaSpace;
        } else if(selectedOptRPS == 2){
            optionB = arrowOpt;
            optionA = optionC = chaSpace;
        } else if(selectedOptRPS == 3){
            optionC = arrowOpt;
            optionB = optionA = chaSpace;
        }
        printf(" \t%c 1. Rules of the game\n", optionA);
        printf(" \t%c 2. Play the game\n", optionB);
        printf(" \t%c 3. Back to menu\n\n", optionC);
                for(a = 1; a<=39 ; a++) printf("%c", cha1);
                printf("\n");  
                        userChoiceRPS = getch();
                if(userChoiceRPS==72 && selectedOptRPS>1) {
                        selectedOptRPS--; //u
                } else if(userChoiceRPS==80 && selectedOptRPS<3) {
                        selectedOptRPS++; //d
                }
                system("cls");
        } while (userChoiceRPS != 13);
        switch(selectedOptRPS){
                case 1:
                       rulesHangman();
                        break;
                case 2:
                        playHangman();
                        break;
                default:
                        mainmenu();
        }
    return 0;
}
int rulesHangman(){
    int cha1 = 177, optionA, d2, d3, d4, selectedOpt = 1, userChoice;
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf(" RULES SECTION ");
    for(a = 1; a<=16 ; a++) printf("%c", cha1);
    printf("\n\n");
    printf("Here are some basic rules of Hangman:\n\n");
    printf("1. A number of (_) equivalent to the number of letters in the word appear to you,\n");
    printf("2. You need to guess the word by entering the word's letters,\n");
    printf("3. if you guess the letter wrong the system will draw a piece of the man and you lose a try becareful you only have 5 tries!\n");
    printf("4. you lose if the man's drawing is completed which mean the man is hanged :( help the man!\n\t");
   	printf("\n");
    for(a = 1; a<=46 ; a++) printf("%c", cha1);
    printf("\nPress any key to continue....");
    getch();
    system("cls");
    hangman();
}
int playHangman(){
    system("cls");
    int quit=1;
        while(quit!=0){
    printf("Please wait !\n       O\n      \\|\n       |\\\n      / \\\n");
    sleep(1);
    system("cls");
    printf("Please wait !\n       O\n       |/\n      /|\n      / \\\n");
    sleep(1);
    system("cls");
    printf("Please wait!\n       O\n      \\|\n       |\\\n      / \\\n");
    sleep(1);
    system("cls");
    printf("Please wait!\n       O\n       |/\n      /|\n      / \\\n");
    sleep(1);
    system("cls");
    printf("Please wait!\n       O\n       |/\n      /|\n      / \\\n");
    sleep(1);
    system("cls");
    srand(time(0));
    int letters=0,random_num;
    random_num=rand()%100 + 1;
    char* word;
    while(letters==0){
        switch(random_num){
            case 1: word="book"; letters = 4; break;
            case 2: word="car"; letters =3; break;
            case 3: word="tree"; letters= 4; break;
            case 4: word="game"; letters=4; break;
            case 5: word="understand"; letters=10; break;
            case 6: word="family"; letters=6; break;
            case 7: word="pen"; letters=3; break;
            case 8: word="coffee"; letters=6; break;
            case 9: word="email"; letters=5; break;
            case 10: word="facebook"; letters=8; break;
            case 11: word="football"; letters=8; break;
            case 12: word="online"; letters=6; break;
            case 13: word="come"; letters=4; break;
            case 14: word="please"; letters=6; break;
            case 15: word="introduction"; letters=12; break;
            case 16: word="project"; letters=7; break;
            case 17: word="create"; letters=6; break;
            case 18: word="programming"; letters=11; break;
            case 19: word="warrior"; letters=7; break;
            case 20: word="weird"; letters=5; break;
            case 21: word="handsome"; letters=8; break;
            case 22: word="amazing"; letters=7; break;
            case 23: word="knife"; letters=5; break;
            case 24: word="engineer"; letters=8;break;
            case 25: word="physics";letters=7;break;
            case 26: word="chemistry";letters=9;break;
            // You can add upto 100 word by adding case;
            default: word=""; letters=0;break;
        }
        random_num=rand()%100 + 1;
    }
    printf("Try guessing the word by guessing the letters: \n");
    char answer[100];
    char wanswer[100]=" ";
    strcpy(answer,"");
    int i;
    printf("o-----------\n|          \n|\n|\n|\n|\n|\n|\n");
        for(i=1;i<=letters;i++){
            strcat(answer,"_ ");
            printf("_ ");
        }
        int b=0, c=0, p=1, finish=0, j;
        while(c<5){  
            printf("\nEnter a letter to guess.... ");
            char letter;
            scanf("%s",&letter);
            system("cls");
            if(strchr(word,letter)!=0){
                for(j=0;j<=letters-1;j++){
                    if(letter==word[j]){
                        p=j*2;
                        if(answer[p]!=letter) finish++;
                        answer[p]=letter;
                    }
                }
                if(c==0) printf("o-----------\n|          \n|\n|\n|\n|\n|\n|\n");  
                if(c==1) printf("o-----------\n|          |\n|\n|\n|\n|\n|\n|\n");
               if(c==2) printf("o-----------\n|          |\n|          O\n|\n|\n|\n|\n|\n");
               if(c==3) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|\n|\n|\n");  
               if(c==4) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|         / \\\n|\n|\n");  
                printf("%s\n",answer);
                printf("Correct Guess!\n");
                printf("You got another try +1\n");
                if(finish==letters) break;
                if(b!=0) printf("Letters you have used  %s",wanswer);
                if(c>0)c--;
            } else {
                wanswer[2*b]=letter;
                strcat(wanswer," ");
                b++;
               system("cls"); c++;
               if(c==1) printf("o-----------\n|          |\n|\n|\n|\n|\n|\n|\n");
               if(c==2) printf("o-----------\n|          |\n|          O\n|\n|\n|\n|\n|\n");
               if(c==3) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|\n|\n|\n");  
               if(c==4) printf("o-----------\n|          |\n|          O\n|          |\n|          |\n|         / \\\n|\n|\n");  
               if(c==5){ system("cls"); printf("o-----------\n|          |\n|          O <--------|you killed me :(|\n|         \\|/\n|          |\n|         / \\\n|\n|\n");}
               if(c!=5){
               printf("%d Tries left\n",4-c);
               printf("%s\n",answer);
               printf("Letters you have used  %s",wanswer);
               }
            }
    }
    if(finish==letters) {    
        system("cls");
        printf("            O <------|You saved me!!!! Thank you! <3|\n           \\|/\n            |\n           / \\\n");
        sleep(1);
        system("cls");
        printf("            O <------|You saved me!!!! Thank you! <3|\n           \\|\n            |\\\n           / \\\n");
        sleep(1);
        system("cls");
        printf("            O <------|You saved me!!!! Thank you! <3|\n            |/\n           /|\n           / \\\n");
        sleep(1);
        system("cls");
        printf("            O <------|You saved me!!!! Thank you! <3|\n            |\n           /|\\\n           / \\\n");
        sleep(1);
        system("cls");
        printf("            O <------|You saved me!!!! Thank you! <3|\n           \\|/\n            |\n           / \\\n");
        printf("Amazing! You won! The word was \"%s\" \n",word);
        getch();
        endOfHangman();
        } else {
				printf("You lost :( The word was \"%s\" \n\n",word);
               getch();
               endOfHangman();
           }
        }
        return 0;
}
int endOfHangman(){
	int displayOpt, selectedOpt = 1, userChoice;
	system("cls");
	do {           
         for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf(" WHAT DO YOU WANT TO DO? ");
        for(a = 1; a<=7 ; a++) printf("%c", cha1);
        printf("\n\n\n");
        if(selectedOpt == 1){
            optionA = arrowOpt;
            optionB= chaSpace;
        } else if(selectedOpt == 2){
            optionB = arrowOpt;
            optionA = chaSpace;
        } 
        printf(" \t%c 1. Play Again?\n", optionA);
        printf(" \t%c 2. Go Back to Menu\n\n", optionB);
        for(a = 1; a<=39 ; a++) printf("%c", cha1);
        userChoice = getch();
        if(userChoice==72 && selectedOpt>1) {
            selectedOpt--; 
        } else if(userChoice==80 && selectedOpt<3) {
            selectedOpt++; 
        }
        system("cls");
    } while (userChoice != 13);
    switch(selectedOpt){
        case 1:
            playHangman();
        case 2:
            hangman();
    }
}
