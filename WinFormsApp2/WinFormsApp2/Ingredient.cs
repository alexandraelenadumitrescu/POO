using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    internal class Ingredient
    {
        private string denumire;
        private decimal pretUnitar;

        public Ingredient(string denumire, decimal pretUnitar)
        {
            this.denumire = denumire;
            this.pretUnitar = pretUnitar;
        }

        public string Denumire { get => denumire; set => denumire = value; }
        public decimal PretUnitar { get => pretUnitar; set => pretUnitar = value; }
    }
}
