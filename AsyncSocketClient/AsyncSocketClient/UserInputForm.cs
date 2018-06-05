using System.Windows.Forms;

namespace AsyncSocketClient
{
    public partial class UserInputForm : Form
    {
        public UserInputForm()
        {
            InitializeComponent();
        }

        public string getUserInput1()
        {
            return mTxt1.Text;
        }

        public string getUserInput2()
        {
            return mTxt2.Text;
        }

        public string getUserInput3()
        {
            return mTxt3.Text;
        }

        public string getUserInput4()
        {
            return txtInstruction.Text;
        }

        public void setDialogBoxParameters(string title, string mask1 = "", string mask2 = "", string mask3 = "")
        {
            this.Text = title;
            mTxt1.Visible = (mask1.Length > 0);
            mTxt2.Visible = (mask2.Length > 0);
            mTxt3.Visible = (mask3.Length > 0);

            if (mask1.Length > 0)
                mTxt1.Mask = mask1;
            if (mask2.Length > 0)
                mTxt2.Mask = mask2;
            if (mask3.Length > 0)
                mTxt3.Mask = mask3;

            txtInstruction.Visible = !((mask1.Length > 0) || (mask2.Length > 0) || (mask3.Length > 0));
        }
    }
}
