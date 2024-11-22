using Microsoft.EntityFrameworkCore;
using Restauran.cs;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Restauran.Methods;

namespace Restauran
{
    public partial class OrderNew : Form
    {
        //public List<string> OrderedFoodName = new(); 
        //public List<uint> OrderedFoodCount = new();
        //public List<uint> OrderedFoodCost = new();
        Dictionary<string, OrderedFood> OrderedFoods = new();
        uint TotalCost = 0;
        uint idWorker = 0;
        string directoryPath = @"..\Чеки";
        string filePath = "чек";
        FormWork FoW = new FormWork();
        DBWork DBW = new DBWork();
        FileWork FiW = new FileWork();

        public OrderNew()
        {
            InitializeComponent();
        }
        private DataContext? dbContext = new DataContext();
        protected async override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);
            dbContext = new DataContext();
            await DBW.DBLoad(dbContext);
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
            short count = 0;
            try { count = short.Parse(textBox1.Text); }
            catch (Exception) { MessageBox.Show("Заполните корректными данными"); return; }

            string selected = "";
            try { selected = dataGridView2.SelectedRows[0].Cells[1].Value.ToString()!; }
            catch (Exception) { MessageBox.Show("Выберите что то из меню"); return; }

            uint cost = (uint)(dataGridView2.SelectedRows[0].Cells[2].Value);
            if (OrderedFoods.ContainsKey(selected))
            {
                OrderedFoods[selected].Count += count;
                OrderedFoods[selected].Cost = (uint)(cost * OrderedFoods[selected].Count);
                listBox1.Items.Clear();
                TotalCost = 0;
                foreach (var el in OrderedFoods)
                {
                    listBox1.Items.Add($"{el.Key}  {el.Value.Count}   {el.Value.Cost:c}");
                    TotalCost += OrderedFoods[selected].Cost;
                }
            }
            else
            {
                OrderedFoods.Add(selected, new OrderedFood((count), (uint)(count * cost)));
                listBox1.Items.Add($"{OrderedFoods.Last().Key}  {OrderedFoods.Last().Value.Count}  {OrderedFoods.Last().Value.Cost:c}");
                TotalCost += OrderedFoods[selected].Cost;
            }
            dataGridView2.ClearSelection();
            label3.Text = $"Итог: {TotalCost}";
        }

        private void dataGridView2_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            dataGridView2.Rows[e.RowIndex].Selected = true;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string key = "";
            try { key = listBox1.SelectedItem!.ToString()!.Split("   ")[0]; }
            catch (Exception) { MessageBox.Show("Вы не выбрали что удалить"); return; }

            listBox1.Items.Remove(listBox1.SelectedItem);
            OrderedFoods.Remove(key);
        }

        private async void OrderNew_Load(object sender, EventArgs e)
        {
            comboBox1 = await Task.Run(() => FoW.BoxAdd(this.comboBox1));
            Type = await Task.Run(() => FoW.ListAdd(this.Type));
        }

        private void comboBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            idWorker = (uint)comboBox1.SelectedIndex + 1;
            using (DataContext db = new DataContext())
            {
                var wor = Enums.Workers.Where(e => e.Key == idWorker).Select(e => new { e.Value.LastName, e.Value.Name }).FirstOrDefault();
                label4.Text = $"{wor!.LastName} {wor.Name}";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            FiW.FileWriteOrder(directoryPath, filePath, this.listBox1, this.label4, TotalCost, idWorker, OrderedFoods);
            //MessageBox.Show("Заказ оформлен");

        }

        private void Type_MouseDown(object sender, MouseEventArgs e)
        {
            int index = Type.IndexFromPoint(e.X, e.Y);
            DBW.DBFoodSort(index, this.Type, this.dataGridView2);
        }
    }
}
