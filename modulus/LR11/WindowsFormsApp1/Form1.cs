﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
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

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            label4.Text = Convert.ToString(Convert.ToInt32(textBox1.Text) + Convert.ToInt32(textBox2.Text));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label4.Text = Convert.ToString(Convert.ToInt32(textBox1.Text) - Convert.ToInt32(textBox2.Text));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label4.Text = null;
            textBox1.Text = null;
            textBox2.Text = null;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
