#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <shadow.h>

int Winner[10][10][8];
int Sum = -10;
int resualt[35][35] = {-10};
int User_Team = 10;
char WorldCup_Name[100];
int state = 1;
int check = 0;

int Start();
int New_Game();
int Saved_Games();
int Next_Games(int n);
int Get_Worldcup_Name(void);
int INPUT(void);
int INPUT1(void);
int OUTPUT(void);
void Show_Team(void);
int Lineup(void);
void Select_Post_Player(void);
void Change_System(void);
int Sort_Point(int d1,int d2,int d3, int d4);

struct Players
{
    int Player_Number;
    char Name[30];
    int Player_Age;
    char Player_Post;
    char Player_Post_New;
    int Skill;
    int Fitness;
    int Form;
    bool Condition;
};
struct Teams
{
    char Name[50] ;
    char Group ;
    int Team_Position ;
    char Fedrasion [10];
    int seed ;
    int Team_Rate;
    int Number_Win;
    int Number_Lose;
    int Number_Equal;
    int Goal_S;
    int Goal_R;
    int Goal_M;
    int Enrollment;
    int System;
    int Sort_Rank;
    bool Defeated;
    char NAMEFILE[25];
    struct Players p[100];
};

struct Teams t[32] = {};
int main()
{

//    int User_Team = 10;
    int exit_game = 20;
    int select_start = Start();

    if(select_start == 1)
        exit_game = New_Game();
    else if(select_start == 2)
        exit_game = Saved_Games();
    else
    {
        printf("Have Fun :)\n");
        return 0;
    }
    if(exit_game == -100)
        return 0;

}
int Start()
{
    int select_start = 3;
    system("clear");
    printf("Select One Option:\n1- New Game\n2- Saved Games\n3- Exit\n");
    scanf("%d",&select_start);
    if(select_start != 1 && select_start != 2 && select_start != 3)
    {
        printf("Entery is not Valid: Choose between 1 or 3\n");
        return Start();
    }
    return select_start;
}


int New_Game()
{
    system("clear");
    INPUT();
    Get_Worldcup_Name();
    for(int i=0; i<=31; i++)
    {
        printf("%s",t[i].Name);
        for(int j=0; j<=15 - strlen(t[i].Name); j++)
        {
            printf(" ");
        }
        if((i+1)%8 == 0)
            printf("\n");
    }
    printf("Select your team:\nNote: Enter a number between 1 and 32\n");
    scanf("%d",&User_Team);
    if(User_Team >32 || User_Team <1)
    {
        printf("Your entery is not valid: \nTry again");
        return New_Game();
    }
    return Next_Games(0);

}


int Saved_Games()   /////Attention!!!!
{
    char Check_Name_Team[100];
    char a='_';
    char b= ' ';
    int x=0,y=0;

    FILE *NAMECUP =NULL;
    NAMECUP = fopen("NAMEWORLDCUP.txt","a+");

    if (!NAMECUP)
    {
        perror("fopen");
        return 0;
    }
    printf("\nSelect the save from the list below:");
    for (x=0; fgets(Check_Name_Team, 100, NAMECUP) != NULL;x++)
    {
        strcpy(Check_Name_Team,strtok(Check_Name_Team,"\n"));

        for(int i = 0 ; Check_Name_Team[i] ; i++)
            if(Check_Name_Team[i] == a)
                Check_Name_Team[i] = b;
        printf("\n%d- %s",x+1,Check_Name_Team);
    }
    printf("\nEnter a number: ");
    scanf("%d",&y);
    NAMECUP= NULL;
    for (x=0; x<y;x++)
    {
        fgets(Check_Name_Team, 100, NAMECUP);
        strcpy(Check_Name_Team,strtok(Check_Name_Team,"\n"));

        for(int i = 0 ; Check_Name_Team[i] ; i++)
            if(Check_Name_Team[i] == b)
                Check_Name_Team[i] = a;

        strcpy(WorldCup_Name,Check_Name_Team);
    }
    fclose(NAMECUP);
    INPUT1();
    return Next_Games(0);
}

