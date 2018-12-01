#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <shadow.h>

int zz = -10;
long long int resualt[35][35] ;
int User_Team = 10;
char WorldCup_Name[100];
int state = 1;
int check = 0;
/// Age Naboode ghablan Save Dar File Ba Hamin Esm ha  ///////////////////////////////////////////////////
int temp_ai[10];
int w1=0,w2=0,w3=0,w4=0,w5=0,w6=0,w7=0,w8=0,l61=0,l62=0,w61=0,w62=0,w57=0,w58=0,w59=0,w60=0;

bool Amin_bool = 0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
int Fight_Penalty(int i,int j);
int A_Power(int i);
int D_Power(int i);
int G_Power(int i);
int M_Power(int i);
int Fight(int i,int j);

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
int menu(void);
int Table(void);
void s_rand(void);
//int stdcmp(struct Teams x, struct Teams y, enum field f);
//void stdsort(struct Teams t[], int len, enum field f);
/*
enum field {
    Name,
    Group,
    Team_Position,
    Fedrasion,
    seed,
    Team_Rate,
    Number_Win,
    Number_Lose,
    Number_Equal,
    Goal_S,
    Goal_R,
    Goal_M,
    Enrollment,
    System,
    Sort_Rank,
};
*/
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
//struct Teams tmp1[32] ={} ;

