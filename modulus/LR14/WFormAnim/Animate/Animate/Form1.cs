using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Animate
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        // Глобальные переменные
        private int x1 = 500, y1 = 200;
        private bool a = true;
        private Pen pen = new Pen(Color.DarkRed, 3);



        // Перерисовка формы
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.DrawRectangle(pen, x1, y1, 30, 30);
        }
        // Действия при загрузке формы
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {


        }

        // Действия при очередном тике
        private void timer1_Tick_1(object sender, EventArgs e)
        {
            Thread t = new Thread(Path);
            t.Start();
            if (x1<=20 && a) a = false;
            if (a) {
                x1 -= 20;
                y1 = (int)Math.Sqrt(x1)+200;
            }
            else
            {
                x1 += 20;
                y1 = -(int)Math.Sqrt(x1)+200;
            }
            label1.Text = DateTime.Now.ToString();
            Invalidate();
            
        }

        void Path()
        {
            Graphics g = this.CreateGraphics();
            float x = 500;
            float y = 200;
            Pen pen2 = new Pen(Color.White, 1);
            bool b = true;
            for (int i = 0; i < 50; i++)
            {
                if (x <= 20 && b) b = false;
                if (b)
                {
                    x -= 20;
                    y = (int)Math.Sqrt(x) + 200;
                }
                else
                {
                    x += 20;
                    y = -(int)Math.Sqrt(x) + 200;
                }
                g.DrawEllipse(pen2, x, y, 1, 1);
                Thread.Sleep(50);
            }
        }
    }
}
