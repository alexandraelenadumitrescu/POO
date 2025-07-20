namespace WinFormsApp2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            List<Produs> produse = new List<Produs>();
            Ingredient i = new Ingredient("ing1", 10);
            Produs prod = new Produs();
            prod.adauga(i,2);


            produse.Add(new Produs());
            produse.Add(new Produs());
            produse.Add(new Produs());
            produse.Add(prod);


            dataGridView1.DataSource =produse;
        }
    }
}