int main()
{

    if(zz == 5)
        return -100;
//    int User_Team = 10;
    int exit_game = 20;
    int select_start = Start();

    for(int i=0;i<35;i++)
    {
        for(int j=0;j<35;j++)
        {
            resualt[i][j]=-10;
        }
    }

    if(select_start == 1)
        exit_game = New_Game();
    else if(select_start == 2)
        exit_game = Saved_Games();
    else
    {
        printf("Have Fun :)\n");
        return 0;
    }
    if(exit_game != 20)
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

int menu(void)
{
    system("clear");
    int f=0;
    int n=0;
    system("clear");
    printf("\nSelect item :");
    printf("\n1- lineup");
    printf("\n2- proceed");
    printf("\n3- table");
    printf("\n4- save");
    printf("\n5- exit\n");
    while(scanf("%d",&n))
    {
        if(n>0 && n<=5)
            break;
        else
            printf( "The selection there is not between item, please select true item!\n" );
    }
    switch(n)
    {
        case 1:
            Lineup();
        case 2:

            printf("\nPlease enter n:\n");
            while(scanf("%d",&f))
            {
                if(f+state>=1 && f+state<= 7)
                    break;
                else
                    printf( "The number there is not between 1-7, please select true number!\n" );
            }
            Next_Games(f);
        case 3:
            Table();
        case 4:
            OUTPUT();
            system("clear");
            printf("                                    --> SAVE DONE <--");
            menu();

        default:
            zz = 5;
            main();

    }
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
    printf("\nSelect your team:\nNote: Enter a number between 1 and 32\n");
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
    while(scanf("%d",&y))
    {
        if(y>0 && y<=x)
            break;
        else
            printf( "The selection there is not between options, please select true item!\n" );
    }


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

        Sort_Point(d1,d2,d3,d4);
        if(n == 0)
        {
            if(t[User_Team-1].Sort_Rank == 0)
                printf("\nStatus: You don't have rank yet");
            else if(t[User_Team-1].Sort_Rank >2)
            {
                printf("Your team is defeated\nDo you want to continue?(Y/N)");
                char temp;
                scanf("%c",&temp);
                if(temp == 'N' || temp == 'n')
                    return -100;
            }
        }



            for(int k=1; k<=4; k++)
            {
                for(int i=0; i<32; i++)
                {
                    if(t[i].Group == t[User_Team-1].Group  && t[i].Team_Position == k)
                    {
                        if(ctf==0)
                            d1 = i;
                        else if(ctf == 1)
                            d2 = i;
                        else if(ctf == 2)
                            d3 = i;
                        else if(ctf == 3)
                        {
                            d4 = i;

                            printf("\n%s vs %s",t[d1].Name,t[d3].Name);
                            if(n != 0)
                            {
                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %lld : %lld %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%10]);
                            }

                            printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                            if(n != 0)
                            {
                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %lld : %lld %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%10]);
                            }
                        }
                        ctf++;
                        break;
                    }
                }
            }
        if(n!=0)
        {
            for(int g=0;g<7;g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == g+65 && t[i].Group != t[User_Team -1].Group  && t[i].Team_Position == k)
                        {
                            if(ctf==0)
                                d1 = i;
                            else if(ctf == 1)
                                d2 = i;
                            else if(ctf == 2)
                                d3 = i;
                            else if(ctf == 3)
                            {
                                d4 = i;

                                printf("\n%s vs %s",t[d1].Name,t[d3].Name);
                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %lld : %lld %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%10]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %lld : %lld %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%10]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }
        }

            if(n != 0)
            {
                printf("\n1- Next\n");
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
            else
            {
                printf("\n1- Menu\n");
                int select = 0;
                while(1>0)
                {
                    scanf("%d",&select);
                    if(select == 1)
                    {
                        system("clear");
                        menu();
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
                        d1 = i;
                    else if(ctf == 1)
                        d2 = i;
                    else if(ctf == 2)
                        d3 = i;
                    else if(ctf == 4)
                    {
                        d4 = i;
                        printf("%s vs %s\n",t[d1].Name,t[d3].Name);
                        if(n != 0)
                        {
                            resualt[d1][d3] = Fight(d1,d3);
                            printf("%s %d : %d %s",t[resualt[d1][d3]/100000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%10]);
                        }
                        printf("%s vs %s\n",t[d2].Name,t[d4].Name);
                        if(n != 0)
                        {
                            resualt[d2][d4] = Fight(d2,d4);
                            printf("%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%10]);
                        }
                    }
                    ctf++;
                }
            }
        }
        Sort_Point(d1,d2,d3,d4);
        if(n == 0)
        {
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
        }

        if(n != 0)
        {
            for(int g=1; g<=7; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'A'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
                        {
                            if(ctf==0)
                                d1 = i;
                            else if(ctf == 1)
                                d2 = i;
                            else if(ctf == 2)
                                d3 = i;
                            else if(ctf == 3)
                            {
                                d4 = i;
                                printf("\n%s vs %s",t[d1].Name,t[d3].Name);

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'B'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);

                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'C'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'D'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'E'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'F'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'G'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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

                                resualt[d1][d3] = Fight(d1,d3);
                                printf("\n%s %d : %d %s",t[resualt[d1][d3]/10000].Name,(resualt[d1][d3]/10)%10,(resualt[d1][d3])%10,t[(resualt[d1][d3]/100)%100]);

                                printf("\n%s vs %s",t[d2].Name,t[d4].Name);

                                resualt[d2][d4] = Fight(d2,d4);
                                printf("\n%s %d : %d %s",t[resualt[d2][d4]/10000].Name,(resualt[d2][d4]/10)%10,(resualt[d2][d4])%10,t[(resualt[d2][d4]/100)%100]);
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }
            if(n != 0)
            {
                printf("\n1- Next\n");
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
            else
            {
                printf("\n1- Menu\n");
                int select = 0;
                while(1>0)
                {
                    scanf("%d",&select);
                    if(select == 1)
                    {
                        system("clear");
                        menu();
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
                            resualt[d1][d4] = Fight(d1,d4);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/10000].Name,(resualt[d1][d2]/10)%10,(resualt[d1][d2])%10,t[(resualt[d1][d2]/100)%100]);
                        }
                        printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                        if(n != 0)
                        {
                            resualt[d2][d3] = Fight(d2,d3);
                            printf("%s %d : %d %s",t[resualt[d1][d2]/10000].Name,(resualt[d1][d2]/10)%10,(resualt[d1][d2])%10,t[(resualt[d1][d2]/100)%100]);
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
        Winner[1][t[User_Team-1].Group-64][state] = temp_winner/10000;
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
            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'A' && t[i].Group != t[User_Team-1].Group   && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_1 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_1%100)/10].Defeated = 1;
            t[((temp_ai_1%100)%10)].Defeated =1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'B'  && t[i].Group != t[User_Team-1].Group&& t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_2 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_2%100)/10].Defeated = 1;
            t[((temp_ai_2%100)%10)].Defeated =1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'C'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_3 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_3%100)/10].Defeated = 1;
            t[((temp_ai_3%100)%10)].Defeated =1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'D'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_4 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_4%100)/10].Defeated = 1;
            t[(temp_ai_4&100)/10].Defeated = 1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'E'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_5 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_5%100)/10].Defeated = 1;
            t[(temp_ai_5&100)/10].Defeated = 1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'F'  && t[i].Group != t[User_Team-1].Group&& t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_6 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_6%100)/10].Defeated = 1;
            t[(temp_ai_6&100)/10].Defeated = 1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'G'&& t[i].Group != t[User_Team-1].Group  && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_7 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_7%100)/10].Defeated = 1;
            t[(temp_ai_7&100)/10].Defeated = 1;

            for(int g=1; g<=8; g++)
            {
                for(int k=1; k<=4; k++)
                {
                    for(int i=0; i<32; i++)
                    {
                        if(t[i].Group == 'H' && t[i].Group != t[User_Team-1].Group && t[i].Team_Position == k)
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
                                    resualt[d1][d4] = Fight(d1,d4);
                                    printf("%s %d : %d %s",t[resualt[d1][d4]/10000].Name,(resualt[d1][d4]/10)%10,(resualt[d1][d4])%10,t[(resualt[d1][d4]/100)%100]);
                                }
                                printf("%s vs %s\n",t[d2].Name,t[d3].Name);
                                if(n != 0)
                                {
                                    resualt[d2][d3] = Fight(d2,d3);
                                    printf("%s %d : %d %s",t[resualt[d2][d3]/10000].Name,(resualt[d2][d3]/10)%10,(resualt[d2][d3])%10,t[(resualt[d2][d3]/100)%100]);
                                }
                                ctf = 0;
                            }
                            ctf++;
                            break;
                        }
                    }
                }
            }

            int temp_ai_8 = Sort_Point(d1,d2,d3,d4);
            t[(temp_ai_8%100)/10].Defeated = 1;
            t[(temp_ai_8&100)/10].Defeated = 1;

            temp_ai[1] = temp_ai_1;
            temp_ai[2] = temp_ai_2;
            temp_ai[3] = temp_ai_3;
            temp_ai[4] = temp_ai_4;
            temp_ai[5] = temp_ai_5;
            temp_ai[6] = temp_ai_6;
            temp_ai[7] = temp_ai_7;
            temp_ai[8] = temp_ai_8;
            if(n != 0)
            {
                printf("\n1- Next\n");
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
            else
            {
                printf("\n1- Menu\n");
                int select = 0;
                while(1>0)
                {
                    scanf("%d",&select);
                    if(select == 1)
                    {
                        system("clear");
                        menu();
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
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(state == 4)    /////// 1/8
    {
        int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,d1=0,d2=0,e1=0,e2=0,f1=0,f2=0,g1=0,g2=0,h1=0,h2=0;

        for(int m=1;m<=8;m++)
        {
            if(t[temp_ai[m]/10000].Group == 'A')
                a1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'B')
                b1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'C')
                c1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'D')
                d1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'E')
                e1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'F')
                f1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'G')
                g1 == temp_ai[m]/1000;
            else if(t[temp_ai[m]/1000].Group == 'H')
                h1 == temp_ai[m]/1000;

            if(t[temp_ai[m]/1000].Group == 'A')
                a2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'B')
                b2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'C')
                c2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'D')
                d2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'E')
                e2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'F')
                f2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'G')
                g2 == (temp_ai[m]/100)%10;
            else if(t[temp_ai[m]/1000].Group == 'H')
                h2 == (temp_ai[m]/100)%10;
        }

        printf("\n%s VS %s",t[a1].Name,t[b2].Name);
        if(n!=0)
        {
            resualt[a1][b2] = Fight(a1,b2);
            printf("\n%s %d : %d %s",t[resualt[a1][b2]/10000].Name,(resualt[a1][b2]-resualt[a1][b2]/10)/10,(resualt[a1][b2]-resualt[a1][b2]/10)%10,t[(resualt[a1][b2]/100)%10]);
            t[(resualt[a1][b2]/100)%10].Defeated = 1;
            w1 = resualt[a1][b2]/10000;
        }
        printf("\n%s VS %s",t[c1].Name,t[d2].Name);
        if(n!=0)
        {
            resualt[c1][d2] = Fight(c1,d2);
            printf("\n%s %d : %d %s",t[resualt[c1][d2]/10000].Name,(resualt[c1][d2]-resualt[c1][d2]/10)/10,(resualt[c1][d2]-resualt[c1][d2]/10)%10,t[(resualt[c1][d2]/100)%10]);
            t[(resualt[c1][d2]/100)%10].Defeated = 1;
            w2 = resualt[c1][d2]/10000;
        }
        printf("\n%s VS %s",t[b1].Name,t[a2].Name);
        if(n!=0)
        {
            resualt[b1][a2] = Fight(b1,a2);
            printf("\n%s %d : %d %s",t[resualt[b1][a2]/10000].Name,(resualt[b1][a2]-resualt[b1][a2]/10)/10,(resualt[b1][a2]-resualt[b1][a2]/10)%10,t[(resualt[b1][a2]/100)%10]);
            t[(resualt[b1][a2]/100)%10].Defeated = 1;
            w3 = resualt[b1][a2]/10000;
        }
        printf("\n%s VS %s",t[d1].Name,t[c2].Name);
        if(n!=0)
        {
            resualt[d1][c2] = Fight(d1,c2);
            printf("\n%s %d : %d %s",t[resualt[d1][c2]/10000].Name,(resualt[d1][c2]-resualt[d1][c2]/10)/10,(resualt[d1][c2]-resualt[d1][c2]/10)%10,t[(resualt[d1][c2]/100)%10]);
            t[(resualt[d1][c2]/100)%10].Defeated = 1;
            w4 = resualt[d1][c2]/10000;
        }
        printf("\n%s VS %s",t[e1].Name,t[f2].Name);
        if(n!=0)
        {
            resualt[e1][f2] = Fight(e1,f2);
            printf("\n%s %d : %d %s",t[resualt[e1][f2]/10000].Name,(resualt[e1][f2]-resualt[e1][f2]/10)/10,(resualt[e1][f2]-resualt[e1][f2]/10)%10,t[(resualt[e1][f2]/100)%10]);
            t[(resualt[e1][f2]/100)%10].Defeated = 1;
            w5 = resualt[e1][f2]/10000;
        }
        printf("\n%s VS %s",t[g1].Name,t[h2].Name);
        if(n!=0)
        {
            resualt[g1][h2] = Fight(g1,h2);
            printf("\n%s %d : %d %s",t[resualt[g1][h2]/10000].Name,(resualt[g1][h2]-resualt[g1][h2]/10)/10,(resualt[g1][h2]-resualt[g1][h2]/10)%10,t[(resualt[g1][h2]/100)%10]);
            t[(resualt[g1][h2]/100)%10].Defeated = 1;
            w6 = resualt[g1][h2]/10000;
        }
        printf("\n%s VS %s",t[f1].Name,t[e2].Name);
        if(n!=0)
        {
            resualt[f1][e2] = Fight(f1,e2);
            printf("\n%s %d : %d %s",t[resualt[f1][e2]/10000].Name,(resualt[f1][e2]-resualt[f1][e2]/10)/10,(resualt[f1][e2]-resualt[f1][e2]/10)%10,t[(resualt[f1][e2]/100)%10]);
            t[(resualt[f1][e2]/100)%10].Defeated = 1;
            w7 = resualt[f1][e2]/10000;
        }
        printf("\n%s VS %s",t[h1].Name,t[g2].Name);
        if(n!=0)
        {
            resualt[h1][g2] = Fight(h1,g2);
            printf("\n%s %d : %d %s",t[resualt[h1][g2]/10000].Name,(resualt[h1][g2]-resualt[h1][g2]/10)/10,(resualt[h1][g2]-resualt[h1][g2]/10)%10,t[(resualt[h1][g2]/100)%10]);
            t[(resualt[h1][g2]/100)%10].Defeated = 1;
            w8 = resualt[h1][g2]/10000;
        }



        if(n != 0)
        {
            if(t[User_Team-1].Defeated == 1)
            {
                printf("\nYour team is defeated\n");
                printf("Do you want to continue? (Y/N)");
                char slc;
                while(1>0)
                {
                    scanf("%c",&slc);
                    if(slc == 'Y' || slc == 'y' || slc == 'N' || slc == 'n')
                        break;
                    else
                    {
                        printf("\nEntery is not valid\nTry again");
                        delay();
                        system("clear");
                    }
                }
                if(slc == 'N' || slc == 'n')
                    return -100;
                else
                {
                    n = 7-state;
                    Next_Games(n);
                }
            }
            else
                printf("\nYour team is in game\n");
            n--;
            printf("\n1- Next");
            if(n != 0)
            {
                printf("\n1- Next\n");
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
            else
            {
                printf("\n1- Menu\n");
                int select = 0;
                while(1>0)
                {
                    scanf("%d",&select);
                    if(select == 1)
                    {
                        system("clear");
                        menu();
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
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(state == 5)     ////////////   1/4
    {
//        int a1=0,a2=0,b1=0,b2=0,c1=0,c2=0,d1=0,d2=0,e1=0,e2=0,f1=0,f2=0,g1=0,g2=0,h1=0,h2=0;



        printf("\n%s VS %s",t[w1].Name,t[w2].Name);
        if(n!=0)
        {
            resualt[w1][w2] = Fight(w1,w2);
            printf("\n%s %d : %d %s",t[resualt[w1][w2]/10000].Name,(resualt[w1][w2]-resualt[w1][w2]/10)/10,(resualt[w1][w2]-resualt[w1][w2]/10)%10,t[(resualt[w1][w2]/100)%10]);
            t[(resualt[w1][w2]/100)%10].Defeated = 1;
            l61 = resualt[w1][w2]/10000;
        }
        printf("\n%s VS %s",t[w3].Name,t[w4].Name);
        if(n!=0)
        {
            resualt[w3][w4] = Fight(w3,w4);
            printf("\n%s %d : %d %s",t[resualt[w3][w4]/10000].Name,(resualt[w3][w4]-resualt[w3][w4]/10)/10,(resualt[w3][w4]-resualt[w3][w4]/10)%10,t[(resualt[w3][w4]/100)%10]);
            t[(resualt[w3][w4]/100)%10].Defeated = 1;
            l62 = resualt[w3][w4]/10000;
        }
        printf("\n%s VS %s",t[w5].Name,t[w6].Name);
        if(n!=0)
        {
            resualt[w5][w6] = Fight(w5,w6);
            printf("\n%s %d : %d %s",t[resualt[w5][w6]/10000].Name,(resualt[w5][w6]-resualt[w5][w6]/10)/10,(resualt[w5][w6]-resualt[w5][w6]/10)%10,t[(resualt[w5][w6]/100)%10]);
            t[(resualt[w5][w6]/100)%10].Defeated = 1;
            w61 = resualt[w5][w6]/10000;
        }
        printf("\n%s VS %s",t[w7].Name,t[w8].Name);
        if(n!=0)
        {
            resualt[w7][w8] = Fight(w7,w8);
            printf("\n%s %d : %d %s",t[resualt[w7][w8]/10000].Name,(resualt[w7][w8]-resualt[w7][w8]/10)/10,(resualt[w7][w8]-resualt[w7][w8]/10)%10,t[(resualt[w7][w8]/100)%10]);
            t[(resualt[w7][w8]/100)%10].Defeated = 1;
            w62 = resualt[w7][w8]/10000;
        }


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
        printf("\n%s VS %s",t[l61].Name,t[l62].Name);
        if(n!=0)
        {
            resualt[l61][l62] = Fight(l61,l62);
            printf("\n%s %d : %d %s",t[resualt[l61][l62]/10000].Name,(resualt[l61][l62]-resualt[l61][l62]/10)/10,(resualt[l61][l62]-resualt[l61][l62]/10)%10,t[(resualt[l61][l62]/100)%10]);
            t[(resualt[l61][l62]/100)%10].Defeated = 1;
            w57 = resualt[l61][l62]/100%10;
            w59 = resualt[l61][l62]/10000;
        }
        printf("\n%s VS %s",t[w61].Name,t[w62].Name);
        if(n!=0)
        {
            resualt[w61][w62] = Fight(w61,w62);
            printf("\n%s %d : %d %s",t[resualt[w61][w62]/10000].Name,(resualt[w61][w62]-resualt[w61][w62]/10)/10,(resualt[w61][w62]-resualt[w61][w62]/10)%10,t[(resualt[w61][w62]/100)%10]);
            t[(resualt[w61][w62]/100)%10].Defeated = 1;
            w58 = resualt[w61][w62]/100%10;
            w60 = resualt[w61][w62]/10000;
        }

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
        printf("\n%s VS %s",t[w57].Name,t[w58].Name);
        if(n!=0)
        {
            resualt[w57][w58] = Fight(w57,w58);
            printf("\n%s %d : %d %s",t[resualt[w57][w58]/10000].Name,(resualt[w57][w58]-resualt[w57][w58]/10)/10,(resualt[w57][w58]-resualt[w57][w58]/10)%10,t[(resualt[w57][w58]/100)%10]);
            t[(resualt[w57][w58]/100)%10].Defeated = 1;
        }
        printf("\n%s VS %s",t[w59].Name,t[w60].Name);
        if(n!=0)
        {
            resualt[w59][w60] = Fight(w59,w60);
            printf("\n%s %d : %d %s",t[resualt[w59][w60]/10000].Name,(resualt[w59][w60]-resualt[w59][w60]/10)/10,(resualt[w59][w60]-resualt[w59][w60]/10)%10,t[(resualt[w59][w60]/100)%10]);
            t[(resualt[w59][w60]/100)%10].Defeated = 1;

            printf("\n                   === THE WINNER OF WORLD CUP 2018 ===");
            printf("\n%s",t[resualt[w59][w60]/10000].Name);

            printf("\n Rank2 ======> %s",t[resualt[w59][w60]/100%10].Name);
            printf("\n Rank3 ======> %s",t[resualt[w57][w58]/1000].Name);
            printf("\n Rank4 ======> %s",t[resualt[w57][w58]/100%10].Name);
        }
        if(n == 0)
        {
            if(t[User_Team-1].Defeated == 1)
                printf("Your team is defeated");
            else
                printf("Your team is in game");

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
    system("clear");
    menu();
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
        delay();
        printf("Downloading ");
        delay();
        printf(".");
        delay();
        printf(".");
        delay();
        printf(".");

        system("unzip Teams.zip");
        fprintf(NAMEFILES1,"%s\n","Teams");
        system("clear");
    }
    fclose(NAMEFILES1);

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

    srand (time(NULL));
    for(int n=0;n<32;n++)
    {
        for( int i = 0 ; i < t[n].Enrollment ; i++ ) {
            t[n].p[i].Skill = (rand() % 61)+40;
            t[n].p[i].Fitness =(rand() % 61)+40;
            t[n].p[i].Form = (rand() % 61)+40;
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
    char nameteam[150];
    int i = 0;
    while (fgets(nameteam, 150, team) != NULL)
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
        sscanf(token, "%d",  &t[i].Defeated);
        token = strtok(NULL, s);
        strcpy(t[i].NAMEFILE,token);

        i++;
    }
    state = t[32].Team_Position;
    User_Team = t[32].seed;
    fclose(team);
    for(i=0;i<32;i++)
    {
        strcpy(address,"SAVE/");
        strcat(address,WorldCup_Name);
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
        char nameplayer[100];

        int j = 0;
        while (fgets(nameplayer,100,player) != NULL)
        {
            const char s[2] = ",";
            char *token;
            token = strtok(nameplayer,s);
            sscanf(token, "%d",  &t[i].p[j].Player_Number);
            token = strtok(NULL,s);
            strcpy(t[i].p[j].Name,token);
            token = strtok(NULL,s);
            sscanf(token, "%d",  &t[i].p[j].Player_Age);
            token = strtok(NULL,s);
            t[i].p[j].Player_Post=*token;
            token = strtok(NULL,s);
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
    //////////////////

    char natijeh[3];

    char address4[100]={};
    strcpy(address4,"SAVE/");
    strcat(address4,WorldCup_Name);
    strcat(address4,"/");
    strcat(address4,"result.txt");
    FILE *goal =NULL;
    goal = fopen(address4,"r");

    if (!goal)
    {
        perror("fopen");
        return 0;
    }


    const char s[2] = "\n";

    for(int x=0;i<35;i++)
    {
        for(int j=0;fgets(natijeh, 3, goal) != NULL || j<35;j++)
        {
            char *token;
            token = strtok(natijeh, s);
            sscanf(token, "%d",  &resualt[x][j]);
        }
    }
    fclose(goal);
//////////

    char intiger[3];

    char address5[100]={};
    strcpy(address5,"SAVE/");
    strcat(address5,WorldCup_Name);
    strcat(address5,"/");
    strcat(address5,"int1.txt");
    FILE *ai =NULL;
    ai = fopen(address5,"r");

    if (!ai)
    {
        perror("fopen");
        return 0;
    }

        for(int j=0;fgets(intiger, 3, ai) != NULL || j<10;j++)
        {
            char *token;
            token = strtok(intiger, s);
            sscanf(token, "%d",  &temp_ai[j]);
        }
    fclose(ai);

    ///////////////////////
    char address6[100]={};
    strcpy(address6,"SAVE/");
    strcat(address6,WorldCup_Name);
    strcpy(address6,"/");
    strcat(address6,"int.txt");
    const char s7[2] = ",";

    FILE *moteghayer = fopen(address6,"r");
    if (!moteghayer)
    {
        perror("fopen");
        return 0;
    }
    char w[3];
    while (fgets(w,3,moteghayer) != NULL)
    {
        char *token;
        token = strtok(w,s7);
        sscanf(token, "%d",  &w1);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w2);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w3);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w4);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w5);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w6);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w7);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w8);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &l61);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &l62);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w61);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w62);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w57);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w58);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w59);
        token = strtok(NULL,s7);
        sscanf(token, "%d",  &w60);
    }
    fclose(moteghayer);


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
    t[32].seed= User_Team;
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
        fprintf(team, "%s,%c,%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%s", t[i].Name, t[i].Group, t[i].Team_Position,t[i].Fedrasion,t[i].seed,t[i].Team_Rate,t[i].Number_Win,t[i].Number_Lose,t[i].Number_Equal,t[i].Goal_S,t[i].Goal_R,t[i].Goal_M,t[i].Enrollment,t[i].Sort_Rank,t[i].System,t[i].Defeated,t[i].NAMEFILE);
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
    char address4[100]={};
    strcpy(address4,"SAVE/");
    strcat(address4,WorldCup_Name);
    strcat(address4,"/");
    strcat(address4,"result.txt");
    FILE *goal =NULL;
    goal = fopen(address4,"w");

    for(int i=0;i<35;i++)
    {
        for(int j=0;j<35;j++)
        {
            fprintf(goal, "%lld\n",resualt[i][j]);
        }
    }
    fclose(goal);
    char address5[100]={};
    strcpy(address5,"SAVE/");
    strcat(address5,WorldCup_Name);
    strcat(address5,"/");
    strcat(address5,"int.txt");
    FILE *moteghayer =NULL;
    moteghayer = fopen(address5,"w");

        for(int j=0;j<35;j++)
        {
            fprintf(moteghayer, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n",w1,w2,w3,w4,w5,w6,w7,w8,l61,l62,w61,w62,w57,w58,w59,w60);
        }
    fclose(moteghayer);
    char address6[100]={};
    strcpy(address6,"SAVE/");
    strcat(address6,WorldCup_Name);
    strcat(address6,"/");
    strcat(address6,"int1.txt");
    FILE *ai =NULL;
    ai = fopen(address6,"w");

        for(int j=0;j<10;j++)
        {
            fprintf(ai, "%d\n",temp_ai[j]);
        }

    fclose(ai);

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
/// for replacing "_"
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
            t[User_Team-1].System = 0;
        case 2 :
            t[User_Team-1].System = 1;
        default :
            t[User_Team-1].System = 2;
    }

    int counter1=0, counter2=0, counter3=0, counter4=0;
    if(t[User_Team-1].System == 0) /// 5-4-1
    {
        for(int j=0;j<t[User_Team-1].Enrollment; j++)
        {
            if(t[User_Team-1].p[j].Player_Post == 'D' && counter1<5)
            {
                t[User_Team-1].p[j].Condition = 1;
                t[User_Team-1].p[j].Player_Post_New = 'D';
                counter1++;
            }
            if(t[User_Team-1].p[j].Player_Post == 'M' && counter2<4)
            {
                t[User_Team-1].p[j].Condition = 1;
                t[User_Team-1].p[j].Player_Post_New = 'M';
                counter2++;
            }
            if(t[User_Team-1].p[j].Player_Post == 'A' && counter3<1)
            {
                t[User_Team-1].p[j].Condition = 1;
                t[User_Team-1].p[j].Player_Post_New = 'A';
                counter3++;
            }
            if(t[User_Team-1].p[j].Player_Post == 'G' && counter4<1)
            {
                t[User_Team-1].p[j].Condition = 1;
                t[User_Team-1].p[j].Player_Post_New = 'G';
                counter4++;
            }
        }
    }
    else if(t[User_Team-1].System == 1)  /// 4-4-2
    {
        counter1=0, counter2=0, counter3=0, counter4=0;
        for(int j=0;j<t[User_Team-1].Enrollment; j++)
        {
            if(t[User_Team-1].p[j].Player_Post == 'D' && counter1<4)
            {
                t[User_Team-1].p[j].Condition = 1;
                t[User_Team-1].p[j].Player_Post_New = 'D';
                counter1++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'M' && counter2<4)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'M';
                counter2++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'A' && counter3<2)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'A';
                counter3++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'G' && counter4<1)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'G';
                counter4++;
            }
        }
    }
    else  /// 4-3-3
    {
        counter1=0, counter2=0, counter3=0, counter4=0;
        for(int j=0;j<t[User_Team -1].Enrollment; j++)
        {
            if(t[User_Team -1].p[j].Player_Post == 'D' && counter1<4)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'D';
                counter1++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'M' && counter2<3)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'M';
                counter2++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'A' && counter3<3)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'A';
                counter3++;
            }
            if(t[User_Team -1].p[j].Player_Post == 'G' && counter4<1)
            {
                t[User_Team -1].p[j].Condition = 1;
                t[User_Team -1].p[j].Player_Post_New = 'G';
                counter4++;
            }
        }
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
            menu();
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
        if(t[User_Team-1].p[i].Player_Post_New != '-')
        {
            printf("%d- %s\n",i + 1,t[User_Team - 1].p[i].Name);
            printf("   Main player post : %c\n",t[User_Team - 1].p[i].Player_Post);
            printf("   New player post : %c\n",t[User_Team - 1].p[i].Player_Post_New);
            printf("   Player skill : %d\n",t[User_Team - 1].p[i].Skill);
            printf("   Player fitness : %d\n",t[User_Team - 1].p[i].Fitness);
            printf("   Player form : %d\n",t[User_Team - 1].p[i].Form);
            printf("----------------------------------\n\n");
            t[User_Team-1].p[i].Condition = 1;
        }
    }
    printf("\n  The list of players in the non-original combination: \n");
    for (int i = 0; i < t[User_Team - 1].Enrollment; i++)
    {
        if(t[User_Team-1].p[i].Player_Post_New == '-')
        {
            printf("%d- %s\n",i + 1,t[User_Team - 1].p[i].Name);
            printf("   Main player post : %c\n",t[User_Team - 1].p[i].Player_Post);
            printf("   New player post :  %c\n",t[User_Team - 1].p[i].Player_Post_New);
            printf("   Player skill : %d\n",t[User_Team - 1].p[i].Skill);
            printf("   Player fitness : %d\n",t[User_Team - 1].p[i].Fitness);
            printf("   Player form : %d\n",t[User_Team - 1].p[i].Form);
            printf("----------------------------------\n");
            t[User_Team-1].p[i].Condition = 0;
        }
    }
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
    }

    for(int i=0; i<32; i++)
    {
        if(t[i].System == 0) /// 5-4-1
        {
            for(int j=0;j<t[i].Enrollment; j++)
            {
                if(t[i].p[j].Player_Post == 'D' && counter1<5)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<1)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<1)
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
                if(t[i].p[j].Player_Post == 'D' && counter1<4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<2)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<1)
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
                if(t[i].p[j].Player_Post == 'D' && counter1<4)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'D';
                    counter1++;
                }
                if(t[i].p[j].Player_Post == 'M' && counter2<3)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'M';
                    counter2++;
                }
                if(t[i].p[j].Player_Post == 'A' && counter3<3)
                {
                    t[i].p[j].Condition = 1;
                    t[i].p[j].Player_Post_New = 'A';
                    counter3++;
                }
                if(t[i].p[j].Player_Post == 'G' && counter4<1)
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
    for(int i=0; i<20000; i++)
    {
        for(int j=0; j<20000; j++)
        {

        }
    }
}


