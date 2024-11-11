namespace ScrollApp
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
            this.vScrollBar1 = new System.Windows.Forms.VScrollBar();
            this.label1 = new System.Windows.Forms.Label();
            this.labelFarTemp = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.labelCTemp = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // vScrollBar1
            // 
            this.vScrollBar1.Location = new System.Drawing.Point(124, 39);
            this.vScrollBar1.Maximum = 60;
            this.vScrollBar1.Minimum = 20;
            this.vScrollBar1.Name = "vScrollBar1";
            this.vScrollBar1.Size = new System.Drawing.Size(25, 226);
            this.vScrollBar1.TabIndex = 0;
            this.vScrollBar1.Value = 32;
            this.vScrollBar1.Scroll += new System.Windows.Forms.ScrollEventHandler(this.vScrollBar1_Scroll);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(17, 35);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(90, 17);
            this.label1.TabIndex = 1;
            this.label1.Text = "Фаренгейт";
            // 
            // labelFarTemp
            // 
            this.labelFarTemp.AutoSize = true;
            this.labelFarTemp.BackColor = System.Drawing.Color.White;
            this.labelFarTemp.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelFarTemp.Location = new System.Drawing.Point(75, 137);
            this.labelFarTemp.Name = "labelFarTemp";
            this.labelFarTemp.Size = new System.Drawing.Size(32, 24);
            this.labelFarTemp.TabIndex = 2;
            this.labelFarTemp.Text = "32";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(193, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(72, 17);
            this.label3.TabIndex = 3;
            this.label3.Text = "Цельсий";
            // 
            // labelCTemp
            // 
            this.labelCTemp.AutoSize = true;
            this.labelCTemp.BackColor = System.Drawing.Color.White;
            this.labelCTemp.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCTemp.Location = new System.Drawing.Point(171, 137);
            this.labelCTemp.Name = "labelCTemp";
            this.labelCTemp.Size = new System.Drawing.Size(21, 24);
            this.labelCTemp.TabIndex = 4;
            this.labelCTemp.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(300, 307);
            this.Controls.Add(this.labelCTemp);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.labelFarTemp);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.vScrollBar1);
            this.Name = "Form1";
            this.Text = "Изменение температуры";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.VScrollBar vScrollBar1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label labelFarTemp;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label labelCTemp;
    }
}

