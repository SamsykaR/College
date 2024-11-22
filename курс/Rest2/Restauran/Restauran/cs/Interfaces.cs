using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Restauran.cs
{
    internal class Interfaces
    {
        public interface IFile
        {
            public void FileRead(string directoryPath, string filePath, uint id, ListBox listBox1);
            public void FileWrite(string directoryPath, string filePath, uint id);
        }
        public interface IDataBase
        {
            public Task DBLoad(DataContext dbContext);
            public void DBSave(DataGridView dgv, DataContext dbContext);
        }
    }
}
