namespace WinFormsApp4
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
            produse.Add(new Produs());
            produse.Add(new Produs());
            produse.Add(new Produs());
            Produs p1 = new Produs();
            p1.Adaugare(new Ingredient("ingredient1", (decimal)11.1),2);
            produse.Add(p1);
            dataGridView1.DataSource = produse;
        }
    }
}
