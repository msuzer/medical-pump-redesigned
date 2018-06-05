namespace AsyncSocketClient
{
    class Instructions
    {
        public const string LOOPBACK_STRING = "HelloWorld!";

        public const string SPECIAL_SIGN_UP_COUNT = "+";
        public const string SPECIAL_SIGN_PRT_COUNTER = "?";
        public const string SPECIAL_SIGN_RST_COUNTER = "!";
        public const string SPECIAL_SIGN_RST_PASS = "0123456789abcdef";

        //MainBoard Part0
        public const string MB_BOARD_NAME = "MainBoard";
        public const string MB_PRINT_SENSORS1 = "A";
        public const string MB_PRINT_TEMPERATURE = "B";
        public const string MB_GET_ALL_LEDS = "C";
        public const string MB_SET_SINGLE_LED = "D"; //Ex: "D311", "E301"
        public const string MB_SET_ALL_LEDS = "E"; //Ex: "E 11100101010101"
        public const string MB_RUN_PERISTATIC_PUMP = "FA";  //Ex: "FA -1500"
        public const string MB_FILL_PERISTATIC_PUMP = SPECIAL_SIGN_UP_COUNT + "FB";  //Ex: "FB 500"
        public const string MB_LOCK_EL_SENS = "G";
        public const string MB_INS_PIC24FJ = "H";
        public const string MB_INS_DSPIC33FJ = "I";
        public const string MB_INS_BALANCER = "J";
        public const string MB_PRINT_BOARD_NET_CONFIG = "K";
        public const string MB_SET_BOARD_IP = "L";
        public const string MB_LOOPBACK_TEST1 = "M" + LOOPBACK_STRING;
        public const string MB_PRINT_FW_VER1 = "N";

        public const string MB_BALANCER1_PRINT_ONCE = MB_INS_BALANCER + "1A0I"; // I: Integer Format, F: Floating Point Format
        public const string MB_BALANCER2_PRINT_ONCE = MB_INS_BALANCER + "2A0I";
        public const string MB_BALANCER1_PRINT_CONT = MB_INS_BALANCER + "1A1I";
        public const string MB_BALANCER2_PRINT_CONT = MB_INS_BALANCER + "2A1I";
        public const string MB_BALANCER1_RESET_TARE = MB_INS_BALANCER + "1B";
        public const string MB_BALANCER2_RESET_TARE = MB_INS_BALANCER + "2B";
        public const string MB_BALANCER1_RESET = MB_INS_BALANCER + "1C";
        public const string MB_BALANCER2_RESET = MB_INS_BALANCER + "2C";
        public const string MB_BALANCER1_CALIBRATE = MB_INS_BALANCER + "1D";
        public const string MB_BALANCER2_CALIBRATE = MB_INS_BALANCER + "2D";
        public const string MB_BALANCER1_SET_GAIN = MB_INS_BALANCER + "1E";
        public const string MB_BALANCER2_SET_GAIN = MB_INS_BALANCER + "2E";

        //MainBoard Part1
        public const string MB_PRINT_SENSORS2 = MB_INS_PIC24FJ+ "A";
        public const string MB_TEST_DC_MOTOR0_SENSORS = MB_INS_PIC24FJ + "B";
        public const string MB_EL_SENS = MB_INS_PIC24FJ + "C";
        public const string MB_INS_DC_MOTORS = MB_INS_PIC24FJ + "D";
        public const string MB_INS_RFID = MB_INS_PIC24FJ + "E";
        public const string MB_LOOPBACK_TEST2 = MB_INS_PIC24FJ + "F" + LOOPBACK_STRING;
        public const string MB_PRINT_FW_VER2 = MB_INS_PIC24FJ + "G";

        public const string MB_RUN_DC_MOTOR0CW = MB_INS_DC_MOTORS + "011";
        public const string MB_RUN_DC_MOTOR1CW = MB_INS_DC_MOTORS + "111";
        public const string MB_RUN_DC_MOTOR2CW = MB_INS_DC_MOTORS + "211";
        public const string MB_RUN_DC_MOTOR3CW = MB_INS_DC_MOTORS + "311";
        public const string MB_RUN_DC_MOTOR4CW = MB_INS_DC_MOTORS + "411";
        public const string MB_RUN_DC_MOTOR5CW = MB_INS_DC_MOTORS + "511";
        public const string MB_RUN_DC_MOTOR6CW = MB_INS_DC_MOTORS + "611";
        public const string MB_RUN_DC_MOTOR7CW = MB_INS_DC_MOTORS + "711";
        public const string MB_RUN_DC_MOTOR0CCW = MB_INS_DC_MOTORS + "001";
        public const string MB_RUN_DC_MOTOR1CCW = MB_INS_DC_MOTORS + "101";
        public const string MB_RUN_DC_MOTOR2CCW = MB_INS_DC_MOTORS + "201";
        public const string MB_RUN_DC_MOTOR3CCW = MB_INS_DC_MOTORS + "301";
        public const string MB_RUN_DC_MOTOR4CCW = MB_INS_DC_MOTORS + "401";
        public const string MB_RUN_DC_MOTOR5CCW = MB_INS_DC_MOTORS + "501";
        public const string MB_RUN_DC_MOTOR6CCW = MB_INS_DC_MOTORS + "601";
        public const string MB_RUN_DC_MOTOR7CCW = MB_INS_DC_MOTORS + "701";
        public const string MB_STOP_DC_MOTOR0 = MB_INS_DC_MOTORS + "000";
        public const string MB_STOP_DC_MOTOR1 = MB_INS_DC_MOTORS + "100";
        public const string MB_STOP_DC_MOTOR2 = MB_INS_DC_MOTORS + "200";
        public const string MB_STOP_DC_MOTOR3 = MB_INS_DC_MOTORS + "300";
        public const string MB_STOP_DC_MOTOR4 = MB_INS_DC_MOTORS + "400";
        public const string MB_STOP_DC_MOTOR5 = MB_INS_DC_MOTORS + "500";
        public const string MB_STOP_DC_MOTOR6 = MB_INS_DC_MOTORS + "600";
        public const string MB_STOP_DC_MOTOR7 = MB_INS_DC_MOTORS + "700";

        public const string MB_RFID1_PRINT_TAG_ONCE = MB_INS_RFID + "199A0";
        public const string MB_RFID2_PRINT_TAG_ONCE = MB_INS_RFID + "299A0";
        public const string MB_RFID1_PRINT_TAG_CONT = MB_INS_RFID + "199A1";
        public const string MB_RFID2_PRINT_TAG_CONT = MB_INS_RFID + "299A1";
        public const string MB_RFID1_WRITE_TAG = MB_INS_RFID + "199B";
        public const string MB_RFID2_WRITE_TAG = MB_INS_RFID + "299B";
        public const string MB_RFID1_SET_RELAY = MB_INS_RFID + "199C";
        public const string MB_RFID2_SET_RELAY = MB_INS_RFID + "299C";
        public const string MB_RFID1_UPDATE_DEVID = MB_INS_RFID + "199D"; //Ex: "199D88"
        public const string MB_RFID2_UPDATE_DEVID = MB_INS_RFID + "299D"; //Ex: "299D88"
        public const string MB_RFID1_RESET_DEVID = MB_INS_RFID + "199E"; //Ex: "199E"
        public const string MB_RFID2_RESET_DEVID = MB_INS_RFID + "299E"; //Ex: "299E"
        public const string MB_RFID1_PRINT_FW_VERSION = MB_INS_RFID + "199F";
        public const string MB_RFID2_PRINT_FW_VERSION = MB_INS_RFID + "299F";

        //MainBoard Part2
        public const string MB_PRINT_SENSORS3 = MB_INS_DSPIC33FJ + "A";
        public const string MB_PRINT_QEI_COUNTERS = MB_INS_DSPIC33FJ + "B0";
        public const string MB_PRINT_QEI_COUNTERS_CONT = MB_INS_DSPIC33FJ + "B1";
        public const string MB_RESET_QEI_COUNTER1 = MB_INS_DSPIC33FJ + "C1";
        public const string MB_RESET_QEI_COUNTER2 = MB_INS_DSPIC33FJ + "C2";
        public const string MB_RESET_STEPPER_DRIVERS = MB_INS_DSPIC33FJ + "D";

        public const string MB_STEPPER1_PRINT_MARK_POSITION = MB_INS_DSPIC33FJ + "E1";
        public const string MB_STEPPER2_PRINT_MARK_POSITION = MB_INS_DSPIC33FJ + "E2";
        public const string MB_STEPPER1_SET_MARK_POSITION = MB_INS_DSPIC33FJ + "F1";
        public const string MB_STEPPER2_SET_MARK_POSITION = MB_INS_DSPIC33FJ + "F2";
        public const string MB_STEPPER1_SET_HOME_POSITION = MB_INS_DSPIC33FJ + "G1";
        public const string MB_STEPPER2_SET_HOME_POSITION = MB_INS_DSPIC33FJ + "G2";
        public const string MB_STEPPER1_GOTO_MARK_POSITION = MB_INS_DSPIC33FJ + "H1";
        public const string MB_STEPPER2_GOTO_MARK_POSITION = MB_INS_DSPIC33FJ + "H2";
        public const string MB_STEPPER1_GOTO_HOME_POSITION = MB_INS_DSPIC33FJ + "I1";
        public const string MB_STEPPER2_GOTO_HOME_POSITION = MB_INS_DSPIC33FJ + "I2";
        public const string MB_STEPPER1_GOTO_POSITION = MB_INS_DSPIC33FJ + "J1";
        public const string MB_STEPPER2_GOTO_POSITION = MB_INS_DSPIC33FJ + "J2";
        public const string MB_STEPPER1_MOVE_STEPS = MB_INS_DSPIC33FJ + "K1";
        public const string MB_STEPPER2_MOVE_STEPS = MB_INS_DSPIC33FJ + "K2";
        public const string MB_STEPPER1_IS_RUNNING = MB_INS_DSPIC33FJ + "L1";
        public const string MB_STEPPER2_IS_RUNNING = MB_INS_DSPIC33FJ + "L2";
        public const string MB_STEPPER1_PRINT_END_POSITIONS = MB_INS_DSPIC33FJ + "M1";
        public const string MB_STEPPER2_PRINT_END_POSITIONS = MB_INS_DSPIC33FJ + "M2";
        public const string MB_STEPPER1_SET_END_POSITIONS = MB_INS_DSPIC33FJ + "N1";
        public const string MB_STEPPER2_SET_END_POSITIONS = MB_INS_DSPIC33FJ + "N2";
        public const string MB_STEPPER1_PRINT_TASK_RESULT = MB_INS_DSPIC33FJ + "O1";
        public const string MB_STEPPER2_PRINT_TASK_RESULT = MB_INS_DSPIC33FJ + "O2";
        public const string MB_STEPPER1_SELECT_STEP_MODE = MB_INS_DSPIC33FJ + "P1";
        public const string MB_STEPPER2_SELECT_STEP_MODE = MB_INS_DSPIC33FJ + "P2";

        public const string MB_LOOPBACK_TEST3 = MB_INS_DSPIC33FJ + "Q" + LOOPBACK_STRING;
        public const string MB_PRINT_FW_VER3 = MB_INS_DSPIC33FJ + "R";

        //SSRBoard
        public const string SSRB_BOARD_NAME = "SSRBoard";
        public const string SSRB_PRINT_SENSORS = "A";
        public const string SSRB_PRINT_ALL_SOLENOIDS = "B";
        public const string SSRB_SET_SINGLE_SOLENOID = "C"; //Ex: "C3 1", "C3 0"
        public const string SSRB_SET_ALL_SOLENOIDS = "D"; //Ex: "D 1110"
        public const string SSRB_PRINT_ALL_SSRS = "E";
        public const string SSRB_SET_SINGLE_SSR = "F"; //Ex: "F3 1", "F3 0"
        public const string SSRB_SET_ALL_SSRS = "G"; //Ex: "G 11100101010101"
        public const string SSRB_PRINT_BOARD_NET_CONFIG = "H";
        public const string SSRB_SET_BOARD_IP = "I";
        public const string SSRB_LOOPBACK_TEST = "J" + LOOPBACK_STRING;
        public const string SSRB_PRINT_FW_VER = "K";

        //SensorBoard
        public const string SB_BOARD_NAME = "SensorBoard";
        public const string SB_PRINT_SENSORS = "A";
        public const string SB_PRINT_ADC_VALUES_ONCE = "B0";
        public const string SB_PRINT_ADC_VALUES_CONT = "B1";
        public const string SB_PRINT_ALL_SOLENOIDS = "C";
        public const string SB_SET_SINGLE_SOLENOID = "D"; //Ex: "D311", "D301"
        public const string SB_SET_ALL_SOLENOIDS = "E"; //Ex: "E 11100101010101"
        public const string SB_INS_DC_MOTORS = "F";  //Ex: "FA -1500"
        public const string SB_EXECUTE_CMD1 = "G1";
        public const string SB_EXECUTE_CMD2 = "G2";
        public const string SB_PRINT_ACTIVITY_LOGS = "H";
        public const string SB_PRINT_CALENDAR = "I";
        public const string SB_SET_CALENDAR = "J";
        public const string SB_CLEAR_FLASH_CHIP = "K";
        public const string SB_PRINT_BOARD_NET_CONFIG = "L";
        public const string SB_SET_BOARD_IP = "M";
        public const string SB_RUN_STATE_MACHINE3 = "N";
        public const string SB_LOOPBACK_TEST = "O" + LOOPBACK_STRING;
        public const string SB_PRINT_FW_VER = "P";

        public const string SB_RUN_DC_MOTOR0CW = SB_INS_DC_MOTORS + "011";
        public const string SB_RUN_DC_MOTOR1CW = SB_INS_DC_MOTORS + "111";
        public const string SB_RUN_DC_MOTOR2CW = SB_INS_DC_MOTORS + "211";
        public const string SB_RUN_DC_MOTOR3CW = SB_INS_DC_MOTORS + "311";
        public const string SB_RUN_DC_MOTOR0CCW = SB_INS_DC_MOTORS + "001";
        public const string SB_RUN_DC_MOTOR1CCW = SB_INS_DC_MOTORS + "101";
        public const string SB_RUN_DC_MOTOR2CCW = SB_INS_DC_MOTORS + "201";
        public const string SB_STOP_DC_MOTOR0 = SB_INS_DC_MOTORS + "000";
        public const string SB_STOP_DC_MOTOR1 = SB_INS_DC_MOTORS + "100";
        public const string SB_STOP_DC_MOTOR2 = SB_INS_DC_MOTORS + "200";
        public const string SB_STOP_DC_MOTOR3 = SB_INS_DC_MOTORS + "300";
    }
}
