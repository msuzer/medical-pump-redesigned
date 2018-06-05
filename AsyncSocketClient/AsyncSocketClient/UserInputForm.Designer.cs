namespace AsyncSocketClient
{
    partial class UserInputForm
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
            this.mTxt1 = new System.Windows.Forms.MaskedTextBox();
            this.mTxt2 = new System.Windows.Forms.MaskedTextBox();
            this.btnOK = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.mTxt3 = new System.Windows.Forms.MaskedTextBox();
            this.txtInstruction = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // mTxt1
            // 
            this.mTxt1.Location = new System.Drawing.Point(12, 20);
            this.mTxt1.Margin = new System.Windows.Forms.Padding(4);
            this.mTxt1.Name = "mTxt1";
            this.mTxt1.Size = new System.Drawing.Size(179, 22);
            this.mTxt1.TabIndex = 0;
            // 
            // mTxt2
            // 
            this.mTxt2.Location = new System.Drawing.Point(199, 20);
            this.mTxt2.Margin = new System.Windows.Forms.Padding(4);
            this.mTxt2.Name = "mTxt2";
            this.mTxt2.Size = new System.Drawing.Size(86, 22);
            this.mTxt2.TabIndex = 1;
            // 
            // btnOK
            // 
            this.btnOK.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.btnOK.Location = new System.Drawing.Point(41, 138);
            this.btnOK.Margin = new System.Windows.Forms.Padding(4);
            this.btnOK.Name = "btnOK";
            this.btnOK.Size = new System.Drawing.Size(100, 28);
            this.btnOK.TabIndex = 4;
            this.btnOK.Text = "OK";
            this.btnOK.UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this.btnCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.btnCancel.Location = new System.Drawing.Point(158, 138);
            this.btnCancel.Margin = new System.Windows.Forms.Padding(4);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(100, 28);
            this.btnCancel.TabIndex = 5;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            // 
            // mTxt3
            // 
            this.mTxt3.Location = new System.Drawing.Point(293, 20);
            this.mTxt3.Margin = new System.Windows.Forms.Padding(4);
            this.mTxt3.Name = "mTxt3";
            this.mTxt3.Size = new System.Drawing.Size(86, 22);
            this.mTxt3.TabIndex = 2;
            // 
            // txtInstruction
            // 
            this.txtInstruction.Location = new System.Drawing.Point(12, 64);
            this.txtInstruction.MaxLength = 32;
            this.txtInstruction.Name = "txtInstruction";
            this.txtInstruction.Size = new System.Drawing.Size(367, 22);
            this.txtInstruction.TabIndex = 6;
            // 
            // UserInputForm
            // 
            this.AcceptButton = this.btnOK;
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(400, 224);
            this.ControlBox = false;
            this.Controls.Add(this.txtInstruction);
            this.Controls.Add(this.mTxt3);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnOK);
            this.Controls.Add(this.mTxt2);
            this.Controls.Add(this.mTxt1);
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "UserInputForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "UserInputForm";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MaskedTextBox mTxt1;
        private System.Windows.Forms.MaskedTextBox mTxt2;
        private System.Windows.Forms.Button btnOK;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.MaskedTextBox mTxt3;
        private System.Windows.Forms.TextBox txtInstruction;
    }
}