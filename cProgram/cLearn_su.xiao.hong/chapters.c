#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//k fib
int k_faci(int m, int k)
{ //m-order_number,k-
    if (m == k - 1 || m == k)
    {
        return 1;
    }
    if (m < k - 1)
    {
        return 0;
    }
    return 2 * k_faci(m - 1, k) - k_faci(m - k - 1, k);
}
// 1.19
// int * sum_i_2(){
//     int arrSize,n;
//     printf("enter size,\n");
//     scanf("%d,%d",&arrSize,&n);
//     int arr[arrSize];
//     if(arrSize<n){
//         exit(0);
//     }
//     long int sum=1;
//     for(int i=1;i<=n;i++){
//         sum*=i*2;
//         if(sum>INT_MAX){
//             exit(0);
//         }
//         arr[i-1]=sum;
//     }
//     return arr;
// }

//clock
int clock(int count)
{
    int hour = 0, minute = 0, second = 0;
    for (int i = 0; i < count; i++)
    {
        second++;
        if (second == 60)
        {
            minute++;
            second = 0;
        }
        if (minute == 60)
        {
            hour++;
            minute = 0;
        }
        if (hour == 24)
        {
            hour = 0;
        }
        printf("%dh %d m %ds\n", hour, minute, second);
    }
    return 0;
}
int getMaxResemble(int m, int n)
{
    int r;
    if (n > m)
    {
        r = m;
        m = n;
        n = r;
    }
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return n;
}
int dayOfYear(int year, int month, int day)
{
    int normalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        normalDays[1] = 29;
    }
    for (int i = 0; i < month - 1; i++)
    {
        day += normalDays[i];
    }
    return day;
}

// charpter nine

// 9.4
void monthDay(int year, int yearDay, int *pMonth, int *pDay)
{
    int normalDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i; //guard;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        normalDays[1] = 29;
    }
    for (i = 0; yearDay > normalDays[i]; i++)
    {
        yearDay -= normalDays[i];
    }
    *pMonth = i + 1;
    *pDay = yearDay;
}

// 10;
// 10.1
void myStrCopy(char *tarStr, char *srcStr)
{
    while (*srcStr != '\0')
    {
        *tarStr = *srcStr;
        *tarStr++;
        *srcStr++;
    }
}

// 11.5
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void transpose(int arr[][5], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(&arr[i][j], &arr[j][i]);
        }
    }
}
// 12.1
typedef struct date{
    int year;
    int month;
    int day;
}DATE;
typedef struct career
{
    char college[30];
    char jobTitle[30];
    char position[30];
}CAREER;
typedef struct personRecord{
    char name[30];
    char sex[30];
    DATE birthday;
    CAREER career_situation;
}PERSONRECORD;

// 12.5
struct card{
    char suit[40];
    char face[10];
};
void initPoker(struct card poker[],char *suit[],char *face[]){
    for(int i=0;i<52;i++){
        strcpy(poker[i].suit,suit[i/13]);
        strcpy(poker[i].face,face[i%13]);
    }
}
void Shufflepoker(struct card* poker){
    for(int i=51;i>0;i--){
        int index=rand()%(i+1);
        // swap(&poker[i],&poker[index]);
        struct card temp;
        temp=poker[i];
        poker[i]=poker[index];
        poker[index]=temp;
    }
}
void printPoker(struct card * poker){
    for(int i=0;i<52;i++){
        printf("face:%s,suit:%s\n",poker[i].face,poker[i].suit);
    }
}

void test(int arr[][2], int (*brr)[2], int *crr)
{
    typedef struct student
    {
        double a;
        char c;
        float age;
    } STUDENT;
    typedef union stu
    {
        short a;
        char c;
        float age;
    } STU;
    int s = sizeof(STUDENT);
    int a=sizeof(STU);
}
int main(void)
{
    // int a=k_faci(4,2);
    // sum_i_2();
    // clock(3601);
    // getMaxResemble(15,50);
    // dayOfYear(2001,3,1);
    // int month,day;
    // monthDay(2000,61,&month,&day);
    // test();
    int arr[][2] = {1, 2, 3, 4, 5, 6};
    // swap(&arr[0][0],&arr[1][0]);
    char *suit[]={"spades","heart","club","diamond"};
    char *face[]={"A","2","3","4","5","6","7","8","9","10","jake","queen","king"};

    struct card poker[52];
    initPoker(poker,suit,face);
    Shufflepoker(poker);
    printPoker(poker);
    return 0;
}
