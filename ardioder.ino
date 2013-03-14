const int channel1PinG = 9;
const int channel1PinB = 10;
const int channel1PinR = 11;

const int channel2PinG = 3;
const int channel2PinB = 5;
const int channel2PinR = 6;

int availableBytes = 0;
boolean isMessage = false;
const int MESSAGELENGTH = 18;
int message[MESSAGELENGTH / 3];

char readString[] = "000";

void setup() {
   pinMode(channel1PinR, OUTPUT); 
   analogWrite(channel1PinR, 0);
   
   pinMode(channel1PinG, OUTPUT); 
   analogWrite(channel1PinG, 0);
   
   pinMode(channel1PinB, OUTPUT); 
   analogWrite(channel1PinB, 0);
   
   pinMode(channel2PinR, OUTPUT); 
   analogWrite(channel1PinR, 0);
   
   pinMode(channel2PinG, OUTPUT); 
   analogWrite(channel1PinG, 0);
   
   pinMode(channel2PinB, OUTPUT); 
   analogWrite(channel1PinB, 0);

   Serial.begin(9600);  
}

void loop () {    
  availableBytes = Serial.available();

  if(availableBytes == 1 && !isMessage) {
    char inChar = Serial.read();
    if(inChar == 'S') {
      isMessage = true;
      Serial.print("Start \n");
    } else {
      Serial.read();
    }
  } else if (isMessage && availableBytes == MESSAGELENGTH) {
    Serial.print("Message \n");
    int stringCounter = 0;
    int messageCounter = 0;
    for(int i = 0; i < MESSAGELENGTH; i++) {
      
      readString[stringCounter] = Serial.read();
      
      if(stringCounter < 2) {
        stringCounter++;
      } else {
        message[messageCounter] = atoi(readString);        
        Serial.print("Value \n");
        Serial.print(message[messageCounter]);
        Serial.print("\n");
        stringCounter = 0;
        messageCounter++;
      }      
      analogWrite(channel1PinR, message[0]);  
      analogWrite(channel1PinG, message[1]); 
      analogWrite(channel1PinB, message[2]);            
      
      analogWrite(channel2PinR, message[3]);  
      analogWrite(channel2PinG, message[4]); 
      analogWrite(channel2PinB, message[5]);
    }
    
    isMessage = false;
  }
}
