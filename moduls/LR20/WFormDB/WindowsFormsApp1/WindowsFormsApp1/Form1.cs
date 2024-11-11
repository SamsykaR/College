using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;
using System.Data.SqlClient;
using System.Data.Entity.Core.Common.CommandTrees.ExpressionBuilder;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            LoadData();
        }
        private void LoadData()
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var command = connect.CreateCommand();
                command.CommandText = @"SELECT * FROM People";
                SQLiteDataReader reader = command.ExecuteReader();
                List<string[]> data = new List<string[]>();
                using (reader)
                {
                    if (reader.HasRows)
                    {
                        while (reader.Read())
                        {
                            int id = reader.GetInt32(0);
                            string name = reader.GetString(1);
                            string bd = reader.GetString(2);
                            int age = reader.GetInt32(3);
                            dataGridView1.Rows.Add(id, name, bd, age);
                            listBox1.Items.Add($"{id} {name}\t{bd}\t {age} лет");
                        }
                    }
                }
            }
        }

        private void button1_Click(object sender, System.EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                cmd.CommandText = @"INSERT INTO People VALUES(@id, @name, @db, @age)";
                int i = dataGridView1.SelectedCells[0].RowIndex;
                DataGridViewRow row = dataGridView1.Rows[i];
                cmd.Parameters.AddWithValue("@id", row.Cells["id"].DefaultNewRowValue);
                cmd.Parameters.AddWithValue("@name", row.Cells["name"].Value);
                cmd.Parameters.AddWithValue("@db", row.Cells["db"].Value);
                cmd.Parameters.AddWithValue("@age", row.Cells["age"].Value);
                cmd.ExecuteNonQuery();
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                var id = (dataGridView1.SelectedRows[0].Cells[0].Value);
                cmd.CommandText = @"DELETE FROM People WHERE Id = @id";
                cmd.Parameters.AddWithValue("@id", id);
                cmd.ExecuteNonQuery();
                dataGridView1.Rows.Clear();
                LoadData();
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            dataGridView1.Rows.Clear();
            listBox1.Items.Clear();
            LoadData();
        }

        private void изменить2_Click(object sender, EventArgs e)
        {
            string[] elements = listBox1.SelectedItem.ToString().Split();
            textBox1.Text = $"{elements[0]} {elements[1]} {elements[2]} {elements[4]}";
        }

        private void удалить2_Click(object sender, EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                var id = (listBox1.SelectedItem.ToString().Split(' ')[0]);
                cmd.CommandText = @"DELETE FROM People WHERE Id = @id";
                cmd.Parameters.AddWithValue("@id", id);
                cmd.ExecuteNonQuery();
                listBox1.Items.Clear();
                dataGridView1.Rows.Clear();
                LoadData();
            }
        }

        private void запись2_Click(object sender, EventArgs e)
        {
            string[] elements = textBox1.Text.ToString().Split();
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                cmd.CommandText = @"INSERT INTO People VALUES(@id, @name, @db, @age)";
                int i = dataGridView1.SelectedCells[0].RowIndex;
                DataGridViewRow row = dataGridView1.Rows[i];
                cmd.Parameters.AddWithValue("@id", dataGridView1.Rows[0].Cells["id"].DefaultNewRowValue);
                cmd.Parameters.AddWithValue("@name", elements[1]);
                cmd.Parameters.AddWithValue("@db", elements[2]);
                cmd.Parameters.AddWithValue("@age", elements[3]);
                cmd.ExecuteNonQuery();
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            string[] elements = textBox1.Text.ToString().Split();
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                cmd.CommandText = @"UPDATE People SET name = @name, age = @age, db = @db WHERE id = @id";
                int i = dataGridView1.SelectedCells[0].RowIndex;
                DataGridViewRow row = dataGridView1.Rows[i];
                cmd.Parameters.AddWithValue("@id", elements[0]);
                cmd.Parameters.AddWithValue("@name", elements[1]);
                cmd.Parameters.AddWithValue("@db", elements[2]);
                cmd.Parameters.AddWithValue("@age", elements[3]);
                cmd.ExecuteNonQuery();
            }
        }
    }
}
