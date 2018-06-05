using System;
using System.Windows.Forms;
using System.Net;
using System.IO;
using System.Configuration;

namespace AsyncSocketClient
{
    public partial class AppMainForm : Form
    {
        private TCPClientSocket mbClient = null;
        private TCPClientSocket ssrbClient = null;
        private TCPClientSocket sbClient = null;
        private TCPServerSocket server = new TCPServerSocket();
        private UDPClientSocket discoverClient = new UDPClientSocket();
        private static AppMainForm frmInstance = null;
        private UserInputForm frmUserDialog = new UserInputForm();
        private bool showDebugMessages = false;
        private bool calibrationFormShown = false;

        public AppMainForm()
        {
            InitializeComponent();
            frmInstance = this;

            initTCPClients();
            server.GotDataFromCTC += GotDataFromCTC;
            server.Run();
            lstClients.Items.Add("None");

            //sSRBoardToolStripMenuItem.Visible = true;
            //sensorBoardToolStripMenuItem.Visible = true;
        }

        public static AppMainForm getInstance()
        {
            return frmInstance;
        }

        public void UnSetCalibrationFormStatus()
        {
            calibrationFormShown = false;
        }

        private void initTCPClients() {
            try
            {
                mbClient = new TCPClientSocket(IPAddress.Parse(ConfigurationManager.AppSettings["MainboardIP"]));
                ssrbClient = new TCPClientSocket(IPAddress.Parse(ConfigurationManager.AppSettings["SSRBoardIP"]));
                sbClient = new TCPClientSocket(IPAddress.Parse(ConfigurationManager.AppSettings["SensorBoardIP"]));
            }
            catch (Exception exc)
            {
                DebugMessage("ConfigurationManager.AppSettings: " + exc.Message);
            }
        }

