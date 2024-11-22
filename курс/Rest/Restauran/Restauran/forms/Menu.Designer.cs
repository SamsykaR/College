using Restauran.cs;

namespace restauran
{
    partial class Menu
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
            Type = new CheckedListBox();
            menuList = new Label();
            dataGridView1 = new DataGridView();
            iDFoodDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nameFDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            costDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            descriptionDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            nameTypeDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            foodTypeDataGridViewTextBoxColumn = new DataGridViewTextBoxColumn();
            foodBindingSource = new BindingSource(components);
            button1 = new Button();
            ((System.ComponentModel.ISupportInitialize)dataGridView1).BeginInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).BeginInit();
            SuspendLayout();
            // 
            // Type
            // 
            Type.Font = new Font("Microsoft Sans Serif", 15F, FontStyle.Regular, GraphicsUnit.Point, 204);
            Type.FormattingEnabled = true;
            Type.Location = new Point(14, 14);
            Type.Margin = new Padding(4, 3, 4, 3);
            Type.Name = "Type";
            Type.Size = new Size(191, 204);
            Type.TabIndex = 0;
            Type.MouseDown += Type_MouseDown;
            // 
            // menuList
            // 
            menuList.AutoSize = true;
            menuList.Font = new Font("Microsoft Sans Serif", 15F, FontStyle.Regular, GraphicsUnit.Point, 204);
            menuList.Location = new Point(213, 14);
            menuList.Margin = new Padding(4, 0, 4, 0);
            menuList.Name = "menuList";
            menuList.Size = new Size(65, 25);
            menuList.TabIndex = 1;
            menuList.Text = "Меню";
            // 
            // dataGridView1
            // 
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.AllowUserToDeleteRows = false;
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridView1.Columns.AddRange(new DataGridViewColumn[] { iDFoodDataGridViewTextBoxColumn, nameFDataGridViewTextBoxColumn, costDataGridViewTextBoxColumn, descriptionDataGridViewTextBoxColumn, nameTypeDataGridViewTextBoxColumn, foodTypeDataGridViewTextBoxColumn });
            dataGridView1.DataSource = foodBindingSource;
            dataGridView1.EditMode = DataGridViewEditMode.EditOnEnter;
            dataGridView1.Location = new Point(213, 42);
            dataGridView1.Name = "dataGridView1";
            dataGridView1.ReadOnly = true;
            dataGridView1.Size = new Size(753, 420);
            dataGridView1.TabIndex = 3;
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
            costDataGridViewTextBoxColumn.Width = 50;
            // 
            // descriptionDataGridViewTextBoxColumn
            // 
            descriptionDataGridViewTextBoxColumn.DataPropertyName = "Description";
            descriptionDataGridViewTextBoxColumn.HeaderText = "Description";
            descriptionDataGridViewTextBoxColumn.Name = "descriptionDataGridViewTextBoxColumn";
            descriptionDataGridViewTextBoxColumn.ReadOnly = true;
            descriptionDataGridViewTextBoxColumn.Width = 500;
            // 
            // nameTypeDataGridViewTextBoxColumn
            // 
            nameTypeDataGridViewTextBoxColumn.DataPropertyName = "NameType";
            nameTypeDataGridViewTextBoxColumn.HeaderText = "NameType";
            nameTypeDataGridViewTextBoxColumn.Name = "nameTypeDataGridViewTextBoxColumn";
            nameTypeDataGridViewTextBoxColumn.ReadOnly = true;
            nameTypeDataGridViewTextBoxColumn.Width = 80;
            // 
            // foodTypeDataGridViewTextBoxColumn
            // 
            foodTypeDataGridViewTextBoxColumn.DataPropertyName = "FoodType";
            foodTypeDataGridViewTextBoxColumn.HeaderText = "FoodType";
            foodTypeDataGridViewTextBoxColumn.Name = "foodTypeDataGridViewTextBoxColumn";
            foodTypeDataGridViewTextBoxColumn.ReadOnly = true;
            foodTypeDataGridViewTextBoxColumn.Visible = false;
            // 
            // foodBindingSource
            // 
            foodBindingSource.DataSource = typeof(Food);
            // 
            // button1
            // 
            button1.Font = new Font("Segoe UI", 15F);
            button1.Location = new Point(17, 232);
            button1.Name = "button1";
            button1.Size = new Size(188, 43);
            button1.TabIndex = 4;
            button1.Text = "Всё";
            button1.UseVisualStyleBackColor = true;
            button1.Click += button1_Click_1;
            // 
            // Menu
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(978, 474);
            Controls.Add(button1);
            Controls.Add(dataGridView1);
            Controls.Add(menuList);
            Controls.Add(Type);
            Margin = new Padding(4, 3, 4, 3);
            Name = "Menu";
            Text = "Menu";
            Load += Menu_Load;
            ((System.ComponentModel.ISupportInitialize)dataGridView1).EndInit();
            ((System.ComponentModel.ISupportInitialize)foodBindingSource).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.CheckedListBox Type;
        private System.Windows.Forms.Label menuList;
        private DataGridView dataGridView1;
        private BindingSource foodBindingSource;
        private DataGridViewTextBoxColumn iDFoodDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameFDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn costDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn descriptionDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn nameTypeDataGridViewTextBoxColumn;
        private DataGridViewTextBoxColumn foodTypeDataGridViewTextBoxColumn;
        private Button button1;
    }
}