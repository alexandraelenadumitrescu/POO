using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
    public partial class Form2 : Form
    {
        
        internal List<Locuinta> locuinte = new List<Locuinta>();
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string txt1;
            string txt2;
            string txt3;
            string txt4;
            string txt5;
            string txt6;
            string txt7;
            string txt8;

            txt1 = textBox1.Text;
            txt2 = textBox2.Text;
            txt3 = textBox3.Text;
            txt4 = textBox4.Text;
            txt5 = textBox5.Text;
            txt6 = textBox6.Text;
            txt7 = textBox7.Text;
            txt8 = textBox8.Text;
            if (string.IsNullOrWhiteSpace(txt6)) 
                {
                locuinte.Add(new Casa(int.Parse(txt1), txt2, int.Parse(txt3), int.Parse(txt4), int.Parse(txt5), int.Parse(txt7),int.Parse(txt8)));
                this.DialogResult = DialogResult.OK;
                this.Close();
            } 

            if (string.IsNullOrWhiteSpace(txt7))
            {
                locuinte.Add(new Apartament(int.Parse(txt1), txt2, int.Parse(txt3), int.Parse(txt4), int.Parse(txt5),int.Parse(txt6)));
            }
            


            this.DialogResult = DialogResult.OK;
            this.Close();

        }
    }
}
