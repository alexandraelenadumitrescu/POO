using System.Collections;
namespace WinFormsApp1
{
    public partial class Form1 : Form
    {
        List<Locuinta> l = new List<Locuinta>();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Apartament a1 = new Apartament(20, "a1", 75, 3, 100000, 3);
            Apartament a2 = new Apartament(20, "a1", 75, 3, 100000, 3);
            Casa c1 = new Casa(20, "a1", 75, 3, 100000, 300, 2);
            Casa c2 = new Casa(20, "a1", 75, 3, 100000, 300, 2);
            
            l.Add(a1);
            l.Add(a2);
            l.Add(c1);
            l.Add(c2);

            listView1.Columns.Add("", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("denumire", 100);
            listView1.Columns.Add("suprafata", 100);
            listView1.Columns.Add("nrCamere", 100);
            listView1.Columns.Add("pret", 100);
            listView1.Columns.Add("etaj", 100);
            listView1.Columns.Add("supraf teren", 100);
            listView1.Columns.Add("nrNiveluri", 100);

            foreach (Locuinta loc in l)
            {
                listView1.Items.Add(loc.Afisare());
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();

            //f2.Show();
            if (f2.ShowDialog() == DialogResult.OK)
            {
                foreach(Locuinta loc in f2.locuinte)
                {
                    l.Add(loc);
                    listView1.Items.Add(loc.Afisare());
                }
            }
        }
    }
}
