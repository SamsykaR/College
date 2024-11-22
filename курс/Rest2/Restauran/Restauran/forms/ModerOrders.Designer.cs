namespace Restauran
{
    partial class ModerOrders
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
            button2 = new Button();
            button1 = new Button();
            dataGridView2 = new DataGridView();
            iDOrderedFoodDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            countDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            costDataGridViewTextBoxColumn1 = new DataGridViewTextBoxColumn();
            iDFoodDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            foodDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            iDOrderDataGridViewTextBoxColumn1 = new DataGridViewTextBoxColumn();
            orderDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            orderedFoodsBindingSource1 = new BindingSource(components);
            orderBindingSource = new BindingSource(components);
            orderedFoodsBindingSource = new BindingSource(components);
            dataGridView1 = new DataGridView();
            iDOrderDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            costDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            orderedFoodBindingSource = new BindingSource(components);
            label1 = new Label();
            button3 = new Button();
            button4 = new Button();
            listBox1 = new ListBox();
            button5 = new Button();
            button6 = new Button();
            ((System.ComponentModel.ISupportInitialize)dataGridView2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodsBindingSource1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)orderBindingSource).BeginInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodsBindingSource).BeginInit();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodBindingSource).BeginInit();
            SuspendLayout();
            // 
            // button2
            // 
            button2.Font = new Font("Segoe UI", 14F);
            button2.Location = new Point(12, 289);
            button2.Name = "button2";
            button2.Size = new Size(143, 58);
            button2.TabIndex = 16;
            button2.Text = "Удалить Заказ";
            button2.UseVisualStyleBackColor = true;
            button2.Click += button2_Click;
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 14F);
            button1.Location = new Point(83, 353);
            button1.Name = "button1";
            button1.Size = new Size(143, 58);
            button1.TabIndex = 15;
            button1.Text = "Сохранить";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // dataGridView2
            // 
            dataGridView2.AutoGenerateColumns = false;
            dataGridView2.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView2.Columns.AddRange(new DataGridViewColumn[] { iDOrderedFoodDataGridViewTextBoxColumn, countDataGridViewTextBoxColumn, costDataGridViewTextBoxColumn1, iDFoodDataGridViewTextBoxColumn, foodDataGridViewTextBoxColumn, iDOrderDataGridViewTextBoxColumn1, orderDataGridViewTextBoxColumn });
            dataGridView2.DataSource = orderedFoodsBindingSource1;
            dataGridView2.Location = new Point(317, 14);
            dataGridView2.Name = "dataGridView2";
            dataGridView2.Size = new Size(577, 269);
            dataGridView2.TabIndex = 14;
            // 
            // iDOrderedFoodDataGridViewTextBoxColumn
            // 
            iDOrderedFoodDataGridViewTextBoxColumn.DataPropertyName = "IDOrderedFood";
            iDOrderedFoodDataGridViewTextBoxColumn.HeaderText = "IDOrderedFood";
            iDOrderedFoodDataGridViewTextBoxColumn.Name = "iDOrderedFoodDataGridViewTextBoxColumn";
            // 
            // countDataGridViewTextBoxColumn
            // 
            countDataGridViewTextBoxColumn.DataPropertyName = "Count";
            countDataGridViewTextBoxColumn.HeaderText = "Count";
            countDataGridViewTextBoxColumn.Name = "countDataGridViewTextBoxColumn";
            // 
            // costDataGridViewTextBoxColumn1
            // 
            costDataGridViewTextBoxColumn1.DataPropertyName = "Cost";
            costDataGridViewTextBoxColumn1.HeaderText = "Cost";
            costDataGridViewTextBoxColumn1.Name = "costDataGridViewTextBoxColumn1";
            // 
            // iDFoodDataGridViewTextBoxColumn
            // 
            iDFoodDataGridViewTextBoxColumn.DataPropertyName = "IDFood";
            iDFoodDataGridViewTextBoxColumn.HeaderText = "IDFood";
            iDFoodDataGridViewTextBoxColumn.Name = "iDFoodDataGridViewTextBoxColumn";
            // 
            // foodDataGridViewTextBoxColumn
            // 
            foodDataGridViewTextBoxColumn.DataPropertyName = "Food";
            foodDataGridViewTextBoxColumn.HeaderText = "Food";
            foodDataGridViewTextBoxColumn.Name = "foodDataGridViewTextBoxColumn";
            foodDataGridViewTextBoxColumn.Visible = false;
            // 
            // iDOrderDataGridViewTextBoxColumn1
            // 
            iDOrderDataGridViewTextBoxColumn1.DataPropertyName = "IDOrder";
            iDOrderDataGridViewTextBoxColumn1.HeaderText = "IDOrder";
            iDOrderDataGridViewTextBoxColumn1.Name = "iDOrderDataGridViewTextBoxColumn1";
            // 
            // orderDataGridViewTextBoxColumn
            // 
            orderDataGridViewTextBoxColumn.DataPropertyName = "Order";
            orderDataGridViewTextBoxColumn.HeaderText = "Order";
            orderDataGridViewTextBoxColumn.Name = "orderDataGridViewTextBoxColumn";
            orderDataGridViewTextBoxColumn.Visible = false;
            // 
            // orderedFoodsBindingSource1
            // 
            orderedFoodsBindingSource1.DataMember = "OrderedFoods";
            orderedFoodsBindingSource1.DataSource = orderBindingSource;
            // 
            // orderBindingSource
            // 
            orderBindingSource.DataSource = typeof(cs.Order);
            // 
            // orderedFoodsBindingSource
            // 
            orderedFoodsBindingSource.DataMember = "OrderedFoods";
            orderedFoodsBindingSource.DataSource = orderBindingSource;
            // 
            // dataGridView1
            // 
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Columns.AddRange(new DataGridViewColumn[] { iDOrderDataGridViewTextBoxColumn, costDataGridViewTextBoxColumn });
            dataGridView1.DataSource = orderBindingSource;
            dataGridView1.Location = new Point(12, 12);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.Size = new Size(292, 271);
            dataGridView1.TabIndex = 13;
            dataGridView1.CellClick += dataGridView1_CellClick;
            // 
            // iDOrderDataGridViewTextBoxColumn
            // 
            iDOrderDataGridViewTextBoxColumn.DataPropertyName = "IDOrder";
            iDOrderDataGridViewTextBoxColumn.HeaderText = "IDOrder";
            iDOrderDataGridViewTextBoxColumn.Name = "iDOrderDataGridViewTextBoxColumn";
            // 
            // costDataGridViewTextBoxColumn
            // 
            costDataGridViewTextBoxColumn.DataPropertyName = "Cost";
            costDataGridViewTextBoxColumn.HeaderText = "Cost";
            costDataGridViewTextBoxColumn.Name = "costDataGridViewTextBoxColumn";
            // 
            // orderedFoodBindingSource
            // 
            orderedFoodBindingSource.DataSource = typeof(cs.OrderedFood);
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Font = new Font("Segoe UI", 20F, FontStyle.Underline);
            label1.Location = new Point(570, 303);
            label1.Name = "label1";
            label1.Size = new Size(62, 37);
            label1.TabIndex = 18;
            label1.Text = "Чек";
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 14F);
            button3.Location = new Point(12, 417);
            button3.Name = "button3";
            button3.Size = new Size(143, 58);
            button3.TabIndex = 19;
            button3.Text = "Вывести текст";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // button4
            // 
            button4.Font = new Font("Segoe UI", 14F);
            button4.Location = new Point(161, 417);
            button4.Name = "button4";
            button4.Size = new Size(143, 58);
            button4.TabIndex = 20;
            button4.Text = "Сохранить чек";
            button4.UseVisualStyleBackColor = true;
            button4.Click += button4_Click;
            // 
            // listBox1
            // 
            listBox1.Font = new Font("Segoe UI", 15F);
            listBox1.FormattingEnabled = true;
            listBox1.ItemHeight = 28;
            listBox1.Items.AddRange(new object[] { "Дата\t\t[дата]", "[Название заведения]", "[номер чека] адрес", "еда1\t\t1шт*200=200", "еда2\t\t1шт*200=200", "ИТОГ\t\t=400", "Обслужил\t[ФИО]" });
            listBox1.Location = new Point(317, 343);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(577, 256);
            listBox1.TabIndex = 17;
            // 
            // button5
            // 
            button5.Font = new Font("Segoe UI", 10F);
            button5.Location = new Point(101, 481);
            button5.Name = "button5";
            button5.Size = new Size(113, 50);
            button5.TabIndex = 21;
            button5.Text = "Открыть папку с чеками";
            button5.UseVisualStyleBackColor = true;
            button5.Click += button5_Click;
            // 
            // button6
            // 
            button6.Font = new Font("Segoe UI", 14F);
            button6.Location = new Point(161, 289);
            button6.Name = "button6";
            button6.Size = new Size(143, 58);
            button6.TabIndex = 22;
            button6.Text = "Удалить Продукт";
            button6.UseVisualStyleBackColor = true;
            button6.Click += button6_Click;
            // 
            // ModerOrders
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(978, 631);
            Controls.Add(button6);
            Controls.Add(button5);
            Controls.Add(button4);
            Controls.Add(button3);
            Controls.Add(label1);
            Controls.Add(listBox1);
            Controls.Add(button2);
            Controls.Add(button1);
            Controls.Add(dataGridView2);
            Controls.Add(dataGridView1);
            FormBorderStyle = FormBorderStyle.None;
            Name = "ModerOrders";
            Text = "ModerOrders";
            ((System.ComponentModel.ISupportInitialize)dataGridView2).EndInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodsBindingSource1).EndInit();
            ((System.ComponentModel.ISupportInitialize)orderBindingSource).EndInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodsBindingSource).EndInit();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            ((System.ComponentModel.ISupportInitialize)orderedFoodBindingSource).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private Button button2;
        private Button button1;
        private DataGridView dataGridView2;
        private DataGridView dataGridView1;
        private BindingSource orderedFoodsBindingSource;
        private BindingSource orderBindingSource;
        private DataGridViewTextBoxColumn iDOrderDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn costDataGridViewTextBoxColumn;
        private Label label1;
        private BindingSource orderedFoodBindingSource;
        private Button button3;
        private BindingSource orderedFoodsBindingSource1;
        private DataGridViewTextBoxColumn iDOrderedFoodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn countDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn costDataGridViewTextBoxColumn1;
        private DataGridViewTextBoxColumn iDFoodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn foodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn iDOrderDataGridViewTextBoxColumn1;
        private DataGridViewTextBoxColumn orderDataGridViewTextBoxColumn;
        private Button button4;
        private ListBox listBox1;
        private Button button5;
        private Button button6;
    }
}