namespace restaurant_paw
{
    public partial class Form1 : Form
    {
        List<Locuinta> locuinte = new List<Locuinta>();
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            listView1.Columns.Add("cod", 100);
            locuinte.Add(new Apartament(10, "ap1", 75, 4, 75000, 3));
            locuinte.Add(new Apartament(10, "ap1", 75, 4, 75000, 3));

            locuinte.Add(new Casa(10, "ap1", 75, 4, 75000, 3, 10));

            locuinte.Add(new Casa(10, "ap1", 75, 4, 75000, 3, 10));

            foreach (Locuinta l in locuinte)
            {
                listView1.Items.Add(l.afisare());
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 f2 = new Form2();
            if (f2.ShowDialog() == DialogResult.OK)
            {
                foreach (Locuinta l in f2.Loc)
                {
                    locuinte.Add(l);
                    listView1.Items.Add(l.afisare());
                }
            }


        }
    }
}