int Next_Games(int n)
{
    system("clear");
    if(state == 1)
    {
        int d1=0, d2=0, d3=0, d4=0, ctf=0;
        for(int k=1; k<=4; k++)
        {
            for(int i=0; i<32; i++)
            {
                if(t[i].Group == t[User_Team-1].Group  && t[i].Team_Position == k)
                {
                    if(ctf==0)
                    {
                        d1 = i;
                    }
                    else if(ctf == 1)
                    {
                        d2 = i;
                    }
                    else if(ctf == 2)
                    {
                        d3 = i;
                    }
                    else if(ctf == 3)
                    {
                        d4 = i;

                        printf("\n%s vs %s",t[d1].Name,t[d3].Name);

                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d1,d2);
                            printf("\n%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                        printf("\n%s vs %s",t[d2].Name,t[d4].Name);
                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d3,d4);
                            printf("\n%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                    }
                    ctf++;
                    break;
                }
            }
        }
        Sort_Point(d1,d2,d3,d4);
        if(t[User_Team-1].Sort_Rank == 0)
            printf("\nYou don't have rank");
        else
            printf("\nYour rank is %d",t[User_Team-1].Sort_Rank);
        if(t[User_Team-1].Sort_Rank >2)
        {
            printf("Your team is defeated\nDo you want to continue?(Y/N)");
            char temp;
            scanf("%c",&temp);
            if(temp == 'N' || temp == 'n')
                return -100;
        }
        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }

    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(state == 2)
    {
        int d1=0, d2=0, d3=0, d4=0, ctf=0;
        for(int k=1; k<=4; k++)
        {
            for(int i=0; i<32; i++)
            {
                if(t[i].Group == t[User_Team-1].Group  && t[i].Team_Position == k)
                {
                    if(ctf==0)
                    {
                        d1 = i;
                    }
                    else if(ctf == 1)
                    {
                        d2 = i;
                    }
                    else if(ctf == 2)
                    {
                        d3 = i;
                    }
                    else if(ctf == 4)
                    {
                        d4 = i;
                        printf("%s vs %s\n",t[d1].Name,t[d3].Name);
                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d1,d3);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                        printf("%s vs %s\n",t[d2].Name,t[d4].Name);
                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d2,d4);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                    }
                    ctf++;
                    break;
                }
            }
        }
        Sort_Point(d1,d2,d3,d4);
        if(t[User_Team-1].Sort_Rank == 0)
            printf("\nYou don't have rank");
        else
            printf("\nYour rank is %d",t[User_Team-1].Sort_Rank);
        if(t[User_Team-1].Sort_Rank >2)
        {
            printf("Your team is defeated\nDo you want to continue?(Y/N)");
            char temp;
            scanf("%c",&temp);
            if(temp == 'N' || temp == 'n')
            {
                return -100;
            }
        }
        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if(state == 3)
    {
        int d1=0, d2=0,d3 =0, d4=0,ctf=0;
        for(int k=1; k<=4; k++)
        {
            for(int i=0; i<32; i++)
            {
                if(t[i].Group == t[User_Team-1].Group  && t[i].Team_Position == k)
                {
                    if(ctf == 0)
                        d1 = i;
                    else if(ctf == 1)
                        d2 = i;
                    else if(ctf == 2)
                        d3 = i;
                    else if(ctf == 3)
                    {
                        d4 = i;
                        printf("%s vs %s\n",t[d1].Name,t[d4].Name);
                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d1,d4);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                        printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                        if(n != 0)
                        {
                            resualt[d1][d2] = Fight(d2,d3);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/1000].Name,(resualt[d1][d2]-resualt[d1][d2]/10)/10,(resualt[d1][d2]-resualt[d1][d2]/10)%10,t[(resualt[d1][d2]/100)%10]);
                        }
                        ctf = 0;
                    }
                    ctf++;
                    break;
                }
            }
        }
        int temp_user = Sort_Point(d1,d2,d3,d4);
