using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Thread a = new Thread(myAnimat);
            a.Start();
        }
        void myAnimat()
        {
            Graphics g = this.CreateGraphics();
            Random rx = new Random();
            
            int step = 0;

            for (int i = 0; i < 10; i++)
            {
                Brush a = new SolidBrush(Color.FromArgb(rx.Next(0, 255), rx.Next(0, 255), rx.Next(0, 255)));
                step = rx.Next(10, 100);
                g.FillRectangle(a, rx.Next(0,250), rx.Next(0, 250), step, step);
                Thread.Sleep(100);
            }
        }

    }
}
