using System;
using System.Configuration;
using System.Net;
using System.Windows.Forms;

namespace AsyncSocketClient
{
    public partial class SettingsDialogForm : Form
    {
        private bool settingsValidated = false;

        public SettingsDialogForm()
        {
            InitializeComponent();
            mTxtMainboardIP.Mask = @"###\.###\.###\.###";
            mTxtSSRBoardIP.Mask = @"###\.###\.###\.###";
            mTxtSensorBoardIP.Mask = @"###\.###\.###\.###";
            mTxtMainboardIP.ValidatingType = typeof(IPAddress);
            mTxtSSRBoardIP.ValidatingType = typeof(IPAddress);
            mTxtSensorBoardIP.ValidatingType = typeof(IPAddress);
            mTxtMainboardIP.TypeValidationCompleted += new TypeValidationEventHandler(IPAdress_TypeValidationCompleted);
            mTxtSSRBoardIP.TypeValidationCompleted += new TypeValidationEventHandler(IPAdress_TypeValidationCompleted);
            mTxtSensorBoardIP.TypeValidationCompleted += new TypeValidationEventHandler(IPAdress_TypeValidationCompleted);
            reloadAppConfig();
        }

        private void IPAdress_TypeValidationCompleted(object sender, TypeValidationEventArgs e)
        {
            if (!e.IsValidInput)
            {
                MessageBox.Show("IP address is invalid!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                settingsValidated = false;
            }
            else {
                settingsValidated = true;
            }
        }

        private void btnSaveSettings_Click(object sender, System.EventArgs e)
        {
            if (settingsValidated) { 
                updateConfig();
            }
        }

        private void reloadAppConfig()
        {
            try
            {
                mTxtMainboardIP.Text = ConfigurationManager.AppSettings["MainboardIP"];
                mTxtSSRBoardIP.Text = ConfigurationManager.AppSettings["SSRBoardIP"];
                mTxtSensorBoardIP.Text = ConfigurationManager.AppSettings["SensorBoardIP"];
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Hata", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void updateConfig()
        {
            try
            {
                Configuration config = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

                config.AppSettings.Settings["MainboardIP"].Value = mTxtMainboardIP.Text;
                config.AppSettings.Settings["SSRBoardIP"].Value = mTxtSSRBoardIP.Text;
                config.AppSettings.Settings["SensorBoardIP"].Value = mTxtSensorBoardIP.Text;

                config.Save(ConfigurationSaveMode.Modified);
                ConfigurationManager.RefreshSection("appSettings");
                MessageBox.Show("Settings are saved!", "Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception exc)
            {
                MessageBox.Show(exc.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void SettingsDialogForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!settingsValidated) {
                if (MessageBox.Show("Settings are not changed. Do you want to exit?", "Warning", MessageBoxButtons.YesNo) == DialogResult.No)
                {
                    e.Cancel = true;
                }
            }
        }
    }
}
