using Microsoft.EntityFrameworkCore;
using Restauran.cs;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Restauran.Methods
{
    internal class FileWork : Interfaces.IFile
    {
        public void FileRead(string directoryPath, string filePath, uint id, ListBox listBox1)
        {
            string totalPath = $@"{directoryPath}\{filePath}{id}.txt";
            if (!Directory.Exists(directoryPath))
            {
                Directory.CreateDirectory(directoryPath);
            }
            try
            {
                using (StreamReader str = File.OpenText(totalPath))
                {
                    listBox1.Items.Clear();
                    if (str.ReadLine() == null || str.ReadLine() == "") { MessageBox.Show("Файл пустой ._."); return; }
                    string[] strings = str.ReadToEnd().Split('\n');
                    foreach (var el in strings)
                    {
                        listBox1.Items.Add(el);
                    }
                }
            }
            catch (Exception)
            {
                MessageBox.Show("Проблема с файлом");
                return;
            }
        }
        ////////////
        public async void FileWrite(string directoryPath, string filePath, uint id)
        {
            string totalPath = $@"{directoryPath}\{filePath}{id}.txt";
            if (!Directory.Exists(directoryPath))
            {
                Directory.CreateDirectory(directoryPath);
            }
            using (StreamWriter str = File.CreateText(totalPath))
            {
                using (DataContext db = new DataContext())
                {
                    //var  Process.Start("explorer.exe", folderPath);
                    var el = await db.Orders.Where(e => e.IDOrder == id).FirstOrDefaultAsync();
                    var el2 = await db.OrderedFoods.Where(e => e.IDOrder == el!.IDOrder).ToListAsync();
                    var el4 = Enums.Workers.Where(e => e.Key == el!.IDWorker).FirstOrDefault();
                    str.WriteLine($"Дата\t\t\t\t{el!.Date}");
                    str.WriteLine($"Gusto Testo");
                    str.WriteLine($"№{el.IDOrder}\t\t\t\tПариж Ленина 19");
                    str.WriteLine($"------------------------------------------------------");
                    foreach (var l in el2)
                    {
                        var el3 = await db.Foods.Where(e => e.IDFood == l.IDFood).FirstOrDefaultAsync();
                        short length = (short)el3.NameF!.Split(' ').Length;
                        short l0 = (short)el3.NameF!.Split(' ')[0].Length;
                        short l01 = 0;
                        if (length > 1)
                            l01 = Convert.ToInt16(l0 + el3.NameF!.Split(' ')[1].Length);

                        //if (length > 2)
                        //str.WriteLine($"{el3!.NameF,-15}{l!.Count}шт *{el3.Cost}={l.Cost:c}");
                        //else
                        await str.WriteLineAsync($"{el3!.NameF,-30}{l!.Count}шт *{el3.Cost}={l.Cost:c}");
                    }
                    str.WriteLine($"------------------------------------------------------");
                    str.WriteLine($"Итог =\t\t\t\t {el.Cost:c}");
                    str.WriteLine($"Обслужил {el4!.Value.LastName} {el4!.Value.Name} {el4!.Value.FatherName}");
                }
            }
            MessageBox.Show("Чек сохранён");
        }
        //////////////
        public async void FileWriteOrder(string directoryPath, string filePath, ListBox listBox1, System.Windows.Forms.Label label4, uint TotalCost, uint idWorker, Dictionary<string, OrderedFood> OrderedFoods)
        {
            string totalPath = "";
            if (!Directory.Exists(directoryPath))
            {
                Directory.CreateDirectory(directoryPath);
            }
            if (listBox1.Items.Count == 0) { MessageBox.Show("А у вас заказ пустой"); return; }
            using (DataContext db = new DataContext())
            {
                //uint idO = (uint)dataGridView1.SelectedRows[0].Cells[0].Value; // исправить ( исправил >=) )
                uint idO = db.Orders.Max(e => e.IDOrder) + 1;
                totalPath = $@"{directoryPath}\{filePath}{idO}.txt";
                string WName = label4.Text;
                if (WName == "не выбрано") { MessageBox.Show("Кто вы?"); return; }
                DateTime dateTime = DateTime.Now;

                db.Orders.Add(new Order { Date = dateTime, Cost = TotalCost, IDWorker = idWorker });
                await db.SaveChangesAsync();
                foreach (var el in OrderedFoods)
                {
                    uint idF = await db.Foods.Where(e => e.NameF == el.Key).Select(e => e.IDFood).FirstOrDefaultAsync();
                    db.OrderedFoods.Add(new OrderedFood { Count = el.Value.Count, Cost = el.Value.Cost, IDFood = idF, IDOrder = idO });
                    //MessageBox.Show($"Count = {el.Value.Count}, Cost = {el.Value.Cost}, IDFood = {idF}, IDOrder = {idO}");
                    await db.SaveChangesAsync();
                }
                /////////////
                using (StreamWriter str = File.CreateText(totalPath))
                {
                    var el = await db.Orders.Where(e => e.IDOrder == idO).FirstOrDefaultAsync();
                    var el2 = await db.OrderedFoods.Where(e => e.IDOrder == el!.IDOrder).ToListAsync();
                    var el4 = Enums.Workers.Where(e => e.Key == el!.IDWorker).FirstOrDefault();
                    str.WriteLine($"Дата\t\t\t{el!.Date}");
                    str.WriteLine($"Gusto Testo");
                    str.WriteLine($"№{el.IDOrder}\t\t\tПариж Ленина 19");
                    str.WriteLine($"---------------------------");
                    foreach (var l in el2)
                    {
                        var el3 = db.Foods.Where(e => e.IDFood == l.IDFood).FirstOrDefault();
                        //if (el3!.NameF!.Split(' ').Length > 1 || el3!.NameF!.Split(' ')[0].Length > 7)
                        //    await str.WriteLineAsync($"{el3!.NameF}\t\t{l!.Count}шт *{el3.Cost}={l.Cost:c}");
                        //else
                        //    await str.WriteLineAsync($"{el3!.NameF}\t\t\t{l!.Count}шт *{el3.Cost}={l.Cost:c}");
			await str.WriteLineAsync($"{el3!.NameF,-30}{l!.Count}шт *{el3.Cost}={l.Cost:c}");
                    }
                    str.WriteLine($"---------------------------");
                    str.WriteLine($"Итог =\t\t\t {el.Cost:c}");
                    str.WriteLine($"Обслужил {el4!.Value.LastName} {el4!.Value.Name} {el4!.Value.FatherName}");
                }
            }
            MessageBoxButtons buttons = MessageBoxButtons.YesNo;

            if (MessageBox.Show("Открыть файл чека?", "Заказ оформлен", buttons) == System.Windows.Forms.DialogResult.Yes)
            {
                Process.Start("notepad.exe", totalPath);
            }
        }
    }
}
