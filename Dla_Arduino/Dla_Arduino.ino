#include <Stepper.h>
#include <Servo.h>

int enPin_x = 38;
int enPin_y =  56;
int x_cords = 0;
int y_cords = 0;
const int stepsPerRevolution = 13000;

Stepper stepper_x(stepsPerRevolution, 55, 54);
Stepper stepper_y(stepsPerRevolution, 61, 60);
Servo servo;

int datafromUser=0;

void setup() {
  pinMode(enPin_x, OUTPUT);
  digitalWrite(enPin_x, LOW);
  pinMode(enPin_y, OUTPUT);
  digitalWrite( enPin_y, LOW);

  servo.attach(4); 
  servo.write(0);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available() > 0)
  {
    datafromUser=Serial.read();

    if(datafromUser == '8')
    {
      stepper_x.step(stepsPerRevolution*3);
      x_cords = x_cords + 3;
    }
    else if(datafromUser == '0')
    { 
      servo.write(0);
      Serial.println(10);

      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
   
     
    }
  else if(datafromUser == '1')
  {
     servo.write(80);
     Serial.println(11);

      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
  }
    else if(datafromUser == '2')
  {
     servo.write(40);
     Serial.println(12);
       if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }    
  } 
    else if(datafromUser == '3')
  {
     servo.write(125);
     Serial.println(13);
      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
  }

    else if(datafromUser == '4')
  {
     servo.write(20);
     Serial.println(14);
      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      } 
  }

    else if(datafromUser == '5')
  {
     servo.write(105);
     Serial.println(15);
      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
  }
    else if(datafromUser == '6')
  {
     servo.write(60);
     Serial.println(16);
      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
  }
    else if(datafromUser == '7')
  {
     servo.write(150);
     Serial.println(17);
      if (x_cords >= y_cords)
      {
        while (y_cords < x_cords + 5)
        {
          stepper_y.step(stepsPerRevolution);
          y_cords = y_cords + 1;
            }
      }
      else if (y_cords > x_cords)
      {
        while (y_cords > x_cords + 5)
        {
          stepper_y.step(-stepsPerRevolution);
          y_cords = y_cords - 1;
        }
       
      }
  }

  }

   
}    

     

     
 
  