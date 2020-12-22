#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isValidTime(char word[])
{
    int lencount = 0;

    for (int i = 0; word[i]!=0; i++)
    {
        if(isdigit(word[i]) || (i==2 && word[i]==':'))
        {
            lencount++;
        }
        else
        {
            return 0;
        }
    }
    char *hour_token = strtok(word, ":");
    char *minute_token = strtok(NULL, ":");

    //printf("Raw: %s:%s\n",hour_token, minute_token);
    int hour = atoi(hour_token);
    int minute = atoi(minute_token);

    //printf("Formazott: %d:%d\n",hour, minute);
    //printf("Raw2: %s:%s\n",hour_token, minute_token);

    if(lencount==5)
    {
        if ((strlen(hour_token)==2 && strlen(minute_token)==2) && ((hour >= 0 && hour < 24) && (minute>=0 && minute < 60)))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int isValidToDo(char word[]) {
    for (int i = 0; word[i]!=0; i++) {
        if(isalpha(word[i])) {
            ;
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc<3 || argc%2==0) //nem teljesul a minimum bemenet, vagy valamelyiket kihagytak
    {
        printf("Hibas Bemenet");
        return 0;
    }

    FILE *f = fopen("C:\\Users\\suhi1\\Desktop\\todolist.txt", "a");
    printf("%d\n",argc);

    char time[100][100];
    char activities[100][100];

    int timecount=0;
    int activitycount=0;
    int time_iterator = 1;
    int act_iterator = 2;
    int cnt = 1;
    while(cnt<argc)
    {
        char time_copy[100];
        char activ_copy[100];
        strcpy(time_copy,argv[time_iterator]);
        strcpy(activ_copy,argv[act_iterator]);

        //printf("TIMEELOTT: %s - %s\n",argv[time_iterator],argv[act_iterator]);
        if(isValidTime(time_copy))
        {
            //printf("TODOELOTT: %s - %s\n",argv[time_iterator],argv[act_iterator]);
            if(isValidToDo(argv[act_iterator]))
            {
                //printf("COPYELOTT: %s - %s\n",argv[time_iterator],argv[act_iterator]);
                strcpy(time[timecount],argv[time_iterator]);
                //printf("COPYUTAN: %s - %s\n",argv[time_iterator],argv[act_iterator]);
                cnt++;
                timecount++;
                strcpy(activities[activitycount],argv[act_iterator]);
                cnt++;
                activitycount++;
                time_iterator+=2;
                act_iterator+=2;
                //printf("%s - %s\n",time[timecount],activities[activitycount]);
            }
            else {
                printf("%s\n","Hibas bemenet");
                time_iterator+=2;
                act_iterator+=2;
                cnt+=2;
            }
        }
        else {
            printf("%s\n","Hibas bemenet");
            time_iterator+=2;
            act_iterator+=2;
            cnt+=2;
        }
    }
    for(int i = 0; i < timecount; i++)
    {
        printf("%s - %s\n",time[i],activities[i]);
        fprintf(f,"%s - %s\n",time[i],activities[i]);
    }
    fclose(f);
    return 0;
}