int Table(void) {
   /* //c = 0;
    for (int h=0;h < 32;h++)
    {
        tmp1[h] = t[h];
    }

    if (state == 1 || state == 2 || state == 3) {

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP A ::\n");
        for (int i = 0; i < 32; i++) {
            if (t[i].Group == 'A') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }
        //////////////
        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP B ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'B') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }

        ///////////////////

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP C ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'C') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }

        //////////////////

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP D ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'D') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }

        /////////////////////

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP E ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'E') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }
//////////////////
        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP F ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'F') {
                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }
        ////////////////

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP G ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'G')
                printf("=================================\n");
            printf("\n                %s",tmp1[i].Name);
            printf("\n Team rate : %d",tmp1[i].Team_Rate);
            printf("\n Number win : %d",tmp1[i].Number_Win);
            printf("\n Number equal : %d",tmp1[i].Number_Equal);
            printf("\n Number lose : %d",tmp1[i].Number_Lose);
            printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
            printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
            printf("\n Goal difference : %d",tmp1[i].Goal_M);
            printf("=================================\n");

        }

        ///////////////

        for (int j = 0; j < 32; j++) {
            stdsort(tmp1,32,Group);

            if (j + 1 != 32 && tmp1[j].Team_Rate == tmp1[j + 1].Team_Rate) {

                if (tmp1[j].Goal_M == tmp1[j + 1].Goal_M) {
                    stdsort(tmp1,32,Goal_S);
                } else
                    stdsort(tmp1,32,Goal_M);
            } else
                stdsort(tmp1,32,Team_Rate);
        }
        printf("\n GROUP H ::\n");
        for (int i = 0; i < 32; i++) {
            if (tmp1[i].Group == 'H') {

                printf("=================================\n");
                printf("\n                %s",tmp1[i].Name);
                printf("\n Team rate : %d",tmp1[i].Team_Rate);
                printf("\n Number win : %d",tmp1[i].Number_Win);
                printf("\n Number equal : %d",tmp1[i].Number_Equal);
                printf("\n Number lose : %d",tmp1[i].Number_Lose);
                printf("\n Number of goals scored : %d",tmp1[i].Goal_S);
                printf("\n Number of flowers eaten : %d",tmp1[i].Goal_R);
                printf("\n Goal difference : %d",tmp1[i].Goal_M);
                printf("=================================\n");

            }
        }
    }
    */
}


