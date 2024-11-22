using Microsoft.EntityFrameworkCore;
using Restauran;
using Restauran.cs;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace restauran
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void менюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form form in MdiChildren)
                form.Close();
            ModerMenu newChild = new();
            newChild.MdiParent = this;
            newChild.StartPosition = FormStartPosition.Manual;
            newChild.Location = new Point(0, 0);
            newChild.Show();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private DataContext? dbContext;
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            this.dbContext = new DataContext();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            this.dbContext?.Dispose();
            this.dbContext = null;
        }

        private void оформитьЗаказToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form form in MdiChildren)
                form.Close();
            OrderNew newChild = new OrderNew();
            newChild.MdiParent = this;
            newChild.StartPosition = FormStartPosition.Manual;
            newChild.Location = new Point(0, 0);
            newChild.Show();
        }

        private void просмотретьменюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form form in MdiChildren)
                form.Close();
            Menu newChild = new Menu();
            newChild.MdiParent = this;
            newChild.StartPosition = FormStartPosition.Manual;
            newChild.Location = new Point(0, 0);
            newChild.Show();
        }

        private void заказыToolStripMenuItem_Click(object sender, EventArgs e)
        {
            foreach (Form form in MdiChildren)
                form.Close();
            ModerOrders newChild = new();
            newChild.MdiParent = this;
            newChild.StartPosition = FormStartPosition.Manual;
            newChild.Location = new Point(0, 0);
            newChild.Show();
        }
    }
}
