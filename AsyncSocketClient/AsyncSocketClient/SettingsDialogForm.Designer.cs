namespace AsyncSocketClient
{
    partial class SettingsDialogForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.mTxtSensorBoardIP = new System.Windows.Forms.MaskedTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.mTxtSSRBoardIP = new System.Windows.Forms.MaskedTextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.mTxtMainboardIP = new System.Windows.Forms.MaskedTextBox();
            this.btnSaveSettings = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.mTxtSensorBoardIP);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.mTxtSSRBoardIP);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.mTxtMainboardIP);
            this.groupBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.groupBox1.Location = new System.Drawing.Point(9, 10);
            this.groupBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Padding = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.groupBox1.Size = new System.Drawing.Size(265, 133);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "IP Settings";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label3.Location = new System.Drawing.Point(10, 96);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 17);
            this.label3.TabIndex = 5;
            this.label3.Text = "Sensor Board:";
            // 
            // mTxtSensorBoardIP
            // 
            this.mTxtSensorBoardIP.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.mTxtSensorBoardIP.Location = new System.Drawing.Point(113, 91);
            this.mTxtSensorBoardIP.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.mTxtSensorBoardIP.Mask = "###.###.###.###";
            this.mTxtSensorBoardIP.Name = "mTxtSensorBoardIP";
            this.mTxtSensorBoardIP.Size = new System.Drawing.Size(131, 26);
            this.mTxtSensorBoardIP.TabIndex = 2;
            this.mTxtSensorBoardIP.Text = "192168001102";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label2.Location = new System.Drawing.Point(10, 64);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(82, 17);
            this.label2.TabIndex = 3;
            this.label2.Text = "SSR Board:";
            // 
            // mTxtSSRBoardIP
            // 
            this.mTxtSSRBoardIP.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.mTxtSSRBoardIP.Location = new System.Drawing.Point(113, 59);
            this.mTxtSSRBoardIP.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.mTxtSSRBoardIP.Mask = "###.###.###.###";
            this.mTxtSSRBoardIP.Name = "mTxtSSRBoardIP";
            this.mTxtSSRBoardIP.Size = new System.Drawing.Size(131, 26);
            this.mTxtSSRBoardIP.TabIndex = 1;
            this.mTxtSSRBoardIP.Text = "192168001101";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.label1.Location = new System.Drawing.Point(10, 32);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Main Board:";
            // 
            // mTxtMainboardIP
            // 
            this.mTxtMainboardIP.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.mTxtMainboardIP.Location = new System.Drawing.Point(113, 27);
            this.mTxtMainboardIP.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.mTxtMainboardIP.Mask = "###.###.###.###";
            this.mTxtMainboardIP.Name = "mTxtMainboardIP";
            this.mTxtMainboardIP.Size = new System.Drawing.Size(131, 26);
            this.mTxtMainboardIP.TabIndex = 0;
            this.mTxtMainboardIP.Text = "192168001100";
            // 
            // btnSaveSettings
            // 
            this.btnSaveSettings.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnSaveSettings.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnSaveSettings.Location = new System.Drawing.Point(465, 333);
            this.btnSaveSettings.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnSaveSettings.Name = "btnSaveSettings";
            this.btnSaveSettings.Size = new System.Drawing.Size(80, 29);
            this.btnSaveSettings.TabIndex = 4;
            this.btnSaveSettings.Text = "Save";
            this.btnSaveSettings.UseVisualStyleBackColor = true;
            this.btnSaveSettings.Click += new System.EventHandler(this.btnSaveSettings_Click);
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(162)));
            this.btnCancel.Location = new System.Drawing.Point(355, 333);
            this.btnCancel.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(80, 29);
            this.btnCancel.TabIndex = 3;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // SettingsDialogForm
            // 
            this.AcceptButton = this.btnSaveSettings;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(568, 377);
            this.ControlBox = false;
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnSaveSettings);
            this.Controls.Add(this.groupBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "SettingsDialogForm";
            this.Text = "Settings";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.SettingsDialogForm_FormClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.MaskedTextBox mTxtMainboardIP;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.MaskedTextBox mTxtSensorBoardIP;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.MaskedTextBox mTxtSSRBoardIP;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btnSaveSettings;
        private System.Windows.Forms.Button btnCancel;
    }
}