/*
 *\
  /*  if(state==4 ||state==5 ||state==6)
    {

    }*/

int M_Power(int i)
{
      int x=0,am=0,skill,fitness,form;
      for( int am = 0 ; am < t[i].Enrollment ; am++ ) {
          if( t[i].p[am].Condition ==1 && t[i].p[am].Player_Post_New== 'M'){
              skill+=t[i].p[am].Skill;
              form+=t[i].p[am].Form ;
              fitness+=t[i].p[am].Fitness;}
      }
      fitness=fitness/11;
      skill=skill/11;
      form=form/11;
      x=skill+form+fitness;
      x=x/3;
      return x;
  }
int G_Power(int i)
{
    int x=0,am=0,skill,fitness,form;
    for( int am = 0 ; am < t[i].Enrollment ; am++ ) {
        if(t[i].p[am].Condition==1&&t[i].p[am].Player_Post_New == 'G'){
            skill+=t[i].p[am].Skill;
            form+=t[i].p[am].Form ;
            fitness+=t[i].p[am].Fitness;}
    }
    fitness=fitness/11;
    skill=skill/11;
    form=form/11;
    x=skill+form+fitness;
    x=x/3;
    return x;
}
int D_Power(int i)
{
    int x=0,am=0,skill,fitness,form;
    for( int am = 0 ; am < t[i].Enrollment ; am++ ) {
        if(t[i].p[am].Condition==1&&t[i].p[am].Player_Post_New == 'D'){
            skill+=t[i].p[am].Skill;
            form+=t[i].p[am].Form ;
            fitness+=t[i].p[am].Fitness;}
    }
    fitness=fitness/11;
    skill=skill/11;
    form=form/11;
    x=skill+form+fitness;
    x=x/3;
    return x;
}
int A_Power(int i)
{
    int x=0,am=0,skill,fitness,form;
    for( int am = 0 ; am < t[i].Enrollment ; am++ ) {
        if(t[i].p[am].Condition==1&&t[i].p[am].Player_Post_New == 'A'){
            skill+=t[i].p[am].Skill;
            form+=t[i].p[am].Form ;
            fitness+=t[i].p[am].Fitness;}
    }
    fitness=fitness/11;
    skill=skill/11;
    form=form/11;
    x=skill+form+fitness;
    x=x/3;
    return x;
}


