using Microsoft.EntityFrameworkCore;
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
using System.IO;
using System.Diagnostics;
using Restauran.Methods;

namespace Restauran
{
    public partial class ModerOrders : Form
    {
        string directoryPath = @"..\Чеки";
        string filePath = "чек";
        FormWork FoW = new FormWork();
        DBWork DBW = new DBWork();
        FileWork FiW = new FileWork();

        public ModerOrders()
        {
            InitializeComponent();
        }
        private DataContext? dbContext = new DataContext();
        protected async override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            await DBW.DBLoad(dbContext!);
            this.orderBindingSource.DataSource = dbContext.Orders.Local.ToBindingList();
            this.orderedFoodsBindingSource.DataSource = dbContext.OrderedFoods.Local.ToBindingList();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            this.dbContext?.Dispose();
            this.dbContext = null;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            uint id = (uint)dataGridView1.SelectedRows[0].Cells[0].Value;
            FiW.FileRead(directoryPath, filePath, id, this.listBox1);
        }

        private void dataGridView1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            dataGridView1.Rows[e.RowIndex].Selected = true;
        }

        private async void button4_Click(object sender, EventArgs e)
        {
            uint id = (uint)dataGridView1.SelectedRows[0].Cells[0].Value;
            FiW.FileWrite(directoryPath, filePath, id);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            try
            {
                Process.Start("explorer.exe", directoryPath);
            }
            catch (Exception) { MessageBox.Show("Возникли проблемы"); }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;

            if (MessageBox.Show("Осторожнее в удалении заказа", "Уверены?", buttons) == System.Windows.Forms.DialogResult.Yes)
            {
                dataGridView1.Rows.Remove(dataGridView1.SelectedRows[0]);
                MessageBox.Show("Удалён заказ и соответствующие ему продукты");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;

            if (MessageBox.Show("Осторожнее в удалении", "Уверены?", buttons) == System.Windows.Forms.DialogResult.Yes)
            {
                dataGridView2.Rows.RemoveAt(dataGridView2.CurrentRow.Index);
                MessageBox.Show("Удалён заказанный продукт");
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DBW.DBSave(this.dataGridView1, this.dataGridView1, dbContext!);
        }
    }
}
