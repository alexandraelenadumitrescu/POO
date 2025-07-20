using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WinFormsApp4
{
    internal class Produs
    {
        private string denumire;
        List<Ingredient> ingrediente;
        List<int> cantitati;
        private decimal adaosComercial;

        public Produs()
        {
            ingrediente = new List<Ingredient>();
            cantitati = new List<int>();
        }

        public string Denumire { get => denumire; set => denumire = value; }
        public int NumarIngrediente { get => ingrediente.Count; }
        
        public int Pret
        {
            get
            {
                int pret = 0;
                int iter = 0;
                foreach(Ingredient i in ingrediente){
                    pret += (int)(i.PretUnitar * cantitati[iter]);
                        iter++;
                }
                return pret;
            }
            
        }
        internal void Adaugare(Ingredient i,int cant)
        {
            ingrediente.Add(i);
            cantitati.Add(cant);
        }
        Ingredient gasireIngredient(int index)
        {
            return ingrediente[index];
        }
        int gasireCantitate(int index)
        {
            return cantitati[index];
        }

    }
}
