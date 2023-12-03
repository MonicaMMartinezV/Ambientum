#include <DHT.h>

#define DHTPIN 0   // Pin de datos del sensor DHT11 conectado al GPIO4 del ESP32
#define port14 14
#define port12 12
#define port13 13
#define DHTTYPE DHT11   // Tipo del sensor DHT, en este caso DHT11


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  // Leer la temperatura y humedad del sensor
  float temperatura = dht.readTemperature();
  float humedad = dht.readHumidity();

  // Verificar si se pudo leer correctamente el sensor
  if (isnan(temperatura) || isnan(humedad)) {
    Serial.println("Error al leer el sensor DHT!");
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C, Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
  } else {
    // Mostrar los datos en el Monitor Serie
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.print(" °C, Humedad: ");
    Serial.print(humedad);
    Serial.println(" %");
    
    if (humedad > 85){      
      digitalWrite(port13, HIGH);
      digitalWrite(port12, LOW);
      digitalWrite(port13, LOW);
    }
    else if(humedad<80){
      digitalWrite(port14, HIGH);
      digitalWrite(port12, LOW);
      digitalWrite(port13, LOW);
    }
    else{
      /*digitalWrite(port13, HIGH);*/
      digitalWrite(port12, LOW);
      digitalWrite(port14, LOW);
    }
    // Puedes agregar aquí más código para enviar los datos a través de WiFi o Bluetooth, por ejemplo.
  }

  delay(5000); // Esperar 2 segundos antes de volver a leer los datos
}
