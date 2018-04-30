#include <IRLib.h>

int RECV_PIN = 11;
int led1 = 50;
int led2 = 51;
int led3 = 52;
int led4 = 53;
IRrecv My_Receiver(RECV_PIN);

IRdecode My_Decoder;
unsigned int Buffer[RAWBUF];
#define prender1  0x4FBC837
#define prender2  0x4FB08F7
#define prender3  0x4FB8877
#define prender4  0x4FB8A75

#define apagar1  0x4FBF00F
#define apagar2  0x4FB30CF
#define apagar3  0x4FBB04F
#define apagar4  0x4FBB24D

#define offall   0x4FB708F
#define onall   0x4FB32CD

void setup()
{
  Serial.begin(9600);
  delay(2000);while(!Serial);//delay for Leonardo
  My_Receiver.enableIRIn(); 
  My_Decoder.UseExtnBuf(Buffer);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
}

void loop() {
  if (My_Receiver.GetResults(&My_Decoder)) {
    My_Receiver.resume(); 
    My_Decoder.decode();
    //My_Decoder.DumpResults();
    Serial.println(My_Decoder.value,HEX);
   //////////////////////////////////////////////////////////////////////
    
    if(My_Decoder.value==prender1)                                     
    {
     
    digitalWrite(led1,HIGH);
   
    }
   if(My_Decoder.value==apagar1) 
    { 
    digitalWrite(led1,LOW);
    }
    ////////////////////////////////////////////////////////////////////////
    if(My_Decoder.value==prender2) //codigo de l contorl sin declarar
    { 
    digitalWrite(led2,HIGH);
    
    }
     if(My_Decoder.value==apagar2) //codigo de l contorl sin declarar
    { 
    digitalWrite(led2,LOW);
    
    }
    ////////////////////////////////////////////////////////////////////////////
     if(My_Decoder.value==prender3) //codigo de l contorl sin declarar
    { 
    digitalWrite(led3,HIGH);
    
    }
     if(My_Decoder.value==apagar3) //codigo de l contorl sin declarar
    { 
    digitalWrite(led3,LOW);
    
    }
   /////////////////////////////////////////////////////////////////////////////
     if(My_Decoder.value==prender4) //codigo de l contorl sin declarar
    { 
    digitalWrite(led4,HIGH);
    
    }
     if(My_Decoder.value==apagar4) //codigo de l contorl sin declarar
    { 
    digitalWrite(led4,LOW);
    
    }
    ///////////////////////////////////////////////////////////////////////////////
     if(My_Decoder.value==offall) //codigo de l contorl sin declarar
    { 
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    
    }
     if(My_Decoder.value==onall) //codigo de l contorl sin declarar
    { 
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);    
    }
    ///////////////////////////////////////////////////////////////////////////////
  }
}

