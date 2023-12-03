#include "UbidotsMicroESP8266.h"
// Este archivo incluye una actualizacion de las librerias de Ubidots y observaras
// al conectarte a Ubidots que se crea otro dispostivo (Device) automaticamente
// tienes que configurar las etiquetas segun el nuevo dispositivo que se crea
// y adicionar la variable var_led  .... todo lo demás es identico 

#include "Ubidots.h"
#include "DHT.h"

#define DEVICE  "8caab5c84aa0"  // Put here your Ubidots device label
#define VARIABLE  "temperatura"  // Put here your Ubidots variable label
#define VARIABLE2 "humedad"
//#define ID_TEMP "65492191f5491d000ea311b1" 
//#define ID_HUM "65492192f5491d000ea311b2"
#define ID_HUM "654926ab53bd73000dc3e685"
//#define ID_TEMP "65492191f5491d000ea311b1"
#define ID_TEMP "65492191f5491d000ea311b1"
#define TOKEN  "BBUS-bf8ddf7ff5c673c66265b17dafb4e75a14f"  // Put here your Ubidots TOKEN
//BBUS-LP3RtilhPAxVRtGhOLXuU1AUXZ1LwM default
//BBUS-bf8ddf7ff5c673c66265b17dafb4e75a14f   apii cred
#define WIFISSID "Moni" // Put here your Wi-Fi SSID
#define PASSWORD "12345678" // Put here your Wi-Fi password

#define portD3 0
#define portD0 16
#define portD1 5
#define portD2 4
#define portD4 2
#define portD8 15
#define portD7 13
#define type DHT11

DHT dht(portD3, type);

Ubidots client(TOKEN);
float Valor_Temperatura = 0;
float Valor_Humedad = 0;

WiFiServer server (80);
void setup() {
  pinMode(portD3, OUTPUT);
  pinMode(portD0, OUTPUT);
  pinMode(portD1, OUTPUT);
  pinMode(portD2, OUTPUT);
  pinMode(portD4, OUTPUT);
  pinMode(portD7, OUTPUT);
  pinMode(portD8, OUTPUT);
    dht.begin();
    Serial.begin(115200);
    //client.wifiConnect(WIFISSID, PASSWORD);

    WiFi.begin(WIFISSID, PASSWORD);
}

void loop() 
{
    float hume = dht.readHumidity();
    float temp = dht.readTemperature();

    Serial.println("------------------------------------");
    Serial.print("Temperatura: "); 
    Serial.print(temp);
    Serial.println("------------------------------------");
    Serial.print("Humedad: ");
    Serial.print(hume);
    Serial.println("------------------------------------");
    
    if (hume<60){      
      digitalWrite(portD2, HIGH);
      digitalWrite(portD0, LOW);
      digitalWrite(portD1, LOW);
    }
    else if(hume > 70){
      digitalWrite(portD0, HIGH);
      digitalWrite(portD1, LOW);
      digitalWrite(portD2, LOW);
    }
    else{
      digitalWrite(portD1, HIGH);
      digitalWrite(portD0, LOW);
      digitalWrite(portD2, LOW);
    }
    
    if (temp>22.5){      
      digitalWrite(portD4, HIGH);
      digitalWrite(portD7, LOW);
      digitalWrite(portD8, LOW);
    }
    else if(temp<20){
      digitalWrite(portD8, HIGH);
      digitalWrite(portD4, LOW);
      digitalWrite(portD7, LOW);
    }
    else{
      digitalWrite(portD7, HIGH);
      digitalWrite(portD8, LOW);
      digitalWrite(portD4, LOW);
    }

    Valor_Temperatura = temp;
    
    client.add(ID_TEMP, Valor_Temperatura); 
    client.send();

    Valor_Humedad = hume;
    
    client.add(ID_HUM, Valor_Humedad); 
    client.send();
    delay(3000);
}
