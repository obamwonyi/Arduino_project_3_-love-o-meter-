
const int sensor_pin = A0;
const float baseline_temp = 20.0;

void setup() {
  Serial.begin(9600);

  for (int pinNumber = 2; pinNumber < 5; pinNumber++)
  {
    //set the current pinNumber as output pin
    pinMode(pinNumber, OUTPUT);
    //write LOW to it
    digitalWrite(pinNumber, LOW);
  }
  

}

void loop() {
 int sensor_val = analogRead(sensor_pin);
 //stores the voltage on the pin
 float voltage = (sensor_val/1024.0) * 5;
 float temperature = (voltage - 0.5) * 100.0;

 Serial.print("Sensor Value: ");
 Serial.println(sensor_val);

 Serial.print("Volts: ");
 Serial.println(voltage);

 Serial.print("Degrees C: ");
 Serial.println(temperature);

 Serial.println("                       ");

 if (temperature < baseline_temp + 2)
 {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
 }


 delay(250);
}
