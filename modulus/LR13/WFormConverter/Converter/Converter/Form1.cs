using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Converter
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double f, i=0;
            try
            {
                double t = double.Parse(textBox1.Text);
                if (radioButton1.Checked == true)
                {
                    i = t / 1000;
                }
                else if (radioButton2.Checked == true)
                {
                    f = 60;
                    i = t * f;
                }
                else
                {
                    f = 3600;
                    i = t * f;
                }
                label4.Text = i.ToString("f2") + " sec";
            }
            catch(FormatException)
            {
                label4.Text = "Неверный формат";
            }
            catch (Exception)
            {
                label4.Text = "Ошибка";
            }
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }
    }
}