int Fight(int i,int j)
{
    srand(time(0));
    int a1 = A_Power(i);
    a1=((a1*5)+rand()%101 )/6;
    int a2 = A_Power(j);
    a1=((a1*5)+rand()%101 )/6;
    int g1 = G_Power(i);
    int g2 = G_Power (j);
    int d1 = D_Power(i);
    int d2 = D_Power (j);
    int m1 = M_Power(i);
    int m2 = M_Power (j);

    int iTotal_Defence=(g1+d1+m1)/3;
    iTotal_Defence=(iTotal_Defence*5+rand()%101)/6;

    int jTotal_Defence=(g2+d2+m2)/3	;
    jTotal_Defence=(jTotal_Defence*5+rand()%101)/6;

    int iGoal=a1-jTotal_Defence;

    int jGoal=a2-iTotal_Defence;

    while (iGoal>10&&jGoal>10)
    {
        iGoal=iGoal/3;
        jGoal=jGoal/3;
    }
    if(iGoal>jGoal)
    {
        //////////////////////////////////////////////////////////////////
        t[i].Goal_S = iGoal + t[i].Goal_S;
        t[i].Goal_R = jGoal + t[i].Goal_R;

        for(int amin = 0;amin < t[i].Enrollment; amin++)
        {
            if(t[i].p[amin].Condition == 1)
                t[i].p[amin].Form = t[i].p[amin].Form*1.17;
        }

        for(int amin = 0;amin < t[j].Enrollment; amin++)
        {
            if(t[j].p[amin].Condition == 1)
                t[j].p[amin].Form = t[j].p[amin].Form*(0.87);
        }

        if(i>=10 && j>=10)
            return i*1000 + j*100 + iGoal*10 + jGoal;
        else if(i>=10 && j<10)
            return i*1000 + j*100 + iGoal*10 + jGoal;
        else if(i<10 && j>=10)
            return i*10000 + j*100 + iGoal*10 + jGoal;
        else
            return i*10000 + j*100 + iGoal*10 + jGoal;
        /*
                   /10000     /100%100     /10%10     %10
           351246  >>>>>>> 35 >>>>>>>>> 12 >>>>>>> 4 >>>>> 6
           010246  >>>>>>> 1  >>>>>>>>> 2  >>>>>>> 4 >>>>> 6
           120345  >>>>>>> 12 >>>>>>>>> 3  >>>>>>> 4 >>>>> 5
           013254  >>>>>>> 1  >>>>>>>>> 32 >>>>>>> 5 >>>>> 4
        */
        if(i>=10 && j>=10)
            return i*1000 + j*100 + iGoal*10 + jGoal;
        else if(i>=10 && j<10)
            return i*1000 + j*100 + iGoal*10 + jGoal;
        else
            return i*10000 + j*100 + iGoal*10 + jGoal;
    }
    else if(iGoal<jGoal)
    {
        ///////////////////////////////////////////////////////////
        t[j].Goal_S = iGoal + t[j].Goal_S;
        t[j].Goal_R = jGoal + t[j].Goal_R;
        if(i>=10 && j>=10)
            return j*1000 + i*100 + jGoal*10 + iGoal;
        else if(i>=10 && j<10)
            return j*1000 + i*100 + jGoal*10 + iGoal;
        else if(i<10 && j>=10)
            return j*10000 + i*100 + iGoal*10 + iGoal;
        else
            return j*10000 + i*100 + jGoal*10 + iGoal;
    }
    else if(iGoal=jGoal)
    {
        //////////////////////////////////////////////////////////////
        t[i].Goal_S = iGoal + t[i].Goal_S;
        t[i].Goal_R = jGoal + t[i].Goal_R;

        if(state == 1 || state == 2 || state == 3)
        {
            printf("\nThe teams become equal! \n");
            return -1*(iGoal);
        }
        else
        {
            printf("\nIt was taken to 90 minutes! \n");

            if(Amin_bool == 0)
            {
                for(int amin = 0;amin < t[i].Enrollment; amin++)
                {
                    if(t[i].p[amin].Condition == 1)
                        t[i].p[amin].Form = t[i].p[amin].Form*0.87;
                }

                for(int amin = 0;amin < t[j].Enrollment; amin++)
                {
                    if(t[j].p[amin].Condition == 1)
                        t[j].p[amin].Form = t[j].p[amin].Form*(0.87);
                }
            }
            if(Amin_bool == 0)
                Fight(i,j);

            if(Amin_bool == 1)
                Amin_bool = 0;
            else
                Amin_bool = 1;
            if(Amin_bool == 0)   ///Penalty
            {
                int d = Fight_Penalty(i,j);
                printf("It was taken to Penalty: \n%s  <%d> : <%d>  %s \n",t[i].Name,d/10,d%10,t[j].Name);
                if(d/10 > d%10)
                    printf("The winner is %s\n",t[i].Name);
                else
                    printf("The winner is %s\n",t[j].Name);
                Amin_bool = 0;
                return -1*(iGoal);
            }
        }
    }
}

