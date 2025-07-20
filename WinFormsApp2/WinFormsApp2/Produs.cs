using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp2
{
    internal class Produs
    {
        private string denumire;
        List<Ingredient> ingrediente;
        List<int> cantitati;
        private decimal adaosComercial;
        

        public Produs()
        {
            this.denumire = "";
            this.ingrediente = new List<Ingredient>();
            this.cantitati = new List<int>();
            this.adaosComercial = 0;
        }

        public string Denumire { get => denumire; }
        public int Numar
        {
            get { return ingrediente.Count; }
        }
        public int Pret
        {
            get
            {
                int total = 0;
                int iter = 0;
                foreach(Ingredient i in ingrediente)
                {
                    total +=(int)( i.PretUnitar * cantitati[iter]+adaosComercial);
                    iter++;
                }
                return total;
            }
        }
        public void adauga(Ingredient i,int cant)
        {
            ingrediente.Add(i);
            cantitati.Add(cant);
        }
        public Ingredient gasesteIngredient(int ind)
        {
            return ingrediente[ind];
        }
        public int gasesteCantitate(int ind)
        {
            return cantitati[ind];
        }

        public override string? ToString()
        {
            return base.ToString();
        }
    }
}
