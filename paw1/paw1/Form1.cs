using System.Collections;

namespace paw1
{
    public partial class Form1 : Form
    {
        //ArrayList l1 = new();
        List<Locuinta> l1 = new List<Locuinta>();
        public Form1()
        {
            InitializeComponent();
            listView1.Columns.Add("", 100);

            listView1.Columns.Add("COD", 100);
            listView1.Columns.Add("DENUIMRE", 100);
            listView1.Columns.Add("SUPRAFATA", 100);
            listView1.Columns.Add("NR CAMERE", 100);

            listView1.Columns.Add("PRET", 100);
            listView1.Columns.Add("ETAJ", 100);
            listView1.Columns.Add("SUPRAFATA TEREN", 100);
            listView1.Columns.Add("NR NIVELURI", 100);



        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Apartament a1 = new Apartament(1, "denumire 1", 100, 4, 150000, 3);
            Apartament a2 = new Apartament(1, "denumire 2", 100, 4, 150000, 3);
            Casa c1 = new Casa(1, "denumire 3", 200, 5, 200000, 500, 2);
            Casa c2 = new Casa(1, "denumire 4", 200, 5, 200000, 500, 2);
            //ArrayList l1 = new();
            l1.Add(a1);
            l1.Add(a2);
            l1.Add(c1);
            l1.Add(c2);
            //listView1
            // a1.Adaugare();
            foreach (Locuinta l in l1)
                listView1.Items.Add(l.Afisare());
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 formAd = new Form2(l1);
            if (formAd.ShowDialog() == DialogResult.OK)
            {
                l1.Add(formAd.LocuintaNoua);
                listView1.Items.Add(formAd.LocuintaNoua.Afisare());
            }
        }
    }
}
