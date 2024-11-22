namespace Restauran
{
    partial class ModerMenu
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
            descriptionDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            costDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nameTypeDataGridViewTextBoxColumn1 = new DataGridViewTextBoxColumn();
            foodBindingSource = new BindingSource(components);
            button1 = new Button();
            button3 = new Button();
            ((System.ComponentModel.ISupportInitialize)dataGridView2).BeginInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).BeginInit();
            SuspendLayout();
            // 
            // dataGridView2
            // 
            dataGridView2.AutoGenerateColumns = false;
            dataGridView2.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView2.Columns.AddRange(new DataGridViewColumn[] { iDFoodDataGridViewTextBoxColumn, nameFDataGridViewTextBoxColumn, descriptionDataGridViewTextBoxColumn, costDataGridViewTextBoxColumn, nameTypeDataGridViewTextBoxColumn1 });
            dataGridView2.DataSource = foodBindingSource;
            dataGridView2.Location = new Point(12, 12);
            dataGridView2.Name = "dataGridView2";
            dataGridView2.Size = new Size(867, 395);
            dataGridView2.TabIndex = 10;
            dataGridView2.CellClick += dataGridView2_CellClick;
            // 
            // iDFoodDataGridViewTextBoxColumn
            // 
            iDFoodDataGridViewTextBoxColumn.DataPropertyName = "IDFood";
            iDFoodDataGridViewTextBoxColumn.HeaderText = "IDFood";
            iDFoodDataGridViewTextBoxColumn.Name = "iDFoodDataGridViewTextBoxColumn";
            iDFoodDataGridViewTextBoxColumn.Width = 50;
            // 
            // nameFDataGridViewTextBoxColumn
            // 
            nameFDataGridViewTextBoxColumn.DataPropertyName = "NameF";
            nameFDataGridViewTextBoxColumn.HeaderText = "NameF";
            nameFDataGridViewTextBoxColumn.Name = "nameFDataGridViewTextBoxColumn";
            // 
            // descriptionDataGridViewTextBoxColumn
            // 
            descriptionDataGridViewTextBoxColumn.DataPropertyName = "Description";
            descriptionDataGridViewTextBoxColumn.HeaderText = "Description";
            descriptionDataGridViewTextBoxColumn.Name = "descriptionDataGridViewTextBoxColumn";
            descriptionDataGridViewTextBoxColumn.Width = 500;
            // 
            // costDataGridViewTextBoxColumn
            // 
            costDataGridViewTextBoxColumn.DataPropertyName = "Cost";
            costDataGridViewTextBoxColumn.HeaderText = "Cost";
            costDataGridViewTextBoxColumn.Name = "costDataGridViewTextBoxColumn";
            costDataGridViewTextBoxColumn.Width = 55;
            // 
            // nameTypeDataGridViewTextBoxColumn1
            // 
            nameTypeDataGridViewTextBoxColumn1.DataPropertyName = "NameType";
            nameTypeDataGridViewTextBoxColumn1.HeaderText = "NameType";
            nameTypeDataGridViewTextBoxColumn1.Name = "nameTypeDataGridViewTextBoxColumn1";
            // 
            // foodBindingSource
            // 
            foodBindingSource.DataSource = typeof(cs.Food);
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 14F);
            button1.Location = new Point(161, 413);
            button1.Name = "button1";
            button1.Size = new Size(143, 58);
            button1.TabIndex = 11;
            button1.Text = "Сохранить изменения";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click;
            // 
            // button3
            // 
            button3.Font = new Font("Segoe UI", 14F);
            button3.Location = new Point(12, 413);
            button3.Name = "button3";
            button3.Size = new Size(143, 58);
            button3.TabIndex = 13;
            button3.Text = "Удалить Продукт";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // ModerMenu
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(892, 483);
            Controls.Add(button3);
            Controls.Add(button1);
            Controls.Add(dataGridView2);
            Name = "ModerMenu";
            Text = "ModerMenu";
            ((System.ComponentModel.ISupportInitialize)dataGridView2).EndInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).EndInit();
            ResumeLayout(false);
        }

        #endregion

        private DataGridView dataGridView2;
        private Button button1;
        private DataGridViewTextBoxColumn nameTypeDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn iDFoodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameFDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn descriptionDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn costDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameTypeDataGridViewTextBoxColumn1;
        private Button button3;
        private BindingSource foodBindingSource;
    }
}