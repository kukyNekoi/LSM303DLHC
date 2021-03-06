/* (c) 2014 - Erik Regla Torres
 *
 *  This file is part of LSM303DLHC.
 *
 *  LSM303DLHC is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  LSM303DLHC is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with LSM303DLHC. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * LSM303DLHC.h
 *
 *  Created on: Jan 30, 2014
 *  Author: jvarred
 */

#ifndef LSM303DLHC_H_
#define LSM303DLHC_H_

namespace std {

#define MAGNETOMETER_ADDRESS    0x1E
#define ACCELEROMETER_ADDRESS   0x19

//Accelerometer constants

//Power options
#define LSM303DLHC_CTRL_REG1_A      0x20
#define LSM303DLHC_LPEN             0b00000000
#define LSM303DLHC_XEN              0b00000001
#define LSM303DLHC_YEN              0b00000010
#define LSM303DLHC_ZEN              0b00000100
#define LSM303DLHC_POWER_OFF        0b00001000
#define LSM303DLHC_POWER_1_HZ       0b00010000
#define LSM303DLHC_POWER_10_HZ      0b00100000
#define LSM303DLHC_POWER_25_HZ      0b00110000
#define LSM303DLHC_POWER_50_HZ      0b01000000
#define LSM303DLHC_POWER_100_HZ     0b01010000
#define LSM303DLHC_POWER_200_HZ     0b01100000
#define LSM303DLHC_POWER_400_HZ     0b01110000
#define LSM303DLHC_POWER_1620_HZ    0b10000000	//only for low power
#define LSM303DLHC_POWER_1344_HZ    0b10010000	//only for normal power
#define LSM303DLHC_POWER_5376_HZ    0b10010000	//only for low power

//Highpass filter settings
#define LSM303DLHC_CTRL_REG2_A                      0x21
#define LSM303DLHC_HIGHPASS_NORMAL_MODE             0b00000000
#define LSM303DLHC_HIGHPASS_REFERENCE_SIGNAL        0b00000001
#define LSM303DLHC_HIGHPASS_NORMAL_MODE_2           0b00000010
#define LSM303DLHC_HIGHPASS_AUTORESET               0b00000011
#define LSM303DLHC_HPCF1                            0b00010000
#define LSM303DLHC_HPCF2                            0b00100000
#define LSM303DLHC_FDS                              0b00001000
#define LSM303DLHC_HPCLICK                          0b00000100
#define LSM303DLHC_HPIS1                            0b00000001
#define LSM303DLHC_HPIS2                            0b00000010

//INTERRUPTS
#define LSM303DLHC_CTRL_REG3_A      0x22
#define LSM303DLHC_I1_CLICK         0b10000000
#define LSM303DLHC_I1_AOI1          0b01000000
#define LSM303DLHC_I1_AOI2          0b00100000
#define LSM303DLHC_I1_DRDY1         0b00010000
#define LSM303DLHC_I1_DRDY2         0b00001000
#define LSM303DLHC_I1_WTM           0b00000100
#define LSM303DLHC_I1_OVERRUN       0b00000010

//BLOCK DATA
#define LSM303DLHC_CTRL_REG4_A      0x23
#define LSM303DLHC_BDU              0b10000000
#define LSM303DLHC_BLE              0b01000000
#define LSM303DLHC_FS1              0b00100000
#define LSM303DLHC_FS0              0b00010000
#define LSM303DLHC_HR               0b00001000
#define LSM303DLHC_SIM              0b00000001

//MEMORY CONFIG
#define LSM303DLHC_CTRL_REG5_A      0x24
#define LSM303DLHC_BOOT             0b10000000
#define LSM303DLHC_FIFO_EN          0b01000000
#define LSM303DLHC_LIR_INT1         0b00001000
#define LSM303DLHC_D4D_INT1         0b00000100
#define LSM303DLHC_LIR_INT2         0b00000010
#define LSM303DLHC_D4D_INT2         0b00000001

//INTERRUPTS
#define LSM303DLHC_CTRL_REG6_A      0x25
#define LSM303DLHC_I2_CLICK_EN      0b10000000
#define LSM303DLHC_I2_INT1          0b01000000
#define LSM303DLHC_I2_INT2          0b00100000
#define LSM303DLHC_BOOT_I1          0b00010000
#define LSM303DLHC_P2_ACT           0b00001000
#define LSM303DLHC_H_LACTIVE        0b00000010

//DATA OVERRUN
#define LSM303DLHC_STATUS_REG_A     0X27
#define LSM303DLHC_ZXOR             0b10000000
#define LSM303DLHC_ZOR              0b01000000
#define LSM303DLHC_YOR              0b00100000
#define LSM303DLHC_XOR              0b00010000
#define LSM303DLHC_ZYDA             0b00001000
#define LSM303DLHC_ZDA              0b00000100
#define LSM303DLHC_YDA              0b00000010
#define LSM303DLHC_XDA              0b00000001

//OUTPUTS
#define LSM303DLHC_OUT_X_L_A        0X28
#define LSM303DLHC_OUT_X_H_A        0X29
#define LSM303DLHC_OUT_Y_L_A        0X2A
#define LSM303DLHC_OUT_Y_H_A        0X2B
#define LSM303DLHC_OUT_Z_L_A        0X2C
#define LSM303DLHC_OUT_Z_H_A        0X2D

//FIFO
#define LSM303DLHC_FIFO_CRTL_REG_A  0x2E
#define LSM303DLHC_FM1              0b10000000
#define LSM303DLHC_FM0              0b01000000
#define LSM303DLHC_TR               0b00100000
#define LSM303DLHC_FTH4             0b00010000
#define LSM303DLHC_FTH3             0b00001000
#define LSM303DLHC_FTH2             0b00000100
#define LSM303DLHC_FTH1             0b00000010
#define LSM303DLHC_FTH0             0b00000001

//DETECTION
#define LSM303DLHC_INT1_CFG_A       0x30
#define LSM303DLHC_AOI              0b10000000
#define LSM303DLHC_6D               0b01000000
#define LSM303DLHC_ZHIE_ZUPE        0b00100000
#define LSM303DLHC_ZLUE_ZDOWNE      0b00010000
#define LSM303DLHC_YHIE_YUPE        0b00001000
#define LSM303DLHC_YLUE_YDOWNE      0b00000100
#define LSM303DLHC_XHIE_XUPE        0b00000010
#define LSM303DLHC_XLIE_XDOWNE      0b00000001

//INTERRUPTS
#define LSM303DLHC_INT1_SRC_A       0x31
#define LSM303DLHC_IA               0b01000000
#define LSM303DLHC_ZH               0b00100000
#define LSM303DLHC_ZL               0b00010000
#define LSM303DLHC_YH               0b00001000
#define LSM303DLHC_YL               0b00000100
#define LSM303DLHC_XH               0b00000010
#define LSM303DLHC_XL               0b00000001

#define LSM303DLHC_INT1_THS_A       0x32
#define LSM303DLHC_INT1_DURATION_A  0x33

//INTERRUPTS
#define LSM303DLHC_INT2_CFG_A       0x34
#define LSM303DLHC_AOI              0b10000000
#define LSM303DLHC_6D               0b01000000
#define LSM303DLHC_ZHIE             0b00100000
#define LSM303DLHC_ZLUE             0b00010000
#define LSM303DLHC_YHIE             0b00001000
#define LSM303DLHC_YLUE             0b00000100
#define LSM303DLHC_XHIE             0b00000010
#define LSM303DLHC_XLIE             0b00000001

//INTERRUPTS
#define LSM303DLHC_INT2_SRC_A       0x35
#define LSM303DLHC_IA               0b01000000
#define LSM303DLHC_ZH               0b00100000
#define LSM303DLHC_ZL               0b00010000
#define LSM303DLHC_YH               0b00001000
#define LSM303DLHC_YL               0b00000100
#define LSM303DLHC_XH               0b00000010
#define LSM303DLHC_XL               0b00000001

#define LSM303DLHC_INT2_THS_A       0x36
#define LSM303DLHC_INT2_DURATION_A  0x37

//CLICK
#define LSM303DLHC_CLICK_CFG_A      0x38
#define LSM303DLHC_ZD               0b00100000
#define LSM303DLHC_ZS               0b00010000
#define LSM303DLHC_YD               0b00001000
#define LSM303DLHC_YS               0b00000100
#define LSM303DLHC_XD               0b00000010
#define LSM303DLHC_XS               0b00000001

//CLICK
#define LSM303DLHC_CLICK_SRC_A      0x39
#define LSM303DLHC_IA               0b01000000
#define LSM303DLHC_DCLICK           0b00100000
#define LSM303DLHC_SCLICK           0b00010000
#define LSM303DLHC_SIGN             0b00001000
#define LSM303DLHC_Z                0b00000100
#define LSM303DLHC_Y                0b00000010
#define LSM303DLHC_X                0b00000001

#define LSM303DLHC_CLICK_THS_A          0x3A
#define LSM303DLHC_CLICK_TIME_LIMIT_A   0x3B

//TIME
#define LSM303DLHC_TIME_LATENCY_A       0x3C
#define LSM303DLHC_TIME_WINDOW_A        0x3D

//Magnetometer constants

//DATA
#define LSM303DLHC_CRA_REG_M        0x00
#define LSM303DLHC_TEMP_EN          0b10000000
#define LSM303DLHC_DO2              0b00010000
#define LSM303DLHC_DO1              0b00001000
#define LSM303DLHC_DO0              0b00000100

//GAIN
#define LSM303DLHC_CRB_REG_M        0x01
#define LSM303DLHC_GN2              0b10000000
#define LSM303DLHC_GN1              0b01000000
#define LSM303DLHC_GN0              0b00100000

//SELECT
#define LSM303DLHC_MR_REG_M         0x02
#define LSM303DLHC_MD_1             0b00000010
#define LSM303DLHC_MD_0             0b00000001

//WRAPPER FOR MODE
#define LSM303DLHC_CONTINOUS_MODE   0b00000000
#define LSM303DLHC_SINGLE_MODE      0b00000001
#define LSM303DLHC_SLEEP_MODE_1     0b00000010
#define LSM303DLHC_SLEEP_MODE_2     0b00000011


#define LSM303DLHC_INPUT_GAIN_1     0x00
#define LSM303DLHC_INPUT_GAIN_2     0x01
#define LSM303DLHC_INPUT_GAIN_3     0x02
#define LSM303DLHC_INPUT_GAIN_4     0x03
#define LSM303DLHC_INPUT_GAIN_5     0x04
#define LSM303DLHC_INPUT_GAIN_6     0x05
#define LSM303DLHC_INPUT_GAIN_7     0x06
#define LSM303DLHC_INPUT_GAIN_8     0x07

#define LSM303DLHC_OUT_X_H_M        0x03
#define LSM303DLHC_OUT_X_L_M        0x04
#define LSM303DLHC_OUT_Y_H_M        0x07
#define LSM303DLHC_OUT_Y_L_M        0x08
#define LSM303DLHC_OUT_Z_H_M        0x05
#define LSM303DLHC_OUT_Z_L_M        0x06

#define LSM303DLHC_TEMP_OUT_H_M     0x31
#define LSM303DLHC_TEMP_OUT_L_M     0x32

typedef struct lsm303_t {
        double x;
        double y;
        double z;
} magdata_t;

class LSM303DLHC {
    private:
        int readAddress(int bus, int address);
        int writeAddress(int bus, int address, int value);
        float accelerometer_scale;
        float magnetometer_scale;

    public:
        LSM303DLHC();
        LSM303DLHC(const char *bus_path);
        ~LSM303DLHC();

        int i2c_magnetometer_handler;
        int i2c_accelerometer_handler;

        int set_device(int bus_handler, int deviceAddress);

        int init_magnetometer(  int speed = LSM303DLHC_DO2 | LSM303DLHC_DO1,
                                int gain = LSM303DLHC_GN0 ,
                                int conversion = LSM303DLHC_CONTINOUS_MODE);

        int init_accelerometer( int power = LSM303DLHC_XEN | LSM303DLHC_YEN | LSM303DLHC_ZEN | LSM303DLHC_POWER_1344_HZ,
                                int scale = LSM303DLHC_FS1);


        int read_accelerometer(lsm303_t *target);
        int read_magnetometer(lsm303_t *target);

};

} /* namespace std */

#endif /* LSM303DLHC_H_ */
