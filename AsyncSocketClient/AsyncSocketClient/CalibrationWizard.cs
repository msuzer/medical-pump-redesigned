using System;
using System.Windows.Forms;

namespace AsyncSocketClient
{
    public partial class CalibrationWizard : Form
    {
        int balancer = 1;
        double v0, v1, b0, b1, gain;
        Int32 gainRep;
        private static CalibrationWizard instance = null;

        public CalibrationWizard(int bal = 1)
        {
            InitializeComponent();
            instance = this;
            balancer = bal;
        }

        public static CalibrationWizard GetInstance()
        {
            return instance;
        }

        protected override void OnShown(EventArgs e)
        {
            btnNext.Text = "İleri";
            btnNext.DialogResult = DialogResult.None;
            btnCancel.DialogResult = DialogResult.Cancel;
            lblResponse.Text = "";
            base.OnShown(e);
        }

        private void CalibrationWizard_FormClosing(object sender, FormClosingEventArgs e)
        {
            AppMainForm.getInstance().UnSetCalibrationFormStatus();
        }

        public void processMessage(string message)
        {
            if (message.Contains("Task Complete!"))
            {
                tabControl1.SelectedIndex = (tabControl1.SelectedIndex + 1 < tabControl1.TabCount) ? tabControl1.SelectedIndex + 1 : tabControl1.SelectedIndex;
                btnNext.Enabled = true;
            }
            else
            {
                int i;

                if ((i = message.IndexOf("Weight: ")) != -1)
                {
                    this.Invoke(new MethodInvoker(delegate ()
                    {
                        message = message.Substring(i + 8);
                    }));
                }

                if (tabControl1.SelectedIndex == 1)
                {
                    b0 = double.Parse(message);
                    tabControl1.SelectedIndex = 2;
                    btnNext.Enabled = true;
                }
                else if (tabControl1.SelectedIndex == 2)
                {
                    b1 = double.Parse(message);
                    gain = (v1 - v0) / (b1 - b0);
                    gainRep = calculateGainRegValue(gain);
                    //lblResponse.Text = b0.ToString() + ", " + b1.ToString() + ", " + v0.ToString() + ", " + v1.ToString() + ", " + gain + ", " + gainRep.ToString("X8");
                    lblResponse.Text = gainRep.ToString("X8");
                    tabControl1.SelectedIndex = 3;
                    btnNext.Text = "Kapat";
                    btnNext.DialogResult = DialogResult.OK;
                    btnNext.Enabled = true;
                }
            }
        }

        private void btnNext_Click(object sender, EventArgs e)
        {
            try
            {
                btnNext.Enabled = false;
                switch (tabControl1.SelectedIndex)
                {
                    case 0:
                        if (balancer == 1)
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER1_CALIBRATE);
                        else
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER2_CALIBRATE);
                        lblPage1.Text = "Devrenin Cevabı Bekleniyor...(5 sn.)";
                        break;
                    case 1:
                        v0 = double.Parse(mTBPage2.Text);
                        if (balancer == 1)
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER1_PRINT_ONCE);
                        else
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER2_PRINT_ONCE);
                        lblPage2.Text = "Devrenin Cevabı Bekleniyor...(5 sn.)";
                        break;
                    case 2:
                        v1 = double.Parse(mTBPage3.Text);
                        if (balancer == 1)
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER1_PRINT_ONCE);
                        else
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER2_PRINT_ONCE);
                        lblPage2.Text = "Devrenin Cevabı Bekleniyor...(5 sn.)";
                        break;
                    case 3:
                        string gval = gainRep.ToString();
                        if (balancer == 1)
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER1_SET_GAIN + gval);
                        else
                            AppMainForm.getInstance().SendMessage(Instructions.MB_BALANCER2_SET_GAIN + gval);
                        break;
                    default:
                        break;
                }
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        Int32 calculateGainRegValue(double gain)
        {
            Int32 retVal = 0;
            Int32 bit = 0x01000000;
            double x = 0;
            for (int i = 0; i > -25; --i)
            {
                double val = Math.Pow(2, i);
                if (x + val < gain)
                {
                    x += val;
                    retVal += bit;
                }
                bit >>= 1;
            }

            return retVal;
        }
    }

    class myTabControl : TabControl
    {
        protected override void WndProc(ref Message m)
        {
            // Hide tabs by trapping the TCM_ADJUSTRECT message
            if (m.Msg == 0x1328 && !DesignMode)
                m.Result = (IntPtr)1;
            else
                base.WndProc(ref m);
        }
    }
}
