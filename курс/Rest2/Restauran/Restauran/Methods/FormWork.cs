using Restauran.cs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Restauran.Methods
{
    internal class FormWork
    {
        public CheckedListBox ListAdd(CheckedListBox list)
        {
            foreach (var el in Enums.Types)
            {
                list.Items.Add(el.Value);
            }
            return list;
        }
        /////////////
        public System.Windows.Forms.ComboBox BoxAdd(System.Windows.Forms.ComboBox cb1)
        {
            foreach (var el in Enums.Workers.Values)
            {
                cb1.Items.Add(el.LastName!);
            }
            return cb1;
        }
        /////////////

    }
}
