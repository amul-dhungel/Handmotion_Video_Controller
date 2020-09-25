const int trigger = 2; // sensor one

const int echo = 3; // sensor one


long time_taken;

int dist,distL;

 

void setup() {
  

Serial.begin(9600); 
  
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 

}


void calculate_distance(int trigger, int echo)
{
digitalWrite(trigger, LOW);
delayMicroseconds(2);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);

digitalWrite(trigger, LOW);

time_taken = pulseIn(echo, HIGH);

dist= time_taken*0.034/2;

if (dist>50)
dist = 50;
}

void loop() { 
  
calculate_distance(trigger,echo);

distL =dist; 






if ((distL >30) && (distL <50) )

{Serial.println("Play/Pause");
delay (500);
}

calculate_distance(trigger,echo);
distL =dist;




if (distL>=13 && distL<=17)
{
  delay(100); 
  calculate_distance(trigger,echo);
  distL =dist;
  if (distL>=13 && distL<=17)
  {
    Serial.println("Left Locked");
    while(distL<=40)
    {
      calculate_distance(trigger,echo);
      distL =dist;
      if (distL<10) //Hand pushed in 
      {Serial.println ("Vup"); delay (300);}
      if (distL>20) //Hand pulled out
      {Serial.println ("Vdown"); delay (300);}
    }
  }
}




delay(200);
}
