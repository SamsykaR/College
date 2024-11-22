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
using System.Diagnostics;

namespace restauran
{
    public partial class Form1 : Form
    {
        Stopwatch stopwatch = new Stopwatch();
        public Form1()
        {
            InitializeComponent();
        }

        private void менюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            stopwatch.Restart();
            ModerMenu newChild = new();
            newChild.MdiParent = this;
            newChild.Show();
            stopwatch.Stop();
            MessageBox.Show($"Time {stopwatch.ElapsedMilliseconds}ms");
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
        private DataContext? dbContext;
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            this.dbContext = new DataContext();
            // Uncomment the line below to start fresh with a new database.
            //this.dbContext.Database.EnsureCreated();
            //this.dbContext.Foods.Load();
            //this.dbContext.OrderedFoods.Load();
            //this.dbContext.FoodTypes.Load();
            //this.dbContext.Workers.Load();
            //this.dbContext.Orders.Load();
            //this.foodTypeBindingSource.DataSource = dbContext.FoodTypes.Local.ToBindingList();
            //this.foodsBindingSource.DataSource = dbContext.Foods.Local.ToBindingList();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            this.dbContext?.Dispose();
            this.dbContext = null;
        }

        private void оформитьЗаказToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OrderNew newChild = new OrderNew();
            newChild.MdiParent = this;
            newChild.Show();
        }

        private void просмотретьменюToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Menu newChild = new Menu();
            newChild.MdiParent = this;
            newChild.Show();
        }

        private void заказыToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ModerOrders newChild = new();
            newChild.MdiParent = this;
            newChild.Show();
        }
    }
}
