using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace paw1
{
    internal class Casa : Locuinta
    {
        private int suprafataTeren;
        private int nrNiveluri;

        public Casa(int cod, string denumire, int suprafata, int nrCamere, int pret,int suprafataTeren,int nrNiveluri ) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.suprafataTeren = suprafataTeren;
            this.nrNiveluri = nrNiveluri;
        }

        public int SuprafataTeren { get => suprafataTeren; set => suprafataTeren = value; }
        public int NrNiveluri { get => nrNiveluri; set => nrNiveluri = value; }

        public override ListViewItem Afisare()
        {
            // lv1.add
            ListViewItem item = new ListViewItem();
            item.SubItems.Add(Cod.ToString());
            item.SubItems.Add(Denumire);

            item.SubItems.Add(Suprafata.ToString());
            item.SubItems.Add(NrCamere.ToString());

            item.SubItems.Add(Pret.ToString());
            item.SubItems.Add("-");
            //item.SubItems.Add(Etaj.ToString());
            item.SubItems.Add(SuprafataTeren.ToString());
            item.SubItems.Add(NrNiveluri.ToString());



            return item;
        }
    }
}
