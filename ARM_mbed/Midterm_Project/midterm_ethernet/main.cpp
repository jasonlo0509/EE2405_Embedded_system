#include "mbed.h"
#include "mbed_rpc.h"
#include "EthernetInterface.h"
#include "HTTPServer.h"
#include "MPU6050.h"
#include "uLCD_4DGL.h"

/**
  *  This example program has been updated to use the RPC    implementation in the new mbed libraries.
  *  This example demonstrates using RPC over serial
  */
  
#define UINT14_MAX        16383
// FXOS8700CQ I2C address
#define FXOS8700CQ_SLAVE_ADDR0 (0x1E<<1) // with pins SA0=0, SA1=0
#define FXOS8700CQ_SLAVE_ADDR1 (0x1D<<1) // with pins SA0=1, SA1=0
#define FXOS8700CQ_SLAVE_ADDR2 (0x1C<<1) // with pins SA0=0, SA1=1
#define FXOS8700CQ_SLAVE_ADDR3 (0x1F<<1) // with pins SA0=1, SA1=1
// FXOS8700CQ internal register addresses
#define FXOS8700Q_STATUS 0x00
#define FXOS8700Q_OUT_X_MSB 0x01
#define FXOS8700Q_OUT_Y_MSB 0x03
#define FXOS8700Q_OUT_Z_MSB 0x05
#define FXOS8700Q_M_OUT_X_MSB 0x33
#define FXOS8700Q_M_OUT_Y_MSB 0x35
#define FXOS8700Q_M_OUT_Z_MSB 0x37
#define FXOS8700Q_WHOAMI 0x0D
#define FXOS8700Q_XYZ_DATA_CFG 0x0E
#define FXOS8700Q_CTRL_REG1 0x2A
#define FXOS8700Q_M_CTRL_REG1 0x5B
#define FXOS8700Q_M_CTRL_REG2 0x5C
#define FXOS8700Q_WHOAMI_VAL 0xC7
// Set the Pin Position
MPU6050 ark(D14,D15);
I2C i2c( D14, D15 );
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;

int m_addr = FXOS8700CQ_SLAVE_ADDR1;
string buff;
uint8_t res[6];
uint8_t who_am_i, data[2];
int16_t acc16;
float t[3];
float gyro[3], RSS;
bool fall;
float acce[3];
int X, Y;

void getData(void);

Serial pc(USBTX, USBRX);
void ACCControl(Arguments *in, Reply *out);
RPCFunction rpcACC(&ACCControl, "ACCControl");
float x;
EthernetInterface eth;
HTTPServer svr;

int main() {
    //The mbed RPC classes are now wrapped to create an RPC enabled version - see RpcClasses.h so don't add to base class
    // receive commands, and send back the responses
    printf("Setting up...\n");
    eth.init();
    int ethErr = eth.connect();
    if(ethErr < 0)
    {
        printf("Error %d in setup.\n", ethErr);
        return -1;
    }
    svr.addHandler<HTTPRpcRequestHandler>("/rpc");
    //attach server to port 80
    svr.start(80, &eth);
    printf("Listening...\n");

    Timer tm;
    tm.start();

    //Listen indefinitely
    while(true)
    {
        svr.poll();
        
        if(tm.read()>.5)
        {
            tm.start();
        }
        ark.getGyro(gyro);
        RSS = sqrt((gyro[0]*gyro[0]) + (gyro[1]*gyro[1]) + (gyro[2]*gyro[2]));// count the absolute value of the gyroscope
    
        ark.getAccelero(acce);
        //pc.printf("Acce0= %f , Acce1= %f ,Acce2= %f \r\n",acce[0],acce[1],acce[2]);
    
        X = acce[0];
        Y = acce[2];
        if (RSS > 80 && abs(acce[1])< 7)
        {
            fall = true;
            uLCD.cls();
            uLCD.text_char('F', 9, 8, RED);
        }
        else
        {
            fall = false;
            uLCD.cls();
            uLCD.filled_circle(5*X+60, 5*Y+60, 4, GREEN);
        }
        
    }
}

// Make sure the method takes in Arguments and Reply objects.
void ACCControl (Arguments *in, Reply *out)   {
    bool success = true;
    // In this scenario, when using RPC delimit the one argument with a space.
    x = in->getArg<double>();
    // Have code here to call another RPC function to wake up specific led or close it.
    char buffer[200], outbuf[256];
    char strings[50];
    // Get the 3-axis accelerometer info.
    //getData();
    
    int n = sprintf(strings, "fall? %d, X = %d, Y = %d \r\n", fall, 5*X+60, 5*Y+60);
    strcpy(buffer, strings);
    if (success) {
        out->putData(buffer);
    } else {
        out->putData("Failed to execute Accelerometer control.");
    }
}

