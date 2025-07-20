using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace paw1
{
    public partial class Form2 : Form
    {
        private List<Locuinta> locuinte;
        [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
        internal Locuinta LocuintaNoua { get; private set; }
        public Form2()
        {
            InitializeComponent();
        }
        internal Form2(List<Locuinta> lista)
        {
            InitializeComponent();
            locuinte = lista;
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string den = textBox1.Text;
            int sup = int.Parse(textBox2.Text);
            LocuintaNoua = new Apartament(0, den, sup, 5, 120000, 4);
            this.DialogResult = DialogResult.OK;
            this.Close();
        }
    }
}
