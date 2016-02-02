/*  Heartbeat
 *   Paul Badger 2009
 *   Demonstates how to use an array with millis to achieve irregular rhythms
 *   This function still uses one delay but it never leaves the LEDpin / LED in 
 *   the ON state.
 */


long heartBeatArray[] = {
    50, 75, 100, 1200};
int hbeatIndex = 1;   // this initialization is important or it starts on the "wrong foot"
long prevMillis;

int LEDpin = 1;


void setup()                    
{
    Serial.begin(9600);
    pinMode(LEDpin, OUTPUT);
  
    
}

void loop()                    
{
    heartBeat(1.75);   // try changing the parameter
}

void heartBeat(float tempo){
    if ((millis() - prevMillis) > (long)(heartBeatArray[hbeatIndex] * tempo)){
        hbeatIndex++;
        if (hbeatIndex > 3) hbeatIndex = 0;

        if ((hbeatIndex % 2) == 0){ 
            digitalWrite(LEDpin, HIGH); 
            delay((int)heartBeatArray[hbeatIndex]) ;   
            digitalWrite(LEDpin, LOW); 
        }
        hbeatIndex++;
        // Serial.println(hbeatIndex);
        prevMillis = millis();

    }
}

