namespace restauran
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
            menuStrip1 = new MenuStrip();
            официантToolStripMenuItem = new ToolStripMenuItem();
            просмотретьменюToolStripMenuItem = new ToolStripMenuItem();
            оформитьЗаказToolStripMenuItem = new ToolStripMenuItem();
            администраторToolStripMenuItem = new ToolStripMenuItem();
            изменитьДанныеToolStripMenuItem = new ToolStripMenuItem();
            заказыToolStripMenuItem = new ToolStripMenuItem();
            запросыToolStripMenuItem = new ToolStripMenuItem();
            menuStrip1.SuspendLayout();
            SuspendLayout();
            // 
            // menuStrip1
            // 
            menuStrip1.Items.AddRange(new ToolStripItem[] { официантToolStripMenuItem, администраторToolStripMenuItem, запросыToolStripMenuItem });
            menuStrip1.Location = new Point(0, 0);
            menuStrip1.Name = "menuStrip1";
            menuStrip1.Padding = new Padding(7, 2, 0, 2);
            menuStrip1.Size = new Size(1196, 24);
            menuStrip1.TabIndex = 0;
            menuStrip1.Text = "menuStrip1";
            // 
            // официантToolStripMenuItem
            // 
            официантToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { просмотретьменюToolStripMenuItem, оформитьЗаказToolStripMenuItem });
            официантToolStripMenuItem.Name = "официантToolStripMenuItem";
            официантToolStripMenuItem.Size = new Size(76, 20);
            официантToolStripMenuItem.Text = "Официант";
            // 
            // просмотретьменюToolStripMenuItem
            // 
            просмотретьменюToolStripMenuItem.Name = "просмотретьменюToolStripMenuItem";
            просмотретьменюToolStripMenuItem.Size = new Size(183, 22);
            просмотретьменюToolStripMenuItem.Text = "Просмотреть меню";
            просмотретьменюToolStripMenuItem.Click += просмотретьменюToolStripMenuItem_Click;
            // 
            // оформитьЗаказToolStripMenuItem
            // 
            оформитьЗаказToolStripMenuItem.Name = "оформитьЗаказToolStripMenuItem";
            оформитьЗаказToolStripMenuItem.Size = new Size(183, 22);
            оформитьЗаказToolStripMenuItem.Text = "Оформить заказ";
            оформитьЗаказToolStripMenuItem.Click += оформитьЗаказToolStripMenuItem_Click;
            // 
            // администраторToolStripMenuItem
            // 
            администраторToolStripMenuItem.DropDownItems.AddRange(new ToolStripItem[] { изменитьДанныеToolStripMenuItem, заказыToolStripMenuItem });
            администраторToolStripMenuItem.Name = "администраторToolStripMenuItem";
            администраторToolStripMenuItem.Size = new Size(106, 20);
            администраторToolStripMenuItem.Text = "Администратор";
            // 
            // изменитьДанныеToolStripMenuItem
            // 
            изменитьДанныеToolStripMenuItem.Name = "изменитьДанныеToolStripMenuItem";
            изменитьДанныеToolStripMenuItem.Size = new Size(113, 22);
            изменитьДанныеToolStripMenuItem.Text = "Меню";
            изменитьДанныеToolStripMenuItem.Click += менюToolStripMenuItem_Click;
            // 
            // заказыToolStripMenuItem
            // 
            заказыToolStripMenuItem.Name = "заказыToolStripMenuItem";
            заказыToolStripMenuItem.Size = new Size(113, 22);
            заказыToolStripMenuItem.Text = "Заказы";
            заказыToolStripMenuItem.Click += заказыToolStripMenuItem_Click;
            // 
            // запросыToolStripMenuItem
            // 
            запросыToolStripMenuItem.Name = "запросыToolStripMenuItem";
            запросыToolStripMenuItem.Size = new Size(68, 20);
            запросыToolStripMenuItem.Text = "Запросы";
            запросыToolStripMenuItem.Visible = false;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1196, 677);
            Controls.Add(menuStrip1);
            IsMdiContainer = true;
            MainMenuStrip = menuStrip1;
            Margin = new Padding(4, 3, 4, 3);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load;
            menuStrip1.ResumeLayout(false);
            menuStrip1.PerformLayout();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem официантToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem администраторToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem просмотретьменюToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem оформитьЗаказToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem изменитьДанныеToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem заказыToolStripMenuItem;
        private ToolStripMenuItem запросыToolStripMenuItem;
    }
}

