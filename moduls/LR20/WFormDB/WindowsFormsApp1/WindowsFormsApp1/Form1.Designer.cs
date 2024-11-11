namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.запись = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.id = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.name = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.db = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.age = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.удалить = new System.Windows.Forms.Button();
            this.изменить = new System.Windows.Forms.Button();
            this.изменить2 = new System.Windows.Forms.Button();
            this.удалить2 = new System.Windows.Forms.Button();
            this.запись2 = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(203, 25);
            this.label1.TabIndex = 0;
            this.label1.Text = "Форма регистрации";
            // 
            // запись
            // 
            this.запись.Location = new System.Drawing.Point(17, 205);
            this.запись.Name = "запись";
            this.запись.Size = new System.Drawing.Size(75, 23);
            this.запись.TabIndex = 1;
            this.запись.Text = "Записать";
            this.запись.UseVisualStyleBackColor = true;
            this.запись.Click += new System.EventHandler(this.button1_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.id,
            this.name,
            this.db,
            this.age});
            this.dataGridView1.Location = new System.Drawing.Point(17, 37);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.Size = new System.Drawing.Size(352, 150);
            this.dataGridView1.TabIndex = 2;
            // 
            // id
            // 
            this.id.HeaderText = "id";
            this.id.Name = "id";
            this.id.ReadOnly = true;
            this.id.Visible = false;
            // 
            // name
            // 
            this.name.HeaderText = "name";
            this.name.Name = "name";
            // 
            // db
            // 
            this.db.HeaderText = "db";
            this.db.Name = "db";
            // 
            // age
            // 
            this.age.HeaderText = "age";
            this.age.Name = "age";
            // 
            // удалить
            // 
            this.удалить.Location = new System.Drawing.Point(109, 205);
            this.удалить.Name = "удалить";
            this.удалить.Size = new System.Drawing.Size(75, 23);
            this.удалить.TabIndex = 3;
            this.удалить.Text = "Удалить";
            this.удалить.UseVisualStyleBackColor = true;
            this.удалить.Click += new System.EventHandler(this.button2_Click);
            // 
            // изменить
            // 
            this.изменить.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.изменить.Location = new System.Drawing.Point(429, 75);
            this.изменить.Name = "изменить";
            this.изменить.Size = new System.Drawing.Size(122, 77);
            this.изменить.TabIndex = 4;
            this.изменить.Text = "Обновить";
            this.изменить.UseVisualStyleBackColor = true;
            this.изменить.Click += new System.EventHandler(this.button3_Click);
            // 
            // изменить2
            // 
            this.изменить2.Location = new System.Drawing.Point(543, 179);
            this.изменить2.Name = "изменить2";
            this.изменить2.Size = new System.Drawing.Size(75, 23);
            this.изменить2.TabIndex = 7;
            this.изменить2.Text = "вставить";
            this.изменить2.UseVisualStyleBackColor = true;
            this.изменить2.Click += new System.EventHandler(this.изменить2_Click);
            // 
            // удалить2
            // 
            this.удалить2.Location = new System.Drawing.Point(723, 205);
            this.удалить2.Name = "удалить2";
            this.удалить2.Size = new System.Drawing.Size(75, 23);
            this.удалить2.TabIndex = 6;
            this.удалить2.Text = "Удалить";
            this.удалить2.UseVisualStyleBackColor = true;
            this.удалить2.Click += new System.EventHandler(this.удалить2_Click);
            // 
            // запись2
            // 
            this.запись2.Location = new System.Drawing.Point(624, 205);
            this.запись2.Name = "запись2";
            this.запись2.Size = new System.Drawing.Size(75, 23);
            this.запись2.TabIndex = 5;
            this.запись2.Text = "Записать";
            this.запись2.UseVisualStyleBackColor = true;
            this.запись2.Click += new System.EventHandler(this.запись2_Click);
            // 
            // listBox1
            // 
            this.listBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 16;
            this.listBox1.Location = new System.Drawing.Point(624, 9);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(267, 164);
            this.listBox1.TabIndex = 8;
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBox1.Location = new System.Drawing.Point(624, 179);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(267, 23);
            this.textBox1.TabIndex = 9;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(816, 205);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 10;
            this.button1.Text = "Изменить";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(914, 242);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.listBox1);
            this.Controls.Add(this.изменить2);
            this.Controls.Add(this.удалить2);
            this.Controls.Add(this.запись2);
            this.Controls.Add(this.изменить);
            this.Controls.Add(this.удалить);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.запись);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button запись;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.Button удалить;
        private System.Windows.Forms.Button изменить;
        private System.Windows.Forms.DataGridViewTextBoxColumn id;
        private System.Windows.Forms.DataGridViewTextBoxColumn name;
        private System.Windows.Forms.DataGridViewTextBoxColumn db;
        private System.Windows.Forms.DataGridViewTextBoxColumn age;
        private System.Windows.Forms.Button изменить2;
        private System.Windows.Forms.Button удалить2;
        private System.Windows.Forms.Button запись2;
        private System.Windows.Forms.ListBox listBox1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
    }
}