/*
        Winner[1][t[User_Team-1].Group-64][state] = temp_winner/1000;
        Winner[2][t[User_Team-1].Group-64][state] = (temp_winner/100)%10;
*/
        t[(temp_user%100)/10].Defeated = 1;
        t[((temp_user%100)%10)].Defeated =1;

        if(t[User_Team-1].Sort_Rank == 0)
            printf("\nYou don't have rank");
        else
            printf("\nYour rank is %d",t[User_Team-1].Sort_Rank);
        if(t[User_Team-1].Sort_Rank >2)
        {
            printf("Your team is defeated\nDo you want to continue?(Y/N)");
            char temp;
            scanf("%c",&temp);
            if(temp == 'N' || temp == 'n')
            {
                return -100;
            }
        }
        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(state == 4)    /////// 1/8
    {


        if(t[User_Team-1].Defeated == 1)
            printf("Your team is defeated");
        else
            printf("Your team is in game");

        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(state == 5)     ////////////   1/4
    {
        int Ra[9][3];
        for(int k=1; k<=8; k++)
        {
            for(int i=0; i<32; i++)
            {
                if (t[i].Group == k+64 && t[i].Team_Position == 1)
                    Ra[k][1] = i;
                if (t[i].Group == k+64 && t[i].Team_Position == 2)
                    Ra[k][2] = i;
            }
        }
        printf("%s vs %s",t[Ra[1][1]].Name,t[Ra[2][2]].Name);
        printf("%s vs %s",t[Ra[3][1]].Name,t[Ra[4][2]].Name);
        printf("%s vs %s",t[Ra[2][1]].Name,t[Ra[1][2]].Name);
        printf("%s vs %s",t[Ra[4][1]].Name,t[Ra[3][2]].Name);
        printf("%s vs %s",t[Ra[5][1]].Name,t[Ra[6][2]].Name);
        printf("%s vs %s",t[Ra[6][1]].Name,t[Ra[8][2]].Name);
        printf("%s vs %s",t[Ra[7][1]].Name,t[Ra[5][2]].Name);
        printf("%s vs %s",t[Ra[8][1]].Name,t[Ra[7][2]].Name);


        if(t[User_Team-1].Defeated == 1)
            printf("Your team is defeated");
        else
            printf("Your team is in game");
        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(state == 6)     /////////    Semi-Final
    {
        int Ra[9][3];
        for(int k=1; k<=8; k++)
        {
            for(int i=0; i<32; i++)
            {
                if (t[i].Group == k+64 && t[i].Team_Position == 1)
                    Ra[k][1] = i;
                if (t[i].Group == k+64 && t[i].Team_Position == 2)
                    Ra[k][2] = i;
            }
        }
        printf("%s vs %s",t[Ra[1][1]].Name,t[Ra[2][2]].Name);
        printf("%s vs %s",t[Ra[3][1]].Name,t[Ra[4][2]].Name);
        printf("%s vs %s",t[Ra[2][1]].Name,t[Ra[1][2]].Name);
        printf("%s vs %s",t[Ra[4][1]].Name,t[Ra[3][2]].Name);
        printf("%s vs %s",t[Ra[5][1]].Name,t[Ra[6][2]].Name);
        printf("%s vs %s",t[Ra[6][1]].Name,t[Ra[8][2]].Name);
        printf("%s vs %s",t[Ra[7][1]].Name,t[Ra[5][2]].Name);
        printf("%s vs %s",t[Ra[8][1]].Name,t[Ra[7][2]].Name);

        if(t[User_Team-1].Defeated == 1)
            printf("Your team is defeated");
        else
            printf("Your team is in game");

        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else                 ////////////    Final + Ranking Match
    {
        int Ra[9][3];
        for(int k=1; k<=8; k++)
        {
            for(int i=0; i<32; i++)
            {
                if (t[i].Group == k+64 && t[i].Team_Position == 1)
                    Ra[k][1] = i;
                if (t[i].Group == k+64 && t[i].Team_Position == 2)
                    Ra[k][2] = i;
            }
        }
        printf("%s vs %s",t[Ra[1][1]].Name,t[Ra[2][2]].Name);
        printf("%s vs %s",t[Ra[3][1]].Name,t[Ra[4][2]].Name);
        printf("%s vs %s",t[Ra[2][1]].Name,t[Ra[1][2]].Name);
        printf("%s vs %s",t[Ra[4][1]].Name,t[Ra[3][2]].Name);
        printf("%s vs %s",t[Ra[5][1]].Name,t[Ra[6][2]].Name);
        printf("%s vs %s",t[Ra[6][1]].Name,t[Ra[8][2]].Name);
        printf("%s vs %s",t[Ra[7][1]].Name,t[Ra[5][2]].Name);
        printf("%s vs %s",t[Ra[8][1]].Name,t[Ra[7][2]].Name);

        if(t[User_Team-1].Defeated == 1)
            printf("Your team is defeated");
        else
            printf("Your team is in game");

        if(n != 0)
        {
            n--;
            printf("\n1- Next");
            int select = 0;
            while(1>0)
            {
                scanf("%d",&select);
                if(select == 1)
                {
                    n--;
                    break;
                }
                else
                {
                    printf("\nEntery is not valid\nTry again");
                    delay();
                    system("clear");
                }
            }
        }
    }
    if(n != 0)
        state ++;
}

int INPUT(void)
{
    bool check1 = 0;
    char Filename[50];
    FILE *NAMEFILES1 = NULL;
    NAMEFILES1 = fopen("NAMEFILES.txt","r+");
    while (fgets(Filename,50,NAMEFILES1) != NULL) {
        strcpy(Filename,strtok(Filename,"\n"));
        if (strcmp("Teams",Filename) == 0) {
            check1 = 1;
        }
    }

    if (check1 == 0)
    {
        system("wget http://bayanbox.ir/download/1666325627207554780/Teams.zip");
        system("unzip Teams.zip");
        fprintf(NAMEFILES1,"%s\n","Teams");
        system("clear");
    }
    fclose(NAMEFILES1);
    for(int i=0; i<32;i++)
    {
        t[i].Enrollment=0;
    }

    for(int i=0; i<32;i++)
    {
        t[i].Team_Rate = 0;
        t[i].Number_Win= 0;
        t[i].Number_Lose= 0;
        t[i].Number_Equal= 0;
        t[i].Goal_S= 0;
        t[i].Goal_R= 0;
        t[i].Goal_M= 0;
        t[i].Sort_Rank=0;
        for(int j=0;j<t[i].Enrollment;j++)
        {
            t[i].p[j].Skill=0;
            t[i].p[j].Fitness=0;
            t[i].p[j].Form=0;
            t[i].p[j].Condition=0;
            t[i].p[j].Player_Post_New='-';
        }
    }

    char address[50]={0};
    FILE *team = fopen("Teams/Teams.csv", "r");
    if (!team) {
        perror("fopen");
        return 0;
    }
    char nameteam[50];
    int i = 0;
    while (fgets(nameteam, 50, team) != NULL)
    {
        const char s[2] = ",";
        char *token;



        token = strtok(nameteam, s);
        strcpy(t[i].Name,token);
        token = strtok(NULL, s);
        t[i].Group=*token;
        token = strtok(NULL, s);
        t[i].Team_Position=*token-48;
        token = strtok(NULL, s);
        strcpy(t[i].Fedrasion,token);
        token = strtok(NULL, s);
        t[i].seed=*token-48;
        token = strtok(NULL, s);
        strcpy(t[i].NAMEFILE,token);
        i++;
    }
    fclose(team);
    for(i=0;i<32;i++)
    {
        strcpy(address,"Teams/");
        strcat(address,t[i].NAMEFILE);
        char *s1=NULL;
        s1 = strtok(address,"\n");
        FILE *player = fopen(s1,"r");
        if (!player)
        {
            perror("fopen");
            return 0;
        }
        ///////////////
        char nameplayer[70];

        int j = 0;
        while (fgets(nameplayer,70,player) != NULL)
        {
            const char s[2] = ",";
            char *token;
            int Number,age;
            token = strtok(nameplayer,s);
            sscanf(token, "%d",  &Number);
            t[i].p[j].Player_Number = Number;
            token = strtok(NULL,s);
            strcpy(t[i].p[j].Name,token);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &age);
            t[i].p[j].Player_Age = age;
            token = strtok(NULL,s);
            t[i].p[j].Player_Post=*token;
            j++;
        }
        t[i].Enrollment=j;
        fclose(player);
    }
    srand (time(NULL));
    for(int n=0;n<32;n++)
    {
        for( int i = 0 ; i < t[n].Enrollment ; i++ ) {
            t[n].p[i].Skill = (rand() %100)+1;
            t[n].p[i].Fitness =(rand() %100)+1;
            t[n].p[i].Form = (rand() %100)+1;
        }
    }
    s_rand();
}
int INPUT1(void)
{
    char address[100]={0};
    char Location[100]={};
    strcpy(address,"SAVE/");
    strcat(address,WorldCup_Name);
    strcat(Location,"/Teams.csv");
    FILE *team = fopen(Location, "r");
    if (!team) {
        perror("fopen");
        return 0;
    }
    char nameteam[50];
    int i = 0;
    while (fgets(nameteam, 50, team) != NULL)
    {
        const char s[2] = ",";
        char *token;

        token = strtok(nameteam, s);
        strcpy(t[i].Name,token);
        token = strtok(NULL, s);
        t[i].Group=*token;
        token = strtok(NULL, s);
        t[i].Team_Position=*token-48;
        token = strtok(NULL, s);
        strcpy(t[i].Fedrasion,token);
        token = strtok(NULL, s);
        t[i].seed=*token-48;
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Team_Rate);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Number_Win);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Number_Lose);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Number_Equal);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Goal_S);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Goal_R);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Goal_M);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Enrollment);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].System);
        token = strtok(NULL, s);
        sscanf(token, "%d",  &t[i].Sort_Rank);
        token = strtok(NULL, s);
        strcpy(t[i].NAMEFILE,token);

        i++;
    }
    state = t[32].Team_Position;
    fclose(team);
    for(i=0;i<32;i++)
    {
        strcpy(address,"/");
        strcat(address,t[i].NAMEFILE);
        char *s1=NULL;
        s1 = strtok(address,"\n");
        FILE *player = fopen(s1,"r");
        if (!player)
        {
            perror("fopen");
            return 0;
        }
        ///////////////
        char nameplayer[70];

        int j = 0;
        while (fgets(nameplayer,70,player) != NULL)
        {
            const char s[2] = ",";
            char *token;
            int Number,age;
            token = strtok(nameplayer,s);
            sscanf(token, "%d",  &t[i].p[j].Player_Number);
            token = strtok(NULL,s);
            strcpy(t[i].p[j].Name,token);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Player_Age);
            token = strtok(NULL,s);
            t[i].p[j].Player_Post=*token;
            t[i].p[j].Player_Post_New=*token;
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Skill);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Fitness);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Form);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Condition);

            j++;
        }
        t[i].Enrollment=j;
        fclose(player);
    }

}
int OUTPUT(void)
{
    char a=' ';
    char b= '_';
    char Address_Worldcup_Name[100] = {};
    char Filename[50];
    bool check1 = 0;
    for(int i = 0 ; WorldCup_Name[i] ; i++)
        if(WorldCup_Name[i] == a)
            WorldCup_Name[i] = b;
    FILE *NAMECUP=NULL;
    NAMECUP=fopen("NAMEWORLDCUP.txt","a");
    fprintf(NAMECUP,"%s\n",WorldCup_Name);
    fclose(NAMECUP);

    t[32].Team_Position= state;

    FILE *NAMEFILES1 = NULL;
    NAMEFILES1 = fopen("NAMEFILES.txt","r");
    while (fgets(Filename,50,NAMEFILES1) != NULL) {
        strcpy(Filename,strtok(Filename,"\n"));
        if (strcmp("SAVE",Filename) == 0) {
            check1 = 1;
        }
    }

    if (check1 == 0)
    {
        system("mkdir SAVE");
        NAMEFILES1 = fopen("NAMEFILES.txt","a");
        fprintf(NAMEFILES1,"%s\n","SAVE");
    }
    fclose(NAMEFILES1);

    strcpy(Address_Worldcup_Name,"mkdir SAVE/");
    strcat(Address_Worldcup_Name,WorldCup_Name);
    strcat(Address_Worldcup_Name,"/");
    system(Address_Worldcup_Name);

    char address1[200]={0};
    strcpy(address1,"SAVE/");
    strcat(address1,WorldCup_Name);
    strcat(address1,"/Teams.csv");
    FILE *team=NULL;
    team = fopen(address1,"w");
    for(int i=0;i<33;i++)
    {
        fprintf(team, "%s,%c,%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s", t[i].Name, t[i].Group, t[i].Team_Position,t[i].Fedrasion,t[i].seed,t[i].Team_Rate,t[i].Number_Win,t[i].Number_Lose,t[i].Number_Equal,t[i].Goal_S,t[i].Goal_R,t[i].Goal_M,t[i].Enrollment,t[i].Sort_Rank,t[i].System,t[i].NAMEFILE);
    }
    fclose(team);
    char address3[100]={};
    for(int i=0;i<32;i++)
    {
        strcpy(address3,"SAVE/");
        strcat(address3,WorldCup_Name);
        strcat(address3,"/");
        strcat(address3,t[i].NAMEFILE);
        FILE *player =NULL;
        player = fopen(address3,"w");
        for (int j = 0; j <+ t[i].Enrollment; j++)
        {
            fprintf(player, "%d,%s,%d,%c,%c,%d,%d,%d,%d\n", t[i].p[j].Player_Number, t[i].p[j].Name, t[i].p[j].Player_Age,t[i].p[j].Player_Post,t[i].p[j].Player_Post_New,t[i].p[j].Skill,t[i].p[j].Fitness,t[i].p[j].Form,t[i].p[j].Condition);
        }
        fclose(player);
    }

}
int Get_Worldcup_Name(void)
{
    char Check_Name_Team[100];
    char a=' ';
    char b= '_';
    printf("\nEnter a username for your WorldCup:");
    if (check==0)
    {
        fgets (WorldCup_Name,100,stdin);
        check=1;
    }
    scanf ("%[^\n]%*c", WorldCup_Name);
    FILE *NAMECUP =NULL;
    NAMECUP = fopen("NAMEWORLDCUP.txt","a+");

    if (!NAMECUP)
    {
        perror("fopen");
        return 0;
    }

    while (fgets(Check_Name_Team, 100, NAMECUP) != NULL)
    {
        strcpy(Check_Name_Team,strtok(Check_Name_Team,"\n"));

        for(int i = 0 ; WorldCup_Name[i] ; i++)
            if(WorldCup_Name[i] == a)
                WorldCup_Name[i] = b;
        if(strcmp(WorldCup_Name,Check_Name_Team)==0)
        {
            printf("\nThis username exists. Please enter another username.");
            fclose(NAMECUP);
            NAMECUP = NULL;
            return Get_Worldcup_Name();
        }
        if(fgets(Check_Name_Team, 100, NAMECUP) == NULL)
            return 0;

    }

}
void Select_Post_Player(void)
{
    int i=0,j=0,x=0;

    printf("\nSelect player first for changes post : ");

    while(scanf("%d",&i))
    {
        if(i>0 && i<=t[User_Team-1].Enrollment)
            break;
        else
            printf( "The selection there is not between player, please select true item!\n" );
    }

    printf("\nSelect player second for changes post : ");
    if(t[User_Team-1].p[i-1].Condition ==0)
    {
        while (scanf("%d",&j)) {
            if (j > 0 && j <= t[User_Team - 1].Enrollment && j != i && t[User_Team -1].p[j - 1].Condition != 0)
                break;
            else
                printf("The selection there is not between player or selection equal with first selection or Both players are in deactive , please select true item!\n");
        }
    }
    else
    {
        while (scanf("%d",&j)) {
            if (j > 0 && j <= t[User_Team - 1].Enrollment && j != i )
                break;
            else
                printf("The selection there is not between player or selection equal with first selection , please select true item!\n");
        }
    }

    if(t[User_Team-1].p[i-1].Condition ==1 && t[User_Team-1].p[j-1].Condition ==1)
    {
        t[User_Team-1].p[j-1].Player_Post_New = t[User_Team-1].p[i-1].Player_Post;
        t[User_Team-1].p[i-1].Player_Post_New = t[User_Team-1].p[j-1].Player_Post;
    }
    else if(t[User_Team-1].p[i-1].Condition ==1 && t[User_Team-1].p[j-1].Condition ==0)
    {
        t[User_Team-1].p[j-1].Player_Post_New = t[User_Team-1].p[i-1].Player_Post;
        t[User_Team-1].p[i-1].Player_Post_New = '-';
        t[User_Team-1].p[i-1].Condition=0;
        t[User_Team-1].p[j-1].Condition=1;
    }
    else if(t[User_Team-1].p[i-1].Condition ==0 && t[User_Team-1].p[j-1].Condition ==1)
    {
        t[User_Team-1].p[i-1].Player_Post_New = t[User_Team-1].p[j-1].Player_Post;
        t[User_Team-1].p[j-1].Player_Post_New = '-';
        t[User_Team-1].p[j-1].Condition=0;
        t[User_Team-1].p[i-1].Condition=1;
    }
    system("clear");
    Show_Team();
    printf("\n 1- Continue Changes\n");
    printf(" 2- Back\n   -->");

    while(scanf("%d",&x))
    {
        if(x>0&&x<=2)
            break;
        else
            printf( "The selection there is not between options, please select true item!\n" );
    }
    switch(x)
    {
        case 1:
            Select_Post_Player();
        default :
            system("clear");
            Lineup();
    }
}
void Change_System(void)
{
    int x= 0;
    printf("\nPlease select a system for your team :");
    printf("\n1-  5-4-1");
    printf("\n2-  4-2-2");
    printf("\n3-  4-3-3");
    while(scanf("%d",&x))
    {
        if(x>0&&x<=3)
            break;
        else
            printf( "The selection there is not between options, please select true item!\n" );
    }

    switch(x)
    {
        case 1 :
            t[User_Team].System = 0;
        case 2 :
            t[User_Team].System = 1;
        default :
            t[User_Team].System = 2;
    }
    system("clear");
    printf("                                                  --> System your team change <--");
    Lineup();
//    return 0;
}
int Lineup(void)
{
    int x=0;
    Show_Team();
    printf("Select item :");
    printf("\n1-Select post player");
    printf("\n2-Change system");
    printf("\n3-Save");
    printf("\n4-Back\n");
    while(scanf("%d",&x))
    {
        if(x>0&&x<=4)
            break;
        else
            printf( "The selection there is not between options, please select true item!\n" );
    }
    switch (x)
    {
        case 1:
            Select_Post_Player();
            return Lineup();
        case 2:
            Change_System();
            return Lineup();
        case 3:
            OUTPUT();
            system("clear");
            printf("                                    --> SAVE DONE <--");
        default:
            return 0;
    }
}
void Show_Team(void)
{
    printf("              Information your team\n");
    printf("                        ||\n");
    printf("                        \\/\n");
    printf("Teams name :%s\n",t[User_Team - 1].Name);
    printf("=================================\n");
    printf("\n  The list of players in the main combination: \n");
    for (int i = 0; i < t[User_Team - 1].Enrollment; i++)
    {
        if(t[User_Team].p[i].Condition==1)
        {
            printf("%d- %s\n",i + 1,t[User_Team - 1].p[i].Name);
            printf("   Main player post : %c\n",t[User_Team - 1].p[i].Player_Post);
            printf("   New player post : %c\n",t[User_Team - 1].p[i].Player_Post_New);
            printf("   Player skill : %d\n",t[User_Team - 1].p[i].Skill);
            printf("   Player fitness : %d\n",t[User_Team - 1].p[i].Fitness);
            printf("   Player form : %d\n",t[User_Team - 1].p[i].Form);

            printf("----------------------------------\n\n");
        }
        else
            continue;
    }
    printf("\n  The list of players in the non-original combination: \n");
    for (int i = 0; i < t[User_Team - 1].Enrollment; i++)
    {
        if(t[User_Team].p[i].Condition==1)
        {
            printf("%d- %s\n",i + 1,t[User_Team - 1].p[i].Name);
            printf("   Main player post : %c\n",t[User_Team - 1].p[i].Player_Post);
            printf("   New player post :  %c\n",t[User_Team - 1].p[i].Player_Post_New);
            printf("   Player skill : %d\n",t[User_Team - 1].p[i].Skill);
            printf("   Player fitness : %d\n",t[User_Team - 1].p[i].Fitness);
            printf("   Player form : %d\n",t[User_Team - 1].p[i].Form);
            printf("----------------------------------\n");
        }
        else
            continue;
    }
}


