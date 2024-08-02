#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<time.h>
#include<conio.h>

struct User {
    char mobile[15];
    char password[20];
}users[100];


struct DETAILS
{
    char mobile_num[15];
    char city[20];
    char theater[20];
    char movie[50];
    int screen;
    char code[10];
    char date[10];
    char time[10];
}book[100];

struct CITY
{
    char city[20];
}cy[15];

struct SEET{
    char seats[4];
}st[100];

struct MOVIE
{
    char code[10];
    char city[20];
    char movie[50];
    char theater[20];
    int screen;
}mv[50];

void ADMIN();
int LOCATION();
int MOVIES();
int THEATERS();
int SEATS();
void INVOICE(int);
void HEDDER();
int REGISTRATION();
int LOGIN();
void LOGO();
void FEEDBACK();
int main()
{
   // LOGO();
    HEDDER();
    int option;
home:
    printf("\n\t\t1)Register.\n\t\t2)Login.\n\t\t3)Admin Login.\n\t\t4)Exit.\n\n\t\tEnter Option: ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        REGISTRATION();
        break;
    case 2:
        LOGIN();
        break;
    case 3:
        ADMIN();
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("..........Please Enter correct option...........");
        goto home;
    }

    return 0;
}

/*---------------------------------------------------------------------------------------------------------------*/
int REGISTRATION()
{
    system("cls");
     HEDDER();
     printf("\n\t...........REGISTRATION.............\n");

    char input_mobile[15],input_password[20];
    int num_users=0;
    FILE *file1;
    file1=fopen("user_details.txt","a");
    printf("\n\t\tEnter mobile number: ");
    scanf("%s", users[0].mobile);
    printf("\t\tSet password: ");
    scanf("%s", users[0].password);
    int ootp,otp;
enter1:
        srand((unsigned int)time(NULL));
        ootp=rand()%10000;
        printf("\n\t\tYour otp: %d",ootp);
        printf("\n\t\tEnter the  OTP: ");
        scanf("%d",&otp);
        if((otp==ootp))
        {
            fprintf(file1, "%s %s\n",users[num_users].mobile,users[num_users].password);
            fclose(file1);
            goto step;
        }
        else
        {
            printf("\n\t\tInvalid OTP");
            printf("\n\t\tResending OTP......\n");
            sleep(2);
            goto enter1;
        }

    //scanf("%s %s",users[num_users].mobile, users[num_users].password);
step:
    system("cls");
    char a[20]={'.','.','.','.','.','.','.','.','.','.','.','.','.'};
    printf("\n\n\t\t\t");
    for(int i=0;i<2;i++)
    {
        printf("\r----------------------\r");
        for(int j=0;j<=11;j++)
        {
            printf("%c ",a[j]);
            usleep(200000);
        }
    }
    system("cls");
    LOGIN();
    //return ;
}

/*---------------------------------------------------------------------------------------------------------------*/
int LOGIN()
{
    system("cls");
    HEDDER();
    printf("\n\t--------Enter your login details-------\n");

    FILE *file1;
login:
    file1=fopen("user_details.txt","r");
    if (file1 == NULL) {
        printf("Error opening file\n");
    }
    int num_users=0;
    while(fscanf(file1,"%s %s",users[num_users].mobile, users[num_users].password) == 2) {
        num_users++;
        }

    char c, mobile_check[50] ,password_check[20];
    int i=0;
    // Get user input
    printf("\n\t\tEnter your Mobile number: ");
    scanf("%s",&mobile_check);
    printf("\t\tEnter Your Password: ");
    while(1){
    c=getch();
    if(c==13){
            password_check[i]='\0';
            break;
    }
    else if(c==8){
        if(i>0){
            i--;
            printf("\b\b");
        }
    }
    else if(c==9||c==32){
        continue;
    }
    else {
    password_check[i]=c;
    printf("*");
    i++;
    }}
    // Check credentials
    int found=0;
     for (i=0;i<num_users;i++){
        if (strcmp(mobile_check, users[i].mobile) == 0 && strcmp(password_check, users[i].password) == 0) {
            found=1;
            break;
        }}

    if(found){
        strcpy(book[0].mobile_num,mobile_check);
        printf("\n\n\t.........Login successful!........\n");
    }
    else {
        printf("\n.....Invalid mobile number or password......\n");
        goto login;
    fclose(file1);
    }
    LOCATION();

    return 0;
}