        public void msg(string mesg)
        {
            try
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    txtResponse.Text += mesg + Environment.NewLine;
                }));
            }
            catch (Exception exc) { }
        }

        public void DebugMessage(string message)
        {
            if (showDebugMessages)
                msg(message);
        }

        public void SendMessage(string message)
        {
            mbClient.SendMessage(message);
        }

        private void WindowMenuItem_Click(object sender, EventArgs e)
        {
            switch ((sender as ToolStripMenuItem).Tag.ToString())
            {
                case "ClearLogs":
                    txtResponse.Text = "";
                    break;
                case "SaveLogsToFile":
                    if (saveFileDialog1.ShowDialog() == DialogResult.OK) {
                        try
                        {
                            StreamWriter sw = new StreamWriter(saveFileDialog1.FileName);
                            sw.Write(txtResponse.Text);
                            sw.Close();
                        } catch (Exception exc) {
                            MessageBox.Show(exc.Message);
                        }
                    }
                    break;
                case "Settings":
                    if ((new SettingsDialogForm()).ShowDialog() == DialogResult.OK) {
                        initTCPClients();
                    }
                    break;
            }
        }

        public void MainBoardMenuItem_Click(object sender, EventArgs e)
        {
            switch ((sender as ToolStripMenuItem).Tag.ToString())
            {
                case "PrintSensorsGroup1":
                    mbClient.SendMessage(Instructions.MB_PRINT_SENSORS1);
                    break;
                case "PrintSensorsGroup2":
                    mbClient.SendMessage(Instructions.MB_PRINT_SENSORS2);
                    break;
                case "PrintSensorsGroup3":
                    mbClient.SendMessage(Instructions.MB_PRINT_SENSORS3);
                    break;
                case "PrintTemperature":
                    mbClient.SendMessage(Instructions.MB_PRINT_TEMPERATURE);
                    break;
                case "PrintLEDs":
                    mbClient.SendMessage(Instructions.MB_GET_ALL_LEDS);
                    break;
                case "SetSingleLED":
                    frmUserDialog.setDialogBoxParameters("Enter LED Position, State and Blink", "#0", "0", "0");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_SET_SINGLE_LED +
                            frmUserDialog.getUserInput1() +
                            frmUserDialog.getUserInput2() +
                            frmUserDialog.getUserInput3());
                    }
                    break;
                case "SetAllLEDs":
                    frmUserDialog.setDialogBoxParameters("Enter LEDs State", "0000000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        try
                        {
                            Int32 state = Convert.ToInt32(frmUserDialog.getUserInput1(), 2);
                            mbClient.SendMessage(Instructions.MB_SET_ALL_LEDS + state.ToString());
                        } catch (Exception exc) {
                            DebugMessage("Convert.ToInt32: " + exc.Message);
                        }
                    }
                    break;
                case "RunPeristaticPump":
                    frmUserDialog.setDialogBoxParameters("Enter Speed", "#0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_PERISTATIC_PUMP + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "FillPeristaticPump":
                    frmUserDialog.setDialogBoxParameters("Enter Weight", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_FILL_PERISTATIC_PUMP + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "PrintEncodersOnce":
                    mbClient.SendMessage(Instructions.MB_PRINT_QEI_COUNTERS);
                    break;
                case "PrintEncodersContinuous":
                    mbClient.SendMessage(Instructions.MB_PRINT_QEI_COUNTERS_CONT);
                    break;
                case "ResetEncoder1":
                    mbClient.SendMessage(Instructions.MB_RESET_QEI_COUNTER1);
                    break;
                case "ResetEncoder2":
                    mbClient.SendMessage(Instructions.MB_RESET_QEI_COUNTER2);
                    break;
                case "ResetStepperDrivers":
                    mbClient.SendMessage(Instructions.MB_RESET_STEPPER_DRIVERS);
                    break;
                case "Stepper1GetMarkPosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_PRINT_MARK_POSITION);
                    break;
                case "Stepper1SetMarkPosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_SET_MARK_POSITION);
                    break;
                case "Stepper1SetHomePosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_SET_HOME_POSITION);
                    break;
                case "Stepper1GotoMarkPosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER1_GOTO_MARK_POSITION + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "Stepper1GotoHomePosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER1_GOTO_HOME_POSITION + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "Stepper1GotoPosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed and Position", "0000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER1_GOTO_POSITION + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper1MoveSteps":
                    frmUserDialog.setDialogBoxParameters("Enter Speed and Steps", "0000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER1_MOVE_STEPS + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper1IsRunning":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_IS_RUNNING);
                    break;
                case "Stepper1PrintEndPositions":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_PRINT_END_POSITIONS);
                    break;
                case "Stepper1SetEndPositions":
                    frmUserDialog.setDialogBoxParameters("Enter BW and FW End Points", "#00000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER1_SET_END_POSITIONS + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper1PrintTaskResult":
                    mbClient.SendMessage(Instructions.MB_STEPPER1_PRINT_TASK_RESULT);
                    break;
                case "Stepper2GetMarkPosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_PRINT_MARK_POSITION);
                    break;
                case "Stepper2SetMarkPosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_SET_MARK_POSITION);
                    break;
                case "Stepper2SetHomePosition":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_SET_HOME_POSITION);
                    break;
                case "Stepper2GotoMarkPosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER2_GOTO_MARK_POSITION + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "Stepper2GotoHomePosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER2_GOTO_HOME_POSITION + " " + frmUserDialog.getUserInput1());
                    }
                    break;
                case "Stepper2GotoPosition":
                    frmUserDialog.setDialogBoxParameters("Enter Speed and Position", "0000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER2_GOTO_POSITION + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper2MoveSteps":
                    frmUserDialog.setDialogBoxParameters("Enter Speed and Steps", "0000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER2_MOVE_STEPS + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper2IsRunning":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_IS_RUNNING);
                    break;
                case "Stepper2PrintEndPositions":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_PRINT_END_POSITIONS);
                    break;
                case "Stepper2SetEndPositions":
                    frmUserDialog.setDialogBoxParameters("Enter BW and FW End Points", "#00000", "#00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_STEPPER2_SET_END_POSITIONS + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "Stepper2PrintTaskResult":
                    mbClient.SendMessage(Instructions.MB_STEPPER2_PRINT_TASK_RESULT);
                    break;
                case "RunDCMotor0CW":
                    mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR0CW + " 6000");
                    break;
                case "RunDCMotor0CCW":
                    mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR0CCW + " 6000");
                    break;
                case "StopDCMotor0":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR0);
                    break;
                case "RunDCMotor1CW":
                    mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR1CW + " 6000");
                    break;
                case "RunDCMotor1CCW":
                    mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR1CCW + " 6000");
                    break;
                case "StopDCMotor1":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR1);
                    break;
                case "RunDCMotor2CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR2CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor2CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR2CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor2":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR2);
                    break;
                case "RunDCMotor3CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR3CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor3CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR3CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor3":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR3);
                    break;
                case "RunDCMotor4CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR4CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor4CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR4CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor4":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR4);
                    break;
                case "RunDCMotor5CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR5CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor5CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR5CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor5":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR5);
                    break;
                case "RunDCMotor6CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR6CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor6CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR6CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor6":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR6);
                    break;
                case "RunDCMotor7CW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR7CW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunDCMotor7CCW":
                    frmUserDialog.setDialogBoxParameters("Enter timeout (ms) and speed (optional)", "0000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_RUN_DC_MOTOR7CCW + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "StopDCMotor7":
                    mbClient.SendMessage(Instructions.MB_STOP_DC_MOTOR7);
                    break;
                case "TestDCMotor0Sensors":
                    mbClient.SendMessage(Instructions.MB_TEST_DC_MOTOR0_SENSORS);
                    break;
                case "PrintRFID1Once":
                    mbClient.SendMessage(Instructions.MB_RFID1_PRINT_TAG_ONCE);
                    break;
                case "PrintRFID2Once":
                    mbClient.SendMessage(Instructions.MB_RFID2_PRINT_TAG_ONCE);
                    break;
                case "PrintRFID1Continuous":
                    mbClient.SendMessage(Instructions.MB_RFID1_PRINT_TAG_CONT);
                    break;
                case "PrintRFID2Continuous":
                    mbClient.SendMessage(Instructions.MB_RFID2_PRINT_TAG_CONT);
                    break;
                case "PrintRFID1FWVersion":
                    mbClient.SendMessage(Instructions.MB_RFID1_PRINT_FW_VERSION);
                    break;
                case "PrintRFID2FWVersion":
                    mbClient.SendMessage(Instructions.MB_RFID2_PRINT_FW_VERSION);
                    break;
                case "PrintBAL1Once":
                    mbClient.SendMessage(Instructions.MB_BALANCER1_PRINT_ONCE);
                    break;
                case "PrintBAL2Once":
                    mbClient.SendMessage(Instructions.MB_BALANCER2_PRINT_ONCE);
                    break;
                case "PrintBAL1Continuous":
                    mbClient.SendMessage(Instructions.MB_BALANCER1_PRINT_CONT);
                    break;
                case "PrintBAL2Continuous":
                    mbClient.SendMessage(Instructions.MB_BALANCER2_PRINT_CONT);
                    break;
                case "BAL1Tare":
                    mbClient.SendMessage(Instructions.MB_BALANCER1_RESET_TARE);
                    break;
                case "BAL2Tare":
                    mbClient.SendMessage(Instructions.MB_BALANCER2_RESET_TARE);
                    break;
                case "BAL1Restart":
                    mbClient.SendMessage(Instructions.MB_BALANCER1_RESET);
                    break;
                case "BAL2Restart":
                    mbClient.SendMessage(Instructions.MB_BALANCER2_RESET);
                    break;
                case "BAL1Calibration":
                    calibrationFormShown = true;
                    new CalibrationWizard(1).ShowDialog();
                    break;
                case "BAL2Calibration":
                    calibrationFormShown = true;
                    new CalibrationWizard(2).ShowDialog();
                    break;
                case "PrintNetworkConfig":
                    mbClient.SendMessage(Instructions.MB_PRINT_BOARD_NET_CONFIG);
                    break;
                case "SetBoardIP":
                    frmUserDialog.setDialogBoxParameters("Enter IP last digit and MAC last digit (optional)", "000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(Instructions.MB_SET_BOARD_IP + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "LoopbackTestCPU0":
                    mbClient.SendMessage(Instructions.MB_LOOPBACK_TEST1);
                    break;
                case "LoopbackTestCPU1":
                    mbClient.SendMessage(Instructions.MB_LOOPBACK_TEST2);
                    break;
                case "LoopbackTestCPU2":
                    mbClient.SendMessage(Instructions.MB_LOOPBACK_TEST3);
                    break;
                case "PrintFWVersionCPU0":
                    mbClient.SendMessage(Instructions.MB_PRINT_FW_VER1);
                    break;
                case "PrintFWVersionCPU1":
                    mbClient.SendMessage(Instructions.MB_PRINT_FW_VER2);
                    break;
                case "PrintFWVersionCPU2":
                    mbClient.SendMessage(Instructions.MB_PRINT_FW_VER3);
                    break;
                case "DiscoverBoard":
                    discoverClient.SendMessage(Instructions.MB_BOARD_NAME);
                    break;
                case "SendInstruction":
                    frmUserDialog.setDialogBoxParameters("Enter Instruction to execute");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        mbClient.SendMessage(frmUserDialog.getUserInput4());
                    }
                    break;
            }
        }

        public void SSRBoardMenuItem_Click(object sender, EventArgs e)
        {
            switch ((sender as ToolStripMenuItem).Tag.ToString())
            {
                case "PrintSensorsGroup3":
                    ssrbClient.SendMessage(Instructions.SSRB_PRINT_SENSORS);
                    break;
                case "PrintSOLENOIDStatus":
                    ssrbClient.SendMessage(Instructions.SSRB_PRINT_ALL_SOLENOIDS);
                    break;
                case "SetSingleSOLENOID":
                    frmUserDialog.setDialogBoxParameters("Enter SOLENOID Position and State", "#00", "0");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        ssrbClient.SendMessage(Instructions.SSRB_SET_SINGLE_SOLENOID +
                            frmUserDialog.getUserInput1() + " " +
                            frmUserDialog.getUserInput2());
                    }
                    break;
                case "SetAllSOLENOIDS":
                    frmUserDialog.setDialogBoxParameters("Enter Solenoids State", "0000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        try { 
                            Int32 state = Convert.ToInt32(frmUserDialog.getUserInput1(), 2);
                            ssrbClient.SendMessage(Instructions.SSRB_SET_ALL_SOLENOIDS + state.ToString());
                        } catch (Exception exc)
                        {
                            DebugMessage("Convert.ToInt32: " + exc.Message);
                        }
                    }
                    break;
                case "PrintSSRStatus":
                    ssrbClient.SendMessage(Instructions.SSRB_PRINT_ALL_SSRS);
                    break;
                case "SetSingleSSR":
                    frmUserDialog.setDialogBoxParameters("Enter SSR Position, State and timeout (ms) (optional)", "#00", "0", "00000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        ssrbClient.SendMessage(Instructions.SSRB_SET_SINGLE_SSR + 
                            frmUserDialog.getUserInput1() + " " + 
                            frmUserDialog.getUserInput2() + " " + 
                            frmUserDialog.getUserInput3());
                    }
                    break;
                case "SetAllSSRS":
                    frmUserDialog.setDialogBoxParameters("Enter SSRs State", "0000000000000000000000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        try
                        {
                            Int32 state = Convert.ToInt32(frmUserDialog.getUserInput1(), 2);
                            ssrbClient.SendMessage(Instructions.SSRB_SET_ALL_SSRS + state.ToString());
                        }
                        catch (Exception exc)
                        {
                            DebugMessage("Convert.ToInt32: " + exc.Message);
                        }
                    }
                    break;
                case "PrintNetworkConfig":
                    ssrbClient.SendMessage(Instructions.SSRB_PRINT_BOARD_NET_CONFIG);
                    break;
                case "SetBoardIP":
                    frmUserDialog.setDialogBoxParameters("Enter IP last digit and MAC last digit (optional)", "000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        ssrbClient.SendMessage(Instructions.SSRB_SET_BOARD_IP + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "LoopbackTest":
                    ssrbClient.SendMessage(Instructions.SSRB_LOOPBACK_TEST);
                    break;
                case "PrintFWVersion":
                    ssrbClient.SendMessage(Instructions.SSRB_PRINT_FW_VER);
                    break;
                case "DiscoverBoard":
                    discoverClient.SendMessage(Instructions.SSRB_BOARD_NAME);
                    break;
                case "SendInstruction":
                    frmUserDialog.setDialogBoxParameters("Enter Instruction to execute");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        ssrbClient.SendMessage(frmUserDialog.getUserInput4());
                    }
                    break;
            }
        }

        public void SensorBoardMenuItem_Click(object sender, EventArgs e)
        {
            switch ((sender as ToolStripMenuItem).Tag.ToString())
            {
                case "PrintSensorsGroup4":
                    sbClient.SendMessage(Instructions.SB_PRINT_SENSORS);
                    break;
                case "PrintADCValuesOnce":
                    sbClient.SendMessage(Instructions.SB_PRINT_ADC_VALUES_ONCE);
                    break;
                case "PrintADCValuesContinuous":
                    sbClient.SendMessage(Instructions.SB_PRINT_ADC_VALUES_CONT);
                    break;
                case "PrintSOLENOIDStatus":
                    sbClient.SendMessage(Instructions.SB_PRINT_ALL_SOLENOIDS);
                    break;
                case "SetSingleSOLENOID":
                    frmUserDialog.setDialogBoxParameters("Enter SOLENOID Position and State", "00", "0");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        sbClient.SendMessage(Instructions.SB_SET_SINGLE_SOLENOID +
                            frmUserDialog.getUserInput1() + " " +
                            frmUserDialog.getUserInput2());
                    }
                    break;
                case "SetAllSOLENOIDS":
                    frmUserDialog.setDialogBoxParameters("Enter Solenoids State", "000000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        try
                        {
                            Int32 state = Convert.ToInt32(frmUserDialog.getUserInput1(), 2);
                            sbClient.SendMessage(Instructions.SB_SET_ALL_SOLENOIDS + state.ToString());
                        }
                        catch (Exception exc)
                        {
                            DebugMessage("Convert.ToInt32: " + exc.Message);
                        }
                    }
                    break;
                case "RunDCMotor0CW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR0CW + " 6000");
                    break;
                case "RunDCMotor0CCW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR0CCW + " 6000");
                    break;
                case "StopDCMotor0":
                    sbClient.SendMessage(Instructions.SB_STOP_DC_MOTOR0);
                    break;
                case "RunDCMotor1CW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR1CW + " 6000");
                    break;
                case "RunDCMotor1CCW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR1CCW + " 6000");
                    break;
                case "StopDCMotor1":
                    sbClient.SendMessage(Instructions.SB_STOP_DC_MOTOR1);
                    break;
                case "RunDCMotor2CW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR2CW + " 6000");
                    break;
                case "RunDCMotor2CCW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR2CCW + " 6000");
                    break;
                case "StopDCMotor2":
                    sbClient.SendMessage(Instructions.SB_STOP_DC_MOTOR2);
                    break;
                case "RunDCMotor3CW":
                    sbClient.SendMessage(Instructions.SB_RUN_DC_MOTOR3CW + " 6000");
                    break;
                case "StopDCMotor3":
                    sbClient.SendMessage(Instructions.SB_STOP_DC_MOTOR3);
                    break;
                case "ExecuteCMD1":
                    sbClient.SendMessage(Instructions.SB_EXECUTE_CMD1);
                    break;
                case "ExecuteCMD2":
                    sbClient.SendMessage(Instructions.SB_EXECUTE_CMD2);
                    break;
                case "PrintActivityLogs":
                    frmUserDialog.setDialogBoxParameters("Enter number of logs to print", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        sbClient.SendMessage(Instructions.SB_PRINT_ACTIVITY_LOGS + frmUserDialog.getUserInput1());
                    }
                    break;
                case "PrintCalendar":
                    sbClient.SendMessage(Instructions.SB_PRINT_CALENDAR);
                    break;
                case "SetCalendar":
                    int day, month, year, wday, hour, min, sec;
                    day = DateTime.Now.Day;
                    month = DateTime.Now.Month;
                    year = DateTime.Now.Year;
                    wday = (int)DateTime.Now.DayOfWeek;
                    hour = DateTime.Now.Hour;
                    min = DateTime.Now.Minute;
                    sec = DateTime.Now.Second;
                    sbClient.SendMessage(Instructions.SB_SET_CALENDAR +
                        day + " " + month + " " + year.ToString().Substring(2,2) + " " + wday +
                        " " + hour + " " + min + " " + sec);
                    break;
                case "ClearFlashChip":
                    if (MessageBox.Show("Clear the Flash Chip?", "Warning!", MessageBoxButtons.YesNo) == DialogResult.Yes)
                    {
                        sbClient.SendMessage(Instructions.SB_CLEAR_FLASH_CHIP);
                    }
                    break;
                case "PrintNetworkConfig":
                    sbClient.SendMessage(Instructions.SB_PRINT_BOARD_NET_CONFIG);
                    break;
                case "SetBoardIP":
                    frmUserDialog.setDialogBoxParameters("Enter IP last digit and MAC last digit (optional)", "000", "000");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        sbClient.SendMessage(Instructions.SB_SET_BOARD_IP + " " + frmUserDialog.getUserInput1() + " " + frmUserDialog.getUserInput2());
                    }
                    break;
                case "RunStateMachine3":
                    sbClient.SendMessage(Instructions.SB_RUN_STATE_MACHINE3);
                    break;
                case "LoopbackTest":
                    sbClient.SendMessage(Instructions.SB_LOOPBACK_TEST);
                    break;
                case "PrintFWVersion":
                    sbClient.SendMessage(Instructions.SB_PRINT_FW_VER);
                    break;
                case "DiscoverBoard":
                    discoverClient.SendMessage(Instructions.SB_BOARD_NAME);
                    break;
                case "SendInstruction":
                    frmUserDialog.setDialogBoxParameters("Enter Instruction to execute");
                    frmUserDialog.ShowDialog();
                    if (frmUserDialog.DialogResult == DialogResult.OK)
                    {
                        sbClient.SendMessage(frmUserDialog.getUserInput4());
                    }
                    break;
                default:
                    break;
            }
        }

        public void GotDataFromCTC(object sender, string data)
        {
            int i;

            if (calibrationFormShown)
            {
                if (data.Contains("<BAL1>") || data.Contains("<BAL2>"))
                {
                    if (CalibrationWizard.GetInstance() != null)
                    {
                        this.Invoke(new MethodInvoker(delegate ()
                        {
                            CalibrationWizard.GetInstance().processMessage(data);
                        }));
                    }
                }
            }

            if ((i = data.IndexOf("<BAL1> Weight: ")) != -1)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    lblBalancer1Weight.Text = data.Substring(i + 15);
                }));
            }
            else if ((i = data.IndexOf("<BAL2> Weight: ")) != -1)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    lblBalancer2Weight.Text = data.Substring(i + 15);
                }));
            }
            else if ((i = data.IndexOf("QEI1: ")) != -1)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    lblEncoder1Position.Text = data.Substring(i + 6, 6);
                    if ((i = data.IndexOf("QEI2: ")) != -1)
                        lblEncoder2Position.Text = data.Substring(i + 6, 6);
                }));
            }
            else if ((i = data.IndexOf("ADC0: ")) != -1)
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    lblADC0Value.Text = data.Substring(i + 6, 4);
                    if ((i = data.IndexOf("ADC1: ")) != -1)
                        lblADC1Value.Text = data.Substring(i + 6, 4);
                    if ((i = data.IndexOf("ADC2: ")) != -1)
                        lblADC2Value.Text = data.Substring(i + 6, 4);
                }));
            }
            else
            {
                if ((i = data.IndexOf("<Sens8,Sens9> are active!")) != -1)
                {
                    mbClient.SendMessage(Instructions.MB_LOCK_EL_SENS + "1");
                } else if ((i = data.IndexOf("<Sens8,Sens9> not active!")) != -1)
                {
                    mbClient.SendMessage(Instructions.MB_LOCK_EL_SENS + "0");
                }
                msg("RX: <" + (sender as Client).cip + "> " + data);
            }
        }

        public void UpdateClientList(string ip, bool connected)
        {
            try
            {
                this.Invoke(new MethodInvoker(delegate ()
                {
                    if (connected)
                    {
                        ListViewItem item = lstClients.FindItemWithText("None");
                        if (item != null)
                            lstClients.Items.Remove(item);

                        item = lstClients.FindItemWithText(ip);
                        if (item == null)
                        {
                            lstClients.Items.Add(ip);
                        }
                    }
                    else
                    {
                        ListViewItem item = lstClients.FindItemWithText(ip);
                        if (item != null)
                        {
                            lstClients.Items.Remove(item);
                            lstClients.Items.Add("None");
                        }
                    }
                
                }));
            }
            catch (Exception exc) { }
        }

        private void AppMainForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            server.Stop();
        }
    }
}
