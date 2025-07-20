using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace restaurant_paw
{
    internal class Apartament:Locuinta
    {
        int etaj;

        public Apartament(int cod, string denumire, int suprafata, int nrCamere, int pret,int etaj) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.etaj = etaj;

        }

        public int Etaj { get => etaj; set => etaj = value; }

        public override ListViewItem afisare()
        {
            // throw new NotImplementedException();
            ListViewItem lv1 = new ListViewItem();
            lv1.SubItems.Add(Cod.ToString());
            lv1.SubItems.Add(Denumire);
            lv1.SubItems.Add(Suprafata.ToString());
            lv1.SubItems.Add(NrCamere.ToString());

            lv1.SubItems.Add(Pret.ToString());
            lv1.SubItems.Add(Etaj.ToString());
            lv1.SubItems.Add("-");
            lv1.SubItems.Add("-");
            return lv1;
        }
    }
}
