using Restauran.cs;

namespace Restauran
{
    partial class OrderNew
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            dataGridView2 = new DataGridView();
            iDFoodDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nameFDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            costDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            descriptionDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nameTypeDataGridViewTextBoxColumn1 = new DataGridViewTextBoxColumn();
            foodBindingSource = new BindingSource(components);
            textBox1 = new TextBox();
            label1 = new Label();
            button1 = new Button();
            listBox1 = new ListBox();
            label2 = new Label();
            button2 = new Button();
            label3 = new Label();
            comboBox1 = new ComboBox();
            label4 = new Label();
            button3 = new Button();
            Type = new CheckedListBox();
            ((System.ComponentModel.ISupportInitialize)dataGridView2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).BeginInit();
            SuspendLayout();
            // 
            // dataGridView2
            // 
            dataGridView2.AutoGenerateColumns = false;
            dataGridView2.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView2.Columns.AddRange(new DataGridViewColumn[] { iDFoodDataGridViewTextBoxColumn, nameFDataGridViewTextBoxColumn, costDataGridViewTextBoxColumn, descriptionDataGridViewTextBoxColumn, nameTypeDataGridViewTextBoxColumn1 });
            dataGridView2.DataSource = foodBindingSource;
            dataGridView2.Location = new Point(257, 11);
            dataGridView2.Name = "dataGridView2";
            dataGridView2.ReadOnly = true;
            dataGridView2.Size = new Size(683, 341);
            dataGridView2.TabIndex = 1;
            dataGridView2.CellClick += dataGridView2_CellClick;
            // 
            // iDFoodDataGridViewTextBoxColumn
            // 
            iDFoodDataGridViewTextBoxColumn.DataPropertyName = "IDFood";
            iDFoodDataGridViewTextBoxColumn.HeaderText = "IDFood";
            iDFoodDataGridViewTextBoxColumn.Name = "iDFoodDataGridViewTextBoxColumn";
            iDFoodDataGridViewTextBoxColumn.ReadOnly = true;
            iDFoodDataGridViewTextBoxColumn.Visible = false;
            // 
            // nameFDataGridViewTextBoxColumn
            // 
            nameFDataGridViewTextBoxColumn.DataPropertyName = "NameF";
            nameFDataGridViewTextBoxColumn.HeaderText = "NameF";
            nameFDataGridViewTextBoxColumn.Name = "nameFDataGridViewTextBoxColumn";
            nameFDataGridViewTextBoxColumn.ReadOnly = true;
            nameFDataGridViewTextBoxColumn.Width = 80;
            // 
            // costDataGridViewTextBoxColumn
            // 
            costDataGridViewTextBoxColumn.DataPropertyName = "Cost";
            costDataGridViewTextBoxColumn.HeaderText = "Cost";
            costDataGridViewTextBoxColumn.Name = "costDataGridViewTextBoxColumn";
            costDataGridViewTextBoxColumn.ReadOnly = true;
            costDataGridViewTextBoxColumn.Width = 60;
            // 
            // descriptionDataGridViewTextBoxColumn
            // 
            descriptionDataGridViewTextBoxColumn.DataPropertyName = "Description";
            descriptionDataGridViewTextBoxColumn.HeaderText = "Description";
            descriptionDataGridViewTextBoxColumn.Name = "descriptionDataGridViewTextBoxColumn";
            descriptionDataGridViewTextBoxColumn.ReadOnly = true;
            descriptionDataGridViewTextBoxColumn.Width = 500;
            // 
            // nameTypeDataGridViewTextBoxColumn1
            // 
            nameTypeDataGridViewTextBoxColumn1.DataPropertyName = "NameType";
            nameTypeDataGridViewTextBoxColumn1.HeaderText = "NameType";
            nameTypeDataGridViewTextBoxColumn1.Name = "nameTypeDataGridViewTextBoxColumn1";
            nameTypeDataGridViewTextBoxColumn1.ReadOnly = true;
            nameTypeDataGridViewTextBoxColumn1.Visible = false;
            // 
            // foodBindingSource
            // 
            foodBindingSource.DataSource = typeof(Food);
            // 
            // textBox1
            // 
            textBox1.Font = new Font("Segoe UI", 15F);
            textBox1.Location = new Point(118, 254);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(35, 34);
            textBox1.TabIndex = 2;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 13F);
            label1.Location = new Point(5, 256);
            label1.Name = "label1";
            label1.Size = new Size(107, 25);
            label1.TabIndex = 3;
            label1.Text = "Количество";
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 14F);
            button1.Location = new Point(12, 294);
            button1.Name = "button1";
            button1.Size = new Size(238, 58);
            button1.TabIndex = 4;
            button1.Text = "Добавить к заказу";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15F);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 28;
            listBox1.Location = new Point(257, 386);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(330, 228);
            listBox1.TabIndex = 5;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Font = new Font("Segoe UI", 15F);
            label2.Location = new Point(257, 355);
            label2.Name = "label2";
            label2.Size = new Size(62, 28);
            label2.TabIndex = 6;
            label2.Text = "Заказ";
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 14F);
            button2.Location = new Point(12, 386);
            button2.Name = "button2";
            button2.Size = new Size(238, 58);
            button2.TabIndex = 7;
            button2.Text = "Удалить из заказа";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Font = new Font("Segoe UI", 15F);
            label3.ImageAlign = ContentAlignment.MiddleRight;
            label3.Location = new Point(386, 355);
            label3.Name = "label3";
            label3.Size = new Size(64, 28);
            label3.TabIndex = 8;
            label3.Text = "Итог: ";
            label3.TextAlign = ContentAlignment.MiddleCenter;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Location = new Point(12, 450);
            comboBox1.Name = "comboBox1";
            comboBox1.Size = new Size(238, 23);
            comboBox1.TabIndex = 10;
            comboBox1.SelectedValueChanged += comboBox1_SelectedValueChanged;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(12, 476);
            label4.Name = "label4";
            label4.Size = new Size(72, 15);
            label4.TabIndex = 11;
            label4.Text = "не выбрано";
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 20F);
            button3.Location = new Point(593, 535);
            button3.Name = "button3";
            button3.Size = new Size(347, 75);
            button3.TabIndex = 12;
            button3.Text = "Оформить";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // Type
            // 
            Type.Font = new Font("Microsoft Sans Serif", 15F, FontStyle.Regular, GraphicsUnit.Point, 204);
            Type.FormattingEnabled = true;
            Type.Location = new Point(12, 11);
            Type.Margin = new Padding(4, 3, 4, 3);
            Type.Name = "Type";
            Type.Size = new Size(238, 229);
            Type.TabIndex = 13;
            Type.MouseDown += Type_MouseDown;
            // 
            // OrderNew
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(978, 631);
            Controls.Add(Type);
            Controls.Add(button3);
            Controls.Add(label4);
            Controls.Add(comboBox1);
            Controls.Add(label3);
            Controls.Add(button2);
            Controls.Add(label2);
            Controls.Add(listBox1);
            Controls.Add(button1);
            Controls.Add(label1);
            Controls.Add(textBox1);
            Controls.Add(dataGridView2);
            FormBorderStyle = FormBorderStyle.None;
            Name = "OrderNew";
            Text = "OrderNew";
            Load += OrderNew_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView2).EndInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private DataGridViewTextBoxColumn nameTypeDataGridViewTextBoxColumn;
        private DataGridView dataGridView2;
        private TextBox textBox1;
        private Label label1;
        private Button button1;
        private ListBox listBox1;
        private Label label2;
        private Button button2;
        private Label label3;
        private ComboBox comboBox1;
        private Label label4;
        private Button button3;
        private DataGridViewTextBoxColumn iDFoodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameFDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn costDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn descriptionDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameTypeDataGridViewTextBoxColumn1;
        private BindingSource foodBindingSource;
        private CheckedListBox Type;
    }
}