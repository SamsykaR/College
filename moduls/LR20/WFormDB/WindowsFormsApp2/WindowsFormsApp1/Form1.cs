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
                cmd.CommandText = $@"DELETE FROM People WHERE Id = {id}";
                cmd.ExecuteNonQuery();
                dataGridView1.Rows.Clear();
                LoadData();
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Form2 form2 = new Form2();
            form2.Show();
        }
    }
}
