using Microsoft.Data.Sqlite;
using Microsoft.EntityFrameworkCore;
using Restauran.cs;
using Restauran.Methods;
using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Microsoft.EntityFrameworkCore.DbLoggerCategory;
using static Restauran.cs.Methods;

namespace restauran
{
    public partial class Menu : Form
    {
        Stopwatch stopwatch = new Stopwatch();
        FormWork FoW = new FormWork();
        DBWork DBW = new DBWork();
        FileWork FiW = new FileWork();
        public Menu()
        {
            //stopwatch.Restart();
            InitializeComponent();
            //stopwatch.Stop();
            //MessageBox.Show($"Time {stopwatch.ElapsedMilliseconds}ms");
        }

        private async void Menu_Load(object sender, EventArgs e)
        {
            //stopwatch.Restart();
            Type = await Task.Run(() => FoW.ListAdd(this.Type));
            //stopwatch.Stop();
            //MessageBox.Show($"Time load {stopwatch.ElapsedMilliseconds}ms");
        }

        private DataContext? dbContext = new DataContext();
        protected override async void OnLoad(EventArgs e)
        {
            stopwatch.Restart();
            base.OnLoad(e);
            await DBW.DBLoad(dbContext);
            this.foodBindingSource.DataSource = dbContext.Foods.Local.ToBindingList();
            stopwatch.Stop();
            MessageBox.Show($"Time db load {stopwatch.ElapsedMilliseconds}ms");
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            this.dbContext?.Dispose();
            this.dbContext = null;
        }

        private async void Type_MouseDown(object sender, MouseEventArgs e)
        {
            //stopwatch.Restart();
            int index = Type.IndexFromPoint(e.X, e.Y);
            DBW.DBFoodSort(index, this.Type, dataGridView1);
            //stopwatch.Stop();
            //MessageBox.Show($"Time type select {stopwatch.ElapsedMilliseconds}ms");
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            //stopwatch.Restart();
            if (Type.SelectedIndex != -1)
            {
                DBW.DBReturnAllFoods(this.Type, this.dataGridView1);
            }
            //stopwatch.Stop();
            //MessageBox.Show($"Time btn click {stopwatch.ElapsedMilliseconds}ms");
        }
    }
}
