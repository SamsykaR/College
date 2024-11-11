using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MenuApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void menuItemAdd_Click(object sender, System.EventArgs e)
        {// код для добавления 
            MessageBox.Show("Добавление");
        }
        private void menuItemDel_Click(object sender, System.EventArgs e)
        {// код для удаления 
            MessageBox.Show("Удаление");
        }
        private void menuItemMove_Click(object sender, System.EventArgs e)
        {// код для перемещения 
            MessageBox.Show("Перемещение");
        }

        private void сообщение1ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            string message = item.Text;
            MessageBox.Show(message);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void menuItemNone_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            string text = item.Text;
            switch(text)
            {
                case "Пусто":
                    trackBar1.TickStyle =
                    TickStyle.None;
                    break;
                case "Сверху-слева":
                    trackBar1.TickStyle =
                    TickStyle.TopLeft;
                    break;
                case "Снизу-справа":
                    trackBar1.TickStyle =
                    TickStyle.BottomRight;
                    break;
                case "С обеих сторон":
                    trackBar1.TickStyle =
                    TickStyle.Both;
                    break;
            }
            foreach (ToolStripMenuItem item1 in menuItemTrackBar.DropDownItems)
            {
                // если текст меню совпадает с переданным параметром, то помечаем пункт меню 
                if (item1.Text == text)
                    item1.Checked = true;
                // если текст меню не совпадает с переданным параметром, то снимаем пометку с пункта меню 
                else
                    item1.Checked = false;
            }
            // проходим по всем подпунктам, изменяющим стиль бегунка и расположенных в контекстном меню программы
            foreach (ToolStripMenuItem item1 in contextMenuStrip2.Items)
            {
                // если текст меню совпадает с переданным параметром, то помечаем пункт меню 
                if (item1.Text == text)
                    item1.Checked = true;
                // если текст меню не совпадает с переданным параметром, то снимаем пометку с пункта меню 
                else
                    item1.Checked = false;
            }
        }

        private void горизонтальнаяToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            string text = item.Text;
            switch (text)
            {
                case "Горизонтальная":
                    trackBar1.Orientation = Orientation.Horizontal;
                    break;
                case "Вертикальная":
                    trackBar1.Orientation = Orientation.Vertical;
                    break;
            }
        }
    }
}
