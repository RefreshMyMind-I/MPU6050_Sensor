#include "MPU6050.h"

int Ascale = GFS_250DPS;
int Gscale = AFS_2G;

float MPU6050::getG()
{
    switch (Gscale)
    {
    case GFS_250DPS:
        return 250.0 / 32768.0;
        break;
    case GFS_500DPS:
        return 500.0 / 32768.0;
        break;
    case GFS_1000DPS:
        return 1000.0 / 32768.0;
        break;
    case GFS_2000DPS:
        return 2000.0 / 32768.0;
        break;
    }
}

float MPU6050::getA()
{
    switch (Ascale)
    {
    case AFS_2G:
        return 2.0 / 32768.0;
        break;
    case AFS_4G:
        return 4.0 / 32768.0;
        break;
    case AFS_8G:
        return 8.0 / 32768.0;
        break;
    case AFS_16G:
        return 16.0 / 32768.0;
        break;
    }
}

void MPU6050::readAccelData(int16_t *destination)
{

    uint8_t rawData[6];
    readBytes(MPU6050_ADDRESS, GYRO_XOUT_H, 6, &rawData[0]);
    destination[0] = (int16_t)((rawData[0]<<8 ) | rawData[1]);
    destination[1] = (int16_t)((rawData[2] << 8) | rawData[3]) ;
    destination[2] = (int16_t)((rawData[4] << 8) | rawData[5]) ;
}   

void MPU6050::initMPU6050(){
    writeByte(MPU6050_ADDRESS,PWR_MGMT_1,0x01);
    
}