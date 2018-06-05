#include "ui.h"
#include "hal.h"
#include "../../UserLibraries/MicrochipXC/utils/bin2str.h"
#include <stdio.h>

unsigned int speed;
int mode, steps, position, end_bw, end_fw;
UINT32_VAL endPositions1, endPositions2;
UINT16_VAL mark1, mark2;

void backup_user_data(void) {
    mark1.Val = StepperMotor.GetMark(STEPPER_MOTOR1);
    mark2.Val = StepperMotor.GetMark(STEPPER_MOTOR2);
    endPositions1 = StepperMotor.GetEndPositions(STEPPER_MOTOR1);
    endPositions2 = StepperMotor.GetEndPositions(STEPPER_MOTOR2);

    if (mark1.byte.HB != DataEERead(1))
        DataEEWrite(mark1.byte.HB, 1);
    if (mark1.byte.LB != DataEERead(2))
        DataEEWrite(mark1.byte.LB, 2);

    if (mark2.byte.HB != DataEERead(3))
        DataEEWrite(mark2.byte.HB, 3);
    if (mark2.byte.LB != DataEERead(4))
        DataEEWrite(mark2.byte.LB, 4);

    if (endPositions1.byte.MB != DataEERead(5))
        DataEEWrite(endPositions1.byte.MB, 5);
    if (endPositions1.byte.UB != DataEERead(6))
        DataEEWrite(endPositions1.byte.UB, 6);
    if (endPositions1.byte.HB != DataEERead(7))
        DataEEWrite(endPositions1.byte.HB, 7);
    if (endPositions1.byte.LB != DataEERead(8))
        DataEEWrite(endPositions1.byte.LB, 8);

    if (endPositions2.byte.MB != DataEERead(9))
        DataEEWrite(endPositions2.byte.MB, 9);
    if (endPositions2.byte.UB != DataEERead(10))
        DataEEWrite(endPositions2.byte.UB, 10);
    if (endPositions2.byte.HB != DataEERead(11))
        DataEEWrite(endPositions2.byte.HB, 11);
    if (endPositions2.byte.LB != DataEERead(12))
        DataEEWrite(endPositions2.byte.LB, 12);

    if (DataEERead(0) != 0x55)
        DataEEWrite(0x55, 0);
}

void restore_user_data(void) {
    if (DataEERead(0) == 0x55) {
        mark1.byte.HB = DataEERead(1);
        mark1.byte.LB = DataEERead(2);
        mark2.byte.HB = DataEERead(3);
        mark2.byte.LB = DataEERead(4);

        endPositions1.byte.MB = DataEERead(5);
        endPositions1.byte.UB = DataEERead(6);
        endPositions1.byte.HB = DataEERead(7);
        endPositions1.byte.LB = DataEERead(8);

        endPositions2.byte.MB = DataEERead(9);
        endPositions2.byte.UB = DataEERead(10);
        endPositions2.byte.HB = DataEERead(11);
        endPositions2.byte.LB = DataEERead(12);

        StepperMotor.SetMark(STEPPER_MOTOR1, mark1.Val);
        StepperMotor.SetMark(STEPPER_MOTOR2, mark2.Val);

        StepperMotor.SetEndPositions(STEPPER_MOTOR1, endPositions1.word.LW, endPositions1.word.HW);
        StepperMotor.SetEndPositions(STEPPER_MOTOR2, endPositions2.word.LW, endPositions2.word.HW);
    }
}