int Fight_Penalty(int i,int j)
{
    srand(time(0));
    int a1 = A_Power(i);
    a1=((a1*5)+rand()%101 )/6;
    int a2 = A_Power(j);
    a1=((a1*5)+rand()%101 )/6;
    int g1 = G_Power(i);
    int g2 = G_Power (j);
    int d1 = D_Power(i);
    int d2 = D_Power (j);
    int m1 = M_Power(i);
    int m2 = M_Power (j);

    int iTotal_Defence=(g1+d1+m1)/3;
    iTotal_Defence=(iTotal_Defence + rand()%101)/2;

    int jTotal_Defence=(g2+d2+m2)/3	;
    jTotal_Defence=(jTotal_Defence + rand()%101)/2;

    int iGoal=a1-jTotal_Defence;
    int jGoal=a2-iTotal_Defence;

    return iGoal*10 + jGoal;
}
/*
int stdcmp(struct Teams x, struct Teams y, enum field f)
{
    switch (f) {
        case Name:
            return strcmp(x.Name, y.Name);
        case Team_Rate:
            return x.Team_Rate - y.Team_Rate;
        case Goal_M:
            return x.Goal_M - y.Goal_M;
        case Group :
            return y.Group - x.Group;
        default:
            return x.Goal_S - y.Goal_S;
    }
}


void stdsort(struct Teams t[], int len, enum field f)
{

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len -1 - i; j++) {
            if (stdcmp(t[j], t[j + 1], f) < 0) {
                struct Teams tmp = tmp1[j];
                t[j] = tmp1[j + 1];
                tmp1[j + 1] = tmp;
            }
        }
    }
}
*/