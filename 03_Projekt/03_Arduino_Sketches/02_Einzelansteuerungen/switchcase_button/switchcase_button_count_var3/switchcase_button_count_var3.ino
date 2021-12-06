//inputs & outputs
const int pot = A0;    // select the input pin for the potentiometer (Analog pin AD2)
int val = 0;       // variable to store the value coming from the sensor to be used as time delay

const int button = 10;      //mode button
const int led1 = 2;       //white
const int led2 = 3;      //green cluster
const int led3 = 4;      //blue cluster
const int led4 = 5;      //red cluster

//counter variables
int button_push_counter = 0;   // counter for the number of button presses
int button_state = 0;         // current state of the button
int last_button_state = 0;     // previous state of the button

void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(button, INPUT);
  
}

void loop() 
{
  
  button_state = digitalRead(button); //reading from button switch
  
  if (button_state != last_button_state)
   {
       button_push_counter++;
   }
   
   else
   {
   }
   
   last_button_state = button_state;

   switch (button_state) 
   {
    case 0:
      white_strobe();
      break;
      
    case 1:
       red_strobe();
      break;
      
     case 2:
      green_strobe();      
      break;
      
    case 3:
      blue_strobe();
      break;

     case 4:
       all_strobe();
      break;
      
    case 5:
      crazy_routine();
      break;
           
    case 6:
       crazy_strobe();
      break;
      
    case 7:
      last_button_state = 0;
      break;  
   }
}


void white_strobe()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led1, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led1, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}

void green_strobe()
{
   val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led2, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led2, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}

void blue_strobe()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led3, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led3, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}

void red_strobe()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led4, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led4, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}


void all_strobe()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led1, HIGH);  // turn the ledPin on
  digitalWrite(led2, HIGH);  // turn the ledPin on
  digitalWrite(led3, HIGH);  // turn the ledPin on
  digitalWrite(led4, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led1, LOW);   // turn the ledPin off
  digitalWrite(led2, LOW);   // turn the ledPin off
  digitalWrite(led3, LOW);   // turn the ledPin off
  digitalWrite(led4, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}


void crazy_routine()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led4, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led4, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}

void crazy_strobe()
{
  val = analogRead(pot);    // read the value from the sensor
  digitalWrite(led4, HIGH);  // turn the ledPin on
  delay(val);                  // stop the program for some time
  digitalWrite(led4, LOW);   // turn the ledPin off
  delay(val);                  // stop the program for some time
}