/*---------------------------------------------------------------------------------------------------------------*/
void LOGO()
{
     printf("\n\t\t_/\\_");
    printf("\n\t\t\\  /");
    printf("\n\t\t/  \\");
    printf("\n\t\t \\/");
    sleep(1);
    system("cls");
    printf("\033[1;32m");
    printf("\n\n\n\t\t\t_/\\_");
    printf("\n\t\t\t\\  /");
    printf("\n\t\t\t/  \\");
    printf("\n\t\t\t \\/");
    sleep(1);
    system("cls");
    printf("\033[1;33m");
    printf("\n\n\n\n\n\t\t\t\t_/\\_");
    printf("\n\t\t\t\t\\  /");
    printf("\n\t\t\t\t/  \\");
    printf("\n\t\t\t\t \\/");
    sleep(1);
    system("cls");
    printf("\033[1;36m");
    printf("\n\n\n\t\t\t\t ______________________");
    printf("\n\t\t\t\t|                      |");
    printf("\033[1;36m");
    printf("\n\t\t\t\t|\033[1;33m ***   *     *  ***** \033[1;36m|");
    printf("\n\t\t\t\t|\033[1;33m *  *  * * * *  *     \033[1;36m|");
    printf("\n\t\t\t\t|\033[1;33m ****  *  *  *  ***** \033[1;36m|");
    printf("\n\t\t\t\t|\033[1;33m *  *  *     *      * \033[1;36m|");
    printf("\n\t\t\t\t|\033[1;33m ***   *     *  ***** \033[1;36m|");
    printf("\n\t\t\t\t|\033[1;33m                      \033[1;36m|");
    printf("\n\t\t\t\t|______________________|");

    printf("\n\n\t\t\t\t     \033[1;31mBOOK MY SCREEN");
    printf("\n\t\t\t\t  \033[1;31mIt all starts here!!\n\n");
    sleep(3);
    printf("\033[0m");
    system("cls");
}
void HEDDER()
{
     printf("\n============================================================================\n\t\t\t\t\tBOOK MY SCREEN\n\
                      ============================================================================\n");
}

int LOCATION()
{
    system("cls");
    HEDDER();
    printf("\t........Select City.........\n\n");

    char cit[20];
    FILE *file_cy;
    file_cy=fopen("city.txt","a+");
//    for(int i=0;i<3;i++){
//    printf("Enter city name: ");
//    scanf("%s",cit);
//    fprintf(file_cy,"%s\n",cit);
//    }
    int i=0,c_num;
    while(fscanf(file_cy,"%s",cy[i].city)==1)
    {
        printf("\t\t%d.%s\n",i,cy[i].city);
        i++;
    }
    printf("\n\t\tSelect City: ");
    scanf("%d",&c_num);
    strcpy(book[0].city,cy[c_num].city);
    printf("\n%s",book[0].city);

    fclose(file_cy);
    MOVIES();


}


int MOVIES()
{
    system("cls");
    HEDDER();
     printf("\t........Select Movie.........\n\n");

    char mov[50];
    FILE *file_mv;
    file_mv=fopen("Movie_list.txt","a+");
//    for(int i=0;i<3;i++){
//    printf("Enter Movie name, Rating: ");
//    scanf("%s",mov);
//    fprintf(file_mv,"%s\n",mov);
//    }
    int i=0;
    int num;
    while(fscanf(file_mv,"%s %s %s %s %d",mv[i].code,mv[i].city,mv[i].movie,mv[i].theater,&mv[i].screen)==5)
    {
        if(strcmp(mv[i].city,book[0].city)==0){
            printf("\t\t%d.%s\n",i,mv[i].movie);
        }
        i++;
    }
    printf("\n\t\tSelect Movie: ");
    scanf("%d",&num);
    strcpy(book[0].movie,mv[num].movie);
    printf("\n%s",book[0].movie);

    fclose(file_mv);
    system("cls");
    HEDDER();
    printf("\n\n\t Theatres screening %s:\n\n",book[0].movie);
    THEATERS();


}

