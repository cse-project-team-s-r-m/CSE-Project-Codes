#include <stdio.h>

char* closet[21]={'\0',"blue_jeans","black_jeans","brown_pants","black_pants","blue_shirt","red_shirt","sweatshirt","sweater","sandals","shoes","sneakers","boots",
    "white_socks","black_socks","orange_socks","wool_socks","shorts","tshirt","belt","jacket"};

    int hot[4]={18,17,9};
    int warm[9]={5,6,3,4,19,14,15,10,11};
    int cold[7]={7,8,1,2,19,20,16,12};

    int i,x,y,option,worn[80],t,tmp[10],unavailable[10],ucount,k1,k2,k3,k4;

void get_dressed(int tmp[],int x,int unavailable[],int ucount)
{

    y=1;

    if(x==0)
    {
        printf("No clothing available at the moment.\n");
    }
    else
    {
        printf("The suitable clothes for this weather are:\n");
        for(y=0;y<x;y++)
        {
            if((k1==0) && (tmp[y]==1 || tmp[y]==2 || tmp[y]==3 || tmp[y]==4))
            {
                printf("%s\n",closet[tmp[y]]);
                k1=1;
            }
            if((k2==0) && (tmp[y]==5 || tmp[y]==6|| tmp[y]==7 || tmp[y]==8))
            {
                printf("%s\n",closet[tmp[y]]);
                k2=1;
            }
            if((k3==0) && (tmp[y]==9 || tmp[y]==10 || tmp[y]==11 || tmp[y]==12))
            {
                printf("%s\n",closet[tmp[y]]);
                k3=1;
            }
            if((k4==0) && (tmp[y]==13 || tmp[y]==14 || tmp[y]==15 || tmp[y]==16))
            {
                printf("%s\n",closet[tmp[y]]);
                k4=1;
            }
            if(tmp[y]==17 || tmp[y]==18 || tmp[y]==19 || tmp[y]==20)
            {
                printf("%s\n",closet[tmp[y]]);
            }
        }
        printf("\n");
    }
    if(ucount>0)
    {
        printf("Unavailable closet are:\n");
        for(y=0;y<ucount;y++)
        {
            printf("%s\n",closet[unavailable[y]]);
        }
        printf("\n");
    }
}

void put_on(int clothing)
{
    int z;
    z=0;
    if(is_dirty(clothing)==1 || is_missing(clothing)==1)
    {
        unavailable[ucount]=clothing;
        ucount++;
    }
    else
    {
        worn[z]=clothing;
        z++;
        tmp[x]=clothing;
        x++;
    }
}
int is_dirty(int clothing)
{
    int count;
    count =0;
    for(y=0;worn[y]!=0;y++)
    {
        if(worn[y]==clothing)
        {
            count++;
        }
    }
    if(count>=3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_missing(int clothing)
{
    for(y=0;worn[y]!=0;y++)
    {
        if(clothing>21)
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int exitcounter, day, week;
    day =1;
    week =1;

    printf("This is your closet\n");

    while(exitcounter!=1){
    printf("It's Week %d\n", week);
    printf("It's Day %d\n", day);
    printf("Enter the Temperature:\n");
    scanf("%d",&t);

    switch(t)
    {
        case 0 ... 25:
            ucount=0;
            x=0;
            printf("The weather outside is cold\n");
            printf("Please select your outfit from these suitable choices:\n");
            printf("Input -1 to conclude.\n");
            for(i=0;i<7;i++)
            {
                printf("%d",i+1);
                printf(".%s\n",closet[cold[i]]);
            }

            for (i=0;i<10;i++)
            {
                scanf("%d",&option);
                if(option == -1)
                {
                    break;
                }
                if(option < 0 || option > 7)
                {
                    printf("You have entered an incorrect selection. Please try again\n");
                }
                else
                {
                    put_on(cold[option-1]);
                }
            }

             get_dressed(tmp,x,unavailable,ucount);

             printf("Press 1 to Exit\n");
             printf("Press 2 to Continue\n");
             scanf("%d",&exitcounter);
             if(exitcounter<1 || exitcounter>2)
             {
                 printf("Incorrect command. Please try again.\n");
                 printf("Press 1 to Exit\n");
                 printf("Press 2 to Continue\n");
                 scanf("%d",&exitcounter);
             }

             day++;
             if(day>7)
             {
               day=1;
               week++;
             }

          k1=0;
          k2=0;
          k3=0;
          k4=0;

            break;

        case 26 ... 39:
            ucount=0;
            x=0;
            printf("The weather outside is warm\n");
            printf("Please select your outfit from these suitable choices:\n");
            for(i=0;i<9;i++)
            {
                printf("%d",i+1);
                printf(".%s\n",closet[warm[i]]);
            }

            for (i=0;i<10;i++)
            {
                scanf("%d",&option);
                if(option == -1)
                {
                    break;
                }
                if(option < 0 || option > 9)
                {
                    printf("You have entered an incorrect selection. Please try again\n");
                }
                else
                {
                    put_on(warm[option-1]);
                }
            }

            get_dressed(tmp,x,unavailable,ucount);

             printf("Press 1 to Exit\n");
             printf("Press 2 to Continue\n");
             scanf("%d",&exitcounter);
             if(exitcounter<1 || exitcounter>2)
             {
                 printf("Incorrect command. Please try again.\n");
                 printf("Press 1 to Exit\n");
                 printf("Press 2 to Continue\n");
                 scanf("%d",&exitcounter);
             }

             day++;
             if(day>7)
             {
               day=1;
               week++;
             }

          k1=0;
          k2=0;
          k3=0;
          k4=0;

            break;

        case 40 ... 100:
            ucount=0;
            x=0;
            printf("The weather outside is hot\n");
            printf("Please select your outfit from these suitable choices:\n");
            printf("Input -1 to conclude.\n");
            for(i=0;i<3;i++)
            {
                printf("%d",i+1);
                printf(".%s\n",closet[hot[i]]);
            }

            for (i=0;i<10;i++)
            {
                scanf("%d",&option);
                if(option == -1)
                {
                    break;
                }
                if(option < 0 || option > 3)
                {
                    printf("You have entered an incorrect selection. Please try again\n");
                }
                else
                {
                    put_on(hot[option-1]);
                }
            }

            get_dressed(tmp,x,unavailable,ucount);

             printf("Press 1 to Exit\n");
             printf("Press 2 to Continue\n");

             scanf("%d",&exitcounter);
             if(exitcounter<1 || exitcounter>2)
             {
                 printf("Incorrect command. Please try again.\n");
                 printf("Press 1 to Exit\n");
                 printf("Press 2 to Continue\n");
                 scanf("%d",&exitcounter);
             }

             day++;
             if(day>7)
             {
               day=1;
               week++;
             }

          k1=0;
          k2=0;
          k3=0;
          k4=0;

             break;

        default:
            printf("Temperature is incorrect. Please try again.\n");
            break;


    }
    }


    return 0;
}