static void ParseAndApplyCommand(char * param) {
    UserInstructions instruction = (UserInstructions) param[0];
    char * args = &param[1];
    char channel = *args;

    switch (instruction) {
        case PRINT_SENSORS:
            COMPort.printf(COM1, "ExtSens: %s", bin2str(GetSensors().Val, 6));
            DataEEWrite(0, 0);
            break;
        case PRINT_QEI_COUNTERS:
            if (channel == '1') {
                COMPort.println(COM1, "Reading Encoders Continuously!");
                set_report_qei(TRUE);
            } else {
                set_report_qei(FALSE);
                COMPort.printf(COM1, "QEI1: %06d QEI2: %06d", QEIModule.Read(QEI_CH1), QEIModule.Read(QEI_CH2));
            }
            break;
        case RESET_QEI_COUNTERS:
            QEIModule.Reset(channel);
            COMPort.printf(COM1, "<QEI%c> Module reset!", channel);
            break;
        case RESET_STEPPER_DRIVERS:
            StepperMotor.Init(NULL);
            COMPort.println(COM1, "Stepper Drivers reset!");
            break;
        case STEPPER_PRINT_MARK_POSITION:
            COMPort.printf(COM1, "<Stepper%c> Mark position: %d", channel, StepperMotor.GetMark(channel));
            break;
        case STEPPER_SET_MARK_POSITION:
            StepperMotor.SetMark(channel, QEIModule.Read(channel));
            //backup_user_data();
            COMPort.printf(COM1, "<Stepper%c> Set MARK position to: %d", channel, StepperMotor.GetMark(channel));
            break;
        case STEPPER_SET_HOME_POSITION:
            QEIModule.Reset(channel);
            COMPort.printf(COM1, "<Stepper%c> Set HOME position!", channel);
            break;
        case STEPPER_GOTO_MARK_POSITION:
            if (sscanf(++args, "%d", &speed) == 1) {
                StepperMotor.GotoMark(channel, speed);
                COMPort.printf(COM1, "<Stepper%c> Going to MARK position!", channel);
            }
            break;
        case STEPPER_GOTO_HOME_POSITION:
            if (sscanf(++args, "%d", &speed) == 1) {
                StepperMotor.GotoHome(channel, speed);
                COMPort.printf(COM1, "<Stepper%c> Going to HOME position!", channel);
            }
            break;
        case STEPPER_GOTO_POSITION:
            if (sscanf(++args, "%d%d", &speed, &position) == 2) {
                StepperMotor.GotoPos(channel, speed, position);
                if (speed != 0)
                    COMPort.printf(COM1, "<Stepper%c> Going to: %d, speed: %d", channel, position, speed);
            } else {
                COMPort.println(COM1, "I need 2 parameters!");
            }
            break;
        case STEPPER_MOVE_STEPS:
            if (sscanf(++args, "%d%d", &speed, &steps) == 2) {
                StepperMotor.MoveSteps(channel, speed, steps);
                COMPort.printf(COM1, "<Stepper%c> Moves %d steps", channel, steps);
            } else {
                COMPort.println(COM1, "I need 2 parameters!");
            }
            break;
        case STEPPER_IS_RUNNING:
            if (StepperMotor.IsStepperRunning(channel))
                COMPort.printf(COM1, "<Stepper%c> Running!", channel);
            else
                COMPort.printf(COM1, "<Stepper%c> Not running!", channel);
            break;
        case STEPPER_PRINT_END_POSITIONS:
            endPositions1 = StepperMotor.GetEndPositions(channel);
            COMPort.printf(COM1, "<Stepper%c> BW end: %d, FW end: %d", channel, endPositions1.word.LW, endPositions1.word.HW);
            break;
        case STEPPER_SET_END_POSITIONS:
            if (sscanf(++args, "%d%d", &end_bw, &end_fw) == 2) {
                if (StepperMotor.SetEndPositions(channel, end_bw, end_fw)) {
                    //backup_user_data();
                    COMPort.printf(COM1, "<Stepper%c> BW end: %d, FW end: %d", channel, end_bw, end_fw);
                } else {
                    COMPort.println(COM1, "Invalid end positions! (bw < fw ?)");
                }
            } else {
                COMPort.println(COM1, "I need 2 parameters!");
            }
            break;
        case STEPPER_PRINT_TASK_RESULT:
            StepperMotor.PrintTaskResult(channel);
            break;
        case STEPPER_SELECT_STEP_MODE:
            /*
             * (0x08), //full step
             * (0x09), //half step
             * (0x0A), //1/4 microstep
             * (0x0B), //1/8 microstep
             * (0x0C) //1/16 microstep
             */
            if (sscanf(++args, "%d", &mode) == 1) {
                if (StepperMotor.SelectStepMode(channel, mode))
                    COMPort.printf(COM1, "<Stepper%c> Set step mode!", channel);
                else
                    COMPort.println(COM1, "Invalid Step Mode!");
            }
            break;
        case BOARD_LOOPBACK:
            COMPort.printf(COM1, "LoopBack test: \"%s\"", args);
            break;
        case PRINT_FW_VER:
            COMPort.println(COM1, "Step Motor Controller v2.1");
            break;
        default:
            COMPort.printf(COM1, "Invalid instruction!: \"%s\"", param);
            break;
    }
}

void CheckUpUserInstruction(void) {
    if (COMPort.GetMessageLen(COM1) > 0) {
        ParseAndApplyCommand(COMPort.GetMessage(COM1));
    }
}
