using Microsoft.EntityFrameworkCore;
using Restauran.cs;
using Restauran.Methods;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Restauran
{
    public partial class ModerMenu : Form
    {
        public ModerMenu()
        {
            InitializeComponent();
        }
        private DataContext? dbContext = new DataContext();
        FormWork FoW = new FormWork();
        DBWork DBW = new DBWork();
        FileWork FiW = new FileWork();
        protected async override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            await DBW.DBLoad(dbContext!);
            this.foodBindingSource.DataSource = dbContext.Foods.Local.ToBindingList();
        }

        protected override void OnClosing(CancelEventArgs e)
        {
            base.OnClosing(e);
            this.dbContext?.Dispose();
            this.dbContext = null;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DBW.DBSave(this.dataGridView2, dbContext!);
        }


        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            dataGridView2.Rows[e.RowIndex].Selected = true;
        }


        private void button3_Click(object sender, EventArgs e)
        {
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;

            if (MessageBox.Show( "Осторожнее в удалении", "Уверены?", buttons) == System.Windows.Forms.DialogResult.Yes)
            {
                dataGridView2.Rows.RemoveAt(dataGridView2.CurrentRow.Index);
                MessageBox.Show("Удалён продукт");
            }
        }
    }
}