int Fight(int First,int Second)
{

}

int Processed_n()
{

}

int Sort_Point(int d1, int d2, int d3, int d4)
{
    if(t[d4].Number_Win*3+t[d4].Number_Equal >= t[d3].Number_Win*3+t[d3].Number_Equal)
    {
        if(t[d3].Number_Win*3+t[d3].Number_Equal >=t[d2].Number_Win*3+t[d2].Number_Equal)
        {
            if(t[d2].Number_Win*3+t[d2].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 1;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 3;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d3*100 + d2*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 1;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 4;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d3*100 + d1*10 + d2;
            }
        }
        else
        {
            if(t[d3].Number_Win*3+t[d3].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 1;
                t[d3].Sort_Rank = 3;
                t[d2].Sort_Rank = 2;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d2*100 + d3*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 1;
                t[d3].Sort_Rank = 4;
                t[d2].Sort_Rank = 2;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d2*100 + d1*10 + d3;
            }
        }
    }
    else if(t[d3].Number_Win*3+t[d3].Number_Equal >= t[d4].Number_Win*3+t[d4].Number_Equal)
    {
        if(t[d4].Number_Win*3+t[d4].Number_Equal >=t[d2].Number_Win*3+t[d2].Number_Equal)
        {
            if(t[d2].Number_Win*3+t[d2].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 1;
                t[d2].Sort_Rank = 3;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d3*100 + d2*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 1;
                t[d2].Sort_Rank = 4;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d3*100 + d1*10 + d2;
            }
        }
        else
        {
            if(t[d4].Number_Win*3+t[d4].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 3;
                t[d3].Sort_Rank = 1;
                t[d2].Sort_Rank = 2;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d2*100 + d3*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 4;
                t[d3].Sort_Rank = 1;
                t[d2].Sort_Rank = 2;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d2*100 + d1*10 + d3;
            }
        }
    }
    else if(t[d2].Number_Win*3+t[d2].Number_Equal >= t[d4].Number_Win*3+t[d4].Number_Equal)
    {
        if(t[d4].Number_Win*3+t[d4].Number_Equal >=t[d3].Number_Win*3+t[d3].Number_Equal)
        {
            if(t[d3].Number_Win*3+t[d3].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 3;
                t[d2].Sort_Rank = 1;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d3*100 + d2*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 4;
                t[d2].Sort_Rank = 1;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d3*100 + d1*10 + d2;
            }
        }
        else
        {
            if(t[d4].Number_Win*3+t[d4].Number_Equal >= t[d1].Number_Win*3+t[d1].Number_Equal)
            {
                t[d4].Sort_Rank = 3;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 1;
                t[d1].Sort_Rank = 4;
                return d4*1000 + d2*100 + d3*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 4;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 1;
                t[d1].Sort_Rank = 3;
                return d4*1000 + d2*100 + d1*10 + d3;
            }
        }
    }
    else ///t[d1].Number_Win*3+t[d1].Number_Equal >= t[d4].Number_Win*3+t[d4].Number_Equal
    {
        if(t[d4].Number_Win*3+t[d4].Number_Equal >=t[d3].Number_Win*3+t[d3].Number_Equal)
        {
            if(t[d3].Number_Win*3+t[d3].Number_Equal >= t[d2].Number_Win*3+t[d2].Number_Equal)
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 3;
                t[d2].Sort_Rank = 4;
                t[d1].Sort_Rank = 1;
                return d4*1000 + d3*100 + d2*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 2;
                t[d3].Sort_Rank = 4;
                t[d2].Sort_Rank = 3;
                t[d1].Sort_Rank = 1;
                return d4*1000 + d3*100 + d1*10 + d2;
            }
        }
        else
        {
            if(t[d4].Number_Win*3+t[d4].Number_Equal >= t[d2].Number_Win*3+t[d2].Number_Equal)
            {
                t[d4].Sort_Rank = 3;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 4;
                t[d1].Sort_Rank = 1;
                return d4*1000 + d2*100 + d3*10 + d1;
            }
            else
            {
                t[d4].Sort_Rank = 4;
                t[d3].Sort_Rank = 2;
                t[d2].Sort_Rank = 3;
                t[d1].Sort_Rank = 1;
                return d4*1000 + d2*100 + d1*10 + d3;
            }
        }
    }
}
void s_rand(void)  //// May Bug in Some Compilers
{
    srand (time(NULL));
    int counter1=0, counter2=0, counter3=0, counter4=0;
    for(int i=0; i<32; i++)
    {
        t[i].System = rand() %3;
        if(t[i].System == 0) /// 5-4-1
        {
            for(int j=0;j<t[i].Enrollment; j++)
            {
                if(t[i].p[j].Player_Post == 'D' && counter1<=5)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<=4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<=1)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<=1)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'G';
                    counter4++;
                }
            }
        }
        else if(t[i].System == 1)  /// 4-4-2
        {
            counter1=0, counter2=0, counter3=0, counter4=0;
            for(int j=0;j<t[i].Enrollment; j++)
            {
                if(t[i].p[j].Player_Post == 'D' && counter1<=4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<=4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<=2)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<=1)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'G';
                    counter4++;
                }
            }
        }
        else  /// 4-3-3
        {
            counter1=0, counter2=0, counter3=0, counter4=0;
            for(int j=0;j<t[i].Enrollment; j++)
            {
                if(t[i].p[j].Player_Post == 'D' && counter1<=4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<=3)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<=3)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<=1)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'G';
                    counter4++;
                }
            }
        }
    }
}

int delay()
{
    for(int i=0; i<33000; i++)
    {
        for(int j=0; j<33000; j++)
        {

        }
    }
}
