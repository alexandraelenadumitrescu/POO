using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace restaurant_paw
{
    internal class Casa:Locuinta
    {
        int suprafataTeren;
        int nrNiveluri;

        public Casa(int cod, string denumire, int suprafata, int nrCamere, int pret,int suprafataTeren,int nrNiveluri) : base(cod, denumire, suprafata, nrCamere, pret)
        {
            this.suprafataTeren = suprafataTeren;
            this.nrNiveluri = nrNiveluri;
        }

        public int SuprafataTeren { get => suprafataTeren; set => suprafataTeren = value; }
        public int NrNiveluri { get => nrNiveluri; set => nrNiveluri = value; }

        public override ListViewItem afisare()
        {
            //throw new NotImplementedException();
            ListViewItem lv1 = new ListViewItem();
            lv1.SubItems.Add(Cod.ToString());
            lv1.SubItems.Add(Denumire);
            lv1.SubItems.Add(Suprafata.ToString());
            lv1.SubItems.Add(NrCamere.ToString());

            lv1.SubItems.Add(Pret.ToString());
            lv1.SubItems.Add("-");
            lv1.SubItems.Add(SuprafataTeren.ToString());
            lv1.SubItems.Add(NrNiveluri.ToString());

            return lv1;
        }
    }
}
