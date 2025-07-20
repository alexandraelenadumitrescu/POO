using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace restaurant_paw
{
    public partial class Form2 : Form
    {
        List<Locuinta> loc = new List<Locuinta>();
        internal List<Locuinta> Loc => loc;

        internal List<Locuinta> GetLocuinte()
        {
            return loc;
        }


        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string txt1 = textBox1.Text;
            string txt2 = textBox2.Text;
            string txt3 = textBox3.Text;
            string txt4 = textBox4.Text;

            string txt5 = textBox5.Text;
            string txt6 = textBox6.Text;
            string txt7 = textBox7.Text;
            string txt8 = textBox8.Text;


            if (string.IsNullOrWhiteSpace(textBox6.Text))
            {
                loc.Add(new Casa(int.Parse(txt1), txt2, int.Parse(txt3), int.Parse(txt4),
                int.Parse(txt5), int.Parse(txt7), int.Parse(txt8)));
                this.DialogResult = DialogResult.OK;
                this.Close();

            }
            else
            {
                loc.Add(new Apartament(int.Parse(txt1), txt2, int.Parse(txt3), int.Parse(txt4),
                int.Parse(txt5), int.Parse(txt6)));
                this.DialogResult = DialogResult.OK;
                this.Close();
            }

        }
    }
}
