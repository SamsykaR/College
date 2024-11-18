using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SQLite;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }
        public int Id = 0;

        private void Form2_Load(object sender, EventArgs e)
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
                            textBox1.Text = name;
                            textBox2.Text = bd;
                            textBox3.Text = Convert.ToString(age);
                            textBox4.Text = Convert.ToString(id);
                            Id = id;
                            break;
                        }
                    }
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Id++;
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var command = connect.CreateCommand();
                command.CommandText = $@"SELECT * FROM People WHERE id = {Id}";
                SQLiteDataReader reader = command.ExecuteReader();
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
                            textBox1.Text = name;
                            textBox2.Text = bd;
                            textBox3.Text = Convert.ToString(age);
                            textBox4.Text = Convert.ToString(id);
                            break;
                        }
                    }
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Id--;
            if (Id <= 0) { Id =1; }
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var command = connect.CreateCommand();
                command.CommandText = $@"SELECT * FROM People WHERE id = {Id}";
                SQLiteDataReader reader = command.ExecuteReader();
                using (reader)
                {
                    while (reader.Read())
                    {
                        int id = reader.GetInt32(0);
                        string name = reader.GetString(1);
                        string bd = reader.GetString(2);
                        int age = reader.GetInt32(3);
                        textBox1.Text = name;
                        textBox2.Text = bd;
                        textBox3.Text = Convert.ToString(age);
                        textBox4.Text = Convert.ToString(id);
                        break;
                    }
                }
            }
        }

        private void запись2_Click(object sender, EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                cmd.CommandText = @"INSERT INTO People VALUES(@id, @name, @db, @age)";
                cmd.Parameters.AddWithValue("@id", textBox4.Text);
                cmd.Parameters.AddWithValue("@name", textBox1.Text);
                cmd.Parameters.AddWithValue("@db", textBox2.Text);
                cmd.Parameters.AddWithValue("@age", textBox3.Text);
                cmd.ExecuteNonQuery();
            }
        }

        private void удалить2_Click(object sender, EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                var id = textBox4.Text;
                cmd.CommandText = $@"DELETE FROM People WHERE id = {id}";
                cmd.ExecuteNonQuery();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string con = "Data Source =mydatabase.db";
            using (var connect = new SQLiteConnection(con))
            {
                connect.Open();
                var cmd = connect.CreateCommand();
                cmd.CommandText = @"UPDATE People SET name = @name, age = @age, db = @db WHERE id = @id";
                cmd.Parameters.AddWithValue("@id", textBox4.Text);
                cmd.Parameters.AddWithValue("@name", textBox1.Text);
                cmd.Parameters.AddWithValue("@db", textBox2.Text);
                cmd.Parameters.AddWithValue("@age", textBox3.Text);
                cmd.ExecuteNonQuery();
            }
        }
    }
}