int THEATERS()
{
     printf("\t........Select Theater.........\n\n");

    char tr[50];int mn;
    FILE *file_th;
    file_th=fopen("Movie_list.txt","a+");
    //For Theater
    int i=0,num2,scr;
     while(fscanf(file_th,"%s %s %s %s %d",mv[i].code,mv[i].city,mv[i].movie,mv[i].theater,&mv[i].screen)==5)
    {
        if(strcmp(mv[i].city,book[0].city)==0){
           if(strcmp(mv[i].movie,book[0].movie)==0){
            printf("\t\t%d.%s\n",i,mv[i].theater);
        }}i++;
    }
    printf("\n\t\tSelect Theater: ");
    scanf("%d",&num2);
    strcpy(book[0].theater,mv[num2].theater);
    i=0;
    //For screen
    while(1)
    {
        if(strcmp(mv[i].city,book[0].city)==0){
           if(strcmp(mv[i].movie,book[0].movie)==0){
            if(strcmp(mv[i].theater,book[0].theater)==0){
                printf("\t\t%d.screen-%d\n",i,mv[i].screen);
                scr=mv[i].screen;
                break;
        }}}i++;
    }
    book[0].screen=scr;
   // printf("\n%s",book[0].theater);
   // printf("\n%d",book[0].screen);
    //For code
    i=0;
    while(1)
    {
        if(strcmp(mv[i].city,book[0].city)==0){
           if(strcmp(mv[i].movie,book[0].movie)==0){
            if(strcmp(mv[i].theater,book[0].theater)==0){
                if(mv[i].screen==book[0].screen){
                printf("\t\tcode-%s\n",mv[i].code);
                strcpy(book[0].code,mv[i].code);
               // printf("%s",book[0].code);
                break;
        }}}}i++;
    }
    fclose(file_th);
    INVOICE(SEATS());
}



