/*
 * This sketch was made by Ritesh Sharma
 * Date : 29th August, 2017
 */
const int clkPin= 2; //the clk attach to pin 2
const int dtPin= 3; //the dt pin attach to pin 3
const int swPin= 4 ;//the sw pin attach to pin 4
 
int encoderVal = 0;
int b=0;
int a[5];
void setup()
{ 
//set clkPin,dePin,swPin as INPUT
pinMode(13,OUTPUT);
pinMode(clkPin, INPUT);
pinMode(dtPin, INPUT);
pinMode(swPin, INPUT);
digitalWrite(swPin, HIGH);
Serial.begin(9600); // initialize serial communications at 9600 bps
 
}
 
void loop()
{
  
int change = getEncoderTurn();//
encoderVal = encoderVal + change;
Serial.println(encoderVal);
if(digitalRead(swPin) == LOW)//if button pull down
{
  b=b+1;
  if(b==1)
  { 
    digitalWrite(13,LOW);
    a[0]=encoderVal;
    Serial.print("1st value is :");
    Serial.println(a[0]);
    delay(1000);
  }

  else if(b==2)
  {
    digitalWrite(13,LOW);
    a[1]=encoderVal;
    Serial.print("2nd value is :");
    Serial.println(a[1]);
    delay(1000);
  }

  else if(b==3)
  {
    digitalWrite(13,LOW);
    a[2]=encoderVal;
    Serial.print("3rd value is :");
    Serial.println(a[2]);
    delay(1000);
    if(a[0]==10&&a[1]==20&&a[2]==30)
{
  Serial.println("Successfull entry....Now you can enter the HAWELI");
  delay(2000);
  b=0;
}

else if(a[0]!=10&&a[1]!=20&&a[2]!=30)
{
  Serial.println("Invalid login");
  delay(2000);
  b=0;
}

}

encoderVal = 0;
  
}

}
 
int getEncoderTurn(void)
{
static int oldA = HIGH; //set the oldA as HIGH
static int oldB = HIGH; //set the oldB as HIGH
int result = 0;
int newA = digitalRead(clkPin);//read the value of clkPin to newA
int newB = digitalRead(dtPin);//read the value of dtPin to newB
if (newA != oldA || newB != oldB) //if the value of clkPin or the dtPin has changed
{
// something has changed
if (oldA == HIGH && newA == LOW)
{
result = (oldB * 2 - 1);
}
}
oldA = newA;
oldB = newB;
return result;
}
