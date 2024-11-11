using System;
using System.Drawing;
using System.Windows.Forms;
namespace WindowsFormsApp3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private int x1 = 650, y1 = 450, x2 = 0, y2 = 0;
        private double a = 150, t, fi = -0.5;
        SolidBrush mySolidBrush = new SolidBrush(Color.Red);
        private void Form1_Load(object sender, EventArgs e)
        {
            x1 = ClientSize.Width / 2;
            y1 = ClientSize.Height / 2;
            t = Math.Tan(fi);
            x2 = x1 + (int)((3 * a * t) / (1 + t * t * t));
            y2 = y1 - (int)((3 * a * t * t) / (1 + t * t * t));
        }
        private void Form1_Paint(object sender,
        PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.FillEllipse(mySolidBrush, x2, y2, 50, 50);
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            fi += 0.01;
            t = Math.Tan(fi);
            x2 = x1 + (int)((3 * a * t) / (1 + t * t * t));
            y2 = y1 - (int)((3 * a * t * t) / (1 + t * t * t));
            Invalidate();
        }
    }
}