int SEATS()
{

    printf("\n\t\t\t\t     .........Select Seets..........\n\n");
    int i=0,j=0,k=0,l=0,s=0,n;
    char line[2000];
    char *seat_num;


    printf("\n");
    FILE *fp;
    fp= fopen("array.txt","r");
     if (fp == NULL) {
        printf("Error opening file\n");
     }
    if (fgets(line,2000,fp)!= NULL) {
        seat_num = strtok(line," ");
        while (seat_num != NULL){
            printf("%s   ",seat_num);
            seat_num= strtok(NULL," ");
            l++;
            if(l==20){
                    printf("\n");
                    l=0;
            }
        }
    }
     fclose(fp);

    printf("\n -------------------------------------------------SCREEN---------------------------------------------------\n");
    printf("\nHow many seats you want ?: ");
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        printf("Enter seat%d: ",j);
        scanf("%s", st[j].seats);
        printf("%s ", st[j].seats);

    }
    system("cls");
    HEDDER();
    printf("\n\t\tEnter Show Date (dt-mon-year):");
    scanf("%s",book[0].date);
    printf("\n\t    .......Show Timings.......\n\t\t1)09.00AM-12.00PM\n\t\t2)12.30PM-03.30PM\n\t\t3)06.00PM-09.00PM\n\t\t4)10.00PM-01.00AM\n\t\tEnter Timing:");
    up:
    scanf("%d",&s);
    switch(s)
    {
        case 1: strcpy(book[0].time,"09.00AM-12.00PM");
            break;
        case 2: strcpy(book[0].time,"12.30PM-03.30PM");
            break;
        case 3: strcpy(book[0].time,"06.00PM-09.00PM");
            break;
        case 4: strcpy(book[0].time,"10.00PM-01.00AM");
            break;
        default:printf("\nEnter correct option:");
            goto up;
    }
   char c;
     printf("Please do payment of %dRS\n press \"enter\" to pay\n",n*200);
     c=getch();
     //system("cls");
    if(c==13){
    char a[20]={'.','.','.','.','.','.','.','.','.','.','.','.','.'};
    printf("\n\n\t\t\t");
    for(int i=0;i<2;i++)
    {
        printf("\r----------------------\r");
        for(int j=0;j<=11;j++)
        {
            printf("%c ",a[j]);
            usleep(200000);
        }
    }}
     printf("\n\n\tSuccessfully done the payment!!!");
    sleep(4);
    system("cls");
    return n;
}
void INVOICE(int n)
{
    system("cls");
    HEDDER();

     printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\t\t    *******BOOK MY SHOW********\n\tNO.of Tickets:%d (",n);
    for(int i=1;i<+n;i++){
    printf("%s ",st[i].seats);}
    printf(")\n\tMovie:%s \n\tScreen: Screen-%d \n\tDate: %s \n",book[0].movie,book[0].screen,book[0].date);
    printf("\tShow Time:%s \n\tPrice: %dx(200)= %dRs\n",book[0].time,n,n*200);
    printf("\tYour mobile_num: %s\n\t\t\t__Thank You__\n",book[0].mobile_num);
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    FILE *file_details=fopen("Booking_Details.txt","a");
    fprintf(file_details,"%s %s %s %s %s %d %s %s \n",book[0].mobile_num,book[0].code,book[0].movie,book[0].city,book[0].theater,book[0].screen,book[0].date,book[0].time);
    fclose(file_details);
    FEEDBACK();
}

void FEEDBACK()
{
    system("cls");
    HEDDER();
    FILE *feedback=fopen("feedback.txt","a");
    fprintf(feedback,"\n%s ",book[0].mobile_num);
     printf("\n\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    printf("\n\tThank you for choosing our app!!");
    printf("\n\tPlease enter your booking experience (out of 5): ");
    int star;
    scanf("%d",&star);
    printf("\tThank you for ");
    for(int i=0;i<star;i++){
        printf("* ");
        fprintf(feedback,"* ");}
    fclose(feedback);
    printf("\n\tEnjoy your movie experience!!!");
    printf("\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

}
void ADMIN()
{
   system("cls");
    HEDDER();
    int i,a;
    char pass[10];
    up:
    printf("\n\t\tPlease Enter Password :");
    scanf("%s",pass);
    if(strcmp(pass,"12345678")==0)
    {
    printf("\n\t.......Correct Password.......");
    FILE *file_c;
    file_c=fopen("city.txt","a+");

    printf("\n\t........Enter Movies,Theater.........\n\n");
    char mov[50];
    FILE *file_mv;
    file_mv=fopen("Movie_list.txt","a+");
    printf("Enter no of Movie names you want to enter : ");
    scanf("%d",&a);
    for(i=0;i<a;i++){
    printf("Enter movie code :");
    scanf("%s",mv[i].code);
    printf("Enter city_name :");
    scanf("%s",mv[i].city);
    printf("Enter movie_name(rating/10) :");
    scanf("%s",mv[i].movie);
    printf("Enter movie_Theater like \"PVR_Mall\":");
    scanf("%s",mv[i].theater);
    printf("Enter Screen_number :");
    scanf("%d",&mv[i].screen);
    fprintf(file_c,"\n%s",mv[i].city);
    fprintf(file_mv,"\n%s %s %s %s %d ",mv[i].code,mv[i].city,mv[i].movie,mv[i].theater,mv[i].screen);
    }
    fclose(file_c);
    fclose(file_mv);
    printf("1.)See the booking orders\n2.)exit\n Choose your option: ");
    scanf("%d",&a);
    if(a==1)
    {
      int n;
    char line[2000];
    printf("\n");
    FILE *fp;
    fp= fopen("Booking_Details.txt","r");
     if (fp == NULL) {
        printf("Error opening file\n");
     }
    if(fgets(line,2000,fp)!= NULL) {
         printf("%s \n",line);
        }
     fclose(fp);
    }
    else if(a==2) exit(-1);
    }
    else{
            printf("\n\t.......Wrong Password.......\n\t try again..");
            goto up;
    }

}
