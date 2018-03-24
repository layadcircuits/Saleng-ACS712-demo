/***************************************************************************
 Saleng ACS712
 
 Description: A simple test code for the Saleng-ACS712 module. Simply upload and open
 the serial monitor with a baud rate of 9600. Connect as follows:

 Saleng Uno Saleng-ACS712
 5V         +   / V
 GND        -   / G
 A0         OUT / S
 
 
 This software is free provided that this notice is not removed and proper attribution 
 is accorded to Layad Circuits and its Author(s).
 Layad Circuits invests resources in producing free software. By purchasing Layad Circuits'
 products or utilizing its services, you support the continuing development of free software
 for all.
  
 Author(s): CDMalecdan for Layad Circuits Electronics Engineering
 Revision: 1.0 - 2018/03/08 - initial creation
 Layad Circuits Electronics Engineering Supplies and Services
 B314 Lopez Bldg., Session Rd. cor. Assumption Rd., Baguio City, Philippines
 www.facebook.com/layadcircuits
 www.layadcircuits.com
 general: info@layadcircuits.com
 sales: sales@layadcircuits.com
 mobile: +63-916-442-8565
 ***************************************************************************/
const byte SENSORPIN = A0;
const unsigned int MIN_RAW_VALUE = 322;
const unsigned int MAX_RAW_VALUE = 700;

unsigned int rawValue; //reading from ADC
int currentMA; //computed, in mA
char str[17]="";//temporary buffer


void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  //read ADC and take average
  rawValue=0;
  for(byte i=0;i<5;i++) 
  {
    rawValue += analogRead(SENSORPIN); 
  }
  rawValue /= 5;

  // limit values
  if(rawValue<=MIN_RAW_VALUE) rawValue = MIN_RAW_VALUE;
  if(rawValue>=700) rawValue = MAX_RAW_VALUE;

  // compute equivalent current
  currentMA = map(rawValue,MIN_RAW_VALUE,MAX_RAW_VALUE,-5000,5000);

  // display results in serial monitor
  Serial.print("Raw="); 
  Serial.print(rawValue); 
  Serial.print(" Calculated="); 
  Serial.print(currentMA); 
  Serial.println(" mA");

  delay(1000);
}
