using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace restaurant_paw
{
    internal abstract class Locuinta
    {
        int cod;
        string denumire;
        int suprafata;
        int nrCamere;
        int pret;

        protected Locuinta(int cod, string denumire, int suprafata, int nrCamere, int pret)
        {
            this.cod = cod;
            this.denumire = denumire;
            this.suprafata = suprafata;
            this.nrCamere = nrCamere;
            this.pret = pret;
        }

        public int Cod { get => cod; set => cod = value; }
        public string Denumire { get => denumire; set => denumire = value; }
        public int Suprafata { get => suprafata; set => suprafata = value; }
        public int Suprafata1 { get => suprafata; set => suprafata = value; }
        public int NrCamere { get => nrCamere; set => nrCamere = value; }
        public int Pret { get => pret; set => pret = value; }

        public abstract ListViewItem afisare();
    }
}
