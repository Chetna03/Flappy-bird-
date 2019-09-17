#include<LiquidCrystal.h>
int rs=0,en=1,d4=2,d5=3,d6=4,d7=5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int i=9;
void setup() {
  pinMode(8,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.println("FLAPPY BIRD");
  delay(1000);
  lcd.clear();
 
  }
char q=0;
void loop() {
 updown();
 if(q==0)
 {
 gameup();
 if(i==1)
 {
  //lcd.clear();
  ran();
  q++;
 }
 } 
 else
 { 
 gamedown();
 if(i==1)
 {
 // lcd.clear();
  ran();
  q=0;
 }
 }
 }
void updown()
{
   if(digitalRead(8)==1)
  { 
    lcd.setCursor(3,1);
    lcd.print(" ");
    lcd.setCursor(3,0);
    lcd.print("@");
   }
  if(digitalRead(8)==0)
    { 
      lcd.setCursor(3,0);
      lcd.print(" "); 
      lcd.setCursor(3,1);
      lcd.print("@");
    } 
}

void gameup()
{ 
  //for(int i=8;i>=1;i--)
//{
  lcd.setCursor(i,0);
  lcd.print("#");
  updown();
 delay(100);
//} 
if(digitalRead(8)==1&&i==3)
{ lcd.setCursor(5,0);
  lcd.clear();
  lcd.print("game over");
  delay(1000);
}
if(digitalRead(8)==0&&i==2)
{
  lcd.clear();
  delay(100);
  //i=5;
  //ran();
  
}

i--;
}
void gamedown()
{ 
  //for(int i=8;i>=1;i--)
//{
  lcd.setCursor(i,1);
  lcd.print("#");
  updown();
 delay(100);
//} 
if(digitalRead(8)==0&&i==2)
{
  lcd.setCursor(5,0);
  lcd.clear();
  lcd.print("game over");
  delay(1000);
}
if(digitalRead(8)==1&&i==2)
{
  lcd.clear();
  delay(100);
  //i=5;
  //ran();
}

i--;
}
void ran()
{
  i=random(3,16);
}

