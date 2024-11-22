using Microsoft.EntityFrameworkCore;
using Restauran.cs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Restauran.Methods
{
    internal class DBWork : Interfaces.IDataBase
    {
        public async Task DBLoad(DataContext dbContext)
        {
            await dbContext.Database.EnsureCreatedAsync();
            await dbContext.Foods.LoadAsync();
            await dbContext.OrderedFoods.LoadAsync();
            await dbContext.Orders.LoadAsync();
        }
        /////////////
        public async void DBFoodSort(int index, CheckedListBox Type, DataGridView dgv)
        {
            if (index != ListBox.NoMatches)
            {
                Type.SetItemChecked(index, !Type.GetItemChecked(index));

                var selectedItems = Type.CheckedItems.Cast<string>().ToList();
                if (selectedItems.Any())
                {
                    //MessageBox.Show("hi");
                    using (DataContext db = new DataContext())
                    {
                        List<Food> data = new List<Food>();
                        foreach (string el in Type.CheckedItems)
                        {
                            data.AddRange(await db.Foods.Where(food => food.NameType == el).ToListAsync());
                        }
                        dgv.DataSource = data;
                    }
                }
            }
        }
        /////////////
        public async void DBReturnAllFoods(CheckedListBox list, DataGridView dgv)
        {
            for (int i = 0; i < list.Items.Count; i++)
            {
                list.SetItemChecked(i, false);
            }
            using (DataContext db = new DataContext())
            {
                var query = db.Foods.AsQueryable();
                var data = await query.ToListAsync();
                dgv.DataSource = data;
            }
            list.SetSelected(list.SelectedIndex, false);
            dgv.Refresh();
        }
        /////////////
        public void DBSave(DataGridView dgv, DataContext dbContext)
        {
            dbContext.SaveChanges();
            dgv.Refresh();
            MessageBox.Show("Сохранено");
        }
        public void DBSave(DataGridView dgv, DataGridView dgv2, DataContext dbContext)
        {
            dbContext.SaveChanges();
            dgv.Refresh();
            dgv2.Refresh();
            MessageBox.Show("Сохранено");
        }
        /////////////

    }
}
