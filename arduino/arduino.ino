int giris = 13;
int giris_1_kapat = 3;
int giris_1_ac = 4;
int giris_2_kapat = 5;
int giris_2_ac = 6;
int giris_3_kapat = 7;
int giris_3_ac = 8;
int serial_value;

void setup() {                
  pinMode(giris, OUTPUT);    
  pinMode(giris_1_ac, OUTPUT); 
  pinMode(giris_1_kapat, OUTPUT); 
  pinMode(giris_2_ac, OUTPUT); 
  pinMode(giris_2_kapat, OUTPUT); 
  pinMode(giris_3_ac, OUTPUT); 
  pinMode(giris_3_kapat, OUTPUT);  
  Serial.begin(9600); 
}

void loop() {
     serial_value = Serial.read();
       
       if(serial_value != -1)
       {
         Serial.println(serial_value);
       }
     if(serial_value == 113){ //q
       digitalWrite(giris_1_kapat, HIGH);
       delay(2000);
       digitalWrite(giris_1_kapat, LOW);  
     }else if(serial_value == 119){ // w
       digitalWrite(giris_1_ac, HIGH);
       delay(2000); 
       digitalWrite(giris_1_ac, LOW); 
     }else if(serial_value == 101){ // e
       digitalWrite(giris_2_kapat, HIGH);
       delay(2000); 
       digitalWrite(giris_2_kapat, LOW); 
     }else if(serial_value == 114){ // r
       digitalWrite(giris_2_ac, HIGH);
       delay(2000); 
       digitalWrite(giris_2_ac, LOW); 
     }else if(serial_value == 116){ // t
       digitalWrite(giris_3_kapat, HIGH);
       delay(2000); 
       digitalWrite(giris_3_kapat, LOW); 
     }else if(serial_value == 121){ // y
       digitalWrite(giris_3_ac, HIGH);
       delay(2000); 
       digitalWrite(giris_3_ac, LOW); 
     }
     
}
