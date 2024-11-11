using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ContactInformation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {

                string workplace = "";
                if (checkBox1.Checked)
                {
                    workplace = checkBox1.Text;
                }
                string pol;
                if (radioButton1.Checked) pol = radioButton1.Text;
                else pol = radioButton2.Text;
                if (textBox2.Text == null || textBox2.Text == "") MessageBox.Show("Поле с именем пользователя не должно быть пустым");
                else if (int.Parse(textBox1.Text) < 0) MessageBox.Show("Возраст должен быть больше или равен 0");
                else if (richTextBox2.Text == null || richTextBox2.Text == "") MessageBox.Show("Поле с адресом пользователя не может оставаться пустым");
                else richTextBox1.Text = $"Имя: {textBox1.Text}\nАдрес: {richTextBox2.Text}\nПроффессия: {workplace}\nПол: {pol}\nВозраст: {textBox1.Text}";
            }
            catch (FormatException)
            {
                MessageBox.Show("Возраст пользователя должен представлять собой число");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "Имя = Ваше имя\nАдрес = Ваш адрес\nПрограммист = Отметьте 'Программист' если вы являетесь программистом\nПол = Выберите ваш пол\nВозраст = Ваш возраст";
        }
    }
}
