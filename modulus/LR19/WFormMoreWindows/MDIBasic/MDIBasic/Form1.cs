using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MDIBasic
{
    public partial class frmContainer : Form
    {
        private int nextFormNumber = 2;
        public frmContainer()
        {
            InitializeComponent();
            // Создание нового экземпляра дочерней формы 
            MDIBasic.frmChild child = new MDIBasic.frmChild(this, "Редактор 1");
            // Вывод созданной формы 
            child.Show();
        }

        private void MenuItemNewWindow_Click(object sender, EventArgs e)
        {
            // Создание нового экземпляра дочерней формы 
            frmChild newChild = new frmChild(this, "Редактор" + nextFormNumber++);
            // Вывод созданной формы 
            newChild.Show();
        }

        private void MenuItemExit_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void MenuItemTile_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.TileHorizontal);
        }

        private void MenuItemCascade_Click(object sender, EventArgs e)
        {
            this.LayoutMdi(MdiLayout.Cascade);
        }
    }
}
