using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace paw1
{
    internal class Apartament : Locuinta
    {
        int etaj;

        public Apartament(int cod, string denumire, int suprafata, int nrCamere, int pret,int etaj) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.etaj = etaj;
        }

        public int Etaj { get => etaj; set => etaj = value; }

        public override ListViewItem Afisare()
        {
            ListViewItem item = new ListViewItem();
            item.SubItems.Add(Cod.ToString());
            item.SubItems.Add(Denumire);
            
            item.SubItems.Add(Suprafata.ToString());
            item.SubItems.Add(NrCamere.ToString());

            item.SubItems.Add(Pret.ToString());
            item.SubItems.Add(Etaj.ToString());
            item.SubItems.Add("-");
            item.SubItems.Add("-");

            

            return item;
        }
    }
}
