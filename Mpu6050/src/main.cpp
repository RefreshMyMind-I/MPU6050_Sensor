#include "Wire.h"
#include <Arduino.h>
#define MPU6050_ADDR 0x68 // Alternatively set AD0 to HIGH  --> Address = 0x69
double filx, fily, filz;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission();
}
void loop()
{
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 14, true);
  double accX = Wire.read() << 8 | Wire.read();
  Serial.print("AcX = ");
  Serial.println(accX);

  Wire.write(0x3C);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 14, true);
  double accY = Wire.read() << 8 | Wire.read();
  Serial.print("AcY = ");
  Serial.println(accY);

  Wire.write(0x3D);
  Wire.endTransmission();
  Wire.requestFrom(MPU6050_ADDR, 14, true);
  double accZ = Wire.read() << 8 | Wire.read();
  Serial.print("AcZ = ");
  Serial.println(accZ);
  delay(100);

  //simple filter
  filx = 0.94 * filx + 0.06 * accX;
  fily = 0.94 * fily + 0.06 * accY;
  filz = 0.94 * filz + 0.06 * accZ;
  Serial.print("Filtered X: ");
  Serial.print(filx);
  Serial.print("\t");
  Serial.pritn("Filtered Y: ");
  Serial.print(fily);
  Serial.pritn("\t");
  Serial.pritn("Filtered Z: ");
  Serial.print(filz);
  Serial.println(" ");
}
