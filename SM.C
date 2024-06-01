#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>
void berth(){
printf("\nplease select yourseat choice\n");
printf("1.Upper Berth\n2.Lower Berth \n3.Middle Berth\n4.Side Lower Berth \n5.Side Upper Berth\n");
}
void print(){
printf("sorry no seats available");
}
void choice(int c,int cc,int ccc,int cd,int cl,int cs){
printf("please enter your booking choice\n");
printf("1 . First Class AC : %d\n2 . AC 2-Tier : %d\n3 . AC 3-Tier : %d\n4 . AC Chair Car :%d \n5 . Sleeper :%d \n6 . Second Sitting :%d \n",c,cc,ccc,cd,cl,cs);
}
void main(){
textmode(BW40);
gotoxy(200,150) ;
printf("\n\n\n\n\n\t\t\t\t\t");
cprintf("WELCOME");
printf("\n");
cprintf("TO TICKET BOOKING SYSTEM \r\n");
delay(2000);
textmode(BW80);
clrscr();
int slow;
float took;
char seats[7][25]={"1A-First Class AC","2A-AC2-Tier","3A-AC3-Tier","Sleeper","CC-AC Chair Car","2S-Second Sitting"};
char box[5][4]={"UB","LB","MB","SLB","SUB"};
int zzz;

//train details
abc:
clrscr();
FILE *fp;
fp=fopen("let.csv","r");
if(fp==NULL){
printf("file cannot open") ;

}
     // y=serial_no,r=train_no,(tr,yr)=train_name,
    // ur=destination,vr=schedule,hr=time
  int y;
  char r[20],tr[20],yr[20],ur[20],vr[20],hr[20];   //page_1_display
  for(int shu=0;shu<9;shu++){

  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  printf("%d %s	  %s	%s	%s	%s\n",y,r,tr,ur,vr,hr);
  }
  textcolor(3);
  cprintf("\nenter 2 to navigate next page\r\n");
  cprintf("\nenter 5 to proceed for registration\r\n");
  textcolor(7);
   fclose(fp);

  scanf("%d",&y);
  if(y==5){
  goto tip;        //tip=registration
  }
  sec:           //second_page_navigation
  clrscr();

 fp=fopen("let.csv","r");

  if(y==2){

  textcolor(7);
  for(shu=0;shu<9;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  }
  for(;shu<19;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  printf("%d %s	 %s    %s    %s  %s\n",y,r,tr,ur,vr,hr);
  }
  fclose(fp);

  textcolor(3);
  cprintf("\nenter 3 to navigate next page\r\n");
  cprintf("\nenter 5 to proceed for registration\r\n");
  cprintf("\nenter 1 to navigate previous page\r\n");
  textcolor(7);
  scanf("%d",&y);

  if(y==5)
  goto tip;

  if(y==1){
  goto abc;
  }
  }

  tri:                      //page_3_navigation
  fp=fopen("let.csv","r");
  if(y==3){
  clrscr();
  textcolor(7);
  for(shu=0;shu<19;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  }
  for(;shu<29;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  printf("%d %s    %s  	  %s    %s  %s\n",y,r,tr,ur,vr,hr);
  }
  fclose(fp);

  textcolor(3);
  cprintf("\nenter 4 to navigate next page\r\n");
  cprintf("\nenter 5 to procees for registration\r\n");
  cprintf("\nenter 2 to navigate previous page\r\n");
  cprintf("\nenter 1 to navigate 1 st page\r\n");

  scanf("%d",&y);
  textcolor(7);

  if(y==4){
  goto tear;
  }
  else if(y==1){
  goto abc;
  }
  else if(y==2)  {
  goto sec;
  }
  else{
  goto tip;
  } }
  textcolor(7);
  clrscr();
   tear:    //page_4_navigation
   clrscr();
  fp=fopen("let.csv","r");
  for(shu=0;shu<29;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  }
  for(;shu<40;shu++){
  fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
  printf("%d %s   %s     %s     %s   %s\n",y,r,tr,ur,vr,hr);

  }
  fclose(fp);
   //navigation_to_all_pages
  textcolor(3);
  cprintf("\nEnter 5 to process for registration\r\n");
  cprintf("\nEnter 1 to navigate 1 st page\r\n");
  cprintf("\nEnter 2 to navigate 2 nd page\r\n");
  cprintf("\nEnter 3 to navigate 3 rd page\r\n");
  scanf("%d",&y);
  textcolor(7);

  if(y==5){
  goto tip;
  }
 else if(y==1){
  goto abc;
  }
  else if(y==2){
  goto sec;
  }
  else{
  goto tri;
  }

 tip:           //ticket_booking
int c,b;
clrscr();
 textcolor(3);
cprintf("\nEnter your train choice\r\n") ;
scanf("%d",&c);

 //train price

FILE *tp;
tp=fopen("d.csv","r");

struct d{
int b,bc,bcc,bd,bs,s,bp;   //1ac 2ac 3ac sitting_ac  sleeper  second_class
char bn[7];        //train no.
}bk,*bb;
bb=&bk;

for(int lo=0;lo<40;lo++){
fscanf(tp,"%d,%d,%d,%d,%d,%d,%d,%s\n",&bk.bp,&bk.b,&bk.bc,&bk.bcc,&bk.bd,&bk.bs,&bk.s,bb->bn);
 if(bk.bp==c)   // c=train_serial_no.
 break;
 }

 //choice of seat
 clrscr();
 textcolor(3);
 choice(bk.b,bk.bc,bk.bcc,bk.bd,bk.bs,bk.s);
 scanf("%d",&b);
 berth();
 scanf("%d",&slow);

//updation
//choice();
//scanf("%d",&b);
struct tic{
int p,a,ac,acc,ad,sl,s;      //p=serial_no.,a=1_AC
//ac=2_AC, acc=3_AC, ad=sitting class ,sl=sleeper ,s=2nd class
char n[6];
}o,*oo;
oo=&o;

FILE *f,*d;
d=fopen("paste.csv","a");     //ic.csv=no of seats
f=fopen("ic.csv","r");
for(int i=0;i<40;i++){
fscanf(f,"%d,%d,%d,%d,%d,%d,%d,%s\n",&o.p,&o.a,&o.ac,&o.acc,&o.ad,&o.sl,&o.s,oo->n);
if(o.p==c&&b==1){    // c=train_serial_no., b=seat_choice(ac,sleeper...)
if(o.a==0)         //1_ac
{printf("sorry no seats available\n");
delay(2000);
goto abc;}

o.a=o.a-1;
zzz=bk.b;      //price_1AC

}
if(o.p==c&&b==2){           //2AC
if(o.ac==0){
printf("sorry no seats available \n");
sleep(2);
goto abc;
}
o.ac-=1;
zzz=bk.bc;      //price_2AC
}
if(o.p==c&&b==3){             //3AC
if(o.acc==0){
printf("sorry no seats available\n");
sleep(2);
goto abc;
}
o.acc-=1;
zzz=bk.bcc ;                       //price_3AC
}
if(o.p==c&&b==4){     //AC_Chair_Car
if(o.ad==0){
print();
sleep(2);
goto abc;
}
o.ad-=1;
zzz=bk.bd ;        //price_AC_Chair_Car
}
if(o.p==c&&b==5){        //Sleeper
if(o.sl==0){
print();
sleep(2);
goto abc;
}
o.sl-=1;
zzz=bk.bs  ;           //price_Sleeper
}
if(o.p==c&&b==6){      //Sitting_Class
if(o.s==0){
print();
sleep(2);
goto abc;
}
o.s-=1;
zzz=bk.s;        //price_Sleeper_Class
}
fprintf(d,"%d,%d,%d,%d,%d,%d,%d,%s\n",o.p,o.a,o.ac,o.acc,o.ad,o.sl,o.s,o.n);
}
//update copmplete
 fclose(d);
 fclose(f);
 remove("ic.csv");
 rename("paste.csv","ic.csv");

fp=fopen("let.csv","r");//need to be changed
shu=0;
for(;shu<40;shu++){
fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
if(y==c)
break;  //data: train_no, train_name ,sl_no,train_time,destination
}
fclose(fp);


struct p{
char fn[40];  //first name
char sn[40];  //second name
char p[11];   //phone no.
char gm[50];  //gmail
char ge[8];   //gender
int a;        //age
}*pp,ss;
pp=&ss;   //address of strct store in pp

FILE *lp;
lp=fopen("passenger.csv","a");  int flow=slow-1; //to access 2Darray(box) index
clrscr();                                       // a=append(changes)
do{
printf("Enter First Name,Second Name,Phone No,Gmail,Gender,Age\n");
scanf("%s%s%s%s%s%d",pp->fn,pp->sn,&ss.p,pp->gm,pp->ge,&ss.a);//indicating string variables

if(ss.a>=75){
took=(0.75*zzz); //zzz=store orginal price
}	      //took is varible to store discount price by using above formula
else{
took=zzz;
}
fprintf(lp,"%d,%f,%d,%s,%s,%s,%s,%s,%s,%s %s,%s,%s,%s,%d,%s,%s\n",zzz,took,y,box[flow],r,tr,ur,vr,hr,ss.fn,ss.sn,ss.p,ss.gm,ss.ge,ss.a,seats[b-1]);


fclose(lp);	 //y=store serial no. of train
} while(0);       // '0'=false,apply at once
//fclose(lp);
textcolor(4);
printf("\n\n\n");
cprintf("AGE : %d \r\n",ss.a);
if(ss.a>=75){
printf("\nDiscount avail : 25%");
printf("\nORIGINAL AMOUNT : %d",zzz);
printf("\nAMOUNT : %f",took);
}
else{
printf("\nDiscount avail :0%");
printf("\nAMOUNT : %f",took);
}
textcolor(3) ;
getch();
clrscr();
textcolor(4);
printf("\nLets proceed for payment\r\n");
printf("\n Choose the payment option");
printf("\n1 .Credit card\n2 .Debit card\n3 .UPI\n ");
textcolor(3);
int t;
scanf("%d",&t);  //t= take choices of payment
//payment
if(t==3){
clrscr();
printf("Enter UPI id : ");
char sw[25];
scanf("%s",sw);
textcolor(4);  //4=for red color
cprintf("\n\nPAY:%f\r\n",took);
textcolor(7);
printf("\nEnter UPI PIN :");
getche();
getche();
getche();
getche();
getche();
getche();
goto zip;
}
if(t==1||t==2){
clrscr();
gotoxy(300,200);
printf("Enter Card Holder Name:xxxx xxxx\n ");
char n[20],nn[20];
scanf("%s%s",n,nn);
printf("Enter Card Number xxxx xxxx xxxx xxxx\n");
char vn[4],vb[4],vc[4],vh[4];
scanf("%s%s%s%s",vn,vb,vc,vh);

printf("enter cvv :");
char cvv[4];

scanf("%s",cvv);
char mm[3],yy[5];
printf("\nenter year of expiry :MM\YYYY");
scanf("%s%s",mm,yy);
printf("\nphone no%s",ss.p);
textcolor(4);
cprintf("\n\nPAY :%f\r\n",took);
textbackground(3);
textcolor(BLINK);
printf("\nEnter otp of 5 digit : ");
getche();
getche();
getche();
getche();
getche();
textbackground(3);
textcolor(BLINK);
printf("\nYou have successfully entered your opt");
textcolor(7);   //white
textbackground(0);  //black
delay(2000);
goto zip;
 }
zip:
textcolor(0);
textcolor(BLINK);
textbackground(3);
cprintf("payment successfull\r\n") ;
for(shu=0;shu<3;shu++){
sound(800);
delay(200);
nosound();
delay(100);
}
delay(2000);
textbackground(0);
textcolor(7);
getch();
textbackground(0);

//profit
struct pf{
int ee,rr;
char pp[7];
}mo,*moo;
moo=&mo;

FILE *ttt,*ppp;
ppp=fopen("profit.csv","a");
ttt=fopen("li.csv","r");

for(int we=0;we<40;we++){
fscanf(ttt,"%d,%d,%s\n",&mo.ee,&mo.rr,moo->pp);   //ee=train_serial_no.
if(mo.ee==c){        //c=train_choice            //rr=price pp=train_no.
mo.rr=mo.rr+took;
}
fprintf(ppp,"%d,%d,%s\n",mo.ee,mo.rr,mo.pp);
}
fclose(ppp);
fclose(ttt);

remove("li.csv");
rename("profit.csv","li.csv");
printf("please wait we are generating your ticket");
delay(1000);

FILE *soo;
soo=fopen("let.csv","r");
int q,e,to,j,fo;
char fg[7],g[4],io[4],go[7],po[12],poo[12];
for(int v=0;v<40;v++){
fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",&y,r,tr,yr,ur,vr,hr);
if(c==y)
break;
}
textcolor(7);
textbackground(0);
clrscr();
int sh,sw,sa;
void randomize();    //generate random
xyz:
sh=rand()%999;       //generate 3 digit no
if(sh/100==0)
goto xyz;
book:
sw=rand()%99;        //generate 2 digit no
if(sw/10==0)
goto book;
bor:
sa=rand()%99999 ;    //generate 5 digit no
if(sa/10000==0)
goto bor;

//ticket structure

printf(" %s (%s)",tr,r);     //tr=train_name   r=train_no

printf(" pnr no: %d-%d%d",sh,sw,sa);    //pnr no
printf("\nS-->E");
printf("\n%s",hr);       //hr=start to end destination
printf("\n%s %s",ss.fn,ss.sn);   //ss.fn=user_first_name ss.sn=second_name
printf("\nGEN:%s  AGE:%d",ss.ge,ss.a); //ss.ge=gender  ss.a=age
printf("\nbase fare: %f",took);        //took=amount paid by user
//time
struct dostime_t time; //predefined structure
_dos_gettime(&time);   // predefined function
printf("\n%d:%d:%d",time.hour,time.minute,time.second);
for(shu=0;shu<3;shu++){
sound(800);
delay(200);
nosound();
delay(100);
}
textcolor(3);
printf("\n\n\n\n");
cprintf("\nReturn Ticket :enter 1\r\n");
cprintf("\nBook Another Ticket :enter 1\r\n");
cprintf("\nSee Profits\r\n");
 int who;
 textcolor(7);
int kkr;
scanf("%d",&kkr);

if( kkr==1){
goto abc;
}
else if(kkr==8)
{
goto xor;
}
else{
goto end;
}
if(kkr==8){
xor:
clrscr();


printf("Enter the train no \n");
scanf("%d",&who);
textcolor(7);
textbackground(0);
//clrscr();

ttt=fopen("li.csv","r");
for(we=0;we<40;we++){
fscanf(ttt,"%d,%d,%s\n",&mo.ee,&mo.rr,moo->pp);
if(mo.ee==who) {
break;
}
printf("TRAIN NO    PROFIT\n");

printf("%s           %d\n",mo.pp,mo.rr);
}
fclose(ttt);
}
printf("\nTo See profits ,enter 8\n");
printf("Book Another Ticket Enter 1\n");
scanf("%d",&kkr);

if( kkr==0) {
goto end;
}
else if(kkr==8) {
goto xor;
}
else if(kkr==1){
goto abc;
}
else{
goto end;
}
getch();

end:
printf("\n\n\n\n\n\n\t\t");
textmode(BW40);
printf("\n\n\n\n\n\n\n\t\t\t\t\t\t");
cprintf("     THANKYOU !\r\n" );
delay(2000);

}




